 /* ------------------------------------------------------------------- */
 /** @file mod_sys.h
  * @brief global system settings file (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_sys.h,v 1.1 2013/09/03 14:42:46 rpy Exp $
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


#ifndef _MOD_SYS_H_
#define _MOD_SYS_H_

#include "api.h"

//################################################################################
// System 

#define eint() asm("eint") // Macros for H430 global IRQ enbale/disable
#define dint() asm("dint")

//! Initialize global system settings
/*! Returns 'false' if initialzation fails */ 
bool sys_Init();

#endif
