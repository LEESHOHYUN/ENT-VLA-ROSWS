// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:srv/GripperCommand.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_H_
#define GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GripperCommand in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__GripperCommand_Request
{
  uint8_t command;
  int16_t value;
} gripper_interfaces__srv__GripperCommand_Request;

// Struct for a sequence of gripper_interfaces__srv__GripperCommand_Request.
typedef struct gripper_interfaces__srv__GripperCommand_Request__Sequence
{
  gripper_interfaces__srv__GripperCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__GripperCommand_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/GripperCommand in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__GripperCommand_Response
{
  bool successed;
} gripper_interfaces__srv__GripperCommand_Response;

// Struct for a sequence of gripper_interfaces__srv__GripperCommand_Response.
typedef struct gripper_interfaces__srv__GripperCommand_Response__Sequence
{
  gripper_interfaces__srv__GripperCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__GripperCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__GRIPPER_COMMAND__STRUCT_H_
