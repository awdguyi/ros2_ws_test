// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'polygon_objects'
#include "map_interfaces/msg/detail/polygon_object__struct.h"

/// Struct defined in msg/PolygonObjectArray in the package map_interfaces.
/**
  * Array of polygons
 */
typedef struct map_interfaces__msg__PolygonObjectArray
{
  map_interfaces__msg__PolygonObject__Sequence polygon_objects;
} map_interfaces__msg__PolygonObjectArray;

// Struct for a sequence of map_interfaces__msg__PolygonObjectArray.
typedef struct map_interfaces__msg__PolygonObjectArray__Sequence
{
  map_interfaces__msg__PolygonObjectArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__PolygonObjectArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__STRUCT_H_
