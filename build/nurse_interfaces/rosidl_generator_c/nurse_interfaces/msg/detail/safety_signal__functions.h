// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nurse_interfaces:msg/SafetySignal.idl
// generated code does not contain a copyright notice

#ifndef NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__FUNCTIONS_H_
#define NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nurse_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "nurse_interfaces/msg/detail/safety_signal__struct.h"

/// Initialize msg/SafetySignal message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nurse_interfaces__msg__SafetySignal
 * )) before or use
 * nurse_interfaces__msg__SafetySignal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__SafetySignal__init(nurse_interfaces__msg__SafetySignal * msg);

/// Finalize msg/SafetySignal message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__SafetySignal__fini(nurse_interfaces__msg__SafetySignal * msg);

/// Create msg/SafetySignal message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nurse_interfaces__msg__SafetySignal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
nurse_interfaces__msg__SafetySignal *
nurse_interfaces__msg__SafetySignal__create();

/// Destroy msg/SafetySignal message.
/**
 * It calls
 * nurse_interfaces__msg__SafetySignal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__SafetySignal__destroy(nurse_interfaces__msg__SafetySignal * msg);

/// Check for msg/SafetySignal message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__SafetySignal__are_equal(const nurse_interfaces__msg__SafetySignal * lhs, const nurse_interfaces__msg__SafetySignal * rhs);

/// Copy a msg/SafetySignal message.
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
nurse_interfaces__msg__SafetySignal__copy(
  const nurse_interfaces__msg__SafetySignal * input,
  nurse_interfaces__msg__SafetySignal * output);

/// Initialize array of msg/SafetySignal messages.
/**
 * It allocates the memory for the number of elements and calls
 * nurse_interfaces__msg__SafetySignal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__SafetySignal__Sequence__init(nurse_interfaces__msg__SafetySignal__Sequence * array, size_t size);

/// Finalize array of msg/SafetySignal messages.
/**
 * It calls
 * nurse_interfaces__msg__SafetySignal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__SafetySignal__Sequence__fini(nurse_interfaces__msg__SafetySignal__Sequence * array);

/// Create array of msg/SafetySignal messages.
/**
 * It allocates the memory for the array and calls
 * nurse_interfaces__msg__SafetySignal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
nurse_interfaces__msg__SafetySignal__Sequence *
nurse_interfaces__msg__SafetySignal__Sequence__create(size_t size);

/// Destroy array of msg/SafetySignal messages.
/**
 * It calls
 * nurse_interfaces__msg__SafetySignal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
void
nurse_interfaces__msg__SafetySignal__Sequence__destroy(nurse_interfaces__msg__SafetySignal__Sequence * array);

/// Check for msg/SafetySignal message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nurse_interfaces
bool
nurse_interfaces__msg__SafetySignal__Sequence__are_equal(const nurse_interfaces__msg__SafetySignal__Sequence * lhs, const nurse_interfaces__msg__SafetySignal__Sequence * rhs);

/// Copy an array of msg/SafetySignal messages.
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
nurse_interfaces__msg__SafetySignal__Sequence__copy(
  const nurse_interfaces__msg__SafetySignal__Sequence * input,
  nurse_interfaces__msg__SafetySignal__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NURSE_INTERFACES__MSG__DETAIL__SAFETY_SIGNAL__FUNCTIONS_H_
