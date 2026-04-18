# ur_robot_manager Architecture & Thread Model

## 1. System Overview

```
┌─────────────────────────────────────────────────────────────────┐
│                    ur_robot_manager_node (C++)                   │
│                                                                 │
│  ┌──────────────┐   ┌──────────────┐   ┌──────────────────────┐│
│  │ ROS2 Executor │   │  Servo Thread │   │ ur_rtde Recv Thread ││
│  │ (multi-thread)│   │  (500Hz)      │   │ (background, auto)  ││
│  │               │   │               │   │                     ││
│  │ - 10Hz timer  │   │ servoSpeedL() │   │ receiveCallback()   ││
│  │ - topic cbs   │   │ → servoJ()    │   │ → robot state sync  ││
│  └───────┬───────┘   └───────┬───────┘   └──────────┬──────────┘│
│          │                   │                      │           │
│          └───────────┬───────┘                      │           │
│                      ▼                              │           │
│         ┌──────────────────────┐                    │           │
│         │   rtde_control_      │◄───────────────────┘           │
│         │   rtde_receive_      │     (state sync thread)        │
│         │   rtde_io_           │                                │
│         └─────────┬────────────┘                                │
│                   │ RTDE Protocol (TCP/IP)                      │
└───────────────────┼─────────────────────────────────────────────┘
                    │
                    ▼
            ┌──────────────┐
            │  UR5e Controller │
            │  192.168.10.126  │
            └──────────────────┘
```

## 2. Thread Model

### Thread 1: ROS2 MultiThreadedExecutor
- **역할**: ROS2 callback 처리 (topic subscribe, timer, action)
- **생성**: `main_node.cpp`에서 `rclcpp::executors::MultiThreadedExecutor`
- **주요 callback**:
  - 10Hz safety timer → `safetyCheckCallback()` → `publishJointState()`
  - `/cmd/move_j` → `cmdMoveJCallback()` → `moveJ(async=true)`
  - `/cmd/custom_move_l` → `cmdCustomMoveLCallback()` → `customMoveL()`
  - `/cmd/stop` → `cmdStopCallback()` → `emergencyStop()`
  - `/cmd/servo_twist` → `setServoTwist()` (값 저장만)
  - `/cmd/servo_enable` → `startServoThread()` / `stopServoThread()`
  - `/cmd/freedrive` → `startFreedrive()` / `stopFreedrive()`
  - `/speed_scale` → `speed_scale_` 업데이트

### Thread 2: Servo Control Thread (500Hz, std::thread)
- **역할**: 실시간 서보 제어 루프
- **생성**: `startServoThread()` → `std::thread(servoThreadLoop)`
- **종료**: `stopServoThread()` → `servo_thread_running_ = false` → `join()`
- **주기**: `initPeriod()` / `waitPeriod()`로 정밀 2ms (500Hz) 타이밍
- **동작**: `servo_twist_cmd_` 읽기 → `servoSpeedL()` → `servoJ()`

### Thread 3: ur_rtde Receive Thread (자동 생성)
- **역할**: UR controller로부터 RTDE 데이터 수신 (robot state 동기화)
- **생성**: `RTDEControlInterface` 생성 시 내부적으로 `boost::thread` 자동 생성
- **동작**: `receiveCallback()` — 무한 루프로 robot state (joint pos, safety mode 등) 갱신
- **중요성**: moveJ(async=false) 블로킹 중에도 state를 업데이트하여 stop 감지 가능

## 3. Mutex 구조

### state_mutex_
```
보호 대상: current_joint_positions_, current_joint_velocities_,
           current_tcp_pose_, current_tcp_force_

Writer: getJointPositions() 등 (10Hz timer에서 호출)
        servoSpeedL() SIM_MODE에서 write
Reader: publishJointState() (10Hz timer)

용도: ROS2 callback 스레드 간 state 변수 경쟁 방지
```

### rtde_mutex_
```
보호 대상: rtde_control_ 의 모든 호출

이유: ur_rtde API가 thread-safe하지 않음.
      ROS2 callback 스레드와 servo thread가 동시에
      rtde_control_->moveJ() 와 rtde_control_->servoJ() 를
      호출할 수 있으므로 상호 배제 필요.

적용 함수:
  - customSpeedL()      (servo에서 speedJ 호출)
  - servoSpeedL()       (servo thread에서 servoJ 호출)
  - servoJ6Only()       (servo thread에서 servoJ 호출)
  - servoStop()
  - stopRobot()         (stopJ + stopL + servoStop)
  - emergencyStop()
  - reconnectControl()
  - setPayload()
```

