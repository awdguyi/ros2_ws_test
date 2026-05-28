// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zmr_interfaces:msg/CurrentFutureStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__STRUCT_HPP_
#define ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__zmr_interfaces__msg__CurrentFutureStates __attribute__((deprecated))
#else
# define DEPRECATED__zmr_interfaces__msg__CurrentFutureStates __declspec(deprecated)
#endif

namespace zmr_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CurrentFutureStates_
{
  using Type = CurrentFutureStates_<ContainerAllocator>;

  explicit CurrentFutureStates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit CurrentFutureStates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _robot_states_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _robot_states_type robot_states;

  // setters for named parameter idiom
  Type & set__robot_states(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->robot_states = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator> *;
  using ConstRawPtr =
    const zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zmr_interfaces__msg__CurrentFutureStates
    std::shared_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zmr_interfaces__msg__CurrentFutureStates
    std::shared_ptr<zmr_interfaces::msg::CurrentFutureStates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CurrentFutureStates_ & other) const
  {
    if (this->robot_states != other.robot_states) {
      return false;
    }
    return true;
  }
  bool operator!=(const CurrentFutureStates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CurrentFutureStates_

// alias to use template instance with default allocator
using CurrentFutureStates =
  zmr_interfaces::msg::CurrentFutureStates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace zmr_interfaces

#endif  // ZMR_INTERFACES__MSG__DETAIL__CURRENT_FUTURE_STATES__STRUCT_HPP_
