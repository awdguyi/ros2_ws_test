// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice
#include "mmp_interfaces/msg/detail/motion_prediction_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `mu_list_list`
// Member `std_list_list`
// Member `conf_list_list`
#include "mmp_interfaces/msg/detail/human_trajectory_array__functions.h"

bool
mmp_interfaces__msg__MotionPredictionResult__init(mmp_interfaces__msg__MotionPredictionResult * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    mmp_interfaces__msg__MotionPredictionResult__fini(msg);
    return false;
  }
  // mu_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(&msg->mu_list_list, 0)) {
    mmp_interfaces__msg__MotionPredictionResult__fini(msg);
    return false;
  }
  // std_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(&msg->std_list_list, 0)) {
    mmp_interfaces__msg__MotionPredictionResult__fini(msg);
    return false;
  }
  // conf_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(&msg->conf_list_list, 0)) {
    mmp_interfaces__msg__MotionPredictionResult__fini(msg);
    return false;
  }
  return true;
}

void
mmp_interfaces__msg__MotionPredictionResult__fini(mmp_interfaces__msg__MotionPredictionResult * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // mu_list_list
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(&msg->mu_list_list);
  // std_list_list
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(&msg->std_list_list);
  // conf_list_list
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(&msg->conf_list_list);
}

bool
mmp_interfaces__msg__MotionPredictionResult__are_equal(const mmp_interfaces__msg__MotionPredictionResult * lhs, const mmp_interfaces__msg__MotionPredictionResult * rhs)
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
  // mu_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__are_equal(
      &(lhs->mu_list_list), &(rhs->mu_list_list)))
  {
    return false;
  }
  // std_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__are_equal(
      &(lhs->std_list_list), &(rhs->std_list_list)))
  {
    return false;
  }
  // conf_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__are_equal(
      &(lhs->conf_list_list), &(rhs->conf_list_list)))
  {
    return false;
  }
  return true;
}

bool
mmp_interfaces__msg__MotionPredictionResult__copy(
  const mmp_interfaces__msg__MotionPredictionResult * input,
  mmp_interfaces__msg__MotionPredictionResult * output)
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
  // mu_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__copy(
      &(input->mu_list_list), &(output->mu_list_list)))
  {
    return false;
  }
  // std_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__copy(
      &(input->std_list_list), &(output->std_list_list)))
  {
    return false;
  }
  // conf_list_list
  if (!mmp_interfaces__msg__HumanTrajectoryArray__Sequence__copy(
      &(input->conf_list_list), &(output->conf_list_list)))
  {
    return false;
  }
  return true;
}

mmp_interfaces__msg__MotionPredictionResult *
mmp_interfaces__msg__MotionPredictionResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmp_interfaces__msg__MotionPredictionResult * msg = (mmp_interfaces__msg__MotionPredictionResult *)allocator.allocate(sizeof(mmp_interfaces__msg__MotionPredictionResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mmp_interfaces__msg__MotionPredictionResult));
  bool success = mmp_interfaces__msg__MotionPredictionResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mmp_interfaces__msg__MotionPredictionResult__destroy(mmp_interfaces__msg__MotionPredictionResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mmp_interfaces__msg__MotionPredictionResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mmp_interfaces__msg__MotionPredictionResult__Sequence__init(mmp_interfaces__msg__MotionPredictionResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmp_interfaces__msg__MotionPredictionResult * data = NULL;

  if (size) {
    data = (mmp_interfaces__msg__MotionPredictionResult *)allocator.zero_allocate(size, sizeof(mmp_interfaces__msg__MotionPredictionResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mmp_interfaces__msg__MotionPredictionResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mmp_interfaces__msg__MotionPredictionResult__fini(&data[i - 1]);
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
mmp_interfaces__msg__MotionPredictionResult__Sequence__fini(mmp_interfaces__msg__MotionPredictionResult__Sequence * array)
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
      mmp_interfaces__msg__MotionPredictionResult__fini(&array->data[i]);
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

mmp_interfaces__msg__MotionPredictionResult__Sequence *
mmp_interfaces__msg__MotionPredictionResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mmp_interfaces__msg__MotionPredictionResult__Sequence * array = (mmp_interfaces__msg__MotionPredictionResult__Sequence *)allocator.allocate(sizeof(mmp_interfaces__msg__MotionPredictionResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mmp_interfaces__msg__MotionPredictionResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mmp_interfaces__msg__MotionPredictionResult__Sequence__destroy(mmp_interfaces__msg__MotionPredictionResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mmp_interfaces__msg__MotionPredictionResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mmp_interfaces__msg__MotionPredictionResult__Sequence__are_equal(const mmp_interfaces__msg__MotionPredictionResult__Sequence * lhs, const mmp_interfaces__msg__MotionPredictionResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mmp_interfaces__msg__MotionPredictionResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mmp_interfaces__msg__MotionPredictionResult__Sequence__copy(
  const mmp_interfaces__msg__MotionPredictionResult__Sequence * input,
  mmp_interfaces__msg__MotionPredictionResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mmp_interfaces__msg__MotionPredictionResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mmp_interfaces__msg__MotionPredictionResult * data =
      (mmp_interfaces__msg__MotionPredictionResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mmp_interfaces__msg__MotionPredictionResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mmp_interfaces__msg__MotionPredictionResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mmp_interfaces__msg__MotionPredictionResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
