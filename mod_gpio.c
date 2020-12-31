 /* ------------------------------------------------------------------- */
 /** @file mod_gpio.c
  * @brief GPIO configuration and access module (code)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_gpio.c,v 1.1 2013/09/03 14:42:45 rpy Exp $
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

#include "api.h"
#include "mod_gpio.h"

//################################################################################
// GPIO

bool gpio_Init()
{
  sys_state_module_enable(SST_MOD_ENABLE_GPIO, true);

  gpio_set_output_enable(GPIO, GPIO_IO_4, true);
  gpio_set_output_enable(GPIO, GPIO_IO_5, true);
  gpio_set_output_enable(GPIO, GPIO_IO_6, true);
  gpio_set_output_enable(GPIO, GPIO_IO_7, true);
  
  return true;
}

void gpio_SetBit(uint8_t bitnr,bool flag)
{
//  if (bitnr<8) gpio_set_data_out(GPIO,(gpio_io_t)(1<<bitnr),flag);
}

