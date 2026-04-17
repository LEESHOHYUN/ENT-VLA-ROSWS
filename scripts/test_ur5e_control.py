#!/usr/bin/env python3
"""
UR5e 간단 제어 테스트 (ur_rtde 직접 사용, ROS2 불필요)

사용법:
  python3 test_ur5e_control.py                    # 상태 읽기만
  python3 test_ur5e_control.py --home              # 홈 위치 이동
  python3 test_ur5e_control.py --movel 0.3 -0.2 0.4 3.14 0 0  # TCP 이동
  python3 test_ur5e_control.py --ip 192.168.10.126  # IP 지정

주의: 로봇이 실제로 움직입니다. 주변 안전을 확인하세요.
"""

import argparse
import sys
import time

try:
    from rtde_control import RTDEControlInterface
    from rtde_receive import RTDEReceiveInterface
    from rtde_io import RTDEIOInterface
except ImportError:
    print("Error: ur_rtde 파이썬 바인딩을 찾을 수 없습니다.")
    print("설치: pip install ur-rtde  또는  ~/ur_rtde에서 빌드")
    sys.exit(1)

DEFAULT_IP = "192.168.10.126"

# 안전 제한
MAX_LINEAR_SPEED = 0.15    # m/s
MAX_JOINT_SPEED = 0.5      # rad/s
MAX_ACCELERATION = 0.5     # rad/s^2 or m/s^2

# 홈 포즈 (joint space, radians)
HOME_JOINTS = [0.0, -1.5708, 0.0, -1.5708, 0.0, 0.0]


def print_robot_state(rtde_r):
    """현재 로봇 상태 출력"""
    q = rtde_r.getActualQ()
    tcp = rtde_r.getActualTCPPose()
    force = rtde_r.getActualTCPForce()
    speed = rtde_r.getActualTCPSpeed()

    print("\n=== UR5e State ===")
    print(f"Joint positions (rad):")
    for i, name in enumerate(["shoulder_pan", "shoulder_lift", "elbow",
                               "wrist_1", "wrist_2", "wrist_3"]):
        print(f"  {name:15s}: {q[i]:+8.4f} rad  ({q[i]*180/3.14159:+8.2f} deg)")

    print(f"\nTCP pose:")
    print(f"  Position : x={tcp[0]:+.4f}, y={tcp[1]:+.4f}, z={tcp[2]:+.4f} (m)")
    print(f"  Rotation : rx={tcp[3]:+.4f}, ry={tcp[4]:+.4f}, rz={tcp[5]:+.4f} (rad)")

    print(f"\nTCP force/torque:")
    print(f"  Force  : Fx={force[0]:+.2f}, Fy={force[1]:+.2f}, Fz={force[2]:+.2f} (N)")
    print(f"  Torque : Tx={force[3]:+.2f}, Ty={force[4]:+.2f}, Tz={force[5]:+.2f} (Nm)")

    tcp_speed_mag = sum(s**2 for s in speed[:3]) ** 0.5
    print(f"\nTCP speed: {tcp_speed_mag:.4f} m/s")
    print(f"Robot mode: {rtde_r.getRobotMode()}")
    print(f"Safety mode: {rtde_r.getSafetyMode()}")
    print("==================\n")


def move_home(rtde_c, rtde_r):
    """홈 위치로 이동"""
    print("Moving to home position...")
    print_robot_state(rtde_r)

    rtde_c.moveJ(HOME_JOINTS, MAX_JOINT_SPEED, MAX_ACCELERATION)

    print("Home position reached.")
    print_robot_state(rtde_r)


def move_to_tcp(rtde_c, rtde_r, target_pose):
    """TCP 좌표로 이동 (moveL)"""
    print(f"Moving to TCP: {target_pose}")
    print_robot_state(rtde_r)

    rtde_c.moveL(target_pose, MAX_LINEAR_SPEED, MAX_ACCELERATION)

    print("Target reached.")
    print_robot_state(rtde_r)


