// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:msg/PathScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__BUILDER_HPP_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/msg/detail/path_schedule_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace msg
{

namespace builder
{

class Init_PathScheduleStamped_path_schedule
{
public:
  explicit Init_PathScheduleStamped_path_schedule(::mps_interfaces::msg::PathScheduleStamped & msg)
  : msg_(msg)
  {}
  ::mps_interfaces::msg::PathScheduleStamped path_schedule(::mps_interfaces::msg::PathScheduleStamped::_path_schedule_type arg)
  {
    msg_.path_schedule = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::msg::PathScheduleStamped msg_;
};

class Init_PathScheduleStamped_header
{
public:
  Init_PathScheduleStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PathScheduleStamped_path_schedule header(::mps_interfaces::msg::PathScheduleStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PathScheduleStamped_path_schedule(msg_);
  }

private:
  ::mps_interfaces::msg::PathScheduleStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::msg::PathScheduleStamped>()
{
  return mps_interfaces::msg::builder::Init_PathScheduleStamped_header();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE_STAMPED__BUILDER_HPP_
