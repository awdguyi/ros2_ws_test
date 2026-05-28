// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mps_interfaces/msg/detail/schedule__rosidl_typesupport_introspection_c.h"
#include "mps_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mps_interfaces/msg/detail/schedule__functions.h"
#include "mps_interfaces/msg/detail/schedule__struct.h"


// Include directives for member types
// Member `schedule_name`
// Member `node_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `node_ids`
// Member `etas`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mps_interfaces__msg__Schedule__init(message_memory);
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_fini_function(void * message_memory)
{
  mps_interfaces__msg__Schedule__fini(message_memory);
}

size_t mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__size_function__Schedule__node_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__node_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__node_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__fetch_function__Schedule__node_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__node_ids(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__assign_function__Schedule__node_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__node_ids(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__resize_function__Schedule__node_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__size_function__Schedule__node_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__node_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__node_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__fetch_function__Schedule__node_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__node_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__assign_function__Schedule__node_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__node_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__resize_function__Schedule__node_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__size_function__Schedule__etas(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__etas(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__etas(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__fetch_function__Schedule__etas(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__etas(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__assign_function__Schedule__etas(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__etas(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__resize_function__Schedule__etas(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_member_array[5] = {
  {
    "schedule_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__Schedule, schedule_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__Schedule, robot_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "node_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__Schedule, node_ids),  // bytes offset in struct
    NULL,  // default value
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__size_function__Schedule__node_ids,  // size() function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__node_ids,  // get_const(index) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__node_ids,  // get(index) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__fetch_function__Schedule__node_ids,  // fetch(index, &value) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__assign_function__Schedule__node_ids,  // assign(index, value) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__resize_function__Schedule__node_ids  // resize(index) function pointer
  },
  {
    "node_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__Schedule, node_names),  // bytes offset in struct
    NULL,  // default value
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__size_function__Schedule__node_names,  // size() function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__node_names,  // get_const(index) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__node_names,  // get(index) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__fetch_function__Schedule__node_names,  // fetch(index, &value) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__assign_function__Schedule__node_names,  // assign(index, value) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__resize_function__Schedule__node_names  // resize(index) function pointer
  },
  {
    "etas",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__Schedule, etas),  // bytes offset in struct
    NULL,  // default value
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__size_function__Schedule__etas,  // size() function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_const_function__Schedule__etas,  // get_const(index) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__get_function__Schedule__etas,  // get(index) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__fetch_function__Schedule__etas,  // fetch(index, &value) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__assign_function__Schedule__etas,  // assign(index, value) function pointer
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__resize_function__Schedule__etas  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_members = {
  "mps_interfaces__msg",  // message namespace
  "Schedule",  // message name
  5,  // number of fields
  sizeof(mps_interfaces__msg__Schedule),
  mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_member_array,  // message members
  mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_init_function,  // function to initialize message memory (memory has to be allocated)
  mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_type_support_handle = {
  0,
  &mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mps_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, msg, Schedule)() {
  if (!mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_type_support_handle.typesupport_identifier) {
    mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mps_interfaces__msg__Schedule__rosidl_typesupport_introspection_c__Schedule_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
