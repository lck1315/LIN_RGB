#ifndef __SCI_IRQ_H__
#define __SCI_IRQ_H__

#define SCI_NUM_IRQS 12

typedef enum{
  SCI_IRQ_EVT_BREAK =                   0,
  SCI_IRQ_EVT_MEAS =                    1,
  SCI_IRQ_RECEIVE =                     2,
  SCI_IRQ_TRANSMIT =                    3,
  SCI_IRQ_RXD_FALLING =                 4,
  SCI_IRQ_RXD_RISING =                  5,
  SCI_IRQ_TXD_TIMEOUT =                 6,
  SCI_IRQ_SCI_TIMER_CMP =               7,
  SCI_IRQ_SCI_TIMER_OV =                8,
  SCI_IRQ_TX_DMA_FINISHED =             9,
  SCI_IRQ_RX_DMA_FINISHED =             10,
  SCI_IRQ_BUS_COLLISION =               11
} sci_irq_t;

#endif
