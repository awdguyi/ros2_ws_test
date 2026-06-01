#!/usr/bin/env python3
"""Package random warehouse human scenes for the original EBM/MPC pipeline.

This script does not run ROS2.  It generates deterministic random pedestrian
trajectories from the warehouse map/graph and writes a portable scene bundle
that the original DyObAv_MPCnEBM_Warehouse code can consume/adapt.

Output layout:
  <output_dir>/
    manifest.json
    human_trajectories.csv
    robot_schedule.csv
    background.png
    README_NEXT_STEPS.md

The generated trajectories use the same high-level assumptions as the ROS2
random actor trials: warehouse graph routes, random seed base, actor count range,
and biased main-aisle actors.
"""

from __future__ import annotations

import argparse
import csv
import json
import math
import random
import shutil
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


@dataclass
class ActorTrajectory:
    trial_id: int
    seed: int
    actor_id: int
    start_node: str
    goal_node: str
    speed_mps: float
    points: list[tuple[float, float]]


def _read_json(path: Path) -> dict:
    with path.open("r", encoding="utf-8") as f:
        return json.load(f)


def _normalize_map(data: dict) -> tuple[list[tuple[float, float]], list[list[tuple[float, float]]]]:
    boundary_raw = data.get("boundary_coords") or data.get("boundary")
    if boundary_raw is None:
        raise ValueError("Map JSON must contain boundary_coords or boundary")
    boundary = [(float(x), float(y)) for x, y in boundary_raw]

    obstacles_raw = data.get("obstacle_list")
    if obstacles_raw is None:
        obstacles_raw = [obj.get("vertices", []) for obj in data.get("obstacle_dict", [])]
    obstacles: list[list[tuple[float, float]]] = []
    for obs in obstacles_raw:
        if len(obs) >= 3:
            obstacles.append([(float(x), float(y)) for x, y in obs])
    return boundary, obstacles


def _normalize_graph(data: dict) -> tuple[dict[str, tuple[float, float]], list[tuple[str, str]]]:
    node_dict = {
        str(k): (float(v[0]), float(v[1]))
        for k, v in data["node_dict"].items()
    }
    edges = [(str(a), str(b)) for a, b in data["edge_list"]]
    return node_dict, edges


def _point_in_poly(point: tuple[float, float], poly: list[tuple[float, float]]) -> bool:
    x, y = point
    inside = False
    j = len(poly) - 1
    for i in range(len(poly)):
        xi, yi = poly[i]
        xj, yj = poly[j]
        if (yi > y) != (yj > y):
            x_at_y = (xj - xi) * (y - yi) / ((yj - yi) or 1e-9) + xi
            inside = inside != (x < x_at_y)
        j = i
    return inside


def _dist_point_to_segment(p: tuple[float, float], a: tuple[float, float], b: tuple[float, float]) -> float:
    px, py = p
    ax, ay = a
    bx, by = b
    dx, dy = bx - ax, by - ay
    den = dx * dx + dy * dy
    if den < 1e-12:
        return math.hypot(px - ax, py - ay)
    t = max(0.0, min(1.0, ((px - ax) * dx + (py - ay) * dy) / den))
    return math.hypot(px - (ax + t * dx), py - (ay + t * dy))


def _ccw(a, b, c) -> bool:
    return (c[1] - a[1]) * (b[0] - a[0]) > (b[1] - a[1]) * (c[0] - a[0])


def _segments_intersect(a, b, c, d) -> bool:
    return _ccw(a, c, d) != _ccw(b, c, d) and _ccw(a, b, c) != _ccw(a, b, d)


def _segment_hits_poly(a: tuple[float, float], b: tuple[float, float], poly: list[tuple[float, float]]) -> bool:
    if _point_in_poly(a, poly) or _point_in_poly(b, poly):
        return True
    for i in range(len(poly)):
        if _segments_intersect(a, b, poly[i], poly[(i + 1) % len(poly)]):
            return True
    return False


def _path_is_clear(points: list[tuple[float, float]], boundary, obstacles, margin: float) -> bool:
    for p in points:
        if not _point_in_poly(p, boundary):
            return False
        for obs in obstacles:
            if _point_in_poly(p, obs):
                return False
            if min(_dist_point_to_segment(p, obs[i], obs[(i + 1) % len(obs)]) for i in range(len(obs))) < margin:
                return False
    for a, b in zip(points[:-1], points[1:]):
        for obs in obstacles:
            if _segment_hits_poly(a, b, obs):
                return False
    return True


def _adjacency(nodes: dict[str, tuple[float, float]], edges: list[tuple[str, str]]) -> dict[str, list[tuple[str, float]]]:
    adj = {k: [] for k in nodes}
    for a, b in edges:
        if a not in nodes or b not in nodes:
            continue
        ax, ay = nodes[a]
        bx, by = nodes[b]
        w = math.hypot(bx - ax, by - ay)
        adj[a].append((b, w))
        adj[b].append((a, w))
    return adj


