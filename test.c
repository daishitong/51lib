/* site:https://github.com/daishitong/51lib */

#include "51lib.h"

void main()
{
    Timer2_PWM_Init();
    Timer2_PWM(1500,20000);
    
    while(1)
    {
        delay_nms(25);
    }
}