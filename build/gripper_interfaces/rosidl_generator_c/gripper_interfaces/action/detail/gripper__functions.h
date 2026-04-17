// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gripper_interfaces:action/Gripper.idl
// generated code does not contain a copyright notice

#ifndef GRIPPER_INTERFACES__ACTION__DETAIL__GRIPPER__FUNCTIONS_H_
#define GRIPPER_INTERFACES__ACTION__DETAIL__GRIPPER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gripper_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "gripper_interfaces/action/detail/gripper__struct.h"

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_Goal
 * )) before or use
 * gripper_interfaces__action__Gripper_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Goal__init(gripper_interfaces__action__Gripper_Goal * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Goal__fini(gripper_interfaces__action__Gripper_Goal * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_Goal *
gripper_interfaces__action__Gripper_Goal__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Goal__destroy(gripper_interfaces__action__Gripper_Goal * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Goal__are_equal(const gripper_interfaces__action__Gripper_Goal * lhs, const gripper_interfaces__action__Gripper_Goal * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_Goal__copy(
  const gripper_interfaces__action__Gripper_Goal * input,
  gripper_interfaces__action__Gripper_Goal * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Goal__Sequence__init(gripper_interfaces__action__Gripper_Goal__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Goal__Sequence__fini(gripper_interfaces__action__Gripper_Goal__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_Goal__Sequence *
gripper_interfaces__action__Gripper_Goal__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Goal__Sequence__destroy(gripper_interfaces__action__Gripper_Goal__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Goal__Sequence__are_equal(const gripper_interfaces__action__Gripper_Goal__Sequence * lhs, const gripper_interfaces__action__Gripper_Goal__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_Goal__Sequence__copy(
  const gripper_interfaces__action__Gripper_Goal__Sequence * input,
  gripper_interfaces__action__Gripper_Goal__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_Result
 * )) before or use
 * gripper_interfaces__action__Gripper_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Result__init(gripper_interfaces__action__Gripper_Result * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Result__fini(gripper_interfaces__action__Gripper_Result * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_Result *
gripper_interfaces__action__Gripper_Result__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Result__destroy(gripper_interfaces__action__Gripper_Result * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Result__are_equal(const gripper_interfaces__action__Gripper_Result * lhs, const gripper_interfaces__action__Gripper_Result * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_Result__copy(
  const gripper_interfaces__action__Gripper_Result * input,
  gripper_interfaces__action__Gripper_Result * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Result__Sequence__init(gripper_interfaces__action__Gripper_Result__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Result__Sequence__fini(gripper_interfaces__action__Gripper_Result__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_Result__Sequence *
gripper_interfaces__action__Gripper_Result__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Result__Sequence__destroy(gripper_interfaces__action__Gripper_Result__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Result__Sequence__are_equal(const gripper_interfaces__action__Gripper_Result__Sequence * lhs, const gripper_interfaces__action__Gripper_Result__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_Result__Sequence__copy(
  const gripper_interfaces__action__Gripper_Result__Sequence * input,
  gripper_interfaces__action__Gripper_Result__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_Feedback
 * )) before or use
 * gripper_interfaces__action__Gripper_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Feedback__init(gripper_interfaces__action__Gripper_Feedback * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Feedback__fini(gripper_interfaces__action__Gripper_Feedback * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_Feedback *
gripper_interfaces__action__Gripper_Feedback__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Feedback__destroy(gripper_interfaces__action__Gripper_Feedback * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Feedback__are_equal(const gripper_interfaces__action__Gripper_Feedback * lhs, const gripper_interfaces__action__Gripper_Feedback * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_Feedback__copy(
  const gripper_interfaces__action__Gripper_Feedback * input,
  gripper_interfaces__action__Gripper_Feedback * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Feedback__Sequence__init(gripper_interfaces__action__Gripper_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Feedback__Sequence__fini(gripper_interfaces__action__Gripper_Feedback__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_Feedback__Sequence *
gripper_interfaces__action__Gripper_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_Feedback__Sequence__destroy(gripper_interfaces__action__Gripper_Feedback__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_Feedback__Sequence__are_equal(const gripper_interfaces__action__Gripper_Feedback__Sequence * lhs, const gripper_interfaces__action__Gripper_Feedback__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_Feedback__Sequence__copy(
  const gripper_interfaces__action__Gripper_Feedback__Sequence * input,
  gripper_interfaces__action__Gripper_Feedback__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_SendGoal_Request
 * )) before or use
 * gripper_interfaces__action__Gripper_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Request__init(gripper_interfaces__action__Gripper_SendGoal_Request * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Request__fini(gripper_interfaces__action__Gripper_SendGoal_Request * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_SendGoal_Request *
gripper_interfaces__action__Gripper_SendGoal_Request__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Request__destroy(gripper_interfaces__action__Gripper_SendGoal_Request * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Request__are_equal(const gripper_interfaces__action__Gripper_SendGoal_Request * lhs, const gripper_interfaces__action__Gripper_SendGoal_Request * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_SendGoal_Request__copy(
  const gripper_interfaces__action__Gripper_SendGoal_Request * input,
  gripper_interfaces__action__Gripper_SendGoal_Request * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__init(gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__fini(gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence *
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__destroy(gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__are_equal(const gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * lhs, const gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_SendGoal_Request__Sequence__copy(
  const gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * input,
  gripper_interfaces__action__Gripper_SendGoal_Request__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_SendGoal_Response
 * )) before or use
 * gripper_interfaces__action__Gripper_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Response__init(gripper_interfaces__action__Gripper_SendGoal_Response * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Response__fini(gripper_interfaces__action__Gripper_SendGoal_Response * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_SendGoal_Response *
gripper_interfaces__action__Gripper_SendGoal_Response__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Response__destroy(gripper_interfaces__action__Gripper_SendGoal_Response * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Response__are_equal(const gripper_interfaces__action__Gripper_SendGoal_Response * lhs, const gripper_interfaces__action__Gripper_SendGoal_Response * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_SendGoal_Response__copy(
  const gripper_interfaces__action__Gripper_SendGoal_Response * input,
  gripper_interfaces__action__Gripper_SendGoal_Response * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__init(gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__fini(gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence *
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__destroy(gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__are_equal(const gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * lhs, const gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_SendGoal_Response__Sequence__copy(
  const gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * input,
  gripper_interfaces__action__Gripper_SendGoal_Response__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_GetResult_Request
 * )) before or use
 * gripper_interfaces__action__Gripper_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Request__init(gripper_interfaces__action__Gripper_GetResult_Request * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Request__fini(gripper_interfaces__action__Gripper_GetResult_Request * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_GetResult_Request *
gripper_interfaces__action__Gripper_GetResult_Request__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Request__destroy(gripper_interfaces__action__Gripper_GetResult_Request * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Request__are_equal(const gripper_interfaces__action__Gripper_GetResult_Request * lhs, const gripper_interfaces__action__Gripper_GetResult_Request * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_GetResult_Request__copy(
  const gripper_interfaces__action__Gripper_GetResult_Request * input,
  gripper_interfaces__action__Gripper_GetResult_Request * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Request__Sequence__init(gripper_interfaces__action__Gripper_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Request__Sequence__fini(gripper_interfaces__action__Gripper_GetResult_Request__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_GetResult_Request__Sequence *
gripper_interfaces__action__Gripper_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Request__Sequence__destroy(gripper_interfaces__action__Gripper_GetResult_Request__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Request__Sequence__are_equal(const gripper_interfaces__action__Gripper_GetResult_Request__Sequence * lhs, const gripper_interfaces__action__Gripper_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_GetResult_Request__Sequence__copy(
  const gripper_interfaces__action__Gripper_GetResult_Request__Sequence * input,
  gripper_interfaces__action__Gripper_GetResult_Request__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_GetResult_Response
 * )) before or use
 * gripper_interfaces__action__Gripper_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Response__init(gripper_interfaces__action__Gripper_GetResult_Response * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Response__fini(gripper_interfaces__action__Gripper_GetResult_Response * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_GetResult_Response *
gripper_interfaces__action__Gripper_GetResult_Response__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Response__destroy(gripper_interfaces__action__Gripper_GetResult_Response * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Response__are_equal(const gripper_interfaces__action__Gripper_GetResult_Response * lhs, const gripper_interfaces__action__Gripper_GetResult_Response * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_GetResult_Response__copy(
  const gripper_interfaces__action__Gripper_GetResult_Response * input,
  gripper_interfaces__action__Gripper_GetResult_Response * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Response__Sequence__init(gripper_interfaces__action__Gripper_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Response__Sequence__fini(gripper_interfaces__action__Gripper_GetResult_Response__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_GetResult_Response__Sequence *
gripper_interfaces__action__Gripper_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_GetResult_Response__Sequence__destroy(gripper_interfaces__action__Gripper_GetResult_Response__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_GetResult_Response__Sequence__are_equal(const gripper_interfaces__action__Gripper_GetResult_Response__Sequence * lhs, const gripper_interfaces__action__Gripper_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_GetResult_Response__Sequence__copy(
  const gripper_interfaces__action__Gripper_GetResult_Response__Sequence * input,
  gripper_interfaces__action__Gripper_GetResult_Response__Sequence * output);

/// Initialize action/Gripper message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gripper_interfaces__action__Gripper_FeedbackMessage
 * )) before or use
 * gripper_interfaces__action__Gripper_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_FeedbackMessage__init(gripper_interfaces__action__Gripper_FeedbackMessage * msg);

/// Finalize action/Gripper message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_FeedbackMessage__fini(gripper_interfaces__action__Gripper_FeedbackMessage * msg);

/// Create action/Gripper message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gripper_interfaces__action__Gripper_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_FeedbackMessage *
gripper_interfaces__action__Gripper_FeedbackMessage__create();

/// Destroy action/Gripper message.
/**
 * It calls
 * gripper_interfaces__action__Gripper_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_FeedbackMessage__destroy(gripper_interfaces__action__Gripper_FeedbackMessage * msg);

/// Check for action/Gripper message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_FeedbackMessage__are_equal(const gripper_interfaces__action__Gripper_FeedbackMessage * lhs, const gripper_interfaces__action__Gripper_FeedbackMessage * rhs);

/// Copy a action/Gripper message.
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
gripper_interfaces__action__Gripper_FeedbackMessage__copy(
  const gripper_interfaces__action__Gripper_FeedbackMessage * input,
  gripper_interfaces__action__Gripper_FeedbackMessage * output);

/// Initialize array of action/Gripper messages.
/**
 * It allocates the memory for the number of elements and calls
 * gripper_interfaces__action__Gripper_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__init(gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__fini(gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * array);

/// Create array of action/Gripper messages.
/**
 * It allocates the memory for the array and calls
 * gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence *
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Gripper messages.
/**
 * It calls
 * gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
void
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__destroy(gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * array);

/// Check for action/Gripper message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gripper_interfaces
bool
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__are_equal(const gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * lhs, const gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Gripper messages.
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
gripper_interfaces__action__Gripper_FeedbackMessage__Sequence__copy(
  const gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * input,
  gripper_interfaces__action__Gripper_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GRIPPER_INTERFACES__ACTION__DETAIL__GRIPPER__FUNCTIONS_H_
