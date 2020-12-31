
#include "adc_ctrl.h"

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void adc_ctrl_pwm_trigger_config(pwm_ch_t pwm_ch, uint16_t config) {

  switch (pwm_ch) {
    case PWM_CH0 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM0_CONFIG, config); break;
    case PWM_CH1 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM1_CONFIG, config); break;
    case PWM_CH2 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM2_CONFIG, config); break;
    case PWM_CH3 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM3_CONFIG, config); break;
  }
}

void adc_ctrl_reg_trigger(int adc_ch) {

  if ((adc_ch < 0) || (adc_ch >= 16)) {
    return;
  }
  WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_REG_TRIGGER, onehot16[adc_ch]);
}

void adc_ctrl_cyclic_mode_config(bool on) {

  adc_ctrl_control_t  control;

  control.val = READ_REG_U16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_CONTROL);
  control.bf.cyclic = on ? 1 : 0;
  WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_CONTROL, control.val);
}

void adc_ctrl_set_mux_delay(uint16_t delay) {

  WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_MUX_DELAY, (delay > 1023) ? 1023 : delay);
}

bool adc_ctrl_is_status_ok(int adc_ch) {

  if (adc_ch >= 16) {
    return false;
  }
  if (READ_REG_U16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_STATUS) & onehot16[adc_ch]) {
    return true;
  }
  return false;
}

void adc_ctrl_set_dma_base_address(uint16_t val) {

  WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_DMA_BASE_ADDR, val);
}

void adc_ctrl_set_sample_extension(uint8_t cycles, uint8_t cycles_vt) {

  adc_ctrl_sample_ext_t  adc_ctrl_sample_ext;

  adc_ctrl_sample_ext.val          = 0;
  adc_ctrl_sample_ext.bf.cycles    = cycles;
  adc_ctrl_sample_ext.bf.cycles_vt = cycles_vt;
  WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_SAMPLE_EXT, adc_ctrl_sample_ext.val);
}

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

#include "vic.h"
#include "vic_irq.h"

volatile static callback_t callback[ADC_CTRL_NUM_IRQS];

void adc_ctrl_handler_init(void) {

  irq_handler_init(VIC_IRQ_ADC_CTRL, ADC_CTRL_NUM_IRQS, (callback_t *)callback, BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_VENABLE);
}

