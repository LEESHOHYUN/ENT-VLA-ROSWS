// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nurse_interfaces:msg/ObjectToken.idl
// generated code does not contain a copyright notice
#include "nurse_interfaces/msg/detail/object_token__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `object_id`
// Member `object_class`
#include "rosidl_runtime_c/string_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
nurse_interfaces__msg__ObjectToken__init(nurse_interfaces__msg__ObjectToken * msg)
{
  if (!msg) {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__init(&msg->object_id)) {
    nurse_interfaces__msg__ObjectToken__fini(msg);
    return false;
  }
  // object_class
  if (!rosidl_runtime_c__String__init(&msg->object_class)) {
    nurse_interfaces__msg__ObjectToken__fini(msg);
    return false;
  }
  // bbox
  // confidence
  // visible
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    nurse_interfaces__msg__ObjectToken__fini(msg);
    return false;
  }
  return true;
}

void
nurse_interfaces__msg__ObjectToken__fini(nurse_interfaces__msg__ObjectToken * msg)
{
  if (!msg) {
    return;
  }
  // object_id
  rosidl_runtime_c__String__fini(&msg->object_id);
  // object_class
  rosidl_runtime_c__String__fini(&msg->object_class);
  // bbox
  // confidence
  // visible
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
}

bool
nurse_interfaces__msg__ObjectToken__are_equal(const nurse_interfaces__msg__ObjectToken * lhs, const nurse_interfaces__msg__ObjectToken * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object_id), &(rhs->object_id)))
  {
    return false;
  }
  // object_class
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object_class), &(rhs->object_class)))
  {
    return false;
  }
  // bbox
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->bbox[i] != rhs->bbox[i]) {
      return false;
    }
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // visible
  if (lhs->visible != rhs->visible) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  return true;
}

bool
nurse_interfaces__msg__ObjectToken__copy(
  const nurse_interfaces__msg__ObjectToken * input,
  nurse_interfaces__msg__ObjectToken * output)
{
  if (!input || !output) {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__copy(
      &(input->object_id), &(output->object_id)))
  {
    return false;
  }
  // object_class
  if (!rosidl_runtime_c__String__copy(
      &(input->object_class), &(output->object_class)))
  {
    return false;
  }
  // bbox
  for (size_t i = 0; i < 4; ++i) {
    output->bbox[i] = input->bbox[i];
  }
  // confidence
  output->confidence = input->confidence;
  // visible
  output->visible = input->visible;
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  return true;
}

nurse_interfaces__msg__ObjectToken *
nurse_interfaces__msg__ObjectToken__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__ObjectToken * msg = (nurse_interfaces__msg__ObjectToken *)allocator.allocate(sizeof(nurse_interfaces__msg__ObjectToken), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nurse_interfaces__msg__ObjectToken));
  bool success = nurse_interfaces__msg__ObjectToken__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nurse_interfaces__msg__ObjectToken__destroy(nurse_interfaces__msg__ObjectToken * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nurse_interfaces__msg__ObjectToken__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nurse_interfaces__msg__ObjectToken__Sequence__init(nurse_interfaces__msg__ObjectToken__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__ObjectToken * data = NULL;

  if (size) {
    data = (nurse_interfaces__msg__ObjectToken *)allocator.zero_allocate(size, sizeof(nurse_interfaces__msg__ObjectToken), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nurse_interfaces__msg__ObjectToken__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nurse_interfaces__msg__ObjectToken__fini(&data[i - 1]);
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
nurse_interfaces__msg__ObjectToken__Sequence__fini(nurse_interfaces__msg__ObjectToken__Sequence * array)
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
      nurse_interfaces__msg__ObjectToken__fini(&array->data[i]);
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

nurse_interfaces__msg__ObjectToken__Sequence *
nurse_interfaces__msg__ObjectToken__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__ObjectToken__Sequence * array = (nurse_interfaces__msg__ObjectToken__Sequence *)allocator.allocate(sizeof(nurse_interfaces__msg__ObjectToken__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nurse_interfaces__msg__ObjectToken__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nurse_interfaces__msg__ObjectToken__Sequence__destroy(nurse_interfaces__msg__ObjectToken__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nurse_interfaces__msg__ObjectToken__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nurse_interfaces__msg__ObjectToken__Sequence__are_equal(const nurse_interfaces__msg__ObjectToken__Sequence * lhs, const nurse_interfaces__msg__ObjectToken__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nurse_interfaces__msg__ObjectToken__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nurse_interfaces__msg__ObjectToken__Sequence__copy(
  const nurse_interfaces__msg__ObjectToken__Sequence * input,
  nurse_interfaces__msg__ObjectToken__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nurse_interfaces__msg__ObjectToken);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nurse_interfaces__msg__ObjectToken * data =
      (nurse_interfaces__msg__ObjectToken *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nurse_interfaces__msg__ObjectToken__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nurse_interfaces__msg__ObjectToken__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nurse_interfaces__msg__ObjectToken__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
