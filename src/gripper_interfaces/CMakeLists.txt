cmake_minimum_required(VERSION 3.8)
project(gripper_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/GripperMsg.msg"
  "srv/SlaveChange.srv"
  "srv/PosVelCurCtrl.srv"
  "srv/DriverEnable.srv"
  "srv/SetParameter.srv"
  "srv/GripperControl.srv"
  "srv/ArduinoControl.srv"
  "srv/Modbus.srv"
  "srv/GripperCommand.srv"
  "srv/StopMotor.srv"
  "action/Gripper.action"
  DEPENDENCIES action_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
