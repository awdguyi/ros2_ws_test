// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice
#include "mps_interfaces/msg/detail/schedule_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `schedules`
#include "mps_interfaces/msg/detail/schedule__functions.h"

bool
mps_interfaces__msg__ScheduleArray__init(mps_interfaces__msg__ScheduleArray * msg)
{
  if (!msg) {
    return false;
  }
  // schedules
  if (!mps_interfaces__msg__Schedule__Sequence__init(&msg->schedules, 0)) {
    mps_interfaces__msg__ScheduleArray__fini(msg);
    return false;
  }
  return true;
}

void
mps_interfaces__msg__ScheduleArray__fini(mps_interfaces__msg__ScheduleArray * msg)
{
  if (!msg) {
    return;
  }
  // schedules
  mps_interfaces__msg__Schedule__Sequence__fini(&msg->schedules);
}

bool
mps_interfaces__msg__ScheduleArray__are_equal(const mps_interfaces__msg__ScheduleArray * lhs, const mps_interfaces__msg__ScheduleArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // schedules
  if (!mps_interfaces__msg__Schedule__Sequence__are_equal(
      &(lhs->schedules), &(rhs->schedules)))
  {
    return false;
  }
  return true;
}

bool
mps_interfaces__msg__ScheduleArray__copy(
  const mps_interfaces__msg__ScheduleArray * input,
  mps_interfaces__msg__ScheduleArray * output)
{
  if (!input || !output) {
    return false;
  }
  // schedules
  if (!mps_interfaces__msg__Schedule__Sequence__copy(
      &(input->schedules), &(output->schedules)))
  {
    return false;
  }
  return true;
}

mps_interfaces__msg__ScheduleArray *
mps_interfaces__msg__ScheduleArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__ScheduleArray * msg = (mps_interfaces__msg__ScheduleArray *)allocator.allocate(sizeof(mps_interfaces__msg__ScheduleArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mps_interfaces__msg__ScheduleArray));
  bool success = mps_interfaces__msg__ScheduleArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mps_interfaces__msg__ScheduleArray__destroy(mps_interfaces__msg__ScheduleArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mps_interfaces__msg__ScheduleArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mps_interfaces__msg__ScheduleArray__Sequence__init(mps_interfaces__msg__ScheduleArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__ScheduleArray * data = NULL;

  if (size) {
    data = (mps_interfaces__msg__ScheduleArray *)allocator.zero_allocate(size, sizeof(mps_interfaces__msg__ScheduleArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mps_interfaces__msg__ScheduleArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mps_interfaces__msg__ScheduleArray__fini(&data[i - 1]);
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
mps_interfaces__msg__ScheduleArray__Sequence__fini(mps_interfaces__msg__ScheduleArray__Sequence * array)
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
      mps_interfaces__msg__ScheduleArray__fini(&array->data[i]);
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

mps_interfaces__msg__ScheduleArray__Sequence *
mps_interfaces__msg__ScheduleArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__ScheduleArray__Sequence * array = (mps_interfaces__msg__ScheduleArray__Sequence *)allocator.allocate(sizeof(mps_interfaces__msg__ScheduleArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mps_interfaces__msg__ScheduleArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mps_interfaces__msg__ScheduleArray__Sequence__destroy(mps_interfaces__msg__ScheduleArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mps_interfaces__msg__ScheduleArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mps_interfaces__msg__ScheduleArray__Sequence__are_equal(const mps_interfaces__msg__ScheduleArray__Sequence * lhs, const mps_interfaces__msg__ScheduleArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mps_interfaces__msg__ScheduleArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mps_interfaces__msg__ScheduleArray__Sequence__copy(
  const mps_interfaces__msg__ScheduleArray__Sequence * input,
  mps_interfaces__msg__ScheduleArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mps_interfaces__msg__ScheduleArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mps_interfaces__msg__ScheduleArray * data =
      (mps_interfaces__msg__ScheduleArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mps_interfaces__msg__ScheduleArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mps_interfaces__msg__ScheduleArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mps_interfaces__msg__ScheduleArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
