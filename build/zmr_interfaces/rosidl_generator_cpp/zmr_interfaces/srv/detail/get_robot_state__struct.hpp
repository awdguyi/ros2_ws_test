// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zmr_interfaces:srv/GetRobotState.idl
// generated code does not contain a copyright notice

#ifndef ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_HPP_
#define ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__zmr_interfaces__srv__GetRobotState_Request __attribute__((deprecated))
#else
# define DEPRECATED__zmr_interfaces__srv__GetRobotState_Request __declspec(deprecated)
#endif

namespace zmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRobotState_Request_
{
  using Type = GetRobotState_Request_<ContainerAllocator>;

  explicit GetRobotState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_id = 0ll;
    }
  }

  explicit GetRobotState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zmr_interfaces__srv__GetRobotState_Request
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zmr_interfaces__srv__GetRobotState_Request
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRobotState_Request_ & other) const
  {
    if (this->robot_id != other.robot_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRobotState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRobotState_Request_

// alias to use template instance with default allocator
using GetRobotState_Request =
  zmr_interfaces::srv::GetRobotState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace zmr_interfaces


#ifndef _WIN32
# define DEPRECATED__zmr_interfaces__srv__GetRobotState_Response __attribute__((deprecated))
#else
# define DEPRECATED__zmr_interfaces__srv__GetRobotState_Response __declspec(deprecated)
#endif

namespace zmr_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetRobotState_Response_
{
  using Type = GetRobotState_Response_<ContainerAllocator>;

  explicit GetRobotState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GetRobotState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _robot_state_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _robot_state_type robot_state;
  using _future_states_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _future_states_type future_states;

  // setters for named parameter idiom
  Type & set__robot_state(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->robot_state = _arg;
    return *this;
  }
  Type & set__future_states(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->future_states = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zmr_interfaces__srv__GetRobotState_Response
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zmr_interfaces__srv__GetRobotState_Response
    std::shared_ptr<zmr_interfaces::srv::GetRobotState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetRobotState_Response_ & other) const
  {
    if (this->robot_state != other.robot_state) {
      return false;
    }
    if (this->future_states != other.future_states) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetRobotState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetRobotState_Response_

// alias to use template instance with default allocator
using GetRobotState_Response =
  zmr_interfaces::srv::GetRobotState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace zmr_interfaces

namespace zmr_interfaces
{

namespace srv
{

struct GetRobotState
{
  using Request = zmr_interfaces::srv::GetRobotState_Request;
  using Response = zmr_interfaces::srv::GetRobotState_Response;
};

}  // namespace srv

}  // namespace zmr_interfaces

#endif  // ZMR_INTERFACES__SRV__DETAIL__GET_ROBOT_STATE__STRUCT_HPP_
