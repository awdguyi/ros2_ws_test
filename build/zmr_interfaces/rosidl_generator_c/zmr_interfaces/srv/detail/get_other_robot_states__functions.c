// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zmr_interfaces:srv/GetOtherRobotStates.idl
// generated code does not contain a copyright notice
#include "zmr_interfaces/srv/detail/get_other_robot_states__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
zmr_interfaces__srv__GetOtherRobotStates_Request__init(zmr_interfaces__srv__GetOtherRobotStates_Request * msg)
{
  if (!msg) {
    return false;
  }
  // ego_robot_id
  return true;
}

void
zmr_interfaces__srv__GetOtherRobotStates_Request__fini(zmr_interfaces__srv__GetOtherRobotStates_Request * msg)
{
  if (!msg) {
    return;
  }
  // ego_robot_id
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Request__are_equal(const zmr_interfaces__srv__GetOtherRobotStates_Request * lhs, const zmr_interfaces__srv__GetOtherRobotStates_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ego_robot_id
  if (lhs->ego_robot_id != rhs->ego_robot_id) {
    return false;
  }
  return true;
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Request__copy(
  const zmr_interfaces__srv__GetOtherRobotStates_Request * input,
  zmr_interfaces__srv__GetOtherRobotStates_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // ego_robot_id
  output->ego_robot_id = input->ego_robot_id;
  return true;
}

zmr_interfaces__srv__GetOtherRobotStates_Request *
zmr_interfaces__srv__GetOtherRobotStates_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__srv__GetOtherRobotStates_Request * msg = (zmr_interfaces__srv__GetOtherRobotStates_Request *)allocator.allocate(sizeof(zmr_interfaces__srv__GetOtherRobotStates_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zmr_interfaces__srv__GetOtherRobotStates_Request));
  bool success = zmr_interfaces__srv__GetOtherRobotStates_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zmr_interfaces__srv__GetOtherRobotStates_Request__destroy(zmr_interfaces__srv__GetOtherRobotStates_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zmr_interfaces__srv__GetOtherRobotStates_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__init(zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__srv__GetOtherRobotStates_Request * data = NULL;

  if (size) {
    data = (zmr_interfaces__srv__GetOtherRobotStates_Request *)allocator.zero_allocate(size, sizeof(zmr_interfaces__srv__GetOtherRobotStates_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zmr_interfaces__srv__GetOtherRobotStates_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zmr_interfaces__srv__GetOtherRobotStates_Request__fini(&data[i - 1]);
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
zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__fini(zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * array)
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
      zmr_interfaces__srv__GetOtherRobotStates_Request__fini(&array->data[i]);
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

zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence *
zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * array = (zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence *)allocator.allocate(sizeof(zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__destroy(zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__are_equal(const zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * lhs, const zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zmr_interfaces__srv__GetOtherRobotStates_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence__copy(
  const zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * input,
  zmr_interfaces__srv__GetOtherRobotStates_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zmr_interfaces__srv__GetOtherRobotStates_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zmr_interfaces__srv__GetOtherRobotStates_Request * data =
      (zmr_interfaces__srv__GetOtherRobotStates_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zmr_interfaces__srv__GetOtherRobotStates_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zmr_interfaces__srv__GetOtherRobotStates_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zmr_interfaces__srv__GetOtherRobotStates_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `other_robot_states_in_order`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
zmr_interfaces__srv__GetOtherRobotStates_Response__init(zmr_interfaces__srv__GetOtherRobotStates_Response * msg)
{
  if (!msg) {
    return false;
  }
  // other_robot_states_in_order
  if (!rosidl_runtime_c__double__Sequence__init(&msg->other_robot_states_in_order, 0)) {
    zmr_interfaces__srv__GetOtherRobotStates_Response__fini(msg);
    return false;
  }
  return true;
}

void
zmr_interfaces__srv__GetOtherRobotStates_Response__fini(zmr_interfaces__srv__GetOtherRobotStates_Response * msg)
{
  if (!msg) {
    return;
  }
  // other_robot_states_in_order
  rosidl_runtime_c__double__Sequence__fini(&msg->other_robot_states_in_order);
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Response__are_equal(const zmr_interfaces__srv__GetOtherRobotStates_Response * lhs, const zmr_interfaces__srv__GetOtherRobotStates_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // other_robot_states_in_order
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->other_robot_states_in_order), &(rhs->other_robot_states_in_order)))
  {
    return false;
  }
  return true;
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Response__copy(
  const zmr_interfaces__srv__GetOtherRobotStates_Response * input,
  zmr_interfaces__srv__GetOtherRobotStates_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // other_robot_states_in_order
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->other_robot_states_in_order), &(output->other_robot_states_in_order)))
  {
    return false;
  }
  return true;
}

zmr_interfaces__srv__GetOtherRobotStates_Response *
zmr_interfaces__srv__GetOtherRobotStates_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__srv__GetOtherRobotStates_Response * msg = (zmr_interfaces__srv__GetOtherRobotStates_Response *)allocator.allocate(sizeof(zmr_interfaces__srv__GetOtherRobotStates_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zmr_interfaces__srv__GetOtherRobotStates_Response));
  bool success = zmr_interfaces__srv__GetOtherRobotStates_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zmr_interfaces__srv__GetOtherRobotStates_Response__destroy(zmr_interfaces__srv__GetOtherRobotStates_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zmr_interfaces__srv__GetOtherRobotStates_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__init(zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__srv__GetOtherRobotStates_Response * data = NULL;

  if (size) {
    data = (zmr_interfaces__srv__GetOtherRobotStates_Response *)allocator.zero_allocate(size, sizeof(zmr_interfaces__srv__GetOtherRobotStates_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zmr_interfaces__srv__GetOtherRobotStates_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zmr_interfaces__srv__GetOtherRobotStates_Response__fini(&data[i - 1]);
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
zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__fini(zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * array)
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
      zmr_interfaces__srv__GetOtherRobotStates_Response__fini(&array->data[i]);
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

zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence *
zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * array = (zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence *)allocator.allocate(sizeof(zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__destroy(zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__are_equal(const zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * lhs, const zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zmr_interfaces__srv__GetOtherRobotStates_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence__copy(
  const zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * input,
  zmr_interfaces__srv__GetOtherRobotStates_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zmr_interfaces__srv__GetOtherRobotStates_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zmr_interfaces__srv__GetOtherRobotStates_Response * data =
      (zmr_interfaces__srv__GetOtherRobotStates_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zmr_interfaces__srv__GetOtherRobotStates_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zmr_interfaces__srv__GetOtherRobotStates_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zmr_interfaces__srv__GetOtherRobotStates_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
