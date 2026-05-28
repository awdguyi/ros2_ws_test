// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mps_interfaces/msg/detail/schedule_array__rosidl_typesupport_introspection_c.h"
#include "mps_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mps_interfaces/msg/detail/schedule_array__functions.h"
#include "mps_interfaces/msg/detail/schedule_array__struct.h"


// Include directives for member types
// Member `schedules`
#include "mps_interfaces/msg/schedule.h"
// Member `schedules`
#include "mps_interfaces/msg/detail/schedule__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mps_interfaces__msg__ScheduleArray__init(message_memory);
}

void mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_fini_function(void * message_memory)
{
  mps_interfaces__msg__ScheduleArray__fini(message_memory);
}

size_t mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__size_function__ScheduleArray__schedules(
  const void * untyped_member)
{
  const mps_interfaces__msg__Schedule__Sequence * member =
    (const mps_interfaces__msg__Schedule__Sequence *)(untyped_member);
  return member->size;
}

const void * mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__get_const_function__ScheduleArray__schedules(
  const void * untyped_member, size_t index)
{
  const mps_interfaces__msg__Schedule__Sequence * member =
    (const mps_interfaces__msg__Schedule__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__get_function__ScheduleArray__schedules(
  void * untyped_member, size_t index)
{
  mps_interfaces__msg__Schedule__Sequence * member =
    (mps_interfaces__msg__Schedule__Sequence *)(untyped_member);
  return &member->data[index];
}

void mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__fetch_function__ScheduleArray__schedules(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mps_interfaces__msg__Schedule * item =
    ((const mps_interfaces__msg__Schedule *)
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__get_const_function__ScheduleArray__schedules(untyped_member, index));
  mps_interfaces__msg__Schedule * value =
    (mps_interfaces__msg__Schedule *)(untyped_value);
  *value = *item;
}

void mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__assign_function__ScheduleArray__schedules(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mps_interfaces__msg__Schedule * item =
    ((mps_interfaces__msg__Schedule *)
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__get_function__ScheduleArray__schedules(untyped_member, index));
  const mps_interfaces__msg__Schedule * value =
    (const mps_interfaces__msg__Schedule *)(untyped_value);
  *item = *value;
}

bool mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__resize_function__ScheduleArray__schedules(
  void * untyped_member, size_t size)
{
  mps_interfaces__msg__Schedule__Sequence * member =
    (mps_interfaces__msg__Schedule__Sequence *)(untyped_member);
  mps_interfaces__msg__Schedule__Sequence__fini(member);
  return mps_interfaces__msg__Schedule__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_member_array[1] = {
  {
    "schedules",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces__msg__ScheduleArray, schedules),  // bytes offset in struct
    NULL,  // default value
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__size_function__ScheduleArray__schedules,  // size() function pointer
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__get_const_function__ScheduleArray__schedules,  // get_const(index) function pointer
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__get_function__ScheduleArray__schedules,  // get(index) function pointer
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__fetch_function__ScheduleArray__schedules,  // fetch(index, &value) function pointer
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__assign_function__ScheduleArray__schedules,  // assign(index, value) function pointer
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__resize_function__ScheduleArray__schedules  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_members = {
  "mps_interfaces__msg",  // message namespace
  "ScheduleArray",  // message name
  1,  // number of fields
  sizeof(mps_interfaces__msg__ScheduleArray),
  mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_member_array,  // message members
  mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_init_function,  // function to initialize message memory (memory has to be allocated)
  mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_type_support_handle = {
  0,
  &mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mps_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, msg, ScheduleArray)() {
  mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mps_interfaces, msg, Schedule)();
  if (!mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_type_support_handle.typesupport_identifier) {
    mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mps_interfaces__msg__ScheduleArray__rosidl_typesupport_introspection_c__ScheduleArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
