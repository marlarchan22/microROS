// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from tf2_msgs:msg/TFMessage.idl
// generated code does not contain a copyright notice
#include "tf2_msgs/msg/detail/tf_message__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_c/deserialize_buffer_utility.h"
#include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "tf2_msgs/msg/detail/tf_message__struct.h"
#include "tf2_msgs/msg/detail/tf_message__functions.h"

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

#include "geometry_msgs/msg/detail/transform_stamped__functions.h"  // transforms

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_geometry_msgs__msg__TransformStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_geometry_msgs__msg__TransformStamped(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TransformStamped)();


typedef tf2_msgs__msg__TFMessage _TFMessage__ros_msg_type;

static bool _TFMessage__cdr_serialize(
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

  _TFMessage__ros_msg_type * ros_message = (_TFMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: transforms
  {
    const size_t size = ros_message->transforms.size;
    rv = ucdr_serialize_uint32_t(cdr, size);

    if(rv == true){
      for(size_t i = 0; i < size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TransformStamped
          )()->data))->cdr_serialize(&ros_message->transforms.data[i], cdr);
        if(rv == false){
          break;
        }
      }
    }
  }

  return rv;
}

static bool _TFMessage__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _TFMessage__ros_msg_type * ros_message = (_TFMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: transforms
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->transforms.capacity){
      fprintf(stderr, "cannot allocate received sequence in ros_message\n");
      return 0;
    }

    ros_message->transforms.size = size;
    for(size_t i = 0; i < size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TransformStamped
        )()->data))->cdr_deserialize(cdr, &ros_message->transforms.data[i]);
      if(rv == false){
        break;
      }
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__msg__TFMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _TFMessage__ros_msg_type * ros_message = (const _TFMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: transforms
  {
    const size_t sequence_size = ros_message->transforms.size;

    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TransformStamped
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->transforms.data[i], current_alignment);
      uint8_t alignment_size = (element_size < MICROXRCEDDS_PADDING) ? element_size : MICROXRCEDDS_PADDING;
      current_alignment += ucdr_alignment(current_alignment, alignment_size) + element_size;
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _TFMessage__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__msg__TFMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__msg__TFMessage(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: transforms
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _TFMessage__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__msg__TFMessage(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_TFMessage = {
  "tf2_msgs::msg",
  "TFMessage",
  _TFMessage__cdr_serialize,
  _TFMessage__cdr_deserialize,
  _TFMessage__get_serialized_size,
  get_serialized_size_tf2_msgs__msg__TFMessage,
  _TFMessage__max_serialized_size
};

static rosidl_message_type_support_t _TFMessage__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_TFMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, msg, TFMessage)() {
  return &_TFMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
