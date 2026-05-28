// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/PolygonObjectArrayStamped.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__STRUCT_HPP_

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
// Member 'polygon_objects'
#include "map_interfaces/msg/detail/polygon_object_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__PolygonObjectArrayStamped __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__PolygonObjectArrayStamped __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PolygonObjectArrayStamped_
{
  using Type = PolygonObjectArrayStamped_<ContainerAllocator>;

  explicit PolygonObjectArrayStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    polygon_objects(_init)
  {
    (void)_init;
  }

  explicit PolygonObjectArrayStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    polygon_objects(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _polygon_objects_type =
    map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>;
  _polygon_objects_type polygon_objects;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__polygon_objects(
    const map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> & _arg)
  {
    this->polygon_objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__PolygonObjectArrayStamped
    std::shared_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__PolygonObjectArrayStamped
    std::shared_ptr<map_interfaces::msg::PolygonObjectArrayStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolygonObjectArrayStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->polygon_objects != other.polygon_objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolygonObjectArrayStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolygonObjectArrayStamped_

// alias to use template instance with default allocator
using PolygonObjectArrayStamped =
  map_interfaces::msg::PolygonObjectArrayStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY_STAMPED__STRUCT_HPP_
