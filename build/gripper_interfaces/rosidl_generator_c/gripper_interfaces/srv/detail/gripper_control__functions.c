// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gripper_interfaces:srv/GripperControl.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/srv/detail/gripper_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `torque_ctrl_param`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `custom_input`
// Member `gripper_init`
// Member `grasping_vel`
#include "rosidl_runtime_c/string_functions.h"

bool
gripper_interfaces__srv__GripperControl_Request__init(gripper_interfaces__srv__GripperControl_Request * msg)
{
  if (!msg) {
    return false;
  }
  // control_mode
  // pos_ctrl_param
  // vel_ctrl_param
  // torque_ctrl_param
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->torque_ctrl_param, 0)) {
    gripper_interfaces__srv__GripperControl_Request__fini(msg);
    return false;
  }
  // custom_input
  if (!rosidl_runtime_c__String__init(&msg->custom_input)) {
    gripper_interfaces__srv__GripperControl_Request__fini(msg);
    return false;
  }
  // gripper_init
  if (!rosidl_runtime_c__String__init(&msg->gripper_init)) {
    gripper_interfaces__srv__GripperControl_Request__fini(msg);
    return false;
  }
  // grasping_vel
  if (!rosidl_runtime_c__String__init(&msg->grasping_vel)) {
    gripper_interfaces__srv__GripperControl_Request__fini(msg);
    return false;
  }
  return true;
}

void
gripper_interfaces__srv__GripperControl_Request__fini(gripper_interfaces__srv__GripperControl_Request * msg)
{
  if (!msg) {
    return;
  }
  // control_mode
  // pos_ctrl_param
  // vel_ctrl_param
  // torque_ctrl_param
  rosidl_runtime_c__uint32__Sequence__fini(&msg->torque_ctrl_param);
  // custom_input
  rosidl_runtime_c__String__fini(&msg->custom_input);
  // gripper_init
  rosidl_runtime_c__String__fini(&msg->gripper_init);
  // grasping_vel
  rosidl_runtime_c__String__fini(&msg->grasping_vel);
}

bool
gripper_interfaces__srv__GripperControl_Request__are_equal(const gripper_interfaces__srv__GripperControl_Request * lhs, const gripper_interfaces__srv__GripperControl_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // control_mode
  if (lhs->control_mode != rhs->control_mode) {
    return false;
  }
  // pos_ctrl_param
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->pos_ctrl_param[i] != rhs->pos_ctrl_param[i]) {
      return false;
    }
  }
  // vel_ctrl_param
  for (size_t i = 0; i < 3; ++i) {
    if (lhs->vel_ctrl_param[i] != rhs->vel_ctrl_param[i]) {
      return false;
    }
  }
  // torque_ctrl_param
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->torque_ctrl_param), &(rhs->torque_ctrl_param)))
  {
    return false;
  }
  // custom_input
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->custom_input), &(rhs->custom_input)))
  {
    return false;
  }
  // gripper_init
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->gripper_init), &(rhs->gripper_init)))
  {
    return false;
  }
  // grasping_vel
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->grasping_vel), &(rhs->grasping_vel)))
  {
    return false;
  }
  return true;
}

bool
gripper_interfaces__srv__GripperControl_Request__copy(
  const gripper_interfaces__srv__GripperControl_Request * input,
  gripper_interfaces__srv__GripperControl_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // control_mode
  output->control_mode = input->control_mode;
  // pos_ctrl_param
  for (size_t i = 0; i < 3; ++i) {
    output->pos_ctrl_param[i] = input->pos_ctrl_param[i];
  }
  // vel_ctrl_param
  for (size_t i = 0; i < 3; ++i) {
    output->vel_ctrl_param[i] = input->vel_ctrl_param[i];
  }
  // torque_ctrl_param
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->torque_ctrl_param), &(output->torque_ctrl_param)))
  {
    return false;
  }
  // custom_input
  if (!rosidl_runtime_c__String__copy(
      &(input->custom_input), &(output->custom_input)))
  {
    return false;
  }
  // gripper_init
  if (!rosidl_runtime_c__String__copy(
      &(input->gripper_init), &(output->gripper_init)))
  {
    return false;
  }
  // grasping_vel
  if (!rosidl_runtime_c__String__copy(
      &(input->grasping_vel), &(output->grasping_vel)))
  {
    return false;
  }
  return true;
}

