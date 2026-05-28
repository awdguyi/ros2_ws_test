# Baseline score standard

This branch uses the following model checkpoint as the baseline score standard:

```text
ST-warehouse-progress/model_best.pth
```

## Purpose

Use this checkpoint as the reference model when comparing later warehouse experiment results, score changes, runtime metrics, and trajectory quality.

## Suggested comparison rule

New experiment results should be compared against this baseline using the same map, launch settings, and evaluation metrics whenever possible.
