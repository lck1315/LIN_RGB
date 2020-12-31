#ifndef __SYS_STATE_IRQ_H__
#define __SYS_STATE_IRQ_H__

#define SYS_STATE_NUM_IRQS 7

typedef enum{
  SYS_STATE_IRQ_WATCHDOG =              0,
  SYS_STATE_IRQ_SOFTWARE =              1,
  SYS_STATE_IRQ_SRAM_PARITY =           2,
  SYS_STATE_IRQ_FLASH_2BIT_ERR =        3,
  SYS_STATE_IRQ_FLASH_1BIT_ERR =        4,
  SYS_STATE_IRQ_FLASH_2BIT_ERR_EE =     5,
  SYS_STATE_IRQ_FLASH_1BIT_ERR_EE =     6
} sys_state_irq_t;

#endif
