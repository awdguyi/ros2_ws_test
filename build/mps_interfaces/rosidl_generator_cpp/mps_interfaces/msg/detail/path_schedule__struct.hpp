// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mps_interfaces:msg/PathSchedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__STRUCT_HPP_
#define MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'path_coords'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mps_interfaces__msg__PathSchedule __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__msg__PathSchedule __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PathSchedule_
{
  using Type = PathSchedule_<ContainerAllocator>;

  explicit PathSchedule_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
    }
  }

  explicit PathSchedule_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0;
    }
  }

  // field types and members
  using _robot_id_type =
    int16_t;
  _robot_id_type robot_id;
  using _path_coords_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _path_coords_type path_coords;
  using _path_times_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _path_times_type path_times;

  // setters for named parameter idiom
  Type & set__robot_id(
    const int16_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__path_coords(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->path_coords = _arg;
    return *this;
  }
  Type & set__path_times(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->path_times = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::msg::PathSchedule_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::msg::PathSchedule_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::PathSchedule_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::PathSchedule_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__msg__PathSchedule
    std::shared_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__msg__PathSchedule
    std::shared_ptr<mps_interfaces::msg::PathSchedule_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PathSchedule_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->path_coords != other.path_coords) {
      return false;
    }
    if (this->path_times != other.path_times) {
      return false;
    }
    return true;
  }
  bool operator!=(const PathSchedule_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PathSchedule_

// alias to use template instance with default allocator
using PathSchedule =
  mps_interfaces::msg::PathSchedule_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__PATH_SCHEDULE__STRUCT_HPP_
