#!/usr/bin/env python3

import math

import rclpy
from geometry_msgs.msg import TransformStamped, Twist
from nav_msgs.msg import Odometry
from rclpy.node import Node
from rcl_interfaces.msg import ParameterDescriptor
from sensor_msgs.msg import JointState
from std_srvs.srv import Trigger
from tf2_ros import TransformBroadcaster


class RvizRobotSimulator(Node):
    def __init__(self):
        super().__init__('rviz_robot_simulator')

        descriptor = ParameterDescriptor(dynamic_typing=True)
        self.declare_parameter('timer_period', 0.05, descriptor)
        self.declare_parameter('initial_x', 1.0, descriptor)
        self.declare_parameter('initial_y', -2.2, descriptor)
        self.declare_parameter('initial_theta', 0.0, descriptor)
        self.declare_parameter('cmd_vel_topic', 'cmd_vel', descriptor)
        self.declare_parameter('odom_topic', 'odom', descriptor)
        self.declare_parameter('base_frame', 'base_footprint', descriptor)
        self.declare_parameter('world_frame', 'world', descriptor)

        self.timer_period = float(self.get_parameter('timer_period').value)
        self.initial_x = float(self.get_parameter('initial_x').value)
        self.initial_y = float(self.get_parameter('initial_y').value)
        self.initial_theta = float(self.get_parameter('initial_theta').value)
        self.cmd_vel_topic = str(self.get_parameter('cmd_vel_topic').value)
        self.odom_topic = str(self.get_parameter('odom_topic').value)
        self.base_frame = str(self.get_parameter('base_frame').value)
        self.world_frame = str(self.get_parameter('world_frame').value)

        namespace = self.get_namespace().strip('/')
        self.child_frame = f'{namespace}/{self.base_frame}' if namespace else self.base_frame

        self.cmd_v = 0.0
        self.cmd_w = 0.0
        self.x = self.initial_x
        self.y = self.initial_y
        self.theta = self.initial_theta
        self.last_time = self.get_clock().now()

        self.create_subscription(Twist, self.cmd_vel_topic, self.cmd_vel_callback, 10)
        self.odom_publisher = self.create_publisher(Odometry, self.odom_topic, 20)
        self.joint_state_publisher = self.create_publisher(JointState, 'joint_states', 10)
        self.tf_broadcaster = TransformBroadcaster(self)
        self.create_service(Trigger, 'reset_rviz_robot', self.reset_callback)
        self.timer = self.create_timer(self.timer_period, self.timer_callback)

        self.get_logger().info(
            f'RViz robot simulator ready at ({self.x:.2f}, {self.y:.2f}, {self.theta:.2f})'
        )

    def cmd_vel_callback(self, msg: Twist):
        self.cmd_v = float(msg.linear.x)
        self.cmd_w = float(msg.angular.z)

    def reset_callback(self, _request, response):
        self.x = self.initial_x
        self.y = self.initial_y
        self.theta = self.initial_theta
        self.cmd_v = 0.0
        self.cmd_w = 0.0
        self.last_time = self.get_clock().now()
        self.publish_state()
        response.success = True
        response.message = (
            f'robot reset to x={self.x:.3f}, y={self.y:.3f}, theta={self.theta:.3f}'
        )
        self.get_logger().info(response.message)
        return response

    def timer_callback(self):
        now = self.get_clock().now()
        dt = max(0.0, (now - self.last_time).nanoseconds / 1e9)
        self.last_time = now

        self.x += self.cmd_v * math.cos(self.theta) * dt
        self.y += self.cmd_v * math.sin(self.theta) * dt
        self.theta = self.normalize_angle(self.theta + self.cmd_w * dt)
        self.publish_state()

    def publish_state(self):
        stamp = self.get_clock().now().to_msg()
        half_theta = 0.5 * self.theta

        odom = Odometry()
        odom.header.stamp = stamp
        odom.header.frame_id = self.world_frame
        odom.child_frame_id = self.child_frame
        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.orientation.z = math.sin(half_theta)
        odom.pose.pose.orientation.w = math.cos(half_theta)
        odom.twist.twist.linear.x = self.cmd_v
        odom.twist.twist.angular.z = self.cmd_w
        self.odom_publisher.publish(odom)

        joint_state = JointState()
        joint_state.header.stamp = stamp
        joint_state.name = ['left_wheel_joint', 'right_wheel_joint']
        joint_state.position = [0.0, 0.0]
        joint_state.velocity = [0.0, 0.0]
        self.joint_state_publisher.publish(joint_state)

        transform = TransformStamped()
        transform.header.stamp = stamp
        transform.header.frame_id = self.world_frame
        transform.child_frame_id = self.child_frame
        transform.transform.translation.x = self.x
        transform.transform.translation.y = self.y
        transform.transform.rotation.z = math.sin(half_theta)
        transform.transform.rotation.w = math.cos(half_theta)
        self.tf_broadcaster.sendTransform(transform)

    @staticmethod
    def normalize_angle(angle):
        return math.atan2(math.sin(angle), math.cos(angle))


def main(args=None):
    rclpy.init(args=args)
    node = RvizRobotSimulator()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
