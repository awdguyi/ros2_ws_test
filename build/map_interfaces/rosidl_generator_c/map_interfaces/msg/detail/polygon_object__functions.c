// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice
#include "map_interfaces/msg/detail/polygon_object__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `object_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `polygon`
#include "geometry_msgs/msg/detail/polygon__functions.h"
// Member `centroid`
#include "geometry_msgs/msg/detail/point32__functions.h"
// Member `object_shape_t`
#include "map_interfaces/msg/detail/object_shape_type__functions.h"
// Member `object_motion_t`
#include "map_interfaces/msg/detail/object_motion_type__functions.h"
// Member `object_semantic_t`
#include "map_interfaces/msg/detail/object_semantic_type__functions.h"

bool
map_interfaces__msg__PolygonObject__init(map_interfaces__msg__PolygonObject * msg)
{
  if (!msg) {
    return false;
  }
  // object_id
  // object_name
  if (!rosidl_runtime_c__String__init(&msg->object_name)) {
    map_interfaces__msg__PolygonObject__fini(msg);
    return false;
  }
  // polygon
  if (!geometry_msgs__msg__Polygon__init(&msg->polygon)) {
    map_interfaces__msg__PolygonObject__fini(msg);
    return false;
  }
  // centroid
  if (!geometry_msgs__msg__Point32__init(&msg->centroid)) {
    map_interfaces__msg__PolygonObject__fini(msg);
    return false;
  }
  // object_shape_t
  if (!map_interfaces__msg__ObjectShapeType__init(&msg->object_shape_t)) {
    map_interfaces__msg__PolygonObject__fini(msg);
    return false;
  }
  // object_motion_t
  if (!map_interfaces__msg__ObjectMotionType__init(&msg->object_motion_t)) {
    map_interfaces__msg__PolygonObject__fini(msg);
    return false;
  }
  // object_semantic_t
  if (!map_interfaces__msg__ObjectSemanticType__init(&msg->object_semantic_t)) {
    map_interfaces__msg__PolygonObject__fini(msg);
    return false;
  }
  return true;
}

void
map_interfaces__msg__PolygonObject__fini(map_interfaces__msg__PolygonObject * msg)
{
  if (!msg) {
    return;
  }
  // object_id
  // object_name
  rosidl_runtime_c__String__fini(&msg->object_name);
  // polygon
  geometry_msgs__msg__Polygon__fini(&msg->polygon);
  // centroid
  geometry_msgs__msg__Point32__fini(&msg->centroid);
  // object_shape_t
  map_interfaces__msg__ObjectShapeType__fini(&msg->object_shape_t);
  // object_motion_t
  map_interfaces__msg__ObjectMotionType__fini(&msg->object_motion_t);
  // object_semantic_t
  map_interfaces__msg__ObjectSemanticType__fini(&msg->object_semantic_t);
}

bool
map_interfaces__msg__PolygonObject__are_equal(const map_interfaces__msg__PolygonObject * lhs, const map_interfaces__msg__PolygonObject * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // object_id
  if (lhs->object_id != rhs->object_id) {
    return false;
  }
  // object_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object_name), &(rhs->object_name)))
  {
    return false;
  }
  // polygon
  if (!geometry_msgs__msg__Polygon__are_equal(
      &(lhs->polygon), &(rhs->polygon)))
  {
    return false;
  }
  // centroid
  if (!geometry_msgs__msg__Point32__are_equal(
      &(lhs->centroid), &(rhs->centroid)))
  {
    return false;
  }
  // object_shape_t
  if (!map_interfaces__msg__ObjectShapeType__are_equal(
      &(lhs->object_shape_t), &(rhs->object_shape_t)))
  {
    return false;
  }
  // object_motion_t
  if (!map_interfaces__msg__ObjectMotionType__are_equal(
      &(lhs->object_motion_t), &(rhs->object_motion_t)))
  {
    return false;
  }
  // object_semantic_t
  if (!map_interfaces__msg__ObjectSemanticType__are_equal(
      &(lhs->object_semantic_t), &(rhs->object_semantic_t)))
  {
    return false;
  }
  return true;
}

