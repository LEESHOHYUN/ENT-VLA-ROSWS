#!/usr/bin/env python3
"""
cam_viewer.py — View all connected cameras in a single tiled window.
Press 'q' to quit, 's' to save a snapshot.

Usage:
    python3 cam_viewer.py
    python3 cam_viewer.py --devices 0 6 8 10
"""

import argparse
import sys
import time

import cv2
import numpy as np


# Default device mapping (even-numbered = capture, odd = metadata on most UVC cams)
DEFAULT_DEVICES = {
    0: "RealSense (Global)",
    6: "ABKO QHD (Handover)",
    8: "C920 HD (Side)",
    10: "USB Endoscope",
}

TILE_SIZE = (480, 640)  # (h, w) per tile


def open_cameras(device_ids: list[int]) -> dict[int, cv2.VideoCapture]:
    caps = {}
    for dev_id in device_ids:
        cap = cv2.VideoCapture(dev_id, cv2.CAP_V4L2)
        if cap.isOpened():
            # Prefer MJPEG for higher resolution/fps
            cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*"MJPG"))
            cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            cap.set(cv2.CAP_PROP_FPS, 15)
            w = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
            h = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
            print(f"  /dev/video{dev_id}: {w}x{h} OK")
            caps[dev_id] = cap
        else:
            print(f"  /dev/video{dev_id}: FAILED to open")
    return caps


def tile_frames(frames: list[np.ndarray], labels: list[str]) -> np.ndarray:
    """Arrange frames in a 2x2 grid with labels."""
    tiles = []
    for frame, label in zip(frames, labels):
        resized = cv2.resize(frame, (TILE_SIZE[1], TILE_SIZE[0]))
        # Label overlay
        cv2.putText(
            resized, label, (10, 30),
            cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2,
        )
        tiles.append(resized)

    # Pad to 4 tiles if fewer cameras
    while len(tiles) < 4:
        blank = np.zeros((TILE_SIZE[0], TILE_SIZE[1], 3), dtype=np.uint8)
        cv2.putText(blank, "No camera", (180, 240),
                    cv2.FONT_HERSHEY_SIMPLEX, 1.0, (80, 80, 80), 2)
        tiles.append(blank)

    row1 = np.hstack(tiles[:2])
    row2 = np.hstack(tiles[2:4])
    return np.vstack([row1, row2])


def main():
    parser = argparse.ArgumentParser(description="View all cameras in tiled window")
    parser.add_argument(
        "--devices", nargs="+", type=int,
        default=list(DEFAULT_DEVICES.keys()),
        help="Video device IDs (e.g. 0 6 8 10)",
    )
    args = parser.parse_args()

    print("Opening cameras...")
    caps = open_cameras(args.devices)

    if not caps:
        print("No cameras opened. Check connections.")
        sys.exit(1)

    print(f"\n{len(caps)} cameras active. Press 'q' to quit, 's' to snapshot.\n")

    frame_count = 0
    fps_time = time.time()

    while True:
        frames = []
        labels = []

        for dev_id in args.devices:
            if dev_id in caps:
                ret, frame = caps[dev_id].read()
                if ret:
                    frames.append(frame)
                    labels.append(DEFAULT_DEVICES.get(dev_id, f"video{dev_id}"))
                else:
                    frames.append(np.zeros((TILE_SIZE[0], TILE_SIZE[1], 3), dtype=np.uint8))
                    labels.append(f"video{dev_id} (no frame)")

        if not frames:
            break

        canvas = tile_frames(frames, labels)

        # FPS counter
        frame_count += 1
        elapsed = time.time() - fps_time
        if elapsed > 1.0:
            fps = frame_count / elapsed
            frame_count = 0
            fps_time = time.time()
            cv2.putText(canvas, f"{fps:.1f} FPS", (canvas.shape[1] - 150, 30),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 0), 2)

        cv2.imshow("Surgical Cameras (q=quit, s=snapshot)", canvas)

        key = cv2.waitKey(1) & 0xFF
        if key == ord("q"):
            break
        elif key == ord("s"):
            ts = time.strftime("%Y%m%d_%H%M%S")
            path = f"/home/hrlsh/storage/surgical/snapshot_{ts}.jpg"
            cv2.imwrite(path, canvas)
            print(f"Snapshot saved: {path}")

    for cap in caps.values():
        cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
