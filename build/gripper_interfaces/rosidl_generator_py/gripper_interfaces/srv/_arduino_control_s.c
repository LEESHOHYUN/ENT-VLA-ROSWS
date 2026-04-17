// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gripper_interfaces:srv/ArduinoControl.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "gripper_interfaces/srv/detail/arduino_control__struct.h"
#include "gripper_interfaces/srv/detail/arduino_control__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gripper_interfaces__srv__arduino_control__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("gripper_interfaces.srv._arduino_control.ArduinoControl_Request", full_classname_dest, 62) == 0);
  }
  gripper_interfaces__srv__ArduinoControl_Request * ros_message = _ros_message;
  {  // power
    PyObject * field = PyObject_GetAttrString(_pymsg, "power");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->power = (Py_True == field);
    Py_DECREF(field);
  }
  {  // solenoid_valve
    PyObject * field = PyObject_GetAttrString(_pymsg, "solenoid_valve");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->solenoid_valve = (Py_True == field);
    Py_DECREF(field);
  }
  {  // spare_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "spare_1");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->spare_1 = (Py_True == field);
    Py_DECREF(field);
  }
  {  // spare_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "spare_2");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->spare_2 = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gripper_interfaces__srv__arduino_control__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ArduinoControl_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gripper_interfaces.srv._arduino_control");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ArduinoControl_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gripper_interfaces__srv__ArduinoControl_Request * ros_message = (gripper_interfaces__srv__ArduinoControl_Request *)raw_ros_message;
  {  // power
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->power ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "power", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // solenoid_valve
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->solenoid_valve ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "solenoid_valve", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // spare_1
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->spare_1 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "spare_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // spare_2
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->spare_2 ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "spare_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "gripper_interfaces/srv/detail/arduino_control__struct.h"
// already included above
// #include "gripper_interfaces/srv/detail/arduino_control__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gripper_interfaces__srv__arduino_control__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("gripper_interfaces.srv._arduino_control.ArduinoControl_Response", full_classname_dest, 63) == 0);
  }
  gripper_interfaces__srv__ArduinoControl_Response * ros_message = _ros_message;
  {  // successed
    PyObject * field = PyObject_GetAttrString(_pymsg, "successed");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->successed = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gripper_interfaces__srv__arduino_control__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ArduinoControl_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gripper_interfaces.srv._arduino_control");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ArduinoControl_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gripper_interfaces__srv__ArduinoControl_Response * ros_message = (gripper_interfaces__srv__ArduinoControl_Response *)raw_ros_message;
  {  // successed
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->successed ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "successed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
