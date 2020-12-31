#include "sys_state.h"

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void sys_state_module_enable(sst_mod_enable_t modules, bool enable) {
  uint16_t module_enable_tmp;

  module_enable_tmp = READ_REG_U16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_MODULE_ENABLE);
  if (enable) {
    module_enable_tmp |=  modules;
  } else {
    module_enable_tmp &= ~modules;
  }
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_MODULE_ENABLE, module_enable_tmp);
}

 void sys_state_set_io23(sst_io2_sel_t sel_io2, sst_io3_sel_t sel_io3) {
  sys_state_control_t sys_state_control;
  sys_state_control.val = READ_REG_U16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL);
  sys_state_control.bf.io3_sel = sel_io3;
  sys_state_control.bf.io2_sel = sel_io2;
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL, sys_state_control.val);
}


void sys_state_set_sys_clk(sst_clk_sel_t sel) {
  sys_state_control_t sys_state_control;

  sys_state_control.val = READ_REG_U16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL);
  sys_state_control.bf.sys_clk_sel = sel;
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL, sys_state_control.val);
}

void sys_state_set_drv_strength(bool io) {
  sys_state_control_t sys_state_control;

  sys_state_control.val = READ_REG_U16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL);
  sys_state_control.bf.ds = io ? 1 : 0;
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL, sys_state_control.val);
}

void sys_state_set_ext_clk(bool io){
  sys_state_control_t sys_state_control;

  sys_state_control.val = READ_REG_U16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL);
  sys_state_control.bf.sel_clk_ext = io ? 1 : 0;
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL, sys_state_control.val);
}

uint16_t sys_state_get_reset_status(void) {
  return READ_REG_U16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_RESET_STATUS);
}

void sys_state_clear_reset_status(void) {
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_RESET_STATUS_CLEAR, 1);
}

void sys_state_reset_enable(sst_reset_enable_t resets) {
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_RESET_ENABLE, resets);
}

void sys_state_software_reset(void) {
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_SW_RESET, BIT_SYS_STATE_SW_RESET_SW_RESET);
}


void sys_state_set_calibration(uint8_t vref, uint8_t bgap, uint8_t sys_osc) {
  sys_state_calibration_t sys_state_calibration;

  sys_state_calibration.val = 0;
  sys_state_calibration.bf.cal_vref     = vref;
  sys_state_calibration.bf.cal_bgap     = bgap;
  sys_state_calibration.bf.cal_sys_osc  = sys_osc;
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CALIBRATION, sys_state_calibration.val);
}

void sys_state_set_calibration_lock(void) {
  WRITE_REG_16(BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CALIBRATION_LOCK, 1);
}
/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

#include "vic.h"
#include "vic_irq.h"

volatile static callback_t callback[SYS_STATE_NUM_IRQS];

void sys_state_handler_init(void) {

  irq_handler_init(VIC_IRQ_SYS_STATE, SYS_STATE_NUM_IRQS, (callback_t *)callback, BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_VENABLE);
}

