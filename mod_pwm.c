 /* ------------------------------------------------------------------- */
 /** @file mod_pwm.c
  * @brief PWM configuration and access module (code)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_pwm.c,v 1.1 2013/09/03 14:42:45 rpy Exp $
  *
  * @verbatim
  * -------------------------------------------------------------------
  * Date     B/F Who Comment
  * ------------------------------------------------------------------- 
  * 13/06/15 (F) RPY initial version
  * 13/06/26 (F) RPY fixed PWM scheduling alog. C&P error for CH3 
  * -------------------------------------------------------------------
  * @endverbatim
  * 
  *
  * @creator      RPY
  * @created      2013/06/15
  * 
  * @project      521.31
  * @requested    -
  * @inspector    - 
  * @verification -
  * @version      $Revision: 1.1 $
  * 
  * 
  * $State: Exp $   
  * $Author: rpy $
  * $Date: 2013/09/03 14:42:45 $

  * $Locker:  $
  * $Url:   $
  *
  * Additional markers:
  *
  *
  *
  */

#include "api.h"
#include "mod_pwm.h"
#include "mod_adc.h"

//################################################################################
// PWM

static pwm_CounterType pwm_Start[PWM_CHANNELS];  // Storage for start time

static pwm_CounterType pwm_OnPhase[PWM_CHANNELS];  // Storage for on-phase durations

static pwm_CounterType pwm_OnSample[PWM_CHANNELS]; // Sampling trigger point for on-phase values (typically in the middle of phase)
                                                   // set to PWM_NO_SAMPE if channel has too-short or no on-phase at all

static pwm_CounterType pwm_OffSample[PWM_CHANNELS]; // Sampling trigger point for off-phase values (typically in the middle of off time)
                                                    // set to PWM_NO_SAMPE if channel has too-short or no off-phase at all

static bool pwm_NextSampleType[PWM_CHANNELS];       // next trigger delay has been configured for ... 'false' = off-phase, 'true' = on-phase

// ------------------------------------------------------------------------------

// internal method which computes the sampling time for the on phase 
// tries to sample in the middle of oo-phase
static inline pwm_CounterType pwm_CalcOnSampleTime(pwm_CounterType start_time, pwm_CounterType on_phase)
{
  if (on_phase>=PWM_MIN_WIDTH_FOR_SAMPLE) return start_time+(on_phase/2);     
  else return PWM_NO_SAMPE;
}

// internal method which computes the sampling time for the off phase 
// tries to sample in the middle of off-phase, takes wrap-arount into account
static inline pwm_CounterType pwm_CalcOffSampleTime(pwm_CounterType end_time, pwm_CounterType on_phase)
{
  unsigned long sampleTmp;   
  pwm_CounterType offPhase;

  offPhase=PWM_PERIOD-on_phase;
  if (offPhase>=PWM_MIN_WIDTH_FOR_SAMPLE) 
  {
    sampleTmp=((unsigned long )end_time)+((unsigned long )(offPhase/2));
    if (sampleTmp>=PWM_PERIOD) sampleTmp-=PWM_PERIOD; // wrap 
    return sampleTmp;     
  }
  else return PWM_NO_SAMPE;
}


