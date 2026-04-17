cmake_minimum_required(VERSION 3.8)
project(gripper_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(gripper_interfaces REQUIRED)
find_package(Qt5 COMPONENTS Widgets Core Gui QUIET)
find_package(Boost REQUIRED COMPONENTS system thread)

# Gripper action node (no Qt dependency)
add_executable(gripper_action_node
  src/gripper_action_node.cpp
)
ament_target_dependencies(gripper_action_node
  rclcpp rclcpp_action std_msgs gripper_interfaces
)
target_include_directories(gripper_action_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Gripper control node (with Qt GUI - optional)
if(Qt5_FOUND)
  add_executable(gripper_node
    src/gripper_node.cpp
  )
  ament_target_dependencies(gripper_node
    rclcpp rclcpp_action std_msgs gripper_interfaces
  )
  target_include_directories(gripper_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
  )
  target_link_libraries(gripper_node
    Qt5::Widgets Qt5::Core Qt5::Gui
    Boost::system Boost::thread
  )
  install(TARGETS gripper_node DESTINATION lib/${PROJECT_NAME})
endif()

install(TARGETS gripper_action_node DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})

ament_package()
