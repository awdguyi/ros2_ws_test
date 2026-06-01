#!/usr/bin/env python3

import argparse
import csv
import math
import os
import random
import re
import signal
import shlex
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Optional

import rclpy
from ament_index_python.packages import get_package_share_directory
from gazebo_msgs.msg import ModelStates
from nav_msgs.msg import Odometry
from rclpy.node import Node


ACTOR_MIN_COUNT = 10
ACTOR_MAX_COUNT = 15
ACTOR_HOLD_UNTIL = 120.0
ACTOR_MIN_SPEED = 0.24
ACTOR_MAX_SPEED = 0.588
ACTOR_CLEARANCE = 0.65
ACTOR_SAMPLE_ATTEMPTS = 2000
MIN_MAIN_AISLE_LENGTH = 1.0
ACTOR_LATERAL_OFFSET_MIN = 0.15
ACTOR_LATERAL_OFFSET_MAX = 0.55
MIN_RANDOM_ROUTE_LENGTH = 8.0

SUMMARY_FIELDS = [
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
    'world_file',
]

KILL_PATTERNS = [
    'gzserver',
    'gzclient',
    'gazebo',
    'ros2 launch zmr_demo demo_warehouse_single_robot_gazebo_mpc_mmp.launch.py',
    'rviz2',
    'robot_state_publisher',
    'spawn_robot',
    'mpc_trajectory_tracker_node',
    'motion_prediction_node',
    'actor_traj_publisher',
    'global_path_coordinate_node',
    'geometric_map_node',
]

WORKSPACE_ROOT = Path('/home/michael/ros2_ws_test')


@dataclass
class GeneratedWorld:
    path: str
    actor_count: int


class TrialMonitor(Node):
    def __init__(self, robot_namespace: str, goal_x: float, goal_y: float):
        super().__init__('random_trial_monitor')
        self.robot_namespace = robot_namespace.strip('/')
        self.goal_x = goal_x
        self.goal_y = goal_y
        self.create_subscription(
            Odometry,
            f'/{self.robot_namespace}/odom',
            self._odom_callback,
            20,
        )
        self.create_subscription(
            ModelStates,
            '/gazebo/model_states',
            self._model_states_callback,
            20,
        )
        self.reset()

    def reset(self):
        self.odom_ready = False
        self.model_states_ready = False
        self.x = float('nan')
        self.y = float('nan')
        self.v = 0.0
        self.robot_pose = None
        self.actor_poses = {}
        self.min_ped_clearance = float('inf')
        self.path_deviations = []
        self.linear_velocities = []
        self.cumul_freeze_sec = 0.0
        self._freeze_start = None
        self._last_update = None

    def _odom_callback(self, msg: Odometry):
        now = time.time()
        self.x = msg.pose.pose.position.x
        self.y = msg.pose.pose.position.y
        self.v = msg.twist.twist.linear.x
        self.robot_pose = (self.x, self.y)
        self.odom_ready = True
        self.linear_velocities.append(abs(self.v))
        self.path_deviations.append(abs(self.x - 1.0))

        frozen = abs(self.v) < 0.05 and self.distance_to_goal() > 1.0
        if frozen and self._freeze_start is None:
            self._freeze_start = now
        elif not frozen and self._freeze_start is not None:
            self.cumul_freeze_sec += now - self._freeze_start
            self._freeze_start = None
        self._last_update = now

    def _model_states_callback(self, msg: ModelStates):
        self.model_states_ready = True
        actor_poses = {}
        robot_pose = self.robot_pose
        for name, pose in zip(msg.name, msg.pose):
            if re.fullmatch(r'actor\d+', name):
                actor_poses[name] = (pose.position.x, pose.position.y)
            elif name in (f'{self.robot_namespace}/robot', self.robot_namespace):
                robot_pose = (pose.position.x, pose.position.y)
        self.actor_poses = actor_poses
        if robot_pose is not None:
            self.robot_pose = robot_pose
        if self.robot_pose is not None and actor_poses:
            rx, ry = self.robot_pose
            for ax, ay in actor_poses.values():
                self.min_ped_clearance = min(
                    self.min_ped_clearance,
                    math.hypot(rx - ax, ry - ay),
                )

    def ready(self) -> bool:
        # Gazebo does not always publish /gazebo/model_states in this launch stack.
        # Odom is the required signal for trial progress; model_states only enriches
        # optional pedestrian-clearance metrics when it is available.
        return self.odom_ready

    def distance_to_goal(self) -> float:
        if not self.odom_ready:
            return float('inf')
        return math.hypot(self.x - self.goal_x, self.y - self.goal_y)

    def finish_freeze(self):
        if self._freeze_start is not None:
            self.cumul_freeze_sec += time.time() - self._freeze_start
            self._freeze_start = None

    def metrics(self):
        self.finish_freeze()
        min_clearance = (
            self.min_ped_clearance if self.min_ped_clearance != float('inf') else float('nan')
        )
        mean_dev = (
            sum(self.path_deviations) / len(self.path_deviations)
            if self.path_deviations else float('nan')
        )
        max_dev = max(self.path_deviations) if self.path_deviations else float('nan')
        mean_v = (
            sum(self.linear_velocities) / len(self.linear_velocities)
            if self.linear_velocities else float('nan')
        )
        min_v = min(self.linear_velocities) if self.linear_velocities else float('nan')
        return {
            'min_ped_clearance_m': min_clearance,
            'mean_path_deviation_m': mean_dev,
            'max_path_deviation_m': max_dev,
            'cumul_freeze_sec': self.cumul_freeze_sec,
            'mean_linear_velocity_mps': mean_v,
            'min_linear_velocity_mps': min_v,
        }


