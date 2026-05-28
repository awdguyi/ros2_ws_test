// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/PolygonObject.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'polygon'
#include "geometry_msgs/msg/detail/polygon__struct.hpp"
// Member 'centroid'
#include "geometry_msgs/msg/detail/point32__struct.hpp"
// Member 'object_shape_t'
#include "map_interfaces/msg/detail/object_shape_type__struct.hpp"
// Member 'object_motion_t'
#include "map_interfaces/msg/detail/object_motion_type__struct.hpp"
// Member 'object_semantic_t'
#include "map_interfaces/msg/detail/object_semantic_type__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__PolygonObject __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__PolygonObject __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PolygonObject_
{
  using Type = PolygonObject_<ContainerAllocator>;

  explicit PolygonObject_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : polygon(_init),
    centroid(_init),
    object_shape_t(_init),
    object_motion_t(_init),
    object_semantic_t(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_id = 0;
      this->object_name = "";
    }
  }

  explicit PolygonObject_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object_name(_alloc),
    polygon(_alloc, _init),
    centroid(_alloc, _init),
    object_shape_t(_alloc, _init),
    object_motion_t(_alloc, _init),
    object_semantic_t(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_id = 0;
      this->object_name = "";
    }
  }

  // field types and members
  using _object_id_type =
    int16_t;
  _object_id_type object_id;
  using _object_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_name_type object_name;
  using _polygon_type =
    geometry_msgs::msg::Polygon_<ContainerAllocator>;
  _polygon_type polygon;
  using _centroid_type =
    geometry_msgs::msg::Point32_<ContainerAllocator>;
  _centroid_type centroid;
  using _object_shape_t_type =
    map_interfaces::msg::ObjectShapeType_<ContainerAllocator>;
  _object_shape_t_type object_shape_t;
  using _object_motion_t_type =
    map_interfaces::msg::ObjectMotionType_<ContainerAllocator>;
  _object_motion_t_type object_motion_t;
  using _object_semantic_t_type =
    map_interfaces::msg::ObjectSemanticType_<ContainerAllocator>;
  _object_semantic_t_type object_semantic_t;

  // setters for named parameter idiom
  Type & set__object_id(
    const int16_t & _arg)
  {
    this->object_id = _arg;
    return *this;
  }
  Type & set__object_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_name = _arg;
    return *this;
  }
  Type & set__polygon(
    const geometry_msgs::msg::Polygon_<ContainerAllocator> & _arg)
  {
    this->polygon = _arg;
    return *this;
  }
  Type & set__centroid(
    const geometry_msgs::msg::Point32_<ContainerAllocator> & _arg)
  {
    this->centroid = _arg;
    return *this;
  }
  Type & set__object_shape_t(
    const map_interfaces::msg::ObjectShapeType_<ContainerAllocator> & _arg)
  {
    this->object_shape_t = _arg;
    return *this;
  }
  Type & set__object_motion_t(
    const map_interfaces::msg::ObjectMotionType_<ContainerAllocator> & _arg)
  {
    this->object_motion_t = _arg;
    return *this;
  }
  Type & set__object_semantic_t(
    const map_interfaces::msg::ObjectSemanticType_<ContainerAllocator> & _arg)
  {
    this->object_semantic_t = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_interfaces::msg::PolygonObject_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::PolygonObject_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObject_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObject_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__PolygonObject
    std::shared_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__PolygonObject
    std::shared_ptr<map_interfaces::msg::PolygonObject_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolygonObject_ & other) const
  {
    if (this->object_id != other.object_id) {
      return false;
    }
    if (this->object_name != other.object_name) {
      return false;
    }
    if (this->polygon != other.polygon) {
      return false;
    }
    if (this->centroid != other.centroid) {
      return false;
    }
    if (this->object_shape_t != other.object_shape_t) {
      return false;
    }
    if (this->object_motion_t != other.object_motion_t) {
      return false;
    }
    if (this->object_semantic_t != other.object_semantic_t) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolygonObject_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolygonObject_

// alias to use template instance with default allocator
using PolygonObject =
  map_interfaces::msg::PolygonObject_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT__STRUCT_HPP_
