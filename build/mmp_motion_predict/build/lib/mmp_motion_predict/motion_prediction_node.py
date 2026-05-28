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

class MotionPredictionNode(Node):
    def __init__(self):
        super().__init__('MotionPredictionNode')
        self.get_logger().info("🚀 [SOTA大腦] 系統啟動中...")

        self.declare_parameter('timer_period', 0.1) # 提速到 10Hz (0.1秒)
        self.timer_period = self.get_parameter('timer_period').value

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
        self.motion_predictor = MotionPredictor()
        self.get_logger().info("✅ [SOTA大腦] 載入完成，等待路人資料...")

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
        K_MODES = 3  # hardcoded std=0.15 in k>1 branch → small constant ellipses
        curr_mu_list = [traj[-1] for traj in self.trajs]

        # 🔥 神級提速：把所有路人一次丟給大腦，不轉換影像、不群集！
        mu_list_list, std_list_list, conf_list_list = self.motion_predictor.predict_all_humans(
            self.trajs, k_modes=K_MODES, obstacle_polys=self.obstacle_polys)

        # t=0: ONE real observation per pedestrian (alpha=1.0) + (K-1) dummies at a far-away
        # position (alpha=0.0).  This keeps hard ALM constraint count at 1 per pedestrian
        # instead of K, preventing 15× penalty amplification that blocks path planning.
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
        self.motion_prediction_viz_publisher.publish(self.motion_prediction_to_vis_msg(mu_list_list, std_list_list, conf_list_list))

    def motion_prediction_to_vis_msg(self, mu_list_list, std_list_list, conf_list_list, name_space="motion_prediction_ns", id_start=0):
        marker_msg = MarkerArray()
        marker_id = id_start
        color_cylinder = (1.0, 0.0, 0.0)
        for mu_list, std_list, conf_list in zip(mu_list_list, std_list_list, conf_list_list):
            for mu, std, conf in zip(mu_list, std_list, conf_list):
                marker_id += 1
                m = Marker()
                m.id = marker_id
                m.type = Marker.CYLINDER
                m.action = Marker.ADD
                m.pose.position.x = float(mu[0])
                m.pose.position.y = float(mu[1])
                m.pose.position.z = 0.0
                m.pose.orientation.w = 1.0
                m.scale.x = std[0]*3.0 + HUMAN_SIZE
                m.scale.y = std[1]*3.0 + HUMAN_SIZE
                m.scale.z = 0.1
                m.color.a = 0.2
                m.color.r = color_cylinder[0]
                m.color.g = color_cylinder[1]
                m.color.b = color_cylinder[2]
                m.header.frame_id = "map"
                m.ns = name_space
                marker_msg.markers.append(m)
        if (marker_id - id_start) < self.last_num_markers:
            for extra_id in range(marker_id+1, id_start+self.last_num_markers+1):
                extra_marker = Marker()
                extra_marker.header.frame_id = "map"
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