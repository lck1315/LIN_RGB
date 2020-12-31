#ifndef __VIC_IRQ_H__
#define __VIC_IRQ_H__

#define VIC_NUM_IRQS 10

typedef enum{
  VIC_IRQ_SYS_STATE =                   0,
  VIC_IRQ_WDOG =                        1,
  VIC_IRQ_DIVIDER =                     2,
  VIC_IRQ_HV_CTRL =                     3,
  VIC_IRQ_ADC_CTRL =                    4,
  VIC_IRQ_PWM =                         5,
  VIC_IRQ_SCI =                         6,
  VIC_IRQ_SWTIMER =                     7,
  VIC_IRQ_GPIO =                        8,
  VIC_IRQ_CCTIMER =                     9
} vic_irq_t;

#endif