// internal method which tries to find a good distribution of on-phases
static void pwm_ScheduleOnPhases()
{
  unsigned long startCh0;
  unsigned long startCh1;
  unsigned long startCh2;
  unsigned long startCh3;
  
  unsigned long endCh0;
  unsigned long endCh1;
  unsigned long endCh2;
  unsigned long endCh3;

  unsigned long shift,endTmp;   
    
  // TODO: this is a simple "squizing" distribution algorithm, 
  // it is not expected to provide the most efficient distribution, 
        
  // CH0 start always at the beginning of the period   
  startCh0=0; 
    
  // CH1 put ater CH1, if end reaches past the period time, create overlap in the middle
  startCh1=pwm_OnPhase[0];    
  endTmp=startCh1+((unsigned long)pwm_OnPhase[1]); 
  if (endTmp>((unsigned long)(PWM_PERIOD))) startCh1=PWM_PERIOD-pwm_OnPhase[1];
    
  // CH2 put behind CH0 and CH1, if goes past the end, put at the end of period, move CH1 1/4 further to the front. 
  startCh2=startCh1+(unsigned long)pwm_OnPhase[1];
  endTmp=startCh2+((unsigned long)pwm_OnPhase[2]);
  if (endTmp>((unsigned long)PWM_PERIOD))
  {             
    shift=(endTmp-(unsigned long)PWM_PERIOD)/4;      
    if (startCh1>shift) startCh1-=shift;
    else startCh1=0;
      
    startCh2=((unsigned long)PWM_PERIOD)-pwm_OnPhase[2];
  }
    
  // CH3 almost the same as CH2 but move CH1 and CH2 1/4 way to the front.
  startCh3=startCh2+(unsigned long)pwm_OnPhase[2];
  endTmp=startCh3+(unsigned long)pwm_OnPhase[3];
  if (endTmp>((unsigned long)PWM_PERIOD))
  {
    shift=(endTmp-(unsigned long)PWM_PERIOD)/4;      
    if (startCh1>shift) startCh1-=shift;
    else startCh1=0;

    if (startCh2>shift) startCh2-=shift;
    else startCh2=0;
      
    startCh3=((unsigned long)PWM_PERIOD)-pwm_OnPhase[3];
  }
  
  endCh0=startCh0+pwm_OnPhase[0];
  endCh1=startCh1+pwm_OnPhase[1];
  endCh2=startCh2+pwm_OnPhase[2];
  endCh3=startCh3+pwm_OnPhase[3]; 

  // Compute On-Phase sampling time    
  pwm_OnSample[0]=pwm_CalcOnSampleTime(startCh0,pwm_OnPhase[0]);
  pwm_OnSample[1]=pwm_CalcOnSampleTime(startCh1,pwm_OnPhase[1]);
  pwm_OnSample[2]=pwm_CalcOnSampleTime(startCh2,pwm_OnPhase[2]);
  pwm_OnSample[3]=pwm_CalcOnSampleTime(startCh3,pwm_OnPhase[3]);

  // Compute Off-Phase sampling time 
  pwm_OffSample[0]=pwm_CalcOffSampleTime(endCh0,pwm_OnPhase[0]);
  pwm_OffSample[1]=pwm_CalcOffSampleTime(endCh1,pwm_OnPhase[1]);
  pwm_OffSample[2]=pwm_CalcOffSampleTime(endCh2,pwm_OnPhase[2]);
  pwm_OffSample[3]=pwm_CalcOffSampleTime(endCh3,pwm_OnPhase[3]);

  // remember start times
  pwm_Start[0]=startCh0;
  pwm_Start[1]=startCh1;
  pwm_Start[2]=startCh2;
  pwm_Start[3]=startCh3;
   
  // configure PWM channels
  pwm_config_start(PWM_GP1,startCh0);
  pwm_config_stop(PWM_GP1,endCh0);
  pwm_set_trigger_delay(PWM_GP1,pwm_OnSample[0]);
  pwm_NextSampleType[0]=true; 
  
  pwm_config_start(PWM_GP2,startCh1);
  pwm_config_stop(PWM_GP2,endCh1);
  pwm_set_trigger_delay(PWM_GP2,pwm_OnSample[1]);
  pwm_NextSampleType[1]=true; 
  
  pwm_config_start(PWM_GP3,startCh2);
  pwm_config_stop(PWM_GP3,endCh2);
  pwm_set_trigger_delay(PWM_GP3,pwm_OnSample[2]);
  pwm_NextSampleType[2]=true; 

  pwm_config_start(PWM_GP4,startCh3);
  pwm_config_stop(PWM_GP4,endCh3);
  pwm_set_trigger_delay(PWM_GP4,pwm_OnSample[3]);
  pwm_NextSampleType[3]=true; 
    
}


// ------ backup ------
#if 0 

