// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/ObjectShapeType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_SHAPE_TYPE__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_SHAPE_TYPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'UNKNOWN'.
/**
  * Object types
 */
enum
{
  map_interfaces__msg__ObjectShapeType__UNKNOWN = 0
};

/// Constant 'POLYGON'.
enum
{
  map_interfaces__msg__ObjectShapeType__POLYGON = 1
};

/// Constant 'CIRCLE'.
enum
{
  map_interfaces__msg__ObjectShapeType__CIRCLE = 2
};

/// Constant 'ELLIPSE'.
enum
{
  map_interfaces__msg__ObjectShapeType__ELLIPSE = 3
};

/// Struct defined in msg/ObjectShapeType in the package map_interfaces.
/**
  * Object shape type
 */
typedef struct map_interfaces__msg__ObjectShapeType
{
  int8_t o_shape_type;
} map_interfaces__msg__ObjectShapeType;

// Struct for a sequence of map_interfaces__msg__ObjectShapeType.
typedef struct map_interfaces__msg__ObjectShapeType__Sequence
{
  map_interfaces__msg__ObjectShapeType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__ObjectShapeType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_SHAPE_TYPE__STRUCT_H_
