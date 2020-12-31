 /* ------------------------------------------------------------------- */
 /** @file mod_hvctrl.c
  * @brief HV_CTRL configuration and access module (code)
  *
  * Purpose:
  *    
  *
  * @section history_sec Revision History
  * $Id: mod_hvctrl.c,v 1.1 2013/09/03 14:42:45 rpy Exp $
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
#include "mod_hvctrl.h"

//################################################################################
// HV CTRL

#define HV_REG_ADC_MUX        (0x00<<4)
#define HV_REG_LIN_AA         (0x01<<4)
#define HV_REG_LIN_CFG        (0x02<<4)
#define HV_REG_LED_DRIVER     (0x03<<4)
#define HV_REG_POWER          (0x04<<4)
#define HV_REG_CAL_I5U        (0x05<<4)
#define HV_REG_CAL_5V         (0x06<<4)

#define HV_DATA_MASK          0x1f
#define HV_DATA_SHIFT         3

// -------------------------------------------------------------------------------


// -------------------------------------------------------------------------------

void hvctrl_SetAdcMux(uint8_t ch)
{
  hv_ctrl_spi_send_16_wr(HV_REG_ADC_MUX,(ch&HV_DATA_MASK)<<HV_DATA_SHIFT); 
}

void hvctrl_SetLINAutoAddr(bool on30k,bool on2mA,bool onAmp)
{
  uint8_t data=(on30k?0x04:0x00) | (on2mA?0x02:0x00) | (onAmp?0x01:0x00);
     
  hv_ctrl_spi_send_16_wr(HV_REG_LIN_AA,data<<HV_DATA_SHIFT); 
}

void hvctrl_SetLINConfig(bool onTrans,bool onHS)
{
  uint8_t data=(onTrans?0x04:0x00) | (onHS?0x01:0x00);
     
  hv_ctrl_spi_send_16_wr(HV_REG_LIN_CFG,data<<HV_DATA_SHIFT); 
}

void hvctrl_SetLEDDrv(bool enable,bool pull,bool slew)
{
  uint8_t data=(enable?0x08:0x00) | (pull?0x02:0x00) | (slew?0x01:0x00);
     
  hv_ctrl_spi_send_16_wr(HV_REG_LED_DRIVER,data<<HV_DATA_SHIFT); 
}

void hvctrl_SetPower(bool stdby,bool sleep)
{
  uint8_t data=(stdby?0x02:0x00) | (sleep?0x01:0x00);
     
  hv_ctrl_spi_send_16_wr(HV_REG_POWER,data<<HV_DATA_SHIFT); 
}

void hvctrl_CalI5U(uint8_t cal)
{
  hv_ctrl_spi_send_16_wr(HV_REG_CAL_I5U,(cal&HV_DATA_MASK)<<HV_DATA_SHIFT);   
}

void hvctrl_Cal5V(uint8_t cal)
{
  hv_ctrl_spi_send_16_wr(HV_REG_CAL_5V,(cal&HV_DATA_MASK)<<HV_DATA_SHIFT);   
}


//! Init method
bool hvctrl_Init(void)
{
  
  hv_ctrl_handler_init();        

  
  hv_ctrl_spi_configure(/* div */ 5, /* mode */ HV_CTRL_8BIT, /* shift */ 3);     
                                    // div=5 -> 24 MHz / (5+1) = 4 MHz / 2 = 2 Mbit/s
                                    // shoft=3 -> mux sel requied to be in the upper 5 bits of data word (????)

  hv_ctrl_set_post_shift_delay(HVCTRL_POST_SHIFT_DELAY); 
    
  hvctrl_SetLINConfig(true,false);     // enable LIN, no HS mode
  hvctrl_SetLEDDrv(true,true,false);   // enable LED driver, pull-down on, no slew control. 

  return true;
}

