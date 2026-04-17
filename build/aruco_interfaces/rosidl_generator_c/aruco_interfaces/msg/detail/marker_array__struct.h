// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from aruco_interfaces:msg/MarkerArray.idl
// generated code does not contain a copyright notice

#ifndef ARUCO_INTERFACES__MSG__DETAIL__MARKER_ARRAY__STRUCT_H_
#define ARUCO_INTERFACES__MSG__DETAIL__MARKER_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'markers'
#include "aruco_interfaces/msg/detail/marker__struct.h"

/// Struct defined in msg/MarkerArray in the package aruco_interfaces.
typedef struct aruco_interfaces__msg__MarkerArray
{
  std_msgs__msg__Header header;
  aruco_interfaces__msg__Marker__Sequence markers;
} aruco_interfaces__msg__MarkerArray;

// Struct for a sequence of aruco_interfaces__msg__MarkerArray.
typedef struct aruco_interfaces__msg__MarkerArray__Sequence
{
  aruco_interfaces__msg__MarkerArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} aruco_interfaces__msg__MarkerArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARUCO_INTERFACES__MSG__DETAIL__MARKER_ARRAY__STRUCT_H_
