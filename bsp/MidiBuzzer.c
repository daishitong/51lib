/* site:https://github.com/daishitong/51lib */

#include "MidiBuzzer.h"
#include "core\T2_delay.h"
#include "core\Timer.h"

#define HalfUsPerSecond 500000

#define ToneFrequent_L_1Do 262
#define ToneFrequent_L_2Re 294
#define ToneFrequent_L_3Mi 330
#define ToneFrequent_L_4Fa 349
#define ToneFrequent_L_5So 392
#define ToneFrequent_L_6La 440
#define ToneFrequent_L_7Xi 494
#define ToneFrequent_M_1Do 523
#define ToneFrequent_M_2Re 587
#define ToneFrequent_M_3Mi 659
#define ToneFrequent_M_4Fa 698
#define ToneFrequent_M_5So 784
#define ToneFrequent_M_6La 880
#define ToneFrequent_M_7Xi 988
#define ToneFrequent_H_1Do 1046
#define ToneFrequent_H_2Re 1175
#define ToneFrequent_H_3Mi 1318
#define ToneFrequent_H_4Fa 1397
#define ToneFrequent_H_5So 1568
#define ToneFrequent_H_6La 1760
#define ToneFrequent_H_7Xi 1967
#define ToneFrequent_0Zero 0

#define SET_BUZZER_ON()     (MidiBuzzer_Pin = 0)
#define SET_BUZZER_OFF()    (MidiBuzzer_Pin = 1)

const unsigned short code ToneFrequent[]=
{
    ToneFrequent_L_1Do,
    ToneFrequent_L_2Re,
    ToneFrequent_L_3Mi,
    ToneFrequent_L_4Fa,
    ToneFrequent_L_5So,
    ToneFrequent_L_6La,
    ToneFrequent_L_7Xi,
    ToneFrequent_M_1Do,
    ToneFrequent_M_2Re,
    ToneFrequent_M_3Mi,
    ToneFrequent_M_4Fa,
    ToneFrequent_M_5So,
    ToneFrequent_M_6La,
    ToneFrequent_M_7Xi,
    ToneFrequent_H_1Do,
    ToneFrequent_H_2Re,
    ToneFrequent_H_3Mi,
    ToneFrequent_H_4Fa,
    ToneFrequent_H_5So,
    ToneFrequent_H_6La,
    ToneFrequent_H_7Xi,
};

const unsigned short code BuzzerHalfPeriodCount[]=
{
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_1Do),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_2Re),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_3Mi),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_4Fa),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_5So),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_6La),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_L_7Xi),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_1Do),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_2Re),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_3Mi),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_4Fa),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_5So),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_6La),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_M_7Xi),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_1Do),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_2Re),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_3Mi),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_4Fa),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_5So),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_6La),
    TIMER_US2COUNT(HalfUsPerSecond / ToneFrequent_H_7Xi),
};

void MidiBuzzer_Init(void)
{
    T2Delay_Init();
    SET_BUZZER_OFF();
}

void MidiBuzzer_SquarePluse(short half_count)
{
  SET_BUZZER_ON();
  T2Delay_DelayCount(half_count);
  SET_BUZZER_OFF();
  T2Delay_DelayCount(half_count);  
}

bool MidiBuzzer_Ring(MidiSegment midi)
{
  short halfPeriodCount,count,i;

  if(midi.time == BeatTime_End)
    return false;
 
  if(midi.tone != BuzzerTone_0Zero)
  {
    halfPeriodCount = BuzzerHalfPeriodCount[midi.tone];
    count = HALF_NUM(midi.time * ToneFrequent[midi.tone]);
    for(i = 0;i < count;i++)
    {
      MidiBuzzer_SquarePluse(halfPeriodCount); 
    }  
  }  
  else
  {
    halfPeriodCount = TIMER_US2COUNT(50000);
    count = midi.time * 10;
    for(i = 0;i < count;i++)
    {
      T2Delay_DelayCount(halfPeriodCount);
    } 
  }

  return true;
}

void MidiBuzzer_Sing(MidiSegment song[])
{
  short index = 0;
  while(MidiBuzzer_Ring(song[index++]));
}