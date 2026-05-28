// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/ObjectMotionType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__ObjectMotionType __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__ObjectMotionType __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectMotionType_
{
  using Type = ObjectMotionType_<ContainerAllocator>;

  explicit ObjectMotionType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->o_motion_type = 0;
    }
  }

  explicit ObjectMotionType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->o_motion_type = 0;
    }
  }

  // field types and members
  using _o_motion_type_type =
    int8_t;
  _o_motion_type_type o_motion_type;

  // setters for named parameter idiom
  Type & set__o_motion_type(
    const int8_t & _arg)
  {
    this->o_motion_type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t UNKNOWN =
    0;
  static constexpr int8_t STATIC =
    1;
  static constexpr int8_t DYNAMIC =
    2;

  // pointer types
  using RawPtr =
    map_interfaces::msg::ObjectMotionType_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::ObjectMotionType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::ObjectMotionType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::ObjectMotionType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__ObjectMotionType
    std::shared_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__ObjectMotionType
    std::shared_ptr<map_interfaces::msg::ObjectMotionType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectMotionType_ & other) const
  {
    if (this->o_motion_type != other.o_motion_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectMotionType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectMotionType_

// alias to use template instance with default allocator
using ObjectMotionType =
  map_interfaces::msg::ObjectMotionType_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectMotionType_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectMotionType_<ContainerAllocator>::STATIC;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectMotionType_<ContainerAllocator>::DYNAMIC;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_MOTION_TYPE__STRUCT_HPP_
