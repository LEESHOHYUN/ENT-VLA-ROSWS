// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__FUNCTIONS_H_
#define GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gripper_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "gripper_interfaces/msg/detail/gripper_msg__struct.h"

/// Initialize msg/GripperMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__msg__GripperMsg
 * )) before or use
 * gripper_interfaces__msg__GripperMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__msg__GripperMsg__init(gripper_interfaces__msg__GripperMsg * msg);

/// Finalize msg/GripperMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__msg__GripperMsg__fini(gripper_interfaces__msg__GripperMsg * msg);

/// Create msg/GripperMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__msg__GripperMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__msg__GripperMsg *
gripper_interfaces__msg__GripperMsg__create();

/// Destroy msg/GripperMsg message.
/**
 * It calls
 * gripper_interfaces__msg__GripperMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__msg__GripperMsg__destroy(gripper_interfaces__msg__GripperMsg * msg);

/// Check for msg/GripperMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__msg__GripperMsg__are_equal(const gripper_interfaces__msg__GripperMsg * lhs, const gripper_interfaces__msg__GripperMsg * rhs);

/// Copy a msg/GripperMsg message.
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
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__msg__GripperMsg__copy(
  const gripper_interfaces__msg__GripperMsg * input,
  gripper_interfaces__msg__GripperMsg * output);

/// Initialize array of msg/GripperMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__msg__GripperMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__msg__GripperMsg__Sequence__init(gripper_interfaces__msg__GripperMsg__Sequence * array, size_t size);

/// Finalize array of msg/GripperMsg messages.
/**
 * It calls
 * gripper_interfaces__msg__GripperMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__msg__GripperMsg__Sequence__fini(gripper_interfaces__msg__GripperMsg__Sequence * array);

/// Create array of msg/GripperMsg messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__msg__GripperMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__msg__GripperMsg__Sequence *
gripper_interfaces__msg__GripperMsg__Sequence__create(size_t size);

/// Destroy array of msg/GripperMsg messages.
/**
 * It calls
 * gripper_interfaces__msg__GripperMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__msg__GripperMsg__Sequence__destroy(gripper_interfaces__msg__GripperMsg__Sequence * array);

/// Check for msg/GripperMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__msg__GripperMsg__Sequence__are_equal(const gripper_interfaces__msg__GripperMsg__Sequence * lhs, const gripper_interfaces__msg__GripperMsg__Sequence * rhs);

/// Copy an array of msg/GripperMsg messages.
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
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__msg__GripperMsg__Sequence__copy(
  const gripper_interfaces__msg__GripperMsg__Sequence * input,
  gripper_interfaces__msg__GripperMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__MSG__DETAIL__GRIPPER_MSG__FUNCTIONS_H_
