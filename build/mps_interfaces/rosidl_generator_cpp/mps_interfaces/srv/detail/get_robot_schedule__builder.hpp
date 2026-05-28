// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:srv/GetRobotSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__BUILDER_HPP_
#define MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/srv/detail/get_robot_schedule__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRobotSchedule_Request_current_time
{
public:
  explicit Init_GetRobotSchedule_Request_current_time(::mps_interfaces::srv::GetRobotSchedule_Request & msg)
  : msg_(msg)
  {}
  ::mps_interfaces::srv::GetRobotSchedule_Request current_time(::mps_interfaces::srv::GetRobotSchedule_Request::_current_time_type arg)
  {
    msg_.current_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::srv::GetRobotSchedule_Request msg_;
};

class Init_GetRobotSchedule_Request_robot_id
{
public:
  Init_GetRobotSchedule_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRobotSchedule_Request_current_time robot_id(::mps_interfaces::srv::GetRobotSchedule_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_GetRobotSchedule_Request_current_time(msg_);
  }

private:
  ::mps_interfaces::srv::GetRobotSchedule_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::srv::GetRobotSchedule_Request>()
{
  return mps_interfaces::srv::builder::Init_GetRobotSchedule_Request_robot_id();
}

}  // namespace mps_interfaces


namespace mps_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetRobotSchedule_Response_path_schedule
{
public:
  Init_GetRobotSchedule_Response_path_schedule()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mps_interfaces::srv::GetRobotSchedule_Response path_schedule(::mps_interfaces::srv::GetRobotSchedule_Response::_path_schedule_type arg)
  {
    msg_.path_schedule = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::srv::GetRobotSchedule_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::srv::GetRobotSchedule_Response>()
{
  return mps_interfaces::srv::builder::Init_GetRobotSchedule_Response_path_schedule();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_ROBOT_SCHEDULE__BUILDER_HPP_
