// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nurse_interfaces:msg/ToolPrompt.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__STRUCT_H_
#define NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__STRUCT_H_

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
// Member 'tool_name'
// Member 'language_prompt'
// Member 'phase'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ToolPrompt in the package nurse_interfaces.
/**
  * Planner output: predicted next tool and language prompt for VLA
 */
typedef struct nurse_interfaces__msg__ToolPrompt
{
  std_msgs__msg__Header header;
  /// e.g. "suction_tip_3mm"
  rosidl_runtime_c__String tool_name;
  /// natural language prompt for VLA executor
  rosidl_runtime_c__String language_prompt;
  /// planner confidence
  float confidence;
  /// current surgical phase
  rosidl_runtime_c__String phase;
} nurse_interfaces__msg__ToolPrompt;

// Struct for a sequence of nurse_interfaces__msg__ToolPrompt.
typedef struct nurse_interfaces__msg__ToolPrompt__Sequence
{
  nurse_interfaces__msg__ToolPrompt * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nurse_interfaces__msg__ToolPrompt__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__TOOL_PROMPT__STRUCT_H_
