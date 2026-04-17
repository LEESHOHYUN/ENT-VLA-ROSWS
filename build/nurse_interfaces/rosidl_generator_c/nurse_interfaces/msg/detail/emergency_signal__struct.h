// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nurse_interfaces:msg/EmergencySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__STRUCT_H_
#define NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'NORMAL'.
/**
  * Status codes
 */
enum
{
  nurse_interfaces__msg__EmergencySignal__NORMAL = 0
};

/// Constant 'BLEEDING'.
enum
{
  nurse_interfaces__msg__EmergencySignal__BLEEDING = 1
};

/// Constant 'CONTAMINATION'.
enum
{
  nurse_interfaces__msg__EmergencySignal__CONTAMINATION = 2
};

/// Constant 'PHASE_COMPLETE'.
enum
{
  nurse_interfaces__msg__EmergencySignal__PHASE_COMPLETE = 3
};

/// Constant 'UNKNOWN'.
enum
{
  nurse_interfaces__msg__EmergencySignal__UNKNOWN = 255
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'detail'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/EmergencySignal in the package nurse_interfaces.
/**
  * Emergency classification from endoscope camera
 */
typedef struct nurse_interfaces__msg__EmergencySignal
{
  std_msgs__msg__Header header;
  uint8_t status;
  float confidence;
  /// optional description
  rosidl_runtime_c__String detail;
} nurse_interfaces__msg__EmergencySignal;

// Struct for a sequence of nurse_interfaces__msg__EmergencySignal.
typedef struct nurse_interfaces__msg__EmergencySignal__Sequence
{
  nurse_interfaces__msg__EmergencySignal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nurse_interfaces__msg__EmergencySignal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__EMERGENCY_SIGNAL__STRUCT_H_
