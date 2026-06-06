#!/usr/bin/env python3

import argparse
import csv
import os
import signal
import subprocess
import time
from collections import Counter
from pathlib import Path


WORKSPACE_ROOT = Path('/home/michael/ros2_ws_test')
CSV_FIELDS = [
    'batch_id',
    'seed_base',
    'seed_start',
    'seed_end',
    'csv_file',
    'rows',
    'success',
    'failure',
    'success_rate',
    'fail_reasons',
    'elapsed_sec',
    'exit_code',
]


def parse_args():
    parser = argparse.ArgumentParser(
        description='Run RViz random trials in repeated relaunch batches.'
    )
    parser.add_argument('--batches', type=int, default=10)
    parser.add_argument('--trials-per-batch', type=int, default=10)
    parser.add_argument('--trial-timeout-sec', type=float, default=90.0)
    parser.add_argument('--random-seed-base', type=int, default=2000)
    parser.add_argument(
        '--seed-list',
        default='',
        help='Comma-separated explicit seeds. Each seed runs as one relaunch batch.',
    )
    parser.add_argument(
        '--unique-seeds-per-batch',
        action='store_true',
        help='Offset random_seed_base by batch_id * trials_per_batch.',
    )
    parser.add_argument('--output-dir', default='rviz_relaunch_batches')
    parser.add_argument('--summary-csv', default='rviz_relaunch_batches_summary.csv')
    parser.add_argument('--use-rviz', default='true', choices=['true', 'false'])
    parser.add_argument('--random-actor-min', type=int, default=None)
    parser.add_argument('--random-actor-max', type=int, default=None)
    parser.add_argument('--collision-distance', type=float, default=0.15)
    parser.add_argument('--static-obstacle-margin', type=float, default=0.15)
    parser.add_argument('--freeze-ignore-ped-distance', type=float, default=0.5)
    parser.add_argument('--output-speed-cap-deviation-threshold', type=float, default=0.65)
    parser.add_argument('--output-speed-cap-linear-max', type=float, default=1.0)
    parser.add_argument('--startup-wait-sec', type=float, default=5.0)
    parser.add_argument('--between-batch-wait-sec', type=float, default=3.0)
    parser.add_argument(
        '--batch-timeout-extra-sec',
        type=float,
        default=60.0,
        help='Extra wall-clock time beyond trials_per_batch * trial_timeout_sec.',
    )
    return parser.parse_args()


def parse_seed_list(seed_list_text):
    if not seed_list_text.strip():
        return []
    return [
        int(seed.strip())
        for seed in seed_list_text.split(',')
        if seed.strip()
    ]


def seed_base_for_batch(args, batch_id):
    if getattr(args, 'seed_values', None):
        return args.seed_values[batch_id]
    if not args.unique_seeds_per_batch:
        return args.random_seed_base
    return args.random_seed_base + batch_id * args.trials_per_batch


def read_rows(csv_path):
    if not csv_path.exists():
        return []
    with csv_path.open(newline='') as csv_file:
        return [
            row for row in csv.DictReader(csv_file)
            if any((value or '').strip() for value in row.values())
        ]


def summarize_rows(rows):
    success = sum(
        1 for row in rows
        if str(row.get('success', '')).strip() in ('1', 'true', 'True')
    )
    reasons = Counter(row.get('fail_reason', '') or '<blank>' for row in rows)
    return success, len(rows) - success, reasons


def terminate_process_group(process, timeout_sec=10.0):
    if process.poll() is not None:
        return
    try:
        os.killpg(process.pid, signal.SIGINT)
    except ProcessLookupError:
        return
    deadline = time.time() + timeout_sec
    while time.time() < deadline:
        if process.poll() is not None:
            return
        time.sleep(0.2)
    try:
        os.killpg(process.pid, signal.SIGTERM)
    except ProcessLookupError:
        return
    deadline = time.time() + 5.0
    while time.time() < deadline:
        if process.poll() is not None:
            return
        time.sleep(0.2)
    try:
        os.killpg(process.pid, signal.SIGKILL)
    except ProcessLookupError:
        pass


