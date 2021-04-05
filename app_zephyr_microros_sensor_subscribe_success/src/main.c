#include <zephyr.h>
#include <device.h>
#include <devicetree.h>

#include <drivers/sensor.h>
#include <drivers/gpio.h>
#include <drivers/led_strip.h>
#include <drivers/spi.h>

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <sys/printk.h>
#include <sys/util.h>

#include <posix/time.h>
#include <posix/sys/time.h>
#include <posix/unistd.h>

//Microros
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

//middleware
#include <rmw_uros/options.h>
#include <microros_transports.h>

//Custom Message
#include <geometry_msgs/msg/vector3.h>
#include <geometry_msgs/msg/transform_stamped.h>
#include <tf2_msgs/msg/tf_message.h>
#include <std_msgs/msg/empty.h>

#include <sensfusion9.h>

//pingpong
#include <std_msgs/msg/header.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define pow2(x) ((x) * (x))

#define STR_CAPACITY 50
#define LED_PIN		 DT_GPIO_PIN(DT_ALIAS(led0), gpios)

#define SW0_NODE	DT_ALIAS(sw0)
#if DT_NODE_HAS_STATUS(SW0_NODE, okay)
#define SW0_GPIO_LABEL	DT_GPIO_LABEL(SW0_NODE, gpios)
#define SW0_GPIO_PIN	DT_GPIO_PIN(SW0_NODE, gpios)
#define SW0_GPIO_FLAGS	(GPIO_INPUT | DT_GPIO_FLAGS(SW0_NODE, gpios))
#else
#error "Unsupported board: sw0 devicetree alias is not defined"
#define SW0_GPIO_LABEL	""
#define SW0_GPIO_PIN	0
#define SW0_GPIO_FLAGS	0
#endif

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc); while(1){};}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}

//Zephyr Sensor Part
static double sqrt(double value)
{
	int i;
	double sqrt = value / 3;

	if (value <= 0) {
		return 0;
	}

	for (i = 0; i < 6; i++) {
		sqrt = (sqrt + value / sqrt) / 2;
	}

	return sqrt;
}

K_SEM_DEFINE(sem, 0, 1);

static void trigger_handler(const struct device *dev,
			    struct sensor_trigger *trigger)
{
	ARG_UNUSED(trigger);

	if (sensor_sample_fetch(dev)) {
		printf("sensor_sample_fetch failed\n");
		return;
	}

	k_sem_give(&sem);
}

//MicroROS Sensor Part
rcl_publisher_t tf_publisher;
rcl_publisher_t euler_publisher;
rcl_publisher_t trigger_publisher;

rcl_subscription_t tf_subscriber;
rcl_subscription_t euler_subscriber;
rcl_subscription_t trigger_subscriber;

uint32_t get_millis_from_timespec(struct timespec tv){
	return tv.tv_sec*1000 + tv.tv_nsec/1e6;
}

//Pingpong
#define STRING_BUFFER_LEN 50
rcl_subscription_t ping_subscriber;
rcl_subscription_t pong_subscriber;

rcl_publisher_t ping_publisher;
rcl_publisher_t pong_publisher;

std_msgs__msg__Header incoming_ping;
std_msgs__msg__Header outcoming_ping;
std_msgs__msg__Header incoming_pong;
int pong_count;
int device_id;
int seq_no;

void ping_timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
	(void) last_call_time;

	if (timer != NULL) {

		seq_no = rand();
		sprintf(outcoming_ping.frame_id.data, "%d_%d", seq_no, device_id);
		outcoming_ping.frame_id.size = strlen(outcoming_ping.frame_id.data);
		
		// Fill the message timestamp
		struct timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		outcoming_ping.stamp.sec = ts.tv_sec;
		outcoming_ping.stamp.nanosec = ts.tv_nsec;

		// Reset the pong count and publish the ping message
		pong_count = 0;
		rcl_publish(&ping_publisher, (const void*)&outcoming_ping, NULL);
		printf("Ping send seq %s\n", outcoming_ping.frame_id.data);  
		printf("subscriber generic type test success, %s\n");
	}
}

