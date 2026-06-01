# Codex prompt: install random warehouse scenes into original EBM/MPC program

Copy this prompt into Codex while working inside the **other/original local EBM+MPC program**.

---

I have a generated random warehouse pedestrian-scene bundle from another repo.  The bundle folder contains:

```text
manifest.json
human_trajectories.csv
robot_schedule.csv
background.png
README_NEXT_STEPS.md
```

The CSV schema is:

```text
trial_id,seed,actor_id,t,x,y,speed_mps,start_node,goal_node
```

Please integrate this bundle into the original EBM+MPC program without changing the EBM model architecture or MPC solver.

Requirements:

1. Add a small loader module, for example:

```text
src/random_scene_loader.py
```

or a location that fits the project structure.

2. The loader should support:

```python
load_scene_bundle(bundle_dir: str) -> SceneBundle
get_trial(bundle: SceneBundle, trial_id: int) -> TrialScene
```

3. `TrialScene` should expose:

```python
trial_id
seed
actor_count
robot_schedule
background_path
actors
```

where each actor has:

```python
actor_id
trajectory_times
trajectory_xy
speed_mps
start_node
goal_node
```

4. Add an example runner script, for example:

```text
scripts/run_original_ebm_random_scene.py
```

that accepts:

```bash
--bundle-dir /path/to/ebm_random_scene_bundle_1000
--trial-id 0
--ebm-config /path/to/wsd_1t20_poselu_enll_train.yaml
--ebm-model-suffix 0
```

5. The runner should:

- load `background.png` as the EBM `ref_image_path`
- load the chosen trial's actor trajectories
- feed each actor's past trajectory into the existing EBM predictor
- produce predicted future trajectories in the same format the original MPC pipeline expects
- feed the dynamic obstacles into the existing MPC loop
- keep robot schedule from `robot_schedule.csv` or `manifest.json`

6. Do not rewrite the EBM model, network loader, or MPC solver.

7. Do not assume ROS2 messages exist in this original pipeline.  Use normal Python data structures first.

8. Add clear logging:

```text
loaded bundle path
loaded trial_id / seed / actor_count
EBM config path
EBM model suffix
background path
first actor first/last point
```

9. Add a dry-run mode:

```bash
--dry-run
```

Dry-run should load the bundle, print summary, instantiate EBM if possible, and exit before running MPC.

10. Add minimal validation:

- fail if `human_trajectories.csv` is missing
- fail if `background.png` is missing
- fail if requested `trial_id` is not present
- fail if any actor has fewer than 5 trajectory points

The goal is to make the original local EBM+MPC program run deterministic random warehouse pedestrian scenes generated from the bundle.
