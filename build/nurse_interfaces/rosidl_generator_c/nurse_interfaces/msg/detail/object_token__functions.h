// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__FUNCTIONS_H_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nurse_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "nurse_interfaces/msg/detail/object_token__struct.h"

/// Initialize msg/ObjectToken message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nurse_interfaces__msg__ObjectToken
 * )) before or use
 * nurse_interfaces__msg__ObjectToken__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectToken__init(nurse_interfaces__msg__ObjectToken * msg);

/// Finalize msg/ObjectToken message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectToken__fini(nurse_interfaces__msg__ObjectToken * msg);

/// Create msg/ObjectToken message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nurse_interfaces__msg__ObjectToken__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
nurse_interfaces__msg__ObjectToken *
nurse_interfaces__msg__ObjectToken__create();

/// Destroy msg/ObjectToken message.
/**
 * It calls
 * nurse_interfaces__msg__ObjectToken__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectToken__destroy(nurse_interfaces__msg__ObjectToken * msg);

/// Check for msg/ObjectToken message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectToken__are_equal(const nurse_interfaces__msg__ObjectToken * lhs, const nurse_interfaces__msg__ObjectToken * rhs);

/// Copy a msg/ObjectToken message.
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
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectToken__copy(
  const nurse_interfaces__msg__ObjectToken * input,
  nurse_interfaces__msg__ObjectToken * output);

/// Initialize array of msg/ObjectToken messages.
/**
 * It allocates the memory for the number of elements and calls
 * nurse_interfaces__msg__ObjectToken__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectToken__Sequence__init(nurse_interfaces__msg__ObjectToken__Sequence * array, size_t size);

/// Finalize array of msg/ObjectToken messages.
/**
 * It calls
 * nurse_interfaces__msg__ObjectToken__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectToken__Sequence__fini(nurse_interfaces__msg__ObjectToken__Sequence * array);

/// Create array of msg/ObjectToken messages.
/**
 * It allocates the memory for the array and calls
 * nurse_interfaces__msg__ObjectToken__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
nurse_interfaces__msg__ObjectToken__Sequence *
nurse_interfaces__msg__ObjectToken__Sequence__create(size_t size);

/// Destroy array of msg/ObjectToken messages.
/**
 * It calls
 * nurse_interfaces__msg__ObjectToken__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectToken__Sequence__destroy(nurse_interfaces__msg__ObjectToken__Sequence * array);

/// Check for msg/ObjectToken message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectToken__Sequence__are_equal(const nurse_interfaces__msg__ObjectToken__Sequence * lhs, const nurse_interfaces__msg__ObjectToken__Sequence * rhs);

/// Copy an array of msg/ObjectToken messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectToken__Sequence__copy(
  const nurse_interfaces__msg__ObjectToken__Sequence * input,
  nurse_interfaces__msg__ObjectToken__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN__FUNCTIONS_H_
