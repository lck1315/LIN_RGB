 /* ------------------------------------------------------------------- */
 /** @file mod_gpio.h
  * @brief GPIO configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_gpio.h,v 1.1 2013/09/03 14:42:45 rpy Exp $
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

#ifndef _MOD_GPIO_H_
#define _MOD_GPIO_H_

#include "api.h"


//################################################################################
// GPIO

// Current setup configures only GPIO bits 4...7!

// these bits are set, if code of corresponding irq routine is executed. 
#define GPIO_FLAG_ADC_COPY_Sx   4 // ... 7 

//! Initialize GPIO registers 
/*! Returns false if init has failed */
bool gpio_Init();

//! Set GPIO pin 'bitbr' to state 'flag' (true->on, false->off)
void gpio_SetBit(uint8_t bitnr,bool flag);

#endif 

