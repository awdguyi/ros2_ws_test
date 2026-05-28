# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mps_interfaces:srv/GetRobotSchedule.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetRobotSchedule_Request(type):
    """Metaclass of message 'GetRobotSchedule_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mps_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mps_interfaces.srv.GetRobotSchedule_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_robot_schedule__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_robot_schedule__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_robot_schedule__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_robot_schedule__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_robot_schedule__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetRobotSchedule_Request(metaclass=Metaclass_GetRobotSchedule_Request):
    """Message class 'GetRobotSchedule_Request'."""

    __slots__ = [
        '_robot_id',
        '_current_time',
    ]

    _fields_and_field_types = {
        'robot_id': 'int64',
        'current_time': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_id = kwargs.get('robot_id', int())
        self.current_time = kwargs.get('current_time', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.robot_id != other.robot_id:
            return False
        if self.current_time != other.current_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_id(self):
        """Message field 'robot_id'."""
        return self._robot_id

    @robot_id.setter
    def robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'robot_id' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'robot_id' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._robot_id = value

    @builtins.property
    def current_time(self):
        """Message field 'current_time'."""
        return self._current_time

    @current_time.setter
    def current_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'current_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._current_time = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetRobotSchedule_Response(type):
    """Metaclass of message 'GetRobotSchedule_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mps_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mps_interfaces.srv.GetRobotSchedule_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_robot_schedule__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_robot_schedule__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_robot_schedule__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_robot_schedule__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_robot_schedule__response

            from mps_interfaces.msg import PathScheduleStamped
            if PathScheduleStamped.__class__._TYPE_SUPPORT is None:
                PathScheduleStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetRobotSchedule_Response(metaclass=Metaclass_GetRobotSchedule_Response):
    """Message class 'GetRobotSchedule_Response'."""

    __slots__ = [
        '_path_schedule',
    ]

    _fields_and_field_types = {
        'path_schedule': 'mps_interfaces/PathScheduleStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['mps_interfaces', 'msg'], 'PathScheduleStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from mps_interfaces.msg import PathScheduleStamped
        self.path_schedule = kwargs.get('path_schedule', PathScheduleStamped())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.path_schedule != other.path_schedule:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def path_schedule(self):
        """Message field 'path_schedule'."""
        return self._path_schedule

    @path_schedule.setter
    def path_schedule(self, value):
        if __debug__:
            from mps_interfaces.msg import PathScheduleStamped
            assert \
                isinstance(value, PathScheduleStamped), \
                "The 'path_schedule' field must be a sub message of type 'PathScheduleStamped'"
        self._path_schedule = value


class Metaclass_GetRobotSchedule(type):
    """Metaclass of service 'GetRobotSchedule'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mps_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mps_interfaces.srv.GetRobotSchedule')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_robot_schedule

            from mps_interfaces.srv import _get_robot_schedule
            if _get_robot_schedule.Metaclass_GetRobotSchedule_Request._TYPE_SUPPORT is None:
                _get_robot_schedule.Metaclass_GetRobotSchedule_Request.__import_type_support__()
            if _get_robot_schedule.Metaclass_GetRobotSchedule_Response._TYPE_SUPPORT is None:
                _get_robot_schedule.Metaclass_GetRobotSchedule_Response.__import_type_support__()


class GetRobotSchedule(metaclass=Metaclass_GetRobotSchedule):
    from mps_interfaces.srv._get_robot_schedule import GetRobotSchedule_Request as Request
    from mps_interfaces.srv._get_robot_schedule import GetRobotSchedule_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
