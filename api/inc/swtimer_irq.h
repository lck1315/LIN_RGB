#ifndef __SWTIMER_IRQ_H__
#define __SWTIMER_IRQ_H__

#define SWTIMER_NUM_IRQS 4

typedef enum{
  SWTIMER_IRQ_EVT_CNT_ZERO_0 =          0,
  SWTIMER_IRQ_EVT_CNT_ZERO_1 =          1,
  SWTIMER_IRQ_EVT_DIV_ZERO_0 =          2,
  SWTIMER_IRQ_EVT_DIV_ZERO_1 =          3
} swtimer_irq_t;

#endif
