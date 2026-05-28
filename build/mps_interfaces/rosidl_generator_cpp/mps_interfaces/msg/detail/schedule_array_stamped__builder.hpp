// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:msg/ScheduleArrayStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY_STAMPED__BUILDER_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/msg/detail/schedule_array_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace msg
{

namespace builder
{

class Init_ScheduleArrayStamped_schedules
{
public:
  explicit Init_ScheduleArrayStamped_schedules(::mps_interfaces::msg::ScheduleArrayStamped & msg)
  : msg_(msg)
  {}
  ::mps_interfaces::msg::ScheduleArrayStamped schedules(::mps_interfaces::msg::ScheduleArrayStamped::_schedules_type arg)
  {
    msg_.schedules = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::msg::ScheduleArrayStamped msg_;
};

class Init_ScheduleArrayStamped_header
{
public:
  Init_ScheduleArrayStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScheduleArrayStamped_schedules header(::mps_interfaces::msg::ScheduleArrayStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ScheduleArrayStamped_schedules(msg_);
  }

private:
  ::mps_interfaces::msg::ScheduleArrayStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::msg::ScheduleArrayStamped>()
{
  return mps_interfaces::msg::builder::Init_ScheduleArrayStamped_header();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY_STAMPED__BUILDER_HPP_
