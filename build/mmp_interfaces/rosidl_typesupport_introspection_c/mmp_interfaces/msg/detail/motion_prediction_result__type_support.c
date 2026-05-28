// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mmp_interfaces:msg/MotionPredictionResult.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mmp_interfaces/msg/detail/motion_prediction_result__rosidl_typesupport_introspection_c.h"
#include "mmp_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mmp_interfaces/msg/detail/motion_prediction_result__functions.h"
#include "mmp_interfaces/msg/detail/motion_prediction_result__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `mu_list_list`
// Member `std_list_list`
// Member `conf_list_list`
#include "mmp_interfaces/msg/human_trajectory_array.h"
// Member `mu_list_list`
// Member `std_list_list`
// Member `conf_list_list`
#include "mmp_interfaces/msg/detail/human_trajectory_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mmp_interfaces__msg__MotionPredictionResult__init(message_memory);
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_fini_function(void * message_memory)
{
  mmp_interfaces__msg__MotionPredictionResult__fini(message_memory);
}

size_t mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__size_function__MotionPredictionResult__mu_list_list(
  const void * untyped_member)
{
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (const mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return member->size;
}

const void * mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__mu_list_list(
  const void * untyped_member, size_t index)
{
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (const mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__mu_list_list(
  void * untyped_member, size_t index)
{
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__fetch_function__MotionPredictionResult__mu_list_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mmp_interfaces__msg__HumanTrajectoryArray * item =
    ((const mmp_interfaces__msg__HumanTrajectoryArray *)
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__mu_list_list(untyped_member, index));
  mmp_interfaces__msg__HumanTrajectoryArray * value =
    (mmp_interfaces__msg__HumanTrajectoryArray *)(untyped_value);
  *value = *item;
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__assign_function__MotionPredictionResult__mu_list_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mmp_interfaces__msg__HumanTrajectoryArray * item =
    ((mmp_interfaces__msg__HumanTrajectoryArray *)
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__mu_list_list(untyped_member, index));
  const mmp_interfaces__msg__HumanTrajectoryArray * value =
    (const mmp_interfaces__msg__HumanTrajectoryArray *)(untyped_value);
  *item = *value;
}

bool mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__resize_function__MotionPredictionResult__mu_list_list(
  void * untyped_member, size_t size)
{
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(member);
  return mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(member, size);
}

size_t mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__size_function__MotionPredictionResult__std_list_list(
  const void * untyped_member)
{
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (const mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return member->size;
}

const void * mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__std_list_list(
  const void * untyped_member, size_t index)
{
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (const mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__std_list_list(
  void * untyped_member, size_t index)
{
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__fetch_function__MotionPredictionResult__std_list_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mmp_interfaces__msg__HumanTrajectoryArray * item =
    ((const mmp_interfaces__msg__HumanTrajectoryArray *)
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__std_list_list(untyped_member, index));
  mmp_interfaces__msg__HumanTrajectoryArray * value =
    (mmp_interfaces__msg__HumanTrajectoryArray *)(untyped_value);
  *value = *item;
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__assign_function__MotionPredictionResult__std_list_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mmp_interfaces__msg__HumanTrajectoryArray * item =
    ((mmp_interfaces__msg__HumanTrajectoryArray *)
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__std_list_list(untyped_member, index));
  const mmp_interfaces__msg__HumanTrajectoryArray * value =
    (const mmp_interfaces__msg__HumanTrajectoryArray *)(untyped_value);
  *item = *value;
}

bool mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__resize_function__MotionPredictionResult__std_list_list(
  void * untyped_member, size_t size)
{
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(member);
  return mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(member, size);
}

size_t mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__size_function__MotionPredictionResult__conf_list_list(
  const void * untyped_member)
{
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (const mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return member->size;
}

const void * mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__conf_list_list(
  const void * untyped_member, size_t index)
{
  const mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (const mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__conf_list_list(
  void * untyped_member, size_t index)
{
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__fetch_function__MotionPredictionResult__conf_list_list(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mmp_interfaces__msg__HumanTrajectoryArray * item =
    ((const mmp_interfaces__msg__HumanTrajectoryArray *)
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__conf_list_list(untyped_member, index));
  mmp_interfaces__msg__HumanTrajectoryArray * value =
    (mmp_interfaces__msg__HumanTrajectoryArray *)(untyped_value);
  *value = *item;
}

void mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__assign_function__MotionPredictionResult__conf_list_list(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mmp_interfaces__msg__HumanTrajectoryArray * item =
    ((mmp_interfaces__msg__HumanTrajectoryArray *)
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__conf_list_list(untyped_member, index));
  const mmp_interfaces__msg__HumanTrajectoryArray * value =
    (const mmp_interfaces__msg__HumanTrajectoryArray *)(untyped_value);
  *item = *value;
}

bool mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__resize_function__MotionPredictionResult__conf_list_list(
  void * untyped_member, size_t size)
{
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence * member =
    (mmp_interfaces__msg__HumanTrajectoryArray__Sequence *)(untyped_member);
  mmp_interfaces__msg__HumanTrajectoryArray__Sequence__fini(member);
  return mmp_interfaces__msg__HumanTrajectoryArray__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmp_interfaces__msg__MotionPredictionResult, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mu_list_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmp_interfaces__msg__MotionPredictionResult, mu_list_list),  // bytes offset in struct
    NULL,  // default value
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__size_function__MotionPredictionResult__mu_list_list,  // size() function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__mu_list_list,  // get_const(index) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__mu_list_list,  // get(index) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__fetch_function__MotionPredictionResult__mu_list_list,  // fetch(index, &value) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__assign_function__MotionPredictionResult__mu_list_list,  // assign(index, value) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__resize_function__MotionPredictionResult__mu_list_list  // resize(index) function pointer
  },
  {
    "std_list_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmp_interfaces__msg__MotionPredictionResult, std_list_list),  // bytes offset in struct
    NULL,  // default value
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__size_function__MotionPredictionResult__std_list_list,  // size() function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__std_list_list,  // get_const(index) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__std_list_list,  // get(index) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__fetch_function__MotionPredictionResult__std_list_list,  // fetch(index, &value) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__assign_function__MotionPredictionResult__std_list_list,  // assign(index, value) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__resize_function__MotionPredictionResult__std_list_list  // resize(index) function pointer
  },
  {
    "conf_list_list",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmp_interfaces__msg__MotionPredictionResult, conf_list_list),  // bytes offset in struct
    NULL,  // default value
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__size_function__MotionPredictionResult__conf_list_list,  // size() function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_const_function__MotionPredictionResult__conf_list_list,  // get_const(index) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__get_function__MotionPredictionResult__conf_list_list,  // get(index) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__fetch_function__MotionPredictionResult__conf_list_list,  // fetch(index, &value) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__assign_function__MotionPredictionResult__conf_list_list,  // assign(index, value) function pointer
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__resize_function__MotionPredictionResult__conf_list_list  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_members = {
  "mmp_interfaces__msg",  // message namespace
  "MotionPredictionResult",  // message name
  4,  // number of fields
  sizeof(mmp_interfaces__msg__MotionPredictionResult),
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_member_array,  // message members
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_init_function,  // function to initialize message memory (memory has to be allocated)
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_type_support_handle = {
  0,
  &mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mmp_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmp_interfaces, msg, MotionPredictionResult)() {
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmp_interfaces, msg, HumanTrajectoryArray)();
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmp_interfaces, msg, HumanTrajectoryArray)();
  mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mmp_interfaces, msg, HumanTrajectoryArray)();
  if (!mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_type_support_handle.typesupport_identifier) {
    mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mmp_interfaces__msg__MotionPredictionResult__rosidl_typesupport_introspection_c__MotionPredictionResult_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
