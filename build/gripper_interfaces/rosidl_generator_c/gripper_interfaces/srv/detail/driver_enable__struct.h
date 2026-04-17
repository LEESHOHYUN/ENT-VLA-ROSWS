// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:srv/DriverEnable.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__DRIVER_ENABLE__STRUCT_H_
#define GRIPPER_INTERFACES__SRV__DETAIL__DRIVER_ENABLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/DriverEnable in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__DriverEnable_Request
{
  bool enable;
} gripper_interfaces__srv__DriverEnable_Request;

// Struct for a sequence of gripper_interfaces__srv__DriverEnable_Request.
typedef struct gripper_interfaces__srv__DriverEnable_Request__Sequence
{
  gripper_interfaces__srv__DriverEnable_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__DriverEnable_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/DriverEnable in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__DriverEnable_Response
{
  bool successed;
} gripper_interfaces__srv__DriverEnable_Response;

// Struct for a sequence of gripper_interfaces__srv__DriverEnable_Response.
typedef struct gripper_interfaces__srv__DriverEnable_Response__Sequence
{
  gripper_interfaces__srv__DriverEnable_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__DriverEnable_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__DRIVER_ENABLE__STRUCT_H_
