 /* ------------------------------------------------------------------- */
 /** @file mod_swt.h
  * @brief SW_TIMER configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_swt.h,v 1.1 2013/09/03 14:42:46 rpy Exp $
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

#ifndef _MOD_SWT_H_
#define _MOD_SWT_H_

#include "api.h"

//################################################################################
// SW Timer

// SW timer is used as a 1 ms time base / tick counter. 

#define SWT_TICK_MAX                    0xffffffffUL  // has to correspond to maximum value representable as swt_TimeType 

#define SWT_COUNT_DOWN_TIMERS           5 // 0 ... 4 number of count-down timers available

typedef unsigned long swt_TimeType;     // data type for time representation 
                                        // (32 bit -> wrap arount every ~49 days)

//! Initialization method
/*! May return 'false' if failed */
bool swt_Init();

//! Busy wait for a specified amount of time  
void swt_Wait(swt_TimeType wait);

//! Returns current tick count. May wrap around at SWT_TICK_MAX
swt_TimeType swt_GetTickCount();

//! Sets new count down value for timer 'num'  
void swt_SetCountDownTimer(uint8_t num,swt_TimeType count);

//! Returns true if specified timer has reached zero
bool swt_IsCountDownTimerZero(uint8_t num);

//! Returns current timer value
swt_TimeType swt_GetCountDownTimer(uint8_t num);


//! Configures periodic timer to run a specified frequency 
void swt_SetupPeriodicTimer(uint16_t prescaler, uint16_t reload, callback_t irq_callback);

//! Configures periodic timer to run a specified frequency 
void swt_StopPeriodicTimer();

//! Set new reload value.
void swt_SetPeriodicTimerReload(uint16_t reload);

#endif
