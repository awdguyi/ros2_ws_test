import os
import csv
import math
import time
import threading
from typing import cast, Optional

try:
    import wandb
    _WANDB_OK = True
except ImportError:
    _WANDB_OK = False

import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup, ReentrantCallbackGroup

from ament_index_python.packages import get_package_share_directory # type: ignore

from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Point, Polygon, Point32 # type: ignore
from visualization_msgs.msg import Marker, MarkerArray
from std_srvs.srv import Empty, Trigger
from gazebo_msgs.msg import EntityState
from gazebo_msgs.srv import SetEntityState

from map_interfaces.msg import PolygonObject # type: ignore
from mps_interfaces.srv import GetRobotSchedule, GetInflatedMap # type: ignore
from zmr_interfaces.msg import CurrentFutureStates # type: ignore
from zmr_interfaces.srv import GetOtherRobotStates # type: ignore
from mmp_interfaces.msg import MotionPredictionResult # type: ignore
from mmp_interfaces.msg import HumanTrajectory, HumanTrajectoryArray # type: ignore

from .local_traj_plan import LocalTrajPlanner
from .mpc_trajectory_tracker import TrajectoryTracker
from .mpc_trajectory_tracker import DebugInfo
from .motion_model import UnicycleModel
from .configs import MpcConfiguration, CircularRobotSpecification


