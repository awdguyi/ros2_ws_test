// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__STRUCT_H_
#define ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_states'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/CurrentFutureStates in the package zmr_interfaces.
typedef struct zmr_interfaces__msg__CurrentFutureStates
{
  /// contains the current and future (within the horizon) states of the robot
  rosidl_runtime_c__double__Sequence robot_states;
} zmr_interfaces__msg__CurrentFutureStates;

// Struct for a sequence of zmr_interfaces__msg__CurrentFutureStates.
typedef struct zmr_interfaces__msg__CurrentFutureStates__Sequence
{
  zmr_interfaces__msg__CurrentFutureStates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zmr_interfaces__msg__CurrentFutureStates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__STRUCT_H_