def point_in_poly(point, poly):
    x, y = point
    inside = False
    j = len(poly) - 1
    for i in range(len(poly)):
        xi, yi = poly[i]
        xj, yj = poly[j]
        crosses = (yi > y) != (yj > y)
        if crosses:
            x_at_y = (xj - xi) * (y - yi) / ((yj - yi) or 1e-9) + xi
            inside = inside != (x < x_at_y)
        j = i
    return inside


def ccw(a, b, c):
    return (c[1] - a[1]) * (b[0] - a[0]) > (b[1] - a[1]) * (c[0] - a[0])


def segments_intersect(a, b, c, d):
    return ccw(a, c, d) != ccw(b, c, d) and ccw(a, b, c) != ccw(a, b, d)


def expanded_bbox_poly(poly, margin):
    xs = [p[0] for p in poly]
    ys = [p[1] for p in poly]
    return [
        [min(xs) - margin, min(ys) - margin],
        [min(xs) - margin, max(ys) + margin],
        [max(xs) + margin, max(ys) + margin],
        [max(xs) + margin, min(ys) - margin],
    ]


def segment_hits_poly(start, end, poly):
    if point_in_poly(start, poly) or point_in_poly(end, poly):
        return True
    for idx, vertex in enumerate(poly):
        if segments_intersect(start, end, tuple(vertex), tuple(poly[(idx + 1) % len(poly)])):
            return True
    return False


def load_walkable_area(map_file_name):
    map_share = package_share('map_description')
    map_path = Path(map_share) / 'data' / map_file_name
    with open(map_path, 'r', encoding='utf-8') as map_file:
        data = __import__('json').load(map_file)
    boundary = data['boundary_coords']
    obstacles = data.get('obstacle_list')
    if obstacles is None:
        obstacles = [obs['vertices'] for obs in data.get('obstacle_dict', [])]
    inflated_obstacles = [expanded_bbox_poly(obs, ACTOR_CLEARANCE) for obs in obstacles]
    return boundary, inflated_obstacles


def path_is_clear(start, end, boundary, inflated_obstacles):
    if not point_in_poly(start, boundary) or not point_in_poly(end, boundary):
        return False
    if any(point_in_poly(start, obs) or point_in_poly(end, obs) for obs in inflated_obstacles):
        return False
    return all(not segment_hits_poly(start, end, obs) for obs in inflated_obstacles)


