"""
Full system launch for ENT Surgical Scrub Nurse.

Single UR5e + gripper + multi-camera + full VLA pipeline.

Usage:
  ros2 launch nurse_bringup full_system_launch.py
  ros2 launch nurse_bringup full_system_launch.py robot_ip:=192.168.10.126
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, LogInfo
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    bringup_share = get_package_share_directory('nurse_bringup')

    robot_params = os.path.join(bringup_share, 'config', 'robot_params.yaml')
    camera_params = os.path.join(bringup_share, 'config', 'camera_params.yaml')
    vla_params = os.path.join(bringup_share, 'config', 'vla_params.yaml')

    # --------------- Launch Arguments ---------------
    declare_robot_ip = DeclareLaunchArgument(
        'robot_ip', default_value='192.168.10.126',
        description='IP address of the scrub nurse UR5e',
    )
    declare_enable_cameras = DeclareLaunchArgument(
        'enable_cameras', default_value='true',
        description='Enable all cameras',
    )
    declare_enable_pipeline = DeclareLaunchArgument(
        'enable_pipeline', default_value='false',
        description='Enable VLA pipeline nodes (SAM2S, Planner, VLA)',
    )
    declare_enable_webgui = DeclareLaunchArgument(
        'enable_webgui', default_value='true',
        description='Enable WebGUI monitoring (rosbridge + web_video_server)',
    )

    # --------------- Robot + Gripper ---------------
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

    # --------------- Cameras ---------------
    # RealSense (wrist-mounted, cam_handeye)
    cam_handeye_node = Node(
        package='realsense2_camera',
        executable='realsense2_camera_node',
        name='camera',
        namespace='cam_handeye',
        output='screen',
        parameters=[camera_params],
        condition=IfCondition(LaunchConfiguration('enable_cameras')),
    )

    # USB webcam (handover zone overview)
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
        condition=IfCondition(LaunchConfiguration('enable_cameras')),
    )

    # USB endoscope
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
        condition=IfCondition(LaunchConfiguration('enable_cameras')),
    )

    # --------------- VLA Pipeline (conditional) ---------------
    # These nodes are placeholders — enable when models are ready
    # SAM2S node: nurse_perception package
    # Planner node: nurse_planning package
    # Safety Gate node: nurse_planning package
    # VLA Executor node: nurse_control package
    # Each will be added as Node() entries once implemented.

    # --------------- WebGUI Monitoring ---------------
    rosbridge_node = Node(
        package='rosbridge_server',
        executable='rosbridge_websocket',
        name='rosbridge_websocket',
        output='screen',
        parameters=[{'port': 9090, 'unregister_timeout': 60.0}],
        condition=IfCondition(LaunchConfiguration('enable_webgui')),
    )

    web_video_node = Node(
        package='web_video_server',
        executable='web_video_server',
        name='web_video_server',
        output='screen',
        parameters=[{'port': 8080, 'default_stream_type': 'mjpeg'}],
        condition=IfCondition(LaunchConfiguration('enable_webgui')),
    )

    # --------------- Static TF ---------------
    static_tf_world = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='static_tf_world_to_base',
        arguments=[
            '--x', '0', '--y', '0', '--z', '0',
            '--roll', '0', '--pitch', '0', '--yaw', '0',
            '--frame-id', 'world', '--child-frame-id', 'base_link',
        ],
    )

    # --------------- Launch Description ---------------
    return LaunchDescription([
        declare_robot_ip,
        declare_enable_cameras,
        declare_enable_pipeline,
        declare_enable_webgui,

        LogInfo(msg='Starting ENT Surgical Scrub Nurse system...'),

        # Core
        robot_manager_node,
        gripper_node,

        # Cameras
        cam_handeye_node,
        cam_handover_node,
        cam_endoscope_node,

        # Monitoring
        rosbridge_node,
        web_video_node,

        # TF
        static_tf_world,
    ])
