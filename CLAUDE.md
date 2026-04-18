# scrub_nurse_ws — ROS2 Workspace for ENT Surgical Scrub Nurse

## 개요
Myringotomy 수술 보조 로봇(Scrub Nurse)의 **ROS2 노드, launch, 하드웨어 제어** 전용.
AI 모델 학습/데이터 파이프라인은 `~/ai_env/vla_venv/`에 위치.

## 시스템 환경
- ROS 2: Humble
- Python: 3.10 (`~/ai_env/vla_venv`, --system-site-packages → rclpy 직접 import)
- Hardware: UR5e (단일), 1DOF Faulhaber gripper, RealSense D415
- GPU: RTX 3080 Ti (12GB) — SmolVLA는 양자화 불필요 (VRAM 0.87GB)

## 빌드 방법
```bash
source /opt/ros/humble/setup.bash
cd ~/scrub_nurse_ws
colcon build --symlink-install
source install/setup.bash
```
(bashrc alias `cb` 로도 동일)

AI 노드 실행 시에만 venv activate:
```bash
source ~/ai_env/vla_venv/bin/activate
ros2 launch nurse_bringup full_system_launch.py
```

## 카메라 구성

| Camera | Topic | 역할 | 상태 |
|---|---|---|---|
| Wrist (RealSense D415) | `/cam_handeye/color/image_raw` | grasp 정밀 제어, VLA 전용 | ✅ 확정 |
| Handover/Closeup | `/cam_handover/image_raw` | hand + patient + emergency 병행 | ✅ 확정 |
| Endoscope (USB) | `/cam_endoscope/image_raw` | emergency detection 병행 | ✅ 확정 |
| Full Scene | `/cam_fullscene/image_raw` | 전체 수술실 뷰 | ✅ 있음 |
| Tool Desk | `/cam_tooldesk/image_raw` | instrument tray 전용 | ✅ 있음 |
| Ceiling | `/cam_ceiling/image_raw` | overhead 뷰 | 🔶 의대 확인 중 |
| Microscope | `/cam_microscope/image_raw` | 수술 현미경 뷰 | 🔶 의대 확인 중 |

- microscope vs endo 중 설정 필요 

## 패키지 구조
```
src/
├── [하드웨어 드라이버 — ros2_ws에서 복사, C++]
│   ├── ur_robot_manager/            ← UR5e 제어 (ur_rtde, single robot)
│   │   customMoveL: TCP → IK8 → best pick → moveJ
│   │   topics: /cmd/move_j, /cmd/custom_move_l, /cmd/home, /cmd/stop
│   │   publish: /joint_states, /tcp_pose, /tcp_wrench, /robot_status
│   ├── ur_robot_manager_interfaces/ ← RobotTask.action, DelayInfo.msg
│   ├── gripper_test/                ← Faulhaber gripper 제어
│   ├── gripper_interfaces/          ← GripperMsg, 9개 서비스
│   └── aruco_interfaces/            ← Marker msg
│
├── [프로젝트 전용 — Python 노드]
│   ├── nurse_bringup/               ← launch 파일 + config
│   ├── nurse_perception/            ← Detector node, Emergency Classifier node
│   ├── nurse_planning/              ← Sequence Transformer Planner, Safety Gate
│   ├── nurse_control/               ← VLA Executor, Handover Controller
│   └── nurse_interfaces/            ← custom msg 정의
│
└── ros2_recorder/                   ← 멀티카메라 녹화
```

## ROS2 Topic 흐름