def shortest_graph_path(node_dict, edge_list, start_id, goal_id):
    unvisited = set(node_dict)
    dist = {node_id: float('inf') for node_id in node_dict}
    prev = {}
    dist[start_id] = 0.0
    adjacency = {node_id: [] for node_id in node_dict}
    for source_id, target_id in edge_list:
        source_id = str(source_id)
        target_id = str(target_id)
        source = node_dict[source_id]
        target = node_dict[target_id]
        weight = math.hypot(target[0] - source[0], target[1] - source[1])
        adjacency[source_id].append((target_id, weight))
        adjacency[target_id].append((source_id, weight))

    while unvisited:
        current = min(unvisited, key=lambda node_id: dist[node_id])
        unvisited.remove(current)
        if current == goal_id or dist[current] == float('inf'):
            break
        for neighbor, weight in adjacency[current]:
            if neighbor not in unvisited:
                continue
            alt = dist[current] + weight
            if alt < dist[neighbor]:
                dist[neighbor] = alt
                prev[neighbor] = current

    if goal_id not in prev and goal_id != start_id:
        return []
    path = [goal_id]
    while path[-1] != start_id:
        path.append(prev[path[-1]])
    path.reverse()
    return path


def load_walkable_graph(graph_file_name, walkable_area):
    graph_share = package_share('mps_motion_plan')
    graph_path = Path(graph_share) / 'data' / graph_file_name
    with open(graph_path, 'r', encoding='utf-8') as graph_file:
        data = __import__('json').load(graph_file)
    boundary, inflated_obstacles = walkable_area
    node_dict = {
        str(node_id): [float(coord[0]), float(coord[1])]
        for node_id, coord in data['node_dict'].items()
    }
    walkable_edges = []
    for source_id, target_id in data['edge_list']:
        start = tuple(float(v) for v in node_dict[str(source_id)])
        end = tuple(float(v) for v in node_dict[str(target_id)])
        if math.hypot(end[0] - start[0], end[1] - start[1]) < MIN_MAIN_AISLE_LENGTH:
            continue
        if path_is_clear(start, end, boundary, inflated_obstacles):
            walkable_edges.append([str(source_id), str(target_id)])
    if not walkable_edges:
        raise RuntimeError(f'No collision-free graph edges found in {graph_path}')
    return node_dict, walkable_edges


def polyline_length(points):
    return sum(
        math.hypot(points[idx + 1][0] - points[idx][0], points[idx + 1][1] - points[idx][1])
        for idx in range(len(points) - 1)
    )


def random_offset_point(point):
    angle = random.uniform(-math.pi, math.pi)
    radius = random.uniform(ACTOR_LATERAL_OFFSET_MIN, ACTOR_LATERAL_OFFSET_MAX)
    return point[0] + math.cos(angle) * radius, point[1] + math.sin(angle) * radius


def sample_actor_path(walkable_area, walkable_graph):
    boundary, inflated_obstacles = walkable_area
    node_dict, edge_list = walkable_graph
    node_ids = list(node_dict)
    for _ in range(ACTOR_SAMPLE_ATTEMPTS):
        speed = random.uniform(ACTOR_MIN_SPEED, ACTOR_MAX_SPEED)
        start_id, goal_id = random.sample(node_ids, 2)
        path_ids = shortest_graph_path(node_dict, edge_list, start_id, goal_id)
        if len(path_ids) < 2:
            continue
        route_points = [tuple(node_dict[node_id]) for node_id in path_ids]
        if polyline_length(route_points) < MIN_RANDOM_ROUTE_LENGTH:
            continue
        actor_points = [random_offset_point(point) for point in route_points]
        if not all(point_in_poly(point, boundary) for point in actor_points):
            continue
        if any(point_in_poly(point, obs) for point in actor_points for obs in inflated_obstacles):
            continue
        if all(path_is_clear(actor_points[i], actor_points[i + 1], boundary, inflated_obstacles)
               for i in range(len(actor_points) - 1)):
            return actor_points, speed
    raise RuntimeError('Could not sample a collision-free actor path')


def path_yaw(points, idx):
    if idx < len(points) - 1:
        a, b = points[idx], points[idx + 1]
    else:
        a, b = points[idx - 1], points[idx]
    return math.atan2(b[1] - a[1], b[0] - a[0])


def waypoint_xml(points, speed):
    chunks = []
    current_time = 0.0
    for idx, point in enumerate(points):
        if idx > 0:
            prev = points[idx - 1]
            current_time += math.hypot(point[0] - prev[0], point[1] - prev[1]) / speed
        chunks.append(f'''
          <waypoint>
            <time>{current_time:.2f}</time>
            <pose>{point[0]:.3f} {point[1]:.3f} 0.0 0 0 {path_yaw(points, idx):.3f}</pose>
          </waypoint>''')
    last = points[-1]
    chunks.append(f'''
          <waypoint>
            <time>{max(ACTOR_HOLD_UNTIL, current_time + 1.0):.2f}</time>
            <pose>{last[0]:.3f} {last[1]:.3f} 0.0 0 0 {path_yaw(points, len(points) - 1):.3f}</pose>
          </waypoint>''')
    return ''.join(chunks)


