// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_interfaces:msg/ObjectMotionType.idl
// generated code does not contain a copyright notice
#include "map_interfaces/msg/detail/object_motion_type__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
map_interfaces__msg__ObjectMotionType__init(map_interfaces__msg__ObjectMotionType * msg)
{
  if (!msg) {
    return false;
  }
  // o_motion_type
  return true;
}

void
map_interfaces__msg__ObjectMotionType__fini(map_interfaces__msg__ObjectMotionType * msg)
{
  if (!msg) {
    return;
  }
  // o_motion_type
}

bool
map_interfaces__msg__ObjectMotionType__are_equal(const map_interfaces__msg__ObjectMotionType * lhs, const map_interfaces__msg__ObjectMotionType * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // o_motion_type
  if (lhs->o_motion_type != rhs->o_motion_type) {
    return false;
  }
  return true;
}

bool
map_interfaces__msg__ObjectMotionType__copy(
  const map_interfaces__msg__ObjectMotionType * input,
  map_interfaces__msg__ObjectMotionType * output)
{
  if (!input || !output) {
    return false;
  }
  // o_motion_type
  output->o_motion_type = input->o_motion_type;
  return true;
}

map_interfaces__msg__ObjectMotionType *
map_interfaces__msg__ObjectMotionType__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__ObjectMotionType * msg = (map_interfaces__msg__ObjectMotionType *)allocator.allocate(sizeof(map_interfaces__msg__ObjectMotionType), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_interfaces__msg__ObjectMotionType));
  bool success = map_interfaces__msg__ObjectMotionType__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_interfaces__msg__ObjectMotionType__destroy(map_interfaces__msg__ObjectMotionType * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_interfaces__msg__ObjectMotionType__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_interfaces__msg__ObjectMotionType__Sequence__init(map_interfaces__msg__ObjectMotionType__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__ObjectMotionType * data = NULL;

  if (size) {
    data = (map_interfaces__msg__ObjectMotionType *)allocator.zero_allocate(size, sizeof(map_interfaces__msg__ObjectMotionType), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_interfaces__msg__ObjectMotionType__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_interfaces__msg__ObjectMotionType__fini(&data[i - 1]);
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
map_interfaces__msg__ObjectMotionType__Sequence__fini(map_interfaces__msg__ObjectMotionType__Sequence * array)
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
      map_interfaces__msg__ObjectMotionType__fini(&array->data[i]);
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

map_interfaces__msg__ObjectMotionType__Sequence *
map_interfaces__msg__ObjectMotionType__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__ObjectMotionType__Sequence * array = (map_interfaces__msg__ObjectMotionType__Sequence *)allocator.allocate(sizeof(map_interfaces__msg__ObjectMotionType__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_interfaces__msg__ObjectMotionType__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_interfaces__msg__ObjectMotionType__Sequence__destroy(map_interfaces__msg__ObjectMotionType__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_interfaces__msg__ObjectMotionType__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_interfaces__msg__ObjectMotionType__Sequence__are_equal(const map_interfaces__msg__ObjectMotionType__Sequence * lhs, const map_interfaces__msg__ObjectMotionType__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_interfaces__msg__ObjectMotionType__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_interfaces__msg__ObjectMotionType__Sequence__copy(
  const map_interfaces__msg__ObjectMotionType__Sequence * input,
  map_interfaces__msg__ObjectMotionType__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_interfaces__msg__ObjectMotionType);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_interfaces__msg__ObjectMotionType * data =
      (map_interfaces__msg__ObjectMotionType *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_interfaces__msg__ObjectMotionType__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_interfaces__msg__ObjectMotionType__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_interfaces__msg__ObjectMotionType__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
