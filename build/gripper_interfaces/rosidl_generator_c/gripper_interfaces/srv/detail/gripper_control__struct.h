// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__STRUCT_H_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'torque_ctrl_param'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'custom_input'
// Member 'gripper_init'
// Member 'grasping_vel'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GripperControl in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__GripperControl_Request
{
  int8_t control_mode;
  uint16_t pos_ctrl_param[3];
  uint16_t vel_ctrl_param[3];
  rosidl_runtime_c__uint32__Sequence torque_ctrl_param;
  rosidl_runtime_c__String custom_input;
  rosidl_runtime_c__String gripper_init;
  rosidl_runtime_c__String grasping_vel;
} gripper_interfaces__srv__GripperControl_Request;

// Struct for a sequence of gripper_interfaces__srv__GripperControl_Request.
typedef struct gripper_interfaces__srv__GripperControl_Request__Sequence
{
  gripper_interfaces__srv__GripperControl_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__GripperControl_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GripperControl in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__GripperControl_Response
{
  bool successed;
} gripper_interfaces__srv__GripperControl_Response;

// Struct for a sequence of gripper_interfaces__srv__GripperControl_Response.
typedef struct gripper_interfaces__srv__GripperControl_Response__Sequence
{
  gripper_interfaces__srv__GripperControl_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__GripperControl_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_CONTROL__STRUCT_H_
