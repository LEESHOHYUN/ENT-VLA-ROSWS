// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ur_robot_manager_interfaces:action/RobotTask.idl
// generated code does not contain a copyright notice
#include "ur_robot_manager_interfaces/action/detail/robot_task__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_Goal__init(ur_robot_manager_interfaces__action__RobotTask_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // task_id
  // positions
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positions, 0)) {
    ur_robot_manager_interfaces__action__RobotTask_Goal__fini(msg);
    return false;
  }
  // tool_type
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_Goal__fini(ur_robot_manager_interfaces__action__RobotTask_Goal * msg)
{
  if (!msg) {
    return;
  }
  // task_id
  // positions
  rosidl_runtime_c__double__Sequence__fini(&msg->positions);
  // tool_type
}

bool
ur_robot_manager_interfaces__action__RobotTask_Goal__are_equal(const ur_robot_manager_interfaces__action__RobotTask_Goal * lhs, const ur_robot_manager_interfaces__action__RobotTask_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_id
  if (lhs->task_id != rhs->task_id) {
    return false;
  }
  // positions
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positions), &(rhs->positions)))
  {
    return false;
  }
  // tool_type
  if (lhs->tool_type != rhs->tool_type) {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_Goal__copy(
  const ur_robot_manager_interfaces__action__RobotTask_Goal * input,
  ur_robot_manager_interfaces__action__RobotTask_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // task_id
  output->task_id = input->task_id;
  // positions
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positions), &(output->positions)))
  {
    return false;
  }
  // tool_type
  output->tool_type = input->tool_type;
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_Goal *
ur_robot_manager_interfaces__action__RobotTask_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Goal * msg = (ur_robot_manager_interfaces__action__RobotTask_Goal *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_Goal));
  bool success = ur_robot_manager_interfaces__action__RobotTask_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_Goal__destroy(ur_robot_manager_interfaces__action__RobotTask_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Goal * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_Goal *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_Goal__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_Goal__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence *
ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_Goal * data =
      (ur_robot_manager_interfaces__action__RobotTask_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error_message`
#include "rosidl_runtime_c/string_functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_Result__init(ur_robot_manager_interfaces__action__RobotTask_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_message
  if (!rosidl_runtime_c__String__init(&msg->error_message)) {
    ur_robot_manager_interfaces__action__RobotTask_Result__fini(msg);
    return false;
  }
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_Result__fini(ur_robot_manager_interfaces__action__RobotTask_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_message
  rosidl_runtime_c__String__fini(&msg->error_message);
}

bool
ur_robot_manager_interfaces__action__RobotTask_Result__are_equal(const ur_robot_manager_interfaces__action__RobotTask_Result * lhs, const ur_robot_manager_interfaces__action__RobotTask_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_message), &(rhs->error_message)))
  {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_Result__copy(
  const ur_robot_manager_interfaces__action__RobotTask_Result * input,
  ur_robot_manager_interfaces__action__RobotTask_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_message
  if (!rosidl_runtime_c__String__copy(
      &(input->error_message), &(output->error_message)))
  {
    return false;
  }
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_Result *
ur_robot_manager_interfaces__action__RobotTask_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Result * msg = (ur_robot_manager_interfaces__action__RobotTask_Result *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_Result));
  bool success = ur_robot_manager_interfaces__action__RobotTask_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_Result__destroy(ur_robot_manager_interfaces__action__RobotTask_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Result * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_Result *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_Result__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_Result__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_Result__Sequence *
ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_Result__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_Result__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_Result * data =
      (ur_robot_manager_interfaces__action__RobotTask_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_Feedback__init(ur_robot_manager_interfaces__action__RobotTask_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(msg);
    return false;
  }
  // completion_percentage
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(ur_robot_manager_interfaces__action__RobotTask_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // completion_percentage
}

bool
ur_robot_manager_interfaces__action__RobotTask_Feedback__are_equal(const ur_robot_manager_interfaces__action__RobotTask_Feedback * lhs, const ur_robot_manager_interfaces__action__RobotTask_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // completion_percentage
  if (lhs->completion_percentage != rhs->completion_percentage) {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_Feedback__copy(
  const ur_robot_manager_interfaces__action__RobotTask_Feedback * input,
  ur_robot_manager_interfaces__action__RobotTask_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // completion_percentage
  output->completion_percentage = input->completion_percentage;
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_Feedback *
ur_robot_manager_interfaces__action__RobotTask_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Feedback * msg = (ur_robot_manager_interfaces__action__RobotTask_Feedback *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_Feedback));
  bool success = ur_robot_manager_interfaces__action__RobotTask_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_Feedback__destroy(ur_robot_manager_interfaces__action__RobotTask_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Feedback * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_Feedback *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence *
ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_Feedback * data =
      (ur_robot_manager_interfaces__action__RobotTask_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "ur_robot_manager_interfaces/action/detail/robot_task__functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!ur_robot_manager_interfaces__action__RobotTask_Goal__init(&msg->goal)) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  ur_robot_manager_interfaces__action__RobotTask_Goal__fini(&msg->goal);
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__are_equal(const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * lhs, const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!ur_robot_manager_interfaces__action__RobotTask_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__copy(
  const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * input,
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!ur_robot_manager_interfaces__action__RobotTask_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request *
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * msg = (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request));
  bool success = ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__destroy(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence *
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request * data =
      (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__fini(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__are_equal(const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * lhs, const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__copy(
  const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * input,
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response *
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * msg = (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response));
  bool success = ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__destroy(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence *
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response * data =
      (ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__fini(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__are_equal(const ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * lhs, const ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__copy(
  const ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * input,
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_GetResult_Request *
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * msg = (ur_robot_manager_interfaces__action__RobotTask_GetResult_Request *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request));
  bool success = ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__destroy(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_GetResult_Request *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence *
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Request * data =
      (ur_robot_manager_interfaces__action__RobotTask_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "ur_robot_manager_interfaces/action/detail/robot_task__functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!ur_robot_manager_interfaces__action__RobotTask_Result__init(&msg->result)) {
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__fini(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  ur_robot_manager_interfaces__action__RobotTask_Result__fini(&msg->result);
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__are_equal(const ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * lhs, const ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!ur_robot_manager_interfaces__action__RobotTask_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__copy(
  const ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * input,
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!ur_robot_manager_interfaces__action__RobotTask_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_GetResult_Response *
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * msg = (ur_robot_manager_interfaces__action__RobotTask_GetResult_Response *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response));
  bool success = ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__destroy(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_GetResult_Response *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence *
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_GetResult_Response * data =
      (ur_robot_manager_interfaces__action__RobotTask_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "ur_robot_manager_interfaces/action/detail/robot_task__functions.h"

bool
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!ur_robot_manager_interfaces__action__RobotTask_Feedback__init(&msg->feedback)) {
    ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  ur_robot_manager_interfaces__action__RobotTask_Feedback__fini(&msg->feedback);
}

bool
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__are_equal(const ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * lhs, const ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!ur_robot_manager_interfaces__action__RobotTask_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__copy(
  const ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * input,
  ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!ur_robot_manager_interfaces__action__RobotTask_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage *
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * msg = (ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage));
  bool success = ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__destroy(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__init(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * data = NULL;

  if (size) {
    data = (ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage *)allocator.zero_allocate(size, sizeof(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(&data[i - 1]);
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
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__fini(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * array)
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
      ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(&array->data[i]);
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

ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence *
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * array = (ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence *)allocator.allocate(sizeof(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__destroy(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__are_equal(const ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * lhs, const ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence__copy(
  const ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * input,
  ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage * data =
      (ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ur_robot_manager_interfaces__action__RobotTask_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
