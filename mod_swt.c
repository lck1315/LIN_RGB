 /* ------------------------------------------------------------------- */
 /** @file mod_swt.c
  * @brief SW_TIMER configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_swt.c,v 1.1 2013/09/03 14:42:46 rpy Exp $
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
  * $Date: 2013/09/03 14:42:46 $

  * $Locker:  $
  * $Url:   $
  *
  * Additional markers:
  *
  *
  *
  */

#include "api.h"
#include "mod_swt.h"

//################################################################################
// SW Timer

// SW timer is used as a 1 ms time base / tick counter. 

#define SWT_TICK_TIMER_NUM              SWTIMER_0      // use TIMER 0 
#define SWT_TICK_TIMER_IRQ              SWTIMER_IRQ_EVT_CNT_ZERO_0

#define SWT_PERIODIC_TIMER_NUM              SWTIMER_1      // use TIMER 1
#define SWT_PERIODIC_TIMER_IRQ              SWTIMER_IRQ_EVT_CNT_ZERO_1

#define SWT_TICK_TIMER_PRESCALER_VAL    23    // timer clock 24MHz / (23+1) -> 1MHz
#define SWT_TICK_TIMER_RELOAD_VAL       999   // timer expected to run at 1MHz (999+1) -> IRQ every 1ms

// ------------------------------------------------------------------------------

static volatile swt_TimeType swt_TickCount;

static volatile swt_TimeType swt_Timers[SWT_COUNT_DOWN_TIMERS];

// ------------------------------------------------------------------------------

void swt_IRQHandler(int sno)
{
  if (sno==SWT_TICK_TIMER_IRQ) 
  {
    if (swt_TickCount<SWT_TICK_MAX) ++swt_TickCount;
    else swt_TickCount=0;
   
    for(uint8_t i=0;i<SWT_COUNT_DOWN_TIMERS;++i) 
      if (swt_Timers[i]>0) --swt_Timers[i];
  }
}

bool swt_Init()
{
  // Setup local data
  swt_TickCount=0;
  
  for(uint8_t i=0;i<SWT_COUNT_DOWN_TIMERS;++i) 
    swt_Timers[i]=0;
  
  // Register IRQ
  swtimer_handler_init();
  irq_handler_register(VIC_IRQ_SWTIMER,SWT_TICK_TIMER_IRQ,swt_IRQHandler);

  // Set timer reload and divider
  swtimer_set_counter_reload (SWT_TICK_TIMER_NUM, SWT_TICK_TIMER_RELOAD_VAL);
  swtimer_set_prescaler_reload (SWT_TICK_TIMER_NUM, SWT_TICK_TIMER_PRESCALER_VAL);

  // Enable timer
  swtimer_autoreload_enable(SWT_TICK_TIMER_NUM,true);  
  swtimer_enable(SWT_TICK_TIMER_NUM,true);

  //  disable periodic timer, since not initialized 
  swtimer_enable(SWT_PERIODIC_TIMER_NUM,false);

  
  // Enable IRQ
  swtimer_enable_irq(SWT_TICK_TIMER_IRQ,true);
  
  return true;
}


// Busy wait for a specified amount of time  
void swt_Wait(swt_TimeType wait)
{
  swt_TimeType start=swt_TickCount;
  swt_TimeType end=start+wait;
  
  if (end==start) return; // wait was 0 -> return immediately
  
  if (end>start) // typical case 
  {
    while(swt_TickCount>=start && swt_TickCount<end) ;
  }
  else // end < start -> wrap around case
  {
    while(swt_TickCount>=start && swt_TickCount<=SWT_TICK_MAX); // wait for wrap around (if using the entire value range, compiler may complain here about pointless comparision)
    while(swt_TickCount<end) ; // wait remaining time    
  }
}

// Returns current tick count. May wrap around at SWT_TICK_MAX
swt_TimeType swt_GetTickCount()
{
  return swt_TickCount;
}

//! Sets new count down value for timer 'num'  
void swt_SetCountDownTimer(uint8_t num,swt_TimeType count)
{
  if (num<SWT_COUNT_DOWN_TIMERS) swt_Timers[num]=count;
}

//! Returns true if specified timer has reached zero
bool swt_IsCountDownTimerZero(uint8_t num)
{
  if (num<SWT_COUNT_DOWN_TIMERS) return (swt_Timers[num]==0)?true:false;
  return true;
}

//! Returns current timer value
swt_TimeType swt_GetCountDownTimer(uint8_t num)
{
  if (num<SWT_COUNT_DOWN_TIMERS) return swt_Timers[num];
  return 0;
}

void swt_SetupPeriodicTimer(uint16_t prescaler, uint16_t reload, callback_t irq_callback)
{
  irq_handler_register(VIC_IRQ_SWTIMER,SWT_PERIODIC_TIMER_IRQ,irq_callback);

  // Set timer reload and divider
  swtimer_set_counter_reload (SWT_PERIODIC_TIMER_NUM, reload);
  swtimer_set_prescaler_reload (SWT_PERIODIC_TIMER_NUM, prescaler);

  // Enable timer
  swtimer_autoreload_enable(SWT_PERIODIC_TIMER_NUM,true);  
  swtimer_enable(SWT_PERIODIC_TIMER_NUM,true);

  // Enable IRQ
  swtimer_enable_irq(SWT_PERIODIC_TIMER_NUM,true); 
}

void swt_StopPeriodicTimer()
{
  swtimer_enable(SWT_PERIODIC_TIMER_NUM,false);
  swtimer_enable_irq(SWT_PERIODIC_TIMER_IRQ,false);  
}

void swt_SetPeriodicTimerReload(uint16_t reload)
{
  swtimer_set_counter_reload(SWT_PERIODIC_TIMER_NUM, reload);  
}
