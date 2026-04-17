cmake_minimum_required(VERSION 3.8)
project(ur_robot_manager)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(ur_robot_manager_interfaces REQUIRED)
find_package(gripper_interfaces REQUIRED)
find_package(Eigen3 REQUIRED)

# Optional: ur_rtde for real robot control
find_package(ur_rtde QUIET)
if(NOT ur_rtde_FOUND)
  message(WARNING "ur_rtde not found. Building in simulation-only mode.")
  add_definitions(-DSIM_MODE=1)
endif()

set(DEPENDENCIES
  rclcpp
  rclcpp_action
  std_msgs
  std_srvs
  sensor_msgs
  geometry_msgs
  tf2_ros
  ur_robot_manager_interfaces
  gripper_interfaces
)

# Utils library (kinematics + trajectory)
add_library(ur_robot_manager_utils SHARED
  src/utils/robot_trajectory.cpp
  src/utils/ur_kinematics.cpp
)
ament_target_dependencies(ur_robot_manager_utils ${DEPENDENCIES})
target_include_directories(ur_robot_manager_utils PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${EIGEN3_INCLUDE_DIR}
)

# Core library (robot manager + action server)
add_library(ur_robot_manager_core SHARED
  src/core/ur_robot_manager.cpp
  src/core/ur_robot_action_server.cpp
)
ament_target_dependencies(ur_robot_manager_core ${DEPENDENCIES})
target_include_directories(ur_robot_manager_core PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${EIGEN3_INCLUDE_DIR}
)
target_link_libraries(ur_robot_manager_core ur_robot_manager_utils)
if(ur_rtde_FOUND)
  target_link_libraries(ur_robot_manager_core ur_rtde::rtde)
endif()

# Main executable
add_executable(ur_robot_manager_node src/nodes/main_node.cpp)
ament_target_dependencies(ur_robot_manager_node ${DEPENDENCIES})
target_include_directories(ur_robot_manager_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${EIGEN3_INCLUDE_DIR}
)
target_link_libraries(ur_robot_manager_node ur_robot_manager_core)

# Install
install(TARGETS
  ur_robot_manager_utils
  ur_robot_manager_core
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
install(TARGETS ur_robot_manager_node DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

ament_package()
