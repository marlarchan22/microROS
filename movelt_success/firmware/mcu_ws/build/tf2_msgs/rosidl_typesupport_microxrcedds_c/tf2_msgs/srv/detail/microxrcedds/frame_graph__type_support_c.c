// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from tf2_msgs:srv/FrameGraph.idl
// generated code does not contain a copyright notice
#include "tf2_msgs/srv/detail/frame_graph__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_c/deserialize_buffer_utility.h"
#include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "tf2_msgs/srv/detail/frame_graph__struct.h"
#include "tf2_msgs/srv/detail/frame_graph__functions.h"

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


// forward declare type support functions


typedef tf2_msgs__srv__FrameGraph_Request _FrameGraph_Request__ros_msg_type;

static bool _FrameGraph_Request__cdr_serialize(
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

  _FrameGraph_Request__ros_msg_type * ros_message = (_FrameGraph_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_serialize_uint8_t(cdr, ros_message->structure_needs_at_least_one_member);

  return rv;
}

static bool _FrameGraph_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FrameGraph_Request__ros_msg_type * ros_message = (_FrameGraph_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: structure_needs_at_least_one_member
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->structure_needs_at_least_one_member);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__srv__FrameGraph_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _FrameGraph_Request__ros_msg_type * ros_message = (const _FrameGraph_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  {
    const size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _FrameGraph_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__srv__FrameGraph_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__srv__FrameGraph_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static size_t _FrameGraph_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__srv__FrameGraph_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FrameGraph_Request = {
  "tf2_msgs::srv",
  "FrameGraph_Request",
  _FrameGraph_Request__cdr_serialize,
  _FrameGraph_Request__cdr_deserialize,
  _FrameGraph_Request__get_serialized_size,
  get_serialized_size_tf2_msgs__srv__FrameGraph_Request,
  _FrameGraph_Request__max_serialized_size
};

static rosidl_message_type_support_t _FrameGraph_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FrameGraph_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, srv, FrameGraph_Request)() {
  return &_FrameGraph_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/deserialize_buffer_utility.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__struct.h"
// already included above
// #include "tf2_msgs/srv/detail/frame_graph__functions.h"

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

#include "rosidl_runtime_c/string.h"  // frame_yaml
#include "rosidl_runtime_c/string_functions.h"  // frame_yaml

// forward declare type support functions


typedef tf2_msgs__srv__FrameGraph_Response _FrameGraph_Response__ros_msg_type;

static bool _FrameGraph_Response__cdr_serialize(
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

  _FrameGraph_Response__ros_msg_type * ros_message = (_FrameGraph_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: frame_yaml
  rv = ucdr_serialize_string(cdr, ros_message->frame_yaml.data);
  if (rv) {
    ros_message->frame_yaml.size = strlen(ros_message->frame_yaml.data);
  }

  return rv;
}

static bool _FrameGraph_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FrameGraph_Response__ros_msg_type * ros_message = (_FrameGraph_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: frame_yaml
  {
    size_t capacity = ros_message->frame_yaml.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->frame_yaml.data, capacity);
    if (rv) {
      ros_message->frame_yaml.size = strlen(ros_message->frame_yaml.data);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__srv__FrameGraph_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _FrameGraph_Response__ros_msg_type * ros_message = (const _FrameGraph_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: frame_yaml
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->frame_yaml.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _FrameGraph_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__srv__FrameGraph_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__srv__FrameGraph_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: frame_yaml
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _FrameGraph_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__srv__FrameGraph_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_FrameGraph_Response = {
  "tf2_msgs::srv",
  "FrameGraph_Response",
  _FrameGraph_Response__cdr_serialize,
  _FrameGraph_Response__cdr_deserialize,
  _FrameGraph_Response__get_serialized_size,
  get_serialized_size_tf2_msgs__srv__FrameGraph_Response,
  _FrameGraph_Response__max_serialized_size
};

static rosidl_message_type_support_t _FrameGraph_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_FrameGraph_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, srv, FrameGraph_Response)() {
  return &_FrameGraph_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "tf2_msgs/srv/frame_graph.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t FrameGraph__callbacks = {
  "tf2_msgs::srv",
  "FrameGraph",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, srv, FrameGraph_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, srv, FrameGraph_Response),
};

static rosidl_service_type_support_t FrameGraph__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &FrameGraph__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, srv, FrameGraph)() {
  return &FrameGraph__handle;
}

#if defined(__cplusplus)
}
#endif
