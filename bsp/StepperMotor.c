/* site:https://github.com/daishitong/51lib */

#include "StepperMotor.h"
#include "core\delay.h"

const char code CONST_STEP_DATA[8] = {0x1,0x3,0x2,0x6,0x4,0xc,0x8,0x9};  
void StepperMotor_SetStepData(char stepData)
{
    SET_STEPPERMOTOR_PORT(stepData);
    delay_nms(STEPPERMOTOR_STEPTIME);
}

void StepperMotor_Run_CW()
{
    char i;
    for(i = 0;i < 8;i++)
    {
        StepperMotor_SetStepData(CONST_STEP_DATA[i]);
    }
}

void StepperMotor_Run_CCW()
{
    char i;
    for(i = 7;i >= 0;i--)
    {
        StepperMotor_SetStepData(CONST_STEP_DATA[i]);
    }
}