def _dijkstra(nodes: dict[str, tuple[float, float]], edges: list[tuple[str, str]], start: str, goal: str) -> list[str]:
    adj = _adjacency(nodes, edges)
    unvisited = set(nodes)
    dist = {k: float("inf") for k in nodes}
    prev: dict[str, str] = {}
    dist[start] = 0.0
    while unvisited:
        cur = min(unvisited, key=lambda k: dist[k])
        unvisited.remove(cur)
        if cur == goal or not math.isfinite(dist[cur]):
            break
        for nxt, w in adj[cur]:
            if nxt not in unvisited:
                continue
            alt = dist[cur] + w
            if alt < dist[nxt]:
                dist[nxt] = alt
                prev[nxt] = cur
    if goal != start and goal not in prev:
        return []
    path = [goal]
    while path[-1] != start:
        path.append(prev[path[-1]])
    path.reverse()
    return path


def _polyline_length(points: Iterable[tuple[float, float]]) -> float:
    pts = list(points)
    return sum(math.hypot(b[0] - a[0], b[1] - a[1]) for a, b in zip(pts[:-1], pts[1:]))


def _offset_point(rng: random.Random, p: tuple[float, float], max_offset: float) -> tuple[float, float]:
    theta = rng.uniform(-math.pi, math.pi)
    r = rng.uniform(0.0, max_offset)
    return p[0] + math.cos(theta) * r, p[1] + math.sin(theta) * r


def _resample_polyline(points: list[tuple[float, float]], speed: float, dt: float, hold_until: float) -> list[tuple[float, float, float]]:
    """Return rows as (t, x, y)."""
    if len(points) < 2:
        return [(0.0, points[0][0], points[0][1])]
    seg_lens = [math.hypot(b[0] - a[0], b[1] - a[1]) for a, b in zip(points[:-1], points[1:])]
    total = sum(seg_lens)
    duration = total / max(speed, 1e-6)
    rows: list[tuple[float, float, float]] = []
    t = 0.0
    while t <= hold_until + 1e-9:
        d = min(t * speed, total)
        acc = 0.0
        x, y = points[-1]
        for idx, seg_len in enumerate(seg_lens):
            if acc + seg_len >= d:
                ratio = 0.0 if seg_len < 1e-9 else (d - acc) / seg_len
                a, b = points[idx], points[idx + 1]
                x = a[0] + (b[0] - a[0]) * ratio
                y = a[1] + (b[1] - a[1]) * ratio
                break
            acc += seg_len
        rows.append((round(t, 3), x, y))
        t += dt
    return rows


def _sample_actor(rng: random.Random, trial_id: int, seed: int, actor_id: int, nodes, edges, boundary, obstacles, args) -> ActorTrajectory:
    node_ids = list(nodes)
    for _ in range(args.sample_attempts):
        start, goal = rng.sample(node_ids, 2)
        path_ids = _dijkstra(nodes, edges, start, goal)
        if len(path_ids) < 2:
            continue
        base_points = [nodes[i] for i in path_ids]
        if _polyline_length(base_points) < args.min_route_length:
            continue
        points = [_offset_point(rng, p, args.actor_offset_max) for p in base_points]
        if not _path_is_clear(points, boundary, obstacles, args.obstacle_margin):
            continue
        speed = rng.uniform(args.actor_min_speed, args.actor_max_speed)
        return ActorTrajectory(trial_id, seed, actor_id, start, goal, speed, points)
    raise RuntimeError(f"trial={trial_id} actor={actor_id}: failed to sample clear actor path")


