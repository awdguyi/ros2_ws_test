# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mps_interfaces:msg/Schedule.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'node_ids'
# Member 'etas'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Schedule(type):
    """Metaclass of message 'Schedule'."""

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
                'mps_interfaces.msg.Schedule')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__schedule
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__schedule
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__schedule
            cls._TYPE_SUPPORT = module.type_support_msg__msg__schedule
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__schedule

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Schedule(metaclass=Metaclass_Schedule):
    """Message class 'Schedule'."""

    __slots__ = [
        '_schedule_name',
        '_robot_id',
        '_node_ids',
        '_node_names',
        '_etas',
    ]

    _fields_and_field_types = {
        'schedule_name': 'string',
        'robot_id': 'int16',
        'node_ids': 'sequence<int16>',
        'node_names': 'sequence<string>',
        'etas': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int16')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.schedule_name = kwargs.get('schedule_name', str())
        self.robot_id = kwargs.get('robot_id', int())
        self.node_ids = array.array('h', kwargs.get('node_ids', []))
        self.node_names = kwargs.get('node_names', [])
        self.etas = array.array('f', kwargs.get('etas', []))

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
        if self.schedule_name != other.schedule_name:
            return False
        if self.robot_id != other.robot_id:
            return False
        if self.node_ids != other.node_ids:
            return False
        if self.node_names != other.node_names:
            return False
        if self.etas != other.etas:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def schedule_name(self):
        """Message field 'schedule_name'."""
        return self._schedule_name

    @schedule_name.setter
    def schedule_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'schedule_name' field must be of type 'str'"
        self._schedule_name = value

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
            assert value >= -32768 and value < 32768, \
                "The 'robot_id' field must be an integer in [-32768, 32767]"
        self._robot_id = value

    @builtins.property
    def node_ids(self):
        """Message field 'node_ids'."""
        return self._node_ids

    @node_ids.setter
    def node_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'h', \
                "The 'node_ids' array.array() must have the type code of 'h'"
            self._node_ids = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -32768 and val < 32768 for val in value)), \
                "The 'node_ids' field must be a set or sequence and each value of type 'int' and each integer in [-32768, 32767]"
        self._node_ids = array.array('h', value)

    @builtins.property
    def node_names(self):
        """Message field 'node_names'."""
        return self._node_names

    @node_names.setter
    def node_names(self, value):
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'node_names' field must be a set or sequence and each value of type 'str'"
        self._node_names = value

    @builtins.property
    def etas(self):
        """Message field 'etas'."""
        return self._etas

    @etas.setter
    def etas(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'etas' array.array() must have the type code of 'f'"
            self._etas = value
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
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'etas' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._etas = array.array('f', value)
