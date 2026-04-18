#!/usr/bin/env python3
"""
UR5e Robot Monitor & Slider Control (ROS2 topic pub/sub, no action server)

GUI(Python) → ROS2 topic → C++ ur_robot_manager_node → ur_rtde → UR5e

Command topics (publish):
  /cmd/move_j         Float64MultiArray  → C++ moveJ
  /cmd/custom_move_l  Float64MultiArray  → C++ customMoveL (IK8→moveJ)
  /cmd/home           Bool               → C++ home
  /cmd/stop           Bool               → C++ emergencyStop
  /speed_scale        Float64MultiArray  → C++ speed_scale_

Monitor topics (subscribe):
  /joint_states       JointState
  /tcp_pose           Float64MultiArray
  /tcp_wrench         WrenchStamped
  /robot_status       String

Usage:
  ros2 launch nurse_bringup robot_only_launch.py   # terminal 1
  python3 robot_monitor.py                          # terminal 2
"""

import json
import math
import os
import threading
import time
import tkinter as tk
from tkinter import ttk, filedialog

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import WrenchStamped
from std_msgs.msg import Float64MultiArray, String, Bool

JOINT_NAMES = ["shoulder_pan", "shoulder_lift", "elbow",
               "wrist_1", "wrist_2", "wrist_3"]
UPDATE_RATE_MS = 50


class MonitorNode(Node):
    def __init__(self):
        super().__init__("robot_monitor_gui")

        self.joint_positions = [0.0] * 6
        self.joint_velocities = [0.0] * 6
        self.tcp_pose = [0.0] * 6
        self.tcp_force = [0.0] * 6
        self.robot_status = "waiting..."
        self.is_moving = False

        # Subscribe
        self.create_subscription(JointState, "/joint_states", self._joint_cb, 10)
        self.create_subscription(Float64MultiArray, "/tcp_pose", self._tcp_cb, 10)
        self.create_subscription(WrenchStamped, "/tcp_wrench", self._wrench_cb, 10)
        self.create_subscription(String, "/robot_status", self._status_cb, 10)
        self.create_subscription(Bool, "/is_moving", self._moving_cb, 10)

        # Publish (commands)
        self.pub_movej = self.create_publisher(Float64MultiArray, "/cmd/move_j", 10)
        self.pub_custom_movel = self.create_publisher(Float64MultiArray, "/cmd/custom_move_l", 10)
        self.pub_home = self.create_publisher(Bool, "/cmd/home", 10)
        self.pub_stop = self.create_publisher(Bool, "/cmd/stop", 10)
        self.pub_speed = self.create_publisher(Float64MultiArray, "/speed_scale", 10)
        self.pub_freedrive = self.create_publisher(Bool, "/cmd/freedrive", 10)
        self.pub_reconnect = self.create_publisher(Bool, "/cmd/reconnect", 10)

    def _joint_cb(self, msg):
        if msg.position:
            self.joint_positions = list(msg.position[:6])
        if msg.velocity:
            self.joint_velocities = list(msg.velocity[:6])

    def _tcp_cb(self, msg):
        if msg.data:
            self.tcp_pose = list(msg.data[:6])

    def _wrench_cb(self, msg):
        self.tcp_force = [
            msg.wrench.force.x, msg.wrench.force.y, msg.wrench.force.z,
            msg.wrench.torque.x, msg.wrench.torque.y, msg.wrench.torque.z,
        ]

    def _status_cb(self, msg):
        self.robot_status = msg.data

    def _moving_cb(self, msg):
        self.is_moving = msg.data

    # -- Command publishers --
    def send_movej(self, joints):
        msg = Float64MultiArray()
        msg.data = joints
        self.pub_movej.publish(msg)

    def send_custom_movel(self, tcp_target):
        msg = Float64MultiArray()
        msg.data = tcp_target
        self.pub_custom_movel.publish(msg)

    def send_home(self):
        self.pub_home.publish(Bool(data=True))

    def send_stop(self):
        self.pub_stop.publish(Bool(data=True))

    def send_speed_scale(self, scale):
        msg = Float64MultiArray()
        msg.data = [scale]
        self.pub_speed.publish(msg)

    def send_freedrive(self, enable):
        self.pub_freedrive.publish(Bool(data=enable))

    def send_reconnect(self):
        self.pub_reconnect.publish(Bool(data=True))


