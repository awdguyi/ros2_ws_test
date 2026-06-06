#!/usr/bin/env python3

import csv
import json
import math
import os
import re
import time
from pathlib import Path

from ament_index_python.packages import get_package_share_directory
import rclpy
from geometry_msgs.msg import PoseArray
from map_interfaces.msg import GeometricMap as MapMsg
from mmp_interfaces.msg import MotionPredictionResult
from nav_msgs.msg import Odometry
from rcl_interfaces.msg import ParameterDescriptor
from rclpy.node import Node
from std_srvs.srv import Trigger


CSV_FIELDS = [
    'trial_id',
    'seed',
    'success',
    'fail_reason',
    'elapsed_sec',
    'actor_count',
    'min_ped_clearance_m',
    'mean_path_deviation_m',
    'max_path_deviation_m',
    'cumul_freeze_sec',
    'mean_linear_velocity_mps',
    'min_linear_velocity_mps',
    'mean_solver_ms',
    'max_solver_ms',
    'fail_x',
    'fail_y',
    'fail_theta',
    'fail_speed_mps',
    'fail_prev3_mean_linear_velocity_mps',
    'fail_prev3_max_linear_velocity_mps',
    'fail_prev3_mean_angular_velocity_radps',
    'fail_prev3_max_angular_velocity_radps',
    'fail_static_obstacle_id',
    'fail_current_ped_clearance_m',
]


def point_in_poly(point, poly):
    x, y = point
    inside = False
    j = len(poly) - 1
    for i, vertex in enumerate(poly):
        xi, yi = vertex
        xj, yj = poly[j]
        if (yi > y) != (yj > y):
            x_at_y = (xj - xi) * (y - yi) / ((yj - yi) or 1e-9) + xi
            inside = inside != (x < x_at_y)
        j = i
    return inside


def expanded_bbox_poly(poly, margin):
    xs = [p[0] for p in poly]
    ys = [p[1] for p in poly]
    return [
        [min(xs) - margin, min(ys) - margin],
        [min(xs) - margin, max(ys) + margin],
        [max(xs) + margin, max(ys) + margin],
        [max(xs) + margin, min(ys) - margin],
    ]


