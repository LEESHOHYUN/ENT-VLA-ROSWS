# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gripper_interfaces:srv/GripperControl.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'torque_ctrl_param'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

# Member 'pos_ctrl_param'
# Member 'vel_ctrl_param'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GripperControl_Request(type):
    """Metaclass of message 'GripperControl_Request'."""

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
                'gripper_interfaces.srv.GripperControl_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__gripper_control__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__gripper_control__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__gripper_control__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__gripper_control__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__gripper_control__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperControl_Request(metaclass=Metaclass_GripperControl_Request):
    """Message class 'GripperControl_Request'."""

    __slots__ = [
        '_control_mode',
        '_pos_ctrl_param',
        '_vel_ctrl_param',
        '_torque_ctrl_param',
        '_custom_input',
        '_gripper_init',
        '_grasping_vel',
    ]

    _fields_and_field_types = {
        'control_mode': 'int8',
        'pos_ctrl_param': 'uint16[3]',
        'vel_ctrl_param': 'uint16[3]',
        'torque_ctrl_param': 'sequence<uint32>',
        'custom_input': 'string',
        'gripper_init': 'string',
        'grasping_vel': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint16'), 3),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint16'), 3),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.control_mode = kwargs.get('control_mode', int())
        if 'pos_ctrl_param' not in kwargs:
            self.pos_ctrl_param = numpy.zeros(3, dtype=numpy.uint16)
        else:
            self.pos_ctrl_param = kwargs.get('pos_ctrl_param')
        if 'vel_ctrl_param' not in kwargs:
            self.vel_ctrl_param = numpy.zeros(3, dtype=numpy.uint16)
        else:
            self.vel_ctrl_param = kwargs.get('vel_ctrl_param')
        self.torque_ctrl_param = array.array('I', kwargs.get('torque_ctrl_param', []))
        self.custom_input = kwargs.get('custom_input', str())
        self.gripper_init = kwargs.get('gripper_init', str())
        self.grasping_vel = kwargs.get('grasping_vel', str())

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
        if self.control_mode != other.control_mode:
            return False
        if any(self.pos_ctrl_param != other.pos_ctrl_param):
            return False
        if any(self.vel_ctrl_param != other.vel_ctrl_param):
            return False
        if self.torque_ctrl_param != other.torque_ctrl_param:
            return False
        if self.custom_input != other.custom_input:
            return False
        if self.gripper_init != other.gripper_init:
            return False
        if self.grasping_vel != other.grasping_vel:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def control_mode(self):
        """Message field 'control_mode'."""
        return self._control_mode

    @control_mode.setter
    def control_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'control_mode' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'control_mode' field must be an integer in [-128, 127]"
        self._control_mode = value

    @builtins.property
    def pos_ctrl_param(self):
        """Message field 'pos_ctrl_param'."""
        return self._pos_ctrl_param

    @pos_ctrl_param.setter
    def pos_ctrl_param(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint16, \
                "The 'pos_ctrl_param' numpy.ndarray() must have the dtype of 'numpy.uint16'"
            assert value.size == 3, \
                "The 'pos_ctrl_param' numpy.ndarray() must have a size of 3"
            self._pos_ctrl_param = value
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
                 len(value) == 3 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'pos_ctrl_param' field must be a set or sequence with length 3 and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._pos_ctrl_param = numpy.array(value, dtype=numpy.uint16)

    @builtins.property
    def vel_ctrl_param(self):
        """Message field 'vel_ctrl_param'."""
        return self._vel_ctrl_param

    @vel_ctrl_param.setter
    def vel_ctrl_param(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint16, \
                "The 'vel_ctrl_param' numpy.ndarray() must have the dtype of 'numpy.uint16'"
            assert value.size == 3, \
                "The 'vel_ctrl_param' numpy.ndarray() must have a size of 3"
            self._vel_ctrl_param = value
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
                 len(value) == 3 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'vel_ctrl_param' field must be a set or sequence with length 3 and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._vel_ctrl_param = numpy.array(value, dtype=numpy.uint16)

    @builtins.property
    def torque_ctrl_param(self):
        """Message field 'torque_ctrl_param'."""
        return self._torque_ctrl_param

    @torque_ctrl_param.setter
    def torque_ctrl_param(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'torque_ctrl_param' array.array() must have the type code of 'I'"
            self._torque_ctrl_param = value
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
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'torque_ctrl_param' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._torque_ctrl_param = array.array('I', value)

    @builtins.property
    def custom_input(self):
        """Message field 'custom_input'."""
        return self._custom_input

    @custom_input.setter
    def custom_input(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'custom_input' field must be of type 'str'"
        self._custom_input = value

    @builtins.property
    def gripper_init(self):
        """Message field 'gripper_init'."""
        return self._gripper_init

    @gripper_init.setter
    def gripper_init(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'gripper_init' field must be of type 'str'"
        self._gripper_init = value

    @builtins.property
    def grasping_vel(self):
        """Message field 'grasping_vel'."""
        return self._grasping_vel

    @grasping_vel.setter
    def grasping_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'grasping_vel' field must be of type 'str'"
        self._grasping_vel = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GripperControl_Response(type):
    """Metaclass of message 'GripperControl_Response'."""

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
                'gripper_interfaces.srv.GripperControl_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__gripper_control__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__gripper_control__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__gripper_control__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__gripper_control__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__gripper_control__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GripperControl_Response(metaclass=Metaclass_GripperControl_Response):
    """Message class 'GripperControl_Response'."""

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


class Metaclass_GripperControl(type):
    """Metaclass of service 'GripperControl'."""

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
                'gripper_interfaces.srv.GripperControl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__gripper_control

            from gripper_interfaces.srv import _gripper_control
            if _gripper_control.Metaclass_GripperControl_Request._TYPE_SUPPORT is None:
                _gripper_control.Metaclass_GripperControl_Request.__import_type_support__()
            if _gripper_control.Metaclass_GripperControl_Response._TYPE_SUPPORT is None:
                _gripper_control.Metaclass_GripperControl_Response.__import_type_support__()


class GripperControl(metaclass=Metaclass_GripperControl):
    from gripper_interfaces.srv._gripper_control import GripperControl_Request as Request
    from gripper_interfaces.srv._gripper_control import GripperControl_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
