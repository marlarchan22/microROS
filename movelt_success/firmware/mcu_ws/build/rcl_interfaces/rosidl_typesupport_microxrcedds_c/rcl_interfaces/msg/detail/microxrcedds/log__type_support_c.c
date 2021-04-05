// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from rcl_interfaces:msg/Log.idl
// generated code does not contain a copyright notice
#include "rcl_interfaces/msg/detail/log__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_c/deserialize_buffer_utility.h"
#include "rcl_interfaces/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "rcl_interfaces/msg/detail/log__struct.h"
#include "rcl_interfaces/msg/detail/log__functions.h"

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

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp
#include "rosidl_runtime_c/string.h"  // file, function, msg, name
#include "rosidl_runtime_c/string_functions.h"  // file, function, msg, name

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_rcl_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_rcl_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_rcl_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time)();


typedef rcl_interfaces__msg__Log _Log__ros_msg_type;

static bool _Log__cdr_serialize(
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

  _Log__ros_msg_type * ros_message = (_Log__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->stamp, cdr);
  // Member: level
  rv = ucdr_serialize_uint8_t(cdr, ros_message->level);
  // Member: name
  rv = ucdr_serialize_string(cdr, ros_message->name.data);
  if (rv) {
    ros_message->name.size = strlen(ros_message->name.data);
  }
  // Member: msg
  rv = ucdr_serialize_string(cdr, ros_message->msg.data);
  if (rv) {
    ros_message->msg.size = strlen(ros_message->msg.data);
  }
  // Member: file
  rv = ucdr_serialize_string(cdr, ros_message->file.data);
  if (rv) {
    ros_message->file.size = strlen(ros_message->file.data);
  }
  // Member: function
  rv = ucdr_serialize_string(cdr, ros_message->function.data);
  if (rv) {
    ros_message->function.size = strlen(ros_message->function.data);
  }
  // Member: line
  rv = ucdr_serialize_uint32_t(cdr, ros_message->line);

  return rv;
}

static bool _Log__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Log__ros_msg_type * ros_message = (_Log__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->stamp);
  // Field name: level
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->level);
  // Field name: name
  {
    size_t capacity = ros_message->name.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->name.data, capacity);
    if (rv) {
      ros_message->name.size = strlen(ros_message->name.data);
    }
  }
  // Field name: msg
  {
    size_t capacity = ros_message->msg.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->msg.data, capacity);
    if (rv) {
      ros_message->msg.size = strlen(ros_message->msg.data);
    }
  }
  // Field name: file
  {
    size_t capacity = ros_message->file.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->file.data, capacity);
    if (rv) {
      ros_message->file.size = strlen(ros_message->file.data);
    }
  }
  // Field name: function
  {
    size_t capacity = ros_message->function.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->function.data, capacity);
    if (rv) {
      ros_message->function.size = strlen(ros_message->function.data);
    }
  }
  // Field name: line
  rv = ucdr_deserialize_uint32_t(cdr, &ros_message->line);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_rcl_interfaces
size_t get_serialized_size_rcl_interfaces__msg__Log(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _Log__ros_msg_type * ros_message = (const _Log__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: stamp
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->stamp, current_alignment);
  // Member: level
  {
    const size_t item_size = sizeof(ros_message->level);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->name.size + 1;
  // Member: msg
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->msg.size + 1;
  // Member: file
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->file.size + 1;
  // Member: function
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->function.size + 1;
  // Member: line
  {
    const size_t item_size = sizeof(ros_message->line);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Log__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_rcl_interfaces__msg__Log(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_rcl_interfaces
size_t max_serialized_size_rcl_interfaces__msg__Log(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: stamp
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: level
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);
  // Member: name
  *full_bounded = false;
  // Member: msg
  *full_bounded = false;
  // Member: file
  *full_bounded = false;
  // Member: function
  *full_bounded = false;
  // Member: line
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint32_t)) + sizeof(uint32_t);

  return current_alignment - initial_alignment;
}

static size_t _Log__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_rcl_interfaces__msg__Log(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_Log = {
  "rcl_interfaces::msg",
  "Log",
  _Log__cdr_serialize,
  _Log__cdr_deserialize,
  _Log__get_serialized_size,
  get_serialized_size_rcl_interfaces__msg__Log,
  _Log__max_serialized_size
};

static rosidl_message_type_support_t _Log__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_Log,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, rcl_interfaces, msg, Log)() {
  return &_Log__type_support;
}

#if defined(__cplusplus)
}
#endif
