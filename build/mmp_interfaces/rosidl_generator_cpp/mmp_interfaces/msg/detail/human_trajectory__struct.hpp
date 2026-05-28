// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mmp_interfaces:msg/HumanTrajectory.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__STRUCT_HPP_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'traj_points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mmp_interfaces__msg__HumanTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__mmp_interfaces__msg__HumanTrajectory __declspec(deprecated)
#endif

namespace mmp_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HumanTrajectory_
{
  using Type = HumanTrajectory_<ContainerAllocator>;

  explicit HumanTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit HumanTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _traj_points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _traj_points_type traj_points;

  // setters for named parameter idiom
  Type & set__traj_points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->traj_points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmp_interfaces__msg__HumanTrajectory
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmp_interfaces__msg__HumanTrajectory
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HumanTrajectory_ & other) const
  {
    if (this->traj_points != other.traj_points) {
      return false;
    }
    return true;
  }
  bool operator!=(const HumanTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HumanTrajectory_

// alias to use template instance with default allocator
using HumanTrajectory =
  mmp_interfaces::msg::HumanTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mmp_interfaces

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY__STRUCT_HPP_