// internal method which tries to find a good distribution of on-phases
static void pwm_ScheduleOnPhases()
{
  unsigned long startCh0;
  unsigned long startCh1;
  unsigned long startCh2;
  unsigned long startCh3;
  
  unsigned long endCh0;
  unsigned long endCh1;
  unsigned long endCh2;
  unsigned long endCh3;

  unsigned long shift,endTmp;   
    
  // TODO: this is a simple "squizing" distribution algorithm, 
  // it is not expected to provide the most efficient distribution, 
        
  // CH0 start always at the beginning of the period   
  startCh0=0; 
    
  // CH1 put ater CH1, if end reaches past the period time, create overlap in the middle
  startCh1=pwm_OnPhase[0];    
  endTmp=startCh1+((unsigned long)pwm_OnPhase[1]); 
  if (endTmp>((unsigned long)(PWM_PERIOD))) startCh1=PWM_PERIOD-pwm_OnPhase[1];
    
  // CH2 put behind CH0 and CH1, if goes past the end, put at the end of period, move CH1 1/4 further to the front. 
  startCh2=startCh1+(unsigned long)pwm_OnPhase[1];
  endTmp=startCh2+((unsigned long)pwm_OnPhase[2]);
  if (endTmp>((unsigned long)PWM_PERIOD))
  {
          
    shift=(endTmp-(unsigned long)PWM_PERIOD)/4;      
    if (startCh1>shift) startCh1-=shift;
    else startCh1=0;
      
    startCh2=((unsigned long)PWM_PERIOD)-pwm_OnPhase[2];
  }
    
  // CH3 almost the same as CH2 but move CH1 and CH2 1/4 way to the front.
  startCh3=startCh2+(unsigned long)pwm_OnPhase[2];
  endTmp=startCh3+(unsigned long)pwm_OnPhase[3];
  if (endTmp>((unsigned long)PWM_PERIOD))
  {
    shift=(endTmp-(unsigned long)PWM_PERIOD)/4;      
    if (startCh1>shift) startCh1-=shift;
    else startCh1=0;

    if (startCh2>shift) startCh2-=shift;
    else startCh2=0;
      
    startCh3=((unsigned long)PWM_PERIOD)-pwm_OnPhase[3];
  }
  
  endCh0=startCh0+pwm_OnPhase[0];
  endCh1=startCh1+pwm_OnPhase[1];
  endCh2=startCh2+pwm_OnPhase[2];
  endCh3=startCh3+pwm_OnPhase[3]; 

  // Compute On-Phase sampling time    
  pwm_OnSample[0]=pwm_CalcOnSampleTime(startCh0,pwm_OnPhase[0]);
  pwm_OnSample[1]=pwm_CalcOnSampleTime(startCh1,pwm_OnPhase[1]);
  pwm_OnSample[2]=pwm_CalcOnSampleTime(startCh2,pwm_OnPhase[2]);
  pwm_OnSample[3]=pwm_CalcOnSampleTime(startCh3,pwm_OnPhase[3]);

  // Compute Off-Phase sampling time 
  pwm_OffSample[0]=pwm_CalcOffSampleTime(endCh0,pwm_OnPhase[0]);
  pwm_OffSample[1]=pwm_CalcOffSampleTime(endCh1,pwm_OnPhase[1]);
  pwm_OffSample[2]=pwm_CalcOffSampleTime(endCh2,pwm_OnPhase[2]);
  pwm_OffSample[3]=pwm_CalcOffSampleTime(endCh3,pwm_OnPhase[3]);

  // remember start times
  pwm_Start[0]=startCh0;
  pwm_Start[1]=startCh1;
  pwm_Start[2]=startCh2;
  pwm_Start[3]=startCh3;
   
  // configure PWM channels
  pwm_config_start(PWM_GP1,startCh0);
  pwm_config_stop(PWM_GP1,endCh0);
  pwm_set_trigger_delay(PWM_GP1,pwm_OnSample[0]);
  pwm_NextSampleType[0]=true; 
  
  pwm_config_start(PWM_GP2,startCh1);
  pwm_config_stop(PWM_GP2,endCh1);
  pwm_set_trigger_delay(PWM_GP2,pwm_OnSample[1]);
  pwm_NextSampleType[1]=true; 
  
  pwm_config_start(PWM_GP3,startCh2);
  pwm_config_stop(PWM_GP3,endCh2);
  pwm_set_trigger_delay(PWM_GP3,pwm_OnSample[2]);
  pwm_NextSampleType[2]=true; 

  pwm_config_start(PWM_GP4,startCh3);
  pwm_config_stop(PWM_GP4,endCh3);
  pwm_set_trigger_delay(PWM_GP4,pwm_OnSample[3]);
  pwm_NextSampleType[3]=true; 
    
}

#endif
// --------------------------------

