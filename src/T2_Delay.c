/* site:https://github.com/daishitong/51lib */

#include <reg52.h>
#include "T2_Delay.h"
#include "Timer.h"

void T2Delay_Init()
{
    C_T2 = 0;
    
    TR2 = 0;
}

void T2Delay_DelayCount(unsigned short nCount)
{
    TH2 = nCount >> 8;
    TL2 = nCount & 0xff;
    
    TR2 = 1;

    while(TF2 == 0);
    TF2 = 0;
    
    TR2 = 0;
}

void T2Delay_DelayTicks(unsigned short nTicks)
{
    T2Delay_DelayCount(TIMER_TICKS2COUNT(nTicks));
}

void T2Delay_DelayUS(unsigned short us)
{
    T2Delay_DelayCount(TIMER_US2COUNT(us));
}
