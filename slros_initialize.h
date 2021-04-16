#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block pid_cc/Subscribe
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_pid_cc_geometry_msgs_TwistStamped> Sub_pid_cc_10;

// For Block pid_cc/ref_speed
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_pid_cc_std_msgs_Float64> Sub_pid_cc_26;

// For Block pid_cc/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_pid_cc_std_msgs_Float64> Pub_pid_cc_3;

void slros_node_init(int argc, char** argv);

#endif