gripper_interfaces__srv__GripperControl_Request *
gripper_interfaces__srv__GripperControl_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__GripperControl_Request * msg = (gripper_interfaces__srv__GripperControl_Request *)allocator.allocate(sizeof(gripper_interfaces__srv__GripperControl_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gripper_interfaces__srv__GripperControl_Request));
  bool success = gripper_interfaces__srv__GripperControl_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gripper_interfaces__srv__GripperControl_Request__destroy(gripper_interfaces__srv__GripperControl_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gripper_interfaces__srv__GripperControl_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gripper_interfaces__srv__GripperControl_Request__Sequence__init(gripper_interfaces__srv__GripperControl_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__GripperControl_Request * data = NULL;

  if (size) {
    data = (gripper_interfaces__srv__GripperControl_Request *)allocator.zero_allocate(size, sizeof(gripper_interfaces__srv__GripperControl_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gripper_interfaces__srv__GripperControl_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gripper_interfaces__srv__GripperControl_Request__fini(&data[i - 1]);
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
gripper_interfaces__srv__GripperControl_Request__Sequence__fini(gripper_interfaces__srv__GripperControl_Request__Sequence * array)
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
      gripper_interfaces__srv__GripperControl_Request__fini(&array->data[i]);
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

gripper_interfaces__srv__GripperControl_Request__Sequence *
gripper_interfaces__srv__GripperControl_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__GripperControl_Request__Sequence * array = (gripper_interfaces__srv__GripperControl_Request__Sequence *)allocator.allocate(sizeof(gripper_interfaces__srv__GripperControl_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gripper_interfaces__srv__GripperControl_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gripper_interfaces__srv__GripperControl_Request__Sequence__destroy(gripper_interfaces__srv__GripperControl_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gripper_interfaces__srv__GripperControl_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gripper_interfaces__srv__GripperControl_Request__Sequence__are_equal(const gripper_interfaces__srv__GripperControl_Request__Sequence * lhs, const gripper_interfaces__srv__GripperControl_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gripper_interfaces__srv__GripperControl_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gripper_interfaces__srv__GripperControl_Request__Sequence__copy(
  const gripper_interfaces__srv__GripperControl_Request__Sequence * input,
  gripper_interfaces__srv__GripperControl_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gripper_interfaces__srv__GripperControl_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gripper_interfaces__srv__GripperControl_Request * data =
      (gripper_interfaces__srv__GripperControl_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gripper_interfaces__srv__GripperControl_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gripper_interfaces__srv__GripperControl_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gripper_interfaces__srv__GripperControl_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
gripper_interfaces__srv__GripperControl_Response__init(gripper_interfaces__srv__GripperControl_Response * msg)
{
  if (!msg) {
    return false;
  }
  // successed
  return true;
}

void
gripper_interfaces__srv__GripperControl_Response__fini(gripper_interfaces__srv__GripperControl_Response * msg)
{
  if (!msg) {
    return;
  }
  // successed
}

bool
gripper_interfaces__srv__GripperControl_Response__are_equal(const gripper_interfaces__srv__GripperControl_Response * lhs, const gripper_interfaces__srv__GripperControl_Response * rhs)
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
gripper_interfaces__srv__GripperControl_Response__copy(
  const gripper_interfaces__srv__GripperControl_Response * input,
  gripper_interfaces__srv__GripperControl_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // successed
  output->successed = input->successed;
  return true;
}

gripper_interfaces__srv__GripperControl_Response *
gripper_interfaces__srv__GripperControl_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__GripperControl_Response * msg = (gripper_interfaces__srv__GripperControl_Response *)allocator.allocate(sizeof(gripper_interfaces__srv__GripperControl_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gripper_interfaces__srv__GripperControl_Response));
  bool success = gripper_interfaces__srv__GripperControl_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gripper_interfaces__srv__GripperControl_Response__destroy(gripper_interfaces__srv__GripperControl_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gripper_interfaces__srv__GripperControl_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gripper_interfaces__srv__GripperControl_Response__Sequence__init(gripper_interfaces__srv__GripperControl_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__GripperControl_Response * data = NULL;

  if (size) {
    data = (gripper_interfaces__srv__GripperControl_Response *)allocator.zero_allocate(size, sizeof(gripper_interfaces__srv__GripperControl_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gripper_interfaces__srv__GripperControl_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gripper_interfaces__srv__GripperControl_Response__fini(&data[i - 1]);
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
gripper_interfaces__srv__GripperControl_Response__Sequence__fini(gripper_interfaces__srv__GripperControl_Response__Sequence * array)
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
      gripper_interfaces__srv__GripperControl_Response__fini(&array->data[i]);
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

gripper_interfaces__srv__GripperControl_Response__Sequence *
gripper_interfaces__srv__GripperControl_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__srv__GripperControl_Response__Sequence * array = (gripper_interfaces__srv__GripperControl_Response__Sequence *)allocator.allocate(sizeof(gripper_interfaces__srv__GripperControl_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gripper_interfaces__srv__GripperControl_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gripper_interfaces__srv__GripperControl_Response__Sequence__destroy(gripper_interfaces__srv__GripperControl_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gripper_interfaces__srv__GripperControl_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gripper_interfaces__srv__GripperControl_Response__Sequence__are_equal(const gripper_interfaces__srv__GripperControl_Response__Sequence * lhs, const gripper_interfaces__srv__GripperControl_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gripper_interfaces__srv__GripperControl_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gripper_interfaces__srv__GripperControl_Response__Sequence__copy(
  const gripper_interfaces__srv__GripperControl_Response__Sequence * input,
  gripper_interfaces__srv__GripperControl_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gripper_interfaces__srv__GripperControl_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gripper_interfaces__srv__GripperControl_Response * data =
      (gripper_interfaces__srv__GripperControl_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gripper_interfaces__srv__GripperControl_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gripper_interfaces__srv__GripperControl_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gripper_interfaces__srv__GripperControl_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