def launch_batch(args, batch_id, csv_path):
    seed_base = seed_base_for_batch(args, batch_id)
    trials = 1 if getattr(args, 'seed_values', None) else args.trials_per_batch
    launch_cmd = [
        'ros2', 'launch', 'zmr_demo', 'rviz_warehouse_100_trials.launch.py',
        f'use_rviz:={args.use_rviz}',
        f'num_trials:={trials}',
        f'trial_timeout_sec:={args.trial_timeout_sec}',
        f'random_seed_base:={seed_base}',
        f'output_csv:={csv_path}',
        f'collision_distance:={args.collision_distance}',
        f'static_obstacle_margin:={args.static_obstacle_margin}',
        f'freeze_ignore_ped_distance:={args.freeze_ignore_ped_distance}',
        f'output_speed_cap_deviation_threshold:={args.output_speed_cap_deviation_threshold}',
        f'output_speed_cap_linear_max:={args.output_speed_cap_linear_max}',
        'log_csv:=false',
        'log_wandb:=false',
    ]
    if args.random_actor_min is not None:
        launch_cmd.append(f'random_actor_min:={args.random_actor_min}')
    if args.random_actor_max is not None:
        launch_cmd.append(f'random_actor_max:={args.random_actor_max}')
    shell_cmd = 'source install/setup.bash && ' + ' '.join(launch_cmd)
    env = os.environ.copy()
    env.setdefault('ROS_LOG_DIR', str(WORKSPACE_ROOT / 'log'))
    return subprocess.Popen(
        ['bash', '-lc', shell_cmd],
        cwd=WORKSPACE_ROOT,
        env=env,
        start_new_session=True,
    )


def write_summary(summary_path, rows):
    summary_path.parent.mkdir(parents=True, exist_ok=True)
    with summary_path.open('w', newline='') as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=CSV_FIELDS)
        writer.writeheader()
        writer.writerows(rows)


def main():
    args = parse_args()
    args.seed_values = parse_seed_list(args.seed_list)
    total_batches = len(args.seed_values) if args.seed_values else args.batches
    trials_per_batch = 1 if args.seed_values else args.trials_per_batch
    output_dir = (WORKSPACE_ROOT / args.output_dir).resolve()
    output_dir.mkdir(parents=True, exist_ok=True)
    summary_path = (WORKSPACE_ROOT / args.summary_csv).resolve()
    summary_rows = []

    for batch_id in range(total_batches):
        csv_path = output_dir / f'rviz_batch_{batch_id:02d}.csv'
        if csv_path.exists():
            csv_path.unlink()

        seed_base = seed_base_for_batch(args, batch_id)
        seed_start = seed_base
        seed_end = seed_base + max(trials_per_batch - 1, 0)
        print(
            f'[batch {batch_id:02d}] launching '
            f'{trials_per_batch} trials seed={seed_start}-{seed_end} -> {csv_path}',
            flush=True,
        )
        start = time.time()
        process = launch_batch(args, batch_id, csv_path)
        deadline = start + trials_per_batch * args.trial_timeout_sec + args.batch_timeout_extra_sec

        while time.time() < deadline:
            rows = read_rows(csv_path)
            if len(rows) >= trials_per_batch:
                break
            if process.poll() is not None and len(rows) >= trials_per_batch:
                break
            if process.poll() is not None and len(rows) < trials_per_batch:
                print(
                    f'[batch {batch_id:02d}] launch exited early with '
                    f'{len(rows)} rows, code={process.returncode}',
                    flush=True,
                )
                break
            time.sleep(1.0)

        rows = read_rows(csv_path)
        terminate_process_group(process)
        elapsed = time.time() - start
        success, failure, reasons = summarize_rows(rows)
        rate = 100.0 * success / len(rows) if rows else 0.0
        summary = {
            'batch_id': batch_id,
            'seed_base': seed_base,
            'seed_start': seed_start,
            'seed_end': seed_end,
            'csv_file': str(csv_path),
            'rows': len(rows),
            'success': success,
            'failure': failure,
            'success_rate': round(rate, 2),
            'fail_reasons': dict(reasons),
            'elapsed_sec': round(elapsed, 2),
            'exit_code': process.returncode,
        }
        summary_rows.append(summary)
        write_summary(summary_path, summary_rows)
        print(
            f"[batch {batch_id:02d}] rows={len(rows)} success={success} "
            f"failure={failure} rate={rate:.1f}% reasons={dict(reasons)}",
            flush=True,
        )
        time.sleep(args.between_batch_wait_sec)

    print(f'[done] summary: {summary_path}', flush=True)
    print(f'[done] per-batch CSVs: {output_dir}', flush=True)


if __name__ == '__main__':
    main()
