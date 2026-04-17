// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:srv/PosVelCurCtrl.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__STRUCT_H_
#define GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/PosVelCurCtrl in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__PosVelCurCtrl_Request
{
  int16_t position;
  int16_t velocity;
  int16_t acceleration;
  int16_t current;
  uint16_t duration;
} gripper_interfaces__srv__PosVelCurCtrl_Request;

// Struct for a sequence of gripper_interfaces__srv__PosVelCurCtrl_Request.
typedef struct gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence
{
  gripper_interfaces__srv__PosVelCurCtrl_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__PosVelCurCtrl_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/PosVelCurCtrl in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__PosVelCurCtrl_Response
{
  bool successed;
} gripper_interfaces__srv__PosVelCurCtrl_Response;

// Struct for a sequence of gripper_interfaces__srv__PosVelCurCtrl_Response.
typedef struct gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence
{
  gripper_interfaces__srv__PosVelCurCtrl_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__PosVelCurCtrl_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__POS_VEL_CUR_CTRL__STRUCT_H_
