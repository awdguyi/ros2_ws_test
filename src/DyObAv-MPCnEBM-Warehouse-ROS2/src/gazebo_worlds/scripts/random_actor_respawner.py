#!/usr/bin/env python3

import json
import math
import os
import random
import time

import rclpy
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from ament_index_python.packages import get_package_share_directory
from gazebo_msgs.srv import DeleteEntity, SpawnEntity
from std_srvs.srv import Trigger


ACTOR_MIN_COUNT = 10
ACTOR_MAX_COUNT = 15
ACTOR_DELETE_MAX_COUNT = 20
ACTOR_HOLD_UNTIL = 120.0
ACTOR_MIN_SPEED = 0.24
ACTOR_MAX_SPEED = 0.588
ACTOR_CLEARANCE = 0.65
ACTOR_SAMPLE_ATTEMPTS = 2000
MIN_MAIN_AISLE_LENGTH = 1.0
ACTOR_LATERAL_OFFSET_MIN = 0.15
ACTOR_LATERAL_OFFSET_MAX = 0.55
MIN_RANDOM_ROUTE_LENGTH = 8.0


def _point_in_poly(point: tuple[float, float], poly: list[list[float]]) -> bool:
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


def _ccw(a: tuple[float, float], b: tuple[float, float], c: tuple[float, float]) -> bool:
    return (c[1] - a[1]) * (b[0] - a[0]) > (b[1] - a[1]) * (c[0] - a[0])


def _segments_intersect(
    a: tuple[float, float],
    b: tuple[float, float],
    c: tuple[float, float],
    d: tuple[float, float],
) -> bool:
    return _ccw(a, c, d) != _ccw(b, c, d) and _ccw(a, b, c) != _ccw(a, b, d)


def _expanded_bbox_poly(poly: list[list[float]], margin: float) -> list[list[float]]:
    xs = [p[0] for p in poly]
    ys = [p[1] for p in poly]
    x_min, x_max = min(xs) - margin, max(xs) + margin
    y_min, y_max = min(ys) - margin, max(ys) + margin
    return [[x_min, y_min], [x_min, y_max], [x_max, y_max], [x_max, y_min]]


def _segment_hits_poly(
    start: tuple[float, float],
    end: tuple[float, float],
    poly: list[list[float]],
) -> bool:
    if _point_in_poly(start, poly) or _point_in_poly(end, poly):
        return True
    for idx, vertex in enumerate(poly):
        next_vertex = poly[(idx + 1) % len(poly)]
        if _segments_intersect(start, end, tuple(vertex), tuple(next_vertex)):
            return True
    return False


def _load_walkable_area(map_share: str, map_file_name: str):
    map_path = os.path.join(map_share, 'data', map_file_name)
    with open(map_path, 'r', encoding='utf-8') as map_file:
        data = json.load(map_file)

    boundary = data['boundary_coords']
    obstacles = data.get('obstacle_list')
    if obstacles is None:
        obstacles = [obs['vertices'] for obs in data.get('obstacle_dict', [])]

    xs = [p[0] for p in boundary]
    ys = [p[1] for p in boundary]
    bounds = (
        min(xs) + ACTOR_CLEARANCE,
        max(xs) - ACTOR_CLEARANCE,
        min(ys) + ACTOR_CLEARANCE,
        max(ys) - ACTOR_CLEARANCE,
    )
    inflated_obstacles = [_expanded_bbox_poly(obs, ACTOR_CLEARANCE) for obs in obstacles]
    return boundary, inflated_obstacles, bounds


def _shortest_graph_path(node_dict: dict, edge_list: list[list[str]], start_id: str, goal_id: str) -> list[str]:
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


def _load_walkable_graph(graph_share: str, graph_file_name: str, walkable_area):
    graph_path = os.path.join(graph_share, 'data', graph_file_name)
    with open(graph_path, 'r', encoding='utf-8') as graph_file:
        data = json.load(graph_file)

    boundary, inflated_obstacles, _ = walkable_area
    node_dict = {
        str(node_id): [float(coord[0]), float(coord[1])]
        for node_id, coord in data['node_dict'].items()
    }
    walkable_edges = []
    for source_id, target_id in data['edge_list']:
        start = tuple(float(v) for v in node_dict[str(source_id)])
        end = tuple(float(v) for v in node_dict[str(target_id)])
        length = math.hypot(end[0] - start[0], end[1] - start[1])
        if length < MIN_MAIN_AISLE_LENGTH:
            continue
        if not _path_is_clear(start, end, boundary, inflated_obstacles):
            continue
        walkable_edges.append([str(source_id), str(target_id)])

    if not walkable_edges:
        raise RuntimeError(f'No collision-free graph edges found in {graph_path}.')
    return node_dict, walkable_edges


