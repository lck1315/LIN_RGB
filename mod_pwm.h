 /* ------------------------------------------------------------------- */
 /** @file mod_pwm.h
  * @brief PWM configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_pwm.h,v 1.1 2013/09/03 14:42:45 rpy Exp $
  *
  * @verbatim
  * -------------------------------------------------------------------
  * Date     B/F Who Comment
  * ------------------------------------------------------------------- 
  * 13/06/15 (F) RPY initial version
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

#ifndef _MOD_PWM_H_
#define _MOD_PWM_H_

#include "api.h"

//################################################################################
// PWM

// PWM module is used to generate PWMs on four channels. 
// The on-phases are distributed along the PWM period to achieve minimum 
// simultanous on times across all channels. 

//#define PWM_PRESCALER             23      // PWM clock 24 MHz / (23+1) -> counter running at 1MHz
//#define PWM_PERIOD                33332   // 1 MHz / (33332+1)  -> 30 Hz

//#define PWM_MIN_WIDTH_FOR_SAMPLE  3333    // 1 MHz / 3333  -> 3.33ms minimum phase duration to allow measurement 

#define PWM_PRESCALER             11      // PWM clock 24 MHz / (11+1) -> counter running at 2MHz
//#define PWM_PRESCALER             7      // PWM clock 24 MHz / (11+1) -> counter running at 2MHz  (untrimmed device)

#define PWM_PERIOD                19999   // 2 MHz / (19999+1)  -> 100 Hz

#define PWM_MIN_WIDTH_FOR_SAMPLE  2000    // 2 MHz / 2000  -> 1ms minimum phase duration to allow measurement 
                                          // (actual value t.b.d. Consider IRQ delay, sampling schedule, transistor delay, line capacity etc...)

#define PWM_CHANNEL_INIT          0       // initial PWM phase value 


#define PWM_NO_SAMPE              0xffff  // indicates that sampling at given time is not possible (i.e. no on/off phase)

#define PWM_CHANNELS              4       // number of PWM channels

#define PWM_GP1                   PWM_CH0 // channel definition for particular glow plug
#define PWM_GP2                   PWM_CH1
#define PWM_GP3                   PWM_CH2
#define PWM_GP4                   PWM_CH3


typedef unsigned short pwm_CounterType; // data type suitable for representation of PWM values 
                                        // HW dependent, here at least 16 bit. 


//! Initialization method
/*! May return 'false' if initialization fails */
bool pwm_Init();

//! Configures the PWM settings of a particular channel (rescheduling of all channels is performed!)
void pwm_SetOnPhase(pwm_ch_t ch,pwm_CounterType duration);

//! Configure PWM settings for all channels
void pwm_SetAllOnPhases(pwm_CounterType durCh0,pwm_CounterType durCh1,pwm_CounterType durCh2,pwm_CounterType durCh3);

//! Retrieves channel's current on-phase duration
pwm_CounterType pwm_GetOnPhase(pwm_ch_t ch);

//! Retrieves channel's current start time 
pwm_CounterType pwm_GetStartTick(pwm_ch_t ch);

//! Retrieves the sampling time, for the on-phase values 
/*! May return PWM_NO_SAMPE if on-phase too short for sampling  */
pwm_CounterType pwm_GetOnSampleTick(pwm_ch_t ch);

//! Retrieves the sampling time, for the off-phase values 
/*! May return PWM_NO_SAMPE if off-phase too short for sampling  */
pwm_CounterType pwm_GetOffSampleTick(pwm_ch_t ch);

#endif
