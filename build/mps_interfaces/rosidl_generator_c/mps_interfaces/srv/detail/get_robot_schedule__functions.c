// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mps_interfaces:srv/GetRobotSchedule.idl
// generated code does not contain a copyright notice
#include "mps_interfaces/srv/detail/get_robot_schedule__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
mps_interfaces__srv__GetRobotSchedule_Request__init(mps_interfaces__srv__GetRobotSchedule_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_id
  // current_time
  return true;
}

void
mps_interfaces__srv__GetRobotSchedule_Request__fini(mps_interfaces__srv__GetRobotSchedule_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_id
  // current_time
}

bool
mps_interfaces__srv__GetRobotSchedule_Request__are_equal(const mps_interfaces__srv__GetRobotSchedule_Request * lhs, const mps_interfaces__srv__GetRobotSchedule_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_id
  if (lhs->robot_id != rhs->robot_id) {
    return false;
  }
  // current_time
  if (lhs->current_time != rhs->current_time) {
    return false;
  }
  return true;
}

bool
mps_interfaces__srv__GetRobotSchedule_Request__copy(
  const mps_interfaces__srv__GetRobotSchedule_Request * input,
  mps_interfaces__srv__GetRobotSchedule_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_id
  output->robot_id = input->robot_id;
  // current_time
  output->current_time = input->current_time;
  return true;
}

