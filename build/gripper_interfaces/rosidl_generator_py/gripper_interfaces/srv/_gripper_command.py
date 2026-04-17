# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gripper_interfaces:srv/GripperCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GripperCommand_Request(type):
    """Metaclass of message 'GripperCommand_Request'."""

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
                'gripper_interfaces.srv.GripperCommand_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__gripper_command__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__gripper_command__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__gripper_command__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__gripper_command__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__gripper_command__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperCommand_Request(metaclass=Metaclass_GripperCommand_Request):
    """Message class 'GripperCommand_Request'."""

    __slots__ = [
        '_command',
        '_value',
    ]

    _fields_and_field_types = {
        'command': 'uint8',
        'value': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.command = kwargs.get('command', int())
        self.value = kwargs.get('value', int())

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
        if self.command != other.command:
            return False
        if self.value != other.value:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'command' field must be an unsigned integer in [0, 255]"
        self._command = value

    @builtins.property
    def value(self):
        """Message field 'value'."""
        return self._value

    @value.setter
    def value(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'value' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'value' field must be an integer in [-32768, 32767]"
        self._value = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GripperCommand_Response(type):
    """Metaclass of message 'GripperCommand_Response'."""

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
                'gripper_interfaces.srv.GripperCommand_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__gripper_command__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__gripper_command__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__gripper_command__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__gripper_command__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__gripper_command__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperCommand_Response(metaclass=Metaclass_GripperCommand_Response):
    """Message class 'GripperCommand_Response'."""

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


class Metaclass_GripperCommand(type):
    """Metaclass of service 'GripperCommand'."""

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
                'gripper_interfaces.srv.GripperCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__gripper_command

            from gripper_interfaces.srv import _gripper_command
            if _gripper_command.Metaclass_GripperCommand_Request._TYPE_SUPPORT is None:
                _gripper_command.Metaclass_GripperCommand_Request.__import_type_support__()
            if _gripper_command.Metaclass_GripperCommand_Response._TYPE_SUPPORT is None:
                _gripper_command.Metaclass_GripperCommand_Response.__import_type_support__()


class GripperCommand(metaclass=Metaclass_GripperCommand):
    from gripper_interfaces.srv._gripper_command import GripperCommand_Request as Request
    from gripper_interfaces.srv._gripper_command import GripperCommand_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
