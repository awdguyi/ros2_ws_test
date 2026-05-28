// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__BUILDER_HPP_
#define ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zmr_interfaces/msg/detail/current_future_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zmr_interfaces
{

namespace msg
{

namespace builder
{

class Init_CurrentFutureStates_robot_states
{
public:
  Init_CurrentFutureStates_robot_states()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zmr_interfaces::msg::CurrentFutureStates robot_states(::zmr_interfaces::msg::CurrentFutureStates::_robot_states_type arg)
  {
    msg_.robot_states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zmr_interfaces::msg::CurrentFutureStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zmr_interfaces::msg::CurrentFutureStates>()
{
  return zmr_interfaces::msg::builder::Init_CurrentFutureStates_robot_states();
}

}  // namespace zmr_interfaces

#endif  // ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__BUILDER_HPP_