void ping_subscription_callback(const void * msgin)
{
	const std_msgs__msg__Header * msg = (const std_msgs__msg__Header *)msgin;

	// Dont pong my own pings
	if(strcmp(outcoming_ping.frame_id.data, msg->frame_id.data) != 0){
		printf("Ping received with seq %s. Answering.\n", msg->frame_id.data);
		rcl_publish(&pong_publisher, (const void*)msg, NULL);
		printf("subscriber2 success, %s\n");
	}
}


void pong_subscription_callback(const void * msgin)
{
	const std_msgs__msg__Header * msg = (const std_msgs__msg__Header *)msgin;

	if(strcmp(outcoming_ping.frame_id.data, msg->frame_id.data) == 0) {
			pong_count++;
			printf("Pong for seq %s (%d)\n", msg->frame_id.data, pong_count);
			printf("subscriber3 success, %s\n");
	}
}


void main(void)
{
    struct sensor_value accel[3];
	double mag;
	int i;
	char meter[200];

	//  IMU configuration
	const struct device *imu_sensor = device_get_binding(DT_LABEL(DT_INST(0, adi_adxl372)));

    if (imu_sensor == NULL) {
		printf("Could not get %s device\n", DT_LABEL(DT_INST(0, adi_adxl372)));
		return;
	}
    //Sensor Trigger Part
	struct sensor_trigger trig = {
		.type = SENSOR_TRIG_DATA_READY,
		.chan = SENSOR_CHAN_ACCEL_XYZ,
	};

	//Trigger handler is for calculating g-value
	if (IS_ENABLED(CONFIG_ADXL372_PEAK_DETECT_MODE)) {
		trig.type = SENSOR_TRIG_THRESHOLD;
	}

	if (IS_ENABLED(CONFIG_ADXL372_TRIGGER)) {
		if (sensor_trigger_set(imu_sensor, &trig, trigger_handler)) {
			printf("Could not set trigger\n");
			return;
		}
	}


    //MicroROS Start Work
	//  LED configuration
	//const struct device *led = device_get_binding(DT_GPIO_LABEL(DT_ALIAS(led0), gpios));
	//gpio_pin_configure(led, LED_PIN, GPIO_OUTPUT_ACTIVE | 0);

	struct sensor_value imu_value;
	struct sensor_value accel_xyz[3], gyro_xyz[3], magn_xyz[3];

	//Movelt
	//Error: MICRO_ROS_FRAMING_REQUIRED' undeclared; CMakeList: STREQUAL unknown
	// Set custom transports
	// Set custom transports
	//rmw_uros_set_custom_transport(
	//	MICRO_ROS_FRAMING_REQUIRED,
	//	(void *) &default_params,
	//	zephyr_transport_open,
	//	zephyr_transport_close,
	//	zephyr_transport_write,
	//	zephyr_transport_read
	//);

	imu_value.val1 = 104; // set accel/gyro sampling frequency to 104 Hz
	imu_value.val2 = 0;
  
    gyro_xyz[0].val1 = 10;
	gyro_xyz[1].val1 = 12;
	gyro_xyz[2].val1 = 14;

    gyro_xyz[0].val2 = 11;
	gyro_xyz[1].val2 = 13;
	gyro_xyz[2].val2 = 15;

	magn_xyz[0].val1 = 16;
	magn_xyz[1].val1 = 18;
	magn_xyz[2].val1 = 20;

	magn_xyz[0].val2 = 17;
	magn_xyz[1].val2 = 19;
	magn_xyz[2].val2 = 21;

	//sensor_attr_set(imu_sensor, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY, &imu_value);

    // ---- micro-ROS configuration ----
	rcl_allocator_t allocator = rcl_get_default_allocator();
	rclc_support_t support;

	// create init_options
	RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

	// create node
	rcl_node_t node;
	RCCHECK(rclc_node_init_default(&node, "zephyr_attitude_node", "", &support));

    // Creating IMU publisher
	RCCHECK(rclc_publisher_init_default(&tf_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(tf2_msgs, msg, TFMessage), "/microROS/tf"));
	RCCHECK(rclc_publisher_init_default(&euler_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Vector3), "/microROS/euler"));
	RCCHECK(rclc_publisher_init_default(&trigger_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Empty), "/microROS/trigger_moveit2"));
	
	RCCHECK(rclc_subscription_init_default(&tf_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(tf2_msgs, msg, TFMessage), "/microROS/tf"));
	RCCHECK(rclc_subscription_init_default(&euler_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Vector3), "/microROS/euler"));
	RCCHECK(rclc_subscription_init_default(&trigger_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Empty), "/microROS/trigger_moveit2"));
	

	//pingpong
	// Create a best effort ping subscriber
	RCCHECK(rclc_subscription_init_best_effort(&ping_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Header), "/microROS/ping"));
	RCCHECK(rclc_subscription_init_best_effort(&ping_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Vector3), "/microROS/euler"));

	// Create a best effort  pong subscriber
	RCCHECK(rclc_subscription_init_best_effort(&pong_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Header), "/microROS/pong"));

       // Create a 3 seconds ping timer timer,
	rcl_timer_t timer;
	RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(2000), ping_timer_callback));
   
	// Create executor
	rclc_executor_t executor;
	RCCHECK(rclc_executor_init(&executor, &support.context, 3, &allocator));
	RCCHECK(rclc_executor_add_timer(&executor, &timer));
	RCCHECK(rclc_executor_add_subscription(&executor, &ping_subscriber, &incoming_ping, &ping_subscription_callback, ON_NEW_DATA));
	RCCHECK(rclc_executor_add_subscription(&executor, &pong_subscriber, &incoming_pong, &pong_subscription_callback, ON_NEW_DATA));
 
 	// Create and allocate the pingpong messages

	char outcoming_ping_buffer[STRING_BUFFER_LEN];
	outcoming_ping.frame_id.data = outcoming_ping_buffer;
	outcoming_ping.frame_id.capacity = STRING_BUFFER_LEN;

	char incoming_ping_buffer[STRING_BUFFER_LEN];
	incoming_ping.frame_id.data = incoming_ping_buffer;
	incoming_ping.frame_id.capacity = STRING_BUFFER_LEN;

	char incoming_pong_buffer[STRING_BUFFER_LEN];
	incoming_pong.frame_id.data = incoming_pong_buffer;
	incoming_pong.frame_id.capacity = STRING_BUFFER_LEN;

	device_id = rand();
	
	//Sensor
	// ---- Main loop ----
	//gpio_pin_set(led, LED_PIN, 0);

	sensfusion9Init();

	geometry_msgs__msg__Vector3 eurler_angles;

	geometry_msgs__msg__TransformStamped tf_stamped;

    tf_stamped.header.frame_id.data = (char*)malloc(STR_CAPACITY*sizeof(char));
	char string1[] = "/world";
	memcpy(tf_stamped.header.frame_id.data, string1, strlen(string1) + 1);
	tf_stamped.header.frame_id.size = strlen(tf_stamped.header.frame_id.data);
	tf_stamped.header.frame_id.capacity = STR_CAPACITY;

	char string2[] = "/inertial_unit";
	tf_stamped.child_frame_id.data =  (char*)malloc(STR_CAPACITY*sizeof(char));
	memcpy(tf_stamped.child_frame_id.data, string2, strlen(string2) + 1);
	tf_stamped.child_frame_id.size = strlen(tf_stamped.child_frame_id.data);
	tf_stamped.child_frame_id.capacity = STR_CAPACITY;
	
	tf_stamped.transform.translation.x = 0.3;
	tf_stamped.transform.translation.y = 0;
	tf_stamped.transform.translation.z = 0.3;
	
	tf2_msgs__msg__TFMessage tf_message;
	tf_message.transforms.data = &tf_stamped;
	tf_message.transforms.size = 1;
	tf_message.transforms.capacity = 1;

	struct timespec tv = {0};
	struct timespec tv_end = {0};
	struct timespec tv_debouncing = {0};
	float sample_rate = 0.3;

	uint32_t loop_delay_us = 10000;
   
    while(1)
	{
	    //pingpong
	    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
	    usleep(100000);
		
	    //sensor
	    sensor_sample_fetch(imu_sensor);
	    sensor_channel_get(imu_sensor, SENSOR_CHAN_ACCEL_XYZ, accel_xyz);
		//Pure Zephyr for sensor Start Work
		if (IS_ENABLED(CONFIG_ADXL372_PEAK_DETECT_MODE)) 
		{
			mag = sqrt(pow2(sensor_ms2_to_g(&accel_xyz[0])) +
				pow2(sensor_ms2_to_g(&accel_xyz[1])) +
				pow2(sensor_ms2_to_g(&accel_xyz[2])));

            for (i = 0; i <= mag && i < (sizeof(meter) - 1); i++) 
			{
				meter[i] = '#';
			}
            meter[i] = '\0';

			printf("%6.2f g: %s\n", mag, meter);
		} 
        else 
		{
			printf("AX=%10.2f AY=%10.2f AZ=%10.2f (m/s^2)\n",
				sensor_value_to_double(&accel_xyz[0]),
				sensor_value_to_double(&accel_xyz[1]),
				sensor_value_to_double(&accel_xyz[2])); 
		}

		if (!IS_ENABLED(CONFIG_ADXL372_TRIGGER)) 
		{
			k_sleep(K_MSEC(2000));
		}
	
		//Movelt Start work
        clock_gettime(CLOCK_MONOTONIC, &tv);
        sensfusion9Update((float) (sensor_value_to_double(&gyro_xyz[0])),
						(float) (sensor_value_to_double(&gyro_xyz[1])),
						(float) (sensor_value_to_double(&gyro_xyz[2])),
						(float) sensor_value_to_double(&accel_xyz[0]),
						(float) sensor_value_to_double(&accel_xyz[1]),
						(float) sensor_value_to_double(&accel_xyz[2]),
						(float) (-sensor_value_to_double(&magn_xyz[0])),
						(float) (-sensor_value_to_double(&magn_xyz[1])),
						(float) ( sensor_value_to_double(&magn_xyz[2])),
						sample_rate);
	    float q[4];

	    tf_stamped.transform.rotation.x = (double) q[1];
	    tf_stamped.transform.rotation.y = (double) q[2];
	    tf_stamped.transform.rotation.z = (double) q[3]; 
	    tf_stamped.transform.rotation.w = (double) q[0];

	    float angles[3];
	    sensfusion9GetEulerRPY(angles);

	    eurler_angles.x = angles[0];
	    eurler_angles.y = angles[1];
	    eurler_angles.z = angles[2];

	    tf_stamped.header.stamp.nanosec = tv.tv_nsec;
	    tf_stamped.header.stamp.sec = tv.tv_sec;

	    rcl_publish(&tf_publisher, &tf_message, NULL);
        rcl_publish(&euler_publisher, &eurler_angles, NULL);

        std_msgs__msg__Empty trigger;
	    rcl_publish(&trigger_publisher, &trigger, NULL);
	    tv_debouncing = tv;

        clock_gettime(CLOCK_MONOTONIC, &tv_end);
	    sample_rate = (float) (get_millis_from_timespec(tv_end) - get_millis_from_timespec(tv))/1000;
	}
	//pingpong
	RCCHECK(rcl_subscription_fini(&ping_subscriber, &node));
	RCCHECK(rcl_subscription_fini(&pong_subscriber, &node));
	RCCHECK(rcl_node_fini(&node));
}