class RvizTrialManager(Node):
    def __init__(self):
        super().__init__('rviz_trial_manager')

        descriptor = ParameterDescriptor(dynamic_typing=True)
        self.declare_parameter('num_trials', 100, descriptor)
        self.declare_parameter('trial_timeout_sec', 90.0, descriptor)
        self.declare_parameter('random_seed_base', 1000, descriptor)
        self.declare_parameter('output_csv', 'rviz_100_trials.csv', descriptor)
        self.declare_parameter('goal_x', 1.0, descriptor)
        self.declare_parameter('goal_y', 12.3, descriptor)
        self.declare_parameter('goal_tolerance', 0.5, descriptor)
        self.declare_parameter('collision_distance', 0.15, descriptor)
        self.declare_parameter('collision_ignore_when_stopped', True, descriptor)
        self.declare_parameter('collision_motion_threshold', 0.05, descriptor)
        self.declare_parameter('freeze_velocity_threshold', 0.05, descriptor)
        self.declare_parameter('freeze_fail_sec', 10.0, descriptor)
        self.declare_parameter('freeze_ignore_ped_distance', 0.5, descriptor)
        self.declare_parameter('robot_namespace', 'zmr_X', descriptor)
        self.declare_parameter('startup_delay_sec', 5.0, descriptor)
        self.declare_parameter('inter_trial_delay_sec', 1.0, descriptor)
        self.declare_parameter('actor_warmup_sec', 2.0, descriptor)
        self.declare_parameter('actor_warmup_timeout_sec', 10.0, descriptor)
        self.declare_parameter('robot_settle_sec', 0.5, descriptor)
        self.declare_parameter('min_actor_pose_msgs_after_reset', 3, descriptor)
        self.declare_parameter('require_prediction_after_reset', True, descriptor)
        self.declare_parameter('map_file_name', 'warehouse_map_real.json', descriptor)
        self.declare_parameter('static_obstacle_margin', 0.25, descriptor)
        self.declare_parameter('enable_static_collision_check', True, descriptor)
        self.declare_parameter('reset_clear_timeout_sec', 2.0, descriptor)
        self.declare_parameter('require_geometry_map_ready', True, descriptor)

        self.num_trials = int(self.get_parameter('num_trials').value)
        self.trial_timeout_sec = float(self.get_parameter('trial_timeout_sec').value)
        self.random_seed_base = int(self.get_parameter('random_seed_base').value)
        self.output_csv = self.resolve_csv_path(str(self.get_parameter('output_csv').value))
        self.goal_x = float(self.get_parameter('goal_x').value)
        self.goal_y = float(self.get_parameter('goal_y').value)
        self.goal_tolerance = float(self.get_parameter('goal_tolerance').value)
        self.collision_distance = float(self.get_parameter('collision_distance').value)
        self.collision_ignore_when_stopped = self.as_bool(
            self.get_parameter('collision_ignore_when_stopped').value)
        self.collision_motion_threshold = float(
            self.get_parameter('collision_motion_threshold').value)
        self.freeze_velocity_threshold = float(self.get_parameter('freeze_velocity_threshold').value)
        self.freeze_fail_sec = float(self.get_parameter('freeze_fail_sec').value)
        self.freeze_ignore_ped_distance = float(
            self.get_parameter('freeze_ignore_ped_distance').value)
        self.robot_namespace = str(self.get_parameter('robot_namespace').value).strip('/')
        self.startup_delay_sec = float(self.get_parameter('startup_delay_sec').value)
        self.inter_trial_delay_sec = float(self.get_parameter('inter_trial_delay_sec').value)
        self.actor_warmup_sec = float(self.get_parameter('actor_warmup_sec').value)
        self.actor_warmup_timeout_sec = float(
            self.get_parameter('actor_warmup_timeout_sec').value)
        self.robot_settle_sec = float(self.get_parameter('robot_settle_sec').value)
        self.min_actor_pose_msgs_after_reset = int(
            self.get_parameter('min_actor_pose_msgs_after_reset').value)
        self.require_prediction_after_reset = self.as_bool(
            self.get_parameter('require_prediction_after_reset').value)
        self.map_file_name = str(self.get_parameter('map_file_name').value)
        self.static_obstacle_margin = float(
            self.get_parameter('static_obstacle_margin').value)
        self.enable_static_collision_check = self.as_bool(
            self.get_parameter('enable_static_collision_check').value)
        self.reset_clear_timeout_sec = float(
            self.get_parameter('reset_clear_timeout_sec').value)
        self.require_geometry_map_ready = self.as_bool(
            self.get_parameter('require_geometry_map_ready').value)
        self.static_obstacles = self.load_static_obstacles()
        self.geometry_map_ready = False
        self.geometry_map_obstacle_count = 0

        self.robot_reset_client = self.create_client(
            Trigger, f'/{self.robot_namespace}/reset_rviz_robot')
        self.actor_reset_client = self.create_client(Trigger, '/reset_rviz_actors')
        self.mpc_reset_client = self.create_client(
            Trigger, f'/{self.robot_namespace}/reset_mpc_policy')
        self.mpc_release_client = self.create_client(
            Trigger, f'/{self.robot_namespace}/release_mpc_policy')
        self.prediction_clear_client = self.create_client(
            Trigger, '/clear_motion_prediction')
        self.create_subscription(
            Odometry, f'/{self.robot_namespace}/odom', self.odom_callback, 30)
        self.create_subscription(PoseArray, '/rviz_actor_poses', self.actor_pose_callback, 10)
        self.create_subscription(
            MotionPredictionResult,
            '/motion_prediction_result',
            self.prediction_callback,
            10,
        )
        self.create_subscription(MapMsg, '/geometry_map', self.geometry_map_callback, 10)

        self.ensure_csv_header()
        self.state = 'startup'
        self.state_since = time.time()
        self.trial_id = 0
        self.reset_metrics()
        self.timer = self.create_timer(0.1, self.timer_callback)
        self.get_logger().info(
            f'RViz trial manager ready: num_trials={self.num_trials}, csv={self.output_csv}'
        )

    @staticmethod
    def resolve_csv_path(path_text):
        path = Path(os.path.expanduser(path_text))
        if not path.is_absolute():
            path = Path.cwd() / path
        return path

    @staticmethod
    def as_bool(value):
        if isinstance(value, str):
            return value.strip().lower() in ('1', 'true', 'yes', 'on')
        return bool(value)

    def ensure_csv_header(self):
        self.output_csv.parent.mkdir(parents=True, exist_ok=True)
        if self.output_csv.exists():
            return
        with open(self.output_csv, 'w', newline='') as csv_file:
            csv.DictWriter(csv_file, fieldnames=CSV_FIELDS).writeheader()

    def load_static_obstacles(self):
        if not self.enable_static_collision_check:
            return []
        map_path = (
            Path(get_package_share_directory('map_description'))
            / 'data'
            / self.map_file_name
        )
        try:
            with open(map_path, 'r', encoding='utf-8') as map_file:
                data = json.load(map_file)
        except Exception as exc:
            self.get_logger().warn(
                f'static obstacle collision check disabled: failed loading {map_path}: {exc}')
            return []
        obstacles = data.get('obstacle_list')
        if obstacles is None:
            obstacles = [obs['vertices'] for obs in data.get('obstacle_dict', [])]
        inflated = [expanded_bbox_poly(obs, self.static_obstacle_margin) for obs in obstacles]
        self.get_logger().info(
            f'static obstacle collision check ready: obstacles={len(inflated)}, '
            f'margin={self.static_obstacle_margin:.2f}m'
        )
        return inflated

    def reset_metrics(self):
        self.odom_ready = False
        self.actor_poses = []
        self.x = float('nan')
        self.y = float('nan')
        self.v = 0.0
        self.w = 0.0
        self.trial_start_time = None
        self.actor_count = 0
        self.min_ped_clearance = float('inf')
        self.current_ped_clearance = float('inf')
        self.path_deviations = []
        self.linear_velocities = []
        self.angular_velocities = []
        self.velocity_history = []
        self.cumul_freeze_sec = 0.0
        self.freeze_start = None
        self.active_seed = self.random_seed_base + self.trial_id
        self.actor_pose_msgs_after_reset = 0
        self.prediction_msgs_after_reset = 0
        self.actor_reset_done_time = None
        self.robot_reset_done_time = None
        self.static_collision = False
        self.static_collision_obstacle_id = -1
        self.fail_x = float('nan')
        self.fail_y = float('nan')
        self.fail_theta = float('nan')
        self.fail_speed = float('nan')
        self.fail_prev3_mean_linear_velocity = float('nan')
        self.fail_prev3_max_linear_velocity = float('nan')
        self.fail_prev3_mean_angular_velocity = float('nan')
        self.fail_prev3_max_angular_velocity = float('nan')
        self.fail_static_obstacle_id = -1
        self.fail_current_ped_clearance = float('nan')

    def odom_callback(self, msg: Odometry):
        self.odom_ready = True
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        self.theta = self.yaw_from_quaternion(msg.pose.pose.orientation)
        self.v = msg.twist.twist.linear.x
        self.w = msg.twist.twist.angular.z
        if self.state == 'running':
            self.linear_velocities.append(abs(self.v))
            self.angular_velocities.append(abs(self.w))
            self.velocity_history.append((time.time(), abs(self.v), abs(self.w)))
            self.path_deviations.append(abs(self.x - self.goal_x))
            self.update_ped_clearance()
            self.update_static_collision()
            self.update_freeze()

    def actor_pose_callback(self, msg: PoseArray):
        self.actor_poses = [(pose.position.x, pose.position.y) for pose in msg.poses]
        self.actor_count = len(self.actor_poses) or self.actor_count
        if self.state in ('warming_actors', 'resetting_robot', 'settling_robot'):
            self.actor_pose_msgs_after_reset += 1
        if self.state == 'running':
            self.update_ped_clearance()

    def prediction_callback(self, _msg: MotionPredictionResult):
        if self.state in ('warming_actors', 'resetting_robot', 'settling_robot'):
            self.prediction_msgs_after_reset += 1

    def geometry_map_callback(self, msg: MapMsg):
        self.geometry_map_obstacle_count = len(msg.obstacle_list.polygon_objects)
        self.geometry_map_ready = self.geometry_map_obstacle_count > 0

    def timer_callback(self):
        now = time.time()
        if self.state == 'startup':
            if now - self.state_since < self.startup_delay_sec:
                return
            if not self.obstacles_ready():
                self.get_logger().warn('waiting for static/geometry obstacles to load...')
                self.state_since = time.time()
                return
            self.begin_reset()
        elif self.state == 'clearing_reset_state':
            self.check_reset_clear_done()
        elif self.state == 'resetting_actors':
            self.check_actor_reset_done()
        elif self.state == 'warming_actors':
            self.check_actor_warmup_done()
        elif self.state == 'resetting_robot':
            self.check_robot_reset_done()
        elif self.state == 'settling_robot':
            self.check_robot_settle_done()
        elif self.state == 'releasing_mpc':
            self.check_mpc_release_done()
        elif self.state == 'running':
            self.check_trial_done()
        elif self.state == 'between_trials':
            if now - self.state_since >= self.inter_trial_delay_sec:
                self.begin_reset()

    def begin_reset(self):
        if self.trial_id >= self.num_trials:
            self.state = 'done'
            self.get_logger().info(f'all RViz-only trials complete: {self.output_csv}')
            return
        if not self.obstacles_ready():
            self.get_logger().warn('waiting for static/geometry obstacles to load...')
            self.state = 'startup'
            self.state_since = time.time()
            return

        self.reset_metrics()
        if not self.mpc_reset_client.wait_for_service(timeout_sec=0.1):
            self.get_logger().warn(
                f'[trial {self.trial_id:03d}] waiting for MPC policy reset service...')
            self.state = 'startup'
            self.state_since = time.time()
            return
        if not self.prediction_clear_client.wait_for_service(timeout_sec=0.1):
            self.get_logger().warn(
                f'[trial {self.trial_id:03d}] waiting for motion prediction clear service...')
            self.state = 'startup'
            self.state_since = time.time()
            return

        self.reset_clear_futures = {}
        self.reset_clear_futures['mpc_policy'] = self.mpc_reset_client.call_async(
            Trigger.Request())
        self.reset_clear_futures['motion_prediction'] = (
            self.prediction_clear_client.call_async(Trigger.Request()))

        if self.reset_clear_futures:
            self.state = 'clearing_reset_state'
            self.state_since = time.time()
            self.get_logger().info(
                f'[trial {self.trial_id:03d}] reset clear requested: '
                f'{", ".join(self.reset_clear_futures)}'
            )
            return

        self.request_actor_reset()

    def check_reset_clear_done(self):
        elapsed = time.time() - self.state_since
        if (
            elapsed < self.reset_clear_timeout_sec
            and not all(future.done() for future in self.reset_clear_futures.values())
        ):
            return
        for name, future in self.reset_clear_futures.items():
            if not future.done():
                self.get_logger().warn(
                    f'[trial {self.trial_id:03d}] reset clear timeout: {name}')
                continue
            try:
                result = future.result()
                if result is not None and not result.success:
                    self.get_logger().warn(
                        f'[trial {self.trial_id:03d}] reset clear failed: '
                        f'{name}: {result.message}')
            except Exception as exc:
                self.get_logger().warn(
                    f'[trial {self.trial_id:03d}] reset clear failed: {name}: {exc}')
        self.request_actor_reset()

    def request_actor_reset(self):
        if not self.actor_reset_client.service_is_ready():
            self.actor_reset_client.wait_for_service(timeout_sec=0.1)
        if not self.actor_reset_client.service_is_ready():
            self.get_logger().warn('waiting for RViz simulator reset services...')
            self.state = 'startup'
            self.state_since = time.time()
            return

        self.actor_future = self.actor_reset_client.call_async(Trigger.Request())
        self.robot_future = None
        self.state = 'resetting_actors'
        self.state_since = time.time()
        self.get_logger().info(
            f'[trial {self.trial_id:03d}] actor reset requested seed={self.active_seed}'
        )

    def check_actor_reset_done(self):
        if not self.actor_future.done():
            if time.time() - self.state_since > 5.0:
                self.finish_trial(False, 'node_error')
            return

        try:
            actor_result = self.actor_future.result()
            match = re.search(r'actor_count=(\d+)', actor_result.message or '')
            if match:
                self.actor_count = int(match.group(1))
        except Exception as exc:
            self.get_logger().warn(f'actor reset failed: {exc}')
            self.finish_trial(False, 'node_error')
            return

        self.actor_reset_done_time = time.time()
        self.state = 'warming_actors'
        self.state_since = time.time()
        self.get_logger().info(
            f'[trial {self.trial_id:03d}] actors warming: '
            f'actor_count={self.actor_count}, warmup={self.actor_warmup_sec:.1f}s'
        )

    def check_actor_warmup_done(self):
        elapsed = time.time() - self.state_since
        actor_ready = self.actor_pose_msgs_after_reset >= self.min_actor_pose_msgs_after_reset
        prediction_ready = (
            not self.require_prediction_after_reset
            or self.prediction_msgs_after_reset > 0
        )
        if elapsed < self.actor_warmup_sec or not actor_ready or not prediction_ready:
            if elapsed > self.actor_warmup_timeout_sec:
                self.get_logger().warn(
                    f'[trial {self.trial_id:03d}] actor warmup timeout; continuing with '
                    f'actor_ready={actor_ready}, prediction_ready={prediction_ready}, '
                    f'actor_pose_msgs={self.actor_pose_msgs_after_reset}, '
                    f'prediction_msgs={self.prediction_msgs_after_reset}'
                )
            else:
                return
        if elapsed < self.actor_warmup_sec:
            return

        if not self.robot_reset_client.service_is_ready():
            self.robot_reset_client.wait_for_service(timeout_sec=0.1)
        if not self.robot_reset_client.service_is_ready():
            self.get_logger().warn('waiting for RViz robot reset service...')
            return

        self.robot_future = self.robot_reset_client.call_async(Trigger.Request())
        self.state = 'resetting_robot'
        self.state_since = time.time()
        self.get_logger().info(
            f'[trial {self.trial_id:03d}] robot reset requested after actor warmup: '
            f'actor_pose_msgs={self.actor_pose_msgs_after_reset}, '
            f'prediction_msgs={self.prediction_msgs_after_reset}'
        )

    def check_robot_reset_done(self):
        if self.robot_future is None or not self.robot_future.done():
            if time.time() - self.state_since > 5.0:
                self.finish_trial(False, 'node_error')
            return

        try:
            result = self.robot_future.result()
            if not result.success:
                self.get_logger().warn(f'robot reset failed: {result.message}')
                self.finish_trial(False, 'node_error')
                return
        except Exception as exc:
            self.get_logger().warn(f'robot reset failed: {exc}')
            self.finish_trial(False, 'node_error')
            return

        self.robot_reset_done_time = time.time()
        self.state = 'settling_robot'
        self.state_since = time.time()
        self.get_logger().info(
            f'[trial {self.trial_id:03d}] robot settling: settle={self.robot_settle_sec:.1f}s'
        )

    def check_robot_settle_done(self):
        if time.time() - self.state_since < self.robot_settle_sec:
            return
        if self.mpc_release_client.wait_for_service(timeout_sec=0.1):
            self.mpc_release_future = self.mpc_release_client.call_async(Trigger.Request())
            self.state = 'releasing_mpc'
            self.state_since = time.time()
            self.get_logger().info(f'[trial {self.trial_id:03d}] MPC release requested')
            return
        self.get_logger().warn(
            f'[trial {self.trial_id:03d}] MPC release service not available; starting trial')
        self.start_running_trial()

    def check_mpc_release_done(self):
        if (
            time.time() - self.state_since < self.reset_clear_timeout_sec
            and not self.mpc_release_future.done()
        ):
            return
        if not self.mpc_release_future.done():
            self.get_logger().warn(
                f'[trial {self.trial_id:03d}] MPC release timeout; starting trial')
        else:
            try:
                result = self.mpc_release_future.result()
                if result is not None and not result.success:
                    self.get_logger().warn(
                        f'[trial {self.trial_id:03d}] MPC release failed: {result.message}')
            except Exception as exc:
                self.get_logger().warn(
                    f'[trial {self.trial_id:03d}] MPC release failed: {exc}')
        self.start_running_trial()

    def start_running_trial(self):
        self.trial_start_time = time.time()
        self.state = 'running'
        self.get_logger().info(
            f'[trial {self.trial_id:03d}] started actor_count={self.actor_count} '
            f'actor_pose_msgs={self.actor_pose_msgs_after_reset} '
            f'prediction_msgs={self.prediction_msgs_after_reset}'
        )

    def check_trial_done(self):
        if self.trial_start_time is None:
            return
        if self.distance_to_goal() <= self.goal_tolerance:
            self.finish_trial(True, 'success')
            return
        if self.ped_collision_active():
            self.finish_trial(False, 'collision')
            return
        if self.static_collision:
            self.finish_trial(False, 'static_collision')
            return
        if self.cumul_freeze_sec > self.freeze_fail_sec:
            self.finish_trial(False, 'freeze')
            return
        if time.time() - self.trial_start_time > self.trial_timeout_sec:
            self.finish_trial(False, 'timeout')

    def finish_trial(self, success, fail_reason):
        if self.state == 'done':
            return
        self.finish_freeze()
        elapsed = time.time() - self.trial_start_time if self.trial_start_time else 0.0
        if not success:
            self.fail_x = self.x
            self.fail_y = self.y
            self.fail_theta = getattr(self, 'theta', float('nan'))
            self.fail_speed = self.v
            self.capture_fail_velocity_window()
            self.fail_static_obstacle_id = (
                self.static_collision_obstacle_id if fail_reason == 'static_collision' else -1
            )
            self.fail_current_ped_clearance = self.current_ped_clearance
        row = {
            'trial_id': self.trial_id,
            'seed': self.active_seed,
            'success': int(success),
            'fail_reason': fail_reason,
            'elapsed_sec': self.fmt(elapsed),
            'actor_count': self.actor_count,
            'min_ped_clearance_m': self.fmt(
                self.min_ped_clearance if self.min_ped_clearance != float('inf') else float('nan')),
            'mean_path_deviation_m': self.fmt(self.mean(self.path_deviations)),
            'max_path_deviation_m': self.fmt(max(self.path_deviations) if self.path_deviations else float('nan')),
            'cumul_freeze_sec': self.fmt(self.cumul_freeze_sec),
            'mean_linear_velocity_mps': self.fmt(self.mean(self.linear_velocities)),
            'min_linear_velocity_mps': self.fmt(min(self.linear_velocities) if self.linear_velocities else float('nan')),
            'mean_solver_ms': 'NaN',
            'max_solver_ms': 'NaN',
            'fail_x': self.fmt(self.fail_x),
            'fail_y': self.fmt(self.fail_y),
            'fail_theta': self.fmt(self.fail_theta),
            'fail_speed_mps': self.fmt(self.fail_speed),
            'fail_prev3_mean_linear_velocity_mps': self.fmt(
                self.fail_prev3_mean_linear_velocity),
            'fail_prev3_max_linear_velocity_mps': self.fmt(
                self.fail_prev3_max_linear_velocity),
            'fail_prev3_mean_angular_velocity_radps': self.fmt(
                self.fail_prev3_mean_angular_velocity),
            'fail_prev3_max_angular_velocity_radps': self.fmt(
                self.fail_prev3_max_angular_velocity),
            'fail_static_obstacle_id': self.fail_static_obstacle_id,
            'fail_current_ped_clearance_m': self.fmt(self.fail_current_ped_clearance),
        }
        with open(self.output_csv, 'a', newline='') as csv_file:
            csv.DictWriter(csv_file, fieldnames=CSV_FIELDS).writerow(row)
        self.get_logger().info(
            f"[trial {self.trial_id:03d}] success={int(success)} "
            f"reason={fail_reason} elapsed={row['elapsed_sec']} actors={self.actor_count}"
        )

        self.trial_id += 1
        self.state = 'between_trials'
        self.state_since = time.time()

    def capture_fail_velocity_window(self, window_sec=3.0):
        now = time.time()
        recent = [
            item for item in self.velocity_history
            if now - item[0] <= window_sec
        ]
        if not recent:
            return
        linear_values = [item[1] for item in recent]
        angular_values = [item[2] for item in recent]
        self.fail_prev3_mean_linear_velocity = self.mean(linear_values)
        self.fail_prev3_max_linear_velocity = max(linear_values)
        self.fail_prev3_mean_angular_velocity = self.mean(angular_values)
        self.fail_prev3_max_angular_velocity = max(angular_values)

    def update_ped_clearance(self):
        if not self.odom_ready:
            return
        if not self.actor_poses:
            self.current_ped_clearance = float('inf')
            return
        self.current_ped_clearance = min(
            math.hypot(self.x - ax, self.y - ay)
            for ax, ay in self.actor_poses
        )
        for ax, ay in self.actor_poses:
            self.min_ped_clearance = min(
                self.min_ped_clearance,
                math.hypot(self.x - ax, self.y - ay),
            )

    def ped_collision_active(self):
        if self.current_ped_clearance >= self.collision_distance:
            return False
        if not self.collision_ignore_when_stopped:
            return True
        return abs(self.v) >= self.collision_motion_threshold

    def update_static_collision(self):
        if not self.static_obstacles or not self.odom_ready:
            return
        for obs_id, obs in enumerate(self.static_obstacles):
            if point_in_poly((self.x, self.y), obs):
                self.static_collision = True
                self.static_collision_obstacle_id = obs_id
                return

    def obstacles_ready(self):
        local_ready = (not self.enable_static_collision_check) or bool(self.static_obstacles)
        ros_ready = (not self.require_geometry_map_ready) or self.geometry_map_ready
        return local_ready and ros_ready

    def update_freeze(self):
        frozen = abs(self.v) < self.freeze_velocity_threshold and self.distance_to_goal() > 1.0
        if frozen and self.current_ped_clearance <= self.freeze_ignore_ped_distance:
            if self.freeze_start is not None:
                self.cumul_freeze_sec += time.time() - self.freeze_start
                self.freeze_start = None
            return
        now = time.time()
        if frozen and self.freeze_start is None:
            self.freeze_start = now
        elif not frozen and self.freeze_start is not None:
            self.cumul_freeze_sec += now - self.freeze_start
            self.freeze_start = None

    def finish_freeze(self):
        if self.freeze_start is not None:
            self.cumul_freeze_sec += time.time() - self.freeze_start
            self.freeze_start = None

    def distance_to_goal(self):
        if not self.odom_ready:
            return float('inf')
        return math.hypot(self.x - self.goal_x, self.y - self.goal_y)

    @staticmethod
    def mean(values):
        return sum(values) / len(values) if values else float('nan')

    @staticmethod
    def fmt(value):
        if isinstance(value, float):
            if math.isnan(value):
                return 'NaN'
            return round(value, 4)
        return value

    @staticmethod
    def yaw_from_quaternion(q):
        siny_cosp = 2.0 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        return math.atan2(siny_cosp, cosy_cosp)


def main(args=None):
    rclpy.init(args=args)
    node = RvizTrialManager()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
