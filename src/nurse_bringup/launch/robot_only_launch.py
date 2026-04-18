"""
Minimal robot-only launch for scrub nurse UR5e + gripper + monitor GUI.

Usage:
  ros2 launch nurse_bringup robot_only_launch.py
  ros2 launch nurse_bringup robot_only_launch.py robot_ip:=192.168.10.126
  ros2 launch nurse_bringup robot_only_launch.py enable_monitor:=false
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, LogInfo
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    bringup_share = get_package_share_directory('nurse_bringup')
    robot_params = os.path.join(bringup_share, 'config', 'robot_params.yaml')
    monitor_script = os.path.join(
        os.path.dirname(os.path.dirname(os.path.dirname(bringup_share))),
        'scripts', 'robot_monitor.py')
    # Fallback to known absolute path
    if not os.path.exists(monitor_script):
        monitor_script = os.path.expanduser('~/scrub_nurse_ws/scripts/robot_monitor.py')

    declare_robot_ip = DeclareLaunchArgument(
        'robot_ip', default_value='192.168.10.126',
        description='IP address of the scrub nurse UR5e',
    )

    declare_enable_monitor = DeclareLaunchArgument(
        'enable_monitor', default_value='true',
        description='Launch robot monitor GUI',
    )

    robot_manager_node = Node(
        package='ur_robot_manager',
        executable='ur_robot_manager_node',
        name='ur_robot_manager_node',
        output='screen',
        parameters=[
            robot_params,
            {'robot_ip': LaunchConfiguration('robot_ip')},
        ],
    )

    gripper_node = Node(
        package='gripper_test',
        executable='gripper_node',
        name='gripper_node',
        output='screen',
    )

    monitor_process = ExecuteProcess(
        cmd=['python3', monitor_script],
        output='screen',
        condition=IfCondition(LaunchConfiguration('enable_monitor')),
    )

    return LaunchDescription([
        declare_robot_ip,
        declare_enable_monitor,
        LogInfo(msg='Starting scrub nurse robot-only (UR5e + gripper + monitor)...'),
        robot_manager_node,
        gripper_node,
        monitor_process,
    ])
