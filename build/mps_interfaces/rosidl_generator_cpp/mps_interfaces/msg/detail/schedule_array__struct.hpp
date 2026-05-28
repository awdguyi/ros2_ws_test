// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mps_interfaces:msg/ScheduleArray.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__STRUCT_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'schedules'
#include "mps_interfaces/msg/detail/schedule__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mps_interfaces__msg__ScheduleArray __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__msg__ScheduleArray __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ScheduleArray_
{
  using Type = ScheduleArray_<ContainerAllocator>;

  explicit ScheduleArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ScheduleArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _schedules_type =
    std::vector<mps_interfaces::msg::Schedule_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mps_interfaces::msg::Schedule_<ContainerAllocator>>>;
  _schedules_type schedules;

  // setters for named parameter idiom
  Type & set__schedules(
    const std::vector<mps_interfaces::msg::Schedule_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<mps_interfaces::msg::Schedule_<ContainerAllocator>>> & _arg)
  {
    this->schedules = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::msg::ScheduleArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::msg::ScheduleArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::ScheduleArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::ScheduleArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__msg__ScheduleArray
    std::shared_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__msg__ScheduleArray
    std::shared_ptr<mps_interfaces::msg::ScheduleArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ScheduleArray_ & other) const
  {
    if (this->schedules != other.schedules) {
      return false;
    }
    return true;
  }
  bool operator!=(const ScheduleArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ScheduleArray_

// alias to use template instance with default allocator
using ScheduleArray =
  mps_interfaces::msg::ScheduleArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE_ARRAY__STRUCT_HPP_
