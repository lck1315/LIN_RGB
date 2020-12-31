#ifndef HAVE_PWM_H
#define HAVE_PWM_H

#include "base.h"

#include "pwm_bf.h"
#include "pwm_irq.h"

#include "vic.h"

typedef enum {
  PWM_CH0,
  PWM_CH1,
  PWM_CH2,
  PWM_CH3,
} pwm_ch_t;

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void pwm_config_prescaler(pwm_ch_t ch, uint8_t  val);
void pwm_config_period   (pwm_ch_t ch, uint16_t val);
void pwm_config_start    (pwm_ch_t ch, uint16_t val);
void pwm_config_stop     (pwm_ch_t ch, uint16_t val);
void pwm_config_polarity (pwm_ch_t ch, bool inverse);

void pwm_enable(pwm_ch_t ch, bool enable);

uint16_t pwm_get_counter(pwm_ch_t ch);

void pwm_set_trigger_delay(pwm_ch_t ch, uint16_t val);

/*RPY*/
void pwm_config_term(pwm_ch_t ch, bool on);
void pwm_config_zero(pwm_ch_t ch, bool on);
bool pwm_status_running();


/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

void pwm_handler_init(void);

void pwm_handler_register(pwm_irq_t irq, callback_t callback);

void pwm_enable_irq(pwm_irq_t irq, bool enable);

pwm_irq_status_t pwm_get_irq_status(void);

void pwm_clear_all_irq_events(void);


#define pwm_handler_register(irq,cb)  irq_handler_register(VIC_IRQ_PWM,irq,cb)

#define pwm_enable_irq(irq,en)  {         \
  if (en) irq_enable(VIC_IRQ_PWM,irq);  \
  else    irq_disable(VIC_IRQ_PWM,irq); \
}

#define pwm_get_irq_status()  ((pwm_irq_status_t)(unsigned short)irq_get_status(VIC_IRQ_PWM))

#define pwm_clear_all_irq_events()  irq_clear_all_events(VIC_IRQ_PWM)

#endif /* HAVE_PWM_H */

