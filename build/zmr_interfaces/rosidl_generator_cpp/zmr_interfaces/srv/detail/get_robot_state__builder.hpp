// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zmr_interfaces:srv/GetRobotState.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__BUILDER_HPP_
#define ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zmr_interfaces/srv/detail/get_robot_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRobotState_Request_robot_id
{
public:
  Init_GetRobotState_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zmr_interfaces::srv::GetRobotState_Request robot_id(::zmr_interfaces::srv::GetRobotState_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zmr_interfaces::srv::GetRobotState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zmr_interfaces::srv::GetRobotState_Request>()
{
  return zmr_interfaces::srv::builder::Init_GetRobotState_Request_robot_id();
}

}  // namespace zmr_interfaces


namespace zmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRobotState_Response_future_states
{
public:
  explicit Init_GetRobotState_Response_future_states(::zmr_interfaces::srv::GetRobotState_Response & msg)
  : msg_(msg)
  {}
  ::zmr_interfaces::srv::GetRobotState_Response future_states(::zmr_interfaces::srv::GetRobotState_Response::_future_states_type arg)
  {
    msg_.future_states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zmr_interfaces::srv::GetRobotState_Response msg_;
};

class Init_GetRobotState_Response_robot_state
{
public:
  Init_GetRobotState_Response_robot_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotState_Response_future_states robot_state(::zmr_interfaces::srv::GetRobotState_Response::_robot_state_type arg)
  {
    msg_.robot_state = std::move(arg);
    return Init_GetRobotState_Response_future_states(msg_);
  }

private:
  ::zmr_interfaces::srv::GetRobotState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zmr_interfaces::srv::GetRobotState_Response>()
{
  return zmr_interfaces::srv::builder::Init_GetRobotState_Response_robot_state();
}

}  // namespace zmr_interfaces

#endif  // ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__BUILDER_HPP_