def package_scenes(args) -> None:
    workspace = Path(args.workspace).expanduser().resolve()
    legacy_root = Path(args.legacy_root).expanduser().resolve() if args.legacy_root else workspace / "DyObAv_MPCnEBM_Warehouse"
    ros2_root = Path(args.ros2_root).expanduser().resolve() if args.ros2_root else workspace / "src" / "DyObAv-MPCnEBM-Warehouse-ROS2" / "src"

    map_path = Path(args.map_json).expanduser()
    if not map_path.is_absolute():
        map_path = ros2_root / "map_description" / "data" / args.map_json
    graph_path = Path(args.graph_json).expanduser()
    if not graph_path.is_absolute():
        graph_path = ros2_root / "mps_motion_plan" / "data" / args.graph_json
    background_path = Path(args.background).expanduser()
    if not background_path.is_absolute():
        background_path = legacy_root / args.background

    boundary, obstacles = _normalize_map(_read_json(map_path))
    nodes, edges = _normalize_graph(_read_json(graph_path))

    out_dir = Path(args.output_dir).expanduser().resolve()
    out_dir.mkdir(parents=True, exist_ok=True)
    traj_csv = out_dir / "human_trajectories.csv"
    robot_csv = out_dir / "robot_schedule.csv"
    manifest_path = out_dir / "manifest.json"

    if background_path.exists():
        shutil.copy2(background_path, out_dir / "background.png")

    manifest = {
        "description": "Random warehouse human scenes packaged for original EBM/MPC pipeline",
        "num_trials": args.num_trials,
        "random_seed_base": args.random_seed_base,
        "map_json": str(map_path),
        "graph_json": str(graph_path),
        "background": str(background_path),
        "dt": args.dt,
        "hold_until": args.hold_until,
        "robot_start": [1.0, -2.2, 0.0],
        "robot_schedule": [[1.0, -2.2], [1.0, 0.5], [1.0, 4.0], [1.0, 6.8], [1.0, 12.3]],
        "trials": [],
    }

    with traj_csv.open("w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["trial_id", "seed", "actor_id", "t", "x", "y", "speed_mps", "start_node", "goal_node"])
        for trial_id in range(args.num_trials):
            seed = args.random_seed_base + trial_id
            rng = random.Random(seed)
            actor_count = rng.randint(args.actor_min_count, args.actor_max_count)
            actors = []
            for actor_id in range(actor_count):
                actor = _sample_actor(rng, trial_id, seed, actor_id, nodes, edges, boundary, obstacles, args)
                actors.append(actor)
                for t, x, y in _resample_polyline(actor.points, actor.speed_mps, args.dt, args.hold_until):
                    writer.writerow([trial_id, seed, actor_id, t, round(x, 4), round(y, 4), round(actor.speed_mps, 4), actor.start_node, actor.goal_node])
            manifest["trials"].append({
                "trial_id": trial_id,
                "seed": seed,
                "actor_count": actor_count,
                "actors": [
                    {
                        "actor_id": a.actor_id,
                        "start_node": a.start_node,
                        "goal_node": a.goal_node,
                        "speed_mps": a.speed_mps,
                        "waypoints": a.points,
                    }
                    for a in actors
                ],
            })

    with robot_csv.open("w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["robot_id", "node_id", "x", "y"])
        for idx, (x, y) in enumerate(manifest["robot_schedule"]):
            writer.writerow([0, idx, x, y])

    manifest_path.write_text(json.dumps(manifest, ensure_ascii=False, indent=2), encoding="utf-8")
    (out_dir / "README_NEXT_STEPS.md").write_text(
        "# Original EBM/MPC random warehouse scene bundle\n\n"
        "Generated files:\n"
        "- `manifest.json`: trial metadata and actor waypoints\n"
        "- `human_trajectories.csv`: dense actor trajectories by trial/time\n"
        "- `robot_schedule.csv`: fixed robot path used by the warehouse trials\n"
        "- `background.png`: EBM reference image, if found\n\n"
        "Next step: connect `human_trajectories.csv` to the original `DyObAv_MPCnEBM_Warehouse` "
        "EBM/MPC simulation loop as dynamic obstacle trajectories.\n",
        encoding="utf-8",
    )
    print(f"Wrote scene bundle: {out_dir}")
    print(f"  {traj_csv}")
    print(f"  {robot_csv}")
    print(f"  {manifest_path}")


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("--workspace", default="/home/michael/ros2_ws_test")
    p.add_argument("--legacy-root", default="")
    p.add_argument("--ros2-root", default="")
    p.add_argument("--map-json", default="warehouse_map_real.json")
    p.add_argument("--graph-json", default="warehouse_graph.json")
    p.add_argument("--background", default="data/warehouse_sim_original/background.png")
    p.add_argument("--output-dir", default="/home/michael/ros2_ws_test/ebm_random_scene_bundle")
    p.add_argument("--num-trials", type=int, default=3)
    p.add_argument("--random-seed-base", type=int, default=2000)
    p.add_argument("--actor-min-count", type=int, default=7)
    p.add_argument("--actor-max-count", type=int, default=15)
    p.add_argument("--actor-min-speed", type=float, default=0.24)
    p.add_argument("--actor-max-speed", type=float, default=0.588)
    p.add_argument("--actor-offset-max", type=float, default=0.55)
    p.add_argument("--obstacle-margin", type=float, default=0.25)
    p.add_argument("--sample-attempts", type=int, default=2000)
    p.add_argument("--min-route-length", type=float, default=8.0)
    p.add_argument("--dt", type=float, default=0.4)
    p.add_argument("--hold-until", type=float, default=90.0)
    return p.parse_args()


if __name__ == "__main__":
    package_scenes(parse_args())
