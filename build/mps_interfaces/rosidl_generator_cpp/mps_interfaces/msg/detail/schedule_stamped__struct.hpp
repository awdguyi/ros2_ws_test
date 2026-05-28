// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mps_interfaces:msg/ScheduleStamped.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__STRUCT_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'schedule'
#include "mps_interfaces/msg/detail/schedule__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mps_interfaces__msg__ScheduleStamped __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__msg__ScheduleStamped __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ScheduleStamped_
{
  using Type = ScheduleStamped_<ContainerAllocator>;

  explicit ScheduleStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    schedule(_init)
  {
    (void)_init;
  }

  explicit ScheduleStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    schedule(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _schedule_type =
    mps_interfaces::msg::Schedule_<ContainerAllocator>;
  _schedule_type schedule;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__schedule(
    const mps_interfaces::msg::Schedule_<ContainerAllocator> & _arg)
  {
    this->schedule = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::msg::ScheduleStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::msg::ScheduleStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::ScheduleStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::ScheduleStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__msg__ScheduleStamped
    std::shared_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__msg__ScheduleStamped
    std::shared_ptr<mps_interfaces::msg::ScheduleStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ScheduleStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->schedule != other.schedule) {
      return false;
    }
    return true;
  }
  bool operator!=(const ScheduleStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ScheduleStamped_

// alias to use template instance with default allocator
using ScheduleStamped =
  mps_interfaces::msg::ScheduleStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_STAMPED__STRUCT_HPP_