def actor_xml(actor_idx, walkable_area, walkable_graph):
    points, speed = sample_actor_path(walkable_area, walkable_graph)
    start = points[0]
    return f'''
    <actor name="actor{actor_idx}">
      <pose>{start[0]:.3f} {start[1]:.3f} 0.0 0 0 {path_yaw(points, 0):.3f}</pose>
      <skin>
        <filename>walk.dae</filename>
        <scale>1.0</scale>
      </skin>
      <animation name="walking">
        <filename>walk.dae</filename>
        <scale>1.0</scale>
        <interpolate_x>true</interpolate_x>
      </animation>
      <plugin name="actor{actor_idx}_plugin" filename="libgazebo_ros_actor_pose.so">
        <updateRate>10</updateRate>
        <refFrameId>map</refFrameId>
      </plugin>
      <script>
        <loop>true</loop>
        <delay_start>0.0</delay_start>
        <auto_start>true</auto_start>
        <trajectory id="0" type="walking">
{waypoint_xml(points, speed)}
        </trajectory>
      </script>
    </actor>
'''


def resolve_base_world(base_world):
    if os.path.isabs(base_world):
        return base_world
    return str(Path(package_share('gazebo_worlds')) / 'worlds' / base_world)


def package_share(package_name):
    try:
        return get_package_share_directory(package_name)
    except Exception:
        fallback = WORKSPACE_ROOT / 'install' / package_name / 'share' / package_name
        if fallback.exists():
            return str(fallback)
        raise


def generate_world(base_world, output_path, seed, map_file_name, graph_file_name):
    random.seed(seed)
    with open(resolve_base_world(base_world), 'r', encoding='utf-8') as world_file:
        world_text = world_file.read()
    world_text = re.sub(
        r'\n\s*<actor name="actor\d+">.*?</actor>',
        '',
        world_text,
        flags=re.DOTALL,
    )
    walkable_area = load_walkable_area(map_file_name)
    walkable_graph = load_walkable_graph(graph_file_name, walkable_area)
    actor_count = random.randint(ACTOR_MIN_COUNT, ACTOR_MAX_COUNT)
    actors_text = '\n'.join(
        actor_xml(idx, walkable_area, walkable_graph)
        for idx in range(1, actor_count + 1)
    )
    world_text = world_text.replace('</world>', f'{actors_text}\n  </world>', 1)
    Path(output_path).parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, 'w', encoding='utf-8') as output_file:
        output_file.write(world_text)
    return GeneratedWorld(str(output_path), actor_count)


