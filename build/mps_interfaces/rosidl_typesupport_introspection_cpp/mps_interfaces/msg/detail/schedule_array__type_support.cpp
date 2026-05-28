// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mps_interfaces/msg/detail/schedule_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mps_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ScheduleArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mps_interfaces::msg::ScheduleArray(_init);
}

void ScheduleArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mps_interfaces::msg::ScheduleArray *>(message_memory);
  typed_message->~ScheduleArray();
}

size_t size_function__ScheduleArray__schedules(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<mps_interfaces::msg::Schedule> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ScheduleArray__schedules(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<mps_interfaces::msg::Schedule> *>(untyped_member);
  return &member[index];
}

void * get_function__ScheduleArray__schedules(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<mps_interfaces::msg::Schedule> *>(untyped_member);
  return &member[index];
}

void fetch_function__ScheduleArray__schedules(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const mps_interfaces::msg::Schedule *>(
    get_const_function__ScheduleArray__schedules(untyped_member, index));
  auto & value = *reinterpret_cast<mps_interfaces::msg::Schedule *>(untyped_value);
  value = item;
}

void assign_function__ScheduleArray__schedules(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<mps_interfaces::msg::Schedule *>(
    get_function__ScheduleArray__schedules(untyped_member, index));
  const auto & value = *reinterpret_cast<const mps_interfaces::msg::Schedule *>(untyped_value);
  item = value;
}

void resize_function__ScheduleArray__schedules(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<mps_interfaces::msg::Schedule> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ScheduleArray_message_member_array[1] = {
  {
    "schedules",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<mps_interfaces::msg::Schedule>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces::msg::ScheduleArray, schedules),  // bytes offset in struct
    nullptr,  // default value
    size_function__ScheduleArray__schedules,  // size() function pointer
    get_const_function__ScheduleArray__schedules,  // get_const(index) function pointer
    get_function__ScheduleArray__schedules,  // get(index) function pointer
    fetch_function__ScheduleArray__schedules,  // fetch(index, &value) function pointer
    assign_function__ScheduleArray__schedules,  // assign(index, value) function pointer
    resize_function__ScheduleArray__schedules  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ScheduleArray_message_members = {
  "mps_interfaces::msg",  // message namespace
  "ScheduleArray",  // message name
  1,  // number of fields
  sizeof(mps_interfaces::msg::ScheduleArray),
  ScheduleArray_message_member_array,  // message members
  ScheduleArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ScheduleArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ScheduleArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ScheduleArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mps_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mps_interfaces::msg::ScheduleArray>()
{
  return &::mps_interfaces::msg::rosidl_typesupport_introspection_cpp::ScheduleArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mps_interfaces, msg, ScheduleArray)() {
  return &::mps_interfaces::msg::rosidl_typesupport_introspection_cpp::ScheduleArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