def move_to_joints(rtde_c, rtde_r, target_joints):
    """Joint 좌표로 이동 (moveJ)"""
    print(f"Moving to joints: {target_joints}")
    print_robot_state(rtde_r)

    rtde_c.moveJ(target_joints, MAX_JOINT_SPEED, MAX_ACCELERATION)

    print("Target reached.")
    print_robot_state(rtde_r)


def gripper_test(rtde_io):
    """디지털 출력으로 그리퍼 간단 테스트 (digital out 0)"""
    print("Gripper test: OPEN (DO0 = True)")
    rtde_io.setStandardDigitalOut(0, True)
    time.sleep(1.0)

    print("Gripper test: CLOSE (DO0 = False)")
    rtde_io.setStandardDigitalOut(0, False)
    time.sleep(1.0)
    print("Gripper test done.")


def interactive_mode(rtde_c, rtde_r):
    """인터랙티브 명령 모드"""
    print("\n=== Interactive Mode ===")
    print("Commands:")
    print("  state     - 현재 상태 출력")
    print("  home      - 홈 위치 이동")
    print("  movel x y z rx ry rz  - TCP 이동")
    print("  movej q1 q2 q3 q4 q5 q6  - Joint 이동 (rad)")
    print("  stop      - 로봇 정지")
    print("  quit      - 종료")
    print()

    while True:
        try:
            cmd = input("ur5e> ").strip().split()
        except (EOFError, KeyboardInterrupt):
            print("\nExiting...")
            break

        if not cmd:
            continue

        action = cmd[0].lower()

        if action == "quit" or action == "q":
            break
        elif action == "state" or action == "s":
            print_robot_state(rtde_r)
        elif action == "home" or action == "h":
            move_home(rtde_c, rtde_r)
        elif action == "stop":
            rtde_c.speedStop()
            rtde_c.servoStop()
            print("Robot stopped.")
        elif action == "movel" and len(cmd) == 7:
            try:
                pose = [float(v) for v in cmd[1:7]]
                move_to_tcp(rtde_c, rtde_r, pose)
            except ValueError:
                print("Error: 숫자 6개를 입력하세요 (x y z rx ry rz)")
        elif action == "movej" and len(cmd) == 7:
            try:
                joints = [float(v) for v in cmd[1:7]]
                move_to_joints(rtde_c, rtde_r, joints)
            except ValueError:
                print("Error: 숫자 6개를 입력하세요 (q1-q6 in rad)")
        else:
            print(f"Unknown command: {' '.join(cmd)}")


def main():
    parser = argparse.ArgumentParser(description="UR5e control test (ur_rtde)")
    parser.add_argument("--ip", default=DEFAULT_IP, help="Robot IP (default: %(default)s)")
    parser.add_argument("--home", action="store_true", help="Move to home position")
    parser.add_argument("--movel", nargs=6, type=float, metavar=("X", "Y", "Z", "RX", "RY", "RZ"),
                        help="Move to TCP pose (meters, radians)")
    parser.add_argument("--movej", nargs=6, type=float, metavar=("Q1", "Q2", "Q3", "Q4", "Q5", "Q6"),
                        help="Move to joint target (radians)")
    parser.add_argument("--interactive", "-i", action="store_true", help="Interactive command mode")
    args = parser.parse_args()

    print(f"Connecting to UR5e at {args.ip}...")

    try:
        rtde_r = RTDEReceiveInterface(args.ip)
        rtde_c = RTDEControlInterface(args.ip)
    except Exception as e:
        print(f"Connection failed: {e}")
        sys.exit(1)

    print("Connected.\n")

    try:
        if args.home:
            move_home(rtde_c, rtde_r)
        elif args.movel:
            move_to_tcp(rtde_c, rtde_r, args.movel)
        elif args.movej:
            move_to_joints(rtde_c, rtde_r, args.movej)
        elif args.interactive:
            interactive_mode(rtde_c, rtde_r)
        else:
            # 기본: 상태만 출력
            print_robot_state(rtde_r)
    except KeyboardInterrupt:
        print("\nInterrupted. Stopping robot...")
        rtde_c.speedStop()
    finally:
        rtde_c.stopScript()
        rtde_c.disconnect()
        rtde_r.disconnect()
        print("Disconnected.")


if __name__ == "__main__":
    main()
