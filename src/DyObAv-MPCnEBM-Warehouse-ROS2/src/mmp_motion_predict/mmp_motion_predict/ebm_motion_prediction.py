import os
import sys
from pathlib import Path
from typing import List, Optional, Tuple

import numpy as np
from shapely.geometry import Polygon as ShapelyPolygon

PathNode = Tuple[float, float]


def _candidate_legacy_src_paths() -> list[str]:
    """Return likely locations of the legacy DyObAv_MPCnEBM_Warehouse/src tree."""
    candidates: list[Path] = []
    here = Path(__file__).resolve()

    # User's normal workspace layout.
    candidates.append(Path('/home/michael/ros2_ws_test/DyObAv_MPCnEBM_Warehouse/src'))

    # Derive from this ROS2 package location if the workspace is elsewhere.
    for parent in [here.parent, *here.parents]:
        if parent.name == 'ros2_ws_test':
            candidates.append(parent / 'DyObAv_MPCnEBM_Warehouse' / 'src')
        if parent.name == 'DyObAv-MPCnEBM-Warehouse-ROS2':
            candidates.append(parent.parent.parent / 'DyObAv_MPCnEBM_Warehouse' / 'src')

    seen = set()
    paths: list[str] = []
    for candidate in candidates:
        resolved = str(candidate)
        if resolved not in seen:
            seen.add(resolved)
            paths.append(resolved)
    return paths


for src_path in _candidate_legacy_src_paths():
    if os.path.isdir(src_path) and src_path not in sys.path:
        sys.path.insert(0, src_path)

try:
    from pkg_mp_ebm.motion_predict import MotionPredictor as LegacyEBMPredictor
except Exception as exc:  # pragma: no cover - runtime dependency check
    LegacyEBMPredictor = None
    _IMPORT_ERROR = exc
else:
    _IMPORT_ERROR = None


class EBMMotionPredictor:
    """Adapter that exposes the same predict_all_humans API used by the ROS2 ST node.

    The legacy EBM predictor returns per-time-step samples from a probability map.
    This adapter converts those samples into the ROS2 node's common output format:
    mu_list_list[t][ped], std_list_list[t][ped], conf_list_list[t][ped].
    """

    def __init__(self,
                 config_file_path: str,
                 model_suffix: str = '0',
                 ref_image_path: Optional[str] = None,
                 num_samples: int = 100,
                 default_std: float = 0.25) -> None:
        if LegacyEBMPredictor is None:
            raise ImportError(
                'Could not import legacy pkg_mp_ebm.motion_predict. '
                f'Checked paths={_candidate_legacy_src_paths()}. Original error={_IMPORT_ERROR}'
            )

        self.config_file_path = self._resolve_config_file(config_file_path)
        self.model_suffix = str(model_suffix)
        self.ref_image_path = ref_image_path
        self.num_samples = int(num_samples)
        self.default_std = float(default_std)
        self.predictor = LegacyEBMPredictor(
            self.config_file_path,
            self.model_suffix,
            self.ref_image_path,
        )

    @staticmethod
    def _resolve_config_file(config_file_path: str) -> str:
        path = Path(str(config_file_path)).expanduser()
        if path.is_absolute() and path.exists():
            return str(path)

        candidates: list[Path] = []
        for src_path in _candidate_legacy_src_paths():
            root = Path(src_path).parent
            candidates.extend([
                root / 'config' / path.name,
                Path(src_path) / 'config' / path.name,
            ])
        candidates.extend([
            Path.cwd() / path,
            Path.cwd() / path.name,
            path,
        ])

        for candidate in candidates:
            if candidate.exists():
                return str(candidate)

        # Let the legacy loader raise a detailed error if it uses custom lookup rules.
        return str(config_file_path)

    @staticmethod
    def _downsample_history(traj: List[PathNode], obs_len: int = 8) -> List[PathNode]:
        # Match the ST node's 10 Hz actor stream -> 2.5 Hz model cadence when possible.
        ds = 4
        t = list(traj)
        t_ds = t[::-1][::ds][:obs_len][::-1]
        if len(t_ds) == 0:
            return [(0.0, 0.0)] * obs_len
        if len(t_ds) < obs_len:
            return [t_ds[0]] * (obs_len - len(t_ds)) + t_ds
        return t_ds

    @staticmethod
    def _samples_to_array(raw_samples) -> np.ndarray:
        arr = np.asarray(raw_samples, dtype=np.float32)
        if arr.ndim != 3:
            raise ValueError(f'Unexpected EBM samples shape: {arr.shape}')
        # Legacy output is usually [T, S, 2]. Accept [S, T, 2] as fallback.
        if arr.shape[-1] != 2:
            raise ValueError(f'Unexpected EBM samples last dimension: {arr.shape}')
        if arr.shape[0] > arr.shape[1]:
            # Heuristic: prediction horizon is usually shorter than sample count.
            arr = np.transpose(arr, (1, 0, 2))
        return arr

    def predict_all_humans(self,
                           trajs_real,
                           k_modes: int = 1,
                           obstacle_polys: Optional[List[ShapelyPolygon]] = None):
        del k_modes, obstacle_polys  # EBM random-trial branch uses one mean mode per pedestrian.

        per_human_samples: list[np.ndarray] = []
        for traj in trajs_real:
            history = self._downsample_history(traj)
            raw = self.predictor.get_motion_prediction_samples(
                history,
                rescale=1.0,
                num_samples=self.num_samples,
            )
            per_human_samples.append(self._samples_to_array(raw))

        if not per_human_samples:
            return [], [], []

        pred_len = min(samples.shape[0] for samples in per_human_samples)
        mu_list_list, std_list_list, conf_list_list = [], [], []

        for t_idx in range(pred_len):
            mu_row, std_row, conf_row = [], [], []
            for samples in per_human_samples:
                step_samples = samples[t_idx]
                mu = np.mean(step_samples, axis=0)
                std = np.std(step_samples, axis=0)
                if not np.isfinite(std).all() or float(np.max(std)) <= 1e-6:
                    std = np.array([self.default_std, self.default_std], dtype=np.float32)
                mu_row.append((float(mu[0]), float(mu[1])))
                std_row.append((float(std[0]), float(std[1])))
                conf_row.append(1.0)
            mu_list_list.append(mu_row)
            std_list_list.append(std_row)
            conf_list_list.append(conf_row)

        return mu_list_list, std_list_list, conf_list_list
