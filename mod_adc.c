 /* ------------------------------------------------------------------- */
 /** @file mod_adc.c
  * @brief HV_ADC configuration and access module (code)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_adc.c,v 1.1 2013/09/03 14:42:44 rpy Exp $
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

#include "api.h"
#include "mod_adc.h"
#include "mod_gpio.h"


//################################################################################
// ADC

#ifndef STDIO_SCI_SOFT // if using SOFT SCI, GPIOs are used for TXD/RXD so we should not interfere here. 

//#define ADC_SHOW_SAMPLE_ON_GPIO // if defined uses GPIOs 4..7 for showing phase sample time

#endif

#define ADC_DMA_AREA_SIZE   (16+(4*(ADC_CH_MAX+1)))  // 16 immediate channel values + 4x (ADC_CH_MAX+1) values related to ADC_DMA_CYCLIC_CHANNEL_SET

#define ADC_DMA_CYCLIC_CHANNEL_SET  0xffff   // for the time beeing enable all HV channels.

// ------------------------------------------------------------------------------

volatile uint16_t adc_DMAArea[ADC_DMA_AREA_SIZE];
volatile uint16_t adc_OnPhaseValues[ADC_PWM_CHANNELS][ADC_CH_MAX+1];
volatile uint16_t adc_OffPhaseValues[ADC_PWM_CHANNELS][ADC_CH_MAX+1];

static bool adc_CurrentSampleType[ADC_PWM_CHANNELS];       // runing trigger delay has been configured for ... 'false' = off-phase, 'true' = on-phase
static bool adc_CurrentSampleEnabled[ADC_PWM_CHANNELS];    // sampling enable flag for given channels

// ------------------------------------------------------------------------------

// Interrupt handler which save DMA data to dedicate on/off phase storage locations. 
void adc_IRQHandlerDMACopy(int sno)
{
  uint8_t chno;
    
  switch(sno)
  {
    case ADC_CTRL_IRQ_EVT_COPY_0: chno=0; break;
    case ADC_CTRL_IRQ_EVT_COPY_1: chno=1; break;
    case ADC_CTRL_IRQ_EVT_COPY_2: chno=2; break;
    case ADC_CTRL_IRQ_EVT_COPY_3: chno=3; break;
    
    default: return;  // if some how other IRQ occured skip further processing
  }

  uint8_t dmaofs=16+(chno*(ADC_CH_MAX+1));    
  
  if (adc_CurrentSampleEnabled[chno]) // only use sample data, if sampling has been enabled (i.e. pwm phase is long enough to give reasonable values)
  {  
    
#ifdef ADC_SHOW_SAMPLE_ON_GPIO    
    gpio_SetBit(GPIO_FLAG_ADC_COPY_Sx+chno,true);
#endif    
    
    (adc_CurrentSampleType[chno]) // on-phase copy (data needs to be moved out of DMA area into the right storage locations)
    {
      for(uint8_t i=0;i<=ADC_CH_MAX;++i) adc_OnPhaseValues[chno][i]=adc_DMAArea[dmaofs+i]; 
    }
    else // off-phase copy
    {
      for(uint8_t i=0;i<=ADC_CH_MAX;++i) adc_OffPhaseValues[chno][i]=adc_DMAArea[dmaofs+i]; 
    }  

#ifdef ADC_SHOW_SAMPLE_ON_GPIO    
    gpio_SetBit(GPIO_FLAG_ADC_COPY_Sx+chno,false);
#endif
    
  }
}

// on the following copy IRQ, sample data is treated as 
// enable control if sampling is performed at all. 
// type=='true' -> on-phase data, type=='false' -> off-phase data
// for that particular channel
void adc_SetCurrentSampleType(uint8_t ch,bool enable,bool type)
{
  uint8_t chno;
  
  switch(ch)
  {
    case ADC_PWM_CH1: chno=0; break;
    case ADC_PWM_CH2: chno=1; break;
    case ADC_PWM_CH3: chno=2; break;
    case ADC_PWM_CH4: chno=3; break;
    
  default: return; // invalid chanel specified.
  }  

  cli(); 
  
  adc_CurrentSampleEnabled[chno]=enable;
  adc_CurrentSampleType[chno]=type;
  
  if (!enable) // if sampling not enabled invalidate data.
  {
    if (type) // on-phase 
    {
      for(uint8_t i=0;i<=ADC_CH_MAX;++i) adc_OnPhaseValues[chno][i]=ADC_INVALID_VALUE; 
    }
    else // off-phase 
    {
      for(uint8_t i=0;i<=ADC_CH_MAX;++i) adc_OffPhaseValues[chno][i]=ADC_INVALID_VALUE; 
    }      
  }
  
  sei();
}

bool adc_Init()
{ 
  // Initialize local data
  for(uint8_t i=0;i<ADC_DMA_AREA_SIZE;++i) adc_DMAArea[i]=ADC_INVALID_VALUE; 
  
  for(uint8_t i=0;i<ADC_PWM_CHANNELS;++i) 
  {
    adc_CurrentSampleType[i]=false;     
    adc_CurrentSampleEnabled[i]=false;     
    for(uint8_t j=0;j<=ADC_CH_MAX;++j) 
    {
      adc_OnPhaseValues[i][j]=ADC_INVALID_VALUE;
      adc_OffPhaseValues[i][j]=ADC_INVALID_VALUE;
    }
  }
      
  // Interrup setup  
  adc_ctrl_handler_init();
  adc_ctrl_clear_all_irq_events();
  adc_ctrl_handler_register(ADC_CTRL_IRQ_EVT_COPY_0,adc_IRQHandlerDMACopy); 
  adc_ctrl_handler_register(ADC_CTRL_IRQ_EVT_COPY_1,adc_IRQHandlerDMACopy); 
  adc_ctrl_handler_register(ADC_CTRL_IRQ_EVT_COPY_2,adc_IRQHandlerDMACopy); 
  adc_ctrl_handler_register(ADC_CTRL_IRQ_EVT_COPY_3,adc_IRQHandlerDMACopy); 
  
  adc_ctrl_set_dma_base_address((uint16_t)adc_DMAArea);
    
  adc_ctrl_set_mux_delay(ADC_MUX_DELAY);
  adc_ctrl_set_sample_extension(ADC_SAMPLE_EXT,ADC_SAMPLE_EXT_VT);
  
  // In this demo all channels are stored in all trigger based copies. 
  adc_ctrl_pwm_trigger_config(PWM_CH0,ADC_DMA_CYCLIC_CHANNEL_SET); 
  adc_ctrl_pwm_trigger_config(PWM_CH1,ADC_DMA_CYCLIC_CHANNEL_SET); 
  adc_ctrl_pwm_trigger_config(PWM_CH2,ADC_DMA_CYCLIC_CHANNEL_SET); 
  adc_ctrl_pwm_trigger_config(PWM_CH3,ADC_DMA_CYCLIC_CHANNEL_SET); 
 
  adc_ctrl_cyclic_mode_config(true);

  // Enable IRQs
  adc_ctrl_enable_irq(ADC_CTRL_IRQ_EVT_COPY_0,true);
  adc_ctrl_enable_irq(ADC_CTRL_IRQ_EVT_COPY_1,true);
  adc_ctrl_enable_irq(ADC_CTRL_IRQ_EVT_COPY_2,true);
  adc_ctrl_enable_irq(ADC_CTRL_IRQ_EVT_COPY_3,true);
  
  return true;
}

// returns current ADC sample value of a given channel. 
uint16_t adc_GetCurrentValue(uint8_t ch)
{
  if (ch<=ADC_CH_MAX) return adc_DMAArea[ch]; // no additional mapping reqired here
 
  return 0;
}

// returns ADC sample value of given ADC channel in the middle high phase of given PWM phase
uint16_t adc_GetOnPhaseValue(uint8_t plug,uint8_t ch)
{
  if (plug<ADC_PWM_CHANNELS && ch<=ADC_CH_MAX) return adc_OnPhaseValues[plug][ch];

  return 0;  
}

// returns ADC sample value of given ADC channel in the middle low phase of given PWM phase
uint16_t adc_GetOffPhaseValue(uint8_t plug,uint8_t ch)
{
  if (plug<ADC_PWM_CHANNELS && ch<=ADC_CH_MAX) return adc_OffPhaseValues[plug][ch];

  return 0;    
}

