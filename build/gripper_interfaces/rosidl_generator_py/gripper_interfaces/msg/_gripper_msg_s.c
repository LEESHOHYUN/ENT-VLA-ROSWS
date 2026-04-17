// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from gripper_interfaces:msg/GripperMsg.idl
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
#include "gripper_interfaces/msg/detail/gripper_msg__struct.h"
#include "gripper_interfaces/msg/detail/gripper_msg__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool gripper_interfaces__msg__gripper_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
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
    assert(strncmp("gripper_interfaces.msg._gripper_msg.GripperMsg", full_classname_dest, 46) == 0);
  }
  gripper_interfaces__msg__GripperMsg * ros_message = _ros_message;
  {  // angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->angle = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // current
    PyObject * field = PyObject_GetAttrString(_pymsg, "current");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->current = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "velocity");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->velocity = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // grp_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "grp_pos");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->grp_pos = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // is_motor_enable
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_motor_enable");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_motor_enable = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_grp_init_ongoing
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_grp_init_ongoing");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_grp_init_ongoing = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_pos_ongoing
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_pos_ongoing");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_pos_ongoing = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_vel_ongoing
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_vel_ongoing");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_vel_ongoing = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_tor_ongoing
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_tor_ongoing");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_tor_ongoing = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_grp_opening
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_grp_opening");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_grp_opening = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_grp_closing
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_grp_closing");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_grp_closing = (Py_True == field);
    Py_DECREF(field);
  }
  {  // grp_direction
    PyObject * field = PyObject_GetAttrString(_pymsg, "grp_direction");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->grp_direction = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_object_grasp
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_object_grasp");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_object_grasp = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_fault_occured
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_fault_occured");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_fault_occured = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * gripper_interfaces__msg__gripper_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GripperMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("gripper_interfaces.msg._gripper_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GripperMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  gripper_interfaces__msg__GripperMsg * ros_message = (gripper_interfaces__msg__GripperMsg *)raw_ros_message;
  {  // angle
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // velocity
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // grp_pos
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->grp_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "grp_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_motor_enable
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_motor_enable ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_motor_enable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_grp_init_ongoing
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_grp_init_ongoing ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_grp_init_ongoing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_pos_ongoing
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_pos_ongoing ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_pos_ongoing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_vel_ongoing
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_vel_ongoing ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_vel_ongoing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_tor_ongoing
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_tor_ongoing ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_tor_ongoing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_grp_opening
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_grp_opening ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_grp_opening", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_grp_closing
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_grp_closing ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_grp_closing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // grp_direction
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->grp_direction ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "grp_direction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_object_grasp
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_object_grasp ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_object_grasp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_fault_occured
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_fault_occured ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_fault_occured", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
