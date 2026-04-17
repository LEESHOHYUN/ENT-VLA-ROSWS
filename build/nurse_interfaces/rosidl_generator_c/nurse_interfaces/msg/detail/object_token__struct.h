// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__STRUCT_H_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'object_id'
// Member 'object_class'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/ObjectToken in the package nurse_interfaces.
/**
  * Single tracked object from SAM2S (instrument or hand)
 */
typedef struct nurse_interfaces__msg__ObjectToken
{
  /// e.g. "myringotomy_knife", "surgeon_hand_left"
  rosidl_runtime_c__String object_id;
  /// instrument type or "hand"
  rosidl_runtime_c__String object_class;
  /// [x_min, y_min, x_max, y_max] normalized 0-1
  float bbox[4];
  /// detection confidence
  float confidence;
  /// currently visible in frame
  bool visible;
  /// 3D position estimate (if depth available)
  geometry_msgs__msg__Point position;
} nurse_interfaces__msg__ObjectToken;

// Struct for a sequence of nurse_interfaces__msg__ObjectToken.
typedef struct nurse_interfaces__msg__ObjectToken__Sequence
{
  nurse_interfaces__msg__ObjectToken * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nurse_interfaces__msg__ObjectToken__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__STRUCT_H_
