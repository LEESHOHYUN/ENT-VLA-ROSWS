# scrub_nurse_ws — ROS2 Workspace for ENT Surgical Scrub Nurse

## 개요
이 워크스페이스는 Myringotomy 수술 보조 로봇(Scrub Nurse)의 **ROS2 노드, launch, 하드웨어 제어** 전용입니다.
AI 모델 학습/데이터 파이프라인은 `~/ai_env/vla_venv/`에 위치합니다.

## 시스템 환경
- ROS 2: Humble
- Python: 3.10 (`~/ai_env/vla_venv`, --system-site-packages → rclpy 직접 import)
- Hardware: UR5e (단일), 1DOF Faulhaber gripper, RealSense D435, USB webcam x1, USB endoscope x1
- GPU: RTX 3080 Ti (12GB) — VLA inference는 4-bit 양자화 필수

## 빌드 방법
```bash
source /opt/ros/humble/setup.bash
source ~/ai_env/vla_venv/bin/activate
cd ~/scrub_nurse_ws
colcon build --symlink-install
source install/setup.bash
```

## 패키지 구조
```
src/
├── [하드웨어 드라이버 — ros2_ws에서 복사, C++]
│   ├── ur_robot_manager/            ← UR5e 제어 (ur_rtde 기반, dual mode지만 single로 사용)
│   ├── ur_robot_manager_interfaces/ ← RobotTask.action, DelayInfo.msg
│   ├── gripper_test/                ← Faulhaber gripper 제어
│   ├── gripper_interfaces/          ← GripperMsg, 9개 서비스 정의
│   └── aruco_interfaces/            ← Marker msg (ur_robot_manager 의존성)
│
├── [프로젝트 전용 — Python 노드]
│   ├── nurse_bringup/               ← launch 파일 + config (진입점)
│   ├── nurse_perception/            ← SAM2S tracking node, Emergency Classifier node
│   ├── nurse_planning/              ← Sequence Transformer Planner, Safety Gate
│   ├── nurse_control/               ← VLA Executor, Handover Controller
│   └── nurse_interfaces/            ← 파이프라인 custom msg 정의
│
└── ros2_recorder/                   ← 멀티카메라 녹화 유틸리티
```

## Launch 파일 (nurse_bringup)
| Launch | 용도 | 명령 |
|--------|------|------|
| `full_system_launch.py` | 전체 시스템 (로봇+카메라+WebGUI) | `ros2 launch nurse_bringup full_system_launch.py` |
| `robot_only_launch.py` | UR5e + gripper만 (headless 테스트) | `ros2 launch nurse_bringup robot_only_launch.py` |
| `cameras_only_launch.py` | 카메라 3대만 | `ros2 launch nurse_bringup cameras_only_launch.py` |

주요 launch argument:
- `robot_ip:=192.168.10.126` (UR5e IP, 기본값 126)
- `enable_cameras:=true/false`
- `enable_pipeline:=true/false` (VLA 파이프라인 노드)
- `enable_webgui:=true/false` (rosbridge + web_video_server)

## ROS2 Topic 흐름 (Hierarchical ST-VLA Pipeline)
```
cam_handover ──→ [SAM2S Node] ──→ /sam2s/object_tokens ──┐
                                                          ├→ [Planner Node] → /planner/next_tool_prompt ─┐
cam_endoscope ─→ [Emergency Node] → /emergency/signal ───┤                                              │
                                                          └→ [Safety Gate] → /safety/go_signal ──────────┤
                                                                                                         │
cam_handeye ──────────────────────────────────────────────────→ [VLA Executor] ←─────────────────────────┘
                                                                      │
                                                              /vla/action_command
                                                                      │
                                                              [UR5e Controller]
                                                                      │
                                                          pickup → grasp → handover → release
```

## Custom Messages (nurse_interfaces)
| Message | Topic | 설명 |
|---------|-------|------|
| `ObjectToken` / `ObjectTokenArray` | `/sam2s/object_tokens` | instrument ID, bbox, visibility, hand state |
| `EmergencySignal` | `/emergency/signal` | NORMAL / BLEEDING / CONTAMINATION / PHASE_COMPLETE |
| `ToolPrompt` | `/planner/next_tool_prompt` | tool_name, language_prompt, confidence, phase |
| `SafetySignal` | `/safety/go_signal` | GO / HOLD / ABORT + reason |

## Camera Topics
| 카메라 | ROS2 Topic | 용도 | 구독 노드 |
|--------|-----------|------|-----------|
| cam_handeye (RealSense) | `/cam_handeye/color/image_raw` | grasp 정밀 제어 | VLA Executor |
| cam_handover (USB) | `/cam_handover/image_raw` | instrument tray + surgeon hand | SAM2S, VLA Executor |
| cam_endoscope (USB) | `/cam_endoscope/image_raw` | emergency detection | Emergency Classifier |

## 하드웨어 드라이버 사용법

### UR5e (ur_robot_manager)
- 원본은 dual robot 시스템이지만, `endobot_ip: '0.0.0.0'`으로 단일 로봇 모드 사용
- 제어: moveJ, moveL, speedJ, servo 모드 지원
- Joy topic: `/rtde1joy/joy`
- Safety: linear 0.15 m/s, angular 0.8 rad/s (수술용 보수적 제한)

### Gripper (gripper_test)
- `/gripper_states` 토픽: angle, current, velocity, grasp detection 등 13개 상태
- `/gripper_command` 서비스: 기본 명령
- `/gripper_control` 서비스: position/velocity/current 제어
- `/stop_motor` 서비스: 긴급 정지

## Config 파일 (nurse_bringup/config/)
- `robot_params.yaml` — UR5e IP, safety limits, handover zone 경계
- `camera_params.yaml` — RealSense/USB 카메라 해상도, FPS
- `vla_params.yaml` — 파이프라인 6노드 전체 파라미터 (모델, topic, threshold 등)

## 관련 디렉토리
- `~/ai_env/vla_venv/` — Python venv + AI 소스코드 (surgical_pipeline, Surgical-SAM-2)
- `~/ros2_ws/` — 범용 로봇 제어 원본 (이 ws의 드라이버 복사 원본)
- `~/ur_rtde/` — ur_rtde C++/Python 라이브러리 소스
- `~/storage/surgical/` — 데이터 전용

## 주의사항
- 이 ws의 C++ 패키지(ur_robot_manager, gripper_test 등)는 `~/ros2_ws/`에서 복사한 것. 원본 수정 시 여기도 동기화 필요.
- `colcon build` 산물(build/, install/, log/)은 git에 포함하지 말 것.
- VLA 모델(OpenVLA-7B)은 12GB VRAM에서 반드시 4-bit 양자화(bitsandbytes)로 로드.
- nurse_* Python 패키지의 entry_points는 아직 주석 처리 상태 — 노드 구현 후 해제.
