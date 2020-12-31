#ifndef __CCTIMER_IRQ_H__
#define __CCTIMER_IRQ_H__

#define CCTIMER_NUM_IRQS 9

typedef enum{
  CCTIMER_IRQ_RESTART_P =               0,
  CCTIMER_IRQ_OVERFLOW_A =              1,
  CCTIMER_IRQ_OVERFLOW_B =              2,
  CCTIMER_IRQ_RESTART_A =               3,
  CCTIMER_IRQ_RESTART_B =               4,
  CCTIMER_IRQ_CAPTURE_A =               5,
  CCTIMER_IRQ_CAPTURE_B =               6,
  CCTIMER_IRQ_COMPARE_A =               7,
  CCTIMER_IRQ_COMPARE_B =               8
} cctimer_irq_t;

#endif
