#ifndef __PWM_IRQ_H__
#define __PWM_IRQ_H__

#define PWM_NUM_IRQS 12

typedef enum{
  PWM_IRQ_EVT_PERIOD0 =                 0,
  PWM_IRQ_EVT_START0 =                  1,
  PWM_IRQ_EVT_STOP0 =                   2,
  PWM_IRQ_EVT_PERIOD1 =                 3,
  PWM_IRQ_EVT_START1 =                  4,
  PWM_IRQ_EVT_STOP1 =                   5,
  PWM_IRQ_EVT_PERIOD2 =                 6,
  PWM_IRQ_EVT_START2 =                  7,
  PWM_IRQ_EVT_STOP2 =                   8,
  PWM_IRQ_EVT_PERIOD3 =                 9,
  PWM_IRQ_EVT_START3 =                  10,
  PWM_IRQ_EVT_STOP3 =                   11
} pwm_irq_t;

#endif