### servo_twist_mutex_
```
보호 대상: servo_twist_cmd_ (Eigen::Matrix<double,6,1>)

Writer: setServoTwist() — ROS2 callback 스레드에서 호출
Reader: servoThreadLoop() — servo thread에서 매 cycle 읽기

용도: twist 명령의 atomic 업데이트 보장
```

## 4. Servo Thread 동작 상세

```
┌────────────────────────────────────────────────────────────────┐
│  외부 입력 (ROS2 topic)                                         │
│                                                                │
│  /cmd/servo_enable (Bool: true) ──→ startServoThread()         │
│                                       └→ std::thread 생성      │
│                                                                │
│  /cmd/servo_twist (Float64MultiArray) ──→ setServoTwist()      │
│    [vx, vy, vz, wx, wy, wz]               └→ servo_twist_cmd_ │
│    (예: joystick, VLA executor, teleop)        에 저장 (mutex)  │
│                                                                │
│  /cmd/servo_enable (Bool: false) ──→ stopServoThread()         │
│                                       └→ servoStop(3.2)       │
└────────────────────────────────────────────────────────────────┘
         │
         ▼
┌────────────────────────────────────────────────────────────────┐
│  Servo Thread (500Hz, dedicated std::thread)                    │
│                                                                │
│  servoThreadLoop() {                                           │
│    while (servo_thread_running_) {                             │
│      ┌─────────────────────────────────────────────────────┐   │
│      │ 1. initPeriod()                                     │   │
│      │    └→ 현재 시점 기록 (ur_rtde 내부 타이밍)           │   │
│      │                                                     │   │
│      │ 2. twist 읽기 (servo_twist_mutex_)                  │   │
│      │    └→ servo_twist_cmd_ 복사                         │   │
│      │                                                     │   │
│      │ 3. if (twist != 0) servoSpeedL(twist)               │   │
│      │    ├→ q 읽기: rtde_receive_->getActualQ()           │   │
│      │    ├→ J = geometricJacobianTCP(q)                   │   │
│      │    ├→ SVD: J = U Σ V^T                             │   │
│      │    ├→ Selective Damping:                            │   │
│      │    │   σ_i > σ_min → S_inv = 1/σ_i                 │   │
│      │    │   σ_i ≤ σ_min → S_inv = σ/(σ²+λ²)            │   │
│      │    ├→ qdot = V · diag(S_inv) · U^T · twist         │   │
│      │    ├→ velocity limit: proportional scaling          │   │
│      │    ├→ q_ref_ += qdot × dt_actual                   │   │
│      │    ├→ joint limit clamp                             │   │
│      │    ├→ drift correction (q_ref_ ↔ q_now)            │   │
│      │    └→ servoJ(q_ref_, 0, 0, dt, lookahead, gain)    │   │
│      │                                                     │   │
│      │ 4. waitPeriod(t_start)                              │   │
│      │    └→ sleep + spin으로 정확히 2ms 대기               │   │
│      └─────────────────────────────────────────────────────┘   │
│    }                                                           │
│  }                                                             │
└────────────────────────────────────────────────────────────────┘
         │
         ▼
┌────────────────────────────────────────────────────────────────┐
│  UR5e Controller                                                │
│  servoJ 명령을 2ms 간격으로 수신 → 실시간 관절 제어             │
│  lookahead_time으로 trajectory smoothing                        │
│  gain으로 position tracking 강도 조절                           │
└────────────────────────────────────────────────────────────────┘
```

### Servo 타이밍 보장 메커니즘

ur_rtde의 `initPeriod()` / `waitPeriod()`는 sleep과 busy-wait를 조합하여
1ms 미만의 jitter로 정확한 주기를 보장합니다:

```
initPeriod(): t_start = steady_clock::now()
waitPeriod(t_start):
  t_elapsed = now() - t_start
  t_remaining = dt - t_elapsed
  if (t_remaining > 1ms):
    sleep(t_remaining - 0.5ms)   // 대략적 sleep
  while (now() - t_start < dt):
    // busy-wait (spin)           // 정밀 보정
```

## 5. 주요 함수 구조

### Motion Commands

