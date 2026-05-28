// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zmr_interfaces:srv/GetOtherRobotStates.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__SRV__DETAIL__GET_OTHER_ROBOT_STATES__STRUCT_HPP_
#define ZMR_INTERFACES__SRV__DETAIL__GET_OTHER_ROBOT_STATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Request __attribute__((deprecated))
#else
# define DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Request __declspec(deprecated)
#endif

namespace zmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetOtherRobotStates_Request_
{
  using Type = GetOtherRobotStates_Request_<ContainerAllocator>;

  explicit GetOtherRobotStates_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ego_robot_id = 0ll;
    }
  }

  explicit GetOtherRobotStates_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ego_robot_id = 0ll;
    }
  }

  // field types and members
  using _ego_robot_id_type =
    int64_t;
  _ego_robot_id_type ego_robot_id;

  // setters for named parameter idiom
  Type & set__ego_robot_id(
    const int64_t & _arg)
  {
    this->ego_robot_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Request
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Request
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetOtherRobotStates_Request_ & other) const
  {
    if (this->ego_robot_id != other.ego_robot_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetOtherRobotStates_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetOtherRobotStates_Request_

// alias to use template instance with default allocator
using GetOtherRobotStates_Request =
  zmr_interfaces::srv::GetOtherRobotStates_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace zmr_interfaces


#ifndef _WIN32
# define DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Response __attribute__((deprecated))
#else
# define DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Response __declspec(deprecated)
#endif

namespace zmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetOtherRobotStates_Response_
{
  using Type = GetOtherRobotStates_Response_<ContainerAllocator>;

  explicit GetOtherRobotStates_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetOtherRobotStates_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _other_robot_states_in_order_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _other_robot_states_in_order_type other_robot_states_in_order;

  // setters for named parameter idiom
  Type & set__other_robot_states_in_order(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->other_robot_states_in_order = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Response
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zmr_interfaces__srv__GetOtherRobotStates_Response
    std::shared_ptr<zmr_interfaces::srv::GetOtherRobotStates_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetOtherRobotStates_Response_ & other) const
  {
    if (this->other_robot_states_in_order != other.other_robot_states_in_order) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetOtherRobotStates_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetOtherRobotStates_Response_

// alias to use template instance with default allocator
using GetOtherRobotStates_Response =
  zmr_interfaces::srv::GetOtherRobotStates_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace zmr_interfaces

namespace zmr_interfaces
{

namespace srv
{

struct GetOtherRobotStates
{
  using Request = zmr_interfaces::srv::GetOtherRobotStates_Request;
  using Response = zmr_interfaces::srv::GetOtherRobotStates_Response;
};

}  // namespace srv

}  // namespace zmr_interfaces

#endif  // ZMR_INTERFACES__SRV__DETAIL__GET_OTHER_ROBOT_STATES__STRUCT_HPP_