// Period IRQ handler (switches between on/off phase sampling)
void pwm_IRQHandlerPeriod(int sno)
{
  uint8_t chno;
  pwm_ch_t pwm_plug; 
  uint8_t adc_plug; 
  
  switch(sno)
  { 
    case PWM_IRQ_EVT_PERIOD0: chno=0; adc_plug=ADC_PWM_CH1; pwm_plug=PWM_GP1; break;
    case PWM_IRQ_EVT_PERIOD1: chno=1; adc_plug=ADC_PWM_CH2; pwm_plug=PWM_GP2; break;
    case PWM_IRQ_EVT_PERIOD2: chno=2; adc_plug=ADC_PWM_CH3; pwm_plug=PWM_GP3; break;
    case PWM_IRQ_EVT_PERIOD3: chno=3; adc_plug=ADC_PWM_CH4; pwm_plug=PWM_GP4; break;
    
    default: return;  // if somehow other IRQ occured, stop processing
  }
  
  bool curtype=pwm_NextSampleType[chno];  
  bool curen=((curtype?pwm_OnSample[chno]:pwm_OffSample[chno])!=PWM_NO_SAMPE)?true:false;  
  adc_SetCurrentSampleType(adc_plug,curen,curtype); // update sampling setings, to be able to store current value in the right on/off location
  
  pwm_NextSampleType[chno]=pwm_NextSampleType[chno]?false:true; // switch between on/off phase sampling
  pwm_set_trigger_delay(pwm_plug,pwm_NextSampleType[chno]?pwm_OnSample[chno]:pwm_OffSample[chno]); // preload trigger delay register for the next period 
}

bool pwm_Init()
{ 
  // Data value init
  for(uint8_t i=0;i<PWM_CHANNELS;++i)
  {
    pwm_Start[i]=0;
    pwm_OnPhase[i]=0;
    pwm_OnSample[i]=0;
    pwm_OffSample[i]=0;
    pwm_NextSampleType[i]=false;
    
  }
  
  pwm_handler_init();
  pwm_clear_all_irq_events();
  pwm_handler_register(PWM_IRQ_EVT_PERIOD0,pwm_IRQHandlerPeriod); // each channel generate own period IRQs 
  pwm_handler_register(PWM_IRQ_EVT_PERIOD1,pwm_IRQHandlerPeriod); // (if known, that all channels run the same period, this could be simplified) 
  pwm_handler_register(PWM_IRQ_EVT_PERIOD2,pwm_IRQHandlerPeriod);
  pwm_handler_register(PWM_IRQ_EVT_PERIOD3,pwm_IRQHandlerPeriod);

  
  // Initilaize polarity
  pwm_config_polarity(PWM_GP1,false);
  pwm_config_polarity(PWM_GP2,false);
  pwm_config_polarity(PWM_GP3,false);
  pwm_config_polarity(PWM_GP4,false);
  
  //Config term & zero flags (switch off both)  
  pwm_config_term(PWM_GP1,false);
  pwm_config_term(PWM_GP1,false);
  pwm_config_term(PWM_GP2,false);
  pwm_config_term(PWM_GP3,false);
  
  pwm_config_zero(PWM_GP1,false);
  pwm_config_zero(PWM_GP2,false);
  pwm_config_zero(PWM_GP3,false);
  pwm_config_zero(PWM_GP4,false);
  
  // Configure prescalers
  pwm_config_prescaler(PWM_GP1,PWM_PRESCALER);
  pwm_config_prescaler(PWM_GP2,PWM_PRESCALER);
  pwm_config_prescaler(PWM_GP3,PWM_PRESCALER);
  pwm_config_prescaler(PWM_GP4,PWM_PRESCALER);

  // Configure periods
  pwm_config_period(PWM_GP1,PWM_PERIOD);
  pwm_config_period(PWM_GP2,PWM_PERIOD);
  pwm_config_period(PWM_GP3,PWM_PERIOD);
  pwm_config_period(PWM_GP4,PWM_PERIOD);
  
  // Initialize on-phases and trigger points to zero
  pwm_config_start(PWM_GP1,0);
  pwm_config_stop(PWM_GP1,0);
  pwm_set_trigger_delay(PWM_GP1,0);
  
  pwm_config_start(PWM_GP2,0);
  pwm_config_stop(PWM_GP2,0);
  pwm_set_trigger_delay(PWM_GP2,0);
  
  pwm_config_start(PWM_GP3,0);
  pwm_config_stop(PWM_GP3,0);
  pwm_set_trigger_delay(PWM_GP3,0);
  
  pwm_config_start(PWM_GP4,0);
  pwm_config_stop(PWM_GP4,0);
  pwm_set_trigger_delay(PWM_GP4,0);
  
  // Enable counter
  pwm_enable(PWM_GP1,true); // since start==stop no signal is generated at this point
  pwm_enable(PWM_GP2,true); 
  pwm_enable(PWM_GP3,true); 
  pwm_enable(PWM_GP4,true); 
  
  pwm_ScheduleOnPhases(); // eventually rescedule on-phases, if non zero value 
                          // has been chosen as init for any channel. 

  
  // Enable period IRQs
  pwm_enable_irq(PWM_IRQ_EVT_PERIOD0,true);
  pwm_enable_irq(PWM_IRQ_EVT_PERIOD1,true);
  pwm_enable_irq(PWM_IRQ_EVT_PERIOD2,true);
  pwm_enable_irq(PWM_IRQ_EVT_PERIOD3,true);
  
  return true;
}


