// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from tf2_msgs:msg/TF2Error.idl
// generated code does not contain a copyright notice
#include "tf2_msgs/msg/detail/tf2_error__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_c/deserialize_buffer_utility.h"
#include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "tf2_msgs/msg/detail/tf2_error__struct.h"
#include "tf2_msgs/msg/detail/tf2_error__functions.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // error_string
#include "rosidl_runtime_c/string_functions.h"  // error_string

// forward declare type support functions


typedef tf2_msgs__msg__TF2Error _TF2Error__ros_msg_type;

static bool _TF2Error__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }

  _TF2Error__ros_msg_type * ros_message = (_TF2Error__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: error
  rv = ucdr_serialize_uint8_t(cdr, ros_message->error);
  // Member: error_string
  rv = ucdr_serialize_string(cdr, ros_message->error_string.data);
  if (rv) {
    ros_message->error_string.size = strlen(ros_message->error_string.data);
  }

  return rv;
}

static bool _TF2Error__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TF2Error__ros_msg_type * ros_message = (_TF2Error__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: error
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->error);
  // Field name: error_string
  {
    size_t capacity = ros_message->error_string.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->error_string.data, capacity);
    if (rv) {
      ros_message->error_string.size = strlen(ros_message->error_string.data);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__msg__TF2Error(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _TF2Error__ros_msg_type * ros_message = (const _TF2Error__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: error
  {
    const size_t item_size = sizeof(ros_message->error);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: error_string
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->error_string.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _TF2Error__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__msg__TF2Error(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__msg__TF2Error(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: error
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: error_string
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _TF2Error__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__msg__TF2Error(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_TF2Error = {
  "tf2_msgs::msg",
  "TF2Error",
  _TF2Error__cdr_serialize,
  _TF2Error__cdr_deserialize,
  _TF2Error__get_serialized_size,
  get_serialized_size_tf2_msgs__msg__TF2Error,
  _TF2Error__max_serialized_size
};

static rosidl_message_type_support_t _TF2Error__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_TF2Error,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, msg, TF2Error)() {
  return &_TF2Error__type_support;
}

#if defined(__cplusplus)
}
#endif
