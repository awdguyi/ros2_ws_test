// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice
#include "zmr_interfaces/msg/detail/current_future_states__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_states`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
zmr_interfaces__msg__CurrentFutureStates__init(zmr_interfaces__msg__CurrentFutureStates * msg)
{
  if (!msg) {
    return false;
  }
  // robot_states
  if (!rosidl_runtime_c__double__Sequence__init(&msg->robot_states, 0)) {
    zmr_interfaces__msg__CurrentFutureStates__fini(msg);
    return false;
  }
  return true;
}

void
zmr_interfaces__msg__CurrentFutureStates__fini(zmr_interfaces__msg__CurrentFutureStates * msg)
{
  if (!msg) {
    return;
  }
  // robot_states
  rosidl_runtime_c__double__Sequence__fini(&msg->robot_states);
}

bool
zmr_interfaces__msg__CurrentFutureStates__are_equal(const zmr_interfaces__msg__CurrentFutureStates * lhs, const zmr_interfaces__msg__CurrentFutureStates * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_states
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->robot_states), &(rhs->robot_states)))
  {
    return false;
  }
  return true;
}

bool
zmr_interfaces__msg__CurrentFutureStates__copy(
  const zmr_interfaces__msg__CurrentFutureStates * input,
  zmr_interfaces__msg__CurrentFutureStates * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_states
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->robot_states), &(output->robot_states)))
  {
    return false;
  }
  return true;
}

zmr_interfaces__msg__CurrentFutureStates *
zmr_interfaces__msg__CurrentFutureStates__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__msg__CurrentFutureStates * msg = (zmr_interfaces__msg__CurrentFutureStates *)allocator.allocate(sizeof(zmr_interfaces__msg__CurrentFutureStates), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(zmr_interfaces__msg__CurrentFutureStates));
  bool success = zmr_interfaces__msg__CurrentFutureStates__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
zmr_interfaces__msg__CurrentFutureStates__destroy(zmr_interfaces__msg__CurrentFutureStates * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    zmr_interfaces__msg__CurrentFutureStates__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
zmr_interfaces__msg__CurrentFutureStates__Sequence__init(zmr_interfaces__msg__CurrentFutureStates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__msg__CurrentFutureStates * data = NULL;

  if (size) {
    data = (zmr_interfaces__msg__CurrentFutureStates *)allocator.zero_allocate(size, sizeof(zmr_interfaces__msg__CurrentFutureStates), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = zmr_interfaces__msg__CurrentFutureStates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        zmr_interfaces__msg__CurrentFutureStates__fini(&data[i - 1]);
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
zmr_interfaces__msg__CurrentFutureStates__Sequence__fini(zmr_interfaces__msg__CurrentFutureStates__Sequence * array)
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
      zmr_interfaces__msg__CurrentFutureStates__fini(&array->data[i]);
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

zmr_interfaces__msg__CurrentFutureStates__Sequence *
zmr_interfaces__msg__CurrentFutureStates__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  zmr_interfaces__msg__CurrentFutureStates__Sequence * array = (zmr_interfaces__msg__CurrentFutureStates__Sequence *)allocator.allocate(sizeof(zmr_interfaces__msg__CurrentFutureStates__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = zmr_interfaces__msg__CurrentFutureStates__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
zmr_interfaces__msg__CurrentFutureStates__Sequence__destroy(zmr_interfaces__msg__CurrentFutureStates__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    zmr_interfaces__msg__CurrentFutureStates__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
zmr_interfaces__msg__CurrentFutureStates__Sequence__are_equal(const zmr_interfaces__msg__CurrentFutureStates__Sequence * lhs, const zmr_interfaces__msg__CurrentFutureStates__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!zmr_interfaces__msg__CurrentFutureStates__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
zmr_interfaces__msg__CurrentFutureStates__Sequence__copy(
  const zmr_interfaces__msg__CurrentFutureStates__Sequence * input,
  zmr_interfaces__msg__CurrentFutureStates__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(zmr_interfaces__msg__CurrentFutureStates);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    zmr_interfaces__msg__CurrentFutureStates * data =
      (zmr_interfaces__msg__CurrentFutureStates *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!zmr_interfaces__msg__CurrentFutureStates__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          zmr_interfaces__msg__CurrentFutureStates__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!zmr_interfaces__msg__CurrentFutureStates__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
