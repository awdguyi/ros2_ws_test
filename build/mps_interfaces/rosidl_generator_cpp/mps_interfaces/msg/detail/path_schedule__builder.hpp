// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__BUILDER_HPP_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/msg/detail/path_schedule__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace msg
{

namespace builder
{

class Init_PathSchedule_path_times
{
public:
  explicit Init_PathSchedule_path_times(::mps_interfaces::msg::PathSchedule & msg)
  : msg_(msg)
  {}
  ::mps_interfaces::msg::PathSchedule path_times(::mps_interfaces::msg::PathSchedule::_path_times_type arg)
  {
    msg_.path_times = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::msg::PathSchedule msg_;
};

class Init_PathSchedule_path_coords
{
public:
  explicit Init_PathSchedule_path_coords(::mps_interfaces::msg::PathSchedule & msg)
  : msg_(msg)
  {}
  Init_PathSchedule_path_times path_coords(::mps_interfaces::msg::PathSchedule::_path_coords_type arg)
  {
    msg_.path_coords = std::move(arg);
    return Init_PathSchedule_path_times(msg_);
  }

private:
  ::mps_interfaces::msg::PathSchedule msg_;
};

class Init_PathSchedule_robot_id
{
public:
  Init_PathSchedule_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathSchedule_path_coords robot_id(::mps_interfaces::msg::PathSchedule::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_PathSchedule_path_coords(msg_);
  }

private:
  ::mps_interfaces::msg::PathSchedule msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::msg::PathSchedule>()
{
  return mps_interfaces::msg::builder::Init_PathSchedule_robot_id();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__BUILDER_HPP_
