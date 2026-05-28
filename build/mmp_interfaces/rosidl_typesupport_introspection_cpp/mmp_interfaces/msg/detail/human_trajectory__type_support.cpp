// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mmp_interfaces:msg/HumanTrajectory.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mmp_interfaces/msg/detail/human_trajectory__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace mmp_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HumanTrajectory_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mmp_interfaces::msg::HumanTrajectory(_init);
}

void HumanTrajectory_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mmp_interfaces::msg::HumanTrajectory *>(message_memory);
  typed_message->~HumanTrajectory();
}

size_t size_function__HumanTrajectory__traj_points(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return member->size();
}

const void * get_const_function__HumanTrajectory__traj_points(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void * get_function__HumanTrajectory__traj_points(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  return &member[index];
}

void fetch_function__HumanTrajectory__traj_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Point *>(
    get_const_function__HumanTrajectory__traj_points(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Point *>(untyped_value);
  value = item;
}

void assign_function__HumanTrajectory__traj_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Point *>(
    get_function__HumanTrajectory__traj_points(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Point *>(untyped_value);
  item = value;
}

void resize_function__HumanTrajectory__traj_points(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Point> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HumanTrajectory_message_member_array[1] = {
  {
    "traj_points",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmp_interfaces::msg::HumanTrajectory, traj_points),  // bytes offset in struct
    nullptr,  // default value
    size_function__HumanTrajectory__traj_points,  // size() function pointer
    get_const_function__HumanTrajectory__traj_points,  // get_const(index) function pointer
    get_function__HumanTrajectory__traj_points,  // get(index) function pointer
    fetch_function__HumanTrajectory__traj_points,  // fetch(index, &value) function pointer
    assign_function__HumanTrajectory__traj_points,  // assign(index, value) function pointer
    resize_function__HumanTrajectory__traj_points  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HumanTrajectory_message_members = {
  "mmp_interfaces::msg",  // message namespace
  "HumanTrajectory",  // message name
  1,  // number of fields
  sizeof(mmp_interfaces::msg::HumanTrajectory),
  HumanTrajectory_message_member_array,  // message members
  HumanTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  HumanTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HumanTrajectory_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HumanTrajectory_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace mmp_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<mmp_interfaces::msg::HumanTrajectory>()
{
  return &::mmp_interfaces::msg::rosidl_typesupport_introspection_cpp::HumanTrajectory_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mmp_interfaces, msg, HumanTrajectory)() {
  return &::mmp_interfaces::msg::rosidl_typesupport_introspection_cpp::HumanTrajectory_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
