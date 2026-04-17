"""
Camera-only launch for testing multi-camera setup independently.

Launches:
  - cam_handeye (RealSense, wrist mounted)
  - cam_handover (USB webcam, handover zone)
  - cam_endoscope (USB endoscope)

Usage:
  ros2 launch nurse_bringup cameras_only_launch.py
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import LogInfo
from launch_ros.actions import Node


def generate_launch_description():
    bringup_share = get_package_share_directory('nurse_bringup')
    camera_params = os.path.join(bringup_share, 'config', 'camera_params.yaml')

    cam_handeye_node = Node(
        package='realsense2_camera',
        executable='realsense2_camera_node',
        name='camera',
        namespace='cam_handeye',
        output='screen',
        parameters=[camera_params],
    )

    cam_handover_node = Node(
        package='usb_cam',
        executable='usb_cam_node_exe',
        name='usb_cam',
        namespace='cam_handover',
        output='screen',
        parameters=[{
            'video_device': '/dev/video0',
            'image_width': 640,
            'image_height': 480,
            'framerate': 30.0,
            'pixel_format': 'yuyv',
        }],
    )

    cam_endoscope_node = Node(
        package='usb_cam',
        executable='usb_cam_node_exe',
        name='usb_cam',
        namespace='cam_endoscope',
        output='screen',
        parameters=[{
            'video_device': '/dev/video2',
            'image_width': 640,
            'image_height': 480,
            'framerate': 30.0,
            'pixel_format': 'yuyv',
        }],
    )

    return LaunchDescription([
        LogInfo(msg='Starting multi-camera setup (handeye + handover + endoscope)...'),
        cam_handeye_node,
        cam_handover_node,
        cam_endoscope_node,
    ])
