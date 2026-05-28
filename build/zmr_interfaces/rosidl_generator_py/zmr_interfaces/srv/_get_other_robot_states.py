# generated from rosidl_generator_py/resource/_idl.py.em
# with input from zmr_interfaces:srv/GetOtherRobotStates.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetOtherRobotStates_Request(type):
    """Metaclass of message 'GetOtherRobotStates_Request'."""

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
            module = import_type_support('zmr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zmr_interfaces.srv.GetOtherRobotStates_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_other_robot_states__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_other_robot_states__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_other_robot_states__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_other_robot_states__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_other_robot_states__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetOtherRobotStates_Request(metaclass=Metaclass_GetOtherRobotStates_Request):
    """Message class 'GetOtherRobotStates_Request'."""

    __slots__ = [
        '_ego_robot_id',
    ]

    _fields_and_field_types = {
        'ego_robot_id': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ego_robot_id = kwargs.get('ego_robot_id', int())

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
        if self.ego_robot_id != other.ego_robot_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ego_robot_id(self):
        """Message field 'ego_robot_id'."""
        return self._ego_robot_id

    @ego_robot_id.setter
    def ego_robot_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ego_robot_id' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'ego_robot_id' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._ego_robot_id = value


# Import statements for member types

# Member 'other_robot_states_in_order'
import array  # noqa: E402, I100

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_GetOtherRobotStates_Response(type):
    """Metaclass of message 'GetOtherRobotStates_Response'."""

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
            module = import_type_support('zmr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zmr_interfaces.srv.GetOtherRobotStates_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_other_robot_states__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_other_robot_states__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_other_robot_states__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_other_robot_states__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_other_robot_states__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetOtherRobotStates_Response(metaclass=Metaclass_GetOtherRobotStates_Response):
    """Message class 'GetOtherRobotStates_Response'."""

    __slots__ = [
        '_other_robot_states_in_order',
    ]

    _fields_and_field_types = {
        'other_robot_states_in_order': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.other_robot_states_in_order = array.array('d', kwargs.get('other_robot_states_in_order', []))

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
        if self.other_robot_states_in_order != other.other_robot_states_in_order:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def other_robot_states_in_order(self):
        """Message field 'other_robot_states_in_order'."""
        return self._other_robot_states_in_order

    @other_robot_states_in_order.setter
    def other_robot_states_in_order(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'other_robot_states_in_order' array.array() must have the type code of 'd'"
            self._other_robot_states_in_order = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'other_robot_states_in_order' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._other_robot_states_in_order = array.array('d', value)


class Metaclass_GetOtherRobotStates(type):
    """Metaclass of service 'GetOtherRobotStates'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('zmr_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'zmr_interfaces.srv.GetOtherRobotStates')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_other_robot_states

            from zmr_interfaces.srv import _get_other_robot_states
            if _get_other_robot_states.Metaclass_GetOtherRobotStates_Request._TYPE_SUPPORT is None:
                _get_other_robot_states.Metaclass_GetOtherRobotStates_Request.__import_type_support__()
            if _get_other_robot_states.Metaclass_GetOtherRobotStates_Response._TYPE_SUPPORT is None:
                _get_other_robot_states.Metaclass_GetOtherRobotStates_Response.__import_type_support__()


class GetOtherRobotStates(metaclass=Metaclass_GetOtherRobotStates):
    from zmr_interfaces.srv._get_other_robot_states import GetOtherRobotStates_Request as Request
    from zmr_interfaces.srv._get_other_robot_states import GetOtherRobotStates_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
