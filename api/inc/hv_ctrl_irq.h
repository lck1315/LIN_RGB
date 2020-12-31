#ifndef __HV_CTRL_IRQ_H__
#define __HV_CTRL_IRQ_H__

#define HV_CTRL_NUM_IRQS 13

typedef enum{
  HV_CTRL_IRQ_RDATA_STATUS_0 =          0,
  HV_CTRL_IRQ_RDATA_STATUS_1 =          1,
  HV_CTRL_IRQ_RDATA_STATUS_2 =          2,
  HV_CTRL_IRQ_RDATA_STATUS_3 =          3,
  HV_CTRL_IRQ_RDATA_STATUS_4 =          4,
  HV_CTRL_IRQ_RDATA_STATUS_5 =          5,
  HV_CTRL_IRQ_RDATA_STATUS_6 =          6,
  HV_CTRL_IRQ_RDATA_STATUS_7 =          7,
  HV_CTRL_IRQ_MISO_IRQ =                8,
  HV_CTRL_IRQ_EOT =                     9,
  HV_CTRL_IRQ_EOT_SEND =                10,
  HV_CTRL_IRQ_READY_WR =                11,
  HV_CTRL_IRQ_READY_RD =                12
} hv_ctrl_irq_t;

#endif
