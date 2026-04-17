# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gripper_interfaces:srv/DriverEnable.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DriverEnable_Request(type):
    """Metaclass of message 'DriverEnable_Request'."""

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
                'gripper_interfaces.srv.DriverEnable_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__driver_enable__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__driver_enable__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__driver_enable__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__driver_enable__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__driver_enable__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DriverEnable_Request(metaclass=Metaclass_DriverEnable_Request):
    """Message class 'DriverEnable_Request'."""

    __slots__ = [
        '_enable',
    ]

    _fields_and_field_types = {
        'enable': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.enable = kwargs.get('enable', bool())

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
        if self.enable != other.enable:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def enable(self):
        """Message field 'enable'."""
        return self._enable

    @enable.setter
    def enable(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enable' field must be of type 'bool'"
        self._enable = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DriverEnable_Response(type):
    """Metaclass of message 'DriverEnable_Response'."""

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
                'gripper_interfaces.srv.DriverEnable_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__driver_enable__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__driver_enable__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__driver_enable__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__driver_enable__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__driver_enable__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DriverEnable_Response(metaclass=Metaclass_DriverEnable_Response):
    """Message class 'DriverEnable_Response'."""

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


class Metaclass_DriverEnable(type):
    """Metaclass of service 'DriverEnable'."""

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
                'gripper_interfaces.srv.DriverEnable')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__driver_enable

            from gripper_interfaces.srv import _driver_enable
            if _driver_enable.Metaclass_DriverEnable_Request._TYPE_SUPPORT is None:
                _driver_enable.Metaclass_DriverEnable_Request.__import_type_support__()
            if _driver_enable.Metaclass_DriverEnable_Response._TYPE_SUPPORT is None:
                _driver_enable.Metaclass_DriverEnable_Response.__import_type_support__()


class DriverEnable(metaclass=Metaclass_DriverEnable):
    from gripper_interfaces.srv._driver_enable import DriverEnable_Request as Request
    from gripper_interfaces.srv._driver_enable import DriverEnable_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
