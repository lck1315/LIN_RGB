 /* ------------------------------------------------------------------- */
 /** @file mod_sci.c
  * @brief SCI configuration and access module (code)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_sci.c,v 1.1 2013/09/03 14:42:46 rpy Exp $
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
#include "mod_sci.h"

// #ifdef STDIO_SCI_HARD

//################################################################################
// SCI

//! Initialization method for SCI for stdio usage. 
bool stdio_Init(sci_baud baudrate)
{
  sys_state_module_enable(SST_MOD_ENABLE_SCI,true); 

  sci_reset_config((sci_cfg)0xff);
  sci_set_config(SCI_ENABLE_TRANSMITTER);
  sci_set_config(SCI_ENABLE_RECEIVER);
  sci_set_baud_rate((sci_baud)baudrate);
  sci_set_auto_mode(SCI_AUTO_OFF);

  return true;
}

int stdio_GetCharNonBlk()
{
  uint8_t val;
  bool rv=sci_receive_byte(&val,false);
  
  if (rv==false) return -1;
  return val;
}

int stdio_GetChar()
{
  uint8_t val;
  bool rv=sci_receive_byte(&val,true);
  
  if (rv==false) return -1;
  return val;
}


int stdio_GetLine(char *buffer,int len,bool echo)
{ 
  if (len==0 || buffer==NULL) return 0;
  
  int pos=0;
  while(pos<len)
  {    
    int b;
    
    b=stdio_GetChar();    
    if (b==-1) break;
    if (echo) stdio_PutChar(b);
    
    if (b==13) break;
    if (b==10) break;
    if (b==27) { pos=0; break; }
    
    buffer[pos]=b;
    pos++;    
  }
  
  if (pos>=len) pos=len-1;
  buffer[pos]=0;

  return pos;
}

//! Blocking write method
void stdio_PutChar(unsigned char ch)
{
   sci_transmit(ch); 
}

// #endif