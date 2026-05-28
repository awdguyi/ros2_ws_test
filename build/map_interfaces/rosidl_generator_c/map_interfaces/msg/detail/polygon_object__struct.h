// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'object_name'
#include "rosidl_runtime_c/string.h"
// Member 'polygon'
#include "geometry_msgs/msg/detail/polygon__struct.h"
// Member 'centroid'
#include "geometry_msgs/msg/detail/point32__struct.h"
// Member 'object_shape_t'
#include "map_interfaces/msg/detail/object_shape_type__struct.h"
// Member 'object_motion_t'
#include "map_interfaces/msg/detail/object_motion_type__struct.h"
// Member 'object_semantic_t'
#include "map_interfaces/msg/detail/object_semantic_type__struct.h"

/// Struct defined in msg/PolygonObject in the package map_interfaces.
/**
  * Polygon with 2D points forming the object
 */
typedef struct map_interfaces__msg__PolygonObject
{
  /// Identifier of the object
  int16_t object_id;
  rosidl_runtime_c__String object_name;
  /// Object date
  geometry_msgs__msg__Polygon polygon;
  geometry_msgs__msg__Point32 centroid;
  /// Object extra information
  /// Type of object, 1 = polygon.
  map_interfaces__msg__ObjectShapeType object_shape_t;
  /// Type of object, e.g., static, dynamic, etc.
  map_interfaces__msg__ObjectMotionType object_motion_t;
  /// Type of object, e.g., car, human, etc.
  map_interfaces__msg__ObjectSemanticType object_semantic_t;
} map_interfaces__msg__PolygonObject;

// Struct for a sequence of map_interfaces__msg__PolygonObject.
typedef struct map_interfaces__msg__PolygonObject__Sequence
{
  map_interfaces__msg__PolygonObject * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__PolygonObject__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__STRUCT_H_
