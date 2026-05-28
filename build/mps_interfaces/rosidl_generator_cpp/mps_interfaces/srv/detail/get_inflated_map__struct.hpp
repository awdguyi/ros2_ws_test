// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mps_interfaces:srv/GetInflatedMap.idl
// generated code does not contain a copyright notice

#ifndef MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__STRUCT_HPP_
#define MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mps_interfaces__srv__GetInflatedMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__srv__GetInflatedMap_Request __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetInflatedMap_Request_
{
  using Type = GetInflatedMap_Request_<ContainerAllocator>;

  explicit GetInflatedMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0ll;
    }
  }

  explicit GetInflatedMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0ll;
    }
  }

  // field types and members
  using _robot_id_type =
    int64_t;
  _robot_id_type robot_id;

  // setters for named parameter idiom
  Type & set__robot_id(
    const int64_t & _arg)
  {
    this->robot_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__srv__GetInflatedMap_Request
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__srv__GetInflatedMap_Request
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetInflatedMap_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetInflatedMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetInflatedMap_Request_

// alias to use template instance with default allocator
using GetInflatedMap_Request =
  mps_interfaces::srv::GetInflatedMap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mps_interfaces


// Include directives for member types
// Member 'inflated_map'
#include "map_interfaces/msg/detail/geometric_map__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__mps_interfaces__srv__GetInflatedMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__mps_interfaces__srv__GetInflatedMap_Response __declspec(deprecated)
#endif

namespace mps_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetInflatedMap_Response_
{
  using Type = GetInflatedMap_Response_<ContainerAllocator>;

  explicit GetInflatedMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : inflated_map(_init)
  {
    (void)_init;
  }

  explicit GetInflatedMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : inflated_map(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _inflated_map_type =
    map_interfaces::msg::GeometricMap_<ContainerAllocator>;
  _inflated_map_type inflated_map;

  // setters for named parameter idiom
  Type & set__inflated_map(
    const map_interfaces::msg::GeometricMap_<ContainerAllocator> & _arg)
  {
    this->inflated_map = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mps_interfaces__srv__GetInflatedMap_Response
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mps_interfaces__srv__GetInflatedMap_Response
    std::shared_ptr<mps_interfaces::srv::GetInflatedMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetInflatedMap_Response_ & other) const
  {
    if (this->inflated_map != other.inflated_map) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetInflatedMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetInflatedMap_Response_

// alias to use template instance with default allocator
using GetInflatedMap_Response =
  mps_interfaces::srv::GetInflatedMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mps_interfaces

namespace mps_interfaces
{

namespace srv
{

struct GetInflatedMap
{
  using Request = mps_interfaces::srv::GetInflatedMap_Request;
  using Response = mps_interfaces::srv::GetInflatedMap_Response;
};

}  // namespace srv

}  // namespace mps_interfaces

#endif  // MPS_INTERFACES__SRV__DETAIL__GET_INFLATED_MAP__STRUCT_HPP_
