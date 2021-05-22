#include <ros.h>
#include <std_msgs/Float32.h>
#define red_led 3
#define yellow_led 9
#define green_led 12

ros::NodeHandle nh;

std_msgs::Float32 red_led_msg;
std_msgs::Float32 yellow_led_msg;
std_msgs::Float32 green_led_msg;

void red_led_Callback(const std_msgs::Float32& red_led_msg) {
  if (red_led_msg.data  == 1.0) {
    digitalWrite(red_led, HIGH);
    delay(500);
    digitalWrite(red_led, LOW);
    delay(500); 
  } else {
    digitalWrite(red_led, LOW);
  }
}
void yellow_led_Callback(const std_msgs::Float32& yellow_led_msg) {
  if (yellow_led_msg.data  == 1.0) {
    digitalWrite(yellow_led, HIGH);
    delay(500);
    digitalWrite(yellow_led, LOW); 
    delay(500);
  } else {
    digitalWrite(yellow_led, LOW);
  }
}
void green_led_Callback(const std_msgs::Float32& msg) {
  
  digitalWrite(green_led, HIGH);
  if (msg.data  == 1) {
    digitalWrite(green_led, HIGH);
    
  } else {
    digitalWrite(green_led, LOW);
  }
}
ros::Subscriber<std_msgs::Float32> red_led_subscriber("toggle_red_led",&red_led_Callback);
ros::Subscriber<std_msgs::Float32> yellow_led_subscriber("toggle_yellow_led",&yellow_led_Callback);
ros::Subscriber<std_msgs::Float32> green_led_subscriber("toggle_green_led",green_led_Callback);

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  
  nh.initNode();
  nh.subscribe(red_led_subscriber);
  nh.subscribe(yellow_led_subscriber);
  nh.subscribe(green_led_subscriber);
}

void loop()
{ 
  Serial.print("Hello world.");
  nh.spinOnce();
}
