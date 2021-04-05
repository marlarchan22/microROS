// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from tf2_msgs:action/LookupTransform.idl
// generated code does not contain a copyright notice
#include "tf2_msgs/action/detail/lookup_transform__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "rosidl_typesupport_microxrcedds_c/deserialize_buffer_utility.h"
#include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "tf2_msgs/action/detail/lookup_transform__struct.h"
#include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

#include "builtin_interfaces/msg/detail/duration__functions.h"  // timeout
#include "builtin_interfaces/msg/detail/time__functions.h"  // source_time, target_time
#include "rosidl_runtime_c/string.h"  // fixed_frame, source_frame, target_frame
#include "rosidl_runtime_c/string_functions.h"  // fixed_frame, source_frame, target_frame

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_builtin_interfaces__msg__Duration(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_builtin_interfaces__msg__Duration(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time)();


typedef tf2_msgs__action__LookupTransform_Goal _LookupTransform_Goal__ros_msg_type;

static bool _LookupTransform_Goal__cdr_serialize(
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

  _LookupTransform_Goal__ros_msg_type * ros_message = (_LookupTransform_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: target_frame
  rv = ucdr_serialize_string(cdr, ros_message->target_frame.data);
  if (rv) {
    ros_message->target_frame.size = strlen(ros_message->target_frame.data);
  }
  // Member: source_frame
  rv = ucdr_serialize_string(cdr, ros_message->source_frame.data);
  if (rv) {
    ros_message->source_frame.size = strlen(ros_message->source_frame.data);
  }
  // Member: source_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->source_time, cdr);
  // Member: timeout
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_serialize(&ros_message->timeout, cdr);
  // Member: target_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->target_time, cdr);
  // Member: fixed_frame
  rv = ucdr_serialize_string(cdr, ros_message->fixed_frame.data);
  if (rv) {
    ros_message->fixed_frame.size = strlen(ros_message->fixed_frame.data);
  }
  // Member: advanced
  rv = ucdr_serialize_bool(cdr, ros_message->advanced);

  return rv;
}

static bool _LookupTransform_Goal__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_Goal__ros_msg_type * ros_message = (_LookupTransform_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: target_frame
  {
    size_t capacity = ros_message->target_frame.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->target_frame.data, capacity);
    if (rv) {
      ros_message->target_frame.size = strlen(ros_message->target_frame.data);
    }
  }
  // Field name: source_frame
  {
    size_t capacity = ros_message->source_frame.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->source_frame.data, capacity);
    if (rv) {
      ros_message->source_frame.size = strlen(ros_message->source_frame.data);
    }
  }
  // Field name: source_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->source_time);
  // Field name: timeout
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Duration
      )()->data))->cdr_deserialize(cdr, &ros_message->timeout);
  // Field name: target_time
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->target_time);
  // Field name: fixed_frame
  {
    size_t capacity = ros_message->fixed_frame.capacity;
    rv = ucdr_deserialize_string(cdr, ros_message->fixed_frame.data, capacity);
    if (rv) {
      ros_message->fixed_frame.size = strlen(ros_message->fixed_frame.data);
    }
  }
  // Field name: advanced
  rv = ucdr_deserialize_bool(cdr, &ros_message->advanced);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_Goal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_Goal__ros_msg_type * ros_message = (const _LookupTransform_Goal__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: target_frame
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->target_frame.size + 1;
  // Member: source_frame
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->source_frame.size + 1;
  // Member: source_time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->source_time, current_alignment);
  // Member: timeout
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Duration(&ros_message->timeout, current_alignment);
  // Member: target_time
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->target_time, current_alignment);
  // Member: fixed_frame
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->fixed_frame.size + 1;
  // Member: advanced
  {
    const size_t item_size = sizeof(ros_message->advanced);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_Goal__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_Goal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_Goal(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: target_frame
  *full_bounded = false;
  // Member: source_frame
  *full_bounded = false;
  // Member: source_time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: timeout
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Duration(full_bounded, current_alignment);
  // Member: target_time
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);
  // Member: fixed_frame
  *full_bounded = false;
  // Member: advanced
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_Goal__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_Goal(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_Goal = {
  "tf2_msgs::action",
  "LookupTransform_Goal",
  _LookupTransform_Goal__cdr_serialize,
  _LookupTransform_Goal__cdr_deserialize,
  _LookupTransform_Goal__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_Goal,
  _LookupTransform_Goal__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_Goal__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_Goal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Goal)() {
  return &_LookupTransform_Goal__type_support;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

#include "geometry_msgs/msg/detail/transform_stamped__functions.h"  // transform
#include "tf2_msgs/msg/detail/tf2_error__functions.h"  // error

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
size_t get_serialized_size_tf2_msgs__msg__TF2Error(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tf2_msgs__msg__TF2Error(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, msg, TF2Error)();


typedef tf2_msgs__action__LookupTransform_Result _LookupTransform_Result__ros_msg_type;

static bool _LookupTransform_Result__cdr_serialize(
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

  _LookupTransform_Result__ros_msg_type * ros_message = (_LookupTransform_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: transform
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TransformStamped
      )()->data))->cdr_serialize(&ros_message->transform, cdr);
  // Member: error
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, msg, TF2Error
      )()->data))->cdr_serialize(&ros_message->error, cdr);

  return rv;
}

