//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pid_cc.h
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
#ifndef RTW_HEADER_pid_cc_h_
#define RTW_HEADER_pid_cc_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "pid_cc_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals (default storage)
struct B_pid_cc_T {
  SL_Bus_pid_cc_geometry_msgs_TwistStamped In1;// '<S56>/In1'
  SL_Bus_pid_cc_geometry_msgs_TwistStamped b_varargout_2;
  real_T ProportionalGain;             // '<S44>/Proportional Gain'
  real_T DerivativeGain;               // '<S33>/Derivative Gain'
  real_T FilterCoefficient;            // '<S42>/Filter Coefficient'
  real_T Switch;                       // '<S30>/Switch'
  SL_Bus_pid_cc_std_msgs_Float64 In1_p;// '<S57>/In1'
  int8_T DataTypeConv2;                // '<S30>/DataTypeConv2'
  boolean_T AND3;                      // '<S30>/AND3'
};

// Block states (default storage) for system '<Root>'
struct DW_pid_cc_T {
  ros_slroscpp_internal_block_P_T obj; // '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_h;// '<S5>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_n;// '<S4>/SourceBlock'
  boolean_T Memory_PreviousInput;      // '<S30>/Memory'
};

// Continuous states (default storage)
struct X_pid_cc_T {
  real_T Integrator_CSTATE;            // '<S39>/Integrator'
  real_T Filter_CSTATE;                // '<S34>/Filter'
};

// State derivatives (default storage)
struct XDot_pid_cc_T {
  real_T Integrator_CSTATE;            // '<S39>/Integrator'
  real_T Filter_CSTATE;                // '<S34>/Filter'
};

// State disabled
struct XDis_pid_cc_T {
  boolean_T Integrator_CSTATE;         // '<S39>/Integrator'
  boolean_T Filter_CSTATE;             // '<S34>/Filter'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_pid_cc_T_ {
  real_T PIDController_D;              // Mask Parameter: PIDController_D
                                          //  Referenced by: '<S33>/Derivative Gain'

  real_T PIDController_I;              // Mask Parameter: PIDController_I
                                          //  Referenced by: '<S36>/Integral Gain'

  real_T PIDController_InitialConditionF;
                              // Mask Parameter: PIDController_InitialConditionF
                                 //  Referenced by: '<S34>/Filter'

  real_T PIDController_InitialConditio_o;
                              // Mask Parameter: PIDController_InitialConditio_o
                                 //  Referenced by: '<S39>/Integrator'

  real_T PIDController_LowerSaturationLi;
                              // Mask Parameter: PIDController_LowerSaturationLi
                                 //  Referenced by:
                                 //    '<S46>/Saturation'
                                 //    '<S32>/DeadZone'

  real_T PIDController_N;              // Mask Parameter: PIDController_N
                                          //  Referenced by: '<S42>/Filter Coefficient'

  real_T PIDController_P;              // Mask Parameter: PIDController_P
                                          //  Referenced by: '<S44>/Proportional Gain'

  real_T PIDController_UpperSaturationLi;
                              // Mask Parameter: PIDController_UpperSaturationLi
                                 //  Referenced by:
                                 //    '<S46>/Saturation'
                                 //    '<S32>/DeadZone'

  SL_Bus_pid_cc_geometry_msgs_TwistStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                      //  Referenced by: '<S56>/Out1'

  SL_Bus_pid_cc_geometry_msgs_TwistStamped Constant_Value;// Computed Parameter: Constant_Value
                                                             //  Referenced by: '<S4>/Constant'

  SL_Bus_pid_cc_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                     //  Referenced by: '<S1>/Constant'

  SL_Bus_pid_cc_std_msgs_Float64 Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                              //  Referenced by: '<S57>/Out1'

  SL_Bus_pid_cc_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                     //  Referenced by: '<S5>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S30>/Constant1'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T ZeroGain_Gain;                // Expression: 0
                                          //  Referenced by: '<S30>/ZeroGain'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S30>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_pid_cc_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_pid_cc_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_pid_cc_T pid_cc_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_pid_cc_T pid_cc_B;

#ifdef __cplusplus

}
#endif

// Continuous states (default storage)
extern X_pid_cc_T pid_cc_X;

// Block states (default storage)
extern struct DW_pid_cc_T pid_cc_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void pid_cc_initialize(void);
  extern void pid_cc_step(void);
  extern void pid_cc_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_pid_cc_T *const pid_cc_M;

