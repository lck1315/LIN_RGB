#ifndef HAVE_SYS_STATE_H
#define HAVE_SYS_STATE_H

#include "base.h"

#include "sys_state_bf.h"
#include "sys_state_irq.h"

#include "vic.h"

typedef enum {
  SST_MOD_ENABLE_SCI     = (1 << 0),
  SST_MOD_ENABLE_GPIO    = (1 << 1),
  SST_MOD_ENABLE_CCTIMER = (1 << 2),
} sst_mod_enable_t;

typedef enum {
  SST_RESET_STATUS_POR               = (1 << 0),
  SST_RESET_STATUS_VDDIO_OK          = (1 << 1),
  SST_RESET_STATUS_VDDC_OK           = (1 << 2),
  SST_RESET_STATUS_NRST              = (1 << 3),
  SST_RESET_STATUS_NRSTD2D           = (1 << 4),
  SST_RESET_STATUS_SYS_CLK_FAIL      = (1 << 5),
  SST_RESET_STATUS_WATCHDOG          = (1 << 6),
  SST_RESET_STATUS_SOFTWARE          = (1 << 7),
  SST_RESET_STATUS_SRAM_PARITY       = (1 << 8),
  SST_RESET_STATUS_FLASH_2BIT_ERR    = (1 << 9),
  SST_RESET_STATUS_FLASH_1BIT_ERR    = (1 << 10),
  SST_RESET_STATUS_FLASH_2BIT_ERR_EE = (1 << 11),
  SST_RESET_STATUS_FLASH_1BIT_ERR_EE = (1 << 12),
} sst_reset_status_t;

typedef enum {
  SST_RESET_ENABLE_WATCHDOG          = (1 << 0),
  SST_RESET_ENABLE_SOFTWARE          = (1 << 1),
  SST_RESET_ENABLE_SRAM_PARITY       = (1 << 2),
  SST_RESET_ENABLE_FLASH_2BIT_ERR    = (1 << 3),
  SST_RESET_ENABLE_FLASH_1BIT_ERR    = (1 << 4),
  SST_RESET_ENABLE_FLASH_2BIT_ERR_EE = (1 << 5),
  SST_RESET_ENABLE_FLASH_1BIT_ERR_EE = (1 << 6),
} sst_reset_enable_t;

typedef enum {
  SST_IO2_SEL_GPIO     = 0,
  SST_IO2_SEL_SCI_TXD  = 1,
  SST_IO2_SEL_CCT_MEAS = 2,
} sst_io2_sel_t;

typedef enum {
  SST_IO3_SEL_GPIO     = 0,
  SST_IO3_SEL_SCI_RXD  = 1,
  SST_IO3_SEL_CCT_PWM  = 2,
  SST_IO3_SEL_EXT_CLK  = 3,
} sst_io3_sel_t;

typedef enum {
  SST_CLK_SEL_24_MHz = 0,
  SST_CLK_SEL_12_MHz = 1,
  SST_CLK_SEL_8_MHz  = 2,
  SST_CLK_SEL_4_MHz  = 3,
} sst_clk_sel_t;

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void sys_state_module_enable(sst_mod_enable_t modules, bool enable);

void sys_state_set_sys_clk(sst_clk_sel_t sel);
void sys_state_set_io23(sst_io2_sel_t sel_io2, sst_io3_sel_t sel_io3);
void sys_state_set_drv_strength(bool io);
void sys_state_set_ext_clk(bool io);

uint16_t sys_state_get_reset_status(void);
void     sys_state_clear_reset_status(void);
void     sys_state_reset_enable(sst_reset_enable_t resets);

void     sys_state_software_reset(void);

void sys_state_set_calibration(uint8_t vref, uint8_t bgap, uint8_t sys_osc);
void sys_state_set_calibration_lock(void);

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

void sys_state_handler_init(void);

void sys_state_handler_register(sys_state_irq_t irq, callback_t callback);

void sys_state_enable_irq(sys_state_irq_t irq, bool enable);

sys_state_irq_status_t sys_state_get_irq_status(void);

void sys_state_clear_all_irq_events(void);

#define sys_state_handler_register(irq,cb)  irq_handler_register(VIC_IRQ_SYS_STATE,irq,cb)

#define sys_state_enable_irq(irq,en)  {         \
  if (en) irq_enable(VIC_IRQ_SYS_STATE,irq);  \
  else    irq_disable(VIC_IRQ_SYS_STATE,irq); \
}

#define sys_state_get_irq_status()  ((sys_state_irq_status_t)(unsigned short)irq_get_status(VIC_IRQ_SYS_STATE))

#define sys_state_clear_all_irq_events()  irq_clear_all_events(VIC_IRQ_SYS_STATE)

#endif /* HAVE_SYS_STATE_H */

