// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/GeometricMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'boundary'
#include "map_interfaces/msg/detail/polygon_object__struct.h"
// Member 'obstacle_list'
#include "map_interfaces/msg/detail/polygon_object_array__struct.h"

/// Struct defined in msg/GeometricMap in the package map_interfaces.
/**
  * Boundary and Obstacle List for Map
 */
typedef struct map_interfaces__msg__GeometricMap
{
  /// header with frame_id and timestamp
  std_msgs__msg__Header header;
  map_interfaces__msg__PolygonObject boundary;
  map_interfaces__msg__PolygonObjectArray obstacle_list;
} map_interfaces__msg__GeometricMap;

// Struct for a sequence of map_interfaces__msg__GeometricMap.
typedef struct map_interfaces__msg__GeometricMap__Sequence
{
  map_interfaces__msg__GeometricMap * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__GeometricMap__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__STRUCT_H_
