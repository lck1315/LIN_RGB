 /* ------------------------------------------------------------------- */
 /** @file mod_adc.h
  * @brief HV_ADC configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_adc.h,v 1.1 2013/09/03 14:42:44 rpy Exp $
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
  * $Date: 2013/09/03 14:42:44 $

  * $Locker:  $
  * $Url:   $
  *
  * Additional markers:
  *
  *
  *
  */

#ifndef _MOD_ADC_H_
#define _MOD_ADC_H_

#include "api.h"

//################################################################################
// ADC

#define ADC_MUX_DELAY       240             // accoring to 521.31 ~10us (->  at 24MHz related to HV delay
#define ADC_SAMPLE_EXT      15              
#define ADC_SAMPLE_EXT_VT   48              // default value

#define ADC_PWM_CH1         0               // glow plug number if requesting ADC values for a particular phase
#define ADC_PWM_CH2         1
#define ADC_PWM_CH3         2
#define ADC_PWM_CH4         3

#define ADC_PWM_CHANNELS    4               // number of PWM channels

#define ADC_CH_NONE         0               // ADC MUX channels 
#define ADC_CH_VDIFF        1               // Value related to DMA storage location
#define ADC_CH_OUT1         2
#define ADC_CH_OUT2         3
#define ADC_CH_OUT3         4
#define ADC_CH_OUT4         5
#define ADC_CH_AIN1         6
#define ADC_CH_AIN2         7
#define ADC_CH_AIN3         8
#define ADC_CH_AIN4         9
#define ADC_CH_VTEMP        10
#define ADC_CH_VDD3         11
#define ADC_CH_VDD5VDDA     12
#define ADC_CH_VS           13
#define ADC_CH_VDD3I_HV     14
#define ADC_CH_VBG          15

#define ADC_CH_MAX          15               // maximum nuber of channels (has to be >= the highes DMA storage location used) 

#define ADC_INVALID_VALUE   0xffffU

//! Initialzation
/*! May return 'false' if failed */
bool adc_Init();

//! Returns current ADC sample value of a given channel. 
uint16_t adc_GetCurrentValue(uint8_t ch);

//! Returns ADC sample value of given ADC channel in the middle high phase of given PWM phase
/*! May return ADC_INVALID_VALUE if measurement was not possible (i.e. due to too short phase) */
uint16_t adc_GetOnPhaseValue(uint8_t plug,uint8_t ch);

//! Returns ADC sample value of given ADC channel in the middle low phase of given PWM phase
/*! May return ADC_INVALID_VALUE if measurement was not possible (i.e. due to too short phase) */
uint16_t adc_GetOffPhaseValue(uint8_t plug,uint8_t ch);


//! Sets sample type 
/*! On the following copy IRQ, sample data is treated as 
    enable control if sampling is performed at all. 
    type=='true' -> on-phase data, type=='false' -> off-phase data
    for that particular channel
 
    This method is intended for internal use in PWM module.
*/
void adc_SetCurrentSampleType(uint8_t ch,bool enable,bool type);

#endif
