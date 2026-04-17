# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gripper_interfaces:msg/GripperMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GripperMsg(type):
    """Metaclass of message 'GripperMsg'."""

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
            module = import_type_support('gripper_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gripper_interfaces.msg.GripperMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__gripper_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__gripper_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__gripper_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__gripper_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__gripper_msg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperMsg(metaclass=Metaclass_GripperMsg):
    """Message class 'GripperMsg'."""

    __slots__ = [
        '_angle',
        '_current',
        '_velocity',
        '_grp_pos',
        '_is_motor_enable',
        '_is_grp_init_ongoing',
        '_is_pos_ongoing',
        '_is_vel_ongoing',
        '_is_tor_ongoing',
        '_is_grp_opening',
        '_is_grp_closing',
        '_grp_direction',
        '_is_object_grasp',
        '_is_fault_occured',
    ]

    _fields_and_field_types = {
        'angle': 'int16',
        'current': 'int16',
        'velocity': 'int16',
        'grp_pos': 'int16',
        'is_motor_enable': 'boolean',
        'is_grp_init_ongoing': 'boolean',
        'is_pos_ongoing': 'boolean',
        'is_vel_ongoing': 'boolean',
        'is_tor_ongoing': 'boolean',
        'is_grp_opening': 'boolean',
        'is_grp_closing': 'boolean',
        'grp_direction': 'boolean',
        'is_object_grasp': 'boolean',
        'is_fault_occured': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.angle = kwargs.get('angle', int())
        self.current = kwargs.get('current', int())
        self.velocity = kwargs.get('velocity', int())
        self.grp_pos = kwargs.get('grp_pos', int())
        self.is_motor_enable = kwargs.get('is_motor_enable', bool())
        self.is_grp_init_ongoing = kwargs.get('is_grp_init_ongoing', bool())
        self.is_pos_ongoing = kwargs.get('is_pos_ongoing', bool())
        self.is_vel_ongoing = kwargs.get('is_vel_ongoing', bool())
        self.is_tor_ongoing = kwargs.get('is_tor_ongoing', bool())
        self.is_grp_opening = kwargs.get('is_grp_opening', bool())
        self.is_grp_closing = kwargs.get('is_grp_closing', bool())
        self.grp_direction = kwargs.get('grp_direction', bool())
        self.is_object_grasp = kwargs.get('is_object_grasp', bool())
        self.is_fault_occured = kwargs.get('is_fault_occured', bool())

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
        if self.angle != other.angle:
            return False
        if self.current != other.current:
            return False
        if self.velocity != other.velocity:
            return False
        if self.grp_pos != other.grp_pos:
            return False
        if self.is_motor_enable != other.is_motor_enable:
            return False
        if self.is_grp_init_ongoing != other.is_grp_init_ongoing:
            return False
        if self.is_pos_ongoing != other.is_pos_ongoing:
            return False
        if self.is_vel_ongoing != other.is_vel_ongoing:
            return False
        if self.is_tor_ongoing != other.is_tor_ongoing:
            return False
        if self.is_grp_opening != other.is_grp_opening:
            return False
        if self.is_grp_closing != other.is_grp_closing:
            return False
        if self.grp_direction != other.grp_direction:
            return False
        if self.is_object_grasp != other.is_object_grasp:
            return False
        if self.is_fault_occured != other.is_fault_occured:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'angle' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'angle' field must be an integer in [-32768, 32767]"
        self._angle = value

    @builtins.property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'current' field must be an integer in [-32768, 32767]"
        self._current = value

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'velocity' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'velocity' field must be an integer in [-32768, 32767]"
        self._velocity = value

    @builtins.property
    def grp_pos(self):
        """Message field 'grp_pos'."""
        return self._grp_pos

    @grp_pos.setter
    def grp_pos(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'grp_pos' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'grp_pos' field must be an integer in [-32768, 32767]"
        self._grp_pos = value

    @builtins.property
    def is_motor_enable(self):
        """Message field 'is_motor_enable'."""
        return self._is_motor_enable

    @is_motor_enable.setter
    def is_motor_enable(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_motor_enable' field must be of type 'bool'"
        self._is_motor_enable = value

    @builtins.property
    def is_grp_init_ongoing(self):
        """Message field 'is_grp_init_ongoing'."""
        return self._is_grp_init_ongoing

    @is_grp_init_ongoing.setter
    def is_grp_init_ongoing(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_grp_init_ongoing' field must be of type 'bool'"
        self._is_grp_init_ongoing = value

    @builtins.property
    def is_pos_ongoing(self):
        """Message field 'is_pos_ongoing'."""
        return self._is_pos_ongoing

    @is_pos_ongoing.setter
    def is_pos_ongoing(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_pos_ongoing' field must be of type 'bool'"
        self._is_pos_ongoing = value

    @builtins.property
    def is_vel_ongoing(self):
        """Message field 'is_vel_ongoing'."""
        return self._is_vel_ongoing

    @is_vel_ongoing.setter
    def is_vel_ongoing(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_vel_ongoing' field must be of type 'bool'"
        self._is_vel_ongoing = value

    @builtins.property
    def is_tor_ongoing(self):
        """Message field 'is_tor_ongoing'."""
        return self._is_tor_ongoing

    @is_tor_ongoing.setter
    def is_tor_ongoing(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_tor_ongoing' field must be of type 'bool'"
        self._is_tor_ongoing = value

    @builtins.property
    def is_grp_opening(self):
        """Message field 'is_grp_opening'."""
        return self._is_grp_opening

    @is_grp_opening.setter
    def is_grp_opening(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_grp_opening' field must be of type 'bool'"
        self._is_grp_opening = value

    @builtins.property
    def is_grp_closing(self):
        """Message field 'is_grp_closing'."""
        return self._is_grp_closing

    @is_grp_closing.setter
    def is_grp_closing(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_grp_closing' field must be of type 'bool'"
        self._is_grp_closing = value

    @builtins.property
    def grp_direction(self):
        """Message field 'grp_direction'."""
        return self._grp_direction

    @grp_direction.setter
    def grp_direction(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'grp_direction' field must be of type 'bool'"
        self._grp_direction = value

    @builtins.property
    def is_object_grasp(self):
        """Message field 'is_object_grasp'."""
        return self._is_object_grasp

    @is_object_grasp.setter
    def is_object_grasp(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_object_grasp' field must be of type 'bool'"
        self._is_object_grasp = value

    @builtins.property
    def is_fault_occured(self):
        """Message field 'is_fault_occured'."""
        return self._is_fault_occured

    @is_fault_occured.setter
    def is_fault_occured(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_fault_occured' field must be of type 'bool'"
        self._is_fault_occured = value
