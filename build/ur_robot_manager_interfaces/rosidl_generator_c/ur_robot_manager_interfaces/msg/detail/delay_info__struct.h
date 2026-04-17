// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur_robot_manager_interfaces:msg/DelayInfo.idl
// generated code does not contain a copyright notice

#ifndef UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__STRUCT_H_
#define UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DelayInfo in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__msg__DelayInfo
{
  rosidl_runtime_c__String command;
  double delay_sec;
} ur_robot_manager_interfaces__msg__DelayInfo;

// Struct for a sequence of ur_robot_manager_interfaces__msg__DelayInfo.
typedef struct ur_robot_manager_interfaces__msg__DelayInfo__Sequence
{
  ur_robot_manager_interfaces__msg__DelayInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__msg__DelayInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__STRUCT_H_
