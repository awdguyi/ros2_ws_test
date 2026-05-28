// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/ObjectSemanticType.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__ObjectSemanticType __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__ObjectSemanticType __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectSemanticType_
{
  using Type = ObjectSemanticType_<ContainerAllocator>;

  explicit ObjectSemanticType_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->o_semantic_type = 0;
    }
  }

  explicit ObjectSemanticType_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->o_semantic_type = 0;
    }
  }

  // field types and members
  using _o_semantic_type_type =
    int8_t;
  _o_semantic_type_type o_semantic_type;

  // setters for named parameter idiom
  Type & set__o_semantic_type(
    const int8_t & _arg)
  {
    this->o_semantic_type = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t UNKNOWN =
    0;
  static constexpr int8_t HUMAN =
    1;
  static constexpr int8_t FORKLIFT =
    2;
  static constexpr int8_t WALL =
    3;
  static constexpr int8_t CONTAINER =
    4;

  // pointer types
  using RawPtr =
    map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__ObjectSemanticType
    std::shared_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__ObjectSemanticType
    std::shared_ptr<map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectSemanticType_ & other) const
  {
    if (this->o_semantic_type != other.o_semantic_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectSemanticType_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectSemanticType_

// alias to use template instance with default allocator
using ObjectSemanticType =
  map_interfaces::msg::ObjectSemanticType_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectSemanticType_<ContainerAllocator>::UNKNOWN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectSemanticType_<ContainerAllocator>::HUMAN;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectSemanticType_<ContainerAllocator>::FORKLIFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectSemanticType_<ContainerAllocator>::WALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t ObjectSemanticType_<ContainerAllocator>::CONTAINER;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__OBJECT_SEMANTIC_TYPE__STRUCT_HPP_
