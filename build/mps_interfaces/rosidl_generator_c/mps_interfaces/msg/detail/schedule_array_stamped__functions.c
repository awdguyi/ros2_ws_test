// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mps_interfaces:msg/ScheduleArrayStamped.idl
// generated code does not contain a copyright notice
#include "mps_interfaces/msg/detail/schedule_array_stamped__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `schedules`
#include "mps_interfaces/msg/detail/schedule_array__functions.h"

bool
mps_interfaces__msg__ScheduleArrayStamped__init(mps_interfaces__msg__ScheduleArrayStamped * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    mps_interfaces__msg__ScheduleArrayStamped__fini(msg);
    return false;
  }
  // schedules
  if (!mps_interfaces__msg__ScheduleArray__init(&msg->schedules)) {
    mps_interfaces__msg__ScheduleArrayStamped__fini(msg);
    return false;
  }
  return true;
}

void
mps_interfaces__msg__ScheduleArrayStamped__fini(mps_interfaces__msg__ScheduleArrayStamped * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // schedules
  mps_interfaces__msg__ScheduleArray__fini(&msg->schedules);
}

bool
mps_interfaces__msg__ScheduleArrayStamped__are_equal(const mps_interfaces__msg__ScheduleArrayStamped * lhs, const mps_interfaces__msg__ScheduleArrayStamped * rhs)
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
  // schedules
  if (!mps_interfaces__msg__ScheduleArray__are_equal(
      &(lhs->schedules), &(rhs->schedules)))
  {
    return false;
  }
  return true;
}

bool
mps_interfaces__msg__ScheduleArrayStamped__copy(
  const mps_interfaces__msg__ScheduleArrayStamped * input,
  mps_interfaces__msg__ScheduleArrayStamped * output)
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
  // schedules
  if (!mps_interfaces__msg__ScheduleArray__copy(
      &(input->schedules), &(output->schedules)))
  {
    return false;
  }
  return true;
}

mps_interfaces__msg__ScheduleArrayStamped *
mps_interfaces__msg__ScheduleArrayStamped__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__ScheduleArrayStamped * msg = (mps_interfaces__msg__ScheduleArrayStamped *)allocator.allocate(sizeof(mps_interfaces__msg__ScheduleArrayStamped), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mps_interfaces__msg__ScheduleArrayStamped));
  bool success = mps_interfaces__msg__ScheduleArrayStamped__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mps_interfaces__msg__ScheduleArrayStamped__destroy(mps_interfaces__msg__ScheduleArrayStamped * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mps_interfaces__msg__ScheduleArrayStamped__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mps_interfaces__msg__ScheduleArrayStamped__Sequence__init(mps_interfaces__msg__ScheduleArrayStamped__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__ScheduleArrayStamped * data = NULL;

  if (size) {
    data = (mps_interfaces__msg__ScheduleArrayStamped *)allocator.zero_allocate(size, sizeof(mps_interfaces__msg__ScheduleArrayStamped), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mps_interfaces__msg__ScheduleArrayStamped__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mps_interfaces__msg__ScheduleArrayStamped__fini(&data[i - 1]);
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
mps_interfaces__msg__ScheduleArrayStamped__Sequence__fini(mps_interfaces__msg__ScheduleArrayStamped__Sequence * array)
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
      mps_interfaces__msg__ScheduleArrayStamped__fini(&array->data[i]);
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

mps_interfaces__msg__ScheduleArrayStamped__Sequence *
mps_interfaces__msg__ScheduleArrayStamped__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__msg__ScheduleArrayStamped__Sequence * array = (mps_interfaces__msg__ScheduleArrayStamped__Sequence *)allocator.allocate(sizeof(mps_interfaces__msg__ScheduleArrayStamped__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mps_interfaces__msg__ScheduleArrayStamped__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mps_interfaces__msg__ScheduleArrayStamped__Sequence__destroy(mps_interfaces__msg__ScheduleArrayStamped__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mps_interfaces__msg__ScheduleArrayStamped__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mps_interfaces__msg__ScheduleArrayStamped__Sequence__are_equal(const mps_interfaces__msg__ScheduleArrayStamped__Sequence * lhs, const mps_interfaces__msg__ScheduleArrayStamped__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mps_interfaces__msg__ScheduleArrayStamped__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mps_interfaces__msg__ScheduleArrayStamped__Sequence__copy(
  const mps_interfaces__msg__ScheduleArrayStamped__Sequence * input,
  mps_interfaces__msg__ScheduleArrayStamped__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mps_interfaces__msg__ScheduleArrayStamped);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mps_interfaces__msg__ScheduleArrayStamped * data =
      (mps_interfaces__msg__ScheduleArrayStamped *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mps_interfaces__msg__ScheduleArrayStamped__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mps_interfaces__msg__ScheduleArrayStamped__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mps_interfaces__msg__ScheduleArrayStamped__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
