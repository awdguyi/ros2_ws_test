// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mmp_interfaces:msg/HumanTrajectoryArray.idl
// generated code does not contain a copyright notice
#include "mmp_interfaces/msg/detail/human_trajectory_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `human_trajectories`
#include "mmp_interfaces/msg/detail/human_trajectory__functions.h"

bool
mmp_interfaces__msg__HumanTrajectoryArray__init(mmp_interfaces__msg__HumanTrajectoryArray * msg)
{
  if (!msg) {
    return false;
  }
  // human_trajectories
  if (!mmp_interfaces__msg__HumanTrajectory__Sequence__init(&msg->human_trajectories, 0)) {
    mmp_interfaces__msg__HumanTrajectoryArray__fini(msg);
    return false;
  }
  return true;
}

void
mmp_interfaces__msg__HumanTrajectoryArray__fini(mmp_interfaces__msg__HumanTrajectoryArray * msg)
{
  if (!msg) {
    return;
  }
  // human_trajectories
  mmp_interfaces__msg__HumanTrajectory__Sequence__fini(&msg->human_trajectories);
}

bool
mmp_interfaces__msg__HumanTrajectoryArray__are_equal(const mmp_interfaces__msg__HumanTrajectoryArray * lhs, const mmp_interfaces__msg__HumanTrajectoryArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // human_trajectories
  if (!mmp_interfaces__msg__HumanTrajectory__Sequence__are_equal(
      &(lhs->human_trajectories), &(rhs->human_trajectories)))
  {
    return false;
  }
  return true;
}

bool
mmp_interfaces__msg__HumanTrajectoryArray__copy(
  const mmp_interfaces__msg__HumanTrajectoryArray * input,
  mmp_interfaces__msg__HumanTrajectoryArray * output)
{
  if (!input || !output) {
    return false;
  }
  // human_trajectories
  if (!mmp_interfaces__msg__HumanTrajectory__Sequence__copy(
      &(input->human_trajectories), &(output->human_trajectories)))
  {
    return false;
  }
  return true;
}

mmp_interfaces__msg__HumanTrajectoryArray *
mmp_interfaces__msg__HumanTrajectoryArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmp_interfaces__msg__HumanTrajectoryArray * msg = (mmp_interfaces__msg__HumanTrajectoryArray *)allocator.allocate(sizeof(mmp_interfaces__msg__HumanTrajectoryArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmp_interfaces__msg__HumanTrajectoryArray));
  bool success = mmp_interfaces__msg__HumanTrajectoryArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmp_interfaces__msg__HumanTrajectoryArray__destroy(mmp_interfaces__msg__HumanTrajectoryArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmp_interfaces__msg__HumanTrajectoryArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(mmp_interfaces__msg__HumanTrajectoryArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmp_interfaces__msg__HumanTrajectoryArray * data = NULL;

  if (size) {
    data = (mmp_interfaces__msg__HumanTrajectoryArray *)allocator.zero_allocate(size, sizeof(mmp_interfaces__msg__HumanTrajectoryArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmp_interfaces__msg__HumanTrajectoryArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmp_interfaces__msg__HumanTrajectoryArray__fini(&data[i - 1]);
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
mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(mmp_interfaces__msg__HumanTrajectoryArray__Sequence * array)
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
      mmp_interfaces__msg__HumanTrajectoryArray__fini(&array->data[i]);
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

mmp_interfaces__msg__HumanTrajectoryArray__Sequence *
mmp_interfaces__msg__HumanTrajectoryArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * array = (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)allocator.allocate(sizeof(mmp_interfaces__msg__HumanTrajectoryArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmp_interfaces__msg__HumanTrajectoryArray__Sequence__destroy(mmp_interfaces__msg__HumanTrajectoryArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmp_interfaces__msg__HumanTrajectoryArray__Sequence__are_equal(const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * lhs, const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmp_interfaces__msg__HumanTrajectoryArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmp_interfaces__msg__HumanTrajectoryArray__Sequence__copy(
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * input,
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmp_interfaces__msg__HumanTrajectoryArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmp_interfaces__msg__HumanTrajectoryArray * data =
      (mmp_interfaces__msg__HumanTrajectoryArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmp_interfaces__msg__HumanTrajectoryArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmp_interfaces__msg__HumanTrajectoryArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmp_interfaces__msg__HumanTrajectoryArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
