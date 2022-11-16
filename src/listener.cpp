#include "ros/ros.h"
#include "std_msgs/String.h"

void ruangbicaraCallback(const std_msgs::String::ConstPtr& msg)
{
 std::cout << "I Heard You:" << msg->data.c_str() << std::endl;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "listener");
 ros::NodeHandle n;
 ros::Subscriber sub = n.subscribe("ruangbicara", 1000, ruangbicaraCallback);
 ros::spin(); //reponse to ros::spinOnce in publisher
 return 0;
}
