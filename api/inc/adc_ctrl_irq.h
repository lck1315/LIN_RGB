#ifndef __ADC_CTRL_IRQ_H__
#define __ADC_CTRL_IRQ_H__

#define ADC_CTRL_NUM_IRQS 21

typedef enum{
  ADC_CTRL_IRQ_EVT_UPDATE_0 =           0,
  ADC_CTRL_IRQ_EVT_UPDATE_1 =           1,
  ADC_CTRL_IRQ_EVT_UPDATE_2 =           2,
  ADC_CTRL_IRQ_EVT_UPDATE_3 =           3,
  ADC_CTRL_IRQ_EVT_UPDATE_4 =           4,
  ADC_CTRL_IRQ_EVT_UPDATE_5 =           5,
  ADC_CTRL_IRQ_EVT_UPDATE_6 =           6,
  ADC_CTRL_IRQ_EVT_UPDATE_7 =           7,
  ADC_CTRL_IRQ_EVT_UPDATE_8 =           8,
  ADC_CTRL_IRQ_EVT_UPDATE_9 =           9,
  ADC_CTRL_IRQ_EVT_UPDATE_10 =          10,
  ADC_CTRL_IRQ_EVT_UPDATE_11 =          11,
  ADC_CTRL_IRQ_EVT_UPDATE_12 =          12,
  ADC_CTRL_IRQ_EVT_UPDATE_13 =          13,
  ADC_CTRL_IRQ_EVT_UPDATE_14 =          14,
  ADC_CTRL_IRQ_EVT_UPDATE_15 =          15,
  ADC_CTRL_IRQ_EVT_COPY_0 =             16,
  ADC_CTRL_IRQ_EVT_COPY_1 =             17,
  ADC_CTRL_IRQ_EVT_COPY_2 =             18,
  ADC_CTRL_IRQ_EVT_COPY_3 =             19,
  ADC_CTRL_IRQ_READY =                  20
} adc_ctrl_irq_t;

#endif
