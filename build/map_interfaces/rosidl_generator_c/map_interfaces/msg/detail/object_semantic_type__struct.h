// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from map_interfaces:msg/ObjectSemanticType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__STRUCT_H_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__STRUCT_H_

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
  map_interfaces__msg__ObjectSemanticType__UNKNOWN = 0
};

/// Constant 'HUMAN'.
enum
{
  map_interfaces__msg__ObjectSemanticType__HUMAN = 1
};

/// Constant 'FORKLIFT'.
enum
{
  map_interfaces__msg__ObjectSemanticType__FORKLIFT = 2
};

/// Constant 'WALL'.
enum
{
  map_interfaces__msg__ObjectSemanticType__WALL = 3
};

/// Constant 'CONTAINER'.
enum
{
  map_interfaces__msg__ObjectSemanticType__CONTAINER = 4
};

/// Struct defined in msg/ObjectSemanticType in the package map_interfaces.
/**
  * Object semantic type
 */
typedef struct map_interfaces__msg__ObjectSemanticType
{
  int8_t o_semantic_type;
} map_interfaces__msg__ObjectSemanticType;

// Struct for a sequence of map_interfaces__msg__ObjectSemanticType.
typedef struct map_interfaces__msg__ObjectSemanticType__Sequence
{
  map_interfaces__msg__ObjectSemanticType * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} map_interfaces__msg__ObjectSemanticType__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__STRUCT_H_
