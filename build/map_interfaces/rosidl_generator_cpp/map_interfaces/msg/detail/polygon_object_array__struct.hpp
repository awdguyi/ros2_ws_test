// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from map_interfaces:msg/PolygonObjectArray.idl
// generated code does not contain a copyright notice

#ifndef MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__STRUCT_HPP_
#define MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'polygon_objects'
#include "map_interfaces/msg/detail/polygon_object__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__map_interfaces__msg__PolygonObjectArray __attribute__((deprecated))
#else
# define DEPRECATED__map_interfaces__msg__PolygonObjectArray __declspec(deprecated)
#endif

namespace map_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PolygonObjectArray_
{
  using Type = PolygonObjectArray_<ContainerAllocator>;

  explicit PolygonObjectArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit PolygonObjectArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _polygon_objects_type =
    std::vector<map_interfaces::msg::PolygonObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<map_interfaces::msg::PolygonObject_<ContainerAllocator>>>;
  _polygon_objects_type polygon_objects;

  // setters for named parameter idiom
  Type & set__polygon_objects(
    const std::vector<map_interfaces::msg::PolygonObject_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<map_interfaces::msg::PolygonObject_<ContainerAllocator>>> & _arg)
  {
    this->polygon_objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__map_interfaces__msg__PolygonObjectArray
    std::shared_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__map_interfaces__msg__PolygonObjectArray
    std::shared_ptr<map_interfaces::msg::PolygonObjectArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PolygonObjectArray_ & other) const
  {
    if (this->polygon_objects != other.polygon_objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const PolygonObjectArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PolygonObjectArray_

// alias to use template instance with default allocator
using PolygonObjectArray =
  map_interfaces::msg::PolygonObjectArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace map_interfaces

#endif  // MAP_INTERFACES__MSG__DETAIL__POLYGON_OBJECT_ARRAY__STRUCT_HPP_
