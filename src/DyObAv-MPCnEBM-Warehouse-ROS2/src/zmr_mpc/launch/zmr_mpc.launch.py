import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch_ros.actions import Node

from launch.substitutions import LaunchConfiguration, PathJoinSubstitution, Command
from launch_ros.substitutions import FindPackageShare
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.descriptions import ParameterValue


def generate_launch_description():
    ld = LaunchDescription()

    pkg_name = 'zmr_mpc'
    pkg_share = FindPackageShare(pkg_name).find(pkg_name) 

    ### Default Values ###
    default_timer_period = 0.2
    default_robot_id = '0'
    default_robot_namespace = 'zmr_X' # letters_numbers
    default_config_mpc_fname = 'mpc_fast.yaml'
    default_config_robot_fname = 'robot_spec_zmr.yaml'

    default_enable_fleet_manager = 'false'

    default_log_csv = 'false'
    default_log_wandb = 'false'
    default_scenario_id = 'S0'
    default_max_task_time = '120.0'
    default_goal_tolerance = '0.5'
    default_predictor_variant = 'zara2'

    ### Declare Launch Variables ###
    timer_period = LaunchConfiguration('timer_period')
    robot_id = LaunchConfiguration('robot_id')
    robot_namespace = LaunchConfiguration('robot_namespace')
    config_mpc_fname = LaunchConfiguration('config_mpc_fname')
    config_robot_fname = LaunchConfiguration('config_robot_fname')

    enable_fleet_manager = LaunchConfiguration('enable_fleet_manager')
    log_csv = LaunchConfiguration('log_csv')
    log_wandb = LaunchConfiguration('log_wandb')
    scenario_id = LaunchConfiguration('scenario_id')
    max_task_time = LaunchConfiguration('max_task_time')
    goal_tolerance = LaunchConfiguration('goal_tolerance')
    predictor_variant = LaunchConfiguration('predictor_variant')

    ### Declare Launch Arguments ###
    declare_timer_period_arg = DeclareLaunchArgument(
        name="timer_period",
        default_value=str(default_timer_period),
        description="Period of timer in seconds",
    )
    ld.add_action(declare_timer_period_arg)

    declare_robot_id_arg = DeclareLaunchArgument(
        name="robot_id",
        default_value=str(default_robot_id),
        description="Robot ID",
    )
    ld.add_action(declare_robot_id_arg)

    declare_robot_namespace_arg = DeclareLaunchArgument(
        name="robot_namespace",
        default_value=str(default_robot_namespace),
        description="Prefix for the robot namespace",
    )
    ld.add_action(declare_robot_namespace_arg)

    declare_config_mpc_fname_arg = DeclareLaunchArgument(
        name="config_mpc_fname",
        default_value=str(default_config_mpc_fname),
        description="File name of the MPC configuration",
    )
    ld.add_action(declare_config_mpc_fname_arg)

    declare_config_robot_fname_arg = DeclareLaunchArgument(
        name="config_robot_fname",
        default_value=str(default_config_robot_fname),
        description="File name of the robot specification",
    )
    ld.add_action(declare_config_robot_fname_arg)

    declare_enable_fleet_manager_arg = DeclareLaunchArgument(
        name="enable_fleet_manager",
        default_value=str(default_enable_fleet_manager),
        description="Enable fleet manager",
    )
    ld.add_action(declare_enable_fleet_manager_arg)

    declare_log_csv_arg = DeclareLaunchArgument(
        name="log_csv",
        default_value=default_log_csv,
        choices=["true", "false"],
        description="Enable experiment CSV recording",
    )
    ld.add_action(declare_log_csv_arg)

    declare_log_wandb_arg = DeclareLaunchArgument(
        name="log_wandb",
        default_value=default_log_wandb,
        choices=["true", "false"],
        description="Enable Weights & Biases live logging",
    )
    ld.add_action(declare_log_wandb_arg)

    declare_scenario_id_arg = DeclareLaunchArgument(
        name="scenario_id",
        default_value=default_scenario_id,
        description="Scenario label written to CSV (e.g. S1, S2)",
    )
    ld.add_action(declare_scenario_id_arg)

    declare_max_task_time_arg = DeclareLaunchArgument(
        name="max_task_time",
        default_value=default_max_task_time,
        description="Max seconds before run is marked as timeout",
    )
    ld.add_action(declare_max_task_time_arg)

    declare_goal_tolerance_arg = DeclareLaunchArgument(
        name="goal_tolerance",
        default_value=default_goal_tolerance,
        description="Distance (m) to goal to count as reached",
    )
    ld.add_action(declare_goal_tolerance_arg)

    declare_predictor_variant_arg = DeclareLaunchArgument(
        name="predictor_variant",
        default_value=default_predictor_variant,
        description="ST checkpoint variant: 'zara2' or 'ST-warehouse-progress'",
    )
    ld.add_action(declare_predictor_variant_arg)

    ### Nodes ###
    mpc_trajectory_tracker_node = Node(
        package=pkg_name,
        executable='mpc_trajectory_tracker_node',
        name='mpc_trajectory_tracker_node',
        # remappings=[
        #     ('/inflated_geometry_map', ['/zmr_X/inflated_geometry_map']),
        # ],
        namespace=robot_namespace,
        output='screen',
        parameters=[
            {'enable_fleet_manager': enable_fleet_manager},
            {'timer_period': timer_period},
            {'robot_id': robot_id},
            {'config_mpc_fname': config_mpc_fname},
            {'config_robot_fname': config_robot_fname},
            {'log_csv': log_csv},
            {'log_wandb': log_wandb},
            {'scenario_id': scenario_id},
            {'max_task_time': max_task_time},
            {'goal_tolerance': goal_tolerance},
            {'predictor_variant': predictor_variant},
        ],
    )
    ld.add_action(mpc_trajectory_tracker_node)

    return ld