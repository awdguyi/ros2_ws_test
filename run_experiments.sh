#!/bin/bash

WORKSPACE_DIR="/home/michael/ros2_ws_test"
CSV="$WORKSPACE_DIR/experiment_results_robot0.csv"
SCENARIO="ST_MPC_filter"
MAX_TASK_TIME="120.0"

cd $WORKSPACE_DIR
echo "開始執行 20 次自動化實驗..."

source /opt/ros/humble/setup.bash
source install/setup.bash

cleanup_gazebo() {
    if [ -n "$LAUNCH_PID" ]; then
        pkill -9 -P $LAUNCH_PID > /dev/null 2>&1
        kill -9 $LAUNCH_PID > /dev/null 2>&1
    fi
    killall -9 rviz2 > /dev/null 2>&1
    pkill -9 -f gzserver > /dev/null 2>&1
    pkill -9 -f gzclient > /dev/null 2>&1
    while pgrep -f gzserver > /dev/null; do
        sleep 1
    done
}

LAUNCH_PID=""
i=1
while [ $i -le 20 ]; do
    echo ""
    echo ">>> Run $i / 20  ($(date '+%H:%M:%S'))"

    cleanup_gazebo
    sleep 3

    LINES_BEFORE=$(wc -l < "$CSV" 2>/dev/null || echo 1)

    ros2 launch zmr_demo demo_warehouse_single_robot_gazebo_mpc_mmp.launch.py \
        use_sim_time:=true log_csv:=true \
        scenario_id:=$SCENARIO \
        max_task_time:=$MAX_TASK_TIME > /dev/null 2>&1 &
    LAUNCH_PID=$!

    # Gazebo 啟動後 paused:=false 已自動 unpause，以下只是保險
    sleep 25
    timeout 10 ros2 service call /gazebo/unpause_physics std_srvs/srv/Empty '{}' > /dev/null 2>&1 || true
    echo "[Auto] 模擬已啟動，等待結果..."

    ELAPSED=0
    TIMEOUT_LIMIT=600

    while true; do
        sleep 5
        ELAPSED=$((ELAPSED + 5))
        LINES_AFTER=$(wc -l < "$CSV" 2>/dev/null || echo 1)
        if [ "$LINES_AFTER" -gt "$LINES_BEFORE" ]; then
            echo "<<< 完成: $(tail -1 $CSV | awk -F',' '{print "success="$5, "reason="$6, "elapsed="$7}')"
            break
        fi
        if [ "$ELAPSED" -ge "$TIMEOUT_LIMIT" ]; then
            echo "[WARN] Run $i wall-time 超時 (${TIMEOUT_LIMIT}s)"
            break
        fi
    done

    cleanup_gazebo
    i=$((i + 1))
    sleep 3
done

echo ""
echo "=== 20 次實驗完成 ==="
tail -20 "$CSV"
