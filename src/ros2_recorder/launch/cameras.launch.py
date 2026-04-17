"""
cameras.launch.py — Launch surgical cameras as ROS2 usb_cam nodes.

Device mapping (update if your devices change):
    /dev/video0  → RealSense RGB      → /cam_global/image_raw     (disabled by default)
    /dev/video6  → ABKO APC930 QHD    → /cam_handover/image_raw
    /dev/video8  → Logitech C920 HD   → /cam_side/image_raw
    /dev/video10 → USB Endoscope      → /cam_endoscope/image_raw

Usage:
    ros2 launch ros2_recorder cameras.launch.py
    ros2 launch ros2_recorder cameras.launch.py cam_global_dev:=/dev/video2

After launch, verify with:
    ros2 topic list | grep cam
    ros2 topic hz /cam_endoscope/image_raw
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


CAMERAS = [
    {
        "name": "cam_global",
        "default_device": "/dev/video0",
        "description": "Full robot workspace (RealSense RGB)",
        "width": 640,
        "height": 480,
        "fps": 15.0,
        "pixel_format": "yuyv",
        "enabled": False,   # RealSense not connected — set True when available
    },
    {
        "name": "cam_handover",
        "default_device": "/dev/video6",
        "description": "Handover zone close-up (ABKO QHD)",
        "width": 640,
        "height": 480,
        "fps": 15.0,
        "pixel_format": "mjpeg2rgb",
        "enabled": True,
    },
    {
        "name": "cam_side",
        "default_device": "/dev/video8",
        "description": "Redundant side view (C920)",
        "width": 640,
        "height": 480,
        "fps": 15.0,
        "pixel_format": "yuyv",
        "enabled": True,
    },
    {
        "name": "cam_endoscope",
        "default_device": "/dev/video10",
        "description": "Endoscope ear canal view (USB)",
        "width": 640,
        "height": 480,
        "fps": 15.0,
        "pixel_format": "mjpeg2rgb",
        "enabled": True,
    },
]


def generate_launch_description():
    actions = []

    for cam in CAMERAS:
        if not cam.get("enabled", True):
            continue

        name = cam["name"]

        dev_arg = DeclareLaunchArgument(
            f"{name}_dev",
            default_value=cam["default_device"],
            description=f"Video device for {name} ({cam['description']})",
        )
        actions.append(dev_arg)

        node = Node(
            package="usb_cam",
            executable="usb_cam_node_exe",
            name=name,
            namespace=name,
            output="screen",
            parameters=[{
                "video_device": LaunchConfiguration(f"{name}_dev"),
                "image_width": cam["width"],
                "image_height": cam["height"],
                "framerate": cam["fps"],
                "pixel_format": cam["pixel_format"],
                "camera_name": name,
                "frame_id": name,
                "auto_white_balance": True,
                "autoexposure": True,
            }],
            remappings=[
                ("image_raw", f"/{name}/image_raw"),
                ("camera_info", f"/{name}/camera_info"),
            ],
        )
        actions.append(node)

    return LaunchDescription(actions)
