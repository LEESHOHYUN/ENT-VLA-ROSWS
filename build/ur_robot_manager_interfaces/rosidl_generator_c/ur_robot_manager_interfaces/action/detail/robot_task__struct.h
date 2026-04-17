// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ur_robot_manager_interfaces:action/RobotTask.idl
// generated code does not contain a copyright notice

#ifndef UR_ROBOT_MANAGER_INTERFACES__ACTION__DETAIL__ROBOT_TASK__STRUCT_H_
#define UR_ROBOT_MANAGER_INTERFACES__ACTION__DETAIL__ROBOT_TASK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'positions'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_Goal
{
  int32_t task_id;
  rosidl_runtime_c__double__Sequence positions;
  int32_t tool_type;
} ur_robot_manager_interfaces__action__RobotTask_Goal;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_Goal.
typedef struct ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_Result
{
  bool success;
  rosidl_runtime_c__String error_message;
} ur_robot_manager_interfaces__action__RobotTask_Result;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_Result.
typedef struct ur_robot_manager_interfaces__action__RobotTask_Result__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_Feedback
{
  rosidl_runtime_c__String status;
  float completion_percentage;
} ur_robot_manager_interfaces__action__RobotTask_Feedback;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_Feedback.
typedef struct ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "ur_robot_manager_interfaces/action/detail/robot_task__struct.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  ur_robot_manager_interfaces__action__RobotTask_Goal goal;
} ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request.
typedef struct ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response.
typedef struct ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} ur_robot_manager_interfaces__action__RobotTask_GetResult_Request;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_GetResult_Request.
typedef struct ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "ur_robot_manager_interfaces/action/detail/robot_task__struct.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_GetResult_Response
{
  int8_t status;
  ur_robot_manager_interfaces__action__RobotTask_Result result;
} ur_robot_manager_interfaces__action__RobotTask_GetResult_Response;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_GetResult_Response.
typedef struct ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "ur_robot_manager_interfaces/action/detail/robot_task__struct.h"

/// Struct defined in action/RobotTask in the package ur_robot_manager_interfaces.
typedef struct ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  ur_robot_manager_interfaces__action__RobotTask_Feedback feedback;
} ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage;

// Struct for a sequence of ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage.
typedef struct ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence
{
  ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UR_ROBOT_MANAGER_INTERFACES__ACTION__DETAIL__ROBOT_TASK__STRUCT_H_
