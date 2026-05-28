// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mps_interfaces/msg/detail/path_schedule__rosidl_typesupport_introspection_c.h"
#include "mps_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mps_interfaces/msg/detail/path_schedule__functions.h"
#include "mps_interfaces/msg/detail/path_schedule__struct.h"


// Include directives for member types
// Member `path_coords`
#include "geometry_msgs/msg/point.h"
// Member `path_coords`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `path_times`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mps_interfaces__msg__PathSchedule__init(message_memory);
}

void mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_fini_function(void * message_memory)
{
  mps_interfaces__msg__PathSchedule__fini(message_memory);
}

size_t mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__size_function__PathSchedule__path_coords(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_const_function__PathSchedule__path_coords(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_function__PathSchedule__path_coords(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__fetch_function__PathSchedule__path_coords(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_const_function__PathSchedule__path_coords(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__assign_function__PathSchedule__path_coords(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_function__PathSchedule__path_coords(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__resize_function__PathSchedule__path_coords(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__size_function__PathSchedule__path_times(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_const_function__PathSchedule__path_times(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_function__PathSchedule__path_times(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__fetch_function__PathSchedule__path_times(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_const_function__PathSchedule__path_times(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__assign_function__PathSchedule__path_times(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_function__PathSchedule__path_times(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__resize_function__PathSchedule__path_times(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_member_array[3] = {
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__PathSchedule, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "path_coords",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__PathSchedule, path_coords),  // bytes offset in struct
    NULL,  // default value
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__size_function__PathSchedule__path_coords,  // size() function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_const_function__PathSchedule__path_coords,  // get_const(index) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_function__PathSchedule__path_coords,  // get(index) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__fetch_function__PathSchedule__path_coords,  // fetch(index, &value) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__assign_function__PathSchedule__path_coords,  // assign(index, value) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__resize_function__PathSchedule__path_coords  // resize(index) function pointer
  },
  {
    "path_times",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__PathSchedule, path_times),  // bytes offset in struct
    NULL,  // default value
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__size_function__PathSchedule__path_times,  // size() function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_const_function__PathSchedule__path_times,  // get_const(index) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__get_function__PathSchedule__path_times,  // get(index) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__fetch_function__PathSchedule__path_times,  // fetch(index, &value) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__assign_function__PathSchedule__path_times,  // assign(index, value) function pointer
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__resize_function__PathSchedule__path_times  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_members = {
  "mps_interfaces__msg",  // message namespace
  "PathSchedule",  // message name
  3,  // number of fields
  sizeof(mps_interfaces__msg__PathSchedule),
  mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_member_array,  // message members
  mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_init_function,  // function to initialize message memory (memory has to be allocated)
  mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_type_support_handle = {
  0,
  &mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mps_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, msg, PathSchedule)() {
  mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_type_support_handle.typesupport_identifier) {
    mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mps_interfaces__msg__PathSchedule__rosidl_typesupport_introspection_c__PathSchedule_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
