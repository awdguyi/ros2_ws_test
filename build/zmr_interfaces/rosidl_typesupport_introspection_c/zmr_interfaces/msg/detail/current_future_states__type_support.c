// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zmr_interfaces/msg/detail/current_future_states__rosidl_typesupport_introspection_c.h"
#include "zmr_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zmr_interfaces/msg/detail/current_future_states__functions.h"
#include "zmr_interfaces/msg/detail/current_future_states__struct.h"


// Include directives for member types
// Member `robot_states`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zmr_interfaces__msg__CurrentFutureStates__init(message_memory);
}

void zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_fini_function(void * message_memory)
{
  zmr_interfaces__msg__CurrentFutureStates__fini(message_memory);
}

size_t zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__size_function__CurrentFutureStates__robot_states(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__get_const_function__CurrentFutureStates__robot_states(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__get_function__CurrentFutureStates__robot_states(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__fetch_function__CurrentFutureStates__robot_states(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__get_const_function__CurrentFutureStates__robot_states(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__assign_function__CurrentFutureStates__robot_states(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__get_function__CurrentFutureStates__robot_states(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__resize_function__CurrentFutureStates__robot_states(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_member_array[1] = {
  {
    "robot_states",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zmr_interfaces__msg__CurrentFutureStates, robot_states),  // bytes offset in struct
    NULL,  // default value
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__size_function__CurrentFutureStates__robot_states,  // size() function pointer
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__get_const_function__CurrentFutureStates__robot_states,  // get_const(index) function pointer
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__get_function__CurrentFutureStates__robot_states,  // get(index) function pointer
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__fetch_function__CurrentFutureStates__robot_states,  // fetch(index, &value) function pointer
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__assign_function__CurrentFutureStates__robot_states,  // assign(index, value) function pointer
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__resize_function__CurrentFutureStates__robot_states  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_members = {
  "zmr_interfaces__msg",  // message namespace
  "CurrentFutureStates",  // message name
  1,  // number of fields
  sizeof(zmr_interfaces__msg__CurrentFutureStates),
  zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_member_array,  // message members
  zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_init_function,  // function to initialize message memory (memory has to be allocated)
  zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_type_support_handle = {
  0,
  &zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zmr_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zmr_interfaces, msg, CurrentFutureStates)() {
  if (!zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_type_support_handle.typesupport_identifier) {
    zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zmr_interfaces__msg__CurrentFutureStates__rosidl_typesupport_introspection_c__CurrentFutureStates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
