/* site:https://github.com/daishitong/51lib */

#include "delay_nop.h"

void delay_5nop()
{
    
}

#include <intrins.h>
void delay_100nop()
{
    char i;
    for(i = 0;i < 10;i++)
    {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}