// Configures the PWM settings of a particular channel (rescheduling of all channels is performed)
void pwm_SetOnPhase(pwm_ch_t ch,pwm_CounterType duration)
{
  if (duration>PWM_PERIOD) duration=PWM_PERIOD;
  
  switch(ch) 
  {
    case PWM_GP1: pwm_OnPhase[0]=duration; break;
    case PWM_GP2: pwm_OnPhase[1]=duration; break;
    case PWM_GP3: pwm_OnPhase[2]=duration; break;
    case PWM_GP4: pwm_OnPhase[3]=duration; break;
  }
  
  pwm_ScheduleOnPhases(); // rescedule on-phases to achieve minimal multi-phase on-time
}

// Configure PWM settings for all phases. 
void pwm_SetAllOnPhases(pwm_CounterType durCh0,pwm_CounterType durCh1,pwm_CounterType durCh2,pwm_CounterType durCh3)
{
  if (durCh0>PWM_PERIOD) durCh0=PWM_PERIOD;
  if (durCh1>PWM_PERIOD) durCh1=PWM_PERIOD;
  if (durCh2>PWM_PERIOD) durCh2=PWM_PERIOD;
  if (durCh3>PWM_PERIOD) durCh3=PWM_PERIOD;
  
  pwm_OnPhase[0]=durCh0;
  pwm_OnPhase[1]=durCh1;
  pwm_OnPhase[2]=durCh2;
  pwm_OnPhase[3]=durCh3;

  pwm_ScheduleOnPhases(); // rescedule on-phases to achieve minimal multi-phase on-time
}

// Retrieves current on-phase duration
pwm_CounterType pwm_GetOnPhase(pwm_ch_t ch)
{ 
  switch(ch) 
  {
    case PWM_GP1: return pwm_OnPhase[0]; break;
    case PWM_GP2: return pwm_OnPhase[1]; break;
    case PWM_GP3: return pwm_OnPhase[2]; break;
    case PWM_GP4: return pwm_OnPhase[3]; break;
  }

  return 0;  
}

// Retrieves current start time 
pwm_CounterType pwm_GetStartTick(pwm_ch_t ch)
{ 
  switch(ch) 
  {
    case PWM_GP1: return pwm_Start[0]; break;
    case PWM_GP2: return pwm_Start[1]; break;
    case PWM_GP3: return pwm_Start[2]; break;
    case PWM_GP4: return pwm_Start[3]; break;
  }

  return 0;  
}

// Retrieves the sampling time, for the on-phase values 
// may return PWM_NO_SAMPE if on-phase too short for sampling 
pwm_CounterType pwm_GetOnSampleTick(pwm_ch_t ch)
{ 
  switch(ch) 
  {
    case PWM_GP1: return pwm_OnSample[0]; break;
    case PWM_GP2: return pwm_OnSample[1]; break;
    case PWM_GP3: return pwm_OnSample[2]; break;
    case PWM_GP4: return pwm_OnSample[3]; break;
  }

  return 0;  
}

// Retrieves the sampling time, for the off-phase values 
// may return PWM_NO_SAMPE if off-phase too short for sampling 
pwm_CounterType pwm_GetOffSampleTick(pwm_ch_t ch)
{ 
  switch(ch) 
  {
    case PWM_GP1: return pwm_OffSample[0]; break;
    case PWM_GP2: return pwm_OffSample[1]; break;
    case PWM_GP3: return pwm_OffSample[2]; break;
    case PWM_GP4: return pwm_OffSample[3]; break;
  }

  return 0;  
}
