// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gripper_interfaces:srv/Modbus.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__STRUCT_H_
#define GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Modbus in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__Modbus_Request
{
  bool enable;
  uint8_t slave_address;
} gripper_interfaces__srv__Modbus_Request;

// Struct for a sequence of gripper_interfaces__srv__Modbus_Request.
typedef struct gripper_interfaces__srv__Modbus_Request__Sequence
{
  gripper_interfaces__srv__Modbus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__Modbus_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Modbus in the package gripper_interfaces.
typedef struct gripper_interfaces__srv__Modbus_Response
{
  bool successed;
} gripper_interfaces__srv__Modbus_Response;

// Struct for a sequence of gripper_interfaces__srv__Modbus_Response.
typedef struct gripper_interfaces__srv__Modbus_Response__Sequence
{
  gripper_interfaces__srv__Modbus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gripper_interfaces__srv__Modbus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__SRV__DETAIL__MODBUS__STRUCT_H_
