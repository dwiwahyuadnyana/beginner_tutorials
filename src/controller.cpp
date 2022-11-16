#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

class controller {
 public:
  controller(){
   sub = n.subscribe("turtle1/pose", 1000,  &controller::callback, this);
   pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
 }
 // Ngambil Posisi Realtime
 void callback(const turtlesim::Pose::ConstPtr& msg){
  std_msgs::String pub_str;
  std::stringstream ss;
  ss << "Current Position: " << "x: " << msg->x << ", " << "y: " << msg->y << ", " << "theta: " << msg->theta;
  pub_str.data = ss.str();
  std::cout << pub_str.data.c_str() << std::endl;
 // Controller
  if (msg->x >= 1){
   geometry_msgs::Twist pubMsg;
   pubMsg.linear.x = 1;
   pub.publish(pubMsg);
   if (msg->x >=10){
    geometry_msgs::Twist pubMsg;
    pubMsg.linear.x = 0;
    pubMsg.angular.z = 0.78;
    pub.publish(pubMsg);
   }
  }
 }
 private:
 ros::NodeHandle n;
 ros::Subscriber sub;
 ros::Publisher pub;
};

int main (int argc, char **argv){
 ros::init(argc, argv, "controller");
 controller ctrl;
 ros::spin();
}
<<<<<<< HEAD

//TEST GITHUB
//TEST GITHUB2
=======
//TEST GITHUB
//test github
//ini test
