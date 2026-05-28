// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mmp_interfaces:msg/HumanTrajectoryArray.idl
// generated code does not contain a copyright notice

#ifndef MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__STRUCT_HPP_
#define MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'human_trajectories'
#include "mmp_interfaces/msg/detail/human_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mmp_interfaces__msg__HumanTrajectoryArray __attribute__((deprecated))
#else
# define DEPRECATED__mmp_interfaces__msg__HumanTrajectoryArray __declspec(deprecated)
#endif

namespace mmp_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HumanTrajectoryArray_
{
  using Type = HumanTrajectoryArray_<ContainerAllocator>;

  explicit HumanTrajectoryArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit HumanTrajectoryArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _human_trajectories_type =
    std::vector<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>>;
  _human_trajectories_type human_trajectories;

  // setters for named parameter idiom
  Type & set__human_trajectories(
    const std::vector<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mmp_interfaces::msg::HumanTrajectory_<ContainerAllocator>>> & _arg)
  {
    this->human_trajectories = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mmp_interfaces__msg__HumanTrajectoryArray
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mmp_interfaces__msg__HumanTrajectoryArray
    std::shared_ptr<mmp_interfaces::msg::HumanTrajectoryArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HumanTrajectoryArray_ & other) const
  {
    if (this->human_trajectories != other.human_trajectories) {
      return false;
    }
    return true;
  }
  bool operator!=(const HumanTrajectoryArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HumanTrajectoryArray_

// alias to use template instance with default allocator
using HumanTrajectoryArray =
  mmp_interfaces::msg::HumanTrajectoryArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mmp_interfaces

#endif  // MMP_INTERFACES__MSG__DETAIL__HUMAN_TRAJECTORY_ARRAY__STRUCT_HPP_
