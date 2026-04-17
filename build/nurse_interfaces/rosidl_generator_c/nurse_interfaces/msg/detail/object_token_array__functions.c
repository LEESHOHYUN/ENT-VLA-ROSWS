// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nurse_interfaces:msg/ObjectTokenArray.idl
// generated code does not contain a copyright notice
#include "nurse_interfaces/msg/detail/object_token_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `tokens`
#include "nurse_interfaces/msg/detail/object_token__functions.h"

bool
nurse_interfaces__msg__ObjectTokenArray__init(nurse_interfaces__msg__ObjectTokenArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nurse_interfaces__msg__ObjectTokenArray__fini(msg);
    return false;
  }
  // tokens
  if (!nurse_interfaces__msg__ObjectToken__Sequence__init(&msg->tokens, 0)) {
    nurse_interfaces__msg__ObjectTokenArray__fini(msg);
    return false;
  }
  return true;
}

void
nurse_interfaces__msg__ObjectTokenArray__fini(nurse_interfaces__msg__ObjectTokenArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // tokens
  nurse_interfaces__msg__ObjectToken__Sequence__fini(&msg->tokens);
}

bool
nurse_interfaces__msg__ObjectTokenArray__are_equal(const nurse_interfaces__msg__ObjectTokenArray * lhs, const nurse_interfaces__msg__ObjectTokenArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // tokens
  if (!nurse_interfaces__msg__ObjectToken__Sequence__are_equal(
      &(lhs->tokens), &(rhs->tokens)))
  {
    return false;
  }
  return true;
}

bool
nurse_interfaces__msg__ObjectTokenArray__copy(
  const nurse_interfaces__msg__ObjectTokenArray * input,
  nurse_interfaces__msg__ObjectTokenArray * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // tokens
  if (!nurse_interfaces__msg__ObjectToken__Sequence__copy(
      &(input->tokens), &(output->tokens)))
  {
    return false;
  }
  return true;
}

nurse_interfaces__msg__ObjectTokenArray *
nurse_interfaces__msg__ObjectTokenArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__ObjectTokenArray * msg = (nurse_interfaces__msg__ObjectTokenArray *)allocator.allocate(sizeof(nurse_interfaces__msg__ObjectTokenArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nurse_interfaces__msg__ObjectTokenArray));
  bool success = nurse_interfaces__msg__ObjectTokenArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nurse_interfaces__msg__ObjectTokenArray__destroy(nurse_interfaces__msg__ObjectTokenArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nurse_interfaces__msg__ObjectTokenArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nurse_interfaces__msg__ObjectTokenArray__Sequence__init(nurse_interfaces__msg__ObjectTokenArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__ObjectTokenArray * data = NULL;

  if (size) {
    data = (nurse_interfaces__msg__ObjectTokenArray *)allocator.zero_allocate(size, sizeof(nurse_interfaces__msg__ObjectTokenArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nurse_interfaces__msg__ObjectTokenArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nurse_interfaces__msg__ObjectTokenArray__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
nurse_interfaces__msg__ObjectTokenArray__Sequence__fini(nurse_interfaces__msg__ObjectTokenArray__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nurse_interfaces__msg__ObjectTokenArray__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

nurse_interfaces__msg__ObjectTokenArray__Sequence *
nurse_interfaces__msg__ObjectTokenArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__ObjectTokenArray__Sequence * array = (nurse_interfaces__msg__ObjectTokenArray__Sequence *)allocator.allocate(sizeof(nurse_interfaces__msg__ObjectTokenArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nurse_interfaces__msg__ObjectTokenArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nurse_interfaces__msg__ObjectTokenArray__Sequence__destroy(nurse_interfaces__msg__ObjectTokenArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nurse_interfaces__msg__ObjectTokenArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nurse_interfaces__msg__ObjectTokenArray__Sequence__are_equal(const nurse_interfaces__msg__ObjectTokenArray__Sequence * lhs, const nurse_interfaces__msg__ObjectTokenArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nurse_interfaces__msg__ObjectTokenArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nurse_interfaces__msg__ObjectTokenArray__Sequence__copy(
  const nurse_interfaces__msg__ObjectTokenArray__Sequence * input,
  nurse_interfaces__msg__ObjectTokenArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nurse_interfaces__msg__ObjectTokenArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nurse_interfaces__msg__ObjectTokenArray * data =
      (nurse_interfaces__msg__ObjectTokenArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nurse_interfaces__msg__ObjectTokenArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nurse_interfaces__msg__ObjectTokenArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nurse_interfaces__msg__ObjectTokenArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
