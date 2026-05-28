// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_interfaces:msg/GeometricMap.idl
// generated code does not contain a copyright notice
#include "map_interfaces/msg/detail/geometric_map__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `boundary`
#include "map_interfaces/msg/detail/polygon_object__functions.h"
// Member `obstacle_list`
#include "map_interfaces/msg/detail/polygon_object_array__functions.h"

bool
map_interfaces__msg__GeometricMap__init(map_interfaces__msg__GeometricMap * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    map_interfaces__msg__GeometricMap__fini(msg);
    return false;
  }
  // boundary
  if (!map_interfaces__msg__PolygonObject__init(&msg->boundary)) {
    map_interfaces__msg__GeometricMap__fini(msg);
    return false;
  }
  // obstacle_list
  if (!map_interfaces__msg__PolygonObjectArray__init(&msg->obstacle_list)) {
    map_interfaces__msg__GeometricMap__fini(msg);
    return false;
  }
  return true;
}

void
map_interfaces__msg__GeometricMap__fini(map_interfaces__msg__GeometricMap * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // boundary
  map_interfaces__msg__PolygonObject__fini(&msg->boundary);
  // obstacle_list
  map_interfaces__msg__PolygonObjectArray__fini(&msg->obstacle_list);
}

bool
map_interfaces__msg__GeometricMap__are_equal(const map_interfaces__msg__GeometricMap * lhs, const map_interfaces__msg__GeometricMap * rhs)
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
  // boundary
  if (!map_interfaces__msg__PolygonObject__are_equal(
      &(lhs->boundary), &(rhs->boundary)))
  {
    return false;
  }
  // obstacle_list
  if (!map_interfaces__msg__PolygonObjectArray__are_equal(
      &(lhs->obstacle_list), &(rhs->obstacle_list)))
  {
    return false;
  }
  return true;
}

bool
map_interfaces__msg__GeometricMap__copy(
  const map_interfaces__msg__GeometricMap * input,
  map_interfaces__msg__GeometricMap * output)
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
  // boundary
  if (!map_interfaces__msg__PolygonObject__copy(
      &(input->boundary), &(output->boundary)))
  {
    return false;
  }
  // obstacle_list
  if (!map_interfaces__msg__PolygonObjectArray__copy(
      &(input->obstacle_list), &(output->obstacle_list)))
  {
    return false;
  }
  return true;
}

map_interfaces__msg__GeometricMap *
map_interfaces__msg__GeometricMap__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__GeometricMap * msg = (map_interfaces__msg__GeometricMap *)allocator.allocate(sizeof(map_interfaces__msg__GeometricMap), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_interfaces__msg__GeometricMap));
  bool success = map_interfaces__msg__GeometricMap__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_interfaces__msg__GeometricMap__destroy(map_interfaces__msg__GeometricMap * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_interfaces__msg__GeometricMap__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_interfaces__msg__GeometricMap__Sequence__init(map_interfaces__msg__GeometricMap__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__GeometricMap * data = NULL;

  if (size) {
    data = (map_interfaces__msg__GeometricMap *)allocator.zero_allocate(size, sizeof(map_interfaces__msg__GeometricMap), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_interfaces__msg__GeometricMap__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_interfaces__msg__GeometricMap__fini(&data[i - 1]);
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
map_interfaces__msg__GeometricMap__Sequence__fini(map_interfaces__msg__GeometricMap__Sequence * array)
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
      map_interfaces__msg__GeometricMap__fini(&array->data[i]);
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

map_interfaces__msg__GeometricMap__Sequence *
map_interfaces__msg__GeometricMap__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__GeometricMap__Sequence * array = (map_interfaces__msg__GeometricMap__Sequence *)allocator.allocate(sizeof(map_interfaces__msg__GeometricMap__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_interfaces__msg__GeometricMap__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_interfaces__msg__GeometricMap__Sequence__destroy(map_interfaces__msg__GeometricMap__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_interfaces__msg__GeometricMap__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_interfaces__msg__GeometricMap__Sequence__are_equal(const map_interfaces__msg__GeometricMap__Sequence * lhs, const map_interfaces__msg__GeometricMap__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_interfaces__msg__GeometricMap__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_interfaces__msg__GeometricMap__Sequence__copy(
  const map_interfaces__msg__GeometricMap__Sequence * input,
  map_interfaces__msg__GeometricMap__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_interfaces__msg__GeometricMap);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_interfaces__msg__GeometricMap * data =
      (map_interfaces__msg__GeometricMap *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_interfaces__msg__GeometricMap__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_interfaces__msg__GeometricMap__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_interfaces__msg__GeometricMap__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
