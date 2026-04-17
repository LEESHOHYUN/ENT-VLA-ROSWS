// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gripper_interfaces:srv/SetParameter.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/srv/detail/set_parameter__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
gripper_interfaces__srv__SetParameter_Request__init(gripper_interfaces__srv__SetParameter_Request * msg)
{
  if (!msg) {
    return false;
  }
  // vel_max
  // acc_max
  return true;
}

void
gripper_interfaces__srv__SetParameter_Request__fini(gripper_interfaces__srv__SetParameter_Request * msg)
{
  if (!msg) {
    return;
  }
  // vel_max
  // acc_max
}

bool
gripper_interfaces__srv__SetParameter_Request__are_equal(const gripper_interfaces__srv__SetParameter_Request * lhs, const gripper_interfaces__srv__SetParameter_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vel_max
  if (lhs->vel_max != rhs->vel_max) {
    return false;
  }
  // acc_max
  if (lhs->acc_max != rhs->acc_max) {
    return false;
  }
  return true;
}

bool
gripper_interfaces__srv__SetParameter_Request__copy(
  const gripper_interfaces__srv__SetParameter_Request * input,
  gripper_interfaces__srv__SetParameter_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // vel_max
  output->vel_max = input->vel_max;
  // acc_max
  output->acc_max = input->acc_max;
  return true;
}

gripper_interfaces__srv__SetParameter_Request *
gripper_interfaces__srv__SetParameter_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__SetParameter_Request * msg = (gripper_interfaces__srv__SetParameter_Request *)allocator.allocate(sizeof(gripper_interfaces__srv__SetParameter_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gripper_interfaces__srv__SetParameter_Request));
  bool success = gripper_interfaces__srv__SetParameter_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gripper_interfaces__srv__SetParameter_Request__destroy(gripper_interfaces__srv__SetParameter_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gripper_interfaces__srv__SetParameter_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gripper_interfaces__srv__SetParameter_Request__Sequence__init(gripper_interfaces__srv__SetParameter_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__SetParameter_Request * data = NULL;

  if (size) {
    data = (gripper_interfaces__srv__SetParameter_Request *)allocator.zero_allocate(size, sizeof(gripper_interfaces__srv__SetParameter_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gripper_interfaces__srv__SetParameter_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gripper_interfaces__srv__SetParameter_Request__fini(&data[i - 1]);
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
gripper_interfaces__srv__SetParameter_Request__Sequence__fini(gripper_interfaces__srv__SetParameter_Request__Sequence * array)
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
      gripper_interfaces__srv__SetParameter_Request__fini(&array->data[i]);
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

gripper_interfaces__srv__SetParameter_Request__Sequence *
gripper_interfaces__srv__SetParameter_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__SetParameter_Request__Sequence * array = (gripper_interfaces__srv__SetParameter_Request__Sequence *)allocator.allocate(sizeof(gripper_interfaces__srv__SetParameter_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gripper_interfaces__srv__SetParameter_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gripper_interfaces__srv__SetParameter_Request__Sequence__destroy(gripper_interfaces__srv__SetParameter_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gripper_interfaces__srv__SetParameter_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gripper_interfaces__srv__SetParameter_Request__Sequence__are_equal(const gripper_interfaces__srv__SetParameter_Request__Sequence * lhs, const gripper_interfaces__srv__SetParameter_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gripper_interfaces__srv__SetParameter_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gripper_interfaces__srv__SetParameter_Request__Sequence__copy(
  const gripper_interfaces__srv__SetParameter_Request__Sequence * input,
  gripper_interfaces__srv__SetParameter_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gripper_interfaces__srv__SetParameter_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gripper_interfaces__srv__SetParameter_Request * data =
      (gripper_interfaces__srv__SetParameter_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gripper_interfaces__srv__SetParameter_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gripper_interfaces__srv__SetParameter_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gripper_interfaces__srv__SetParameter_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
gripper_interfaces__srv__SetParameter_Response__init(gripper_interfaces__srv__SetParameter_Response * msg)
{
  if (!msg) {
    return false;
  }
  // successed
  return true;
}

void
gripper_interfaces__srv__SetParameter_Response__fini(gripper_interfaces__srv__SetParameter_Response * msg)
{
  if (!msg) {
    return;
  }
  // successed
}

bool
gripper_interfaces__srv__SetParameter_Response__are_equal(const gripper_interfaces__srv__SetParameter_Response * lhs, const gripper_interfaces__srv__SetParameter_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // successed
  if (lhs->successed != rhs->successed) {
    return false;
  }
  return true;
}

bool
gripper_interfaces__srv__SetParameter_Response__copy(
  const gripper_interfaces__srv__SetParameter_Response * input,
  gripper_interfaces__srv__SetParameter_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // successed
  output->successed = input->successed;
  return true;
}

gripper_interfaces__srv__SetParameter_Response *
gripper_interfaces__srv__SetParameter_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__SetParameter_Response * msg = (gripper_interfaces__srv__SetParameter_Response *)allocator.allocate(sizeof(gripper_interfaces__srv__SetParameter_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gripper_interfaces__srv__SetParameter_Response));
  bool success = gripper_interfaces__srv__SetParameter_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gripper_interfaces__srv__SetParameter_Response__destroy(gripper_interfaces__srv__SetParameter_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gripper_interfaces__srv__SetParameter_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gripper_interfaces__srv__SetParameter_Response__Sequence__init(gripper_interfaces__srv__SetParameter_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__SetParameter_Response * data = NULL;

  if (size) {
    data = (gripper_interfaces__srv__SetParameter_Response *)allocator.zero_allocate(size, sizeof(gripper_interfaces__srv__SetParameter_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gripper_interfaces__srv__SetParameter_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gripper_interfaces__srv__SetParameter_Response__fini(&data[i - 1]);
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
gripper_interfaces__srv__SetParameter_Response__Sequence__fini(gripper_interfaces__srv__SetParameter_Response__Sequence * array)
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
      gripper_interfaces__srv__SetParameter_Response__fini(&array->data[i]);
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

gripper_interfaces__srv__SetParameter_Response__Sequence *
gripper_interfaces__srv__SetParameter_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__SetParameter_Response__Sequence * array = (gripper_interfaces__srv__SetParameter_Response__Sequence *)allocator.allocate(sizeof(gripper_interfaces__srv__SetParameter_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gripper_interfaces__srv__SetParameter_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gripper_interfaces__srv__SetParameter_Response__Sequence__destroy(gripper_interfaces__srv__SetParameter_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gripper_interfaces__srv__SetParameter_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gripper_interfaces__srv__SetParameter_Response__Sequence__are_equal(const gripper_interfaces__srv__SetParameter_Response__Sequence * lhs, const gripper_interfaces__srv__SetParameter_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gripper_interfaces__srv__SetParameter_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gripper_interfaces__srv__SetParameter_Response__Sequence__copy(
  const gripper_interfaces__srv__SetParameter_Response__Sequence * input,
  gripper_interfaces__srv__SetParameter_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gripper_interfaces__srv__SetParameter_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gripper_interfaces__srv__SetParameter_Response * data =
      (gripper_interfaces__srv__SetParameter_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gripper_interfaces__srv__SetParameter_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gripper_interfaces__srv__SetParameter_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gripper_interfaces__srv__SetParameter_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
