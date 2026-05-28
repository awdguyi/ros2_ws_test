"""
Motion predictor wrapping SingularTrajectory (CVPR 2024) for real-time MPC deployment.

SingularTrajectory was trained on ETH/UCY with:
  - sampling DT : 0.4 s
  - observation  : 8 steps (3.2 s)
  - prediction   : 12 steps (4.8 s)
  - samples/pass : 20 (DDIM diffusion)

Input trajectories are resampled to match the training grid before inference;
outputs are resampled back to the caller's time grid.

Usage::

    from pkg_mp_singulartraj.motion_predict import MotionPredictor

    predictor = MotionPredictor(
        config_path='/home/michael/ai_training_ws/SingularTrajectory/'
                    'config/stochastic/singulartrajectory-transformerdiffusion-hotel.json',
        checkpoint_path='/home/michael/ai_training_ws/SingularTrajectory/'
                        'checkpoints/SingularTrajectory-stochastic/hotel/model_best.pth',
    )
    samples = predictor.get_motion_prediction_samples(
        input_trajs=[[(x0, y0), (x1, y1), ...]],   # one list per pedestrian
        num_samples=20,
        sampling_time=0.2,
        pred_len=20,
    )
    # samples[0].shape == (20, 20, 2)  → (pred_len, num_samples, 2) for ped 0
"""

import math
import json
import os
import sys
from typing import Optional

import numpy as np
import torch
from sklearn.cluster import DBSCAN

# ---------------------------------------------------------------------------
# Path to the SingularTrajectory repository
# ---------------------------------------------------------------------------
_ST_ROOT = os.environ.get(
    'SINGULAR_TRAJECTORY_ROOT',
    '/home/michael/ai_training_ws/SingularTrajectory',
)


def _ensure_st_on_path() -> None:
    if _ST_ROOT not in sys.path:
        sys.path.insert(0, _ST_ROOT)


# ---------------------------------------------------------------------------
# Type alias (matches SGAN / CVM interface)
# ---------------------------------------------------------------------------
PathNode = tuple[float, float]


