// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mps_interfaces:msg/ScheduleStamped.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mps_interfaces/msg/detail/schedule_stamped__struct.hpp"
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

void ScheduleStamped_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mps_interfaces::msg::ScheduleStamped(_init);
}

void ScheduleStamped_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mps_interfaces::msg::ScheduleStamped *>(message_memory);
  typed_message->~ScheduleStamped();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ScheduleStamped_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces::msg::ScheduleStamped, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "schedule",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<mps_interfaces::msg::Schedule>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces::msg::ScheduleStamped, schedule),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ScheduleStamped_message_members = {
  "mps_interfaces::msg",  // message namespace
  "ScheduleStamped",  // message name
  2,  // number of fields
  sizeof(mps_interfaces::msg::ScheduleStamped),
  ScheduleStamped_message_member_array,  // message members
  ScheduleStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  ScheduleStamped_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ScheduleStamped_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ScheduleStamped_message_members,
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
get_message_type_support_handle<mps_interfaces::msg::ScheduleStamped>()
{
  return &::mps_interfaces::msg::rosidl_typesupport_introspection_cpp::ScheduleStamped_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mps_interfaces, msg, ScheduleStamped)() {
  return &::mps_interfaces::msg::rosidl_typesupport_introspection_cpp::ScheduleStamped_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
