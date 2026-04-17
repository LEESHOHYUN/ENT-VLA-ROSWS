// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gripper_interfaces:msg/GripperMsg.idl
// generated code does not contain a copyright notice
#include "gripper_interfaces/msg/detail/gripper_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
gripper_interfaces__msg__GripperMsg__init(gripper_interfaces__msg__GripperMsg * msg)
{
  if (!msg) {
    return false;
  }
  // angle
  // current
  // velocity
  // grp_pos
  // is_motor_enable
  // is_grp_init_ongoing
  // is_pos_ongoing
  // is_vel_ongoing
  // is_tor_ongoing
  // is_grp_opening
  // is_grp_closing
  // grp_direction
  // is_object_grasp
  // is_fault_occured
  return true;
}

void
gripper_interfaces__msg__GripperMsg__fini(gripper_interfaces__msg__GripperMsg * msg)
{
  if (!msg) {
    return;
  }
  // angle
  // current
  // velocity
  // grp_pos
  // is_motor_enable
  // is_grp_init_ongoing
  // is_pos_ongoing
  // is_vel_ongoing
  // is_tor_ongoing
  // is_grp_opening
  // is_grp_closing
  // grp_direction
  // is_object_grasp
  // is_fault_occured
}

bool
gripper_interfaces__msg__GripperMsg__are_equal(const gripper_interfaces__msg__GripperMsg * lhs, const gripper_interfaces__msg__GripperMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  // grp_pos
  if (lhs->grp_pos != rhs->grp_pos) {
    return false;
  }
  // is_motor_enable
  if (lhs->is_motor_enable != rhs->is_motor_enable) {
    return false;
  }
  // is_grp_init_ongoing
  if (lhs->is_grp_init_ongoing != rhs->is_grp_init_ongoing) {
    return false;
  }
  // is_pos_ongoing
  if (lhs->is_pos_ongoing != rhs->is_pos_ongoing) {
    return false;
  }
  // is_vel_ongoing
  if (lhs->is_vel_ongoing != rhs->is_vel_ongoing) {
    return false;
  }
  // is_tor_ongoing
  if (lhs->is_tor_ongoing != rhs->is_tor_ongoing) {
    return false;
  }
  // is_grp_opening
  if (lhs->is_grp_opening != rhs->is_grp_opening) {
    return false;
  }
  // is_grp_closing
  if (lhs->is_grp_closing != rhs->is_grp_closing) {
    return false;
  }
  // grp_direction
  if (lhs->grp_direction != rhs->grp_direction) {
    return false;
  }
  // is_object_grasp
  if (lhs->is_object_grasp != rhs->is_object_grasp) {
    return false;
  }
  // is_fault_occured
  if (lhs->is_fault_occured != rhs->is_fault_occured) {
    return false;
  }
  return true;
}

bool
gripper_interfaces__msg__GripperMsg__copy(
  const gripper_interfaces__msg__GripperMsg * input,
  gripper_interfaces__msg__GripperMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // angle
  output->angle = input->angle;
  // current
  output->current = input->current;
  // velocity
  output->velocity = input->velocity;
  // grp_pos
  output->grp_pos = input->grp_pos;
  // is_motor_enable
  output->is_motor_enable = input->is_motor_enable;
  // is_grp_init_ongoing
  output->is_grp_init_ongoing = input->is_grp_init_ongoing;
  // is_pos_ongoing
  output->is_pos_ongoing = input->is_pos_ongoing;
  // is_vel_ongoing
  output->is_vel_ongoing = input->is_vel_ongoing;
  // is_tor_ongoing
  output->is_tor_ongoing = input->is_tor_ongoing;
  // is_grp_opening
  output->is_grp_opening = input->is_grp_opening;
  // is_grp_closing
  output->is_grp_closing = input->is_grp_closing;
  // grp_direction
  output->grp_direction = input->grp_direction;
  // is_object_grasp
  output->is_object_grasp = input->is_object_grasp;
  // is_fault_occured
  output->is_fault_occured = input->is_fault_occured;
  return true;
}

gripper_interfaces__msg__GripperMsg *
gripper_interfaces__msg__GripperMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__msg__GripperMsg * msg = (gripper_interfaces__msg__GripperMsg *)allocator.allocate(sizeof(gripper_interfaces__msg__GripperMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gripper_interfaces__msg__GripperMsg));
  bool success = gripper_interfaces__msg__GripperMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gripper_interfaces__msg__GripperMsg__destroy(gripper_interfaces__msg__GripperMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gripper_interfaces__msg__GripperMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gripper_interfaces__msg__GripperMsg__Sequence__init(gripper_interfaces__msg__GripperMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__msg__GripperMsg * data = NULL;

  if (size) {
    data = (gripper_interfaces__msg__GripperMsg *)allocator.zero_allocate(size, sizeof(gripper_interfaces__msg__GripperMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gripper_interfaces__msg__GripperMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gripper_interfaces__msg__GripperMsg__fini(&data[i - 1]);
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
gripper_interfaces__msg__GripperMsg__Sequence__fini(gripper_interfaces__msg__GripperMsg__Sequence * array)
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
      gripper_interfaces__msg__GripperMsg__fini(&array->data[i]);
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

gripper_interfaces__msg__GripperMsg__Sequence *
gripper_interfaces__msg__GripperMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gripper_interfaces__msg__GripperMsg__Sequence * array = (gripper_interfaces__msg__GripperMsg__Sequence *)allocator.allocate(sizeof(gripper_interfaces__msg__GripperMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gripper_interfaces__msg__GripperMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gripper_interfaces__msg__GripperMsg__Sequence__destroy(gripper_interfaces__msg__GripperMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gripper_interfaces__msg__GripperMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gripper_interfaces__msg__GripperMsg__Sequence__are_equal(const gripper_interfaces__msg__GripperMsg__Sequence * lhs, const gripper_interfaces__msg__GripperMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gripper_interfaces__msg__GripperMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gripper_interfaces__msg__GripperMsg__Sequence__copy(
  const gripper_interfaces__msg__GripperMsg__Sequence * input,
  gripper_interfaces__msg__GripperMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gripper_interfaces__msg__GripperMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gripper_interfaces__msg__GripperMsg * data =
      (gripper_interfaces__msg__GripperMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gripper_interfaces__msg__GripperMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gripper_interfaces__msg__GripperMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gripper_interfaces__msg__GripperMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
