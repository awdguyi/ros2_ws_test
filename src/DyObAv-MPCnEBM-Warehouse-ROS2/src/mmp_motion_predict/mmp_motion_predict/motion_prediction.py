import os
import sys
import torch
import numpy as np
import time
from typing import Optional, List
from shapely.geometry import Point, Polygon as ShapelyPolygon

# 魔法陣：連結到 SingularTrajectory
sys.path.append("/home/michael/ai_training_ws/SingularTrajectory")
import baseline
from SingularTrajectory import *
from utils import *

PathNode = tuple[float, float]

class MotionPredictor:
    def __init__(self, config_file_path: str = "/home/michael/ai_training_ws/SingularTrajectory/config/config_example.json", model_suffix: str = "zara2", ref_image_path:Optional[str]=None) -> None:
        print("\n🚀 [*] 正在從實驗室喚醒 SingularTrajectory SOTA 大腦...\n")
        class FakeArgs:
            cfg = "/home/michael/ai_training_ws/SingularTrajectory/config/config_example.json"
            gpu_id = "0"
            test = True
            tag = "SingularTrajectory-TEMP"
            
        self.args = FakeArgs()
        self.hyper_params = get_exp_config(self.args.cfg)
        os.environ["CUDA_VISIBLE_DEVICES"] = self.args.gpu_id
        
        PredictorModel = getattr(baseline, self.hyper_params.baseline).TrajectoryPredictor
        hook_func = DotDict({
            "model_forward_pre_hook": getattr(baseline, self.hyper_params.baseline).model_forward_pre_hook,
            "model_forward": getattr(baseline, self.hyper_params.baseline).model_forward,
            "model_forward_post_hook": getattr(baseline, self.hyper_params.baseline).model_forward_post_hook
        })
        
        ModelTrainer = getattr(trainer, *[s for s in trainer.__dict__.keys() if self.hyper_params.baseline in s.lower()])
        self.my_trainer = ModelTrainer(base_model=PredictorModel, model=SingularTrajectory, hook_func=hook_func, args=self.args, hyper_params=self.hyper_params)
        
        self.model = self.my_trainer.model
        _ckpt_base = "/home/michael/ai_training_ws/SingularTrajectory/checkpoints/SingularTrajectory-TEMP"
        weight_path = os.path.join(_ckpt_base, model_suffix, "model_best.pth")
        print(f"[MotionPredictor] Loading checkpoint: {weight_path}")
        self.model.load_state_dict(torch.load(weight_path))
        self.model.float()  # checkpoint saved in fp16; force all params to fp32

        self.device = torch.device('cuda')
        self.model.to(self.device)
        self.model.eval()
        
        self.obs_len = self.hyper_params.obs_len
        self.pred_len = self.hyper_params.pred_len

        self.ebl = None
        self.ebl_ref_image_raw = None

    def get_motion_prediction(self, input_traj: list[PathNode], rescale:Optional[float]=1.0, debug:bool=False):
        t = list(input_traj)
        if rescale is not None:
            t = [(x[0]*rescale, x[1]*rescale) for x in t]

        if len(t) == 0:
            t = [(0.0, 0.0)] * self.obs_len
        elif len(t) < self.obs_len:
            t = [t[0]] * (self.obs_len - len(t)) + t
        else:
            t = t[-self.obs_len:]
            
        obs_traj = torch.tensor([t], dtype=torch.float16).to(self.device)
        
        with torch.no_grad():
            try:
                future_traj = self.model(obs_traj) 
                print(f"✅ [大腦推論成功] 算出來的 Shape 是: {future_traj.shape}")
                future_traj_np = future_traj.cpu().numpy().astype(np.float32)
            except Exception as e:
                print("\n❌❌❌ [大腦推論崩潰] 進入保護機制！❌❌❌")
                print(f"錯誤原因：{e}\n")
                future_traj_np = np.zeros((1, 20, self.pred_len, 2), dtype=np.float32)
                last_pt = np.array(t[-1])
                for k in range(20):
                    for step in range(self.pred_len):
                        future_traj_np[0, k, step] = last_pt + np.array([0.1*(step+1), 0.1*(step+1)])

        mu = np.mean(future_traj_np, axis=1)[0]
        std = np.std(future_traj_np, axis=1)[0]
        
        mu_list_list, std_list_list, conf_list_list, clusters_list = [], [], [], []
        
        for step in range(self.pred_len):
            mu_list_list.append([tuple(mu[step])])
            std_list_list.append([tuple(std[step])])
            conf_list_list.append([1.0])
            clusters_list.append([tuple(mu[step])])
            
        if debug: return clusters_list, mu_list_list, std_list_list, conf_list_list, None, None
        return clusters_list, mu_list_list, std_list_list, conf_list_list

    def get_motion_prediction_samples(self, *args, **kwargs): return np.zeros((self.pred_len * 10, 2))
    def clustering_and_fitting_from_samples(self, *args, **kwargs): return [], [], [], []

    def _cluster_trajectories(self, samples: np.ndarray, k: int):
        """K-means on final positions to cluster trajectory samples into k modes.

        Args:
            samples: (n_samples, pred_len, 2)
        Returns:
            labels (n_samples,), traj_centers (k, pred_len, 2)
        """
        n = samples.shape[0]
        k = min(k, n)
        features = samples[:, -1, :]  # cluster by final position (n, 2)

        # K-means++ init (fixed seed for reproducibility)
        rng = np.random.RandomState(42)
        centers = features[[rng.randint(n)]].copy()
        for _ in range(k - 1):
            dists = np.min(
                np.sum((features[:, None, :] - centers[None, :, :]) ** 2, axis=-1),
                axis=1)
            probs = dists / (dists.sum() + 1e-9)
            centers = np.vstack([centers, features[rng.choice(n, p=probs)]])

        labels = np.zeros(n, dtype=int)
        for _ in range(10):
            dists = np.sum(
                (features[:, None, :] - centers[None, :, :]) ** 2, axis=-1)  # (n, k)
            labels = dists.argmin(axis=1)
            for ki in range(k):
                mask = labels == ki
                if mask.any():
                    centers[ki] = features[mask].mean(axis=0)

        traj_centers = np.zeros((k, samples.shape[1], 2), dtype=np.float32)
        for ki in range(k):
            mask = labels == ki
            traj_centers[ki] = samples[mask].mean(axis=0) if mask.any() else samples[0]

        return labels, traj_centers

    @staticmethod
    def _filter_by_obstacles(samples: np.ndarray,
                             obstacle_polys: List[ShapelyPolygon],
                             min_ratio: float = 0.25) -> np.ndarray:
        """Remove samples whose trajectory passes through any static obstacle.

        samples: (n_samples, pred_len, 2) in real-world metres
        min_ratio: if fewer than this fraction survive, skip filtering entirely
                   (avoids degenerate single-sample clustering when all samples
                   happen to be near an obstacle boundary).
        Returns: (M, pred_len, 2), M >= 1
        """
        if not obstacle_polys:
            return samples
        valid = []
        for s in range(samples.shape[0]):
            ok = True
            for t in range(samples.shape[1]):
                pt = Point(float(samples[s, t, 0]), float(samples[s, t, 1]))
                for poly in obstacle_polys:
                    if poly.contains(pt):
                        ok = False
                        break
                if not ok:
                    break
            if ok:
                valid.append(s)
        # Too few survivors → filter is degenerate, return all originals
        if len(valid) < max(1, int(samples.shape[0] * min_ratio)):
            return samples
        return samples[valid]

    def _ebl_score_samples(self, obs_traj_pixels: list, samples: np.ndarray) -> np.ndarray:
        """Score ST samples using EBL energy map. Lower = more likely.

        obs_traj_pixels: list of (px, py) in EBL image coords (world → pixel)
        samples: (n_samples, pred_len, 2) in world coordinates
        Returns: (n_samples,) mean energy per sample
        """
        try:
            energy_map = self.ebl.inference(obs_traj_pixels, self.ebl_ref_image_raw.clone(), rescale=1.0)
            energy_np = energy_map.numpy()  # (pred_len_ebl, H, W)
            H, W = energy_np.shape[1], energy_np.shape[2]
            t_steps = min(samples.shape[1], energy_np.shape[0])
            scores = np.zeros(samples.shape[0], dtype=np.float32)
            for s_idx in range(samples.shape[0]):
                total = 0.0
                for t in range(t_steps):
                    wx = float(samples[s_idx, t, 0])
                    wy = float(samples[s_idx, t, 1])
                    px = int(np.clip((wx + 15.0) * 10.0, 0, W - 1))
                    py = int(np.clip(H - 1 - (wy + 15.0) * 10.0, 0, H - 1))
                    total += energy_np[t, py, px]
                scores[s_idx] = total / t_steps
            return scores
        except Exception as e:
            print(f"[EBL] scoring error: {e}")
            return np.zeros(samples.shape[0], dtype=np.float32)

    def predict_all_humans(self, trajs_real, k_modes: int = 1,
                           obstacle_polys: Optional[List[ShapelyPolygon]] = None):
        # Downsample from 10 Hz (actor_pose) to 2.5 Hz (SingularTrajectory training cadence).
        # Take every 4th point going backwards from the most recent observation so each
        # consecutive pair is 0.4 s apart, matching what the model was trained on.
        POSE_HZ   = 10    # actor_pose plugin update rate
        TRAIN_HZ  = 2.5   # ETH/UCY training frame rate
        DS        = max(1, int(POSE_HZ / TRAIN_HZ))   # downsample factor = 4

        batch_input = []
        for traj in trajs_real:
            t = list(traj)
            # Pick every DS-th sample starting from the most recent, then flip back to
            # chronological order.  Result: up to obs_len frames at 2.5 Hz.
            t_ds = t[::-1][::DS][:self.obs_len][::-1]
            if len(t_ds) == 0:
                t_ds = [(0.0, 0.0)] * self.obs_len
            elif len(t_ds) < self.obs_len:
                t_ds = [t_ds[0]] * (self.obs_len - len(t_ds)) + t_ds
            batch_input.append(t_ds)

        N = len(trajs_real)
        last_positions = np.array([batch_input[i][-1] for i in range(N)], dtype=np.float32)
        # velocity is now per 0.4 s step — matches PRED_DT directly
        velocities = np.array([
            [batch_input[i][-1][0] - batch_input[i][-2][0],
             batch_input[i][-1][1] - batch_input[i][-2][1]]
            for i in range(N)
        ], dtype=np.float32)

        obs_traj = torch.tensor(batch_input, dtype=torch.float32).to(self.device)

        model_ok = False
        with torch.no_grad():
            try:
                k_dim = self.hyper_params.k              # 4
                s_dim = self.hyper_params.num_samples    # 20
                adaptive_anchor = torch.zeros(
                    (N, k_dim, s_dim), dtype=torch.float32, device=self.device)
                scene_mask = torch.ones(
                    (N, N), dtype=torch.bool, device=self.device)
                addl_info = {
                    "scene_mask":      scene_mask,
                    "num_samples":     s_dim,
                    "inference_steps": 5,   # fewer diffusion steps → faster
                }
                output = self.model(obs_traj, adaptive_anchor, addl_info=addl_info)
                # recon_traj: (s, N, pred_len, 2) → transpose to (N, s, pred_len, 2)
                future_traj_np = output["recon_traj"].cpu().numpy().astype(np.float32)
                future_traj_np = future_traj_np.transpose(1, 0, 2, 3)
                model_ok = True
                print(f"[SingularTraj] ✅ model OK, shape={future_traj_np.shape}")
            except Exception as e:
                print(f"[SingularTraj] fallback: {e}")
                future_traj_np = np.zeros((N, 20, self.pred_len, 2), dtype=np.float32)

        if not model_ok:
            # Constant-velocity at PRED_DT per step (velocity already at 2.5 Hz scale)
            for i in range(N):
                for ki in range(20):
                    for step in range(self.pred_len):
                        future_traj_np[i, ki, step] = (
                            last_positions[i] + velocities[i] * (step + 1)
                        )

        # Pre-filter once per pedestrian (used by both branches below)
        filtered_samples = []
        for i in range(N):
            s = future_traj_np[i]
            if obstacle_polys:
                s = self._filter_by_obstacles(s, obstacle_polys)
            filtered_samples.append(s)

        # EBL energy filter: discard ST samples in high-energy (unlikely) regions
        if self.ebl is not None:
            ebl_filtered = []
            for i in range(N):
                s = filtered_samples[i]
                H_map = self.ebl_ref_image_raw.shape[0]
                obs_px = [(float((batch_input[i][t][0] + 15.0) * 10.0),
                           float(H_map - 1 - (batch_input[i][t][1] + 15.0) * 10.0))
                          for t in range(len(batch_input[i]))]
                scores = self._ebl_score_samples(obs_px, s)
                cutoff = np.percentile(scores, 60)
                keep = np.where(scores <= cutoff)[0]
                min_keep = max(1, int(s.shape[0] * 0.25))
                if len(keep) < min_keep:
                    ebl_filtered.append(s)
                else:
                    ebl_filtered.append(s[keep])
            filtered_samples = ebl_filtered

        if k_modes <= 1:
            # Single mean trajectory per pedestrian (original behaviour)
            mu_list_list, std_list_list, conf_list_list = [], [], []
            for t in range(self.pred_len):
                mu_row, std_row, conf_row = [], [], []
                for i in range(N):
                    s = filtered_samples[i]
                    mu_row.append(tuple(np.mean(s, axis=0)[t]))
                    std_row.append(tuple(np.std(s,  axis=0)[t]))
                    conf_row.append(1.0)
                mu_list_list.append(mu_row)
                std_list_list.append(std_row)
                conf_list_list.append(conf_row)
            return mu_list_list, std_list_list, conf_list_list

        # K-modes: cluster samples into k_modes groups per pedestrian.
        # Virtual pedestrian index vi = i*k_modes + ki
        N_virtual = N * k_modes
        all_centers = np.zeros((N_virtual, self.pred_len, 2), dtype=np.float32)
        all_weights = np.zeros(N_virtual, dtype=np.float32)

        for i in range(N):
            samples_i = filtered_samples[i]
            labels, traj_centers = self._cluster_trajectories(samples_i, k_modes)
            k_actual = traj_centers.shape[0]  # min(k_modes, n_filtered_samples)
            for ki in range(k_modes):
                vi = i * k_modes + ki
                if ki < k_actual:
                    all_centers[vi] = traj_centers[ki]
                    all_weights[vi] = float((labels == ki).sum()) / samples_i.shape[0]
                else:
                    # Fewer valid clusters than k_modes — reuse last center, zero weight
                    all_centers[vi] = traj_centers[k_actual - 1]
                    all_weights[vi] = 0.0

        mu_list_list, std_list_list, conf_list_list = [], [], []
        for t in range(self.pred_len):
            mu_list_list.append([tuple(all_centers[vi, t]) for vi in range(N_virtual)])
            std_list_list.append([(0.15, 0.15)] * N_virtual)
            conf_list_list.append([float(all_weights[vi]) for vi in range(N_virtual)])
        return mu_list_list, std_list_list, conf_list_list
