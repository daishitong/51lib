#include "Calcalation.h"

void GetMinMax_short(short a,short b,short* min,short* max)
{
    if(a < b)
    {
        *min = a;
        *max = b;
    }
    else
    {
        *min = b;
        *max = a;
    }
}