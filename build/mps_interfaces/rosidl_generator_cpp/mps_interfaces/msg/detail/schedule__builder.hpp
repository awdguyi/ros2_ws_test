// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE__BUILDER_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mps_interfaces/msg/detail/schedule__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mps_interfaces
{

namespace msg
{

namespace builder
{

class Init_Schedule_etas
{
public:
  explicit Init_Schedule_etas(::mps_interfaces::msg::Schedule & msg)
  : msg_(msg)
  {}
  ::mps_interfaces::msg::Schedule etas(::mps_interfaces::msg::Schedule::_etas_type arg)
  {
    msg_.etas = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mps_interfaces::msg::Schedule msg_;
};

class Init_Schedule_node_names
{
public:
  explicit Init_Schedule_node_names(::mps_interfaces::msg::Schedule & msg)
  : msg_(msg)
  {}
  Init_Schedule_etas node_names(::mps_interfaces::msg::Schedule::_node_names_type arg)
  {
    msg_.node_names = std::move(arg);
    return Init_Schedule_etas(msg_);
  }

private:
  ::mps_interfaces::msg::Schedule msg_;
};

class Init_Schedule_node_ids
{
public:
  explicit Init_Schedule_node_ids(::mps_interfaces::msg::Schedule & msg)
  : msg_(msg)
  {}
  Init_Schedule_node_names node_ids(::mps_interfaces::msg::Schedule::_node_ids_type arg)
  {
    msg_.node_ids = std::move(arg);
    return Init_Schedule_node_names(msg_);
  }

private:
  ::mps_interfaces::msg::Schedule msg_;
};

class Init_Schedule_robot_id
{
public:
  explicit Init_Schedule_robot_id(::mps_interfaces::msg::Schedule & msg)
  : msg_(msg)
  {}
  Init_Schedule_node_ids robot_id(::mps_interfaces::msg::Schedule::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_Schedule_node_ids(msg_);
  }

private:
  ::mps_interfaces::msg::Schedule msg_;
};

class Init_Schedule_schedule_name
{
public:
  Init_Schedule_schedule_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Schedule_robot_id schedule_name(::mps_interfaces::msg::Schedule::_schedule_name_type arg)
  {
    msg_.schedule_name = std::move(arg);
    return Init_Schedule_robot_id(msg_);
  }

private:
  ::mps_interfaces::msg::Schedule msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mps_interfaces::msg::Schedule>()
{
  return mps_interfaces::msg::builder::Init_Schedule_schedule_name();
}

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE__BUILDER_HPP_
