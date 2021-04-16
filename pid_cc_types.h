//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pid_cc_types.h
//
// Code generated for Simulink model 'pid_cc'.
//
// Model version                  : 1.24
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Apr 16 15:33:34 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_pid_cc_types_h_
#define RTW_HEADER_pid_cc_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_pid_cc_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_ros_time_Time_

// MsgType=ros_time/Time
struct SL_Bus_pid_cc_ros_time_Time
{
  real_T Sec;
  real_T Nsec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_pid_cc_std_msgs_Header
{
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_pid_cc_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_pid_cc_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_pid_cc_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_pid_cc_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_pid_cc_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_geometry_msgs_TwistStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_pid_cc_geometry_msgs_TwistStamped_

// MsgType=geometry_msgs/TwistStamped
struct SL_Bus_pid_cc_geometry_msgs_TwistStamped
{
  // MsgType=std_msgs/Header
  SL_Bus_pid_cc_std_msgs_Header Header;

  // MsgType=geometry_msgs/Twist
  SL_Bus_pid_cc_geometry_msgs_Twist Twist;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_pid_cc_T_ P_pid_cc_T;

// Forward declaration for rtModel
typedef struct tag_RTM_pid_cc_T RT_MODEL_pid_cc_T;

#endif                                 // RTW_HEADER_pid_cc_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