# ---------------------------------------------------------------------------
# MotionPredictor
# ---------------------------------------------------------------------------
class MotionPredictor:
    """Wraps SingularTrajectory (CVPR 2024) to match the SGAN/EBM predictor API.

    All SVD basis matrices and K-means anchor centres are ``nn.Parameter``s
    stored inside the checkpoint.  Loading a ``model_best.pth`` restores them
    without requiring the original training dataset.

    Non-adaptive anchors are used (the K-means cluster centres learned during
    training), which do not require a scene image or homography and therefore
    generalise to new environments.
    """

    # Training constants
    ST_DT = 0.4        # seconds per step
    ST_OBS_LEN = 8     # observation steps
    ST_PRED_LEN = 12   # prediction steps
    ST_N_SAMPLES = 20  # samples per diffusion forward pass

    def __init__(
            self,
            config_path: str,
            checkpoint_path: Optional[str] = None,
            checkpoint_tag: str = 'SingularTrajectory-stochastic',
    ) -> None:
        """
        Args:
            config_path:      Path to the per-scene JSON config used during
                              training (e.g. singulartrajectory-...-hotel.json).
            checkpoint_path:  Path to ``model_best.pth``.  When *None* the path
                              is derived from the config's ``checkpoint_dir``
                              field relative to ``_ST_ROOT``::

                                  {_ST_ROOT}/{checkpoint_dir}/{checkpoint_tag}/{dataset}/model_best.pth

            checkpoint_tag:   Subdirectory tag used during training, e.g.
                              ``'SingularTrajectory-stochastic'``.  Only
                              consulted when ``checkpoint_path`` is *None*.
        """
        _ensure_st_on_path()

        # Delayed imports – only work after _ST_ROOT is on sys.path
        from utils.utils import DotDict
        from SingularTrajectory import SingularTrajectory as _STModel
        from baseline.transformerdiffusion import TrajectoryPredictor
        from baseline.transformerdiffusion.bridge import (
            model_forward_pre_hook,
            model_forward,
            model_forward_post_hook,
        )

        with open(config_path) as f:
            hyper_params = DotDict(json.load(f))
        self.hyper_params = hyper_params

        if checkpoint_path is None:
            # checkpoint_dir in config is relative (e.g. "./checkpoints/")
            chkpt_subdir = hyper_params.checkpoint_dir.lstrip('.').lstrip('/')
            checkpoint_path = os.path.join(
                _ST_ROOT, chkpt_subdir, checkpoint_tag, hyper_params.dataset, 'model_best.pth'
            )

        self.device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
        self.k = hyper_params.k
        self.n_samples = hyper_params.num_samples  # 20

        # Build diffusion backbone (same config as STTransformerDiffusionTrainer)
        diffusion_cfg = DotDict({
            'scheduler': 'ddim',
            'steps': 10,
            'beta_start': 1.e-4,
            'beta_end': 5.e-2,
            'beta_schedule': 'linear',
            'k': hyper_params.k,
            's': hyper_params.num_samples,
        })
        predictor_model = TrajectoryPredictor(diffusion_cfg).to(self.device)

        hook_func = DotDict({
            'model_forward_pre_hook': model_forward_pre_hook,
            'model_forward': model_forward,
            'model_forward_post_hook': model_forward_post_hook,
        })

        self.model = _STModel(
            baseline_model=predictor_model,
            hook_func=hook_func,
            hyper_params=hyper_params,
        ).to(self.device)

        state_dict = torch.load(checkpoint_path, map_location=self.device)
        self.model.load_state_dict(state_dict)
        self.model.eval()

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    def _build_anchor(self, obs_traj: torch.Tensor) -> torch.Tensor:
        """Build non-adaptive anchor from stored K-means centres.

        Pedestrians are split into *moving* and *static* groups (same as the
        training loop) and the corresponding anchor parameter is replicated per
        pedestrian.

        Args:
            obs_traj: ``(n_ped, obs_len, 2)`` on ``self.device``.

        Returns:
            ``(n_ped, k, s)`` anchor tensor on ``self.device``.
        """
        n_ped = obs_traj.size(0)
        mask = self.model.calculate_mask(obs_traj)   # (n_ped,) bool: True = moving
        n_moving = mask.sum().item()
        n_static = (~mask).sum().item()

        C_anchor_m = self.model.adaptive_anchor_m.C_anchor  # (k, s)
        C_anchor_s = self.model.adaptive_anchor_s.C_anchor  # (k, s)

        anchor = torch.zeros(
            (n_ped, self.k, self.n_samples),
            dtype=torch.float,
            device=self.device,
        )
        if n_moving > 0:
            anchor[mask] = C_anchor_m.unsqueeze(0).expand(n_moving, -1, -1)
        if n_static > 0:
            anchor[~mask] = C_anchor_s.unsqueeze(0).expand(n_static, -1, -1)
        return anchor

    @torch.no_grad()
    def _predict_once(
            self,
            obs_traj: torch.Tensor,
            anchor: torch.Tensor,
            seed: Optional[int] = None,
    ) -> np.ndarray:
        """Single diffusion inference pass.

        Args:
            obs_traj: ``(n_ped, obs_len, 2)`` on ``self.device``.
            anchor:   ``(n_ped, k, s)`` on ``self.device``.
            seed:     Random seed passed to the DDIM sampler.

        Returns:
            NumPy array ``(s, n_ped, pred_len, 2)``.
        """
        n_ped = obs_traj.size(0)
        # All pedestrians in the same scene → full attention mask
        scene_mask = torch.ones(
            (n_ped, n_ped), dtype=torch.bool, device=self.device
        )
        addl_info = {
            'scene_mask': scene_mask,
            'num_samples': self.n_samples,
            'inference_steps': None,
            'inference_seed': seed,
        }
        output = self.model(obs_traj, anchor, addl_info=addl_info)
        return output['recon_traj'].cpu().numpy()   # (s, n_ped, 12, 2)

    # ------------------------------------------------------------------
    # Public interface
    # ------------------------------------------------------------------

    def get_motion_prediction_samples(
            self,
            input_trajs: list[list[PathNode]],
            rescale: Optional[float] = 1.0,
            num_samples: int = 20,
            sampling_time: float = 0.2,
            pred_len: int = 20,
    ) -> list[np.ndarray]:
        """Generate multi-modal trajectory predictions.

        Args:
            input_trajs:   One list of ``(x, y)`` nodes per pedestrian.
            rescale:       Coordinate scale factor (applied before inference).
                           Pass ``None`` or ``1.0`` to skip. Defaults to 1.0.
            num_samples:   Total desired prediction samples. Defaults to 20.
                           If > 20 the model is run multiple times with different
                           seeds and the results are concatenated.
            sampling_time: Seconds per input step. Defaults to 0.2.
            pred_len:      Desired output length (steps at ``sampling_time``).
                           Defaults to 20.

        Returns:
            One ``np.ndarray`` per pedestrian, each ``(pred_len, num_samples, 2)``.
        """
        n_ped = len(input_trajs)
        if n_ped == 0:
            return []

        # ---- resample each observed trajectory to ST training grid --------
        obs_list: list[list[PathNode]] = []
        for traj in input_trajs:
            if rescale is not None and rescale != 1.0:
                traj = [(p[0] * rescale, p[1] * rescale) for p in traj]
            resampled = self._resample(traj, dt_in=sampling_time, dt_out=self.ST_DT)
            if len(resampled) < self.ST_OBS_LEN:
                # Pad at the start with the earliest known position
                pad = [resampled[0]] * (self.ST_OBS_LEN - len(resampled))
                resampled = pad + resampled
            else:
                resampled = resampled[-self.ST_OBS_LEN:]
            obs_list.append(resampled)

        obs_np = np.array(obs_list, dtype=np.float32)          # (n_ped, 8, 2)
        obs_traj = torch.from_numpy(obs_np).to(self.device)

        anchor = self._build_anchor(obs_traj)

        # ---- run inference (multiple passes if num_samples > ST_N_SAMPLES) --
        n_passes = math.ceil(num_samples / self.ST_N_SAMPLES)
        all_passes: list[np.ndarray] = []
        for i in range(n_passes):
            recon = self._predict_once(obs_traj, anchor, seed=i)
            all_passes.append(recon)

        # (total_s, n_ped, 12, 2)  →  trim to exact count
        all_preds = np.concatenate(all_passes, axis=0)[:num_samples]

        # ---- resample each prediction to caller's time grid ----------------
        result: list[np.ndarray] = []
        for ped_i in range(n_ped):
            ped_samples = np.empty((pred_len, num_samples, 2), dtype=np.float32)
            for s_i in range(num_samples):
                traj_st = all_preds[s_i, ped_i]                   # (12, 2)
                traj_list = [
                    (float(traj_st[t, 0]), float(traj_st[t, 1]))
                    for t in range(traj_st.shape[0])
                ]
                resampled_out = self._resample(
                    traj_list, dt_in=self.ST_DT, dt_out=sampling_time
                )
                if len(resampled_out) < pred_len:
                    resampled_out += [resampled_out[-1]] * (pred_len - len(resampled_out))
                else:
                    resampled_out = resampled_out[:pred_len]
                ped_samples[:, s_i, :] = np.array(resampled_out, dtype=np.float32)
            result.append(ped_samples)

        return result

    def clustering_and_fitting_from_samples(
            self,
            traj_samples: np.ndarray,
            eps: float = 10.0,
            min_sample: int = 5,
            enlarge: float = 1.0,
            extra_margin: float = 0.0,
    ):
        """Cluster prediction samples into Gaussian distributions (DBSCAN).

        Identical interface to ``pkg_mp_sgan.MotionPredictor.clustering_and_fitting_from_samples``.

        Args:
            traj_samples: ``(T, num_samples, 2)`` — samples at each future step.
            eps:          DBSCAN neighbourhood radius. Defaults to 10.
            min_sample:   DBSCAN core-point threshold. Defaults to 5.
            enlarge:      Std scaling factor. Defaults to 1.0.
            extra_margin: Additive margin on std. Defaults to 0.0.

        Returns:
            ``(clusters_list, mu_list_list, std_list_list, conf_list_list)``
        """
        if traj_samples.ndim != 3:
            raise ValueError('traj_samples must have shape (T, num_samples, 2).')

        clusters_list, mu_list_list, std_list_list, conf_list_list = [], [], [], []
        total = traj_samples.shape[1]
        for t in range(traj_samples.shape[0]):
            clusters = self.fit_DBSCAN(traj_samples[t], eps=eps, min_sample=min_sample)
            clusters_list.append(clusters)
            mu_list, std_list = self.fit_cluster2gaussian(clusters, enlarge, extra_margin)
            conf_list = [round(len(c) / total, 2) for c in clusters]
            mu_list_list.append(mu_list)
            std_list_list.append(std_list)
            conf_list_list.append(conf_list)

        return clusters_list, mu_list_list, std_list_list, conf_list_list

    # ------------------------------------------------------------------
    # Static utilities
    # ------------------------------------------------------------------

    @staticmethod
    def _resample(traj: list[PathNode], dt_in: float, dt_out: float) -> list[PathNode]:
        """Linearly resample *traj* from ``dt_in`` to ``dt_out`` grid.

        The output covers exactly the same time span as the input.
        """
        if len(traj) < 2:
            return list(traj)
        xs = [p[0] for p in traj]
        ys = [p[1] for p in traj]
        t_in = np.arange(len(traj), dtype=float) * dt_in
        duration = t_in[-1]
        # Generate output times up to (and including) the input end-time
        t_out = np.arange(0, duration + dt_out * 0.5, dt_out)
        t_out = t_out[t_out <= duration + 1e-9]
        xs_out = np.interp(t_out, t_in, xs)
        ys_out = np.interp(t_out, t_in, ys)
        return list(zip(xs_out.tolist(), ys_out.tolist()))

    @staticmethod
    def fit_DBSCAN(data: np.ndarray, eps: float, min_sample: int) -> list[np.ndarray]:
        """Run DBSCAN and return a list of clusters (noise points discarded)."""
        labels = DBSCAN(eps=eps, min_samples=min_sample).fit(data).labels_
        return [data[labels == lbl] for lbl in sorted(set(labels)) if lbl != -1]

    @staticmethod
    def fit_cluster2gaussian(
            clusters: list[np.ndarray],
            enlarge: float = 1.0,
            extra_margin: float = 0.0,
    ) -> tuple[list, list]:
        """Fit each cluster to a (mean, std) Gaussian."""
        mu_list  = [np.mean(c, axis=0) for c in clusters]
        std_list = [np.std(c, axis=0) * enlarge + extra_margin for c in clusters]
        return mu_list, std_list
