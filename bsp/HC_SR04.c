/* site:https://github.com/daishitong/51lib */

#include "HC_SR04.h"
#include "core\TimeCounter0.h"
#include "core\delay.h"

void HC_SR04_Init()
{
    TimeCounter0_Init();

    Echo_Pin = 1;
}

// distance = v * t / 2 = v * count * 12 * T / 2 = v * count * 12 / f / 2 
// distance = 340 m/s * count * 12 / 11.0592M / 2
//          = 340 m/s * count * 12 / (11.0592 * 1e6) s / 2
//          = count * (340 * 12) / (11059200 * 2) m
//          = count / ((11059200 * 2) / (340 *12)) m
//          = count / 5421.2 m
//          = count / 5421.2 * 1000 mm
//          = count / 5.4212 mm
#define DistancePerCount 5.4212

float HC_SR04_GetDistance()
{
    unsigned short count;

    Echo_Pin = 1;
  
    Trig_Pin = 1;
    delay_nus(10);
    Trig_Pin = 0;

    while(Echo_Pin == 0);
    TimeCounter0_Start();

    while(Echo_Pin == 1);
    TimeCounter0_Stop();

    count = TimeCounter0_CurrentCount();

    return (float)count / DistancePerCount;
}