bool
map_interfaces__msg__PolygonObject__copy(
  const map_interfaces__msg__PolygonObject * input,
  map_interfaces__msg__PolygonObject * output)
{
  if (!input || !output) {
    return false;
  }
  // object_id
  output->object_id = input->object_id;
  // object_name
  if (!rosidl_runtime_c__String__copy(
      &(input->object_name), &(output->object_name)))
  {
    return false;
  }
  // polygon
  if (!geometry_msgs__msg__Polygon__copy(
      &(input->polygon), &(output->polygon)))
  {
    return false;
  }
  // centroid
  if (!geometry_msgs__msg__Point32__copy(
      &(input->centroid), &(output->centroid)))
  {
    return false;
  }
  // object_shape_t
  if (!map_interfaces__msg__ObjectShapeType__copy(
      &(input->object_shape_t), &(output->object_shape_t)))
  {
    return false;
  }
  // object_motion_t
  if (!map_interfaces__msg__ObjectMotionType__copy(
      &(input->object_motion_t), &(output->object_motion_t)))
  {
    return false;
  }
  // object_semantic_t
  if (!map_interfaces__msg__ObjectSemanticType__copy(
      &(input->object_semantic_t), &(output->object_semantic_t)))
  {
    return false;
  }
  return true;
}

map_interfaces__msg__PolygonObject *
map_interfaces__msg__PolygonObject__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__PolygonObject * msg = (map_interfaces__msg__PolygonObject *)allocator.allocate(sizeof(map_interfaces__msg__PolygonObject), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(map_interfaces__msg__PolygonObject));
  bool success = map_interfaces__msg__PolygonObject__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
map_interfaces__msg__PolygonObject__destroy(map_interfaces__msg__PolygonObject * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    map_interfaces__msg__PolygonObject__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
map_interfaces__msg__PolygonObject__Sequence__init(map_interfaces__msg__PolygonObject__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__PolygonObject * data = NULL;

  if (size) {
    data = (map_interfaces__msg__PolygonObject *)allocator.zero_allocate(size, sizeof(map_interfaces__msg__PolygonObject), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = map_interfaces__msg__PolygonObject__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        map_interfaces__msg__PolygonObject__fini(&data[i - 1]);
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
map_interfaces__msg__PolygonObject__Sequence__fini(map_interfaces__msg__PolygonObject__Sequence * array)
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
      map_interfaces__msg__PolygonObject__fini(&array->data[i]);
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

map_interfaces__msg__PolygonObject__Sequence *
map_interfaces__msg__PolygonObject__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  map_interfaces__msg__PolygonObject__Sequence * array = (map_interfaces__msg__PolygonObject__Sequence *)allocator.allocate(sizeof(map_interfaces__msg__PolygonObject__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = map_interfaces__msg__PolygonObject__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
map_interfaces__msg__PolygonObject__Sequence__destroy(map_interfaces__msg__PolygonObject__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    map_interfaces__msg__PolygonObject__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
map_interfaces__msg__PolygonObject__Sequence__are_equal(const map_interfaces__msg__PolygonObject__Sequence * lhs, const map_interfaces__msg__PolygonObject__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!map_interfaces__msg__PolygonObject__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
map_interfaces__msg__PolygonObject__Sequence__copy(
  const map_interfaces__msg__PolygonObject__Sequence * input,
  map_interfaces__msg__PolygonObject__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(map_interfaces__msg__PolygonObject);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    map_interfaces__msg__PolygonObject * data =
      (map_interfaces__msg__PolygonObject *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!map_interfaces__msg__PolygonObject__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          map_interfaces__msg__PolygonObject__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!map_interfaces__msg__PolygonObject__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
