 /* ------------------------------------------------------------------- */
 /** @file mod_hvctrl.h
  * @brief HV_CTRL configuration and access module (header)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_hvctrl.h,v 1.1 2013/09/03 14:42:45 rpy Exp $
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
  * @created      2012/06/15
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

#ifndef _MOD_HVCTRL_H_
#define _MOD_HVCTRL_H_

#include "api.h"

//################################################################################
// HV CTRL

// this module implement the interface to HV part. 

#define HVCTRL_POST_SHIFT_DELAY   208      // ~8.5us (10us mux_delay + 0.2us sample time - ~2.5us spi_tansfer (8bit+ovh @ 4MHz)) + 0.8us some margin (due to sample_ext)

//! Initialize HV interface
/*! May return 'false' if failed */
bool hvctrl_Init(void);

// -------------------------------------------------------------------------------


/*! Sets manually ADC channel to sample. */ 
void hvctrl_SetAdcMux(uint8_t ch);

/*! Sets AA pull-up and current source configuration */
void hvctrl_SetLINAutoAddr(bool on30k,bool on2mA,bool onAmp);

/*! Sets LIN configuration */
void hvctrl_SetLINConfig(bool onTrans,bool onHS);

/*! Controls LED driver state */
void hvctrl_SetLEDDrv(bool enable,bool pull,bool slew);

/*! Sets power state */
void hvctrl_SetPower(bool stdby,bool sleep);

/*! Sets callibration value */ 
void hvctrl_CalI5U(uint8_t cal);

/*! Sets callibration value */ 
void hvctrl_Cal5V(uint8_t cal);

#endif
