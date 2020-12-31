 /* ------------------------------------------------------------------- */
 /** @file mod_sci.h
  * @brief SCI configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_sci.h,v 1.1 2013/09/03 14:42:46 rpy Exp $
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


#ifndef _MOD_SCI_H_
#define _MOD_SCI_H_

#include "api.h"

//################################################################################
// SCI

#define STDIO_SCI_BAUD SCI_BAUD_24MHZ_19200

//! Initialization method for SCI for stdio usage. 
/*! Returns 'false' if initialization fails */
bool stdio_Init(sci_baud baudrate);

//! Non-blocking read method
/*! return -1 if no character is waiting in receiver buffer */
int stdio_GetCharNonBlk();

//! Blocking read method
/*! return -1 if some error occured */
int stdio_GetChar();

//! Reads data into buffer until 'len' characters read or CR/NL occures, ESC cancels input
/*! returns number of characters read */
int stdio_GetLine(char *buffer,int len,bool echo);

//! Blocking write method
void stdio_PutChar(unsigned char ch);

#endif
