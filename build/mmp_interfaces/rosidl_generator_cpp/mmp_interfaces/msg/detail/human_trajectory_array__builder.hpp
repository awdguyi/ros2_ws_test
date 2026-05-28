// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmp_interfaces:msg/HumanTrajectoryArray.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__BUILDER_HPP_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmp_interfaces/msg/detail/human_trajectory_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmp_interfaces
{

namespace msg
{

namespace builder
{

class Init_HumanTrajectoryArray_human_trajectories
{
public:
  Init_HumanTrajectoryArray_human_trajectories()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmp_interfaces::msg::HumanTrajectoryArray human_trajectories(::mmp_interfaces::msg::HumanTrajectoryArray::_human_trajectories_type arg)
  {
    msg_.human_trajectories = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmp_interfaces::msg::HumanTrajectoryArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmp_interfaces::msg::HumanTrajectoryArray>()
{
  return mmp_interfaces::msg::builder::Init_HumanTrajectoryArray_human_trajectories();
}

}  // namespace mmp_interfaces

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__BUILDER_HPP_
