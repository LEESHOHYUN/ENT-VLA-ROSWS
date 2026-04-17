#!/usr/bin/env python3
"""
simple_record.py — Single-script camera capture + rosbag2 recording.
No usb_cam, no ros2 CLI, no daemon needed. Just OpenCV + rosbag2_py.

Usage:
    python simple_record.py                         # record cam_handover (video6)
    python simple_record.py --device 10             # record endoscope
    python simple_record.py --device 6 8 10         # record 3 cameras
    python simple_record.py --device 6 --duration 30  # record 30 seconds
"""

import argparse
import os
import signal
import sys
import time
from datetime import datetime
from pathlib import Path

import cv2
import numpy as np

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import rosbag2_py
from rclpy.serialization import serialize_message

# Device → name mapping
DEVICE_NAMES = {
    0: "cam_global",
    6: "cam_handover",
    8: "cam_side",
    10: "cam_endoscope",
}


class SimpleRecorder(Node):
    def __init__(self, device_ids, output_dir, fps, duration, preview):
        super().__init__("simple_recorder")

        self.fps = fps
        self.duration = duration
        self.preview = preview
        self.frame_count = 0
        self.start_time = time.time()
        self.running = True

        # Open cameras
        self.caps = {}
        self.cam_names = {}
        for dev_id in device_ids:
            cap = cv2.VideoCapture(dev_id, cv2.CAP_V4L2)
            if not cap.isOpened():
                self.get_logger().error(f"/dev/video{dev_id}: FAILED to open")
                continue
            cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*"MJPG"))
            cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            cap.set(cv2.CAP_PROP_FPS, fps)
            w = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
            h = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
            name = DEVICE_NAMES.get(dev_id, f"cam_{dev_id}")
            self.caps[dev_id] = cap
            self.cam_names[dev_id] = name
            self.get_logger().info(f"/dev/video{dev_id} ({name}): {w}x{h} OK")

        if not self.caps:
            self.get_logger().error("No cameras opened!")
            return

        # Setup rosbag2 writer
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        bag_path = str(Path(output_dir) / f"session_{ts}" / "rosbag2")
        Path(bag_path).parent.mkdir(parents=True, exist_ok=True)

        storage = rosbag2_py.StorageOptions(uri=bag_path, storage_id="sqlite3")
        converter = rosbag2_py.ConverterOptions(
            input_serialization_format="cdr",
            output_serialization_format="cdr",
        )
        self.writer = rosbag2_py.SequentialWriter()
        self.writer.open(storage, converter)

        # Register topics
        for dev_id, name in self.cam_names.items():
            topic = f"/{name}/image_raw"
            meta = rosbag2_py.TopicMetadata(
                name=topic, type="sensor_msgs/msg/Image", serialization_format="cdr"
            )
            self.writer.create_topic(meta)

        self.get_logger().info(f"Recording to: {bag_path}")
        self.get_logger().info(f"Cameras: {list(self.cam_names.values())}, FPS: {fps}")
        if duration > 0:
            self.get_logger().info(f"Duration: {duration}s")
        self.get_logger().info("Press Ctrl+C to stop")

        # Timer
        self.timer = self.create_timer(1.0 / fps, self.capture_callback)

    def capture_callback(self):
        if not self.running:
            return

        # Duration check
        elapsed = time.time() - self.start_time
        if self.duration > 0 and elapsed > self.duration:
            self.get_logger().info(f"Duration {self.duration}s reached. Stopping.")
            self.running = False
            return

        now_ns = self.get_clock().now().nanoseconds
        preview_frames = []

        for dev_id, cap in self.caps.items():
            ret, frame = cap.read()
            if not ret:
                continue

            name = self.cam_names[dev_id]
            topic = f"/{name}/image_raw"

            # Build Image message
            msg = Image()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = name
            msg.height, msg.width = frame.shape[:2]
            msg.encoding = "bgr8"
            msg.is_bigendian = False
            msg.step = msg.width * 3
            msg.data = frame.tobytes()

            # Write to bag
            self.writer.write(topic, serialize_message(msg), now_ns)

            if self.preview:
                small = cv2.resize(frame, (320, 240))
                cv2.putText(small, name, (5, 20),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)
                preview_frames.append(small)

        self.frame_count += 1

        # Status every 5 seconds
        if self.frame_count % (self.fps * 5) == 0:
            elapsed = time.time() - self.start_time
            actual_fps = self.frame_count / elapsed
            self.get_logger().info(
                f"Recorded {self.frame_count} frames, {actual_fps:.1f} fps, {elapsed:.0f}s"
            )

        # Preview
        if self.preview and preview_frames:
            while len(preview_frames) < 4:
                preview_frames.append(np.zeros((240, 320, 3), dtype=np.uint8))
            row1 = np.hstack(preview_frames[:2])
            row2 = np.hstack(preview_frames[2:4])
            canvas = np.vstack([row1, row2])
            cv2.imshow("Recording (q=stop)", canvas)
            if cv2.waitKey(1) & 0xFF == ord("q"):
                self.running = False

    def shutdown(self):
        self.running = False
        for cap in self.caps.values():
            cap.release()
        if hasattr(self, 'writer'):
            del self.writer
        if self.preview:
            cv2.destroyAllWindows()
        elapsed = time.time() - self.start_time
        self.get_logger().info(
            f"Done: {self.frame_count} frames in {elapsed:.1f}s "
            f"({self.frame_count/elapsed:.1f} fps)"
        )

    def destroy_node(self):
        self.shutdown()
        super().destroy_node()


def main():
    parser = argparse.ArgumentParser(description="Simple camera recorder")
    parser.add_argument("--device", "-d", nargs="+", type=int, default=[6],
                        help="Video device IDs (default: 6)")
    parser.add_argument("--fps", type=float, default=10, help="Recording FPS")
    parser.add_argument("--duration", type=float, default=0, help="Max seconds (0=unlimited)")
    parser.add_argument("--output", "-o", default="/home/hrlsh/storage/surgical/recordings",
                        help="Output directory")
    parser.add_argument("--preview", action="store_true", help="Show preview window")
    args = parser.parse_args()

    rclpy.init()
    node = SimpleRecorder(args.device, args.output, args.fps, args.duration, args.preview)

    try:
        while node.running:
            rclpy.spin_once(node, timeout_sec=0.01)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
