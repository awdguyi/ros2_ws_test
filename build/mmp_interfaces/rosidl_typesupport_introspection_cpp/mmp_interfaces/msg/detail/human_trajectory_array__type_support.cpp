// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from mmp_interfaces:msg/HumanTrajectoryArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "mmp_interfaces/msg/detail/human_trajectory_array__struct.hpp"
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

void HumanTrajectoryArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) mmp_interfaces::msg::HumanTrajectoryArray(_init);
}

void HumanTrajectoryArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<mmp_interfaces::msg::HumanTrajectoryArray *>(message_memory);
  typed_message->~HumanTrajectoryArray();
}

size_t size_function__HumanTrajectoryArray__human_trajectories(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<mmp_interfaces::msg::HumanTrajectory> *>(untyped_member);
  return member->size();
}

const void * get_const_function__HumanTrajectoryArray__human_trajectories(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<mmp_interfaces::msg::HumanTrajectory> *>(untyped_member);
  return &member[index];
}

void * get_function__HumanTrajectoryArray__human_trajectories(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<mmp_interfaces::msg::HumanTrajectory> *>(untyped_member);
  return &member[index];
}

void fetch_function__HumanTrajectoryArray__human_trajectories(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const mmp_interfaces::msg::HumanTrajectory *>(
    get_const_function__HumanTrajectoryArray__human_trajectories(untyped_member, index));
  auto & value = *reinterpret_cast<mmp_interfaces::msg::HumanTrajectory *>(untyped_value);
  value = item;
}

void assign_function__HumanTrajectoryArray__human_trajectories(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<mmp_interfaces::msg::HumanTrajectory *>(
    get_function__HumanTrajectoryArray__human_trajectories(untyped_member, index));
  const auto & value = *reinterpret_cast<const mmp_interfaces::msg::HumanTrajectory *>(untyped_value);
  item = value;
}

void resize_function__HumanTrajectoryArray__human_trajectories(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<mmp_interfaces::msg::HumanTrajectory> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HumanTrajectoryArray_message_member_array[1] = {
  {
    "human_trajectories",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<mmp_interfaces::msg::HumanTrajectory>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mmp_interfaces::msg::HumanTrajectoryArray, human_trajectories),  // bytes offset in struct
    nullptr,  // default value
    size_function__HumanTrajectoryArray__human_trajectories,  // size() function pointer
    get_const_function__HumanTrajectoryArray__human_trajectories,  // get_const(index) function pointer
    get_function__HumanTrajectoryArray__human_trajectories,  // get(index) function pointer
    fetch_function__HumanTrajectoryArray__human_trajectories,  // fetch(index, &value) function pointer
    assign_function__HumanTrajectoryArray__human_trajectories,  // assign(index, value) function pointer
    resize_function__HumanTrajectoryArray__human_trajectories  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HumanTrajectoryArray_message_members = {
  "mmp_interfaces::msg",  // message namespace
  "HumanTrajectoryArray",  // message name
  1,  // number of fields
  sizeof(mmp_interfaces::msg::HumanTrajectoryArray),
  HumanTrajectoryArray_message_member_array,  // message members
  HumanTrajectoryArray_init_function,  // function to initialize message memory (memory has to be allocated)
  HumanTrajectoryArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HumanTrajectoryArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HumanTrajectoryArray_message_members,
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
get_message_type_support_handle<mmp_interfaces::msg::HumanTrajectoryArray>()
{
  return &::mmp_interfaces::msg::rosidl_typesupport_introspection_cpp::HumanTrajectoryArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, mmp_interfaces, msg, HumanTrajectoryArray)() {
  return &::mmp_interfaces::msg::rosidl_typesupport_introspection_cpp::HumanTrajectoryArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
