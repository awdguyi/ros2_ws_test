#!/usr/bin/env python3

import json
import math
import random
from collections import deque
from pathlib import Path

import rclpy
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import Point, Pose, PoseArray
from mmp_interfaces.msg import HumanTrajectory, HumanTrajectoryArray
from rcl_interfaces.msg import ParameterDescriptor
from rclpy.node import Node
from std_srvs.srv import Trigger
from visualization_msgs.msg import Marker, MarkerArray


ACTOR_SAMPLE_ATTEMPTS = 2000
MAX_SAMPLE_ATTEMPTS = 100
PROTECTION_CHECK_DT = 0.25


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
    for a, b in edge_list:
        ax, ay = node_dict[a]
        bx, by = node_dict[b]
        cost = math.hypot(bx - ax, by - ay)
        adjacency[a].append((b, cost))
        adjacency[b].append((a, cost))

    while unvisited:
        current = min(unvisited, key=lambda node_id: dist[node_id])
        if current == goal_id or dist[current] == float('inf'):
            break
        unvisited.remove(current)
        for neighbor, cost in adjacency[current]:
            alt = dist[current] + cost
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


def polyline_length(points):
    return sum(
        math.hypot(points[idx + 1][0] - points[idx][0], points[idx + 1][1] - points[idx][1])
        for idx in range(len(points) - 1)
    )


