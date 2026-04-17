// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__STRUCT_H_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__STRUCT_H_

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
// Member 'tokens'
#include "nurse_interfaces/msg/detail/object_token__struct.h"

/// Struct defined in msg/ObjectTokenArray in the package nurse_interfaces.
/**
  * Array of tracked objects from SAM2S
 */
typedef struct nurse_interfaces__msg__ObjectTokenArray
{
  std_msgs__msg__Header header;
  nurse_interfaces__msg__ObjectToken__Sequence tokens;
} nurse_interfaces__msg__ObjectTokenArray;

// Struct for a sequence of nurse_interfaces__msg__ObjectTokenArray.
typedef struct nurse_interfaces__msg__ObjectTokenArray__Sequence
{
  nurse_interfaces__msg__ObjectTokenArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nurse_interfaces__msg__ObjectTokenArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__STRUCT_H_
