#!/usr/bin/env python3
"""
recorder_node.py — Multi-camera synchronized recorder for surgical VLM-VLA pipeline.

Subscribes to 4 camera image topics + auxiliary topics (VLM prompts, robot state),
synchronizes camera frames via message_filters.ApproximateTimeSynchronizer,
and writes to rosbag2 (default) + optional HDF5.

Usage (standalone):
    ros2 run ros2_recorder recorder_node --ros-args --params-file config/recorder_config.yaml

Usage (launch):
    ros2 launch ros2_recorder multi_camera_recorder.launch.py
"""

import os
import time
from datetime import datetime
from pathlib import Path

import yaml
import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from sensor_msgs.msg import Image, CompressedImage
from std_msgs.msg import String, Float32, Float32MultiArray
from geometry_msgs.msg import PoseStamped

import message_filters

# rosbag2 writer
import rosbag2_py
from rclpy.serialization import serialize_message

# Optional HDF5
try:
    import h5py
    HDF5_AVAILABLE = True
except ImportError:
    HDF5_AVAILABLE = False


# Map string msg types to actual classes for extra_topics
MSG_TYPE_MAP = {
    "std_msgs/msg/String": String,
    "std_msgs/msg/Float32": Float32,
    "std_msgs/msg/Float32MultiArray": Float32MultiArray,
    "geometry_msgs/msg/PoseStamped": PoseStamped,
    "sensor_msgs/msg/Image": Image,
    "sensor_msgs/msg/CompressedImage": CompressedImage,
}


