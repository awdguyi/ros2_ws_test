// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/ObjectMotionType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__STRUCT_H_

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
  map_interfaces__msg__ObjectMotionType__UNKNOWN = 0
};

/// Constant 'STATIC'.
enum
{
  map_interfaces__msg__ObjectMotionType__STATIC = 1
};

/// Constant 'DYNAMIC'.
enum
{
  map_interfaces__msg__ObjectMotionType__DYNAMIC = 2
};

/// Struct defined in msg/ObjectMotionType in the package map_interfaces.
/**
  * Object motion type
 */
typedef struct map_interfaces__msg__ObjectMotionType
{
  int8_t o_motion_type;
} map_interfaces__msg__ObjectMotionType;

// Struct for a sequence of map_interfaces__msg__ObjectMotionType.
typedef struct map_interfaces__msg__ObjectMotionType__Sequence
{
  map_interfaces__msg__ObjectMotionType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__ObjectMotionType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__STRUCT_H_
