# EBM random warehouse scene package

This branch is for creating a local data package that can be downloaded and given to a separate/original EBM+MPC program.

It does **not** require changing `main` and does **not** rely on the ROS2 EBM adapter branch.

## What this package provides

The generator script:

```text
scripts/package_ebm_random_warehouse_scene.py
```

reads the warehouse map/graph and produces deterministic random pedestrian scenes:

```text
<output_dir>/
  manifest.json
  human_trajectories.csv
  robot_schedule.csv
  background.png
  README_NEXT_STEPS.md
```

The important generated files are:

- `human_trajectories.csv`: actor trajectories indexed by `trial_id`, `seed`, `actor_id`, and time `t`.
- `manifest.json`: complete trial metadata, actor waypoint routes, speeds, seeds, and robot schedule.
- `robot_schedule.csv`: fixed robot route used in the warehouse random trials.
- `background.png`: EBM reference image copied from `DyObAv_MPCnEBM_Warehouse/data/warehouse_sim_original/background.png`.

## Recommended local workflow

From your existing `~/ros2_ws_test` repository:

```bash
cd ~/ros2_ws_test

git fetch origin
git checkout exp/ebm-original-random-map
git pull origin exp/ebm-original-random-map
```

Generate a small test bundle first:

```bash
python3 scripts/package_ebm_random_warehouse_scene.py \
  --num-trials 3 \
  --random-seed-base 2000 \
  --output-dir /home/michael/ros2_ws_test/ebm_random_scene_bundle_test
```

Check the result:

```bash
ls -lh /home/michael/ros2_ws_test/ebm_random_scene_bundle_test
head -20 /home/michael/ros2_ws_test/ebm_random_scene_bundle_test/human_trajectories.csv
```

Generate the full 1000-trial bundle:

```bash
python3 scripts/package_ebm_random_warehouse_scene.py \
  --num-trials 1000 \
  --random-seed-base 2000 \
  --output-dir /home/michael/ros2_ws_test/ebm_random_scene_bundle_1000
```

## How to give it to the original/local EBM+MPC program

Copy this generated folder:

```text
/home/michael/ros2_ws_test/ebm_random_scene_bundle_1000
```

into the other original EBM+MPC program, then use:

```text
human_trajectories.csv
manifest.json
background.png
```

as the input scenario dataset.

## CSV schema

`human_trajectories.csv` columns:

```text
trial_id,seed,actor_id,t,x,y,speed_mps,start_node,goal_node
```

- `trial_id`: trial index.
- `seed`: deterministic seed, usually `random_seed_base + trial_id`.
- `actor_id`: pedestrian ID inside the trial.
- `t`: time in seconds.
- `x`, `y`: pedestrian world coordinates in meters.
- `speed_mps`: assigned actor speed.
- `start_node`, `goal_node`: sampled graph route endpoints.

## Integration expectation

The original EBM+MPC program should load one trial at a time:

1. Select rows with the desired `trial_id`.
2. Group by `actor_id`.
3. Feed each actor's `(t, x, y)` trajectory as the dynamic pedestrian trajectory.
4. Use `background.png` as EBM `ref_image_path`.
5. Use the robot path from `robot_schedule.csv` or `manifest.json`.

## Notes

This package is meant to make random scenes reproducible outside ROS2.  It does not itself run EBM or MPC.
