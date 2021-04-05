#include <stdio.h>
#include <std_msgs/msg/string.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>



  // create rcl_node
  rcl_node_t my_node;
  rc = rclc_node_init_default(&my_node, "node_0", "executor_examples", &support);
  if (rc != RCL_RET_OK) {
    printf("Error in rclc_node_init_default\n");
    return -1;
  }

  rcl_subscription_t my_sub = rcl_get_zero_initialized_subscription();
  rc = rclc_subscription_init_default(&my_sub, &my_node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Vector3), "/microROS/euler");
  if (rc != RCL_RET_OK) 
  {
    printf("Failed to create subscriber %s.\n", topic_name);
    return -1;
  } else {
    printf("Created subscriber %s:\n", topic_name);
  }

    rclc_executor_t executor;
  executor = rclc_executor_get_zero_initialized_executor();

int main(int argc, const char * argv[])
{
  rcl_allocator_t allocator = rcl_get_default_allocator();
  rclc_support_t support;
  rcl_ret_t rc;

  // create init_options
  rc = rclc_support_init(&support, argc, argv, &allocator);
  if (rc != RCL_RET_OK) {
    printf("Error rclc_support_init.\n");
    return -1;
  }
