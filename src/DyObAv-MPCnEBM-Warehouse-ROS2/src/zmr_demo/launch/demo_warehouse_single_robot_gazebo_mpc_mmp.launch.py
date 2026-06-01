import os
from typing import Union

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.actions import IncludeLaunchDescription

from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.substitutions import Command
from launch_ros.substitutions import FindPackageShare
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource


def summon_robot(pkg_share, model_file_name, robot_namespace: Union[str, LaunchConfiguration], robot_init_position: list[float]) -> list:
    """Return a list of actions (Rviz, Gazebo, MapTransform) to be added in the launch description to summon a robot."""
    launch_file_rviz = PythonLaunchDescriptionSource(
        [pkg_share, '/launch/zmr_bringup.launch.py'])
    include_launch_rviz = IncludeLaunchDescription(launch_file_rviz, launch_arguments={
        'model_file_name': model_file_name,
        'robot_namespace': robot_namespace,
        'use_rviz': 'false',
        'use_joint_state_publisher': 'false'}.items()
    )

    launch_file_gazebo = PythonLaunchDescriptionSource(
        [pkg_share, '/launch/zmr_spawn_entity.launch.py'])
    include_launch_gazebo = IncludeLaunchDescription(launch_file_gazebo, launch_arguments={
        'model_file_name': model_file_name,
        'robot_namespace': robot_namespace,
        'use_gazebo': 'false',
        'init_x': str(robot_init_position[0]),
        'init_y': str(robot_init_position[1]),
        'init_z': '0.0',
        'init_theta': str(robot_init_position[2])}.items()
    )

    if isinstance(robot_namespace, LaunchConfiguration):
        map_transform_node = Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            namespace=robot_namespace,
            name='static_transform_publisher',
            arguments=['0', '0', '0', '0', '0', '0', 'world', [robot_namespace, '/odom']], # x y z yaw pitch roll frame_id child_frame_id period_in_ms
        )
    elif isinstance(robot_namespace, str):
        map_transform_node = Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='static_transform_publisher_'+robot_namespace,
            arguments=['0', '0', '0', '0', '0', '0', 'world', robot_namespace+'/odom'], # x y z yaw pitch roll frame_id child_frame_id period_in_ms
        )
    else:
        raise TypeError("robot_namespace must be either a string or a LaunchConfiguration.")
    
    return [include_launch_rviz, include_launch_gazebo, map_transform_node]


