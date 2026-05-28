// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/PolygonObjectArrayStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__STRUCT_H_

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
// Member 'polygon_objects'
#include "map_interfaces/msg/detail/polygon_object_array__struct.h"

/// Struct defined in msg/PolygonObjectArrayStamped in the package map_interfaces.
/**
  * Array of polygons, with header
 */
typedef struct map_interfaces__msg__PolygonObjectArrayStamped
{
  /// header with frame_id and timestamp
  std_msgs__msg__Header header;
  map_interfaces__msg__PolygonObjectArray polygon_objects;
} map_interfaces__msg__PolygonObjectArrayStamped;

// Struct for a sequence of map_interfaces__msg__PolygonObjectArrayStamped.
typedef struct map_interfaces__msg__PolygonObjectArrayStamped__Sequence
{
  map_interfaces__msg__PolygonObjectArrayStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__PolygonObjectArrayStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__STRUCT_H_
