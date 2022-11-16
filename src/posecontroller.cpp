#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "turtlesim/Pose.h"

class posecontroller{
 public:
  posecontroller(){
   sub = n.subscribe("turtle1/pose", 1000, &posecontroller::callback, this);
   pub = n.advertise<turtlesim::Pose>("turtle1/pose", 1000);
  }
  void callback(const turtlesim::Pose::ConstPtr& msg){
   std_msgs::String pub_str;
   std::stringstream ss;
   ss << "Current position: " << msg->x << ", " << msg->y;
   pub_str.data = ss.str();
   std::cout << pub_str.data.c_str() << std::endl;
   

   if (msg->x >= 11){
   turtlesim::Pose pubMsg;
   pubMsg.x = 0 ;
   pub.publish(pubMsg);
   }
  }
  private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
};

int main(int argc, char **argv){
ros::init(argc, argv, "posecontroller");
posecontroller ctrl;
ros::spin();
}

