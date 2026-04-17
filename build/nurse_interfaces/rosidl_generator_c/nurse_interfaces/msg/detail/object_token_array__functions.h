// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__FUNCTIONS_H_
#define NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nurse_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "nurse_interfaces/msg/detail/object_token_array__struct.h"

/// Initialize msg/ObjectTokenArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nurse_interfaces__msg__ObjectTokenArray
 * )) before or use
 * nurse_interfaces__msg__ObjectTokenArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectTokenArray__init(nurse_interfaces__msg__ObjectTokenArray * msg);

/// Finalize msg/ObjectTokenArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectTokenArray__fini(nurse_interfaces__msg__ObjectTokenArray * msg);

/// Create msg/ObjectTokenArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nurse_interfaces__msg__ObjectTokenArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
nurse_interfaces__msg__ObjectTokenArray *
nurse_interfaces__msg__ObjectTokenArray__create();

/// Destroy msg/ObjectTokenArray message.
/**
 * It calls
 * nurse_interfaces__msg__ObjectTokenArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectTokenArray__destroy(nurse_interfaces__msg__ObjectTokenArray * msg);

/// Check for msg/ObjectTokenArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectTokenArray__are_equal(const nurse_interfaces__msg__ObjectTokenArray * lhs, const nurse_interfaces__msg__ObjectTokenArray * rhs);

/// Copy a msg/ObjectTokenArray message.
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
nurse_interfaces__msg__ObjectTokenArray__copy(
  const nurse_interfaces__msg__ObjectTokenArray * input,
  nurse_interfaces__msg__ObjectTokenArray * output);

/// Initialize array of msg/ObjectTokenArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * nurse_interfaces__msg__ObjectTokenArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectTokenArray__Sequence__init(nurse_interfaces__msg__ObjectTokenArray__Sequence * array, size_t size);

/// Finalize array of msg/ObjectTokenArray messages.
/**
 * It calls
 * nurse_interfaces__msg__ObjectTokenArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectTokenArray__Sequence__fini(nurse_interfaces__msg__ObjectTokenArray__Sequence * array);

/// Create array of msg/ObjectTokenArray messages.
/**
 * It allocates the memory for the array and calls
 * nurse_interfaces__msg__ObjectTokenArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
nurse_interfaces__msg__ObjectTokenArray__Sequence *
nurse_interfaces__msg__ObjectTokenArray__Sequence__create(size_t size);

/// Destroy array of msg/ObjectTokenArray messages.
/**
 * It calls
 * nurse_interfaces__msg__ObjectTokenArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__ObjectTokenArray__Sequence__destroy(nurse_interfaces__msg__ObjectTokenArray__Sequence * array);

/// Check for msg/ObjectTokenArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__ObjectTokenArray__Sequence__are_equal(const nurse_interfaces__msg__ObjectTokenArray__Sequence * lhs, const nurse_interfaces__msg__ObjectTokenArray__Sequence * rhs);

/// Copy an array of msg/ObjectTokenArray messages.
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
nurse_interfaces__msg__ObjectTokenArray__Sequence__copy(
  const nurse_interfaces__msg__ObjectTokenArray__Sequence * input,
  nurse_interfaces__msg__ObjectTokenArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__OBJECT_TOKEN_ARRAY__FUNCTIONS_H_
