#ifndef HAVE_SWTIMER_H
#define HAVE_SWTIMER_H

#include "base.h"

#include "swtimer_bf.h"
#include "swtimer_irq.h"

#include "vic.h"

#define TIMERS  (SWTIMER_NUM_IRQS >> 1)

typedef enum {
  SWTIMER_0  = 0,
  SWTIMER_1  = 1,
  SWTIMER_2  = 2,
  SWTIMER_3  = 3,
  SWTIMER_4  = 4,
  SWTIMER_5  = 5
} swtimer_dev_t;

typedef enum {
  SWTIMER_RESTART_0     = (1 <<           SWTIMER_0),
  SWTIMER_RESTART_1     = (1 <<           SWTIMER_1),
  SWTIMER_RESTART_2     = (1 <<           SWTIMER_2),
  SWTIMER_RESTART_3     = (1 <<           SWTIMER_3),
  SWTIMER_RESTART_4     = (1 <<           SWTIMER_4),
  SWTIMER_RESTART_5     = (1 <<           SWTIMER_5),
  SWTIMER_PRE_RESTART_0 = (1 << (TIMERS + SWTIMER_0)),
  SWTIMER_PRE_RESTART_1 = (1 << (TIMERS + SWTIMER_1)),
  SWTIMER_PRE_RESTART_2 = (1 << (TIMERS + SWTIMER_2)),
  SWTIMER_PRE_RESTART_3 = (1 << (TIMERS + SWTIMER_3)),
  SWTIMER_PRE_RESTART_4 = (1 << (TIMERS + SWTIMER_4)),
  SWTIMER_PRE_RESTART_5 = (1 << (TIMERS + SWTIMER_5)),
} swtimer_cmd_t;

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void swtimer_set_command (swtimer_cmd_t command);

void swtimer_enable (swtimer_dev_t swtimer_dev, bool enable);

void swtimer_autoreload_enable (swtimer_dev_t swtimer_dev, bool enable);

void swtimer_set_counter_reload (swtimer_dev_t swtimer_dev, uint16_t val);

void swtimer_set_prescaler_reload (swtimer_dev_t swtimer_dev, uint16_t val);

uint16_t swtimer_get_counter_value (swtimer_dev_t swtimer_dev);

uint16_t swtimer_get_reload_value (swtimer_dev_t swtimer_dev);

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

void swtimer_handler_init(void);

void swtimer_handler_register(swtimer_irq_t irq, callback_t callback);

void swtimer_enable_irq(swtimer_irq_t irq, bool enable);

swtimer_irq_status_t swtimer_get_irq_status(void);

void swtimer_clear_all_irq_events(void);


#define swtimer_handler_register(irq,cb)  irq_handler_register(VIC_IRQ_SWTIMER,irq,cb)

#define swtimer_enable_irq(irq,en)  {         \
  if (en) irq_enable(VIC_IRQ_SWTIMER,irq);  \
  else    irq_disable(VIC_IRQ_SWTIMER,irq); \
}

#define swtimer_get_irq_status()  (swtimer_irq_status_t)(unsigned short)irq_get_status(VIC_IRQ_SWTIMER)

#define swtimer_clear_all_irq_events()  irq_clear_all_events(VIC_IRQ_SWTIMER)

#endif /* HAVE_SWTIMER_H */