def _point_is_clear(
    point: tuple[float, float],
    boundary: list[list[float]],
    inflated_obstacles: list[list[list[float]]],
) -> bool:
    return (
        _point_in_poly(point, boundary)
        and all(not _point_in_poly(point, obs) for obs in inflated_obstacles)
    )


def _path_is_clear(
    start: tuple[float, float],
    end: tuple[float, float],
    boundary: list[list[float]],
    inflated_obstacles: list[list[list[float]]],
) -> bool:
    if not _point_is_clear(start, boundary, inflated_obstacles):
        return False
    if not _point_is_clear(end, boundary, inflated_obstacles):
        return False
    return all(not _segment_hits_poly(start, end, obs) for obs in inflated_obstacles)


def _polyline_length(points: list[tuple[float, float]]) -> float:
    return sum(
        math.hypot(points[idx + 1][0] - points[idx][0], points[idx + 1][1] - points[idx][1])
        for idx in range(len(points) - 1)
    )


def _random_offset_point(point: tuple[float, float]) -> tuple[float, float]:
    angle = random.uniform(-math.pi, math.pi)
    radius = random.uniform(ACTOR_LATERAL_OFFSET_MIN, ACTOR_LATERAL_OFFSET_MAX)
    return (
        point[0] + math.cos(angle) * radius,
        point[1] + math.sin(angle) * radius,
    )


def _all_segments_clear(
    points: list[tuple[float, float]],
    boundary: list[list[float]],
    inflated_obstacles: list[list[list[float]]],
) -> bool:
    return all(
        _path_is_clear(points[idx], points[idx + 1], boundary, inflated_obstacles)
        for idx in range(len(points) - 1)
    )


def _sample_actor_path(walkable_area, walkable_graph):
    boundary, inflated_obstacles, _ = walkable_area
    node_dict, edge_list = walkable_graph
    node_ids = list(node_dict)

    for _ in range(ACTOR_SAMPLE_ATTEMPTS):
        speed = random.uniform(ACTOR_MIN_SPEED, ACTOR_MAX_SPEED)
        start_id, goal_id = random.sample(node_ids, 2)
        path_ids = _shortest_graph_path(node_dict, edge_list, start_id, goal_id)
        if len(path_ids) < 2:
            continue

        route_points = [tuple(node_dict[node_id]) for node_id in path_ids]
        if _polyline_length(route_points) < MIN_RANDOM_ROUTE_LENGTH:
            continue

        actor_points = [_random_offset_point(point) for point in route_points]
        if not all(_point_is_clear(point, boundary, inflated_obstacles) for point in actor_points):
            continue
        if not _all_segments_clear(actor_points, boundary, inflated_obstacles):
            continue

        return actor_points, speed

    raise RuntimeError('Could not sample a collision-free random actor path.')


def _waypoint_xml(points: list[tuple[float, float]], speed: float) -> str:
    waypoints = []
    current_time = 0.0
    for idx, point in enumerate(points):
        if idx < len(points) - 1:
            next_point = points[idx + 1]
            yaw = math.atan2(next_point[1] - point[1], next_point[0] - point[0])
        else:
            prev_point = points[idx - 1]
            yaw = math.atan2(point[1] - prev_point[1], point[0] - prev_point[0])

        if idx > 0:
            prev_point = points[idx - 1]
            segment_length = math.hypot(point[0] - prev_point[0], point[1] - prev_point[1])
            current_time += segment_length / speed

        waypoints.append(f'''
          <waypoint>
            <time>{current_time:.2f}</time>
            <pose>{point[0]:.3f} {point[1]:.3f} 0.0 0 0 {yaw:.3f}</pose>
          </waypoint>''')

    last_point = points[-1]
    if len(points) >= 2:
        prev_point = points[-2]
        last_yaw = math.atan2(last_point[1] - prev_point[1], last_point[0] - prev_point[0])
    else:
        last_yaw = 0.0
    hold_time = max(ACTOR_HOLD_UNTIL, current_time + 1.0)
    waypoints.append(f'''
          <waypoint>
            <time>{hold_time:.2f}</time>
            <pose>{last_point[0]:.3f} {last_point[1]:.3f} 0.0 0 0 {last_yaw:.3f}</pose>
          </waypoint>''')
    return ''.join(waypoints)


