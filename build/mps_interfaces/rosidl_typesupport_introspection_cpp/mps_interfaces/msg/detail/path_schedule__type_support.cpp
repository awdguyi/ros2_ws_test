// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mps_interfaces/msg/detail/path_schedule__struct.hpp"
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

void PathSchedule_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mps_interfaces::msg::PathSchedule(_init);
}

void PathSchedule_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mps_interfaces::msg::PathSchedule *>(message_memory);
  typed_message->~PathSchedule();
}

size_t size_function__PathSchedule__path_coords(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathSchedule__path_coords(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__PathSchedule__path_coords(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathSchedule__path_coords(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__PathSchedule__path_coords(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__PathSchedule__path_coords(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__PathSchedule__path_coords(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__PathSchedule__path_coords(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

size_t size_function__PathSchedule__path_times(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__PathSchedule__path_times(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__PathSchedule__path_times(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__PathSchedule__path_times(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__PathSchedule__path_times(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__PathSchedule__path_times(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__PathSchedule__path_times(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__PathSchedule__path_times(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PathSchedule_message_member_array[3] = {
  {
    "robot_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces::msg::PathSchedule, robot_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "path_coords",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces::msg::PathSchedule, path_coords),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathSchedule__path_coords,  // size() function pointer
    get_const_function__PathSchedule__path_coords,  // get_const(index) function pointer
    get_function__PathSchedule__path_coords,  // get(index) function pointer
    fetch_function__PathSchedule__path_coords,  // fetch(index, &value) function pointer
    assign_function__PathSchedule__path_coords,  // assign(index, value) function pointer
    resize_function__PathSchedule__path_coords  // resize(index) function pointer
  },
  {
    "path_times",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mps_interfaces::msg::PathSchedule, path_times),  // bytes offset in struct
    nullptr,  // default value
    size_function__PathSchedule__path_times,  // size() function pointer
    get_const_function__PathSchedule__path_times,  // get_const(index) function pointer
    get_function__PathSchedule__path_times,  // get(index) function pointer
    fetch_function__PathSchedule__path_times,  // fetch(index, &value) function pointer
    assign_function__PathSchedule__path_times,  // assign(index, value) function pointer
    resize_function__PathSchedule__path_times  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PathSchedule_message_members = {
  "mps_interfaces::msg",  // message namespace
  "PathSchedule",  // message name
  3,  // number of fields
  sizeof(mps_interfaces::msg::PathSchedule),
  PathSchedule_message_member_array,  // message members
  PathSchedule_init_function,  // function to initialize message memory (memory has to be allocated)
  PathSchedule_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PathSchedule_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PathSchedule_message_members,
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
get_message_type_support_handle<mps_interfaces::msg::PathSchedule>()
{
  return &::mps_interfaces::msg::rosidl_typesupport_introspection_cpp::PathSchedule_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mps_interfaces, msg, PathSchedule)() {
  return &::mps_interfaces::msg::rosidl_typesupport_introspection_cpp::PathSchedule_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
