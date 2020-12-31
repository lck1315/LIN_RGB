 /* ------------------------------------------------------------------- */
 /** @file mod_sys.c
  * @brief global system settings file (code)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_sys.c,v 1.1 2013/09/03 14:42:46 rpy Exp $
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
#include "mod_sys.h"

//################################################################################
// System 

// Initialize global system settings
bool sys_Init()
{
  vic_handler_init();
  sys_state_set_sys_clk(SST_CLK_SEL_24_MHz);
    
  sys_state_set_io23(SST_IO2_SEL_GPIO,SST_IO3_SEL_GPIO); 
    
  return true;
}


//################################################################################
