import os
import time
from collections import deque

import rclpy
from rclpy.node import Node

from ament_index_python.packages import get_package_share_directory # type: ignore

from geometry_msgs.msg import Point, PoseStamped

from mmp_interfaces.msg import HumanTrajectory, HumanTrajectoryArray # type: ignore


HUMAN_SIZE = 0.2 # meter


class ActorTrajNode(Node):
    def __init__(self):
        super().__init__(self.__class__.__name__)
        self.get_logger().info(f"{self.__class__.__name__} init..")

        time.sleep(5) # wait for other nodes to start

        pkg_root_dir = get_package_share_directory('mmp_motion_predict')

        self.declare_parameter('timer_period', 0.2)
        self.timer_period = self.get_parameter('timer_period').value

        # Timer for publishing human trajectories
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        # Subscriber to actor poses
        self.actor_pose_received = False

        self.actor_trajs = [deque(maxlen=30) for _ in range(5)]
        self.actor_pose_subscriptions = []
        for idx in range(5):
            actor_pose_name = f'actor{idx + 1}_pose'
            self.actor_pose_subscriptions.append(
                self.create_subscription(
                    PoseStamped,
                    actor_pose_name,
                    lambda msg, actor_idx=idx: self.actor_pose_callback(msg, actor_idx),
                    10
                )
            )

        # Publisher for human trajectory
        human_trajs_name = 'human_traj_array'
        self.human_trajs_publisher = self.create_publisher(
            HumanTrajectoryArray,
            human_trajs_name,
            10
        )

    def timer_callback(self):
        if not self.actor_pose_received:
            self.get_logger().debug("Waiting for actor pose message...")
            return
        
        self.assemble_trajs_msg()
        self.human_trajs_publisher.publish(self.human_trajs_msg)
        
    def actor_pose_callback(self, msg: PoseStamped, actor_idx: int):
        actor_pose = [float(msg.pose.position.x), float(msg.pose.position.y)]
        self.actor_trajs[actor_idx].append(actor_pose)
        self.actor_pose_received = True

    def assemble_trajs_msg(self):
        self.human_trajs_msg = HumanTrajectoryArray()

        for actor_traj in self.actor_trajs:
            if actor_traj:
                actor_traj_msg = HumanTrajectory()
                actor_traj_msg.traj_points = [
                    Point(x=float(x[0]), y=float(x[1]), z=0.0)
                    for x in actor_traj
                ]
                self.human_trajs_msg.human_trajectories.append(actor_traj_msg)

        

def main(args=None):
    rclpy.init(args=args)

    node = ActorTrajNode()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
