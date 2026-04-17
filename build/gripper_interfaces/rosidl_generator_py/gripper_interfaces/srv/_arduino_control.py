# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gripper_interfaces:srv/ArduinoControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArduinoControl_Request(type):
    """Metaclass of message 'ArduinoControl_Request'."""

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
                'gripper_interfaces.srv.ArduinoControl_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__arduino_control__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__arduino_control__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__arduino_control__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__arduino_control__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__arduino_control__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArduinoControl_Request(metaclass=Metaclass_ArduinoControl_Request):
    """Message class 'ArduinoControl_Request'."""

    __slots__ = [
        '_power',
        '_solenoid_valve',
        '_spare_1',
        '_spare_2',
    ]

    _fields_and_field_types = {
        'power': 'boolean',
        'solenoid_valve': 'boolean',
        'spare_1': 'boolean',
        'spare_2': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.power = kwargs.get('power', bool())
        self.solenoid_valve = kwargs.get('solenoid_valve', bool())
        self.spare_1 = kwargs.get('spare_1', bool())
        self.spare_2 = kwargs.get('spare_2', bool())

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
        if self.power != other.power:
            return False
        if self.solenoid_valve != other.solenoid_valve:
            return False
        if self.spare_1 != other.spare_1:
            return False
        if self.spare_2 != other.spare_2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def power(self):
        """Message field 'power'."""
        return self._power

    @power.setter
    def power(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'power' field must be of type 'bool'"
        self._power = value

    @builtins.property
    def solenoid_valve(self):
        """Message field 'solenoid_valve'."""
        return self._solenoid_valve

    @solenoid_valve.setter
    def solenoid_valve(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'solenoid_valve' field must be of type 'bool'"
        self._solenoid_valve = value

    @builtins.property
    def spare_1(self):
        """Message field 'spare_1'."""
        return self._spare_1

    @spare_1.setter
    def spare_1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'spare_1' field must be of type 'bool'"
        self._spare_1 = value

    @builtins.property
    def spare_2(self):
        """Message field 'spare_2'."""
        return self._spare_2

    @spare_2.setter
    def spare_2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'spare_2' field must be of type 'bool'"
        self._spare_2 = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ArduinoControl_Response(type):
    """Metaclass of message 'ArduinoControl_Response'."""

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
                'gripper_interfaces.srv.ArduinoControl_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__arduino_control__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__arduino_control__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__arduino_control__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__arduino_control__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__arduino_control__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArduinoControl_Response(metaclass=Metaclass_ArduinoControl_Response):
    """Message class 'ArduinoControl_Response'."""

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


class Metaclass_ArduinoControl(type):
    """Metaclass of service 'ArduinoControl'."""

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
                'gripper_interfaces.srv.ArduinoControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__arduino_control

            from gripper_interfaces.srv import _arduino_control
            if _arduino_control.Metaclass_ArduinoControl_Request._TYPE_SUPPORT is None:
                _arduino_control.Metaclass_ArduinoControl_Request.__import_type_support__()
            if _arduino_control.Metaclass_ArduinoControl_Response._TYPE_SUPPORT is None:
                _arduino_control.Metaclass_ArduinoControl_Response.__import_type_support__()


class ArduinoControl(metaclass=Metaclass_ArduinoControl):
    from gripper_interfaces.srv._arduino_control import ArduinoControl_Request as Request
    from gripper_interfaces.srv._arduino_control import ArduinoControl_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