class RobotMonitorApp:
    def __init__(self, root, ros_node):
        self.root = root
        self.root.title("UR5e Monitor (ROS2 Topic)")
        self.root.geometry("900x1100")
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)

        self.node = ros_node
        self.running = True
        self.slider_active = False
        self.tcp_slider_active = False
        self.speed_scale = 0.3

        # Freedrive / trajectory recording state
        self.freedrive_on = False
        self.recording = False
        self.recorded_trajectory = []  # list of {"t", "q", "tcp"}
        self.record_t0 = 0.0

        self._build_gui()
        self._start_monitoring()

    def _build_gui(self):
        # -- Status --
        sf = ttk.Frame(self.root, padding=5)
        sf.pack(fill="x")
        self.status_var = tk.StringVar(value="Waiting for C++ node...")
        ttk.Label(sf, textvariable=self.status_var,
                  font=("monospace", 10, "bold")).pack(side="left")

        # -- TCP Position --
        tcp_f = ttk.LabelFrame(self.root, text="TCP Position", padding=8)
        tcp_f.pack(fill="x", padx=8, pady=3)
        self.tcp_vars = {}
        for i, n in enumerate(["X", "Y", "Z", "Rx", "Ry", "Rz"]):
            ttk.Label(tcp_f, text=f"{n}:").grid(row=i//3, column=(i%3)*2, sticky="e", padx=4, pady=2)
            v = tk.StringVar(value="—")
            ttk.Label(tcp_f, textvariable=v, width=12, font=("monospace", 10)).grid(
                row=i//3, column=(i%3)*2+1, sticky="w", padx=4)
            self.tcp_vars[n] = v

        # -- Force/Torque --
        ft_f = ttk.LabelFrame(self.root, text="TCP Force / Torque", padding=8)
        ft_f.pack(fill="x", padx=8, pady=3)
        self.ft_vars = {}
        for i, n in enumerate(["Fx", "Fy", "Fz", "Tx", "Ty", "Tz"]):
            ttk.Label(ft_f, text=f"{n}:").grid(row=i//3, column=(i%3)*2, sticky="e", padx=4, pady=2)
            v = tk.StringVar(value="—")
            ttk.Label(ft_f, textvariable=v, width=12, font=("monospace", 10)).grid(
                row=i//3, column=(i%3)*2+1, sticky="w", padx=4)
            self.ft_vars[n] = v

        # -- Joints --
        jf = ttk.LabelFrame(self.root, text="Joint Positions", padding=8)
        jf.pack(fill="x", padx=8, pady=3)
        for c, t in enumerate(["Joint", "Rad", "Deg", "Vel"]):
            ttk.Label(jf, text=t, font=("", 9, "bold")).grid(row=0, column=c)
        self.jrad, self.jdeg, self.jvel = [], [], []
        for i in range(6):
            ttk.Label(jf, text=JOINT_NAMES[i]).grid(row=i+1, column=0, sticky="e", padx=4)
            for lst in [self.jrad, self.jdeg, self.jvel]:
                v = tk.StringVar(value="—")
                col = [self.jrad, self.jdeg, self.jvel].index(lst) + 1
                ttk.Label(jf, textvariable=v, width=10, font=("monospace", 10)).grid(
                    row=i+1, column=col, padx=4)
                lst.append(v)

        # -- Joint Sliders → /cmd/move_j --
        jsf = ttk.LabelFrame(self.root, text="Joint Slider → /cmd/move_j", padding=8)
        jsf.pack(fill="x", padx=8, pady=3)
        self.jsliders = []
        for i in range(6):
            ttk.Label(jsf, text=f"J{i+1}:").grid(row=i, column=0, sticky="e", padx=4)
            v = tk.DoubleVar(value=0.0)
            s = ttk.Scale(jsf, from_=-3.14, to=3.14, orient="horizontal", length=350, variable=v)
            s.grid(row=i, column=1, padx=4, pady=1, sticky="ew")
            s.bind("<ButtonPress-1>", lambda e: setattr(self, 'slider_active', True))
            s.bind("<ButtonRelease-1>", lambda e: self._on_j_release())
            self.jsliders.append(v)
        jsf.columnconfigure(1, weight=1)

        # -- TCP Sliders → /cmd/custom_move_l --
        tsf = ttk.LabelFrame(self.root, text="TCP Slider → /cmd/custom_move_l (IK→moveJ)", padding=8)
        tsf.pack(fill="x", padx=8, pady=3)
        tcp_names = ["X(m)", "Y(m)", "Z(m)", "Rx", "Ry", "Rz"]
        tcp_ranges = [(-0.8,0.8),(-0.8,0.8),(0.0,0.8),(-3.14,3.14),(-3.14,3.14),(-3.14,3.14)]
        self.tsliders = []
        for i in range(6):
            ttk.Label(tsf, text=f"{tcp_names[i]}:").grid(row=i, column=0, sticky="e", padx=4)
            v = tk.DoubleVar(value=0.0)
            lo, hi = tcp_ranges[i]
            s = ttk.Scale(tsf, from_=lo, to=hi, orient="horizontal", length=350, variable=v)
            s.grid(row=i, column=1, padx=4, pady=1, sticky="ew")
            s.bind("<ButtonPress-1>", lambda e: setattr(self, 'tcp_slider_active', True))
            s.bind("<ButtonRelease-1>", lambda e: self._on_tcp_release())
            self.tsliders.append(v)
        tsf.columnconfigure(1, weight=1)

        # -- Controls --
        cf = ttk.Frame(self.root, padding=8)
        cf.pack(fill="x", padx=8, pady=3)
        ttk.Label(cf, text="Speed:").pack(side="left")
        self.speed_var = tk.DoubleVar(value=self.speed_scale)
        ttk.Scale(cf, from_=0.05, to=1.0, orient="horizontal", length=150,
                  variable=self.speed_var, command=self._on_speed).pack(side="left", padx=5)
        self.speed_lbl = tk.StringVar(value=f"{self.speed_scale:.0%}")
        ttk.Label(cf, textvariable=self.speed_lbl, width=5).pack(side="left")
        ttk.Button(cf, text="Sync", command=self._sync).pack(side="left", padx=10)
        ttk.Button(cf, text="Home", command=lambda: (self.node.send_home(), self.log("→ Home"))).pack(side="left", padx=5)
        style = ttk.Style()
        style.configure("Stop.TButton", foreground="red", font=("", 10, "bold"))
        ttk.Button(cf, text="STOP", command=lambda: (self.node.send_stop(), self.log("STOP")),
                   style="Stop.TButton").pack(side="right", padx=5)
        ttk.Button(cf, text="Reconnect",
                   command=lambda: (self.node.send_reconnect(), self.log("→ Reconnect control"))
                   ).pack(side="right", padx=5)

        # -- Freedrive / Trajectory Recording --
        ff = ttk.LabelFrame(self.root, text="Freedrive (Kinesthetic Teaching)", padding=8)
        ff.pack(fill="x", padx=8, pady=3)

        self.freedrive_var = tk.BooleanVar(value=False)
        self.freedrive_cb = ttk.Checkbutton(
            ff, text="Freedrive Mode", variable=self.freedrive_var,
            command=self._on_freedrive_toggle)
        self.freedrive_cb.grid(row=0, column=0, padx=5)

        self.rec_btn = ttk.Button(ff, text="Record", command=self._on_record)
        self.rec_btn.grid(row=0, column=1, padx=5)

        self.save_btn = ttk.Button(ff, text="Save", command=self._on_save, state="disabled")
        self.save_btn.grid(row=0, column=2, padx=5)

        self.rec_status_var = tk.StringVar(value="")
        ttk.Label(ff, textvariable=self.rec_status_var,
                  font=("monospace", 9)).grid(row=0, column=3, padx=10, sticky="w")

        self.hz_var = tk.IntVar(value=10)
        ttk.Label(ff, text="Hz:").grid(row=0, column=4, padx=(10,2))
        hz_spin = ttk.Spinbox(ff, from_=1, to=50, width=4, textvariable=self.hz_var)
        hz_spin.grid(row=0, column=5, padx=2)

        # -- Log --
        lf = ttk.LabelFrame(self.root, text="Log", padding=5)
        lf.pack(fill="both", expand=True, padx=8, pady=3)
        self.log_text = tk.Text(lf, height=5, width=80, font=("monospace", 9))
        self.log_text.pack(fill="both", expand=True)
        sb = ttk.Scrollbar(self.log_text, command=self.log_text.yview)
        sb.pack(side="right", fill="y")
        self.log_text.config(yscrollcommand=sb.set)

    # =================================================================
    # Display update
    # =================================================================
    def _start_monitoring(self):
        self._update()

    def _update(self):
        if not self.running:
            return

        q = self.node.joint_positions
        qd = self.node.joint_velocities
        tcp = self.node.tcp_pose
        ft = self.node.tcp_force

        for i, n in enumerate(["X","Y","Z","Rx","Ry","Rz"]):
            u = " m" if i < 3 else " rad"
            self.tcp_vars[n].set(f"{tcp[i]:+.4f}{u}")
        for i, n in enumerate(["Fx","Fy","Fz","Tx","Ty","Tz"]):
            u = " N" if i < 3 else " Nm"
            self.ft_vars[n].set(f"{ft[i]:+.2f}{u}")
        for i in range(6):
            self.jrad[i].set(f"{q[i]:+.4f}")
            self.jdeg[i].set(f"{q[i]*180/math.pi:+.2f}°")
            self.jvel[i].set(f"{qd[i]:+.4f}")

        if not self.slider_active:
            for i in range(6):
                self.jsliders[i].set(q[i])
        if not self.tcp_slider_active:
            for i in range(6):
                self.tsliders[i].set(tcp[i])

        self.status_var.set(f"{self.node.robot_status} | moving={self.node.is_moving}")
        self.root.after(UPDATE_RATE_MS, self._update)

    # =================================================================
    # Slider → topic publish
    # =================================================================
    def _on_j_release(self):
        self.slider_active = False
        target = [self.jsliders[i].get() for i in range(6)]
        self.log(f"→ /cmd/move_j [{', '.join(f'{v:.2f}' for v in target)}]")
        self.node.send_movej(target)

    def _on_tcp_release(self):
        self.tcp_slider_active = False
        target = [self.tsliders[i].get() for i in range(6)]
        self.log(f"→ /cmd/custom_move_l [{', '.join(f'{v:.4f}' for v in target)}]")
        self.node.send_custom_movel(target)

    def _on_speed(self, val):
        self.speed_scale = float(val)
        self.speed_lbl.set(f"{self.speed_scale:.0%}")
        self.node.send_speed_scale(self.speed_scale)

    def _sync(self):
        q = self.node.joint_positions
        tcp = self.node.tcp_pose
        for i in range(6):
            self.jsliders[i].set(q[i])
            self.tsliders[i].set(tcp[i])
        self.log("Synced.")

    # =================================================================
    # Freedrive / Trajectory recording
    # =================================================================
    def _on_freedrive_toggle(self):
        self.freedrive_on = self.freedrive_var.get()
        self.node.send_freedrive(self.freedrive_on)
        if self.freedrive_on:
            self.log("Freedrive ON")
        else:
            self.log("Freedrive OFF")
            if self.recording:
                self._stop_recording()

    def _on_record(self):
        if not self.recording:
            self._start_recording()
        else:
            self._stop_recording()

    def _start_recording(self):
        if not self.freedrive_on:
            self.freedrive_var.set(True)
            self._on_freedrive_toggle()

        self.recorded_trajectory = []
        self.record_t0 = time.time()
        self.recording = True
        self.rec_btn.configure(text="Stop")
        self.save_btn.configure(state="disabled")
        self.log("Recording started...")
        self._record_tick()

    def _stop_recording(self):
        self.recording = False
        self.rec_btn.configure(text="Record")
        n = len(self.recorded_trajectory)
        if n > 0:
            dur = self.recorded_trajectory[-1]["t"]
            self.rec_status_var.set(f"{n} pts, {dur:.1f}s")
            self.save_btn.configure(state="normal")
            self.log(f"Recording stopped: {n} points, {dur:.1f}s")
        else:
            self.rec_status_var.set("")
            self.log("Recording stopped: empty")

    def _record_tick(self):
        if not self.recording:
            return
        q = list(self.node.joint_positions)
        tcp = list(self.node.tcp_pose)
        t = time.time() - self.record_t0
        self.recorded_trajectory.append({"t": round(t, 4), "q": q, "tcp": tcp})
        self.rec_status_var.set(f"REC {len(self.recorded_trajectory)} pts, {t:.1f}s")

        interval_ms = max(20, int(1000 / self.hz_var.get()))
        self.root.after(interval_ms, self._record_tick)

    def _on_save(self):
        if not self.recorded_trajectory:
            return
        default_name = f"traj_{time.strftime('%Y%m%d_%H%M%S')}.json"
        default_dir = os.path.expanduser("~/scrub_nurse_ws/data/trajectories")
        os.makedirs(default_dir, exist_ok=True)
        fpath = filedialog.asksaveasfilename(
            initialdir=default_dir,
            initialfile=default_name,
            defaultextension=".json",
            filetypes=[("JSON", "*.json"), ("All", "*.*")])
        if not fpath:
            return
        data = {
            "hz": self.hz_var.get(),
            "num_points": len(self.recorded_trajectory),
            "duration_sec": self.recorded_trajectory[-1]["t"],
            "trajectory": self.recorded_trajectory,
        }
        with open(fpath, "w") as f:
            json.dump(data, f, indent=2)
        self.log(f"Saved → {fpath}")

    def log(self, msg):
        self.log_text.insert(tk.END, f"[{time.strftime('%H:%M:%S')}] {msg}\n")
        self.log_text.see(tk.END)

    def on_close(self):
        self.running = False
        self.root.destroy()


def main():
    rclpy.init()
    ros_node = MonitorNode()
    spin_thread = threading.Thread(target=rclpy.spin, args=(ros_node,), daemon=True)
    spin_thread.start()

    root = tk.Tk()
    app = RobotMonitorApp(root, ros_node)
    root.mainloop()

    ros_node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
