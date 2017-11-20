/* site:https://github.com/daishitong/51lib */

#include "ExternalInterrupt0.h"
#include <reg52.h>

sbit ExternalInterrupt0_Pin = P3^2;

void ExternalInterrupt0_Init()
{
    IT0 = 1;    // 0:low level active 1:falling edge active
    IE0 = 0;	// Interrupt 0 Edge Flag.
    ExternalInterrupt0_Pin = 1;
}

void ExternalInterrupt0_Reset()
{
    IE0 = 0;	// clear Interrupt 0 Edge Flag
}

void ExternalInterrupt0_WaitHighLevel()
{
    while(ExternalInterrupt0_Pin == 0);	// wait high level
}

void ExternalInterrupt0_WaitFallingEdge()
{
    while(!IE0);// wait external Interrupt is detected
}
