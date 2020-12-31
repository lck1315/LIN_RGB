#ifndef HAVE_ADC_CTRL_H
#define HAVE_ADC_CTRL_H

#include "base.h"
#include "utils.h"

#include "pwm.h"

#include "adc_ctrl_bf.h"
#include "adc_ctrl_irq.h"

#include "vic.h"

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void adc_ctrl_pwm_trigger_config(pwm_ch_t pwm_ch, uint16_t config);

void adc_ctrl_reg_trigger(int adc_ch);

void adc_ctrl_cyclic_mode_config(bool on);

void adc_ctrl_set_mux_delay(uint16_t delay);

bool adc_ctrl_is_status_ok(int adc_ch);

void adc_ctrl_set_dma_base_address(uint16_t val);

void adc_ctrl_set_sample_extension(uint8_t cycles, uint8_t cycles_vt);

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

void adc_ctrl_handler_init(void);

void adc_ctrl_handler_register(adc_ctrl_irq_t irq, callback_t callback);

void adc_ctrl_enable_irq(adc_ctrl_irq_t irq, bool enable);

adc_ctrl_irq_status0_t adc_ctrl_get_irq_status(void);

void adc_ctrl_clear_all_irq_events(void);


#define adc_ctrl_handler_register(irq,cb)  irq_handler_register(VIC_IRQ_ADC_CTRL,irq,cb)

#define adc_ctrl_enable_irq(irq,en)  {         \
  if (en) irq_enable(VIC_IRQ_ADC_CTRL,irq);  \
  else    irq_disable(VIC_IRQ_ADC_CTRL,irq); \
}

#define adc_ctrl_get_irq_status()  ((adc_ctrl_irq_status0_t)(unsigned short)irq_get_status(VIC_IRQ_ADC_CTRL))

#define adc_ctrl_clear_all_irq_events()  irq_clear_all_events(VIC_IRQ_ADC_CTRL)

#endif /* HAVE_ADC_CTRL_H */

