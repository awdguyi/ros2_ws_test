// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mps_interfaces:msg/Schedule.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__MSG__DETAIL__SCHEDULE__STRUCT_HPP_
#define MPS_INTERFACES__MSG__DETAIL__SCHEDULE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mps_interfaces__msg__Schedule __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__msg__Schedule __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Schedule_
{
  using Type = Schedule_<ContainerAllocator>;

  explicit Schedule_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->schedule_name = "";
      this->robot_id = 0;
    }
  }

  explicit Schedule_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : schedule_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->schedule_name = "";
      this->robot_id = 0;
    }
  }

  // field types and members
  using _schedule_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _schedule_name_type schedule_name;
  using _robot_id_type =
    int16_t;
  _robot_id_type robot_id;
  using _node_ids_type =
    std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>>;
  _node_ids_type node_ids;
  using _node_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _node_names_type node_names;
  using _etas_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _etas_type etas;

  // setters for named parameter idiom
  Type & set__schedule_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->schedule_name = _arg;
    return *this;
  }
  Type & set__robot_id(
    const int16_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }
  Type & set__node_ids(
    const std::vector<int16_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int16_t>> & _arg)
  {
    this->node_ids = _arg;
    return *this;
  }
  Type & set__node_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->node_names = _arg;
    return *this;
  }
  Type & set__etas(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->etas = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::msg::Schedule_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::msg::Schedule_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::Schedule_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::msg::Schedule_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__msg__Schedule
    std::shared_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__msg__Schedule
    std::shared_ptr<mps_interfaces::msg::Schedule_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Schedule_ & other) const
  {
    if (this->schedule_name != other.schedule_name) {
      return false;
    }
    if (this->robot_id != other.robot_id) {
      return false;
    }
    if (this->node_ids != other.node_ids) {
      return false;
    }
    if (this->node_names != other.node_names) {
      return false;
    }
    if (this->etas != other.etas) {
      return false;
    }
    return true;
  }
  bool operator!=(const Schedule_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Schedule_

// alias to use template instance with default allocator
using Schedule =
  mps_interfaces::msg::Schedule_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__MSG__DETAIL__SCHEDULE__STRUCT_HPP_