| 함수 | 입력 | 내부 동작 | ur_rtde 호출 | 비고 |
|------|------|---------|-------------|------|
| `moveJ` | joint[6], speed, accel, async | speed_scale 적용, clamp | `rtde_control_->moveJ()` | topic callback에서 async=true |
| `moveL` | pose[6], speed, accel, async | speed_scale 적용, clamp | `rtde_control_->moveL()` | |
| `customMoveL` | tcp_target[6] | TCP offset sync → IK8 → best pick → FK verify | `rtde_control_->moveJ()` | singularity-safe TCP 이동 |
| `customSpeedL` | Eigen twist(6) | adaptive DLS (λ ramp) + β normalization → qdot | `rtde_control_->speedJ()` | TCP 속도→joint 속도 변환 |
| `servoSpeedL` | Eigen twist(6) | Selective Damping SVD → q_ref_ 적분 | `rtde_control_->servoJ()` | 실시간 서보 (500Hz) |
| `servoJ6Only` | wz_tcp (double) | J6만 속도 적분, J1-J5 현재 유지 | `rtde_control_->servoJ()` | endoscope 회전 전용 |

### customSpeedL vs servoSpeedL

```
customSpeedL (일회성 속도 명령):
  twist → J^T (JJ^T + λ²I)^{-1} twist → speedJ
  
  특징:
  - 매 호출이 독립적 (상태 없음)
  - adaptive λ: manipulability 기반 선형 보간
  - β normalization: 명령 TCP 속도와 실제 TCP 속도 크기 일치 보정
  - speedJ로 실행 (속도 명령)

servoSpeedL (연속 서보 루프):
  twist → V · diag(S_inv) · U^T twist → q_ref_ += qdot·dt → servoJ(q_ref_)
  
  특징:
  - 상태 유지 (q_ref_, servo_mode_active_, last_servo_time_)
  - Selective Damping SVD: 각 singular value별 독립 damping
  - position 적분: qdot를 시간 적분하여 위치 명령 생성
  - drift 보정: q_ref_와 실제 q의 차이가 threshold 초과 시 리셋
  - servoJ로 실행 (위치 명령)
  - 500Hz 전용 스레드에서 호출
```

### Safety

```
safetyCheckCallback() — 10Hz timer
  ├→ checkJointLimits()
  │   └→ 각 joint별 upper/lower limit까지의 거리 체크
  │      거리 < threshold → stopRobot()
  ├→ force 체크
  │   └→ |F| > force_limit → stopRobot()
  └→ status publish ("/robot_status")
```

### Stop 함수 계층

```
stopRobot()          — 일반 정지
  ├→ stopJ(2.0)       moveJ/speedJ 정지 (joint deceleration)
  ├→ stopL(10.0)      moveL/speedL 정지 (TCP deceleration)
  └→ servoStop(3.2)   servoJ/servoL 정지

emergencyStop()      — 긴급 정지
  ├→ stopJ(2.0)
  ├→ stopL(10.0)
  ├→ servoStop(3.2)
  └→ triggerProtectiveStop()  ← 안전 정지 (하드웨어 레벨)
```

## 6. async=false 중 Stop이 가능한 이유

### ur_rtde 내부 아키텍처

```
Thread A (ROS2 callback, moveJ 호출):
  moveJ(target, speed, accel, async=false)
    → sendCommand(cmd)
      → rtde_->send(cmd)            // 명령 전송
      → while (state != DONE) {     // 블로킹 루프
            if (isProtectiveStopped())  → return false  ← 탈출 1
            if (isEmergencyStopped())   → return false  ← 탈출 2
            if (!isProgramRunning())    → return false  ← 탈출 3
            if (timeout)               → return false  ← 탈출 4
            sleep(1ms)
        }

Thread B (ROS2 callback, stop 호출):
  emergencyStop()
    → rtde_control_->stopJ(2.0)
      → sendCommand(STOP_CMD)
        → rtde_->send(cmd)          // stop 명령 전송 (별도 스레드)

Thread C (ur_rtde 내부, 자동 생성):
  receiveCallback() {               // boost::thread, 무한 루프
    while (!stop_thread_) {
      rtde_->receiveData(robot_state_)  // UR controller로부터 state 수신
      // → isProtectiveStopped(), isProgramRunning() 등의 값 갱신
    }
  }
```

### 동작 시퀀스

```
시간 →
Thread A:  moveJ 호출 → [블로킹: state==DONE 대기 중...]  → state 변경 감지 → return
Thread B:                     stopJ() 호출 → 로봇에 stop 전송
Thread C:  [수신 루프]───────────[로봇 상태 갱신]──────────────[stop 상태 반영]
UR Robot:  [moveJ 실행 중]──────[stop 수신]──[정지]──[state=DONE 또는 STOPPED]
```

핵심: **moveJ의 블로킹은 busy-wait (1ms sleep + state polling)**이며,
ur_rtde 내부의 receive thread가 robot state를 지속적으로 업데이트하므로
다른 스레드에서 stop 명령을 보내면 블로킹 루프의 조건 검사에서 탈출합니다.

