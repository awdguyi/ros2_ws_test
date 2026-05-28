// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:msg/ScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__BUILDER_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/msg/detail/schedule_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace msg
{

namespace builder
{

class Init_ScheduleStamped_schedule
{
public:
  explicit Init_ScheduleStamped_schedule(::mps_interfaces::msg::ScheduleStamped & msg)
  : msg_(msg)
  {}
  ::mps_interfaces::msg::ScheduleStamped schedule(::mps_interfaces::msg::ScheduleStamped::_schedule_type arg)
  {
    msg_.schedule = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::msg::ScheduleStamped msg_;
};

class Init_ScheduleStamped_header
{
public:
  Init_ScheduleStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScheduleStamped_schedule header(::mps_interfaces::msg::ScheduleStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ScheduleStamped_schedule(msg_);
  }

private:
  ::mps_interfaces::msg::ScheduleStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::msg::ScheduleStamped>()
{
  return mps_interfaces::msg::builder::Init_ScheduleStamped_header();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__BUILDER_HPP_
