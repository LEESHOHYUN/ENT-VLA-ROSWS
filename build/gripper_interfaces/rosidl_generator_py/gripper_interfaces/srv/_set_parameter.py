# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gripper_interfaces:srv/SetParameter.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetParameter_Request(type):
    """Metaclass of message 'SetParameter_Request'."""

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
                'gripper_interfaces.srv.SetParameter_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_parameter__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_parameter__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_parameter__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_parameter__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_parameter__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetParameter_Request(metaclass=Metaclass_SetParameter_Request):
    """Message class 'SetParameter_Request'."""

    __slots__ = [
        '_vel_max',
        '_acc_max',
    ]

    _fields_and_field_types = {
        'vel_max': 'uint16',
        'acc_max': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vel_max = kwargs.get('vel_max', int())
        self.acc_max = kwargs.get('acc_max', int())

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
        if self.vel_max != other.vel_max:
            return False
        if self.acc_max != other.acc_max:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def vel_max(self):
        """Message field 'vel_max'."""
        return self._vel_max

    @vel_max.setter
    def vel_max(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_max' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'vel_max' field must be an unsigned integer in [0, 65535]"
        self._vel_max = value

    @builtins.property
    def acc_max(self):
        """Message field 'acc_max'."""
        return self._acc_max

    @acc_max.setter
    def acc_max(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_max' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'acc_max' field must be an unsigned integer in [0, 65535]"
        self._acc_max = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetParameter_Response(type):
    """Metaclass of message 'SetParameter_Response'."""

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
                'gripper_interfaces.srv.SetParameter_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_parameter__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_parameter__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_parameter__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_parameter__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_parameter__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetParameter_Response(metaclass=Metaclass_SetParameter_Response):
    """Message class 'SetParameter_Response'."""

    __slots__ = [
        '_successed',
    ]

    _fields_and_field_types = {
        'successed': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.successed = kwargs.get('successed', bool())

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
        if self.successed != other.successed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def successed(self):
        """Message field 'successed'."""
        return self._successed

    @successed.setter
    def successed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'successed' field must be of type 'bool'"
        self._successed = value


class Metaclass_SetParameter(type):
    """Metaclass of service 'SetParameter'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('gripper_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gripper_interfaces.srv.SetParameter')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_parameter

            from gripper_interfaces.srv import _set_parameter
            if _set_parameter.Metaclass_SetParameter_Request._TYPE_SUPPORT is None:
                _set_parameter.Metaclass_SetParameter_Request.__import_type_support__()
            if _set_parameter.Metaclass_SetParameter_Response._TYPE_SUPPORT is None:
                _set_parameter.Metaclass_SetParameter_Response.__import_type_support__()


class SetParameter(metaclass=Metaclass_SetParameter):
    from gripper_interfaces.srv._set_parameter import SetParameter_Request as Request
    from gripper_interfaces.srv._set_parameter import SetParameter_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
