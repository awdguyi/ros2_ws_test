// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mmp_interfaces:msg/HumanTrajectory.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__STRUCT_H_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'traj_points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/HumanTrajectory in the package mmp_interfaces.
/**
  * Trajectory of human
 */
typedef struct mmp_interfaces__msg__HumanTrajectory
{
  /// points of the trajectory
  geometry_msgs__msg__Point__Sequence traj_points;
} mmp_interfaces__msg__HumanTrajectory;

// Struct for a sequence of mmp_interfaces__msg__HumanTrajectory.
typedef struct mmp_interfaces__msg__HumanTrajectory__Sequence
{
  mmp_interfaces__msg__HumanTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mmp_interfaces__msg__HumanTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__STRUCT_H_
