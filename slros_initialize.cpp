#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "pid_cc";

// For Block pid_cc/Subscribe
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_pid_cc_geometry_msgs_TwistStamped> Sub_pid_cc_10;

// For Block pid_cc/ref_speed
SimulinkSubscriber<std_msgs::Float64, SL_Bus_pid_cc_std_msgs_Float64> Sub_pid_cc_26;

// For Block pid_cc/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_pid_cc_std_msgs_Float64> Pub_pid_cc_3;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

