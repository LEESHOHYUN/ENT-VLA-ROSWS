// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__STRUCT_H_
#define GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GripperMsg in the package gripper_interfaces.
typedef struct gripper_interfaces__msg__GripperMsg
{
  int16_t angle;
  int16_t current;
  int16_t velocity;
  int16_t grp_pos;
  bool is_motor_enable;
  bool is_grp_init_ongoing;
  bool is_pos_ongoing;
  bool is_vel_ongoing;
  bool is_tor_ongoing;
  bool is_grp_opening;
  bool is_grp_closing;
  bool grp_direction;
  bool is_object_grasp;
  bool is_fault_occured;
} gripper_interfaces__msg__GripperMsg;

// Struct for a sequence of gripper_interfaces__msg__GripperMsg.
typedef struct gripper_interfaces__msg__GripperMsg__Sequence
{
  gripper_interfaces__msg__GripperMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__msg__GripperMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__STRUCT_H_
