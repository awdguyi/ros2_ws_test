// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zmr_interfaces:srv/GetOtherRobotStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__SRV__DETAIL__GET_OTHER_ROBOT_STATES__BUILDER_HPP_
#define ZMR_INTERFACES__SRV__DETAIL__GET_OTHER_ROBOT_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zmr_interfaces/srv/detail/get_other_robot_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetOtherRobotStates_Request_ego_robot_id
{
public:
  Init_GetOtherRobotStates_Request_ego_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zmr_interfaces::srv::GetOtherRobotStates_Request ego_robot_id(::zmr_interfaces::srv::GetOtherRobotStates_Request::_ego_robot_id_type arg)
  {
    msg_.ego_robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zmr_interfaces::srv::GetOtherRobotStates_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zmr_interfaces::srv::GetOtherRobotStates_Request>()
{
  return zmr_interfaces::srv::builder::Init_GetOtherRobotStates_Request_ego_robot_id();
}

}  // namespace zmr_interfaces


namespace zmr_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetOtherRobotStates_Response_other_robot_states_in_order
{
public:
  Init_GetOtherRobotStates_Response_other_robot_states_in_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::zmr_interfaces::srv::GetOtherRobotStates_Response other_robot_states_in_order(::zmr_interfaces::srv::GetOtherRobotStates_Response::_other_robot_states_in_order_type arg)
  {
    msg_.other_robot_states_in_order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zmr_interfaces::srv::GetOtherRobotStates_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::zmr_interfaces::srv::GetOtherRobotStates_Response>()
{
  return zmr_interfaces::srv::builder::Init_GetOtherRobotStates_Response_other_robot_states_in_order();
}

}  // namespace zmr_interfaces

#endif  // ZMR_INTERFACES__SRV__DETAIL__GET_OTHER_ROBOT_STATES__BUILDER_HPP_
