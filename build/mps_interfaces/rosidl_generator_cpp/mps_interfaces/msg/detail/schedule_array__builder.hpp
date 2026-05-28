// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__BUILDER_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/msg/detail/schedule_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace msg
{

namespace builder
{

class Init_ScheduleArray_schedules
{
public:
  Init_ScheduleArray_schedules()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mps_interfaces::msg::ScheduleArray schedules(::mps_interfaces::msg::ScheduleArray::_schedules_type arg)
  {
    msg_.schedules = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::msg::ScheduleArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::msg::ScheduleArray>()
{
  return mps_interfaces::msg::builder::Init_ScheduleArray_schedules();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__BUILDER_HPP_
