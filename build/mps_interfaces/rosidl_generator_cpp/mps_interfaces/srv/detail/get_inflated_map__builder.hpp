// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:srv/GetInflatedMap.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__BUILDER_HPP_
#define MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/srv/detail/get_inflated_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetInflatedMap_Request_robot_id
{
public:
  Init_GetInflatedMap_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mps_interfaces::srv::GetInflatedMap_Request robot_id(::mps_interfaces::srv::GetInflatedMap_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::srv::GetInflatedMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::srv::GetInflatedMap_Request>()
{
  return mps_interfaces::srv::builder::Init_GetInflatedMap_Request_robot_id();
}

}  // namespace mps_interfaces


namespace mps_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetInflatedMap_Response_inflated_map
{
public:
  Init_GetInflatedMap_Response_inflated_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mps_interfaces::srv::GetInflatedMap_Response inflated_map(::mps_interfaces::srv::GetInflatedMap_Response::_inflated_map_type arg)
  {
    msg_.inflated_map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::srv::GetInflatedMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::srv::GetInflatedMap_Response>()
{
  return mps_interfaces::srv::builder::Init_GetInflatedMap_Response_inflated_map();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__BUILDER_HPP_
