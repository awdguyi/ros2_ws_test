# ST warehouse baseline score standard

This branch uses the following model checkpoint as the baseline score standard:

```text
ST-warehouse-progress/model_best.pth
```

## Baseline run

```text
C7_5k_gap2_stprog_run0
```

W&B project:

```text
mpc-warehouse-navigation
```

## Training objective of this ST checkpoint

The `C7_5k_gap2_stprog` run uses the ST checkpoint from `ST-warehouse-progress`.

Training objective:

```text
0.5 × GT min-ADE
0.3 × EBL teacher
1.0 × velocity progress loss
```

Meaning:

- `0.5 × GT min-ADE`: keep predictions close to the ground-truth pedestrian trajectory.
- `0.3 × EBL teacher`: inherit the teacher model's multimodal distribution.
- `1.0 × velocity progress loss`: force predicted trajectories to keep moving forward.

Observed effect:

- Compared with `zara2`, this ST checkpoint predicts the pedestrian farther forward earlier.
- This raises `st_center_score`, approximately `~4` versus `~3`.
- The higher score helps the controller trigger right-shift avoidance earlier.

## Current limitation

The ST checkpoint has not yet reached its maximum effect because `early_preview` requires two conditions to be true at the same time:

```python
6.0 < ttc_oncoming < 7.5
and st_center_onc > 0.3
```

From W&B, `c7_early_preview` stays at `0` for the whole run. This means that inside the TTC window of `6–7.5 s`, `st_center_onc` did not exceed `0.3`.

In short:

- `stprog` makes `st_center_score` higher.
- But the score is still not high enough inside the current early TTC window, or the timing does not align with the gate.

## Planning options, no code changes yet

### Option A: Lower the ST gate threshold

```python
_C7_EARLY_ST_TH = 0.15  # from 0.3
```

Pros:

- Simplest change.
- Makes `early_preview` easier to trigger.

Risk:

- The robot may start a light right shift even when the pedestrian prediction is still uncertain.

### Option B: Expand the TTC window and lower the threshold

```python
_C7_TTC_EARLY = 9.0     # from 7.5
_C7_EARLY_ST_TH = 0.2   # from 0.3
```

Pros:

- Gives the controller a longer warning window.

Risk:

- May trigger too early.
- May react to pedestrians that are not truly oncoming.

### Option C: Replace the ST gate with a geometric condition

Instead of depending only on ST score, use direction alignment and distance/closing behavior:

```python
heading_alignment > threshold
and closing_speed > 0
and 6.0 < ttc_oncoming < 9.0
```

Pros:

- More stable.
- Less sensitive to the ST score distribution.

Risk:

- Requires additional geometric calculations.

### Option D: Data diagnosis first

Add W&B logging for the raw ST gate value:

```python
live/st_center_onc_raw
```

Purpose:

- Confirm the actual value of `st_center_onc` during `6.0 < ttc_oncoming < 7.5`.
- Then decide whether to lower the threshold or change the gate logic.

Pros:

- Most conservative.
- Most evidence-based.

Risk:

- Requires one more run to collect data.

## Recommended next step

Use Option D first.

After confirming `st_center_onc_raw`, choose:

- Option A if `st_center_onc_raw` is close to `0.3`, for example around `0.15–0.29`.
- Option B if the score crosses the threshold slightly before or after the current TTC window.
- Option C if `st_center_onc_raw` is unstable or poorly correlated with real oncoming geometry.

## Comparison rule

New experiment results should be compared against this baseline using the same map, world file, launch settings, checkpoint path, and evaluation metrics whenever possible.
