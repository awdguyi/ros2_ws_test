// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice
#include "mps_interfaces/msg/detail/schedule__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `schedule_name`
// Member `node_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `node_ids`
// Member `etas`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
mps_interfaces__msg__Schedule__init(mps_interfaces__msg__Schedule * msg)
{
  if (!msg) {
    return false;
  }
  // schedule_name
  if (!rosidl_runtime_c__String__init(&msg->schedule_name)) {
    mps_interfaces__msg__Schedule__fini(msg);
    return false;
  }
  // robot_id
  // node_ids
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->node_ids, 0)) {
    mps_interfaces__msg__Schedule__fini(msg);
    return false;
  }
  // node_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->node_names, 0)) {
    mps_interfaces__msg__Schedule__fini(msg);
    return false;
  }
  // etas
  if (!rosidl_runtime_c__float__Sequence__init(&msg->etas, 0)) {
    mps_interfaces__msg__Schedule__fini(msg);
    return false;
  }
  return true;
}

void
mps_interfaces__msg__Schedule__fini(mps_interfaces__msg__Schedule * msg)
{
  if (!msg) {
    return;
  }
  // schedule_name
  rosidl_runtime_c__String__fini(&msg->schedule_name);
  // robot_id
  // node_ids
  rosidl_runtime_c__int16__Sequence__fini(&msg->node_ids);
  // node_names
  rosidl_runtime_c__String__Sequence__fini(&msg->node_names);
  // etas
  rosidl_runtime_c__float__Sequence__fini(&msg->etas);
}

bool
mps_interfaces__msg__Schedule__are_equal(const mps_interfaces__msg__Schedule * lhs, const mps_interfaces__msg__Schedule * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // schedule_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->schedule_name), &(rhs->schedule_name)))
  {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // node_ids
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->node_ids), &(rhs->node_ids)))
  {
    return false;
  }
  // node_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->node_names), &(rhs->node_names)))
  {
    return false;
  }
  // etas
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->etas), &(rhs->etas)))
  {
    return false;
  }
  return true;
}

bool
mps_interfaces__msg__Schedule__copy(
  const mps_interfaces__msg__Schedule * input,
  mps_interfaces__msg__Schedule * output)
{
  if (!input || !output) {
    return false;
  }
  // schedule_name
  if (!rosidl_runtime_c__String__copy(
      &(input->schedule_name), &(output->schedule_name)))
  {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // node_ids
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->node_ids), &(output->node_ids)))
  {
    return false;
  }
  // node_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->node_names), &(output->node_names)))
  {
    return false;
  }
  // etas
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->etas), &(output->etas)))
  {
    return false;
  }
  return true;
}

mps_interfaces__msg__Schedule *
mps_interfaces__msg__Schedule__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__Schedule * msg = (mps_interfaces__msg__Schedule *)allocator.allocate(sizeof(mps_interfaces__msg__Schedule), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mps_interfaces__msg__Schedule));
  bool success = mps_interfaces__msg__Schedule__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mps_interfaces__msg__Schedule__destroy(mps_interfaces__msg__Schedule * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mps_interfaces__msg__Schedule__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mps_interfaces__msg__Schedule__Sequence__init(mps_interfaces__msg__Schedule__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__Schedule * data = NULL;

  if (size) {
    data = (mps_interfaces__msg__Schedule *)allocator.zero_allocate(size, sizeof(mps_interfaces__msg__Schedule), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mps_interfaces__msg__Schedule__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mps_interfaces__msg__Schedule__fini(&data[i - 1]);
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
mps_interfaces__msg__Schedule__Sequence__fini(mps_interfaces__msg__Schedule__Sequence * array)
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
      mps_interfaces__msg__Schedule__fini(&array->data[i]);
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

mps_interfaces__msg__Schedule__Sequence *
mps_interfaces__msg__Schedule__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__Schedule__Sequence * array = (mps_interfaces__msg__Schedule__Sequence *)allocator.allocate(sizeof(mps_interfaces__msg__Schedule__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mps_interfaces__msg__Schedule__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mps_interfaces__msg__Schedule__Sequence__destroy(mps_interfaces__msg__Schedule__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mps_interfaces__msg__Schedule__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mps_interfaces__msg__Schedule__Sequence__are_equal(const mps_interfaces__msg__Schedule__Sequence * lhs, const mps_interfaces__msg__Schedule__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mps_interfaces__msg__Schedule__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mps_interfaces__msg__Schedule__Sequence__copy(
  const mps_interfaces__msg__Schedule__Sequence * input,
  mps_interfaces__msg__Schedule__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mps_interfaces__msg__Schedule);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mps_interfaces__msg__Schedule * data =
      (mps_interfaces__msg__Schedule *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mps_interfaces__msg__Schedule__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mps_interfaces__msg__Schedule__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mps_interfaces__msg__Schedule__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
