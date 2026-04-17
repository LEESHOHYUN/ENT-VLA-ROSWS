"""
record_all.launch.py — Launch cameras + synchronized recorder.

Usage:
    ros2 launch ros2_recorder record_all.launch.py
    ros2 launch ros2_recorder record_all.launch.py cam_global_dev:=/dev/video2

Skip a camera (e.g. RealSense not connected):
    ros2 launch ros2_recorder record_all.launch.py cam_global_dev:=/dev/null

Stop recording: Ctrl+C
"""

import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    launch_dir = os.path.dirname(os.path.abspath(__file__))
    pkg_dir = os.path.dirname(launch_dir)
    recorder_script = os.path.join(pkg_dir, "nodes", "recorder_node.py")
    config_path = os.path.join(pkg_dir, "config", "recorder_config.yaml")

    # 1. Launch all cameras
    cameras_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(launch_dir, "cameras.launch.py")
        ),
    )

    # 2. Launch recorder as a Python process (no colcon build needed)
    #    Delayed 3s to let cameras initialize.
    recorder_process = TimerAction(
        period=3.0,
        actions=[
            ExecuteProcess(
                cmd=[
                    "python3", recorder_script,
                    "--ros-args", "-p", f"config_file:={config_path}",
                ],
                output="screen",
            ),
        ],
    )

    return LaunchDescription([
        cameras_launch,
        recorder_process,
    ])