class MultiCameraRecorder(Node):
    """
    ROS2 node that synchronizes multiple camera feeds and records all
    topics to rosbag2 and optionally HDF5.
    """

    def __init__(self):
        super().__init__("multi_camera_recorder")

        # Load config
        config_path = self.declare_parameter("config_file", "").value
        if not config_path:
            # Default: look next to this file's package
            config_path = str(
                Path(__file__).resolve().parent.parent / "config" / "recorder_config.yaml"
            )
        self._cfg = self._load_config(config_path)
        rec_cfg = self._cfg["recording"]
        img_cfg = self._cfg.get("image", {})

        # Session directory
        self._session_dir = self._create_session_dir(rec_cfg["output_dir"])
        self.get_logger().info(f"Recording session: {self._session_dir}")

        # QoS: use SYSTEM_DEFAULT which auto-matches publisher's QoS.
        # usb_cam publishes RELIABLE; other drivers may use BEST_EFFORT.
        # SYSTEM_DEFAULT handles both without manual matching.
        img_qos = QoSProfile(
            reliability=ReliabilityPolicy.SYSTEM_DEFAULT,
            durability=DurabilityPolicy.VOLATILE,
            history=HistoryPolicy.KEEP_LAST,
            depth=rec_cfg.get("queue_size", 30),
        )
        reliable_qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=rec_cfg.get("queue_size", 30),
        )

        # Determine image message type
        transport = img_cfg.get("transport", "raw")
        self._img_msg_type = CompressedImage if transport == "compressed" else Image

        # ---- Camera subscribers (for synchronization) ----
        self._cam_subs = []     # message_filters.Subscriber objects
        self._cam_names = []    # camera names in order
        self._cam_topics = []   # topic strings in order

        for cam in self._cfg["cameras"]:
            if not cam.get("enabled", True):
                continue
            topic = cam["topic"]
            if transport == "compressed":
                topic = topic + "/compressed"

            sub = message_filters.Subscriber(self, self._img_msg_type, topic, qos_profile=img_qos)
            self._cam_subs.append(sub)
            self._cam_names.append(cam["name"])
            self._cam_topics.append(cam["topic"])
            self.get_logger().info(f"Camera: {cam['name']} -> {topic}")

        if not self._cam_subs:
            self.get_logger().error("No cameras enabled — nothing to record")
            return

        # Per-camera debug counters (to verify individual cameras are receiving)
        self._cam_msg_counts = {name: 0 for name in self._cam_names}
        for i, sub in enumerate(self._cam_subs):
            name = self._cam_names[i]
            topic = self._cam_topics[i]
            # Also create a direct subscriber to count per-camera messages
            self.create_subscription(
                self._img_msg_type, topic,
                lambda msg, n=name: self._cam_debug_callback(n),
                img_qos,
            )

        # ApproximateTimeSynchronizer across all enabled cameras
        sync_slop = rec_cfg.get("sync_slop_sec", 0.5)
        queue_size = rec_cfg.get("queue_size", 30)
        self._sync = message_filters.ApproximateTimeSynchronizer(
            self._cam_subs, queue_size, sync_slop
        )
        self._sync.registerCallback(self._synced_callback)
        self.get_logger().info(
            f"Synchronized {len(self._cam_subs)} cameras, "
            f"slop={sync_slop}s, target={rec_cfg['sync_rate_hz']}Hz"
        )

        # ---- Extra topic subscribers (recorded independently, not synced) ----
        self._extra_subs = []
        for extra in self._cfg.get("extra_topics", []):
            if not extra.get("enabled", True):
                continue
            msg_type_str = extra["msg_type"]
            msg_cls = MSG_TYPE_MAP.get(msg_type_str)
            if msg_cls is None:
                self.get_logger().warn(f"Unknown msg type '{msg_type_str}', skipping {extra['topic']}")
                continue

            sub = self.create_subscription(
                msg_cls, extra["topic"],
                lambda msg, t=extra["topic"], mc=msg_cls: self._extra_topic_callback(msg, t, mc),
                reliable_qos,
            )
            self._extra_subs.append(sub)
            self.get_logger().info(f"Extra topic: {extra['topic']} ({msg_type_str})")

        # ---- rosbag2 writer ----
        self._bag_writer = None
        out_cfg = rec_cfg.get("output", {})
        if out_cfg.get("rosbag2", {}).get("enabled", True):
            self._init_bag_writer(out_cfg["rosbag2"])

        # ---- HDF5 writer ----
        self._hdf5_file = None
        self._hdf5_datasets = {}
        self._hdf5_flush_interval = 50
        if out_cfg.get("hdf5", {}).get("enabled", False):
            self._init_hdf5_writer(out_cfg["hdf5"])

        # ---- Rate limiting ----
        target_hz = rec_cfg.get("sync_rate_hz", 5)
        self._min_interval = 1.0 / target_hz
        self._last_sync_time = 0.0

        # ---- Stats ----
        self._frame_count = 0
        self._start_time = time.time()
        self._max_duration = rec_cfg.get("max_duration_sec", 0)
        self._status_interval = rec_cfg.get("status_interval_sec", 10)
        self._last_status_time = time.time()

        # Status timer
        self.create_timer(self._status_interval, self._status_timer_callback)

        self.get_logger().info("Recorder initialized — waiting for camera data...")

    # ---- Config ----

    def _load_config(self, path: str) -> dict:
        p = Path(path)
        if not p.exists():
            self.get_logger().error(f"Config not found: {path}")
            raise FileNotFoundError(f"Config not found: {path}")
        with open(p) as f:
            cfg = yaml.safe_load(f)
        self.get_logger().info(f"Loaded config: {path}")
        return cfg

    def _create_session_dir(self, base_dir: str) -> Path:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        session_dir = Path(base_dir) / f"session_{ts}"
        session_dir.mkdir(parents=True, exist_ok=True)
        return session_dir

    # ---- rosbag2 ----

    def _init_bag_writer(self, bag_cfg: dict):
        storage_id = bag_cfg.get("storage_id", "sqlite3")
        bag_path = str(self._session_dir / "rosbag2")

        storage_options = rosbag2_py.StorageOptions(
            uri=bag_path,
            storage_id=storage_id,
        )
        converter_options = rosbag2_py.ConverterOptions(
            input_serialization_format="cdr",
            output_serialization_format="cdr",
        )

        self._bag_writer = rosbag2_py.SequentialWriter()
        self._bag_writer.open(storage_options, converter_options)

        # Register camera image topics
        img_type_str = (
            "sensor_msgs/msg/CompressedImage"
            if self._img_msg_type == CompressedImage
            else "sensor_msgs/msg/Image"
        )
        for topic in self._cam_topics:
            topic_meta = rosbag2_py.TopicMetadata(
                name=topic, type=img_type_str, serialization_format="cdr"
            )
            self._bag_writer.create_topic(topic_meta)

        # Register extra topics
        for extra in self._cfg.get("extra_topics", []):
            if not extra.get("enabled", True):
                continue
            topic_meta = rosbag2_py.TopicMetadata(
                name=extra["topic"],
                type=extra["msg_type"],
                serialization_format="cdr",
            )
            self._bag_writer.create_topic(topic_meta)

        self.get_logger().info(f"rosbag2 writer: {bag_path} (storage={storage_id})")

    def _write_to_bag(self, topic: str, msg, timestamp_ns: int):
        if self._bag_writer is None:
            return
        self._bag_writer.write(topic, serialize_message(msg), timestamp_ns)

    # ---- HDF5 ----

    def _init_hdf5_writer(self, hdf5_cfg: dict):
        if not HDF5_AVAILABLE:
            self.get_logger().warn("h5py not installed — HDF5 output disabled")
            return

        hdf5_path = self._session_dir / "recording.h5"
        self._hdf5_file = h5py.File(str(hdf5_path), "w")
        self._hdf5_flush_interval = hdf5_cfg.get("flush_interval", 50)

        # Create groups for each camera (datasets created on first frame)
        for name in self._cam_names:
            self._hdf5_file.create_group(name)

        # Timestamps dataset
        self._hdf5_file.create_dataset(
            "timestamps", shape=(0,), maxshape=(None,), dtype="float64"
        )

        self.get_logger().info(f"HDF5 writer: {hdf5_path}")

    def _write_to_hdf5(self, cam_images: dict, timestamp: float):
        """Write synchronized camera frames to HDF5."""
        if self._hdf5_file is None:
            return

        idx = self._frame_count

        # Append timestamp
        ts_ds = self._hdf5_file["timestamps"]
        ts_ds.resize((idx + 1,))
        ts_ds[idx] = timestamp

        # Append each camera image
        for cam_name, img_array in cam_images.items():
            grp = self._hdf5_file[cam_name]
            ds_name = "images"
            if ds_name not in grp:
                h, w = img_array.shape[:2]
                c = img_array.shape[2] if img_array.ndim == 3 else 1
                grp.create_dataset(
                    ds_name,
                    shape=(0, h, w, c),
                    maxshape=(None, h, w, c),
                    dtype="uint8",
                    chunks=(1, h, w, c),
                    compression="gzip",
                    compression_opts=1,
                )
            ds = grp[ds_name]
            ds.resize((idx + 1, *ds.shape[1:]))
            ds[idx] = img_array if img_array.ndim == 3 else img_array[..., np.newaxis]

        if (idx + 1) % self._hdf5_flush_interval == 0:
            self._hdf5_file.flush()

    # ---- Synchronized callback (cameras) ----

    def _synced_callback(self, *msgs):
        """Called when all enabled cameras have a time-synchronized frame."""
        now = time.time()

        # Rate limiting
        if (now - self._last_sync_time) < self._min_interval:
            return
        self._last_sync_time = now

        # Max duration check
        if self._max_duration > 0 and (now - self._start_time) > self._max_duration:
            self.get_logger().info(
                f"Max duration {self._max_duration}s reached — stopping recorder"
            )
            self._shutdown()
            raise SystemExit(0)

        timestamp_ns = self.get_clock().now().nanoseconds
        cam_images = {}

        for i, msg in enumerate(msgs):
            topic = self._cam_topics[i]
            cam_name = self._cam_names[i]

            # Write to rosbag2
            self._write_to_bag(topic, msg, timestamp_ns)

            # Decode image for HDF5 if enabled
            if self._hdf5_file is not None:
                img_array = self._decode_image_msg(msg)
                if img_array is not None:
                    cam_images[cam_name] = img_array

        # Write to HDF5
        if cam_images:
            self._write_to_hdf5(cam_images, timestamp_ns / 1e9)

        self._frame_count += 1

    # ---- Extra topic callback (non-synced) ----

    def _extra_topic_callback(self, msg, topic: str, msg_cls):
        timestamp_ns = self.get_clock().now().nanoseconds
        self._write_to_bag(topic, msg, timestamp_ns)

    # ---- Image decoding ----

    def _decode_image_msg(self, msg) -> np.ndarray | None:
        """Convert sensor_msgs/Image or CompressedImage to numpy array."""
        try:
            if isinstance(msg, Image):
                # Raw image: reshape from flat data
                h, w = msg.height, msg.width
                if msg.encoding in ("rgb8", "bgr8"):
                    return np.frombuffer(msg.data, dtype=np.uint8).reshape(h, w, 3)
                elif msg.encoding in ("mono8",):
                    return np.frombuffer(msg.data, dtype=np.uint8).reshape(h, w)
                elif msg.encoding in ("16UC1",):
                    return np.frombuffer(msg.data, dtype=np.uint16).reshape(h, w)
                else:
                    # Fallback: try as 3-channel
                    return np.frombuffer(msg.data, dtype=np.uint8).reshape(h, w, -1)
            elif isinstance(msg, CompressedImage):
                import cv2
                buf = np.frombuffer(msg.data, dtype=np.uint8)
                return cv2.imdecode(buf, cv2.IMREAD_COLOR)
        except Exception as e:
            self.get_logger().warn(f"Image decode failed: {e}")
        return None

    # ---- Debug ----

    def _cam_debug_callback(self, cam_name: str):
        self._cam_msg_counts[cam_name] += 1

    # ---- Status ----

    def _status_timer_callback(self):
        elapsed = time.time() - self._start_time
        fps = self._frame_count / elapsed if elapsed > 0 else 0.0

        # Per-camera counts
        cam_status = ", ".join(
            f"{name}={count}" for name, count in self._cam_msg_counts.items()
        )
        self.get_logger().info(
            f"Recording: {self._frame_count} synced frames, "
            f"{fps:.1f} fps, {elapsed:.0f}s elapsed | "
            f"Per-cam msgs: [{cam_status}]"
        )

    # ---- Shutdown ----

    def _shutdown(self):
        if self._bag_writer is not None:
            del self._bag_writer
            self._bag_writer = None
            self.get_logger().info("rosbag2 writer closed")

        if self._hdf5_file is not None:
            self._hdf5_file.flush()
            self._hdf5_file.close()
            self._hdf5_file = None
            self.get_logger().info("HDF5 writer closed")

        self.get_logger().info(
            f"Session complete: {self._frame_count} frames -> {self._session_dir}"
        )

    def destroy_node(self):
        self._shutdown()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = MultiCameraRecorder()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, SystemExit):
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