```
[PERCEPTION]
cam_handover + cam_tooldesk + cam_fullscene + (cam_ceiling)
  → Detector Node: RF-DETR (ICLR 2026 SOTA, DINOv2 backbone)
    - detection + instance segmentation 통합
    - ENT instrument 9 classes + surgeon_hand fine-tuning
    - Fallback: YOLOv11 (속도 우선 시)
  → /perception/object_tokens

cam_handover + cam_endoscope + (cam_microscope)
  → Emergency Classifier Node (lightweight CNN)
  → /emergency/signal [NORMAL|BLEEDING|CONTAMINATION|PHASE_COMPLETE]

/tcp_wrench → handover 완료 감지

[VOICE]
STT → /voice/command → Planner 보조 입력 (있으면 사용)

[PLANNER]
/perception/object_tokens + /voice/command + action_history + elapsed_time
  → Sequence Transformer Planner Node
  → /planner/next_tool_prompt
  → /planner/confidence
  → /planner/timing_estimate

[SAFETY GATE]
/planner/next_tool_prompt + /emergency/signal + robot_state + /tcp_wrench
  → Safety Gate Node
  → /safety/command [GO|HOLD|ABORT]

[VLA EXECUTOR] — GO only
/planner/next_tool_prompt + /cam_handover + /cam_handeye
  → SmolVLA (VRAM 0.87GB)
  → /vla/action_command

[UR5e CONTROLLER — C++]
/vla/action_command
  → customMoveL (IK8→moveJ) → pickup → grasp → handover → release
  → /tcp_wrench로 handover 완료 감지

[RECORDING NODE — data collection 시]
전체 image + tokens + wrench + action → rosbag2 + RLDS
```

## Custom Messages (nurse_interfaces)

| Message | Topic | 설명 |
|---|---|---|
| `ObjectToken` / `ObjectTokenArray` | `/perception/object_tokens` | instrument ID, bbox, visibility, hand state |
| `EmergencySignal` | `/emergency/signal` | NORMAL/BLEEDING/CONTAMINATION/PHASE_COMPLETE |
| `ToolPrompt` | `/planner/next_tool_prompt` | tool_name, language_prompt, confidence, phase |
| `SafetySignal` | `/safety/command` | GO/HOLD/ABORT + reason |

## Launch 파일 (nurse_bringup)

| Launch | 용도 | 명령 |
|---|---|---|
| `full_system_launch.py` | 전체 시스템 | `ros2 launch nurse_bringup full_system_launch.py` |
| `robot_only_launch.py` | UR5e + gripper만 | `ros2 launch nurse_bringup robot_only_launch.py` |
| `cameras_only_launch.py` | 카메라만 | `ros2 launch nurse_bringup cameras_only_launch.py` |

주요 launch arguments:
- `robot_ip:=192.168.10.126`
- `enable_cameras:=true/false`
- `enable_pipeline:=true/false`
- `enable_recording:=true/false`

## Safety 파라미터
- Linear: 0.15 m/s max
- Angular: 0.8 rad/s max
- Delta per step: ±5mm translation, ±3deg rotation
- Handover zone: robot_params.yaml에 정의
- Wrench threshold: handover 완료 감지 (yaml로 조정 가능)

## 하드웨어 드라이버

### UR5e (ur_robot_manager)
- `endobot_ip: '0.0.0.0'` → 단일 로봇 모드
- customMoveL: TCP target → IK8 → best joint config → moveJ
- 1kHz servoJ 실시간 루프는 C++ 필수

### Gripper (gripper_test)
- `/gripper_states`: angle, current, velocity 등 13개 상태
- `/gripper_command`, `/gripper_control`, `/stop_motor` 서비스

### FT (ur_robot_manager)
- `/tcp_wrench` topic (10Hz)
- handover 완료 감지: force threshold crossing 기반
- 별도 외장 센서 불필요 (UR5e 내장)

## 관련 디렉토리
- `~/ai_env/vla_venv/` — Python venv + AI 소스코드
- `~/ros2_ws/` — 범용 로봇 제어 원본
- `~/ur_rtde/` — ur_rtde 소스
- `~/storage/surgical/` — 데이터 전용

## 주의사항
- `note.md` 수정 금지
- C++ 패키지는 `~/ros2_ws/`에서 복사본. 원본 수정 시 동기화 필요
- build/, install/, log/ → git 제외
- SmolVLA: VRAM 0.87GB, 양자화 불필요
- 1kHz servoJ 실시간 루프: C++ 필수 (Python은 단위 명령에만)
- Perception: RF-DETR (ICLR 2026, DINOv2 backbone) — 외부 씬 instrument+hand 통합
- SAM2: endo cam emergency classifier 보조로만 제한, 외부 씬에서 제거
- nurse_* Python 패키지 entry_points: 노드 구현 후 주석 해제