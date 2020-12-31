#ifndef __GPIO_IRQ_H__
#define __GPIO_IRQ_H__

#define GPIO_NUM_IRQS 16

typedef enum{
  GPIO_IRQ_EVT_POS_0 =                  0,
  GPIO_IRQ_EVT_NEG_0 =                  1,
  GPIO_IRQ_EVT_POS_1 =                  2,
  GPIO_IRQ_EVT_NEG_1 =                  3,
  GPIO_IRQ_EVT_POS_2 =                  4,
  GPIO_IRQ_EVT_NEG_2 =                  5,
  GPIO_IRQ_EVT_POS_3 =                  6,
  GPIO_IRQ_EVT_NEG_3 =                  7,
  GPIO_IRQ_EVT_POS_4 =                  8,
  GPIO_IRQ_EVT_NEG_4 =                  9,
  GPIO_IRQ_EVT_POS_5 =                  10,
  GPIO_IRQ_EVT_NEG_5 =                  11,
  GPIO_IRQ_EVT_POS_6 =                  12,
  GPIO_IRQ_EVT_NEG_6 =                  13,
  GPIO_IRQ_EVT_POS_7 =                  14,
  GPIO_IRQ_EVT_NEG_7 =                  15
} gpio_irq_t;

#endif
