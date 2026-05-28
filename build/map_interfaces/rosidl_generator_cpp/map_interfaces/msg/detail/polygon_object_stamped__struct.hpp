// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/PolygonObjectStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__STRUCT_HPP_

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
// Member 'polygon_object'
#include "map_interfaces/msg/detail/polygon_object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__PolygonObjectStamped __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__PolygonObjectStamped __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PolygonObjectStamped_
{
  using Type = PolygonObjectStamped_<ContainerAllocator>;

  explicit PolygonObjectStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    polygon_object(_init)
  {
    (void)_init;
  }

  explicit PolygonObjectStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    polygon_object(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _polygon_object_type =
    map_interfaces::msg::PolygonObject_<ContainerAllocator>;
  _polygon_object_type polygon_object;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__polygon_object(
    const map_interfaces::msg::PolygonObject_<ContainerAllocator> & _arg)
  {
    this->polygon_object = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__PolygonObjectStamped
    std::shared_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__PolygonObjectStamped
    std::shared_ptr<map_interfaces::msg::PolygonObjectStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolygonObjectStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->polygon_object != other.polygon_object) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolygonObjectStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolygonObjectStamped_

// alias to use template instance with default allocator
using PolygonObjectStamped =
  map_interfaces::msg::PolygonObjectStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_STAMPED__STRUCT_HPP_