class RandomActorRespawner(Node):
    def __init__(self):
        super().__init__('random_actor_respawner')

        self.declare_parameter('map_file_name', 'warehouse_map_real.json')
        self.declare_parameter('graph_file_name', 'warehouse_graph.json')
        self.declare_parameter('actor_min_count', ACTOR_MIN_COUNT)
        self.declare_parameter('actor_max_count', ACTOR_MAX_COUNT)
        self.declare_parameter('actor_delete_max_count', ACTOR_DELETE_MAX_COUNT)

        self.actor_min_count = int(self.get_parameter('actor_min_count').value)
        self.actor_max_count = int(self.get_parameter('actor_max_count').value)
        self.actor_delete_max_count = int(self.get_parameter('actor_delete_max_count').value)
        if self.actor_min_count > self.actor_max_count:
            raise ValueError('actor_min_count must be <= actor_max_count')
        if self.actor_delete_max_count < self.actor_max_count:
            raise ValueError('actor_delete_max_count must be >= actor_max_count')
        map_file_name = str(self.get_parameter('map_file_name').value)
        graph_file_name = str(self.get_parameter('graph_file_name').value)

        map_share = get_package_share_directory('map_description')
        graph_share = get_package_share_directory('mps_motion_plan')
        self.walkable_area = _load_walkable_area(map_share, map_file_name)
        self.walkable_graph = _load_walkable_graph(
            graph_share,
            graph_file_name,
            self.walkable_area,
        )

        self.callback_group = ReentrantCallbackGroup()
        self.delete_client = self.create_client(
            DeleteEntity,
            '/delete_entity',
            callback_group=self.callback_group,
        )
        self.spawn_client = self.create_client(
            SpawnEntity,
            '/spawn_actor_entity',
            callback_group=self.callback_group,
        )
        self.service = self.create_service(
            Trigger,
            '/rerandomize_actors',
            self.rerandomize_callback,
            callback_group=self.callback_group,
        )
        self._busy = False
        self.get_logger().info(
            f'Ready to rerandomize {self.actor_min_count}-{self.actor_max_count} '
            f'actor start-goal paths')

    @staticmethod
    def _wait_future(future, timeout_sec=5.0):
        deadline = time.time() + timeout_sec
        while rclpy.ok() and not future.done() and time.time() < deadline:
            time.sleep(0.02)
        return future.done()

    def _actor_xml_with_summary(self, actor_idx: int):
        actor_points, speed = _sample_actor_path(
            self.walkable_area,
            self.walkable_graph,
        )
        waypoints = _waypoint_xml(actor_points, speed)
        actor_xml = f'''
    <actor name="actor{actor_idx}">
      <skin>
        <filename>walk.dae</filename>
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
        <trajectory id="0" type="walking">
{waypoints}
        </trajectory>
      </script>
    </actor>
'''
        return actor_xml, actor_points[0], actor_points[-1], speed

    def rerandomize_callback(self, _request, response):
        if self._busy:
            response.success = False
            response.message = 'actor rerandomization already running'
            return response

        self._busy = True
        try:
            if not self.delete_client.wait_for_service(timeout_sec=2.0):
                raise RuntimeError('/delete_entity service not available')
            if not self.spawn_client.wait_for_service(timeout_sec=2.0):
                raise RuntimeError('/spawn_actor_entity service not available')

            random_seed = time.time_ns() ^ (os.getpid() << 16)
            random.seed(random_seed)
            actor_count = random.randint(self.actor_min_count, self.actor_max_count)
            self.get_logger().info(
                f'Rerandomizing {actor_count} actors with seed={random_seed}')

            for actor_idx in range(1, self.actor_delete_max_count + 1):
                req = DeleteEntity.Request()
                req.name = f'actor{actor_idx}'
                future = self.delete_client.call_async(req)
                self._wait_future(future, timeout_sec=2.0)

            summaries = []
            for actor_idx in range(1, actor_count + 1):
                actor_xml, start, goal, speed = self._actor_xml_with_summary(actor_idx)
                req = SpawnEntity.Request()
                req.name = f'actor{actor_idx}'
                req.xml = '<sdf version="1.6">' + actor_xml + '</sdf>'
                req.robot_namespace = ''
                req.reference_frame = 'world'
                future = self.spawn_client.call_async(req)
                if not self._wait_future(future, timeout_sec=5.0):
                    raise RuntimeError(f'timeout spawning actor{actor_idx}')
                result = future.result()
                if result is not None and not result.success:
                    raise RuntimeError(
                        f'failed spawning actor{actor_idx}: {result.status_message}')
                summaries.append(
                    f'actor{actor_idx}: '
                    f'({start[0]:.2f},{start[1]:.2f})->'
                    f'({goal[0]:.2f},{goal[1]:.2f}) v={speed:.2f}')

            response.success = True
            response.message = (
                f'regenerated {actor_count} random actor start-goal paths '
                f'with seed={random_seed}')
            self.get_logger().info(response.message)
            self.get_logger().info(' | '.join(summaries))
        except Exception as exc:
            response.success = False
            response.message = str(exc)
            self.get_logger().warn(f'Rerandomize failed: {exc}')
        finally:
            self._busy = False
        return response


def main(args=None):
    rclpy.init(args=args)
    node = RandomActorRespawner()
    executor = MultiThreadedExecutor(num_threads=2)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.remove_node(node)
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
