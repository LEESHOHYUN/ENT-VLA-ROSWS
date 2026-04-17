from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('slave_number', default_value='1'),
        DeclareLaunchArgument('ui_on', default_value='false'),

        Node(
            package='gripper_test',
            executable='gripper_node',
            name='gripper_node',
            parameters=[{
                'slave_number': LaunchConfiguration('slave_number'),
                'ui_on': LaunchConfiguration('ui_on'),
            }],
            output='screen',
        ),

        Node(
            package='gripper_test',
            executable='gripper_action_node',
            name='gripper_action',
            output='screen',
        ),
    ])
