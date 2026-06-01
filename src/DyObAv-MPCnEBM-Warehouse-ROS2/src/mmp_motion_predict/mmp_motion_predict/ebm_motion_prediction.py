import os
import sys
from pathlib import Path
from typing import List, Optional, Tuple

import numpy as np
from shapely.geometry import Polygon as ShapelyPolygon

PathNode = Tuple[float, float]


def _candidate_legacy_src_paths() -> list[str]:
    candidates: list[Path] = []
    here = Path(__file__).resolve()
    candidates.append(Path('/home/michael/ros2_ws_test/DyObAv_MPCnEBM_Warehouse/src'))
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
except Exception as exc:
    LegacyEBMPredictor = None
    _IMPORT_ERROR = exc
else:
    _IMPORT_ERROR = None


class EBMMotionPredictor:
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
        self.ref_image_path = self._resolve_ref_image(ref_image_path)
        self.num_samples = int(num_samples)
        self.default_std = float(default_std)
        self.predictor = LegacyEBMPredictor(
            self.config_file_path,
            self.model_suffix,
            self.ref_image_path,
        )
        if not hasattr(self.predictor, 'ref_image'):
            raise RuntimeError(
                'EBM requires ebm_ref_image_path. Pass warehouse background image, e.g. '
                '/home/michael/ros2_ws_test/DyObAv_MPCnEBM_Warehouse/data/warehouse_sim_original/background.png'
            )
        self.ref_h = int(self.predictor.ref_image.shape[0])
        self.ref_w = int(self.predictor.ref_image.shape[1])

    @staticmethod
    def _resolve_config_file(config_file_path: str) -> str:
        path = Path(str(config_file_path)).expanduser()
        if path.is_absolute() and path.exists():
            return str(path)
        candidates: list[Path] = []
        for src_path in _candidate_legacy_src_paths():
            root = Path(src_path).parent
            candidates.extend([root / 'config' / path.name, Path(src_path) / 'config' / path.name])
        candidates.extend([Path.cwd() / path, Path.cwd() / path.name, path])
        for candidate in candidates:
            if candidate.exists():
                return str(candidate)
        return str(config_file_path)

    @staticmethod
    def _resolve_ref_image(ref_image_path: Optional[str]) -> Optional[str]:
        if ref_image_path is None:
            return None
        raw = str(ref_image_path).strip()
        if raw == '':
            return None
        path = Path(raw).expanduser()
        if path.is_absolute() and path.exists():
            return str(path)
        candidates: list[Path] = []
        for src_path in _candidate_legacy_src_paths():
            root = Path(src_path).parent
            candidates.extend([
                root / raw,
                root / 'data' / raw,
                root / 'data' / 'warehouse_sim_original' / raw,
                root / 'data' / 'warehouse_sim_dataset' / raw,
                Path(src_path) / raw,
            ])
        candidates.extend([Path.cwd() / raw, path])
        for candidate in candidates:
            if candidate.exists():
                return str(candidate)
        return raw

    @staticmethod
    def _downsample_history(traj: List[PathNode], obs_len: int = 5) -> List[PathNode]:
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
        if arr.ndim == 2 and arr.shape[-1] == 2:
            n = arr.shape[0]
            # Legacy docs say flattened [T*num_samples, 2]. 20 is the configured pred_len.
            pred_len = 20
            if n % pred_len == 0:
                arr = arr.reshape(pred_len, n // pred_len, 2)
        if arr.ndim != 3 or arr.shape[-1] != 2:
            raise ValueError(f'Unexpected EBM samples shape: {arr.shape}')
        if arr.shape[0] > arr.shape[1]:
            arr = np.transpose(arr, (1, 0, 2))
        return arr

    def _image_samples_to_world(self, samples: np.ndarray) -> np.ndarray:
        # Legacy warehouse EBM uses image coordinates. Convert to ROS/world metres.
        # Forward mapping used in the old codebase: px=(wx+15)*10, py=H-1-(wy+15)*10.
        world = samples.astype(np.float32).copy()
        world[..., 0] = world[..., 0] / 10.0 - 15.0
        world[..., 1] = (float(self.ref_h - 1) - world[..., 1]) / 10.0 - 15.0
        # Keep extreme sampled pixels from creating huge RViz/MPC ghosts.
        world[..., 0] = np.clip(world[..., 0], -20.0, 20.0)
        world[..., 1] = np.clip(world[..., 1], -20.0, 20.0)
        return world

    def predict_all_humans(self,
                           trajs_real,
                           k_modes: int = 1,
                           obstacle_polys: Optional[List[ShapelyPolygon]] = None):
        del k_modes, obstacle_polys
        per_human_samples: list[np.ndarray] = []
        for traj in trajs_real:
            history = self._downsample_history(traj)
            raw = self.predictor.get_motion_prediction_samples(
                history,
                rescale=10.0,
                num_samples=self.num_samples,
            )
            samples = self._samples_to_array(raw)
            samples = self._image_samples_to_world(samples)
            per_human_samples.append(samples)
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
                std = np.clip(std, self.default_std, 1.2)
                mu_row.append((float(mu[0]), float(mu[1])))
                std_row.append((float(std[0]), float(std[1])))
                conf_row.append(1.0)
            mu_list_list.append(mu_row)
            std_list_list.append(std_row)
            conf_list_list.append(conf_row)
        return mu_list_list, std_list_list, conf_list_list
