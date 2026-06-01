import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    ld = LaunchDescription()

    pkg_share = FindPackageShare(package='zmr_demo').find('zmr_demo')

    timer_period = LaunchConfiguration('timer_period')
    robot_id = LaunchConfiguration('robot_id')
    robot_namespace = LaunchConfiguration('robot_namespace')
    model_file_name = LaunchConfiguration('model_file_name')
    config_robot_fname = LaunchConfiguration('config_robot_fname')
    config_mpc_fname = LaunchConfiguration('config_mpc_fname')
    map_file_name = LaunchConfiguration('map_file_name')
    graph_file_name = LaunchConfiguration('graph_file_name')
    schedule_file_name = LaunchConfiguration('schedule_file_name')
    config_mmp_fname = LaunchConfiguration('config_mmp_fname')
    predictor_backend = LaunchConfiguration('predictor_backend')
    predictor_variant = LaunchConfiguration('predictor_variant')
    ebm_model_suffix = LaunchConfiguration('ebm_model_suffix')
    ebm_ref_image_path = LaunchConfiguration('ebm_ref_image_path')
    ebm_num_samples = LaunchConfiguration('ebm_num_samples')
    num_trials = LaunchConfiguration('num_trials')
    trial_timeout_sec = LaunchConfiguration('trial_timeout_sec')
    random_seed_base = LaunchConfiguration('random_seed_base')
    random_actor_min = LaunchConfiguration('random_actor_min')
    random_actor_max = LaunchConfiguration('random_actor_max')
    main_aisle_ratio = LaunchConfiguration('main_aisle_ratio')
    min_main_aisle_actors = LaunchConfiguration('min_main_aisle_actors')
    main_aisle_progress_min = LaunchConfiguration('main_aisle_progress_min')
    main_aisle_progress_max = LaunchConfiguration('main_aisle_progress_max')
    main_aisle_width = LaunchConfiguration('main_aisle_width')
    start_exclusion_radius = LaunchConfiguration('start_exclusion_radius')
    start_front_clear_dist = LaunchConfiguration('start_front_clear_dist')
    start_front_clear_width = LaunchConfiguration('start_front_clear_width')
    min_actor_spawn_separation = LaunchConfiguration('min_actor_spawn_separation')
    output_csv = LaunchConfiguration('output_csv')
    goal_x = LaunchConfiguration('goal_x')
    goal_y = LaunchConfiguration('goal_y')
    goal_tolerance = LaunchConfiguration('goal_tolerance')
    collision_distance = LaunchConfiguration('collision_distance')
    collision_ignore_when_stopped = LaunchConfiguration('collision_ignore_when_stopped')
    collision_motion_threshold = LaunchConfiguration('collision_motion_threshold')
    freeze_fail_sec = LaunchConfiguration('freeze_fail_sec')
    actor_warmup_sec = LaunchConfiguration('actor_warmup_sec')
    actor_warmup_timeout_sec = LaunchConfiguration('actor_warmup_timeout_sec')
    robot_settle_sec = LaunchConfiguration('robot_settle_sec')
    min_actor_pose_msgs_after_reset = LaunchConfiguration('min_actor_pose_msgs_after_reset')
    require_prediction_after_reset = LaunchConfiguration('require_prediction_after_reset')
    use_rviz = LaunchConfiguration('use_rviz')
    rviz_file_name = LaunchConfiguration('rviz_file_name')
    log_csv = LaunchConfiguration('log_csv')
    log_wandb = LaunchConfiguration('log_wandb')
    scenario_id = LaunchConfiguration('scenario_id')

    for name, default_value, description in [
        ('timer_period', '0.2', 'Main planning period'),
        ('robot_id', '0', 'Robot ID'),
        ('robot_namespace', 'zmr_X', 'Robot namespace'),
        ('model_file_name', 'robot.urdf.xacro', 'Robot model file'),
        ('config_robot_fname', 'robot_spec_zmr.yaml', 'Robot spec config'),
        ('config_mpc_fname', 'mpc_fast.yaml', 'MPC config'),
        ('map_file_name', 'warehouse_map_real.json', 'Map JSON'),
        ('graph_file_name', 'warehouse_graph.json', 'Navigation graph'),
        ('schedule_file_name', 'warehouse_schedule.csv', 'Robot schedule'),
        ('config_mmp_fname', 'wsd_1t20_poselu_enll_train.yaml', 'Motion prediction config'),
        ('predictor_backend', 'ebm', 'Motion prediction backend: st or ebm'),
        ('predictor_variant', 'ST-warehouse-progress', 'ST checkpoint variant'),
        ('ebm_model_suffix', '0', 'EBM checkpoint suffix'),
        ('ebm_ref_image_path', '', 'Optional EBM reference image path'),
        ('ebm_num_samples', '100', 'EBM samples per prediction step'),
        ('num_trials', '100', 'Number of RViz-only trials'),
        ('trial_timeout_sec', '90.0', 'Per-trial timeout'),
        ('random_seed_base', '1000', 'Actor random seed base'),
        ('random_actor_min', '7', 'Minimum random actor count per trial'),
        ('random_actor_max', '15', 'Maximum random actor count per trial'),
        ('main_aisle_ratio', '0.45', 'Fraction of actors biased near the main aisle'),
        ('min_main_aisle_actors', '4', 'Minimum number of main aisle nearby actors'),
        ('main_aisle_progress_min', '0.25', 'Lower progress bound for main aisle nearby actor spawns'),
        ('main_aisle_progress_max', '0.90', 'Upper progress bound for main aisle nearby actor spawns'),
        ('main_aisle_width', '2.0', 'Main aisle nearby spawn width in meters'),
        ('start_exclusion_radius', '2.5', 'No actor spawn or early path inside this radius from robot start'),
        ('start_front_clear_dist', '4.0', 'Forward clear-zone length from robot start'),
        ('start_front_clear_width', '1.8', 'Forward clear-zone width from robot start'),
        ('min_actor_spawn_separation', '0.8', 'Minimum spacing between actor initial positions'),
        ('output_csv', 'rviz_100_trials_ebm.csv', 'Trial summary CSV'),
        ('goal_x', '1.0', 'Goal x'),
        ('goal_y', '12.3', 'Goal y'),
        ('goal_tolerance', '0.5', 'Goal tolerance'),
        ('collision_distance', '0.22', 'Pedestrian fail distance; independent from MPC human inflation'),
        ('collision_ignore_when_stopped', 'true', 'Ignore pedestrian collision while robot is stopped'),
        ('collision_motion_threshold', '0.05', 'Minimum robot speed to count pedestrian collision'),
        ('freeze_fail_sec', '10.0', 'Freeze failure seconds'),
        ('actor_warmup_sec', '2.0', 'Delay after actor reset before robot reset'),
        ('actor_warmup_timeout_sec', '10.0', 'Maximum time to wait for actor/prediction warmup'),
        ('robot_settle_sec', '0.5', 'Delay after robot reset before starting a trial'),
        ('min_actor_pose_msgs_after_reset', '3', 'Actor pose messages required after actor reset'),
        ('require_prediction_after_reset', 'true', 'Wait for a prediction message after actor reset'),
        ('rviz_file_name', 'mmp_single_robot_surroundings.rviz', 'RViz config'),
        ('log_csv', 'false', 'Let MPC write its own CSV'),
        ('log_wandb', 'false', 'Enable W&B in MPC'),
        ('scenario_id', 'rviz_only_trials_ebm', 'MPC scenario label'),
    ]:
        ld.add_action(DeclareLaunchArgument(
            name=name,
            default_value=default_value,
            description=description,
        ))

    ld.add_action(DeclareLaunchArgument(
        name='use_rviz',
        default_value='true',
        choices=['true', 'false'],
        description='Whether to start RViz',
    ))

    rviz_file_path = PathJoinSubstitution([pkg_share, 'rviz', rviz_file_name])
    ld.add_action(Node(
        condition=IfCondition(use_rviz),
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_file_path],
    ))

    map_launch = PythonLaunchDescriptionSource([
        FindPackageShare(package='map_description').find('map_description'),
        '/launch/geo_map.launch.py',
    ])
    ld.add_action(IncludeLaunchDescription(map_launch, launch_arguments={
        'timer_period': timer_period,
        'map_file_name': map_file_name,
        'use_rviz': 'false',
    }.items()))

    motion_plan_launch = PythonLaunchDescriptionSource([
        FindPackageShare(package='mps_motion_plan').find('mps_motion_plan'),
        '/launch/motion_plan.launch.py',
    ])
    ld.add_action(IncludeLaunchDescription(motion_plan_launch, launch_arguments={
        'graph_file_name': graph_file_name,
        'schedule_file_name': schedule_file_name,
        'rescale_map': 'false',
        'rescale_graph': 'false',
    }.items()))

    robot_bringup_launch = PythonLaunchDescriptionSource([
        FindPackageShare(package='zmr_description').find('zmr_description'),
        '/launch/zmr_bringup.launch.py',
    ])
    ld.add_action(IncludeLaunchDescription(robot_bringup_launch, launch_arguments={
        'robot_namespace': robot_namespace,
        'model_file_name': model_file_name,
        'use_rviz': 'false',
        'use_joint_state_publisher': 'false',
    }.items()))

    ld.add_action(Node(
        package='zmr_demo',
        executable='rviz_robot_simulator',
        namespace=robot_namespace,
        name='rviz_robot_simulator',
        output='screen',
        parameters=[
            {'timer_period': 0.05},
            {'initial_x': 1.0},
            {'initial_y': -2.2},
            {'initial_theta': 0.0},
        ],
    ))

    ld.add_action(Node(
        package='zmr_demo',
        executable='rviz_actor_simulator',
        name='rviz_actor_simulator',
        output='screen',
        parameters=[
            {'timer_period': timer_period},
            {'random_seed_base': random_seed_base},
            {'actor_min_count': random_actor_min},
            {'actor_max_count': random_actor_max},
            {'main_aisle_ratio': main_aisle_ratio},
            {'min_main_aisle_actors': min_main_aisle_actors},
            {'main_aisle_progress_min': main_aisle_progress_min},
            {'main_aisle_progress_max': main_aisle_progress_max},
            {'main_aisle_width': main_aisle_width},
            {'start_exclusion_radius': start_exclusion_radius},
            {'start_front_clear_dist': start_front_clear_dist},
            {'start_front_clear_width': start_front_clear_width},
            {'min_actor_spawn_separation': min_actor_spawn_separation},
            {'map_file_name': map_file_name},
            {'graph_file_name': graph_file_name},
        ],
    ))

    ld.add_action(Node(
        package='mmp_motion_predict',
        executable='motion_prediction_node',
        name='motion_prediction_node',
        output='screen',
        parameters=[
            {'timer_period': timer_period},
            {'predictor_backend': predictor_backend},
            {'config_file_name': config_mmp_fname},
            {'predictor_variant': predictor_variant},
            {'ebm_model_suffix': ebm_model_suffix},
            {'ebm_ref_image_path': ebm_ref_image_path},
            {'ebm_num_samples': ebm_num_samples},
        ],
    ))

    mpc_launch = PythonLaunchDescriptionSource([
        FindPackageShare(package='zmr_mpc').find('zmr_mpc'),
        '/launch/zmr_mpc.launch.py',
    ])
    ld.add_action(IncludeLaunchDescription(mpc_launch, launch_arguments={
        'timer_period': timer_period,
        'robot_id': robot_id,
        'robot_namespace': robot_namespace,
        'config_mpc_fname': config_mpc_fname,
        'config_robot_fname': config_robot_fname,
        'log_csv': log_csv,
        'log_wandb': log_wandb,
        'scenario_id': scenario_id,
        'max_task_time': trial_timeout_sec,
        'goal_tolerance': goal_tolerance,
        'predictor_variant': predictor_variant,
        'reset_on_finish': 'false',
        'rerandomize_actors_on_reset': 'false',
        'robot_init_x': '1.0',
        'robot_init_y': '-2.2',
        'robot_init_z': '0.0',
        'robot_init_theta': '0.0',
    }.items()))

    ld.add_action(Node(
        package='zmr_demo',
        executable='rviz_trial_manager',
        name='rviz_trial_manager',
        output='screen',
        parameters=[
            {'num_trials': num_trials},
            {'trial_timeout_sec': trial_timeout_sec},
            {'random_seed_base': random_seed_base},
            {'output_csv': output_csv},
            {'goal_x': goal_x},
            {'goal_y': goal_y},
            {'goal_tolerance': goal_tolerance},
            {'collision_distance': collision_distance},
            {'collision_ignore_when_stopped': collision_ignore_when_stopped},
            {'collision_motion_threshold': collision_motion_threshold},
            {'freeze_fail_sec': freeze_fail_sec},
            {'actor_warmup_sec': actor_warmup_sec},
            {'actor_warmup_timeout_sec': actor_warmup_timeout_sec},
            {'robot_settle_sec': robot_settle_sec},
            {'min_actor_pose_msgs_after_reset': min_actor_pose_msgs_after_reset},
            {'require_prediction_after_reset': require_prediction_after_reset},
            {'map_file_name': map_file_name},
            {'robot_namespace': robot_namespace},
        ],
    ))

    return ld
