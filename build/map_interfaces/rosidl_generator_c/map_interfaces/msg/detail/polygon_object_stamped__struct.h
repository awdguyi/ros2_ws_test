// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/PolygonObjectStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__STRUCT_H_

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
// Member 'polygon_object'
#include "map_interfaces/msg/detail/polygon_object__struct.h"

/// Struct defined in msg/PolygonObjectStamped in the package map_interfaces.
/**
  * Polygon with 2D points forming the object, with header
 */
typedef struct map_interfaces__msg__PolygonObjectStamped
{
  /// Header with frame_id and timestamp
  std_msgs__msg__Header header;
  /// Polygon with 2D points forming the object
  map_interfaces__msg__PolygonObject polygon_object;
} map_interfaces__msg__PolygonObjectStamped;

// Struct for a sequence of map_interfaces__msg__PolygonObjectStamped.
typedef struct map_interfaces__msg__PolygonObjectStamped__Sequence
{
  map_interfaces__msg__PolygonObjectStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__PolygonObjectStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__STRUCT_H_