mps_interfaces__srv__GetRobotSchedule_Request *
mps_interfaces__srv__GetRobotSchedule_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__srv__GetRobotSchedule_Request * msg = (mps_interfaces__srv__GetRobotSchedule_Request *)allocator.allocate(sizeof(mps_interfaces__srv__GetRobotSchedule_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mps_interfaces__srv__GetRobotSchedule_Request));
  bool success = mps_interfaces__srv__GetRobotSchedule_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mps_interfaces__srv__GetRobotSchedule_Request__destroy(mps_interfaces__srv__GetRobotSchedule_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mps_interfaces__srv__GetRobotSchedule_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mps_interfaces__srv__GetRobotSchedule_Request__Sequence__init(mps_interfaces__srv__GetRobotSchedule_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__srv__GetRobotSchedule_Request * data = NULL;

  if (size) {
    data = (mps_interfaces__srv__GetRobotSchedule_Request *)allocator.zero_allocate(size, sizeof(mps_interfaces__srv__GetRobotSchedule_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mps_interfaces__srv__GetRobotSchedule_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mps_interfaces__srv__GetRobotSchedule_Request__fini(&data[i - 1]);
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
mps_interfaces__srv__GetRobotSchedule_Request__Sequence__fini(mps_interfaces__srv__GetRobotSchedule_Request__Sequence * array)
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
      mps_interfaces__srv__GetRobotSchedule_Request__fini(&array->data[i]);
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

mps_interfaces__srv__GetRobotSchedule_Request__Sequence *
mps_interfaces__srv__GetRobotSchedule_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__srv__GetRobotSchedule_Request__Sequence * array = (mps_interfaces__srv__GetRobotSchedule_Request__Sequence *)allocator.allocate(sizeof(mps_interfaces__srv__GetRobotSchedule_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mps_interfaces__srv__GetRobotSchedule_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mps_interfaces__srv__GetRobotSchedule_Request__Sequence__destroy(mps_interfaces__srv__GetRobotSchedule_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mps_interfaces__srv__GetRobotSchedule_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mps_interfaces__srv__GetRobotSchedule_Request__Sequence__are_equal(const mps_interfaces__srv__GetRobotSchedule_Request__Sequence * lhs, const mps_interfaces__srv__GetRobotSchedule_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mps_interfaces__srv__GetRobotSchedule_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mps_interfaces__srv__GetRobotSchedule_Request__Sequence__copy(
  const mps_interfaces__srv__GetRobotSchedule_Request__Sequence * input,
  mps_interfaces__srv__GetRobotSchedule_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mps_interfaces__srv__GetRobotSchedule_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mps_interfaces__srv__GetRobotSchedule_Request * data =
      (mps_interfaces__srv__GetRobotSchedule_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mps_interfaces__srv__GetRobotSchedule_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mps_interfaces__srv__GetRobotSchedule_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mps_interfaces__srv__GetRobotSchedule_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `path_schedule`
#include "mps_interfaces/msg/detail/path_schedule_stamped__functions.h"

bool
mps_interfaces__srv__GetRobotSchedule_Response__init(mps_interfaces__srv__GetRobotSchedule_Response * msg)
{
  if (!msg) {
    return false;
  }
  // path_schedule
  if (!mps_interfaces__msg__PathScheduleStamped__init(&msg->path_schedule)) {
    mps_interfaces__srv__GetRobotSchedule_Response__fini(msg);
    return false;
  }
  return true;
}

void
mps_interfaces__srv__GetRobotSchedule_Response__fini(mps_interfaces__srv__GetRobotSchedule_Response * msg)
{
  if (!msg) {
    return;
  }
  // path_schedule
  mps_interfaces__msg__PathScheduleStamped__fini(&msg->path_schedule);
}

bool
mps_interfaces__srv__GetRobotSchedule_Response__are_equal(const mps_interfaces__srv__GetRobotSchedule_Response * lhs, const mps_interfaces__srv__GetRobotSchedule_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // path_schedule
  if (!mps_interfaces__msg__PathScheduleStamped__are_equal(
      &(lhs->path_schedule), &(rhs->path_schedule)))
  {
    return false;
  }
  return true;
}

bool
mps_interfaces__srv__GetRobotSchedule_Response__copy(
  const mps_interfaces__srv__GetRobotSchedule_Response * input,
  mps_interfaces__srv__GetRobotSchedule_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // path_schedule
  if (!mps_interfaces__msg__PathScheduleStamped__copy(
      &(input->path_schedule), &(output->path_schedule)))
  {
    return false;
  }
  return true;
}

mps_interfaces__srv__GetRobotSchedule_Response *
mps_interfaces__srv__GetRobotSchedule_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__srv__GetRobotSchedule_Response * msg = (mps_interfaces__srv__GetRobotSchedule_Response *)allocator.allocate(sizeof(mps_interfaces__srv__GetRobotSchedule_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mps_interfaces__srv__GetRobotSchedule_Response));
  bool success = mps_interfaces__srv__GetRobotSchedule_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mps_interfaces__srv__GetRobotSchedule_Response__destroy(mps_interfaces__srv__GetRobotSchedule_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mps_interfaces__srv__GetRobotSchedule_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mps_interfaces__srv__GetRobotSchedule_Response__Sequence__init(mps_interfaces__srv__GetRobotSchedule_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__srv__GetRobotSchedule_Response * data = NULL;

  if (size) {
    data = (mps_interfaces__srv__GetRobotSchedule_Response *)allocator.zero_allocate(size, sizeof(mps_interfaces__srv__GetRobotSchedule_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mps_interfaces__srv__GetRobotSchedule_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mps_interfaces__srv__GetRobotSchedule_Response__fini(&data[i - 1]);
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
mps_interfaces__srv__GetRobotSchedule_Response__Sequence__fini(mps_interfaces__srv__GetRobotSchedule_Response__Sequence * array)
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
      mps_interfaces__srv__GetRobotSchedule_Response__fini(&array->data[i]);
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

mps_interfaces__srv__GetRobotSchedule_Response__Sequence *
mps_interfaces__srv__GetRobotSchedule_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mps_interfaces__srv__GetRobotSchedule_Response__Sequence * array = (mps_interfaces__srv__GetRobotSchedule_Response__Sequence *)allocator.allocate(sizeof(mps_interfaces__srv__GetRobotSchedule_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mps_interfaces__srv__GetRobotSchedule_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mps_interfaces__srv__GetRobotSchedule_Response__Sequence__destroy(mps_interfaces__srv__GetRobotSchedule_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mps_interfaces__srv__GetRobotSchedule_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mps_interfaces__srv__GetRobotSchedule_Response__Sequence__are_equal(const mps_interfaces__srv__GetRobotSchedule_Response__Sequence * lhs, const mps_interfaces__srv__GetRobotSchedule_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mps_interfaces__srv__GetRobotSchedule_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mps_interfaces__srv__GetRobotSchedule_Response__Sequence__copy(
  const mps_interfaces__srv__GetRobotSchedule_Response__Sequence * input,
  mps_interfaces__srv__GetRobotSchedule_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mps_interfaces__srv__GetRobotSchedule_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mps_interfaces__srv__GetRobotSchedule_Response * data =
      (mps_interfaces__srv__GetRobotSchedule_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mps_interfaces__srv__GetRobotSchedule_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mps_interfaces__srv__GetRobotSchedule_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mps_interfaces__srv__GetRobotSchedule_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
