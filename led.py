#!/usr/bin/env python
import rospy
from std_msgs.msg import Float32
#initializing node and subscribing and publishing
rospy.init_node('led_testing')
# Publisher for LED
red_led = rospy.Publisher('toggle_red_led',Float32,queue_size=10)
yellow_led = rospy.Publisher('toggle_yellow_led',Float32,queue_size=10)
green_led = rospy.Publisher('toggle_green_led',Float32,queue_size=10)

rate = rospy.Rate(100)
while not rospy.is_shutdown():
    green_data_led = 1 ## 1 ON 0 OFF
    green_led.publish(green_data_led)
    
    yellow_data_led = 1 ## 1 ON 0 OFF
    yellow_led.publish(yellow_data_led)

    red_data_led = 1 ## 1 ON 0 OFF
    red_led.publish(red_data_led)
    rate.sleep()
rospy.spin()