// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:srv/StopMotor.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__STOP_MOTOR__STRUCT_H_
#define GRIPPER_INTERFACES__SRV__DETAIL__STOP_MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/StopMotor in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__StopMotor_Request
{
  uint16_t duration;
} gripper_interfaces__srv__StopMotor_Request;

// Struct for a sequence of gripper_interfaces__srv__StopMotor_Request.
typedef struct gripper_interfaces__srv__StopMotor_Request__Sequence
{
  gripper_interfaces__srv__StopMotor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__StopMotor_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/StopMotor in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__StopMotor_Response
{
  bool successed;
} gripper_interfaces__srv__StopMotor_Response;

// Struct for a sequence of gripper_interfaces__srv__StopMotor_Response.
typedef struct gripper_interfaces__srv__StopMotor_Response__Sequence
{
  gripper_interfaces__srv__StopMotor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__StopMotor_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__STOP_MOTOR__STRUCT_H_
