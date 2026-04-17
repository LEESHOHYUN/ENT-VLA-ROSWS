// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nurse_interfaces:msg/SafetySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__STRUCT_H_
#define NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GO'.
/**
  * Decision codes
 */
enum
{
  nurse_interfaces__msg__SafetySignal__GO = 0
};

/// Constant 'HOLD'.
enum
{
  nurse_interfaces__msg__SafetySignal__HOLD = 1
};

/// Constant 'ABORT'.
enum
{
  nurse_interfaces__msg__SafetySignal__ABORT = 2
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'reason'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SafetySignal in the package nurse_interfaces.
/**
  * Safety Gate output
 */
typedef struct nurse_interfaces__msg__SafetySignal
{
  std_msgs__msg__Header header;
  uint8_t decision;
  /// human-readable reason for HOLD/ABORT
  rosidl_runtime_c__String reason;
} nurse_interfaces__msg__SafetySignal;

// Struct for a sequence of nurse_interfaces__msg__SafetySignal.
typedef struct nurse_interfaces__msg__SafetySignal__Sequence
{
  nurse_interfaces__msg__SafetySignal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nurse_interfaces__msg__SafetySignal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__STRUCT_H_
