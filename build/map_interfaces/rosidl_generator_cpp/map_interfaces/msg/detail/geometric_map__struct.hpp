// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/GeometricMap.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__STRUCT_HPP_

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
// Member 'boundary'
#include "map_interfaces/msg/detail/polygon_object__struct.hpp"
// Member 'obstacle_list'
#include "map_interfaces/msg/detail/polygon_object_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__GeometricMap __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__GeometricMap __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GeometricMap_
{
  using Type = GeometricMap_<ContainerAllocator>;

  explicit GeometricMap_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    boundary(_init),
    obstacle_list(_init)
  {
    (void)_init;
  }

  explicit GeometricMap_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    boundary(_alloc, _init),
    obstacle_list(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _boundary_type =
    map_interfaces::msg::PolygonObject_<ContainerAllocator>;
  _boundary_type boundary;
  using _obstacle_list_type =
    map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>;
  _obstacle_list_type obstacle_list;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__boundary(
    const map_interfaces::msg::PolygonObject_<ContainerAllocator> & _arg)
  {
    this->boundary = _arg;
    return *this;
  }
  Type & set__obstacle_list(
    const map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> & _arg)
  {
    this->obstacle_list = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_interfaces::msg::GeometricMap_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::GeometricMap_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::GeometricMap_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::GeometricMap_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__GeometricMap
    std::shared_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__GeometricMap
    std::shared_ptr<map_interfaces::msg::GeometricMap_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GeometricMap_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->boundary != other.boundary) {
      return false;
    }
    if (this->obstacle_list != other.obstacle_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const GeometricMap_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GeometricMap_

// alias to use template instance with default allocator
using GeometricMap =
  map_interfaces::msg::GeometricMap_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__GEOMETRIC_MAP__STRUCT_HPP_