static bool _LookupTransform_Result__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_Result__ros_msg_type * ros_message = (_LookupTransform_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: transform
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, geometry_msgs, msg, TransformStamped
      )()->data))->cdr_deserialize(cdr, &ros_message->transform);
  // Field name: error
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, msg, TF2Error
      )()->data))->cdr_deserialize(cdr, &ros_message->error);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_Result(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_Result__ros_msg_type * ros_message = (const _LookupTransform_Result__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: transform
  current_alignment +=
    get_serialized_size_geometry_msgs__msg__TransformStamped(&ros_message->transform, current_alignment);
  // Member: error
  current_alignment +=
    get_serialized_size_tf2_msgs__msg__TF2Error(&ros_message->error, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_Result__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_Result(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_Result(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: transform
  current_alignment +=
    max_serialized_size_geometry_msgs__msg__TransformStamped(full_bounded, current_alignment);
  // Member: error
  current_alignment +=
    max_serialized_size_tf2_msgs__msg__TF2Error(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_Result__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_Result(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_Result = {
  "tf2_msgs::action",
  "LookupTransform_Result",
  _LookupTransform_Result__cdr_serialize,
  _LookupTransform_Result__cdr_deserialize,
  _LookupTransform_Result__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_Result,
  _LookupTransform_Result__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_Result__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_Result,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Result)() {
  return &_LookupTransform_Result__type_support;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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


typedef tf2_msgs__action__LookupTransform_Feedback _LookupTransform_Feedback__ros_msg_type;

static bool _LookupTransform_Feedback__cdr_serialize(
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

  _LookupTransform_Feedback__ros_msg_type * ros_message = (_LookupTransform_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_serialize_uint8_t(cdr, ros_message->structure_needs_at_least_one_member);

  return rv;
}

static bool _LookupTransform_Feedback__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_Feedback__ros_msg_type * ros_message = (_LookupTransform_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: structure_needs_at_least_one_member
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->structure_needs_at_least_one_member);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_Feedback__ros_msg_type * ros_message = (const _LookupTransform_Feedback__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  {
    const size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_Feedback__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_Feedback(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_Feedback(
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

static size_t _LookupTransform_Feedback__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_Feedback(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_Feedback = {
  "tf2_msgs::action",
  "LookupTransform_Feedback",
  _LookupTransform_Feedback__cdr_serialize,
  _LookupTransform_Feedback__cdr_deserialize,
  _LookupTransform_Feedback__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_Feedback,
  _LookupTransform_Feedback__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_Feedback__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_Feedback,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Feedback)() {
  return &_LookupTransform_Feedback__type_support;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"  // goal
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_tf2_msgs__action__LookupTransform_Goal(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tf2_msgs__action__LookupTransform_Goal(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Goal)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID)();


typedef tf2_msgs__action__LookupTransform_SendGoal_Request _LookupTransform_SendGoal_Request__ros_msg_type;

static bool _LookupTransform_SendGoal_Request__cdr_serialize(
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

  _LookupTransform_SendGoal_Request__ros_msg_type * ros_message = (_LookupTransform_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Goal
      )()->data))->cdr_serialize(&ros_message->goal, cdr);

  return rv;
}

static bool _LookupTransform_SendGoal_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_SendGoal_Request__ros_msg_type * ros_message = (_LookupTransform_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: goal
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Goal
      )()->data))->cdr_deserialize(cdr, &ros_message->goal);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_SendGoal_Request__ros_msg_type * ros_message = (const _LookupTransform_SendGoal_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: goal
  current_alignment +=
    get_serialized_size_tf2_msgs__action__LookupTransform_Goal(&ros_message->goal, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_SendGoal_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    max_serialized_size_unique_identifier_msgs__msg__UUID(full_bounded, current_alignment);
  // Member: goal
  current_alignment +=
    max_serialized_size_tf2_msgs__action__LookupTransform_Goal(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_SendGoal_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_SendGoal_Request = {
  "tf2_msgs::action",
  "LookupTransform_SendGoal_Request",
  _LookupTransform_SendGoal_Request__cdr_serialize,
  _LookupTransform_SendGoal_Request__cdr_deserialize,
  _LookupTransform_SendGoal_Request__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Request,
  _LookupTransform_SendGoal_Request__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_SendGoal_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_SendGoal_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_SendGoal_Request)() {
  return &_LookupTransform_SendGoal_Request__type_support;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

// already included above
// #include "builtin_interfaces/msg/detail/time__functions.h"  // stamp

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time)();


typedef tf2_msgs__action__LookupTransform_SendGoal_Response _LookupTransform_SendGoal_Response__ros_msg_type;

static bool _LookupTransform_SendGoal_Response__cdr_serialize(
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

  _LookupTransform_SendGoal_Response__ros_msg_type * ros_message = (_LookupTransform_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: accepted
  rv = ucdr_serialize_bool(cdr, ros_message->accepted);
  // Member: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_serialize(&ros_message->stamp, cdr);

  return rv;
}

static bool _LookupTransform_SendGoal_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_SendGoal_Response__ros_msg_type * ros_message = (_LookupTransform_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: accepted
  rv = ucdr_deserialize_bool(cdr, &ros_message->accepted);
  // Field name: stamp
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, builtin_interfaces, msg, Time
      )()->data))->cdr_deserialize(cdr, &ros_message->stamp);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_SendGoal_Response__ros_msg_type * ros_message = (const _LookupTransform_SendGoal_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: accepted
  {
    const size_t item_size = sizeof(ros_message->accepted);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: stamp
  current_alignment +=
    get_serialized_size_builtin_interfaces__msg__Time(&ros_message->stamp, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_SendGoal_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: accepted
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);
  // Member: stamp
  current_alignment +=
    max_serialized_size_builtin_interfaces__msg__Time(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_SendGoal_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_SendGoal_Response = {
  "tf2_msgs::action",
  "LookupTransform_SendGoal_Response",
  _LookupTransform_SendGoal_Response__cdr_serialize,
  _LookupTransform_SendGoal_Response__cdr_deserialize,
  _LookupTransform_SendGoal_Response__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_SendGoal_Response,
  _LookupTransform_SendGoal_Response__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_SendGoal_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_SendGoal_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_SendGoal_Response)() {
  return &_LookupTransform_SendGoal_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "tf2_msgs/action/lookup_transform.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t LookupTransform_SendGoal__callbacks = {
  "tf2_msgs::action",
  "LookupTransform_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_SendGoal_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_SendGoal_Response),
};

static rosidl_service_type_support_t LookupTransform_SendGoal__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &LookupTransform_SendGoal__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_SendGoal)() {
  return &LookupTransform_SendGoal__handle;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID)();


typedef tf2_msgs__action__LookupTransform_GetResult_Request _LookupTransform_GetResult_Request__ros_msg_type;

static bool _LookupTransform_GetResult_Request__cdr_serialize(
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

  _LookupTransform_GetResult_Request__ros_msg_type * ros_message = (_LookupTransform_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);

  return rv;
}

static bool _LookupTransform_GetResult_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_GetResult_Request__ros_msg_type * ros_message = (_LookupTransform_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_GetResult_Request__ros_msg_type * ros_message = (const _LookupTransform_GetResult_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_GetResult_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    max_serialized_size_unique_identifier_msgs__msg__UUID(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_GetResult_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_GetResult_Request = {
  "tf2_msgs::action",
  "LookupTransform_GetResult_Request",
  _LookupTransform_GetResult_Request__cdr_serialize,
  _LookupTransform_GetResult_Request__cdr_deserialize,
  _LookupTransform_GetResult_Request__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Request,
  _LookupTransform_GetResult_Request__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_GetResult_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_GetResult_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_GetResult_Request)() {
  return &_LookupTransform_GetResult_Request__type_support;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"  // result

// forward declare type support functions
size_t get_serialized_size_tf2_msgs__action__LookupTransform_Result(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tf2_msgs__action__LookupTransform_Result(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Result)();


typedef tf2_msgs__action__LookupTransform_GetResult_Response _LookupTransform_GetResult_Response__ros_msg_type;

static bool _LookupTransform_GetResult_Response__cdr_serialize(
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

  _LookupTransform_GetResult_Response__ros_msg_type * ros_message = (_LookupTransform_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: status
  rv = ucdr_serialize_int8_t(cdr, ros_message->status);
  // Member: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Result
      )()->data))->cdr_serialize(&ros_message->result, cdr);

  return rv;
}

static bool _LookupTransform_GetResult_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_GetResult_Response__ros_msg_type * ros_message = (_LookupTransform_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: status
  rv = ucdr_deserialize_int8_t(cdr, &ros_message->status);
  // Field name: result
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Result
      )()->data))->cdr_deserialize(cdr, &ros_message->result);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_GetResult_Response__ros_msg_type * ros_message = (const _LookupTransform_GetResult_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: status
  {
    const size_t item_size = sizeof(ros_message->status);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: result
  current_alignment +=
    get_serialized_size_tf2_msgs__action__LookupTransform_Result(&ros_message->result, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_GetResult_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: status
  current_alignment += ucdr_alignment(current_alignment, sizeof(int8_t)) + sizeof(int8_t);
  // Member: result
  current_alignment +=
    max_serialized_size_tf2_msgs__action__LookupTransform_Result(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_GetResult_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_GetResult_Response = {
  "tf2_msgs::action",
  "LookupTransform_GetResult_Response",
  _LookupTransform_GetResult_Response__cdr_serialize,
  _LookupTransform_GetResult_Response__cdr_deserialize,
  _LookupTransform_GetResult_Response__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_GetResult_Response,
  _LookupTransform_GetResult_Response__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_GetResult_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_GetResult_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_GetResult_Response)() {
  return &_LookupTransform_GetResult_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "tf2_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "tf2_msgs/action/lookup_transform.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t LookupTransform_GetResult__callbacks = {
  "tf2_msgs::action",
  "LookupTransform_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_GetResult_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_GetResult_Response),
};

static rosidl_service_type_support_t LookupTransform_GetResult__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &LookupTransform_GetResult__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_GetResult)() {
  return &LookupTransform_GetResult__handle;
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
// #include "tf2_msgs/action/detail/lookup_transform__struct.h"
// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"

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

// already included above
// #include "tf2_msgs/action/detail/lookup_transform__functions.h"  // feedback
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // goal_id

// forward declare type support functions
size_t get_serialized_size_tf2_msgs__action__LookupTransform_Feedback(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_tf2_msgs__action__LookupTransform_Feedback(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Feedback)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_tf2_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID)();


typedef tf2_msgs__action__LookupTransform_FeedbackMessage _LookupTransform_FeedbackMessage__ros_msg_type;

static bool _LookupTransform_FeedbackMessage__cdr_serialize(
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

  _LookupTransform_FeedbackMessage__ros_msg_type * ros_message = (_LookupTransform_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_serialize(&ros_message->goal_id, cdr);
  // Member: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Feedback
      )()->data))->cdr_serialize(&ros_message->feedback, cdr);

  return rv;
}

static bool _LookupTransform_FeedbackMessage__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LookupTransform_FeedbackMessage__ros_msg_type * ros_message = (_LookupTransform_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: goal_id
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, unique_identifier_msgs, msg, UUID
      )()->data))->cdr_deserialize(cdr, &ros_message->goal_id);
  // Field name: feedback
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_Feedback
      )()->data))->cdr_deserialize(cdr, &ros_message->feedback);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t get_serialized_size_tf2_msgs__action__LookupTransform_FeedbackMessage(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return 0;
  }

  const _LookupTransform_FeedbackMessage__ros_msg_type * ros_message = (const _LookupTransform_FeedbackMessage__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    get_serialized_size_unique_identifier_msgs__msg__UUID(&ros_message->goal_id, current_alignment);
  // Member: feedback
  current_alignment +=
    get_serialized_size_tf2_msgs__action__LookupTransform_Feedback(&ros_message->feedback, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _LookupTransform_FeedbackMessage__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_tf2_msgs__action__LookupTransform_FeedbackMessage(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_tf2_msgs
size_t max_serialized_size_tf2_msgs__action__LookupTransform_FeedbackMessage(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: goal_id
  current_alignment +=
    max_serialized_size_unique_identifier_msgs__msg__UUID(full_bounded, current_alignment);
  // Member: feedback
  current_alignment +=
    max_serialized_size_tf2_msgs__action__LookupTransform_Feedback(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _LookupTransform_FeedbackMessage__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_tf2_msgs__action__LookupTransform_FeedbackMessage(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_LookupTransform_FeedbackMessage = {
  "tf2_msgs::action",
  "LookupTransform_FeedbackMessage",
  _LookupTransform_FeedbackMessage__cdr_serialize,
  _LookupTransform_FeedbackMessage__cdr_deserialize,
  _LookupTransform_FeedbackMessage__get_serialized_size,
  get_serialized_size_tf2_msgs__action__LookupTransform_FeedbackMessage,
  _LookupTransform_FeedbackMessage__max_serialized_size
};

static rosidl_message_type_support_t _LookupTransform_FeedbackMessage__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_LookupTransform_FeedbackMessage,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, tf2_msgs, action, LookupTransform_FeedbackMessage)() {
  return &_LookupTransform_FeedbackMessage__type_support;
}

#if defined(__cplusplus)
}
#endif
