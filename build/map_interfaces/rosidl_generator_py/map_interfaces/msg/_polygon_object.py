# generated from rosidl_generator_py/resource/_idl.py.em
# with input from map_interfaces:msg/PolygonObject.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PolygonObject(type):
    """Metaclass of message 'PolygonObject'."""

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
            module = import_type_support('map_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'map_interfaces.msg.PolygonObject')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__polygon_object
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__polygon_object
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__polygon_object
            cls._TYPE_SUPPORT = module.type_support_msg__msg__polygon_object
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__polygon_object

            from geometry_msgs.msg import Point32
            if Point32.__class__._TYPE_SUPPORT is None:
                Point32.__class__.__import_type_support__()

            from geometry_msgs.msg import Polygon
            if Polygon.__class__._TYPE_SUPPORT is None:
                Polygon.__class__.__import_type_support__()

            from map_interfaces.msg import ObjectMotionType
            if ObjectMotionType.__class__._TYPE_SUPPORT is None:
                ObjectMotionType.__class__.__import_type_support__()

            from map_interfaces.msg import ObjectSemanticType
            if ObjectSemanticType.__class__._TYPE_SUPPORT is None:
                ObjectSemanticType.__class__.__import_type_support__()

            from map_interfaces.msg import ObjectShapeType
            if ObjectShapeType.__class__._TYPE_SUPPORT is None:
                ObjectShapeType.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PolygonObject(metaclass=Metaclass_PolygonObject):
    """Message class 'PolygonObject'."""

    __slots__ = [
        '_object_id',
        '_object_name',
        '_polygon',
        '_centroid',
        '_object_shape_t',
        '_object_motion_t',
        '_object_semantic_t',
    ]

    _fields_and_field_types = {
        'object_id': 'int16',
        'object_name': 'string',
        'polygon': 'geometry_msgs/Polygon',
        'centroid': 'geometry_msgs/Point32',
        'object_shape_t': 'map_interfaces/ObjectShapeType',
        'object_motion_t': 'map_interfaces/ObjectMotionType',
        'object_semantic_t': 'map_interfaces/ObjectSemanticType',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Polygon'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['map_interfaces', 'msg'], 'ObjectShapeType'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['map_interfaces', 'msg'], 'ObjectMotionType'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['map_interfaces', 'msg'], 'ObjectSemanticType'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.object_id = kwargs.get('object_id', int())
        self.object_name = kwargs.get('object_name', str())
        from geometry_msgs.msg import Polygon
        self.polygon = kwargs.get('polygon', Polygon())
        from geometry_msgs.msg import Point32
        self.centroid = kwargs.get('centroid', Point32())
        from map_interfaces.msg import ObjectShapeType
        self.object_shape_t = kwargs.get('object_shape_t', ObjectShapeType())
        from map_interfaces.msg import ObjectMotionType
        self.object_motion_t = kwargs.get('object_motion_t', ObjectMotionType())
        from map_interfaces.msg import ObjectSemanticType
        self.object_semantic_t = kwargs.get('object_semantic_t', ObjectSemanticType())

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
        if self.object_id != other.object_id:
            return False
        if self.object_name != other.object_name:
            return False
        if self.polygon != other.polygon:
            return False
        if self.centroid != other.centroid:
            return False
        if self.object_shape_t != other.object_shape_t:
            return False
        if self.object_motion_t != other.object_motion_t:
            return False
        if self.object_semantic_t != other.object_semantic_t:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def object_id(self):
        """Message field 'object_id'."""
        return self._object_id

    @object_id.setter
    def object_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'object_id' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'object_id' field must be an integer in [-32768, 32767]"
        self._object_id = value

    @builtins.property
    def object_name(self):
        """Message field 'object_name'."""
        return self._object_name

    @object_name.setter
    def object_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'object_name' field must be of type 'str'"
        self._object_name = value

    @builtins.property
    def polygon(self):
        """Message field 'polygon'."""
        return self._polygon

    @polygon.setter
    def polygon(self, value):
        if __debug__:
            from geometry_msgs.msg import Polygon
            assert \
                isinstance(value, Polygon), \
                "The 'polygon' field must be a sub message of type 'Polygon'"
        self._polygon = value

    @builtins.property
    def centroid(self):
        """Message field 'centroid'."""
        return self._centroid

    @centroid.setter
    def centroid(self, value):
        if __debug__:
            from geometry_msgs.msg import Point32
            assert \
                isinstance(value, Point32), \
                "The 'centroid' field must be a sub message of type 'Point32'"
        self._centroid = value

    @builtins.property
    def object_shape_t(self):
        """Message field 'object_shape_t'."""
        return self._object_shape_t

    @object_shape_t.setter
    def object_shape_t(self, value):
        if __debug__:
            from map_interfaces.msg import ObjectShapeType
            assert \
                isinstance(value, ObjectShapeType), \
                "The 'object_shape_t' field must be a sub message of type 'ObjectShapeType'"
        self._object_shape_t = value

    @builtins.property
    def object_motion_t(self):
        """Message field 'object_motion_t'."""
        return self._object_motion_t

    @object_motion_t.setter
    def object_motion_t(self, value):
        if __debug__:
            from map_interfaces.msg import ObjectMotionType
            assert \
                isinstance(value, ObjectMotionType), \
                "The 'object_motion_t' field must be a sub message of type 'ObjectMotionType'"
        self._object_motion_t = value

    @builtins.property
    def object_semantic_t(self):
        """Message field 'object_semantic_t'."""
        return self._object_semantic_t

    @object_semantic_t.setter
    def object_semantic_t(self, value):
        if __debug__:
            from map_interfaces.msg import ObjectSemanticType
            assert \
                isinstance(value, ObjectSemanticType), \
                "The 'object_semantic_t' field must be a sub message of type 'ObjectSemanticType'"
        self._object_semantic_t = value
