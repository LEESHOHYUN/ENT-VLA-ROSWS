"""
Minimal robot-only launch for scrub nurse UR5e + gripper testing.
No cameras, no pipeline, no web GUI.

Usage:
  ros2 launch nurse_bringup robot_only_launch.py
  ros2 launch nurse_bringup robot_only_launch.py robot_ip:=192.168.10.126
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    bringup_share = get_package_share_directory('nurse_bringup')
    robot_params = os.path.join(bringup_share, 'config', 'robot_params.yaml')

    declare_robot_ip = DeclareLaunchArgument(
        'robot_ip', default_value='192.168.10.126',
        description='IP address of the scrub nurse UR5e',
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

    return LaunchDescription([
        declare_robot_ip,
        LogInfo(msg='Starting scrub nurse robot-only (UR5e + gripper)...'),
        robot_manager_node,
        gripper_node,
    ])