def kill_old_processes():
    for pattern in KILL_PATTERNS:
        subprocess.run(['pkill', '-f', pattern], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    time.sleep(3.0)


def terminate_process(proc: Optional[subprocess.Popen]):
    if proc is None or proc.poll() is not None:
        return
    try:
        os.killpg(os.getpgid(proc.pid), signal.SIGINT)
        proc.wait(timeout=8)
    except Exception:
        try:
            os.killpg(os.getpgid(proc.pid), signal.SIGTERM)
            proc.wait(timeout=5)
        except Exception:
            try:
                os.killpg(os.getpgid(proc.pid), signal.SIGKILL)
            except Exception:
                pass


def read_mpc_row(csv_path, scenario_id, since_mtime):
    path = Path(csv_path).expanduser()
    if not path.exists() or path.stat().st_mtime < since_mtime:
        return None
    try:
        with open(path, newline='') as csv_file:
            rows = [row for row in csv.DictReader(csv_file) if row.get('scenario') == scenario_id]
    except Exception:
        return None
    return rows[-1] if rows else None


def map_fail_reason(reason):
    if not reason:
        return 'success'
    if reason in ('ped_too_close', 'robot_collision'):
        return 'collision'
    return reason


def launch_trial(args, trial_id, world: GeneratedWorld, scenario_id, log_path):
    ros_args = [
        'ros2', 'launch', 'zmr_demo', 'demo_warehouse_single_robot_gazebo_mpc_mmp.launch.py',
        'use_sim_time:=true',
        'log_csv:=true',
        f'log_wandb:={str(args.log_wandb).lower()}',
        f'scenario_id:={scenario_id}',
        f'predictor_variant:={args.predictor_variant}',
        f'world_file_name:={world.path}',
        'randomize_actors:=false',
        'reset_on_finish:=false',
        'rerandomize_actors_on_reset:=false',
        f'max_task_time:={args.timeout_sec}',
        f'use_rviz:={str(args.use_rviz).lower()}',
    ]
    setup_path = Path(args.workspace) / 'install' / 'setup.bash'
    cmd = [
        '/bin/bash',
        '-lc',
        f'source {shlex.quote(str(setup_path))} && '
        + ' '.join(shlex.quote(part) for part in ros_args),
    ]
    log_path.parent.mkdir(parents=True, exist_ok=True)
    log_file = open(log_path, 'w', encoding='utf-8')
    proc = subprocess.Popen(
        cmd,
        cwd=args.workspace,
        stdout=log_file,
        stderr=subprocess.STDOUT,
        preexec_fn=os.setsid,
        text=True,
    )
    return proc, log_file


def write_summary_header(path):
    write_header = not Path(path).exists()
    if write_header:
        with open(path, 'w', newline='') as csv_file:
            csv.DictWriter(csv_file, fieldnames=SUMMARY_FIELDS).writeheader()


def append_summary(path, row):
    with open(path, 'a', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=SUMMARY_FIELDS)
        writer.writerow({field: row.get(field, '') for field in SUMMARY_FIELDS})


def fmt(value):
    if value is None:
        return ''
    if isinstance(value, float):
        if math.isnan(value):
            return 'NaN'
        return round(value, 4)
    return value


def run_one_trial(args, monitor, trial_id):
    seed = args.random_seed_base + trial_id
    world_path = Path(args.tmp_world_dir) / f'random_world_trial_{trial_id:03d}.world'
    scenario_id = f'{args.scenario_name}_trial_{trial_id:03d}'
    log_path = Path(args.log_dir) / f'trial_{trial_id:03d}.log'
    mpc_csv = Path(args.workspace) / 'experiment_results_robot0.csv'
    mpc_csv_mtime = mpc_csv.stat().st_mtime if mpc_csv.exists() else 0

    kill_old_processes()
    world = generate_world(
        args.base_world,
        world_path,
        seed,
        args.map_file_name,
        args.graph_file_name,
    )
    monitor.reset()
    proc = None
    log_file = None
    start_time = time.time()
    fail_reason = 'unknown'
    success = False

    try:
        proc, log_file = launch_trial(args, trial_id, world, scenario_id, log_path)

        ready_deadline = time.time() + args.startup_timeout_sec
        while time.time() < ready_deadline and proc.poll() is None:
            rclpy.spin_once(monitor, timeout_sec=0.1)
            if monitor.ready():
                break
        if not monitor.ready():
            fail_reason = 'node_crash' if proc.poll() is not None else 'unknown'
        else:
            deadline = time.time() + args.timeout_sec + 10.0
            while time.time() < deadline and proc.poll() is None:
                rclpy.spin_once(monitor, timeout_sec=0.1)
                if monitor.distance_to_goal() <= args.goal_tolerance:
                    success = True
                    fail_reason = 'success'
                    time.sleep(1.0)
                    break
                if monitor.min_ped_clearance < args.collision_distance:
                    fail_reason = 'collision'
                    break
                if monitor.cumul_freeze_sec > args.freeze_timeout_sec:
                    fail_reason = 'freeze'
                    break

            if not success and fail_reason == 'unknown':
                if proc.poll() is not None:
                    fail_reason = 'gazebo_crash'
                else:
                    fail_reason = 'timeout'

        elapsed = time.time() - start_time
        time.sleep(0.5)
        mpc_row = read_mpc_row(mpc_csv, scenario_id, mpc_csv_mtime)
        metrics = monitor.metrics()
        if mpc_row:
            success = mpc_row.get('success') == '1'
            fail_reason = map_fail_reason(mpc_row.get('failure_reason', ''))
            elapsed = float(mpc_row.get('elapsed_sec') or elapsed)
            metrics['min_ped_clearance_m'] = float(mpc_row.get('min_ped_clearance_m') or 'nan')
            metrics['mean_path_deviation_m'] = float(mpc_row.get('path_dev_mean_m') or 'nan')
            metrics['max_path_deviation_m'] = float(mpc_row.get('path_dev_max_m') or 'nan')
            metrics['cumul_freeze_sec'] = float(mpc_row.get('total_freeze_sec') or 'nan')
            metrics['mean_linear_velocity_mps'] = float(mpc_row.get('avg_v_mps') or 'nan')
            mean_solver_ms = float(mpc_row.get('avg_solver_ms') or 'nan')
            max_solver_ms = float(mpc_row.get('max_solver_ms') or 'nan')
        else:
            mean_solver_ms = float('nan')
            max_solver_ms = float('nan')

        return {
            'trial_id': trial_id,
            'seed': seed,
            'success': int(success),
            'fail_reason': fail_reason,
            'elapsed_sec': fmt(elapsed),
            'actor_count': world.actor_count,
            'min_ped_clearance_m': fmt(metrics['min_ped_clearance_m']),
            'mean_path_deviation_m': fmt(metrics['mean_path_deviation_m']),
            'max_path_deviation_m': fmt(metrics['max_path_deviation_m']),
            'cumul_freeze_sec': fmt(metrics['cumul_freeze_sec']),
            'mean_linear_velocity_mps': fmt(metrics['mean_linear_velocity_mps']),
            'min_linear_velocity_mps': fmt(metrics['min_linear_velocity_mps']),
            'mean_solver_ms': fmt(mean_solver_ms),
            'max_solver_ms': fmt(max_solver_ms),
            'world_file': world.path,
        }
    finally:
        terminate_process(proc)
        if log_file:
            log_file.close()
        kill_old_processes()


def parse_args():
    parser = argparse.ArgumentParser(description='Run repeated Gazebo relaunch trials with randomized actors baked into temporary worlds.')
    parser.add_argument('--num-trials', type=int, default=100)
    parser.add_argument('--timeout-sec', type=float, default=90.0)
    parser.add_argument('--startup-timeout-sec', type=float, default=35.0)
    parser.add_argument('--random-seed-base', type=int, default=1000)
    parser.add_argument('--base-world', default='aws/small_warehouse_2.world')
    parser.add_argument('--output-csv', default='experiment_results_100_trials.csv')
    parser.add_argument('--scenario-name', default='random_warehouse_100')
    parser.add_argument('--predictor-variant', default='ST-warehouse-progress')
    parser.add_argument('--map-file-name', default='warehouse_map_real.json')
    parser.add_argument('--graph-file-name', default='warehouse_graph.json')
    parser.add_argument('--workspace', default='/home/michael/ros2_ws_test')
    parser.add_argument('--tmp-world-dir', default='/tmp/random_world_trials')
    parser.add_argument('--log-dir', default='/tmp/random_world_trials/logs')
    parser.add_argument('--goal-x', type=float, default=1.0)
    parser.add_argument('--goal-y', type=float, default=12.3)
    parser.add_argument('--goal-tolerance', type=float, default=0.5)
    parser.add_argument('--collision-distance', type=float, default=0.25)
    parser.add_argument('--freeze-timeout-sec', type=float, default=20.0)
    parser.add_argument('--robot-namespace', default='zmr_X')
    parser.add_argument('--log-wandb', action='store_true')
    parser.add_argument('--use-rviz', action='store_true')
    return parser.parse_args()


def main():
    args = parse_args()
    global WORKSPACE_ROOT
    WORKSPACE_ROOT = Path(args.workspace)
    output_csv = Path(args.output_csv)
    if not output_csv.is_absolute():
        output_csv = Path(args.workspace) / output_csv
    write_summary_header(output_csv)

    rclpy.init()
    monitor = TrialMonitor(args.robot_namespace, args.goal_x, args.goal_y)
    try:
        for trial_id in range(args.num_trials):
            row = run_one_trial(args, monitor, trial_id)
            append_summary(output_csv, row)
            print(
                f"[trial {trial_id:03d}] success={row['success']} "
                f"reason={row['fail_reason']} elapsed={row['elapsed_sec']} "
                f"actors={row['actor_count']} world={row['world_file']}",
                flush=True,
            )
    finally:
        monitor.destroy_node()
        rclpy.shutdown()
        kill_old_processes()

    print(f"[done] summary CSV: {output_csv}")


if __name__ == '__main__':
    main()