### 왜 "thread-safe하지 않다"는데 동작하는가?

ur_rtde가 "thread-safe하지 않다"는 것은 **동시에 두 개의 motion command를 보내면 안 된다**는 의미이지,
stop 명령이 안 된다는 뜻이 아닙니다. 내부적으로:

- `sendCommand()` 내부에서 `rtde_->send()`는 socket write — 동시 호출 시 data corruption 가능
- 하지만 moveJ 블로킹 중에는 `rtde_->send()`가 **이미 끝난 상태** (대기 루프에 있음)
- 이때 다른 스레드에서 `stopJ()` → `rtde_->send(stop_cmd)` 호출은 socket이 idle이므로 **실제로 충돌 없음**

다만 이것은 **보장된 동작이 아닌 우연히 안전한 동작**입니다.
명시적 `rtde_mutex_`를 사용하는 것이 올바른 방법입니다.

## 7. Tunable Parameters (#TUNABLE)

코드에서 `#TUNABLE`로 검색하면 모든 조정 가능 파라미터를 찾을 수 있습니다.

### ServoParams (servo_params_)
| 파라미터 | 기본값 | 범위 | 설명 |
|---------|--------|------|------|
| dt | 0.002 | 0.002-0.008 | 서보 주기 [s]. 500Hz=0.002 |
| lookahead | 0.1 | 0.03-0.2 | servoJ trajectory smoothing |
| gain | 300 | 100-2000 | servoJ position tracking gain |
| sigma_min | 0.005 | 0.001-0.01 | SVD damping 시작 특이값 |
| lambda_max | 0.1 | 0.01-0.5 | 최대 damping 값 |
| qdot_max | 2.5 | 1.0-3.14 | 최대 joint 속도 [rad/s] |
| ref_error_max | 0.5 | 0.1-1.0 | q_ref_ drift 리셋 임계 [rad] |

### SpeedLParams (speedl_params_)
| 파라미터 | 기본값 | 범위 | 설명 |
|---------|--------|------|------|
| lambda_max | 0.018 | 0.01-0.05 | 특이점 최대 λ |
| lambda_min | 0.002 | 0.001-0.005 | 평상시 최소 λ |
| w_threshold | 0.009 | 0.005-0.02 | manipulability λ ramp 시작 |
| qdot_lim | 2.5 | 1.0-3.14 | 최대 joint 속도 [rad/s] |
| beta_min | 0.5 | 0.3-0.8 | β 정규화 하한 |
| beta_max | 1.5 | 1.2-2.0 | β 정규화 상한 |

### SafetyParams (safety_params_)
| 파라미터 | 기본값 | 범위 | 설명 |
|---------|--------|------|------|
| force_limit | 30.0 | 10-50 | force stop 임계 [N] |
| joint_limit_threshold | 0.1 | 0.05-0.2 | joint limit 접근 경고 [rad] |
| joint_limits_upper[6] | ±2π, ±π | - | UR5e joint 상한 |
| joint_limits_lower[6] | ±2π, ±π | - | UR5e joint 하한 |

## 8. Topic 구조

### 퍼블리시 (C++ → 외부)
| Topic | Type | Rate | 용도 |
|-------|------|------|------|
| /joint_states | JointState | 10Hz | joint pos, vel, effort |
| /tcp_pose | Float64MultiArray | 10Hz | TCP [x y z rx ry rz] |
| /tcp_wrench | WrenchStamped | 10Hz | force/torque |
| /robot_status | String | 10Hz | "connected:moving:servo" |
| /is_moving | Bool | event | 이동 상태 |

### 구독 (외부 → C++)
| Topic | Type | 처리 | 실행 |
|-------|------|------|------|
| /cmd/move_j | Float64MultiArray(6) | cmdMoveJCallback | moveJ(async=true) |
| /cmd/custom_move_l | Float64MultiArray(6) | cmdCustomMoveLCallback | customMoveL() |
| /cmd/home | Bool | cmdHomeCallback | moveJ(home, async) |
| /cmd/stop | Bool | cmdStopCallback | emergencyStop() |
| /cmd/freedrive | Bool | cmdFreedriveCallback | start/stopFreedrive() |
| /cmd/reconnect | Bool | lambda | reconnectControl() |
| /cmd/servo_enable | Bool | lambda | start/stopServoThread() |
| /cmd/servo_twist | Float64MultiArray(6) | lambda → setServoTwist() | (servo thread에서 소비) |
| /speed_scale | Float64MultiArray(1) | lambda | speed_scale_ 갱신 |