class RvizActorSimulator(Node):
    def __init__(self):
        super().__init__('rviz_actor_simulator')

        descriptor = ParameterDescriptor(dynamic_typing=True)
        self.declare_parameter('timer_period', 0.2, descriptor)
        self.declare_parameter('actor_min_count', 7, descriptor)
        self.declare_parameter('actor_max_count', 15, descriptor)
        self.declare_parameter('random_seed_base', 1000, descriptor)
        self.declare_parameter('map_file_name', 'warehouse_map_real.json', descriptor)
        self.declare_parameter('graph_file_name', 'warehouse_graph.json', descriptor)
        self.declare_parameter('actor_min_speed', 0.24, descriptor)
        self.declare_parameter('actor_max_speed', 0.588, descriptor)
        self.declare_parameter('actor_clearance', 0.65, descriptor)
        self.declare_parameter('lateral_offset_min', 0.15, descriptor)
        self.declare_parameter('lateral_offset_max', 0.55, descriptor)
        self.declare_parameter('min_route_length', 8.0, descriptor)
        self.declare_parameter('min_edge_length', 1.0, descriptor)
        self.declare_parameter('history_length', 30, descriptor)
        self.declare_parameter('main_aisle_ratio', 0.45, descriptor)
        self.declare_parameter('min_main_aisle_actors', 4, descriptor)
        self.declare_parameter('main_aisle_progress_min', 0.25, descriptor)
        self.declare_parameter('main_aisle_progress_max', 0.90, descriptor)
        self.declare_parameter('main_aisle_width', 2.0, descriptor)
        self.declare_parameter('start_exclusion_radius', 2.5, descriptor)
        self.declare_parameter('start_front_clear_dist', 4.0, descriptor)
        self.declare_parameter('start_front_clear_width', 1.8, descriptor)
        self.declare_parameter('min_actor_spawn_separation', 0.8, descriptor)
        self.declare_parameter('spawn_protection_time_sec', 8.0, descriptor)
        self.declare_parameter('robot_path_protection_time_sec', 8.0, descriptor)
        self.declare_parameter('robot_path_protection_radius', 0.30, descriptor)
        self.declare_parameter('robot_path_protection_progress_max', 0.35, descriptor)

        self.timer_period = float(self.get_parameter('timer_period').value)
        self.actor_min_count = int(self.get_parameter('actor_min_count').value)
        self.actor_max_count = int(self.get_parameter('actor_max_count').value)
        self.random_seed_base = int(self.get_parameter('random_seed_base').value)
        self.map_file_name = str(self.get_parameter('map_file_name').value)
        self.graph_file_name = str(self.get_parameter('graph_file_name').value)
        self.actor_min_speed = float(self.get_parameter('actor_min_speed').value)
        self.actor_max_speed = float(self.get_parameter('actor_max_speed').value)
        self.actor_clearance = float(self.get_parameter('actor_clearance').value)
        self.lateral_offset_min = float(self.get_parameter('lateral_offset_min').value)
        self.lateral_offset_max = float(self.get_parameter('lateral_offset_max').value)
        self.min_route_length = float(self.get_parameter('min_route_length').value)
        self.min_edge_length = float(self.get_parameter('min_edge_length').value)
        self.history_length = int(self.get_parameter('history_length').value)
        self.main_aisle_ratio = float(self.get_parameter('main_aisle_ratio').value)
        self.min_main_aisle_actors = int(self.get_parameter('min_main_aisle_actors').value)
        self.main_aisle_progress_min = float(self.get_parameter('main_aisle_progress_min').value)
        self.main_aisle_progress_max = float(self.get_parameter('main_aisle_progress_max').value)
        self.main_aisle_width = float(self.get_parameter('main_aisle_width').value)
        self.start_exclusion_radius = float(self.get_parameter('start_exclusion_radius').value)
        self.start_front_clear_dist = float(self.get_parameter('start_front_clear_dist').value)
        self.start_front_clear_width = float(self.get_parameter('start_front_clear_width').value)
        self.min_actor_spawn_separation = float(self.get_parameter('min_actor_spawn_separation').value)
        self.spawn_protection_time_sec = float(self.get_parameter('spawn_protection_time_sec').value)
        self.robot_path_protection_time_sec = float(
            self.get_parameter('robot_path_protection_time_sec').value)
        self.robot_path_protection_radius = float(
            self.get_parameter('robot_path_protection_radius').value)
        self.robot_path_protection_progress_max = float(
            self.get_parameter('robot_path_protection_progress_max').value)

        self.boundary, self.inflated_obstacles = self.load_walkable_area()
        self.node_dict, self.edge_list = self.load_walkable_graph()
        self.main_aisle_centerline = [
            tuple(self.node_dict[node_id])
            for node_id in ('12', '11', '10', '9', '8')
        ]
        self.robot_start = self.main_aisle_centerline[0]
        self.robot_path_dir = self.unit_vector(
            self.robot_start,
            self.main_aisle_centerline[1],
        )
        self.main_aisle_length = polyline_length(self.main_aisle_centerline)
        self.trial_id = -1
        self.actors = []

        self.human_traj_publisher = self.create_publisher(
            HumanTrajectoryArray, '/human_traj_array', 10)
        self.pose_publisher = self.create_publisher(PoseArray, '/rviz_actor_poses', 10)
        self.marker_publisher = self.create_publisher(MarkerArray, '/rviz_actor_markers', 10)
        self.create_service(Trigger, '/reset_rviz_actors', self.reset_callback)
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        self.reset_actors()

    def package_share(self, package_name):
        return Path(get_package_share_directory(package_name))

    def load_walkable_area(self):
        map_path = self.package_share('map_description') / 'data' / self.map_file_name
        with open(map_path, 'r', encoding='utf-8') as map_file:
            data = json.load(map_file)
        boundary = data['boundary_coords']
        obstacles = data.get('obstacle_list')
        if obstacles is None:
            obstacles = [obs['vertices'] for obs in data.get('obstacle_dict', [])]
        inflated = [expanded_bbox_poly(obs, self.actor_clearance) for obs in obstacles]
        return boundary, inflated

    def load_walkable_graph(self):
        graph_path = self.package_share('mps_motion_plan') / 'data' / self.graph_file_name
        with open(graph_path, 'r', encoding='utf-8') as graph_file:
            data = json.load(graph_file)
        node_dict = {
            str(node_id): tuple(float(v) for v in coords)
            for node_id, coords in data['node_dict'].items()
        }
        walkable_edges = []
        for source_id, target_id in data['edge_list']:
            start = tuple(float(v) for v in node_dict[str(source_id)])
            end = tuple(float(v) for v in node_dict[str(target_id)])
            if math.hypot(end[0] - start[0], end[1] - start[1]) < self.min_edge_length:
                continue
            if path_is_clear(start, end, self.boundary, self.inflated_obstacles):
                walkable_edges.append([str(source_id), str(target_id)])
        if not walkable_edges:
            raise RuntimeError(f'No collision-free graph edges found in {graph_path}')
        return node_dict, walkable_edges

    def reset_callback(self, _request, response):
        self.reset_actors()
        response.success = True
        response.message = (
            f'trial_id={self.trial_id} seed={self.current_seed} actor_count={len(self.actors)}'
        )
        self.get_logger().info(response.message)
        return response

    def reset_actors(self):
        self.trial_id += 1
        self.current_seed = self.random_seed_base + self.trial_id
        random.seed(self.current_seed)
        actor_count = random.randint(self.actor_min_count, self.actor_max_count)
        main_count = max(
            self.min_main_aisle_actors,
            math.ceil(actor_count * self.main_aisle_ratio),
        )
        main_count = min(main_count, actor_count)
        other_count = actor_count - main_count
        self.get_logger().info(
            f'[random_actor] trial_id={self.trial_id} actor_count={actor_count} '
            f'main_aisle_nearby_actors={main_count} other_actors={other_count}'
        )

        actors = []
        spawn_points = []
        for actor_idx in range(1, main_count + 1):
            actor = self.sample_main_aisle_nearby_actor(actor_idx, spawn_points)
            actors.append(actor)
            spawn_points.append(self.actor_spawn(actor))
        for actor_idx in range(main_count + 1, actor_count + 1):
            actor = self.sample_other_actor(actor_idx, spawn_points)
            actors.append(actor)
            spawn_points.append(self.actor_spawn(actor))

        self.actors = actors
        self.log_generation_summary(actor_count, main_count, other_count, spawn_points)
        self.start_time = self.get_clock().now()
        self.publish_all()

    def sample_main_aisle_nearby_actor(self, actor_id, existing_spawns):
        separation = self.min_actor_spawn_separation
        for attempt in range(MAX_SAMPLE_ATTEMPTS):
            speed = random.uniform(self.actor_min_speed, self.actor_max_speed)
            spawn_progress = random.uniform(
                self.main_aisle_progress_min,
                self.main_aisle_progress_max,
            )
            lateral = self.random_main_lateral_offset()
            spawn = self.offset_main_point(spawn_progress, lateral)

            start_id = self.nearest_graph_node(spawn)
            goal_id = random.choice([node_id for node_id in self.node_dict if node_id != start_id])
            path_ids = shortest_graph_path(self.node_dict, self.edge_list, start_id, goal_id)
            if len(path_ids) < 2:
                continue
            route = [tuple(self.node_dict[node_id]) for node_id in path_ids]
            if not path_is_clear(spawn, route[0], self.boundary, self.inflated_obstacles):
                self.get_logger().debug('[random_actor] rejected path: crosses blocked area')
                continue
            points = [spawn] + [self.random_offset_point(point) for point in route[1:]]
            actor = self.make_actor(actor_id, points, speed, 'main_nearby')
            if self.actor_is_valid(actor, existing_spawns, separation):
                return actor
            if attempt == MAX_SAMPLE_ATTEMPTS // 2:
                separation = min(separation, 0.6)

        self.get_logger().warn(
            f'[random_actor] main aisle nearby sampling relaxed for actor{actor_id}'
        )
        return self.sample_other_actor(actor_id, existing_spawns, relaxed=True)

    def sample_other_actor(self, actor_id, existing_spawns, relaxed=False):
        separation = 0.6 if relaxed else self.min_actor_spawn_separation
        for attempt in range(ACTOR_SAMPLE_ATTEMPTS):
            speed = random.uniform(self.actor_min_speed, self.actor_max_speed)
            start_id, goal_id = random.sample(list(self.node_dict), 2)
            path_ids = shortest_graph_path(self.node_dict, self.edge_list, start_id, goal_id)
            if len(path_ids) < 2:
                continue
            route = [tuple(self.node_dict[node_id]) for node_id in path_ids]
            if polyline_length(route) < self.min_route_length:
                continue
            points = [self.random_offset_point(point) for point in route]
            if not all(point_in_poly(point, self.boundary) for point in points):
                continue
            if any(point_in_poly(point, obs) for point in points for obs in self.inflated_obstacles):
                continue
            if all(path_is_clear(points[i], points[i + 1], self.boundary, self.inflated_obstacles)
                   for i in range(len(points) - 1)):
                actor = self.make_actor(actor_id, points, speed, 'other')
                if self.actor_is_valid(actor, existing_spawns, separation):
                    return actor
            if attempt == MAX_SAMPLE_ATTEMPTS and not relaxed:
                separation = min(separation, 0.6)
        raise RuntimeError(f'Could not sample a collision-free actor path for actor{actor_id}')

    def make_actor(self, actor_id, points, speed, group):
        return {
            'name': f'actor{actor_id}',
            'group': group,
            'speed': speed,
            'waypoints': self.make_timed_waypoints(points, speed),
            'history': deque(maxlen=self.history_length),
        }

    def random_offset_point(self, point):
        angle = random.uniform(-math.pi, math.pi)
        radius = random.uniform(self.lateral_offset_min, self.lateral_offset_max)
        return point[0] + math.cos(angle) * radius, point[1] + math.sin(angle) * radius

    def random_main_lateral_offset(self):
        max_offset = max(0.0, self.main_aisle_width * 0.5)
        min_offset = min(self.lateral_offset_min, max_offset)
        magnitude = random.uniform(min_offset, max_offset)
        return random.choice([-1.0, 1.0]) * magnitude

    @staticmethod
    def unit_vector(start, end):
        dx = end[0] - start[0]
        dy = end[1] - start[1]
        length = math.hypot(dx, dy) or 1e-9
        return dx / length, dy / length

    def point_at_polyline_distance(self, distance):
        remaining = max(0.0, min(distance, self.main_aisle_length))
        points = self.main_aisle_centerline
        for idx in range(len(points) - 1):
            start = points[idx]
            end = points[idx + 1]
            seg_len = math.hypot(end[0] - start[0], end[1] - start[1])
            if remaining <= seg_len:
                ratio = 0.0 if seg_len <= 1e-9 else remaining / seg_len
                return (
                    start[0] + (end[0] - start[0]) * ratio,
                    start[1] + (end[1] - start[1]) * ratio,
                )
            remaining -= seg_len
        return points[-1]

    def offset_main_point(self, progress, lateral):
        base = self.point_at_polyline_distance(progress * self.main_aisle_length)
        dx, dy = self.robot_path_dir
        left_normal = -dy, dx
        return base[0] + left_normal[0] * lateral, base[1] + left_normal[1] * lateral

    def progress_at_main_waypoint(self, waypoint):
        distance = 0.0
        points = self.main_aisle_centerline
        for idx in range(len(points) - 1):
            if points[idx] == waypoint:
                return distance / self.main_aisle_length
            distance += math.hypot(
                points[idx + 1][0] - points[idx][0],
                points[idx + 1][1] - points[idx][1],
            )
        return 1.0

    def nearest_graph_node(self, point):
        return min(
            self.node_dict,
            key=lambda node_id: self.distance(point, self.node_dict[node_id]),
        )

    @staticmethod
    def actor_spawn(actor):
        _, x, y = actor['waypoints'][0]
        return x, y

    def actor_is_valid(self, actor, existing_spawns, separation):
        points = [(x, y) for _, x, y in actor['waypoints']]
        if len(points) < 2:
            return False
        if not all(point_in_poly(point, self.boundary) for point in points):
            return False
        if any(point_in_poly(point, obs) for point in points for obs in self.inflated_obstacles):
            return False
        if not all(path_is_clear(points[i], points[i + 1], self.boundary, self.inflated_obstacles)
                   for i in range(len(points) - 1)):
            return False

        spawn = points[0]
        if not self.spawn_is_valid(spawn, existing_spawns, separation):
            return False
        return not self.enters_start_protection_early(actor)

    def spawn_is_valid(self, spawn, existing_spawns, separation):
        if self.distance(spawn, self.robot_start) < self.start_exclusion_radius:
            self.get_logger().debug('[random_actor] rejected spawn: too close to robot start')
            return False
        if self.inside_robot_front_clear_zone(spawn):
            self.get_logger().debug('[random_actor] rejected spawn: in front clear zone')
            return False
        for other in existing_spawns:
            if self.distance(spawn, other) < separation:
                self.get_logger().debug('[random_actor] rejected spawn: too close to existing actor')
                return False
        return True

    def enters_start_protection_early(self, actor):
        t = 0.0
        while t <= self.spawn_protection_time_sec + 1e-9:
            pos = self.interpolate_actor(actor, t, loop=False)
            if self.distance(pos, self.robot_start) < self.start_exclusion_radius:
                return True
            if self.inside_robot_front_clear_zone(pos):
                return True
            t += PROTECTION_CHECK_DT
        t = 0.0
        while t <= self.robot_path_protection_time_sec + 1e-9:
            pos = self.interpolate_actor(actor, t, loop=False)
            if self.distance_to_protected_robot_path(pos) < self.robot_path_protection_radius:
                return True
            t += PROTECTION_CHECK_DT
        return False

    def distance_to_protected_robot_path(self, point):
        max_distance = max(
            0.0,
            min(self.main_aisle_length, self.main_aisle_length * self.robot_path_protection_progress_max),
        )
        best = float('inf')
        traveled = 0.0
        points = self.main_aisle_centerline
        for idx in range(len(points) - 1):
            start = points[idx]
            end = points[idx + 1]
            seg_len = self.distance(start, end)
            if traveled >= max_distance:
                break
            usable = min(seg_len, max_distance - traveled)
            if usable <= 1e-9:
                break
            ratio = usable / seg_len
            clipped_end = (
                start[0] + (end[0] - start[0]) * ratio,
                start[1] + (end[1] - start[1]) * ratio,
            )
            best = min(best, self.distance_to_segment(point, start, clipped_end))
            traveled += usable
        return best

    @staticmethod
    def distance_to_segment(point, start, end):
        px, py = point
        sx, sy = start
        ex, ey = end
        dx = ex - sx
        dy = ey - sy
        denom = dx * dx + dy * dy
        if denom <= 1e-12:
            return math.hypot(px - sx, py - sy)
        u = max(0.0, min(1.0, ((px - sx) * dx + (py - sy) * dy) / denom))
        closest = sx + u * dx, sy + u * dy
        return math.hypot(px - closest[0], py - closest[1])

    def inside_robot_front_clear_zone(self, point):
        dx = point[0] - self.robot_start[0]
        dy = point[1] - self.robot_start[1]
        fx, fy = self.robot_path_dir
        forward = dx * fx + dy * fy
        lateral = -dx * fy + dy * fx
        return (
            0.0 <= forward <= self.start_front_clear_dist
            and abs(lateral) <= self.start_front_clear_width * 0.5
        )

    @staticmethod
    def distance(a, b):
        return math.hypot(a[0] - b[0], a[1] - b[1])

    def log_generation_summary(self, actor_count, main_count, other_count, spawn_points):
        min_start_dist = min(
            (self.distance(spawn, self.robot_start) for spawn in spawn_points),
            default=float('nan'),
        )
        min_sep = float('nan')
        if len(spawn_points) >= 2:
            min_sep = min(
                self.distance(spawn_points[i], spawn_points[j])
                for i in range(len(spawn_points))
                for j in range(i + 1, len(spawn_points))
            )
        self.get_logger().info(
            f'[random_actor] generated actors: {actor_count}'
        )
        self.get_logger().info(
            f'[random_actor] trial_id={self.trial_id} '
            f'actor_count={actor_count} main_aisle_nearby_actors={main_count} '
            f'other_actors={other_count} '
            f'min_dist_to_robot_start={min_start_dist:.2f}m '
            f'min_actor_spawn_separation={min_sep:.2f}m '
            f'main_aisle_width={self.main_aisle_width:.1f}m '
            f'path_protection={self.robot_path_protection_time_sec:.1f}s/'
            f'{self.robot_path_protection_radius:.2f}m'
        )

    @staticmethod
    def make_timed_waypoints(points, speed):
        waypoints = []
        elapsed = 0.0
        for idx, point in enumerate(points):
            if idx > 0:
                prev = points[idx - 1]
                elapsed += math.hypot(point[0] - prev[0], point[1] - prev[1]) / speed
            waypoints.append((elapsed, point[0], point[1]))
        return waypoints

    def timer_callback(self):
        self.publish_all()

    def publish_all(self):
        now = self.get_clock().now()
        elapsed = (now - self.start_time).nanoseconds / 1e9 if hasattr(self, 'start_time') else 0.0
        traj_msg = HumanTrajectoryArray()
        pose_msg = PoseArray()
        pose_msg.header.frame_id = 'map'
        pose_msg.header.stamp = now.to_msg()
        marker_msg = MarkerArray()

        marker_id = 0
        for idx, actor in enumerate(self.actors):
            x, y = self.interpolate_actor(actor, elapsed)
            actor['history'].append((x, y))

            traj = HumanTrajectory()
            traj.traj_points = [Point(x=float(px), y=float(py), z=0.0)
                                for px, py in actor['history']]
            traj_msg.human_trajectories.append(traj)

            pose = Pose()
            pose.position.x = x
            pose.position.y = y
            pose.orientation.w = 1.0
            pose_msg.poses.append(pose)

            marker_id = self.add_actor_markers(marker_msg, marker_id, idx, actor, x, y, now)

        for stale_id in range(marker_id, getattr(self, 'last_marker_count', 0)):
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.header.stamp = now.to_msg()
            marker.ns = 'rviz_actor_sim'
            marker.id = stale_id
            marker.action = Marker.DELETE
            marker_msg.markers.append(marker)
        self.last_marker_count = marker_id

        self.human_traj_publisher.publish(traj_msg)
        self.pose_publisher.publish(pose_msg)
        self.marker_publisher.publish(marker_msg)

    @staticmethod
    def interpolate_actor(actor, elapsed, loop=True):
        waypoints = actor['waypoints']
        duration = max(waypoints[-1][0], 1e-6)
        t = elapsed % duration if loop else min(max(0.0, elapsed), duration)
        for idx in range(len(waypoints) - 1):
            t0, x0, y0 = waypoints[idx]
            t1, x1, y1 = waypoints[idx + 1]
            if t0 <= t <= t1:
                ratio = 0.0 if t1 <= t0 else (t - t0) / (t1 - t0)
                return x0 + (x1 - x0) * ratio, y0 + (y1 - y0) * ratio
        return waypoints[-1][1], waypoints[-1][2]

    @staticmethod
    def add_actor_markers(marker_msg, marker_id, actor_idx, actor, x, y, now):
        sphere = Marker()
        sphere.header.frame_id = 'map'
        sphere.header.stamp = now.to_msg()
        sphere.ns = 'rviz_actor_sim'
        sphere.id = marker_id
        marker_id += 1
        sphere.type = Marker.SPHERE
        sphere.action = Marker.ADD
        sphere.pose.position.x = x
        sphere.pose.position.y = y
        sphere.pose.position.z = 0.2
        sphere.pose.orientation.w = 1.0
        sphere.scale.x = 0.28
        sphere.scale.y = 0.28
        sphere.scale.z = 0.28
        sphere.color.r = 1.0
        sphere.color.g = 0.12 + 0.05 * (actor_idx % 3)
        sphere.color.b = 0.05
        sphere.color.a = 1.0
        marker_msg.markers.append(sphere)

        line = Marker()
        line.header.frame_id = 'map'
        line.header.stamp = now.to_msg()
        line.ns = 'rviz_actor_sim'
        line.id = marker_id
        marker_id += 1
        line.type = Marker.LINE_STRIP
        line.action = Marker.ADD
        line.scale.x = 0.04
        line.color.r = 1.0
        line.color.g = 0.75
        line.color.b = 0.2
        line.color.a = 0.75
        line.points = [Point(x=float(px), y=float(py), z=0.1) for px, py in actor['history']]
        marker_msg.markers.append(line)
        return marker_id


def main(args=None):
    rclpy.init(args=args)
    node = RvizActorSimulator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
