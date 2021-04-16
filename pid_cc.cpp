//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pid_cc.cpp
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
#include "pid_cc.h"
#include "pid_cc_private.h"

// Block signals (default storage)
B_pid_cc_T pid_cc_B;

// Continuous states
X_pid_cc_T pid_cc_X;

// Block states (default storage)
DW_pid_cc_T pid_cc_DW;

// Real-time model
RT_MODEL_pid_cc_T pid_cc_M_ = RT_MODEL_pid_cc_T();
RT_MODEL_pid_cc_T *const pid_cc_M = &pid_cc_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  pid_cc_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  pid_cc_step();
  pid_cc_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  pid_cc_step();
  pid_cc_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void pid_cc_step(void)
{
  SL_Bus_pid_cc_std_msgs_Float64 b_varargout_2;
  SL_Bus_pid_cc_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_IntegralGain;
  real_T rtb_SignPreSat;
  real_T rtb_ZeroGain;
  real_T tmp;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(pid_cc_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&pid_cc_M->solverInfo,((pid_cc_M->Timing.clockTick0+1)*
      pid_cc_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(pid_cc_M)) {
    pid_cc_M->Timing.t[0] = rtsiGetT(&pid_cc_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(pid_cc_M)) {
    // Outputs for Atomic SubSystem: '<Root>/ref_speed'
    // MATLABSystem: '<S5>/SourceBlock' incorporates:
    //   Inport: '<S57>/In1'

    b_varargout_1 = Sub_pid_cc_26.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S57>/Enable'

    if (b_varargout_1) {
      pid_cc_B.In1_p = b_varargout_2;
    }

    // End of MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/ref_speed'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S4>/SourceBlock' incorporates:
    //   Inport: '<S56>/In1'

    b_varargout_1 = Sub_pid_cc_10.getLatestMessage(&pid_cc_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S56>/Enable'

    if (b_varargout_1) {
      pid_cc_B.In1 = pid_cc_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Sum: '<Root>/Sum'
    rtb_IntegralGain = pid_cc_B.In1_p.Data - pid_cc_B.In1.Twist.Linear.X;

    // Gain: '<S44>/Proportional Gain'
    pid_cc_B.ProportionalGain = pid_cc_P.PIDController_P * rtb_IntegralGain;

    // Gain: '<S33>/Derivative Gain'
    pid_cc_B.DerivativeGain = pid_cc_P.PIDController_D * rtb_IntegralGain;
  }

  // Gain: '<S42>/Filter Coefficient' incorporates:
  //   Integrator: '<S34>/Filter'
  //   Sum: '<S34>/SumD'

  pid_cc_B.FilterCoefficient = (pid_cc_B.DerivativeGain - pid_cc_X.Filter_CSTATE)
    * pid_cc_P.PIDController_N;

  // Sum: '<S48>/Sum' incorporates:
  //   Integrator: '<S39>/Integrator'

  rtb_SignPreSat = (pid_cc_B.ProportionalGain + pid_cc_X.Integrator_CSTATE) +
    pid_cc_B.FilterCoefficient;

  // Saturate: '<S46>/Saturation'
  if (rtb_SignPreSat > pid_cc_P.PIDController_UpperSaturationLi) {
    rtb_ZeroGain = pid_cc_P.PIDController_UpperSaturationLi;
  } else if (rtb_SignPreSat < pid_cc_P.PIDController_LowerSaturationLi) {
    rtb_ZeroGain = pid_cc_P.PIDController_LowerSaturationLi;
  } else {
    rtb_ZeroGain = rtb_SignPreSat;
  }

  // End of Saturate: '<S46>/Saturation'

  // Saturate: '<Root>/Saturation'
  if (rtb_ZeroGain > pid_cc_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = pid_cc_P.Saturation_UpperSat;
  } else if (rtb_ZeroGain < pid_cc_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = pid_cc_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = rtb_ZeroGain;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_pid_cc_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Gain: '<S30>/ZeroGain'
  rtb_ZeroGain = pid_cc_P.ZeroGain_Gain * rtb_SignPreSat;

  // DeadZone: '<S32>/DeadZone'
  if (rtb_SignPreSat > pid_cc_P.PIDController_UpperSaturationLi) {
    rtb_SignPreSat -= pid_cc_P.PIDController_UpperSaturationLi;
  } else if (rtb_SignPreSat >= pid_cc_P.PIDController_LowerSaturationLi) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -= pid_cc_P.PIDController_LowerSaturationLi;
  }

  // End of DeadZone: '<S32>/DeadZone'
  if (rtmIsMajorTimeStep(pid_cc_M)) {
    // Gain: '<S36>/Integral Gain'
    rtb_IntegralGain *= pid_cc_P.PIDController_I;

    // Signum: '<S30>/SignPreIntegrator'
    if (rtb_IntegralGain < 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = -1.0;
    } else if (rtb_IntegralGain > 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = 1.0;
    } else if (rtb_IntegralGain == 0.0) {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = 0.0;
    } else {
      // DataTypeConversion: '<S30>/DataTypeConv2'
      tmp = (rtNaN);
    }

    // End of Signum: '<S30>/SignPreIntegrator'

    // DataTypeConversion: '<S30>/DataTypeConv2'
    if (rtIsNaN(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    // DataTypeConversion: '<S30>/DataTypeConv2'
    pid_cc_B.DataTypeConv2 = static_cast<int8_T>(tmp < 0.0 ? static_cast<int32_T>
      (static_cast<int8_T>(-static_cast<int8_T>(static_cast<uint8_T>(-tmp)))) :
      static_cast<int32_T>(static_cast<int8_T>(static_cast<uint8_T>(tmp))));
  }

  // Signum: '<S30>/SignPreSat'
  if (rtb_SignPreSat < 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = -1.0;
  } else if (rtb_SignPreSat > 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = 1.0;
  } else if (rtb_SignPreSat == 0.0) {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = 0.0;
  } else {
    // DataTypeConversion: '<S30>/DataTypeConv1'
    tmp = (rtNaN);
  }

  // End of Signum: '<S30>/SignPreSat'

  // DataTypeConversion: '<S30>/DataTypeConv1'
  if (rtIsNaN(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  // Logic: '<S30>/AND3' incorporates:
  //   DataTypeConversion: '<S30>/DataTypeConv1'
  //   RelationalOperator: '<S30>/Equal1'
  //   RelationalOperator: '<S30>/NotEqual'

  pid_cc_B.AND3 = ((rtb_ZeroGain != rtb_SignPreSat) && ((tmp < 0.0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-tmp)))) : static_cast<int32_T>(static_cast<int8_T>(
    static_cast<uint8_T>(tmp)))) == pid_cc_B.DataTypeConv2));
  if (rtmIsMajorTimeStep(pid_cc_M)) {
    // Switch: '<S30>/Switch' incorporates:
    //   Memory: '<S30>/Memory'

    if (pid_cc_DW.Memory_PreviousInput) {
      // Switch: '<S30>/Switch' incorporates:
      //   Constant: '<S30>/Constant1'

      pid_cc_B.Switch = pid_cc_P.Constant1_Value;
    } else {
      // Switch: '<S30>/Switch'
      pid_cc_B.Switch = rtb_IntegralGain;
    }

    // End of Switch: '<S30>/Switch'
  }

  if (rtmIsMajorTimeStep(pid_cc_M)) {
    if (rtmIsMajorTimeStep(pid_cc_M)) {
      // Update for Memory: '<S30>/Memory'
      pid_cc_DW.Memory_PreviousInput = pid_cc_B.AND3;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(pid_cc_M)) {
    rt_ertODEUpdateContinuousStates(&pid_cc_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++pid_cc_M->Timing.clockTick0;
    pid_cc_M->Timing.t[0] = rtsiGetSolverStopTime(&pid_cc_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.036s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.036, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      pid_cc_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void pid_cc_derivatives(void)
{
  XDot_pid_cc_T *_rtXdot;
  _rtXdot = ((XDot_pid_cc_T *) pid_cc_M->derivs);

  // Derivatives for Integrator: '<S39>/Integrator'
  _rtXdot->Integrator_CSTATE = pid_cc_B.Switch;

  // Derivatives for Integrator: '<S34>/Filter'
  _rtXdot->Filter_CSTATE = pid_cc_B.FilterCoefficient;
}

// Model initialize function
void pid_cc_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&pid_cc_M->solverInfo, &pid_cc_M->Timing.simTimeStep);
    rtsiSetTPtr(&pid_cc_M->solverInfo, &rtmGetTPtr(pid_cc_M));
    rtsiSetStepSizePtr(&pid_cc_M->solverInfo, &pid_cc_M->Timing.stepSize0);
    rtsiSetdXPtr(&pid_cc_M->solverInfo, &pid_cc_M->derivs);
    rtsiSetContStatesPtr(&pid_cc_M->solverInfo, (real_T **)
                         &pid_cc_M->contStates);
    rtsiSetNumContStatesPtr(&pid_cc_M->solverInfo,
      &pid_cc_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&pid_cc_M->solverInfo,
      &pid_cc_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&pid_cc_M->solverInfo,
      &pid_cc_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&pid_cc_M->solverInfo,
      &pid_cc_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&pid_cc_M->solverInfo, (&rtmGetErrorStatus(pid_cc_M)));
    rtsiSetRTModelPtr(&pid_cc_M->solverInfo, pid_cc_M);
  }

  rtsiSetSimTimeStep(&pid_cc_M->solverInfo, MAJOR_TIME_STEP);
  pid_cc_M->intgData.y = pid_cc_M->odeY;
  pid_cc_M->intgData.f[0] = pid_cc_M->odeF[0];
  pid_cc_M->intgData.f[1] = pid_cc_M->odeF[1];
  pid_cc_M->intgData.f[2] = pid_cc_M->odeF[2];
  pid_cc_M->contStates = ((X_pid_cc_T *) &pid_cc_X);
  rtsiSetSolverData(&pid_cc_M->solverInfo, static_cast<void *>
                    (&pid_cc_M->intgData));
  rtsiSetSolverName(&pid_cc_M->solverInfo,"ode3");
  rtmSetTPtr(pid_cc_M, &pid_cc_M->Timing.tArray[0]);
  pid_cc_M->Timing.stepSize0 = 0.036;

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[13];
    char_T b_zeroDelimTopic[11];
    static const char_T tmp[10] = { '/', 'r', 'e', 'f', '_', 's', 'p', 'e', 'e',
      'd' };

    static const char_T tmp_0[12] = { '/', 'v', 'e', 'h', 'i', 'c', 'l', 'e',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_1[12] = { '/', 't', 'i', 'm', 'e', 'd', '_', 'a',
      'c', 'c', 'e', 'l' };

    // InitializeConditions for Integrator: '<S39>/Integrator'
    pid_cc_X.Integrator_CSTATE = pid_cc_P.PIDController_InitialConditio_o;

    // InitializeConditions for Integrator: '<S34>/Filter'
    pid_cc_X.Filter_CSTATE = pid_cc_P.PIDController_InitialConditionF;

    // InitializeConditions for Memory: '<S30>/Memory'
    pid_cc_DW.Memory_PreviousInput = pid_cc_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/ref_speed'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S57>/Out1' incorporates:
    //   Inport: '<S57>/In1'

    pid_cc_B.In1_p = pid_cc_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    pid_cc_DW.obj_h.matlabCodegenIsDeleted = false;
    pid_cc_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[10] = '\x00';
    Sub_pid_cc_26.createSubscriber(&b_zeroDelimTopic[0], 1);
    pid_cc_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/ref_speed'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S56>/Out1' incorporates:
    //   Inport: '<S56>/In1'

    pid_cc_B.In1 = pid_cc_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    pid_cc_DW.obj_n.matlabCodegenIsDeleted = false;
    pid_cc_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Sub_pid_cc_10.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    pid_cc_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    pid_cc_DW.obj.matlabCodegenIsDeleted = false;
    pid_cc_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_0[i] = tmp_1[i];
    }

    b_zeroDelimTopic_0[12] = '\x00';
    Pub_pid_cc_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    pid_cc_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void pid_cc_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/ref_speed'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!pid_cc_DW.obj_h.matlabCodegenIsDeleted) {
    pid_cc_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/ref_speed'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!pid_cc_DW.obj_n.matlabCodegenIsDeleted) {
    pid_cc_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!pid_cc_DW.obj.matlabCodegenIsDeleted) {
    pid_cc_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
