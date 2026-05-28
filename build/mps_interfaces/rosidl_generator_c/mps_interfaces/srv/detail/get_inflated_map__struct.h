// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mps_interfaces:srv/GetInflatedMap.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__STRUCT_H_
#define MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetInflatedMap in the package mps_interfaces.
typedef struct mps_interfaces__srv__GetInflatedMap_Request
{
  int64_t robot_id;
} mps_interfaces__srv__GetInflatedMap_Request;

// Struct for a sequence of mps_interfaces__srv__GetInflatedMap_Request.
typedef struct mps_interfaces__srv__GetInflatedMap_Request__Sequence
{
  mps_interfaces__srv__GetInflatedMap_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__srv__GetInflatedMap_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'inflated_map'
#include "map_interfaces/msg/detail/geometric_map__struct.h"

/// Struct defined in srv/GetInflatedMap in the package mps_interfaces.
typedef struct mps_interfaces__srv__GetInflatedMap_Response
{
  map_interfaces__msg__GeometricMap inflated_map;
} mps_interfaces__srv__GetInflatedMap_Response;

// Struct for a sequence of mps_interfaces__srv__GetInflatedMap_Response.
typedef struct mps_interfaces__srv__GetInflatedMap_Response__Sequence
{
  mps_interfaces__srv__GetInflatedMap_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mps_interfaces__srv__GetInflatedMap_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__STRUCT_H_