#ifdef __cplusplus

}
#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'pid_cc'
//  '<S1>'   : 'pid_cc/Blank Message'
//  '<S2>'   : 'pid_cc/PID Controller'
//  '<S3>'   : 'pid_cc/Publish'
//  '<S4>'   : 'pid_cc/Subscribe'
//  '<S5>'   : 'pid_cc/ref_speed'
//  '<S6>'   : 'pid_cc/PID Controller/Anti-windup'
//  '<S7>'   : 'pid_cc/PID Controller/D Gain'
//  '<S8>'   : 'pid_cc/PID Controller/Filter'
//  '<S9>'   : 'pid_cc/PID Controller/Filter ICs'
//  '<S10>'  : 'pid_cc/PID Controller/I Gain'
//  '<S11>'  : 'pid_cc/PID Controller/Ideal P Gain'
//  '<S12>'  : 'pid_cc/PID Controller/Ideal P Gain Fdbk'
//  '<S13>'  : 'pid_cc/PID Controller/Integrator'
//  '<S14>'  : 'pid_cc/PID Controller/Integrator ICs'
//  '<S15>'  : 'pid_cc/PID Controller/N Copy'
//  '<S16>'  : 'pid_cc/PID Controller/N Gain'
//  '<S17>'  : 'pid_cc/PID Controller/P Copy'
//  '<S18>'  : 'pid_cc/PID Controller/Parallel P Gain'
//  '<S19>'  : 'pid_cc/PID Controller/Reset Signal'
//  '<S20>'  : 'pid_cc/PID Controller/Saturation'
//  '<S21>'  : 'pid_cc/PID Controller/Saturation Fdbk'
//  '<S22>'  : 'pid_cc/PID Controller/Sum'
//  '<S23>'  : 'pid_cc/PID Controller/Sum Fdbk'
//  '<S24>'  : 'pid_cc/PID Controller/Tracking Mode'
//  '<S25>'  : 'pid_cc/PID Controller/Tracking Mode Sum'
//  '<S26>'  : 'pid_cc/PID Controller/Tsamp - Integral'
//  '<S27>'  : 'pid_cc/PID Controller/Tsamp - Ngain'
//  '<S28>'  : 'pid_cc/PID Controller/postSat Signal'
//  '<S29>'  : 'pid_cc/PID Controller/preSat Signal'
//  '<S30>'  : 'pid_cc/PID Controller/Anti-windup/Cont. Clamping Parallel'
//  '<S31>'  : 'pid_cc/PID Controller/Anti-windup/Cont. Clamping Parallel/Dead Zone'
//  '<S32>'  : 'pid_cc/PID Controller/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
//  '<S33>'  : 'pid_cc/PID Controller/D Gain/Internal Parameters'
//  '<S34>'  : 'pid_cc/PID Controller/Filter/Cont. Filter'
//  '<S35>'  : 'pid_cc/PID Controller/Filter ICs/Internal IC - Filter'
//  '<S36>'  : 'pid_cc/PID Controller/I Gain/Internal Parameters'
//  '<S37>'  : 'pid_cc/PID Controller/Ideal P Gain/Passthrough'
//  '<S38>'  : 'pid_cc/PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S39>'  : 'pid_cc/PID Controller/Integrator/Continuous'
//  '<S40>'  : 'pid_cc/PID Controller/Integrator ICs/Internal IC'
//  '<S41>'  : 'pid_cc/PID Controller/N Copy/Disabled'
//  '<S42>'  : 'pid_cc/PID Controller/N Gain/Internal Parameters'
//  '<S43>'  : 'pid_cc/PID Controller/P Copy/Disabled'
//  '<S44>'  : 'pid_cc/PID Controller/Parallel P Gain/Internal Parameters'
//  '<S45>'  : 'pid_cc/PID Controller/Reset Signal/Disabled'
//  '<S46>'  : 'pid_cc/PID Controller/Saturation/Enabled'
//  '<S47>'  : 'pid_cc/PID Controller/Saturation Fdbk/Disabled'
//  '<S48>'  : 'pid_cc/PID Controller/Sum/Sum_PID'
//  '<S49>'  : 'pid_cc/PID Controller/Sum Fdbk/Disabled'
//  '<S50>'  : 'pid_cc/PID Controller/Tracking Mode/Disabled'
//  '<S51>'  : 'pid_cc/PID Controller/Tracking Mode Sum/Passthrough'
//  '<S52>'  : 'pid_cc/PID Controller/Tsamp - Integral/Passthrough'
//  '<S53>'  : 'pid_cc/PID Controller/Tsamp - Ngain/Passthrough'
//  '<S54>'  : 'pid_cc/PID Controller/postSat Signal/Forward_Path'
//  '<S55>'  : 'pid_cc/PID Controller/preSat Signal/Forward_Path'
//  '<S56>'  : 'pid_cc/Subscribe/Enabled Subsystem'
//  '<S57>'  : 'pid_cc/ref_speed/Enabled Subsystem'

#endif                                 // RTW_HEADER_pid_cc_h_

//
// File trailer for generated code.
//
// [EOF]
//
