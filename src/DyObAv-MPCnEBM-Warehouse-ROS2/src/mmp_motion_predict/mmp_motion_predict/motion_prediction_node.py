import os
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from visualization_msgs.msg import Marker, MarkerArray
from mmp_interfaces.msg import HumanTrajectory, HumanTrajectoryArray
from mmp_interfaces.msg import MotionPredictionResult
from map_interfaces.msg import GeometricMap as MapMsg  # type: ignore
from shapely.geometry import Polygon as ShapelyPolygon
from .motion_prediction import MotionPredictor

HUMAN_SIZE = 0.2
ST_PREDICTION_LENGTH_SCALE = 1.0

class MotionPredictionNode(Node):
    def __init__(self):
        super().__init__('MotionPredictionNode')
        self.get_logger().info("🚀 [SOTA大腦] 系統啟動中...")

        self.declare_parameter('timer_period', 0.1) # 提速到 10Hz (0.1秒)
        self.timer_period = self.get_parameter('timer_period').value
        self.declare_parameter('predictor_variant', 'zara2')
        predictor_variant = self.get_parameter('predictor_variant').value

        self.traj_subscription = self.create_subscription(
            HumanTrajectoryArray, 'human_traj_array', self.traj_callback, 10)
        self.map_subscription = self.create_subscription(
            MapMsg, 'geometry_map', self._map_callback, 10)
        self.obstacle_polys = []  # shapely Polygon list, updated on each map message

        self.motion_prediction_publisher = self.create_publisher(
            MotionPredictionResult, 'motion_prediction_result', 10)
        self.motion_prediction_viz_publisher = self.create_publisher(
            MarkerArray, 'motion_prediction_viz', 10)

        self._init_motion_prediction_result_msg()
        self.last_num_markers = 0
        self.traj_received = False
        self.trajs = []

        # 🧠 載入你的 2024 新大腦！(不再需要傳入地圖圖片)
        self.motion_predictor = MotionPredictor(model_suffix=predictor_variant)
        self.get_logger().info(f"✅ [SOTA大腦] 載入完成 (variant={predictor_variant})，等待路人資料...")

        self.timer = self.create_timer(self.timer_period, self.timer_callback)

    def _init_motion_prediction_result_msg(self):
        self.motion_prediction_msg = MotionPredictionResult()
        self.motion_prediction_msg.header.stamp = self.get_clock().now().to_msg()
        self.motion_prediction_msg.header.frame_id = 'map'

    def _map_callback(self, msg: MapMsg):
        polys = []
        for obj in msg.obstacle_list.polygon_objects:
            pts = [(p.x, p.y) for p in obj.polygon.points]
            if len(pts) >= 3:
                polys.append(ShapelyPolygon(pts))
        self.obstacle_polys = polys

    def traj_callback(self, msg: HumanTrajectoryArray):
        self.trajs = [[(coords.x, coords.y) for coords in traj.traj_points] for traj in msg.human_trajectories]
        self.traj_received = True

    def timer_callback(self):
        if not self.traj_received or len(self.trajs) == 0:
            return
        
        N_ped = max(1, len(self.trajs))
        K_MODES = 1
        curr_mu_list = [traj[-1] for traj in self.trajs]

        # 🔥 神級提速：把所有路人一次丟給大腦，不轉換影像、不群集！
        mu_list_list, std_list_list, conf_list_list = self.motion_predictor.predict_all_humans(
            self.trajs, k_modes=K_MODES, obstacle_polys=self.obstacle_polys)

        # t=0: one real observation per pedestrian. K=1 keeps both MPC input and
        # RViz visualization to a single predicted line per pedestrian.
        _DUMMY = (-1000.0, -1000.0)
        curr_mu_expanded, curr_std_expanded, curr_conf_expanded = [], [], []
        for pos in curr_mu_list:
            curr_mu_expanded.append(pos)
            curr_std_expanded.append([HUMAN_SIZE, HUMAN_SIZE])
            curr_conf_expanded.append(1.0)
            for _ in range(K_MODES - 1):
                curr_mu_expanded.append(_DUMMY)
                curr_std_expanded.append([HUMAN_SIZE, HUMAN_SIZE])
                curr_conf_expanded.append(0.0)

        mu_list_list   = [curr_mu_expanded]   + mu_list_list
        std_list_list  = [curr_std_expanded]  + std_list_list
        conf_list_list = [curr_conf_expanded] + conf_list_list

        if ST_PREDICTION_LENGTH_SCALE != 1.0:
            mu_list_list = self._scale_prediction_mu_for_mpc(
                mu_list_list, conf_list_list, K_MODES, ST_PREDICTION_LENGTH_SCALE)

        self.motion_prediction_msg.mu_list_list = []
        for mu_list in mu_list_list:
            msg = HumanTrajectoryArray()
            msg.human_trajectories.append(HumanTrajectory(traj_points=[Point(x=float(pt[0]), y=float(pt[1])) for pt in mu_list]))
            self.motion_prediction_msg.mu_list_list.append(msg)

        self.motion_prediction_msg.std_list_list = []
        for std_list in std_list_list:
            msg = HumanTrajectoryArray()
            msg.human_trajectories.append(HumanTrajectory(traj_points=[Point(x=float(pt[0]), y=float(pt[1])) for pt in std_list]))
            self.motion_prediction_msg.std_list_list.append(msg)

        self.motion_prediction_msg.conf_list_list = []
        for conf_list in conf_list_list:
            msg = HumanTrajectoryArray()
            msg.human_trajectories.append(HumanTrajectory(traj_points=[Point(x=float(pt), y=float(pt)) for pt in conf_list]))
            self.motion_prediction_msg.conf_list_list.append(msg)

        self.motion_prediction_publisher.publish(self.motion_prediction_msg)
        self.motion_prediction_viz_publisher.publish(
            self.motion_prediction_to_vis_msg(mu_list_list, std_list_list, conf_list_list))

    def _scale_prediction_mu_for_mpc(self, mu_list_list, conf_list_list, k_modes: int, scale: float):
        scaled_mu_list_list = [list(mu_list) for mu_list in mu_list_list]
        if not scaled_mu_list_list or not scaled_mu_list_list[0]:
            return scaled_mu_list_list

        n_ped = max(1, len(scaled_mu_list_list[0]) // k_modes)
        for ped_idx in range(n_ped):
            obs_index = ped_idx * k_modes
            if obs_index >= len(scaled_mu_list_list[0]):
                continue

            obs_mu = scaled_mu_list_list[0][obs_index]
            if abs(float(obs_mu[0])) >= 999.0 or abs(float(obs_mu[1])) >= 999.0:
                continue

            ox, oy = float(obs_mu[0]), float(obs_mu[1])
            for t_idx in range(1, len(scaled_mu_list_list)):
                for mode_idx in range(k_modes):
                    flat_idx = ped_idx * k_modes + mode_idx
                    if flat_idx >= len(scaled_mu_list_list[t_idx]):
                        continue
                    if (t_idx < len(conf_list_list)
                            and flat_idx < len(conf_list_list[t_idx])
                            and float(conf_list_list[t_idx][flat_idx]) <= 0.0):
                        continue

                    mu = scaled_mu_list_list[t_idx][flat_idx]
                    if abs(float(mu[0])) >= 999.0 or abs(float(mu[1])) >= 999.0:
                        continue

                    scaled_mu_list_list[t_idx][flat_idx] = (
                        ox + (float(mu[0]) - ox) * scale,
                        oy + (float(mu[1]) - oy) * scale,
                    )

        return scaled_mu_list_list

    def motion_prediction_to_vis_msg(self, mu_list_list, std_list_list, conf_list_list,
                                     name_space="motion_prediction_ns", id_start=0):
        marker_msg = MarkerArray()
        marker_id = id_start
        stamp = self.get_clock().now().to_msg()

        mode_colors = [
            (0.0, 0.4, 1.0),  # single prediction line
        ]
        k_modes = len(mode_colors)

        if not mu_list_list or not mu_list_list[0]:
            return marker_msg

        n_ped = max(1, len(mu_list_list[0]) // k_modes)

        def valid_point(mu, conf=None):
            if mu is None or len(mu) < 2:
                return False
            if conf is not None and float(conf) <= 0.0:
                return False
            return abs(float(mu[0])) < 999.0 and abs(float(mu[1])) < 999.0

        def set_marker_color(marker, color, alpha):
            marker.color.r = color[0]
            marker.color.g = color[1]
            marker.color.b = color[2]
            marker.color.a = max(0.08, min(0.8, float(alpha)))

        def add_observed_marker(ped_idx, obs_mu):
            nonlocal marker_id
            if not valid_point(obs_mu):
                return
            marker_id += 1
            obs = Marker()
            obs.header.frame_id = "map"
            obs.header.stamp = stamp
            obs.ns = name_space
            obs.id = marker_id
            obs.type = Marker.SPHERE
            obs.action = Marker.ADD
            obs.pose.position.x = float(obs_mu[0])
            obs.pose.position.y = float(obs_mu[1])
            obs.pose.position.z = 0.16
            obs.pose.orientation.w = 1.0
            obs.scale.x = HUMAN_SIZE * 2.4
            obs.scale.y = HUMAN_SIZE * 2.4
            obs.scale.z = HUMAN_SIZE * 2.4
            obs.color.r = 1.0
            obs.color.g = 0.0
            obs.color.b = 0.0
            obs.color.a = 1.0
            marker_msg.markers.append(obs)

        for ped_idx in range(n_ped):
            obs_index = ped_idx * k_modes
            if obs_index >= len(mu_list_list[0]):
                continue

            obs_mu = mu_list_list[0][obs_index]
            add_observed_marker(ped_idx, obs_mu)

            for mode_idx, color in enumerate(mode_colors):
                flat_idx = ped_idx * k_modes + mode_idx
                points = []
                conf_values = []

                if valid_point(obs_mu):
                    points.append(Point(x=float(obs_mu[0]), y=float(obs_mu[1]), z=0.18))

                for t_idx in range(1, len(mu_list_list)):
                    if flat_idx >= len(mu_list_list[t_idx]):
                        continue

                    mu = mu_list_list[t_idx][flat_idx]
                    conf = conf_list_list[t_idx][flat_idx] if t_idx < len(conf_list_list) and flat_idx < len(conf_list_list[t_idx]) else 0.0
                    if not valid_point(mu, conf):
                        continue

                    points.append(Point(x=float(mu[0]), y=float(mu[1]), z=0.18))
                    conf_values.append(float(conf))

                if len(points) < 2:
                    continue

                alpha = (sum(conf_values) / len(conf_values)) * 0.8 if conf_values else 0.2

                marker_id += 1
                line = Marker()
                line.header.frame_id = "map"
                line.header.stamp = stamp
                line.ns = name_space
                line.id = marker_id
                line.type = Marker.LINE_STRIP
                line.action = Marker.ADD
                line.pose.orientation.w = 1.0
                line.scale.x = 0.015
                line.points = points
                set_marker_color(line, color, alpha)
                marker_msg.markers.append(line)

        if (marker_id - id_start) < self.last_num_markers:
            for extra_id in range(marker_id + 1, id_start + self.last_num_markers + 1):
                extra_marker = Marker()
                extra_marker.header.frame_id = "map"
                extra_marker.header.stamp = stamp
                extra_marker.ns = name_space
                extra_marker.id = extra_id
                extra_marker.action = Marker.DELETE
                marker_msg.markers.append(extra_marker)
        self.last_num_markers = marker_id - id_start
        return marker_msg

def main(args=None):
    rclpy.init(args=args)
    node = MotionPredictionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
