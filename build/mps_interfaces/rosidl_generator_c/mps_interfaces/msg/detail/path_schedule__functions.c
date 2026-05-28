// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice
#include "mps_interfaces/msg/detail/path_schedule__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `path_coords`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `path_times`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
mps_interfaces__msg__PathSchedule__init(mps_interfaces__msg__PathSchedule * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // path_coords
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->path_coords, 0)) {
    mps_interfaces__msg__PathSchedule__fini(msg);
    return false;
  }
  // path_times
  if (!rosidl_runtime_c__float__Sequence__init(&msg->path_times, 0)) {
    mps_interfaces__msg__PathSchedule__fini(msg);
    return false;
  }
  return true;
}

void
mps_interfaces__msg__PathSchedule__fini(mps_interfaces__msg__PathSchedule * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // path_coords
  geometry_msgs__msg__Point__Sequence__fini(&msg->path_coords);
  // path_times
  rosidl_runtime_c__float__Sequence__fini(&msg->path_times);
}

bool
mps_interfaces__msg__PathSchedule__are_equal(const mps_interfaces__msg__PathSchedule * lhs, const mps_interfaces__msg__PathSchedule * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // path_coords
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->path_coords), &(rhs->path_coords)))
  {
    return false;
  }
  // path_times
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->path_times), &(rhs->path_times)))
  {
    return false;
  }
  return true;
}

bool
mps_interfaces__msg__PathSchedule__copy(
  const mps_interfaces__msg__PathSchedule * input,
  mps_interfaces__msg__PathSchedule * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // path_coords
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->path_coords), &(output->path_coords)))
  {
    return false;
  }
  // path_times
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->path_times), &(output->path_times)))
  {
    return false;
  }
  return true;
}

mps_interfaces__msg__PathSchedule *
mps_interfaces__msg__PathSchedule__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__PathSchedule * msg = (mps_interfaces__msg__PathSchedule *)allocator.allocate(sizeof(mps_interfaces__msg__PathSchedule), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mps_interfaces__msg__PathSchedule));
  bool success = mps_interfaces__msg__PathSchedule__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mps_interfaces__msg__PathSchedule__destroy(mps_interfaces__msg__PathSchedule * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mps_interfaces__msg__PathSchedule__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mps_interfaces__msg__PathSchedule__Sequence__init(mps_interfaces__msg__PathSchedule__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__PathSchedule * data = NULL;

  if (size) {
    data = (mps_interfaces__msg__PathSchedule *)allocator.zero_allocate(size, sizeof(mps_interfaces__msg__PathSchedule), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mps_interfaces__msg__PathSchedule__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mps_interfaces__msg__PathSchedule__fini(&data[i - 1]);
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
mps_interfaces__msg__PathSchedule__Sequence__fini(mps_interfaces__msg__PathSchedule__Sequence * array)
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
      mps_interfaces__msg__PathSchedule__fini(&array->data[i]);
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

mps_interfaces__msg__PathSchedule__Sequence *
mps_interfaces__msg__PathSchedule__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__PathSchedule__Sequence * array = (mps_interfaces__msg__PathSchedule__Sequence *)allocator.allocate(sizeof(mps_interfaces__msg__PathSchedule__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mps_interfaces__msg__PathSchedule__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mps_interfaces__msg__PathSchedule__Sequence__destroy(mps_interfaces__msg__PathSchedule__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mps_interfaces__msg__PathSchedule__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mps_interfaces__msg__PathSchedule__Sequence__are_equal(const mps_interfaces__msg__PathSchedule__Sequence * lhs, const mps_interfaces__msg__PathSchedule__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mps_interfaces__msg__PathSchedule__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mps_interfaces__msg__PathSchedule__Sequence__copy(
  const mps_interfaces__msg__PathSchedule__Sequence * input,
  mps_interfaces__msg__PathSchedule__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mps_interfaces__msg__PathSchedule);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mps_interfaces__msg__PathSchedule * data =
      (mps_interfaces__msg__PathSchedule *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mps_interfaces__msg__PathSchedule__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mps_interfaces__msg__PathSchedule__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mps_interfaces__msg__PathSchedule__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
