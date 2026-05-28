// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mmp_interfaces:msg/HumanTrajectory.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__BUILDER_HPP_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mmp_interfaces/msg/detail/human_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mmp_interfaces
{

namespace msg
{

namespace builder
{

class Init_HumanTrajectory_traj_points
{
public:
  Init_HumanTrajectory_traj_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mmp_interfaces::msg::HumanTrajectory traj_points(::mmp_interfaces::msg::HumanTrajectory::_traj_points_type arg)
  {
    msg_.traj_points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mmp_interfaces::msg::HumanTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mmp_interfaces::msg::HumanTrajectory>()
{
  return mmp_interfaces::msg::builder::Init_HumanTrajectory_traj_points();
}

}  // namespace mmp_interfaces

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__BUILDER_HPP_
