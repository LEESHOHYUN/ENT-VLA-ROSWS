// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nurse_interfaces:msg/EmergencySignal.idl
// generated code does not contain a copyright notice
#include "nurse_interfaces/msg/detail/emergency_signal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `detail`
#include "rosidl_runtime_c/string_functions.h"

bool
nurse_interfaces__msg__EmergencySignal__init(nurse_interfaces__msg__EmergencySignal * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nurse_interfaces__msg__EmergencySignal__fini(msg);
    return false;
  }
  // status
  // confidence
  // detail
  if (!rosidl_runtime_c__String__init(&msg->detail)) {
    nurse_interfaces__msg__EmergencySignal__fini(msg);
    return false;
  }
  return true;
}

void
nurse_interfaces__msg__EmergencySignal__fini(nurse_interfaces__msg__EmergencySignal * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // status
  // confidence
  // detail
  rosidl_runtime_c__String__fini(&msg->detail);
}

bool
nurse_interfaces__msg__EmergencySignal__are_equal(const nurse_interfaces__msg__EmergencySignal * lhs, const nurse_interfaces__msg__EmergencySignal * rhs)
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
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // detail
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->detail), &(rhs->detail)))
  {
    return false;
  }
  return true;
}

bool
nurse_interfaces__msg__EmergencySignal__copy(
  const nurse_interfaces__msg__EmergencySignal * input,
  nurse_interfaces__msg__EmergencySignal * output)
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
  // status
  output->status = input->status;
  // confidence
  output->confidence = input->confidence;
  // detail
  if (!rosidl_runtime_c__String__copy(
      &(input->detail), &(output->detail)))
  {
    return false;
  }
  return true;
}

nurse_interfaces__msg__EmergencySignal *
nurse_interfaces__msg__EmergencySignal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__EmergencySignal * msg = (nurse_interfaces__msg__EmergencySignal *)allocator.allocate(sizeof(nurse_interfaces__msg__EmergencySignal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nurse_interfaces__msg__EmergencySignal));
  bool success = nurse_interfaces__msg__EmergencySignal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nurse_interfaces__msg__EmergencySignal__destroy(nurse_interfaces__msg__EmergencySignal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nurse_interfaces__msg__EmergencySignal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nurse_interfaces__msg__EmergencySignal__Sequence__init(nurse_interfaces__msg__EmergencySignal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__EmergencySignal * data = NULL;

  if (size) {
    data = (nurse_interfaces__msg__EmergencySignal *)allocator.zero_allocate(size, sizeof(nurse_interfaces__msg__EmergencySignal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nurse_interfaces__msg__EmergencySignal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nurse_interfaces__msg__EmergencySignal__fini(&data[i - 1]);
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
nurse_interfaces__msg__EmergencySignal__Sequence__fini(nurse_interfaces__msg__EmergencySignal__Sequence * array)
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
      nurse_interfaces__msg__EmergencySignal__fini(&array->data[i]);
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

nurse_interfaces__msg__EmergencySignal__Sequence *
nurse_interfaces__msg__EmergencySignal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nurse_interfaces__msg__EmergencySignal__Sequence * array = (nurse_interfaces__msg__EmergencySignal__Sequence *)allocator.allocate(sizeof(nurse_interfaces__msg__EmergencySignal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nurse_interfaces__msg__EmergencySignal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nurse_interfaces__msg__EmergencySignal__Sequence__destroy(nurse_interfaces__msg__EmergencySignal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nurse_interfaces__msg__EmergencySignal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nurse_interfaces__msg__EmergencySignal__Sequence__are_equal(const nurse_interfaces__msg__EmergencySignal__Sequence * lhs, const nurse_interfaces__msg__EmergencySignal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nurse_interfaces__msg__EmergencySignal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nurse_interfaces__msg__EmergencySignal__Sequence__copy(
  const nurse_interfaces__msg__EmergencySignal__Sequence * input,
  nurse_interfaces__msg__EmergencySignal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nurse_interfaces__msg__EmergencySignal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nurse_interfaces__msg__EmergencySignal * data =
      (nurse_interfaces__msg__EmergencySignal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nurse_interfaces__msg__EmergencySignal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nurse_interfaces__msg__EmergencySignal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nurse_interfaces__msg__EmergencySignal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