class MpcControllerNode(Node):
    def __init__(self):
        super().__init__(self.__class__.__name__)
        self.get_logger().info(f"{self.__class__.__name__} init..")

        time.sleep(5) # wait for other nodes to start

        pkg_root_dir = get_package_share_directory('zmr_mpc')

        self.declare_parameter('timer_period', 0.2)
        self.timer_period = self.get_parameter('timer_period').value

        # SingularTrajectory ETH/UCY dataset step = 0.4s (2.5 Hz); must match training data
        self.declare_parameter('pred_dt', 0.4)
        self.pred_dt = self.get_parameter('pred_dt').value

        # Note that this will be set to False if the service is not available
        self.declare_parameter('enable_fleet_manager', False)
        self.enable_fleet_manager = self.get_parameter('enable_fleet_manager').value

        self.declare_parameter('config_mpc_fname', 'mpc_default.yaml')
        config_mpc_fname = self.get_parameter('config_mpc_fname').value
        self.config_mpc_fpath = os.path.join(pkg_root_dir, 'config', config_mpc_fname)

        self.declare_parameter('config_robot_fname', 'robot_spec.yaml')
        config_robot_fname = self.get_parameter('config_robot_fname').value
        self.config_robot_fpath = os.path.join(pkg_root_dir, 'config', config_robot_fname)

        self.declare_parameter('robot_id', 0)
        self.robot_id = self.get_parameter('robot_id').value

        self.declare_parameter('robot_namespace', 'zmr_X')
        self.robot_namespace = self.get_parameter('robot_namespace').value
        
        self.cmd_vel_name   = 'cmd_vel'
        self.odom_name      = 'odom'
        self.dynobs_name    = '/motion_prediction_result'
        self.schedule_name  = 'robot_schedule'

        # CB group
        client_cb_group = MutuallyExclusiveCallbackGroup()
        timer_cb_group = MutuallyExclusiveCallbackGroup()

        # Timer for publishing cmd_vel
        self.kt = 0
        self.timer = self.create_timer(self.timer_period, self.timer_callback, callback_group=timer_cb_group)

        # Subscriber to odometry
        self.odom_subscription = self.create_subscription(
            Odometry,
            self.odom_name,
            self.odom_callback,
            10
        )

        # Subscriber to dynamic obstacles
        self.dynobs_subscription = self.create_subscription(
            MotionPredictionResult,
            self.dynobs_name,
            self.dynobs_callback,
            10
        )
        self.motion_prediction_result = []

        # Subscriber to raw pedestrian trajectories (for stable C4 heading estimation)
        self.raw_traj_subscription = self.create_subscription(
            HumanTrajectoryArray,
            '/human_traj_array',
            self.raw_traj_callback,
            10
        )
        self.raw_traj_data = None
        self._dir_scale_filtered = {}  # Nn → low-pass filtered dir_scale
        # C7.1 lane selector (disabled — kept for rollback):
        # self._selected_lane: str = 'center'
        # self._lane_score_center: float = 0.0
        # self._lane_score_right: float = 0.0
        # self._lane_hold_count: int = 0
        self._lane_offset_filtered: float = 0.0   # C7.3: LP-filtered lateral offset fed to MPC
        self._last_v: float = 0.0                 # C7.3: previous step commanded velocity for TTC
        self._mu_cache: list = []                  # C7: predicted positions (kept for rollback)
        self._conf_cache: list = []                # C7: confidence values (kept for rollback)

        # Get the inflated map from the service
        map_service_name = '/get_inflated_map'
        self.get_map_client = self.create_client(
            GetInflatedMap,
            map_service_name,
            callback_group=client_cb_group
        )
        while not self.get_map_client.wait_for_service(timeout_sec=self.timer_period*10):
            self.get_logger().info('Map service not available, waiting again...')
        self.map_request = GetInflatedMap.Request()

        # Get the response from the service
        service_name = '/get_robot_schedule'
        self.get_schedule_client = self.create_client(
            GetRobotSchedule,
            service_name,
            callback_group=client_cb_group
        )
        while not self.get_schedule_client.wait_for_service(timeout_sec=self.timer_period*10):
            self.get_logger().info('Schedule service not available, waiting again...')
        self.robot_schedule_request = GetRobotSchedule.Request()

        # Get the other robot states from the service
        robot_service_name = '/get_other_robot_states'
        self.get_robot_states_client = self.create_client(
            GetOtherRobotStates,
            robot_service_name,
            callback_group=client_cb_group
        )
        while not self.get_robot_states_client.wait_for_service(timeout_sec=self.timer_period*10):
            self.get_logger().info('Robot states service not available and will be disabled.')
            self.enable_fleet_manager = False
            break
        self.robot_states_request = GetOtherRobotStates.Request()

        self.declare_parameter('reset_on_finish', True)
        self._reset_on_finish: bool = bool(self.get_parameter('reset_on_finish').value)
        self.declare_parameter('reset_service_name', '/reset_simulation')
        self._reset_service_name: str = self.get_parameter('reset_service_name').value
        self.reset_world_client = self.create_client(
            Empty,
            self._reset_service_name,
            callback_group=client_cb_group
        )
        self.declare_parameter('set_entity_state_service_name', '/set_entity_state')
        self._set_entity_state_service_name: str = self.get_parameter(
            'set_entity_state_service_name').value
        self.set_entity_state_client = self.create_client(
            SetEntityState,
            self._set_entity_state_service_name,
            callback_group=client_cb_group
        )
        self.declare_parameter('robot_entity_name', f'{self.robot_namespace}/robot')
        self._robot_entity_name: str = self.get_parameter('robot_entity_name').value
        self.declare_parameter('robot_init_x', 1.0)
        self.declare_parameter('robot_init_y', -2.2)
        self.declare_parameter('robot_init_z', 0.0)
        self.declare_parameter('robot_init_theta', 0.0)
        self._robot_init_x = float(self.get_parameter('robot_init_x').value)
        self._robot_init_y = float(self.get_parameter('robot_init_y').value)
        self._robot_init_z = float(self.get_parameter('robot_init_z').value)
        self._robot_init_theta = float(self.get_parameter('robot_init_theta').value)
        self.declare_parameter('rerandomize_actors_on_reset', True)
        self._rerandomize_actors_on_reset: bool = bool(
            self.get_parameter('rerandomize_actors_on_reset').value
        )
        self.declare_parameter('rerandomize_actors_service_name', '/rerandomize_actors')
        self._rerandomize_actors_service_name: str = self.get_parameter(
            'rerandomize_actors_service_name').value
        self.rerandomize_actors_client = self.create_client(
            Trigger,
            self._rerandomize_actors_service_name,
            callback_group=client_cb_group
        )
        self.declare_parameter('clear_actor_trajs_service_name', '/clear_actor_trajs')
        self._clear_actor_trajs_service_name: str = self.get_parameter(
            'clear_actor_trajs_service_name').value
        self.clear_actor_trajs_client = self.create_client(
            Trigger,
            self._clear_actor_trajs_service_name,
            callback_group=client_cb_group
        )
        self.reset_policy_service = self.create_service(
            Trigger,
            'reset_mpc_policy',
            self._reset_policy_callback,
        )
        self.release_policy_service = self.create_service(
            Trigger,
            'release_mpc_policy',
            self._release_policy_callback,
        )
        self._reset_pending = False
        self._waiting_reset_odom = False
        self._reset_pending_since: Optional[float] = None
        self._reset_timeout_sec = 15.0

        # Publisher for cmd_vel
        self.cmd_vel_publisher = self.create_publisher(
            Twist,
            self.cmd_vel_name,
            10
        )

        # Publisher for the current and future states of the robot
        states_msg_name = 'robot_states'
        self.robot_state_publisher = self.create_publisher(
            CurrentFutureStates,
            states_msg_name,
            10
        )
        
        # Publisher for the schedule/path visualization
        viz_msg_name = f'robot_{self.robot_id}_schedule_viz'
        self.schedule_viz_publisher = self.create_publisher(
            MarkerArray,
            viz_msg_name,
            10
        )
        # Publisher for the dynamic obstacle trajectories as seen by MPC (post-resampling)
        self.dyn_obs_mpc_viz_publisher = self.create_publisher(
            MarkerArray,
            '/dyn_obs_mpc_viz',
            10
        )
        self._dyn_obs_mpc_viz_last_count = 0
        self.color_node = (1.0, 0.0, 0.0) # red
        self.color_edge = (1.0, 1.0, 1.0) # white

        self.cfg_mpc = MpcConfiguration.from_yaml(self.config_mpc_fpath)
        self.cfg_robot = CircularRobotSpecification.from_yaml(self.config_robot_fpath)

        self.planner = LocalTrajPlanner(self.cfg_mpc.ts, self.cfg_mpc.N_hor,
                                        self.cfg_robot.lin_vel_max, verbose=False)
        self.controller = TrajectoryTracker(self.cfg_mpc, self.cfg_robot)
        self.controller.load_motion_model(UnicycleModel(self.cfg_robot.ts))

        self.odom_received = False
        self.dynobs_received = False
        self.motion_prediction_stamp = None
        self.schedule_received = False
        self.map_received = False
        self._obs_in_zone = False   # True while nearest obstacle < zone radius
        self._obs_zone_frames = 0   # frames spent continuously in zone

        self.boundary_coords = None
        self.obstacle_list = None
        self.last_pred_states = None

        self.first_message = True

        # --- Experiment recorder (zero impact unless log_csv:=true) ---
        self.declare_parameter('log_csv', False)
        self._log_csv: bool = self.get_parameter('log_csv').value
        self.declare_parameter('scenario_id', 'S0')
        self._scenario_id: str = self.get_parameter('scenario_id').value
        self.declare_parameter('max_task_time', 120.0)
        self._max_task_time: float = self.get_parameter('max_task_time').value
        self.declare_parameter('goal_tolerance', 0.5)
        self._goal_tolerance: float = self.get_parameter('goal_tolerance').value

        self.declare_parameter('log_wandb', False)
        self._log_wandb: bool = self.get_parameter('log_wandb').value and _WANDB_OK
        self._wandb_run = None
        self.declare_parameter('predictor_variant', 'zara2')
        self._predictor_variant: str = self.get_parameter('predictor_variant').value
        self.declare_parameter('human_radius_inflation', 0.25)
        self._human_radius_inflation: float = float(
            self.get_parameter('human_radius_inflation').value
        )
        if self._log_wandb:
            try:
                wandb.login()
            except Exception as e:
                self.get_logger().error(f"[W&B] login failed ({e}), disabling W&B")
                self._log_wandb = False

        if self._log_csv:
            self._csv_path = os.path.expanduser(
                f'~/ros2_ws_test/experiment_results_robot{self.robot_id}.csv')
            self._run_id: int = 0
            self._awaiting_departure: bool = False
            self._last_goal_pos: Optional[tuple] = None
            self._init_run_tracking()
            self._ensure_csv_header()
            self.get_logger().info(
                f"[Recorder] Enabled — scenario={self._scenario_id}, "
                f"csv={self._csv_path}, wandb={self._log_wandb}")

        ### Send prerequisite service requests
        self.send_map_request()
        self.send_schedule_request()

    def timer_callback(self):
        if self._reset_pending:
            if (
                self._reset_pending_since is not None
                and time.time() - self._reset_pending_since > self._reset_timeout_sec
            ):
                self.get_logger().warn("[Recorder] Reset/rerandomize timeout; resuming MPC")
                self._release_reset_pending()
            self.cmd_vel_publisher.publish(Twist())
            return
        if not self.odom_received:
            self.get_logger().debug("Waiting for odometry message...")
            return
        if not self.schedule_received:
            self.get_logger().debug("Waiting for schedule message...")
            return
        if not self.map_received:
            self.get_logger().debug("Waiting for map info message...")
            return

        self.kt += 1
        
        current_state = np.array([self.x, self.y, self.theta])
        if self.first_message:
            scheduled_path_coords = self.ref_path_coords
            goal_coord = scheduled_path_coords[-1]
            goal_coord_prev = scheduled_path_coords[-2]
            goal_heading = np.arctan2(goal_coord[1]-goal_coord_prev[1], goal_coord[0]-goal_coord_prev[0])
            goal_state = np.array([*goal_coord, goal_heading])
            self.controller.load_init_states(current_state, goal_state)
            self.first_message = False

        self.controller.set_current_state(current_state)

        if self.controller.finishing:
            ref_states, ref_speed, *_ = self.planner.get_local_ref(self.kt*self.cfg_mpc.ts, (float(current_state[0]), float(current_state[1])))
        else:
            ref_states, ref_speed, *_ = self.planner.get_local_ref(self.kt*self.cfg_mpc.ts, (float(current_state[0]), float(current_state[1])), external_ref_speed=self.controller.base_speed)
        
        if self.last_pred_states is not None:
            if np.dot(ref_states[-1, :2]-ref_states[0, :2], self.last_pred_states[-1, :2]-self.last_pred_states[0, :2]) < 0:
                ref_states = ref_states
            else:
                ref_states = ref_states*0.9 + self.last_pred_states*0.1

        # C7 right-reference shift disabled: MPC now tracks the unshifted
        # center reference and avoids ST prediction tubes through dynamic
        # obstacle constraints only.
        yaw = ref_states[0, 2]
        dx  = self.x - ref_states[0, 0]
        dy  = self.y - ref_states[0, 1]
        signed_right_error = dx * math.sin(yaw) - dy * math.cos(yaw)
        ttc_oncoming = float('inf')
        strength = 0.0
        target_offset = 0.0
        avoid_target = 0.0
        recenter_target = 0.0
        c7_phase = 0.0
        position_capped = False
        committed_avoid = False
        early_preview = False
        early_offset = 0.0
        st_center_score = 0.0
        st_center_onc = 0.0
        st_center_samd = 0.0
        st_benefit = 0.0
        self._lane_offset_filtered = 0.0

        self.controller.set_ref_states(ref_states, ref_speed=ref_speed)

        other_robot_states = None
        if self.enable_fleet_manager:
            robot_states_response = self.send_robot_states_request()
            ors_in_order = robot_states_response.other_robot_states_in_order
            if len(ors_in_order) > 0:
                other_robot_states = [-10] * self.cfg_mpc.ns * (self.cfg_mpc.N_hor+1) * self.cfg_mpc.Nother
                idx = 0
                idx_pred = self.cfg_mpc.ns * self.cfg_mpc.Nother
                for i in range(len(ors_in_order)//(self.cfg_mpc.ns * (self.cfg_mpc.N_hor+1))):
                    current_ors = ors_in_order[i:i+self.cfg_mpc.ns * (self.cfg_mpc.N_hor+1)]
                    other_robot_states[idx : idx+self.cfg_mpc.ns] = current_ors[:self.cfg_mpc.ns]
                    other_robot_states[idx_pred : idx_pred+self.cfg_mpc.ns*self.cfg_mpc.N_hor] = current_ors[self.cfg_mpc.ns:]
                    idx += self.cfg_mpc.ns
                    idx_pred += self.cfg_mpc.ns*self.cfg_mpc.N_hor
                # self.get_logger().info(f"Other robot states: {other_robot_states}")
            #     self.get_logger().info(f"Get")
            # else:
            #     self.get_logger().info(f"No Get")

        full_dyn_obstacle_list = None
        dir_scales = []
        if self.dynobs_received:
            try:
                mu_list_list, std_list_list, conf_list_list = self.motion_prediction_result
                raw_n_obs = max([len(x) for x in mu_list_list])
                selected_dynobs_indices = self._select_nearest_dynobs_indices(mu_list_list, raw_n_obs)
                n_obs = len(selected_dynobs_indices)
                # Initialize to far-away dummy with alpha=0; unfilled slots no longer
                # create fake obstacles at the origin.
                dyn_obs_list = [[[-1000.0, -1000.0, 0.2, 0.2, 0, 0.0]] * (self.cfg_mpc.N_hor + 1) for _ in range(n_obs)]

                # C7.4a: re-enable prediction caches for ST direction-aware scoring
                self._mu_cache   = [[None] * (self.cfg_mpc.N_hor + 1) for _ in range(n_obs)]
                self._conf_cache = [[0.0]  * (self.cfg_mpc.N_hor + 1) for _ in range(n_obs)]

                pred_steps = len(mu_list_list)

                # C4: direction-aware radius scaling from stable raw trajectory history
                dir_scales = self._compute_stable_dir_scales(raw_n_obs, mu_list_list)

                # ST line avoidance: use the predicted line itself. The solver
                # adds the robot width later, so this introduces no extra
                # pedestrian-side safety buffer.
                _ST_TUBE_RADIUS = 0.25
                _ST_CONF_ACTIVE = 1e-3
                _DUMMY_DYN_OBS = [-1000.0, -1000.0, 0.2, 0.2, 0, 0.0]

                # Direct Tt→pred_step mapping (matches May-14 git baseline).
                for Tt, (mu_list, std_list, conf_list) in enumerate(
                        zip(mu_list_list, std_list_list, conf_list_list)):
                    if Tt > self.cfg_mpc.N_hor:
                        break
                    for slot_idx, raw_idx in enumerate(selected_dynobs_indices):
                        if raw_idx >= len(mu_list) or raw_idx >= len(std_list) or raw_idx >= len(conf_list):
                            continue
                        mu = mu_list[raw_idx]
                        std = std_list[raw_idx]
                        conf = conf_list[raw_idx]
                        if conf <= _ST_CONF_ACTIVE or abs(mu[0]) >= 999.0 or abs(mu[1]) >= 999.0:
                            dyn_obs_list[slot_idx][Tt] = _DUMMY_DYN_OBS
                            self._mu_cache[slot_idx][Tt]   = None
                            self._conf_cache[slot_idx][Tt] = 0.0
                            continue

                        base_rx = max(std[0], _ST_TUBE_RADIUS)
                        base_ry = max(std[1], _ST_TUBE_RADIUS)
                        std_x = base_rx + self._human_radius_inflation
                        std_y = base_ry + self._human_radius_inflation
                        dyn_obs_list[slot_idx][Tt] = [mu[0], mu[1], std_x, std_y, 0, conf]
                        self._mu_cache[slot_idx][Tt]   = mu    # C7.4a
                        self._conf_cache[slot_idx][Tt] = conf  # C7.4a

                full_dyn_obstacle_list = dyn_obs_list
                self.dyn_obs_mpc_viz_publisher.publish(
                    self._dyn_obs_list_to_vis_msg(dyn_obs_list))
                self.get_logger().debug(
                    f"[DynObs] n_obs={n_obs}/{raw_n_obs} pred_steps={pred_steps}")
            except Exception as e:
                self.get_logger().error(f"[DynObs] 建構失敗: {e}", throttle_duration_sec=2.0)

        actions, pred_states, current_refs, debug_info = self.controller.run_step(
            static_obstacles=self.obstacle_list,
            full_dyn_obstacle_list=full_dyn_obstacle_list,
            other_robot_states=other_robot_states,
            map_updated=False)
        v, w = actions[-1]
        self._last_v = float(v)  # C7.3: cache for next step's TTC

        # Immediate human body no-speed zone. This matches the red transparent
        # body circle published in /dyn_obs_mpc_viz and intentionally uses only
        # Tt=0, not the future prediction tube.
        _zone_scale = 1.0
        if full_dyn_obstacle_list:
            for obs_traj in full_dyn_obstacle_list:
                if not obs_traj:
                    continue
                if self._robot_inside_dyn_obstacle_step(obs_traj[0]):
                    _zone_scale = 0.0
                    break
        v = float(v) * _zone_scale
        if _zone_scale == 0.0:
            w = 0.0

        # self.print_debug_info(v, w, debug_info)

        cmd_vel = Twist()
        ### For differential drive robot, use the robot frame ###
        cmd_vel.linear.x = v
        cmd_vel.angular.z = w
        ### For omnidirectional robot, use the world frame ###
        # cmd_vel.linear.x = v * math.cos(self.theta)
        # cmd_vel.linear.y = v * math.sin(self.theta)
        # cmd_vel.angular.z = w

        cur_future_states = [self.x, self.y, self.theta] + [x for subarray in pred_states for x in subarray]
        cur_future_states = [float(x) for x in cur_future_states]
        robot_states = CurrentFutureStates()
        robot_states.robot_states = cur_future_states

        # --- Recorder: passive per-step collection (no effect on control) ---
        if self._log_csv:
            # After a run ends the robot stays near the goal; wait until it moves away
            # before starting the next run so we don't log 0-second phantom runs.
            if self._awaiting_departure and self._last_goal_pos is not None:
                d = math.hypot(self.x - self._last_goal_pos[0],
                               self.y - self._last_goal_pos[1])
                if d > self._goal_tolerance * 2:
                    self._awaiting_departure = False

            if not self._task_started and self.schedule_received and not self._awaiting_departure:
                self._run_start_time = time.time()
                self._task_started = True
                self._goal_pos = self.ref_path_coords[-1] if self.ref_path_coords else None
                self.get_logger().info(
                    f"[Recorder] Run {self._run_id} started, goal={self._goal_pos}")
                if self._log_wandb:
                    _cfg = {
                        "scenario":          self._scenario_id,
                        "predictor_variant": self._predictor_variant,
                        "qrpd":              self.cfg_mpc.qrpd,
                        "qvel":              self.cfg_mpc.qvel,
                        "qstcobs":           self.cfg_mpc.qstcobs,
                        "qdynobs":           self.cfg_mpc.qdynobs,
                        "ang_acc_penalty":   self.cfg_mpc.ang_acc_penalty,
                        "N_hor":             self.cfg_mpc.N_hor,
                        "ts":                self.cfg_mpc.ts,
                    }
                    _name = f"{self._scenario_id}_run{self._run_id}"
                    def _init_wandb(cfg=_cfg, name=_name):
                        try:
                            r = wandb.init(
                                project="mpc-warehouse-navigation",
                                name=name, config=cfg,
                                reinit='finish_previous',
                            )
                            self._wandb_run = r
                            self.get_logger().info(f"[W&B] Run: {r.url}")
                        except Exception as e:
                            self.get_logger().error(
                                f"[W&B] init failed ({e}), disabling")
                            self._log_wandb = False
                    threading.Thread(target=_init_wandb, daemon=True).start()

            if self._task_started:
                self._solver_times.append(debug_info['step_runtime'])
                self._v_list.append(float(v))
                self._w_list.append(float(w))
                step_dev = 0.0
                if self.ref_path_coords:
                    step_dev = self._seg_deviation(self.x, self.y, self.ref_path_coords)
                    self._path_deviations.append(step_dev)
                step_ped_dist = float('inf')
                if full_dyn_obstacle_list:
                    for obs in full_dyn_obstacle_list:
                        if abs(obs[0][0]) < 500:
                            d = math.hypot(obs[0][0] - self.x, obs[0][1] - self.y)
                            self._min_ped_clearance = min(self._min_ped_clearance, d)
                            step_ped_dist = min(step_ped_dist, d)
                if other_robot_states is not None:
                    ns = self.cfg_mpc.ns
                    for i in range(self.cfg_mpc.Nother):
                        ox = other_robot_states[i * ns]
                        oy = other_robot_states[i * ns + 1]
                        if ox != -10:
                            d = math.hypot(ox - self.x, oy - self.y)
                            self._min_robot_clearance = min(self._min_robot_clearance, d)
                elapsed = time.time() - self._run_start_time

                # --- Freeze / stop-go / recovery tracking ---
                _FREEZE_THRESH = 0.05   # m/s: below this counts as frozen
                _BLOCK_DIST    = 2.5    # m: pedestrian is considered blocking path
                now = time.time()
                is_frozen = abs(float(v)) < _FREEZE_THRESH
                ped_blocking = (step_ped_dist < _BLOCK_DIST) if step_ped_dist != float('inf') else False

                if is_frozen and not self._is_frozen:
                    self._freeze_start_time = now
                elif not is_frozen and self._is_frozen:
                    self._stop_go_count += 1
                    if self._freeze_start_time is not None:
                        self._total_freeze_sec += now - self._freeze_start_time
                        self._freeze_start_time = None
                    if self._last_unblock_time is not None:
                        self._recovery_latencies.append(now - self._last_unblock_time)
                        self._last_unblock_time = None
                self._is_frozen = is_frozen

                if not ped_blocking and self._ped_was_blocking:
                    self._last_unblock_time = now
                self._ped_was_blocking = ped_blocking
                # --- end freeze tracking ---

                if self._log_wandb and self._wandb_run is not None:
                    wandb.log({
                        "live/linear_velocity_mps":  float(v),
                        "live/angular_velocity_rps": float(w),
                        "live/solver_ms":            debug_info['step_runtime'] * 1000,
                        "live/path_deviation_m":     step_dev,
                        "live/nearest_ped_dist_m":   step_ped_dist if step_ped_dist != float('inf') else -1.0,
                        "live/elapsed_sec":          elapsed,
                        "live/is_frozen":            1.0 if is_frozen else 0.0,
                        "live/cumul_freeze_sec":     self._total_freeze_sec,
                        "live/ped_blocking":         1.0 if ped_blocking else 0.0,
                        "live/c7_oncoming_active":   1.0 if ttc_oncoming < 6.0 else 0.0,
                        "live/c7_ttc_oncoming":      ttc_oncoming if ttc_oncoming != float('inf') else -1.0,
                        "live/c7_offset_strength":   strength,
                        "live/c7_lane_offset":       self._lane_offset_filtered,
                        "live/c7_target_offset":     target_offset,
                        "live/c7_signed_right_error": signed_right_error,
                        "live/c7_phase":             c7_phase,
                        "live/c7_avoid_target":      avoid_target,
                        "live/c7_recenter_target":   recenter_target,
                        "live/c7_position_capped":   1.0 if position_capped else 0.0,
                        "live/c7_committed_avoid":   1.0 if committed_avoid else 0.0,
                        "live/c7_commit_floor":      0.0,
                        "live/c7_early_preview":     1.0 if early_preview else 0.0,
                        "live/c7_early_offset":      early_offset,
                        "live/c7_st_center_score":   st_center_score,
                        "live/c7_st_benefit":        st_benefit,
                        "live/c7_st_oncoming_score": st_center_onc,
                        "live/c7_st_same_dir_score": st_center_samd,
                        "live/human_radius_inflation": self._human_radius_inflation,
                    })
                if self._goal_pos:
                    dist_to_goal = math.hypot(
                        self.x - self._goal_pos[0], self.y - self._goal_pos[1])
                    if dist_to_goal < self._goal_tolerance:
                        ped_ok = self._min_ped_clearance >= 0.3
                        robot_ok = self._min_robot_clearance >= self.cfg_robot.vehicle_width * 2
                        success = ped_ok and robot_ok
                        reason = ('' if success else
                                  ('ped_too_close' if not ped_ok else 'robot_collision'))
                        self._log_run_result(success, reason)
                    elif elapsed > self._max_task_time:
                        self._log_run_result(False, 'timeout')

        self.cmd_vel_publisher.publish(cmd_vel)
        self.robot_state_publisher.publish(robot_states)
        self.schedule_viz_publisher.publish(
            self.robot_path_to_vis_msg(
                self.ref_path_coords.copy(),
                current_ref=current_refs.tolist(),
                pred_states=pred_states)
        )

    def odom_callback(self, msg: Odometry):
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        self.theta = 2 * math.atan2(msg.pose.pose.orientation.z, msg.pose.pose.orientation.w)

        self.odom_received = True
        if self._waiting_reset_odom:
            self._waiting_reset_odom = False
            self.get_logger().info(
                f"[Recorder] Reset odom received: "
                f"x={self.x:.2f}, y={self.y:.2f}, theta={self.theta:.2f}")

    def raw_traj_callback(self, msg: HumanTrajectoryArray):
        self.raw_traj_data = msg

    def _generate_offset_ref(self, ref_states: np.ndarray, offset_m: float) -> np.ndarray:
        """C7: shift reference path laterally to the right by offset_m, using path tangent."""
        shifted = ref_states.copy()
        n = len(ref_states)
        for i in range(n):
            if n >= 2:
                if i < n - 1:
                    dx = ref_states[i + 1, 0] - ref_states[i, 0]
                    dy = ref_states[i + 1, 1] - ref_states[i, 1]
                else:
                    dx = ref_states[i, 0] - ref_states[i - 1, 0]
                    dy = ref_states[i, 1] - ref_states[i - 1, 1]
                norm = math.hypot(dx, dy)
                if norm > 1e-6:
                    rx, ry = dy / norm, -dx / norm  # right normal
                else:
                    yaw = ref_states[i, 2]
                    rx, ry = math.sin(yaw), -math.cos(yaw)
            else:
                yaw = ref_states[i, 2]
                rx, ry = math.sin(yaw), -math.cos(yaw)
            shifted[i, 0] += offset_m * rx
            shifted[i, 1] += offset_m * ry
        return shifted

    def _score_lane_hazard(self, ref_states: np.ndarray) -> float:
        """C7: score a reference path against cached ST predictions. Lower = safer."""
        _SIGMA = 0.4   # Gaussian kernel width (m); 0.4 gives 0.875σ separation for 0.35m offset
        _GAMMA = 0.9   # temporal discount
        score = 0.0
        T = len(ref_states)
        for Nn, mu_seq in enumerate(self._mu_cache):
            conf_seq = self._conf_cache[Nn]
            for t in range(min(T, len(mu_seq))):
                mu = mu_seq[t]
                if mu is None:
                    continue
                conf = conf_seq[t]
                rx, ry = ref_states[t, 0], ref_states[t, 1]
                d2 = (mu[0] - rx) ** 2 + (mu[1] - ry) ** 2
                score += (_GAMMA ** t) * conf * math.exp(-d2 / (2.0 * _SIGMA ** 2))
        return score

    def _score_lane_hazard_directional(self, ref_states: np.ndarray):
        """C7.5 final: direction-aware hazard score — returns (total, oncoming, same_dir) tuple.
        Same-dir weight = 0. Uses actor_idx = Nn // K for multi-mode ST predictor."""
        _SIGMA           = 0.4
        _GAMMA           = 0.9
        _ONCOMING_THRESH = 0.5
        _SAME_DIR_THRESH = -0.5
        _ONCOMING_WEIGHT = 1.0
        _SAME_DIR_WEIGHT = 0.0
        _CROSSING_WEIGHT = 0.0

        vr_x = math.cos(self.theta)
        vr_y = math.sin(self.theta)

        # Derive K (modes per actor) from cache size vs number of raw trajectories
        n_traj  = len(self.raw_traj_data.human_trajectories) if self.raw_traj_data else 0
        n_cache = len(self._mu_cache)
        K = max(1, n_cache // n_traj) if n_traj > 0 else 1

        total_score    = 0.0
        oncoming_score = 0.0
        same_dir_score = 0.0
        T = len(ref_states)
        for Nn, mu_seq in enumerate(self._mu_cache):
            conf_seq = self._conf_cache[Nn]

            # Map multi-mode slot back to raw actor index
            actor_idx = Nn // K
            w_dir = 0.0
            is_oncoming = False
            if self.raw_traj_data is not None and actor_idx < n_traj:
                pts = self.raw_traj_data.human_trajectories[actor_idx].traj_points
                if len(pts) >= 10:
                    dvx = pts[-1].x - pts[-10].x
                    dvy = pts[-1].y - pts[-10].y
                    vp_norm = math.hypot(dvx, dvy)
                    if vp_norm > 1e-3:
                        ped_vx = dvx / vp_norm
                        ped_vy = dvy / vp_norm
                        s_k = -(ped_vx * vr_x + ped_vy * vr_y)
                        if s_k > _ONCOMING_THRESH:
                            w_dir = _ONCOMING_WEIGHT
                            is_oncoming = True
                        elif s_k < _SAME_DIR_THRESH:
                            w_dir = _SAME_DIR_WEIGHT
                        else:
                            w_dir = _CROSSING_WEIGHT

            if w_dir < 1e-6:
                continue

            actor_score = 0.0
            for t in range(min(T, len(mu_seq))):
                mu = mu_seq[t]
                if mu is None:
                    continue
                # Skip predictions behind the robot — actor has already passed
                forward_mu = (mu[0] - self.x) * math.cos(self.theta) + (mu[1] - self.y) * math.sin(self.theta)
                if forward_mu < 0.3:
                    continue
                conf = conf_seq[t]
                rx, ry = ref_states[t, 0], ref_states[t, 1]
                d2 = (mu[0] - rx) ** 2 + (mu[1] - ry) ** 2
                actor_score += w_dir * (_GAMMA ** t) * conf * math.exp(-d2 / (2.0 * _SIGMA ** 2))

            total_score += actor_score
            if is_oncoming:
                oncoming_score += actor_score
            else:
                same_dir_score += actor_score

        return total_score, oncoming_score, same_dir_score

    def _select_lane(self, ref_states: np.ndarray) -> str:
        """C7.1: dynamic lane selector — scores center vs right internally, dual threshold + hold time."""
        _OFFSET_M         = 0.35   # fixed offset used for scoring comparison only
        _MIN_SWITCH_SCORE = 0.8    # center score absolute floor before considering switch
        _MIN_BENEFIT      = 0.3    # center - right must exceed this to switch; 0.3 triggers ~20 steps earlier
        _RETURN_SCORE     = 0.08   # conservative: stay right until pedestrian fully clear
        _MIN_HOLD_STEPS   = 20     # minimum steps in current lane before returning to center

        center_score = self._score_lane_hazard(ref_states)
        right_ref    = self._generate_offset_ref(ref_states, _OFFSET_M)
        right_score  = self._score_lane_hazard(right_ref)

        self._lane_score_center = center_score
        self._lane_score_right  = right_score
        self._lane_hold_count  += 1

        if self._selected_lane == 'center':
            benefit = center_score - right_score
            if center_score > _MIN_SWITCH_SCORE and benefit > _MIN_BENEFIT:
                self._selected_lane = 'right'
                self._lane_hold_count = 0
        else:  # 'right'
            if self._lane_hold_count > _MIN_HOLD_STEPS and center_score < _RETURN_SCORE:
                self._selected_lane = 'center'
                self._lane_hold_count = 0

        return self._selected_lane

    def _min_ttc_oncoming(self) -> float:
        """C7.3: TTC to nearest oncoming pedestrian using projection + lateral gate."""
        _ONCOMING_THRESH   = 0.5
        _LATERAL_GATE      = 1.2    # m
        _PED_SPEED_ASSUMED = 0.6    # m/s (conservative; actual actor ~0.33 m/s → triggers earlier)

        if self.raw_traj_data is None:
            return float('inf')

        vr_x = math.cos(self.theta)
        vr_y = math.sin(self.theta)

        min_ttc = float('inf')
        for traj in self.raw_traj_data.human_trajectories:
            pts = traj.traj_points
            if len(pts) < 10:
                continue

            dvx = pts[-1].x - pts[-10].x
            dvy = pts[-1].y - pts[-10].y
            vp_norm = math.hypot(dvx, dvy)
            if vp_norm < 1e-3:
                continue
            ped_vx = dvx / vp_norm
            ped_vy = dvy / vp_norm

            s_k = -(ped_vx * vr_x + ped_vy * vr_y)  # +1 = oncoming
            if s_k < _ONCOMING_THRESH:
                continue

            dx = pts[-1].x - self.x
            dy = pts[-1].y - self.y

            forward_dist = dx * vr_x + dy * vr_y
            if forward_dist <= 0.0:
                continue

            lateral_dist = abs(-dx * vr_y + dy * vr_x)
            if lateral_dist > _LATERAL_GATE:
                continue

            # Use effective speed floor so TTC doesn't balloon when robot brakes.
            v_robot_eff = max(abs(self._last_v), 0.8)
            # Oncoming ped has negative forward component → v_close > v_robot_eff
            v_ped_forward = (ped_vx * vr_x + ped_vy * vr_y) * _PED_SPEED_ASSUMED
            v_close = max(v_robot_eff - v_ped_forward, 0.1)

            ttc = forward_dist / v_close
            min_ttc = min(min_ttc, ttc)

        return min_ttc

    def _nearest_oncoming_dist(self) -> float:
        """C7.2: forward distance to nearest oncoming pedestrian (projection + lateral gate)."""
        _ONCOMING_THRESH = 0.5   # s_k floor: requires clear head-on component
        _LATERAL_GATE    = 1.2   # m: ignore peds too far to the side

        if self.raw_traj_data is None:
            return float('inf')

        vr_x = math.cos(self.theta)
        vr_y = math.sin(self.theta)

        min_dist = float('inf')
        for traj in self.raw_traj_data.human_trajectories:
            pts = traj.traj_points
            if len(pts) < 10:
                continue

            dvx = pts[-1].x - pts[-10].x
            dvy = pts[-1].y - pts[-10].y
            vp_norm = math.hypot(dvx, dvy)
            if vp_norm < 1e-3:
                continue
            dvx /= vp_norm
            dvy /= vp_norm

            s_k = -(dvx * vr_x + dvy * vr_y)  # +1 = oncoming
            if s_k < _ONCOMING_THRESH:
                continue

            dx = pts[-1].x - self.x
            dy = pts[-1].y - self.y

            forward_dist = dx * vr_x + dy * vr_y
            if forward_dist <= 0.0:
                continue  # already behind robot

            lateral_dist = abs(-dx * vr_y + dy * vr_x)
            if lateral_dist > _LATERAL_GATE:
                continue

            min_dist = min(min_dist, forward_dist)

        return min_dist

    def _select_nearest_dynobs_indices(self, mu_list_list: list, raw_n_obs: int) -> list[int]:
        max_dynobs = int(getattr(self.cfg_mpc, 'Ndynobs', raw_n_obs))
        if raw_n_obs <= max_dynobs:
            return list(range(raw_n_obs))

        scores = []
        for obs_idx in range(raw_n_obs):
            best_dist = float('inf')
            for mu_list in mu_list_list[:min(len(mu_list_list), self.cfg_mpc.N_hor + 1)]:
                if obs_idx >= len(mu_list):
                    continue
                mx, my = mu_list[obs_idx]
                if abs(mx) >= 999.0 or abs(my) >= 999.0:
                    continue
                best_dist = min(best_dist, math.hypot(mx - self.x, my - self.y))
            scores.append((best_dist, obs_idx))

        selected = [obs_idx for _, obs_idx in sorted(scores)[:max_dynobs]]
        self.get_logger().debug(
            f"[DynObs] selected nearest {len(selected)}/{raw_n_obs} actors for MPC")
        return selected

    def _compute_stable_dir_scales(self, n_obs: int, mu_list_list: list) -> list:
        _LP_ALPHA = 0.5   # fast recovery — half-life ~2 steps
        dir_scales = [1.0] * n_obs

        if self.raw_traj_data is None:
            return dir_scales

        raw_trajs = self.raw_traj_data.human_trajectories
        n_actors = len(raw_trajs)
        if n_actors == 0:
            return dir_scales

        K = max(1, n_obs // n_actors)

        vr_x = math.cos(self.theta)
        vr_y = math.sin(self.theta)

        for Nn in range(n_obs):
            actor_idx = Nn // K
            if actor_idx >= n_actors:
                continue

            pts = raw_trajs[actor_idx].traj_points
            if len(pts) < 10:
                continue

            # A: distance gate 3m — only perturb when encounter is imminent
            dist_to_actor = math.hypot(pts[-1].x - self.x, pts[-1].y - self.y)
            if dist_to_actor > 3.0:
                continue

            # B: lead mode only
            if K > 1 and Nn % K != 0:
                continue

            dvx = pts[-1].x - pts[-10].x
            dvy = pts[-1].y - pts[-10].y
            vp_norm = math.hypot(dvx, dvy)
            if vp_norm < 1e-3:
                continue

            dvx /= vp_norm
            dvy /= vp_norm

            # Danger score: +1=oncoming, -1=same-dir, 0=perpendicular
            s_k = -(dvx * vr_x + dvy * vr_y)

            # Confidence gate: ignore weak directional signal (noise / glancing angle)
            if s_k < 0.7:
                target_scale = 1.0  # decay back to neutral
            else:
                # Smooth linear interpolation: s_k=0.7→1.00, s_k=1.0→1.07
                normalized = (s_k - 0.7) / 0.3
                target_scale = 1.0 + 0.07 * normalized

            prev = self._dir_scale_filtered.get(Nn, 1.0)
            filtered = (1.0 - _LP_ALPHA) * prev + _LP_ALPHA * target_scale
            self._dir_scale_filtered[Nn] = filtered
            dir_scales[Nn] = filtered

        return dir_scales

    def dynobs_callback(self, msg: MotionPredictionResult):
        mu_list_list = []
        mu_list_list_msg:list[HumanTrajectoryArray] = msg.mu_list_list
        for mu_list_msg in mu_list_list_msg:
            mu_list_msg_seq:list[HumanTrajectory] = mu_list_msg.human_trajectories
            mu_list = []
            for mus_at_time_msg in mu_list_msg_seq:
                traj_pts:list[Point] = mus_at_time_msg.traj_points
                mus_at_time = [(pt.x, pt.y) for pt in traj_pts]
                mu_list += mus_at_time
            mu_list_list.append(mu_list)

        std_list_list = []
        std_list_list_msg:list[HumanTrajectoryArray] = msg.std_list_list
        for std_list_msg in std_list_list_msg:
            std_list_msg_seq:list[HumanTrajectory] = std_list_msg.human_trajectories
            std_list = []
            for stds_at_time_msg in std_list_msg_seq:
                traj_pts:list[Point] = stds_at_time_msg.traj_points # type: ignore
                stds_at_time = [(pt.x, pt.y) for pt in traj_pts]
                std_list += stds_at_time
            std_list_list.append(std_list)

        conf_list_list = []
        conf_list_list_msg:list[HumanTrajectoryArray] = msg.conf_list_list
        for conf_list_msg in conf_list_list_msg:
            conf_list_msg_seq:list[HumanTrajectory] = conf_list_msg.human_trajectories
            conf_list = []
            for confs_at_time_msg in conf_list_msg_seq:
                traj_pts:list[Point] = confs_at_time_msg.traj_points # type: ignore
                confs_at_time = [pt.x for pt in traj_pts]
                conf_list += confs_at_time
            conf_list_list.append(conf_list)

        self.motion_prediction_stamp = self.get_clock().now()
        self.motion_prediction_result = (mu_list_list, std_list_list, conf_list_list)
        self.dynobs_received = True


    def send_map_request(self) -> GetInflatedMap.Response:
        self.map_request.robot_id = self.robot_id
        future = self.get_map_client.call_async(self.map_request)
        rclpy.spin_until_future_complete(self, future)
        self.map_response = future.result()
        self.map_response = cast(GetInflatedMap.Response, self.map_response)

        boundary_coords = self.polygon_to_tuples(self.map_response.inflated_map.boundary.polygon)
        obstacle_list = []
        obstacle_objects:list[PolygonObject] = self.map_response.inflated_map.obstacle_list.polygon_objects
        for obstacle_obj in obstacle_objects:
            obstacle_list.append(self.polygon_to_tuples(obstacle_obj.polygon))
        self.boundary_coords = boundary_coords
        self.obstacle_list = obstacle_list
        self.map_received = True
        return self.map_response

    def send_schedule_request(self) -> GetRobotSchedule.Response:
        self.robot_schedule_request.robot_id = self.robot_id
        self.robot_schedule_request.current_time = float(self.get_clock().now().nanoseconds / 1e9)
        future = self.get_schedule_client.call_async(self.robot_schedule_request)
        rclpy.spin_until_future_complete(self, future)
        self.robot_schedule_response = future.result()
        self.robot_schedule_response = cast(GetRobotSchedule.Response, self.robot_schedule_response)

        path_coords:list[Point] = self.robot_schedule_response.path_schedule.path_schedule.path_coords
        self.ref_path_coords = []
        for point in path_coords:
            self.ref_path_coords.append((point.x, point.y))
        self.planner.load_path(self.ref_path_coords, None, self.cfg_robot.lin_vel_max) # ignore the path times
        self.schedule_received = True
        return self.robot_schedule_response

    def send_robot_states_request(self) -> GetOtherRobotStates.Response:
        if not self.get_robot_states_client.wait_for_service(timeout_sec=self.timer_period/5):
            self.get_logger().debug(f'Robot states service not available for robot {self.robot_id}.')
            return GetOtherRobotStates.Response()
        self.robot_states_request.ego_robot_id = self.robot_id
        self.robot_states_response = self.get_robot_states_client.call(self.robot_states_request)
        return self.robot_states_response

    def _robot_inside_dyn_obstacle_step(self, step) -> bool:
        if abs(step[0]) > 500.0:
            return False
        rx = max(float(step[2]), 1e-3)
        ry = max(float(step[3]), 1e-3)
        dx = self.x - float(step[0])
        dy = self.y - float(step[1])
        stop_scale = 1.10
        rx *= stop_scale
        ry *= stop_scale
        return (dx * dx) / (rx * rx) + (dy * dy) / (ry * ry) <= 1.0

    def _dyn_obs_list_to_vis_msg(self, dyn_obs_list: list) -> MarkerArray:
        """Clear dynamic obstacle visualization markers.

        The no-speed zone is still active through _robot_inside_dyn_obstacle_step(),
        but the red transparent RViz stop circles are hidden.
        """
        marker_msg = MarkerArray()

        # Clean up stale markers from previous frame
        for stale_id in range(self._dyn_obs_mpc_viz_last_count):
            m = Marker()
            m.header.frame_id = "map"
            m.ns = "dyn_obs_mpc_ns"
            m.id = stale_id
            m.action = Marker.DELETE
            marker_msg.markers.append(m)
        self._dyn_obs_mpc_viz_last_count = 0
        return marker_msg

    # ------------------------------------------------------------------ #
    #  Experiment recorder helpers                                        #
    # ------------------------------------------------------------------ #
    def _init_run_tracking(self):
        self._task_started: bool = False
        self._run_start_time: Optional[float] = None
        self._goal_pos: Optional[tuple] = None
        self._min_ped_clearance: float = float('inf')
        self._min_robot_clearance: float = float('inf')
        self._solver_times: list = []
        self._v_list: list = []
        self._w_list: list = []
        self._path_deviations: list = []
        # Freeze / oscillation tracking
        self._is_frozen: bool = False
        self._freeze_start_time: Optional[float] = None
        self._total_freeze_sec: float = 0.0
        self._stop_go_count: int = 0
        self._ped_was_blocking: bool = False
        self._last_unblock_time: Optional[float] = None
        self._recovery_latencies: list = []
        # _awaiting_departure and _last_goal_pos are NOT reset here;
        # they are managed by _log_run_result to prevent immediate re-trigger.

    def _ensure_csv_header(self):
        write_header = not os.path.exists(self._csv_path)
        with open(self._csv_path, 'a', newline='') as f:
            if write_header:
                csv.writer(f).writerow([
                    'run_id', 'scenario', 'predictor_variant', 'robot_id', 'timestamp',
                    'success', 'failure_reason', 'elapsed_sec',
                    'min_ped_clearance_m', 'min_robot_clearance_m',
                    'path_dev_mean_m', 'path_dev_max_m',
                    'avg_solver_ms', 'max_solver_ms',
                    'avg_v_mps', 'avg_abs_w_rps',
                    'v_jerk_std', 'w_jerk_std',
                    'total_freeze_sec', 'stop_go_count', 'avg_recovery_latency_sec',
                ])

    def _log_run_result(self, success: bool, failure_reason: str = ''):
        elapsed = time.time() - self._run_start_time if self._run_start_time else 0.0
        sol_ms = [t * 1000 for t in self._solver_times]
        v_arr  = np.array(self._v_list)  if self._v_list  else np.zeros(1)
        w_arr  = np.array(self._w_list)  if self._w_list  else np.zeros(1)
        dev    = np.array(self._path_deviations) if self._path_deviations else np.zeros(1)
        v_j = float(np.std(np.diff(v_arr))) if len(v_arr) > 1 else 0.0
        w_j = float(np.std(np.diff(w_arr))) if len(w_arr) > 1 else 0.0
        ped_c   = round(self._min_ped_clearance,   3) if self._min_ped_clearance   != float('inf') else -1
        robot_c = round(self._min_robot_clearance, 3) if self._min_robot_clearance != float('inf') else -1

        # Finalize freeze duration if still frozen at run end
        if self._is_frozen and self._freeze_start_time is not None:
            self._total_freeze_sec += time.time() - self._freeze_start_time
        avg_recovery = (float(np.mean(self._recovery_latencies))
                        if self._recovery_latencies else -1.0)

        with open(self._csv_path, 'a', newline='') as f:
            csv.writer(f).writerow([
                self._run_id, self._scenario_id, self._predictor_variant, self.robot_id,
                time.strftime('%Y-%m-%d %H:%M:%S'),
                int(success), failure_reason, round(elapsed, 2),
                ped_c, robot_c,
                round(float(np.mean(dev)), 3), round(float(np.max(dev)), 3),
                round(float(np.mean(sol_ms)), 2) if sol_ms else -1,
                round(float(np.max(sol_ms)),  2) if sol_ms else -1,
                round(float(np.mean(np.abs(v_arr))), 3),
                round(float(np.mean(np.abs(w_arr))), 3),
                round(v_j, 4), round(w_j, 4),
                round(self._total_freeze_sec, 2),
                self._stop_go_count,
                round(avg_recovery, 2),
            ])
        self.get_logger().info(
            f"[Recorder] Run {self._run_id} → success={success} "
            f"ped_clearance={ped_c}m elapsed={elapsed:.1f}s "
            f"freeze={self._total_freeze_sec:.1f}s stop_go={self._stop_go_count}")
        if self._log_wandb and self._wandb_run is not None:
            wandb.run.summary.update({
                "result/success":                int(success),
                "result/failure_reason":         failure_reason,
                "result/elapsed_sec":            round(elapsed, 2),
                "result/ped_clearance_m":        ped_c,
                "result/avg_v_mps":              round(float(np.mean(np.abs(v_arr))), 3),
                "result/avg_abs_w_rps":          round(float(np.mean(np.abs(w_arr))), 3),
                "result/path_dev_mean_m":        round(float(np.mean(dev)), 3),
                "result/path_dev_max_m":         round(float(np.max(dev)), 3),
                "result/avg_solver_ms":          round(float(np.mean(sol_ms)), 2) if sol_ms else -1,
                "result/total_freeze_sec":       round(self._total_freeze_sec, 2),
                "result/stop_go_count":          self._stop_go_count,
                "result/avg_recovery_latency_sec": round(avg_recovery, 2),
            })
            wandb.finish()
            self._wandb_run = None
        self._run_id += 1
        last = self._goal_pos
        self._init_run_tracking()
        self._last_goal_pos = last
        self._awaiting_departure = True
        self._reset_world_after_run()

    def _clear_policy_state(self):
        self.kt = 0
        self.first_message = True
        self.last_pred_states = None
        self.motion_prediction_result = []
        self.raw_traj_data = None
        self._dir_scale_filtered = {}
        self._mu_cache = []
        self._conf_cache = []
        self._lane_offset_filtered = 0.0
        self._last_v = 0.0
        self._obs_in_zone = False
        self._obs_zone_frames = 0
        self.odom_received = False
        if getattr(self, 'ref_path_coords', None):
            self.planner.load_path(
                self.ref_path_coords,
                None,
                self.cfg_robot.lin_vel_max
            )

    def _reset_policy_callback(self, _request, response):
        self.cmd_vel_publisher.publish(Twist())
        self._clear_policy_state()
        self._reset_pending = True
        self._waiting_reset_odom = False
        self._reset_pending_since = time.time()
        response.success = True
        response.message = 'MPC policy cleared and command output held at zero'
        self.get_logger().info(f'[Recorder] {response.message}')
        return response

    def _release_policy_callback(self, _request, response):
        self.cmd_vel_publisher.publish(Twist())
        self._clear_policy_state()
        self._release_reset_pending()
        response.success = True
        response.message = 'MPC policy released after reset'
        self.get_logger().info(f'[Recorder] {response.message}')
        return response

    def _reset_world_after_run(self):
        if not self._reset_on_finish:
            return

        self.cmd_vel_publisher.publish(Twist())
        self._clear_policy_state()

        self._reset_pending = True
        self._reset_pending_since = time.time()
        self._clear_actor_history_before_rerandomize()

    def _clear_actor_history_before_rerandomize(self):
        if not self.clear_actor_trajs_client.wait_for_service(timeout_sec=0.5):
            self.get_logger().warn(
                f"[Recorder] Actor trajectory history clear skipped: "
                f"service {self._clear_actor_trajs_service_name} not available")
            self._rerandomize_actors_after_clear()
            return

        future = self.clear_actor_trajs_client.call_async(Trigger.Request())
        future.add_done_callback(self._on_actor_history_clear_done)

    def _on_actor_history_clear_done(self, future):
        try:
            result = future.result()
            if result is not None and result.success:
                self.get_logger().info(f"[Recorder] {result.message}")
            elif result is not None:
                self.get_logger().warn(
                    f"[Recorder] Actor trajectory history clear failed: {result.message}")
        except Exception as exc:
            self.get_logger().warn(f"[Recorder] Actor trajectory history clear failed: {exc}")
        self._rerandomize_actors_after_clear()

    def _rerandomize_actors_after_clear(self):
        if not self._rerandomize_actors_on_reset:
            self._reset_simulation_after_rerandomize()
            return
        if not self.rerandomize_actors_client.wait_for_service(timeout_sec=0.5):
            self.get_logger().warn(
                f"[Recorder] Actor rerandomize skipped: "
                f"service {self._rerandomize_actors_service_name} not available")
            self._reset_simulation_after_rerandomize()
            return

        future = self.rerandomize_actors_client.call_async(Trigger.Request())
        future.add_done_callback(self._on_actor_rerandomize_done)

    def _on_actor_rerandomize_done(self, future):
        try:
            result = future.result()
            if result is not None and result.success:
                self.get_logger().info(f"[Recorder] {result.message}")
            elif result is not None:
                self.get_logger().warn(f"[Recorder] Actor rerandomize failed: {result.message}")
        except Exception as exc:
            self.get_logger().warn(f"[Recorder] Actor rerandomize failed: {exc}")
        self._reset_simulation_after_rerandomize()

    def _reset_simulation_after_rerandomize(self):
        if not self.reset_world_client.wait_for_service(timeout_sec=0.5):
            self.get_logger().warn(
                f"[Recorder] Simulation reset skipped: "
                f"service {self._reset_service_name} not available")
            self._force_robot_init_pose()
            return

        future = self.reset_world_client.call_async(Empty.Request())
        future.add_done_callback(self._on_world_reset_done)

    def _on_world_reset_done(self, future):
        try:
            future.result()
            self.get_logger().info(
                f"[Recorder] Simulation reset by {self._reset_service_name}; "
                f"forcing robot back to init pose")
            self._waiting_reset_odom = True
            self.odom_received = False
        except Exception as exc:
            self.get_logger().warn(f"[Recorder] Simulation reset failed: {exc}")
        self._force_robot_init_pose()

    def _force_robot_init_pose(self):
        self.x = self._robot_init_x
        self.y = self._robot_init_y
        self.theta = self._robot_init_theta
        self.odom_received = True

        if not self.set_entity_state_client.wait_for_service(timeout_sec=0.5):
            self.get_logger().warn(
                f"[Recorder] Robot pose reset service "
                f"{self._set_entity_state_service_name} not available")
            self._release_reset_pending()
            return

        state = EntityState()
        state.name = self._robot_entity_name
        state.reference_frame = 'world'
        state.pose.position.x = self._robot_init_x
        state.pose.position.y = self._robot_init_y
        state.pose.position.z = self._robot_init_z
        half_theta = 0.5 * self._robot_init_theta
        state.pose.orientation.z = math.sin(half_theta)
        state.pose.orientation.w = math.cos(half_theta)
        state.twist.linear.x = 0.0
        state.twist.linear.y = 0.0
        state.twist.angular.z = 0.0

        request = SetEntityState.Request()
        request.state = state
        future = self.set_entity_state_client.call_async(request)
        future.add_done_callback(self._on_robot_init_pose_done)

    def _on_robot_init_pose_done(self, future):
        try:
            result = future.result()
            if result is not None and result.success:
                self.get_logger().info(
                    f"[Recorder] Robot reset to init pose: "
                    f"x={self._robot_init_x:.2f}, y={self._robot_init_y:.2f}, "
                    f"theta={self._robot_init_theta:.2f}")
            elif result is not None:
                self.get_logger().warn(
                    f"[Recorder] Robot pose reset failed: {result.status_message}")
        except Exception as exc:
            self.get_logger().warn(f"[Recorder] Robot pose reset failed: {exc}")

        self.x = self._robot_init_x
        self.y = self._robot_init_y
        self.theta = self._robot_init_theta
        self.odom_received = True
        self._release_reset_pending()

    def _release_reset_pending(self):
        self._reset_pending = False
        self._waiting_reset_odom = False
        self._reset_pending_since = None

    @staticmethod
    def _seg_deviation(x: float, y: float, path: list) -> float:
        """Perpendicular distance from (x,y) to nearest segment in path."""
        if len(path) < 2:
            return math.hypot(x - path[0][0], y - path[0][1])
        min_d = float('inf')
        for i in range(len(path) - 1):
            ax, ay = path[i]
            bx, by = path[i + 1]
            dx, dy = bx - ax, by - ay
            seg2 = dx * dx + dy * dy
            t = max(0.0, min(1.0, ((x - ax) * dx + (y - ay) * dy) / seg2)) if seg2 > 1e-9 else 0.0
            min_d = min(min_d, math.hypot(x - (ax + t * dx), y - (ay + t * dy)))
        return min_d

    # ------------------------------------------------------------------ #

    def print_debug_info(self, v: float, w: float, debug_info: DebugInfo):
        self.get_logger().info(f"Current state: {(round(self.x, 2), round(self.y, 2), round(self.theta, 2))} -> Target position: {self.planner.current_target_node}")
        self.get_logger().info(f"Mode: {self.controller.mode}, v: {round(v, 2)}, w: {round(w, 2)}")
        self.get_logger().info(f"Cost: {round(debug_info['cost'], 2)}. Solve time: {round(debug_info['step_runtime'], 4)} s")

    def robot_path_to_vis_msg(self,
                              points: list[tuple[float, float]],
                              current_ref:Optional[list[tuple[float, float]]]=None,
                              pred_states:Optional[list[tuple[float, float]]]=None,
                              name_space:str="robot_schedule_ns", 
                              id_start:int=0) -> MarkerArray:
        """Convert a PathSchedule message to a MarkerArray message"""
        marker_schedule_msg = MarkerArray()
        if self.ref_path_coords is None:
            return marker_schedule_msg
        
        marker_id = id_start

        marker_id += 1
        marker_point_msg_1 = self.tuples_to_vis_msg(points, Marker.POINTS, self.color_node, marker_id, scale=0.2)
        marker_point_msg_1.header.frame_id = "map"
        marker_point_msg_1.ns = name_space
        marker_schedule_msg.markers.append(marker_point_msg_1)

        marker_id += 1
        marker_line_msg_1 = self.tuples_to_vis_msg(points, Marker.LINE_STRIP, self.color_edge, marker_id, scale=0.05)
        marker_line_msg_1.header.frame_id = "map"
        marker_line_msg_1.ns = name_space
        marker_schedule_msg.markers.append(marker_line_msg_1)

        if current_ref is not None:
            marker_id += 1
            # color: magenta (0.8, 0.0, 0.8)
            marker_point_msg_2 = self.tuples_to_vis_msg(current_ref, Marker.POINTS, (0.8, 0.0, 0.8), marker_id, scale=0.1)
            marker_point_msg_2.header.frame_id = "map"
            marker_point_msg_2.ns = name_space
            marker_schedule_msg.markers.append(marker_point_msg_2)

        if pred_states is not None:
            marker_id += 1
            # color: yellow (1.0, 1.0, 0.0)
            marker_point_msg_3 = self.tuples_to_vis_msg(pred_states, Marker.POINTS, (1.0, 1.0, 0.0), marker_id, scale=0.1)
            marker_point_msg_3.header.frame_id = "map"
            marker_point_msg_3.ns = name_space
            marker_schedule_msg.markers.append(marker_point_msg_3)

        return marker_schedule_msg
    
    @staticmethod
    def tuples_to_vis_msg(points: list[tuple[float, float]],
                          marker_type,
                          color: tuple[float, float, float],
                          marker_id: int,
                          scale:float=0.05) -> Marker:
        """Convert points to a Marker message"""
        marker_msg = Marker()
        marker_msg.id = marker_id
        marker_msg.type = marker_type
        marker_msg.action = Marker.ADD

        marker_msg.pose.position.x = 0.0
        marker_msg.pose.position.y = 0.0
        marker_msg.pose.position.z = 0.0
        marker_msg.pose.orientation.x = 0.0
        marker_msg.pose.orientation.y = 0.0
        marker_msg.pose.orientation.z = 0.0
        marker_msg.pose.orientation.w = 1.0

        marker_msg.scale.x = scale
        marker_msg.scale.y = scale
        marker_msg.scale.z = scale

        marker_msg.color.a = 1.0
        marker_msg.color.r = color[0]
        marker_msg.color.g = color[1]
        marker_msg.color.b = color[2]

        marker_msg.lifetime.sec = 0 # forever
        marker_msg.frame_locked = False # not locked to a frame
        [marker_msg.points.append(Point(x=pt[0], y=pt[1])) for pt in points]
        return marker_msg
    
    @staticmethod
    def polygon_to_tuples(polygon: Polygon) -> list[tuple[float, float]]:
        """Convert a Polygon message to a list of tuples"""
        vertices = []
        points:list[Point32] = polygon.points
        for point in points:
            vertices.append((point.x, point.y))
        return vertices


def main(args=None):
    rclpy.init(args=args)

    node = MpcControllerNode()
    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
