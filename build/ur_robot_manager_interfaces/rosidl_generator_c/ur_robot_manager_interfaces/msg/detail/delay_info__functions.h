// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ur_robot_manager_interfaces:msg/DelayInfo.idl
// generated code does not contain a copyright notice

#ifndef UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__FUNCTIONS_H_
#define UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ur_robot_manager_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ur_robot_manager_interfaces/msg/detail/delay_info__struct.h"

/// Initialize msg/DelayInfo message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ur_robot_manager_interfaces__msg__DelayInfo
 * )) before or use
 * ur_robot_manager_interfaces__msg__DelayInfo__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
bool
ur_robot_manager_interfaces__msg__DelayInfo__init(ur_robot_manager_interfaces__msg__DelayInfo * msg);

/// Finalize msg/DelayInfo message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
void
ur_robot_manager_interfaces__msg__DelayInfo__fini(ur_robot_manager_interfaces__msg__DelayInfo * msg);

/// Create msg/DelayInfo message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ur_robot_manager_interfaces__msg__DelayInfo__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
ur_robot_manager_interfaces__msg__DelayInfo *
ur_robot_manager_interfaces__msg__DelayInfo__create();

/// Destroy msg/DelayInfo message.
/**
 * It calls
 * ur_robot_manager_interfaces__msg__DelayInfo__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
void
ur_robot_manager_interfaces__msg__DelayInfo__destroy(ur_robot_manager_interfaces__msg__DelayInfo * msg);

/// Check for msg/DelayInfo message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
bool
ur_robot_manager_interfaces__msg__DelayInfo__are_equal(const ur_robot_manager_interfaces__msg__DelayInfo * lhs, const ur_robot_manager_interfaces__msg__DelayInfo * rhs);

/// Copy a msg/DelayInfo message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
bool
ur_robot_manager_interfaces__msg__DelayInfo__copy(
  const ur_robot_manager_interfaces__msg__DelayInfo * input,
  ur_robot_manager_interfaces__msg__DelayInfo * output);

/// Initialize array of msg/DelayInfo messages.
/**
 * It allocates the memory for the number of elements and calls
 * ur_robot_manager_interfaces__msg__DelayInfo__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
bool
ur_robot_manager_interfaces__msg__DelayInfo__Sequence__init(ur_robot_manager_interfaces__msg__DelayInfo__Sequence * array, size_t size);

/// Finalize array of msg/DelayInfo messages.
/**
 * It calls
 * ur_robot_manager_interfaces__msg__DelayInfo__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
void
ur_robot_manager_interfaces__msg__DelayInfo__Sequence__fini(ur_robot_manager_interfaces__msg__DelayInfo__Sequence * array);

/// Create array of msg/DelayInfo messages.
/**
 * It allocates the memory for the array and calls
 * ur_robot_manager_interfaces__msg__DelayInfo__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
ur_robot_manager_interfaces__msg__DelayInfo__Sequence *
ur_robot_manager_interfaces__msg__DelayInfo__Sequence__create(size_t size);

/// Destroy array of msg/DelayInfo messages.
/**
 * It calls
 * ur_robot_manager_interfaces__msg__DelayInfo__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
void
ur_robot_manager_interfaces__msg__DelayInfo__Sequence__destroy(ur_robot_manager_interfaces__msg__DelayInfo__Sequence * array);

/// Check for msg/DelayInfo message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
bool
ur_robot_manager_interfaces__msg__DelayInfo__Sequence__are_equal(const ur_robot_manager_interfaces__msg__DelayInfo__Sequence * lhs, const ur_robot_manager_interfaces__msg__DelayInfo__Sequence * rhs);

/// Copy an array of msg/DelayInfo messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ur_robot_manager_interfaces
bool
ur_robot_manager_interfaces__msg__DelayInfo__Sequence__copy(
  const ur_robot_manager_interfaces__msg__DelayInfo__Sequence * input,
  ur_robot_manager_interfaces__msg__DelayInfo__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UR_ROBOT_MANAGER_INTERFACES__MSG__DETAIL__DELAY_INFO__FUNCTIONS_H_
