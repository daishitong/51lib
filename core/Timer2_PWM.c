/* site:https://github.com/daishitong/51lib */

#include "Timer2_PWM.h"
#include "Timer2.h"

typedef enum
{
    PWM_LEVEL_HIGH,
    PWM_LEVEL_LOW
}PWM_LEVEL;

PWM_LEVEL _pwm_level = PWM_LEVEL_HIGH;
ushort _high_count,_low_count;
void Timer2_PWM_Handler()
{
    if(_pwm_level == PWM_LEVEL_HIGH)
    {
        Timer_PWM_Pin = 1;
        Timer2_SetCounterOut(_high_count);
        _pwm_level = PWM_LEVEL_LOW;
    }
    else
    {
        Timer_PWM_Pin = 0;
        Timer2_SetCounterOut(_low_count);
        _pwm_level = PWM_LEVEL_HIGH;
    }
}

void Timer2_PWM_Init()
{
    Timer2_Init(Timer2_PWM_Handler);
}

void Timer2_PWM(ushort high_us,ushort low_us)
{
    Timer2_Stop();

    _high_count = TIMER_US2COUNT(high_us);
    _low_count = TIMER_US2COUNT(low_us);

    Timer2_PWM_Handler();
}