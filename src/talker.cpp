#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream> //generating messages

int main(int argc, char **argv)
{
 ros::init(argc, argv, "talker"); //ros master-init name node inisiation
 ros::NodeHandle n; //nodehandle sebagai n
 ros::Publisher ruangbicara_pub = n.advertise<std_msgs::String>("ruangbicara", 1000); //nama topic = chatter
 ros::Rate loop_rate(10);
 int count = 0;
 while (ros::ok())
  {
   std_msgs::String msg;
   std::stringstream ss;
   ss << "Hello World" << count;
   msg.data = ss.str();
   std::cout << msg.data.c_str() << std::endl;
   ruangbicara_pub.publish(msg);
   ros::spinOnce();
   loop_rate.sleep();
   ++count;
   }
 return 0;
}