def generate_launch_description():
    ld = LaunchDescription()
  
    pkg_name = 'zmr_demo'
    pkg_share = FindPackageShare(package=pkg_name).find(pkg_name)

    ### Fixed Values ###
    robot_init_position = [1.0, -2.2, 0.0]  # x, y, theta

    ### Default Values ###
    default_timer_period = 0.2

    default_robot_id = '0'
    default_robot_namespace = 'zmr_X'
    default_model_file_name = 'robot.urdf.xacro'
    default_config_file_name = 'robot_spec_mir.yaml'

    default_map_file_name = 'warehouse_map_real.json'
    default_graph_file_name = 'warehouse_graph.json'
    default_schedule_file_name = 'warehouse_schedule.csv'

    default_config_mmp_fname = 'wsd_1t20_poselu_enll_train.yaml'

    default_rviz_file_name = 'mmp_single_robot_surroundings.rviz'
    default_world_file_name = 'aws/small_warehouse_2.world'

    default_log_csv = 'false'
    default_log_wandb = 'false'
    default_scenario_id = 'S0'
    default_max_task_time = '120.0'
    default_goal_tolerance = '0.5'
    default_predictor_variant = 'zara2'
    default_reset_on_finish = 'true'
    default_rerandomize_actors_on_reset = 'true'
    default_randomize_actors = 'true'

    ### Declare Launch Variables ###
    timer_period = LaunchConfiguration('timer_period')

    robot_id = LaunchConfiguration('robot_id')
    robot_namespace = LaunchConfiguration('robot_namespace')
    model_file_name = LaunchConfiguration('model_file_name')
    config_file_name = LaunchConfiguration('config_file_name')

    map_file_name = LaunchConfiguration('map_file_name')
    graph_file_name = LaunchConfiguration('graph_file_name')
    schedule_file_name = LaunchConfiguration('schedule_file_name')

    config_mmp_fname = LaunchConfiguration('config_mmp_fname')

    log_csv = LaunchConfiguration('log_csv')
    log_wandb = LaunchConfiguration('log_wandb')
    scenario_id = LaunchConfiguration('scenario_id')
    max_task_time = LaunchConfiguration('max_task_time')
    goal_tolerance = LaunchConfiguration('goal_tolerance')
    predictor_variant = LaunchConfiguration('predictor_variant')
    reset_on_finish = LaunchConfiguration('reset_on_finish')
    rerandomize_actors_on_reset = LaunchConfiguration('rerandomize_actors_on_reset')
    randomize_actors = LaunchConfiguration('randomize_actors')

    use_controller = LaunchConfiguration('use_controller')

    use_rviz = LaunchConfiguration('use_rviz')
    rviz_file_name = LaunchConfiguration('rviz_file_name')
    world_file_name = LaunchConfiguration('world_file_name')

    ### Declare Launch Arguments ###
    declare_timer_period_arg = DeclareLaunchArgument(
        name='timer_period',
        default_value=str(default_timer_period),
        description='Map update period'
    )
    ld.add_action(declare_timer_period_arg)

    declare_model_file_name_arg = DeclareLaunchArgument(
        name='model_file_name',
        default_value=str(default_model_file_name),
        description='Model file name'
    )
    ld.add_action(declare_model_file_name_arg)

    declare_config_file_name_arg = DeclareLaunchArgument(
        name='config_file_name',
        default_value=str(default_config_file_name),
        description='Config file name'
    )
    ld.add_action(declare_config_file_name_arg)

    declare_robot_id_arg = DeclareLaunchArgument(
        name='robot_id',
        default_value=str(default_robot_id),
        description='Robot ID'
    )
    ld.add_action(declare_robot_id_arg)

    declare_robot_namespace_arg = DeclareLaunchArgument(
        name='robot_namespace',
        default_value=str(default_robot_namespace),
        description='Robot namespace'
    )
    ld.add_action(declare_robot_namespace_arg)

    declare_config_mmp_fname_arg = DeclareLaunchArgument(
        name="config_mmp_fname",
        default_value=default_config_mmp_fname,
        description="Config file name for motion prediction",
    )
    ld.add_action(declare_config_mmp_fname_arg)

    declare_map_file_name_arg = DeclareLaunchArgument(
        name='map_file_name',
        default_value=str(default_map_file_name),
        description='Map file name'
    )
    ld.add_action(declare_map_file_name_arg)

    declare_graph_file_name_arg = DeclareLaunchArgument(
        name='graph_file_name',
        default_value=str(default_graph_file_name),
        description='Graph file name'
    )
    ld.add_action(declare_graph_file_name_arg)

    declare_schedule_file_name_arg = DeclareLaunchArgument(
        name='schedule_file_name',
        default_value=str(default_schedule_file_name),
        description='Schedule file name (in CSV format)'
    )
    ld.add_action(declare_schedule_file_name_arg)

    declare_log_csv_arg = DeclareLaunchArgument(
        name='log_csv',
        default_value=default_log_csv,
        choices=["true", "false"],
        description='Enable experiment CSV recording'
    )
    ld.add_action(declare_log_csv_arg)

    declare_log_wandb_arg = DeclareLaunchArgument(
        name='log_wandb',
        default_value=default_log_wandb,
        choices=["true", "false"],
        description='Enable Weights & Biases live logging'
    )
    ld.add_action(declare_log_wandb_arg)

    declare_scenario_id_arg = DeclareLaunchArgument(
        name='scenario_id',
        default_value=default_scenario_id,
        description='Scenario label written to CSV (e.g. S1, S2)'
    )
    ld.add_action(declare_scenario_id_arg)

    declare_max_task_time_arg = DeclareLaunchArgument(
        name='max_task_time',
        default_value=default_max_task_time,
        description='Max seconds before run is marked as timeout'
    )
    ld.add_action(declare_max_task_time_arg)

    declare_goal_tolerance_arg = DeclareLaunchArgument(
        name='goal_tolerance',
        default_value=default_goal_tolerance,
        description='Distance (m) to goal to count as reached'
    )
    ld.add_action(declare_goal_tolerance_arg)

    declare_predictor_variant_arg = DeclareLaunchArgument(
        name='predictor_variant',
        default_value=default_predictor_variant,
        description="ST checkpoint variant: 'zara2' or 'ST-warehouse-progress'",
    )
    ld.add_action(declare_predictor_variant_arg)

    declare_reset_on_finish_arg = DeclareLaunchArgument(
        name='reset_on_finish',
        default_value=default_reset_on_finish,
        choices=['true', 'false'],
        description='Reset Gazebo world and MPC policy state after each recorded run',
    )
    ld.add_action(declare_reset_on_finish_arg)

    declare_rerandomize_actors_on_reset_arg = DeclareLaunchArgument(
        name='rerandomize_actors_on_reset',
        default_value=default_rerandomize_actors_on_reset,
        choices=['true', 'false'],
        description='Randomize actor start-goal paths before resetting simulation time',
    )
    ld.add_action(declare_rerandomize_actors_on_reset_arg)

    declare_randomize_actors_arg = DeclareLaunchArgument(
        name='randomize_actors',
        default_value=default_randomize_actors,
        choices=['true', 'false'],
        description='Randomize actors in the Gazebo world before startup',
    )
    ld.add_action(declare_randomize_actors_arg)

    declare_use_controller_arg = DeclareLaunchArgument(
        name='use_controller',
        default_value='true',
        choices=["true", "false"],
        description='Whether to start controller'
    )
    ld.add_action(declare_use_controller_arg)

    declare_use_rviz_arg = DeclareLaunchArgument(
        name='use_rviz',
        default_value='true',
        choices=["true", "false"],
        description='Whether to start RVIZ'
    )
    ld.add_action(declare_use_rviz_arg)

    declare_rviz_file_name_arg = DeclareLaunchArgument(
        name="rviz_file_name", 
        default_value=str(default_rviz_file_name), 
        description="Name of rviz config file"
    )
    ld.add_action(declare_rviz_file_name_arg)
    rviz_file_path = PathJoinSubstitution([pkg_share, 'rviz', rviz_file_name])

    declare_world_file_name_arg = DeclareLaunchArgument(
        name='world_file_name',
        default_value=str(default_world_file_name),
        description='Name of the world file to load'
    )
    ld.add_action(declare_world_file_name_arg)

    ### Nodes ###
    rviz2_node = Node(
        condition=IfCondition(use_rviz),
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=["-d", rviz_file_path],
    )
    ld.add_action(rviz2_node)

    ### Other Launch Files ###
    pkg_name_1 = 'map_description'
    launch_file_1 = PythonLaunchDescriptionSource(
        [FindPackageShare(package=pkg_name_1).find(pkg_name_1), '/launch/geo_map.launch.py'])
    include_launch_1 = IncludeLaunchDescription(launch_file_1, launch_arguments={
        'timer_period': timer_period,
        'map_file_name': map_file_name,
        'use_rviz': 'false'}.items()
    )
    ld.add_action(include_launch_1)

    pkg_name_gazebo = 'gazebo_worlds'
    launch_file_gazebo = PythonLaunchDescriptionSource(
        [FindPackageShare(package=pkg_name_gazebo).find(pkg_name_gazebo), '/launch/small_warehouse.launch.py'])
    include_launch_gazebo = IncludeLaunchDescription(launch_file_gazebo, launch_arguments={
        'world_file_name': world_file_name,
        'map_file_name': map_file_name,
        'graph_file_name': graph_file_name,
        'schedule_file_name': schedule_file_name,
        'randomize_actors': randomize_actors,
        'paused': 'false'}.items()
    )
    ld.add_action(include_launch_gazebo)

    pkg_name_2 = 'mps_motion_plan'
    launch_file_2 = PythonLaunchDescriptionSource(
        [FindPackageShare(package=pkg_name_2).find(pkg_name_2), '/launch/motion_plan.launch.py'])
    include_launch_2 = IncludeLaunchDescription(launch_file_2, launch_arguments={
        "schedule_file_name": schedule_file_name,
        'graph_file_name': graph_file_name,
        'rescale_map': 'false',
        'rescale_graph': 'false'}.items()
    )
    ld.add_action(include_launch_2)

    pkg_name_3 = 'zmr_description'
    pkg_share_robot = FindPackageShare(package=pkg_name_3).find(pkg_name_3)
    robot_launch_list = summon_robot(pkg_share_robot, model_file_name, robot_namespace, robot_init_position)
    for action in robot_launch_list:
        ld.add_action(action)

    ### Only when not using Gazebo ###
    # pkg_name_4 = 'zmr_drive_model'
    # launch_file_4 = PythonLaunchDescriptionSource(
    #     [FindPackageShare(package=pkg_name_4).find(pkg_name_4), '/launch/zmr_drive_model.launch.py'])
    # include_launch_4 = IncludeLaunchDescription(launch_file_4, launch_arguments={
    #     'robot_namespace': robot_namespace,
    #     'init_x': '1.0',
    #     'init_y': '-1.7',
    #     'init_theta': '1.57',
    #     'keep_cmd_vel': 'true'}.items()
    # )
    # ld.add_action(include_launch_4)

    pkg_name_6 = 'zmr_mpc'
    launch_file_6 = PythonLaunchDescriptionSource(
        [FindPackageShare(package=pkg_name_6).find(pkg_name_6), '/launch/zmr_mpc.launch.py'])
    include_launch_6 = IncludeLaunchDescription(launch_file_6, launch_arguments={
        'timer_period': timer_period,
        'robot_namespace': robot_namespace,
        'config_file_name': config_file_name,
        'robot_id': robot_id,
        'log_csv': log_csv,
        'log_wandb': log_wandb,
        'scenario_id': scenario_id,
        'max_task_time': max_task_time,
        'goal_tolerance': goal_tolerance,
        'predictor_variant': predictor_variant,
        'reset_on_finish': reset_on_finish,
        'rerandomize_actors_on_reset': rerandomize_actors_on_reset,
        'robot_init_x': str(robot_init_position[0]),
        'robot_init_y': str(robot_init_position[1]),
        'robot_init_z': '0.0',
        'robot_init_theta': str(robot_init_position[2])}.items()
    )
    ld.add_action(include_launch_6)

    pkg_name_7 = 'mmp_motion_predict'
    launch_file_7 = PythonLaunchDescriptionSource(
        [FindPackageShare(package=pkg_name_7).find(pkg_name_7), '/launch/mmp_motion_predict.launch.py'])
    include_launch_7 = IncludeLaunchDescription(launch_file_7, launch_arguments={
        'timer_period': timer_period,
        'config_mmp_fname': config_mmp_fname,
        'predictor_variant': predictor_variant}.items()
    )
    ld.add_action(include_launch_7)

    return ld
