#ifndef HAVE_HV_CTRL_H
#define HAVE_HV_CTRL_H

#include "base.h"

#include "hv_ctrl_bf.h"
#include "hv_ctrl_irq.h"

#include "vic.h"

typedef enum {
  HV_CTRL_16BIT = 0,
  HV_CTRL_12BIT = 1,
  HV_CTRL_8BIT  = 2,
  HV_CTRL_1HOT  = 3
} hv_ctrl_mode_t;

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void hv_ctrl_set_post_shift_delay(uint16_t delay);
void hv_ctrl_cctimer_sel(uint16_t val);

void hv_ctrl_spi_configure(int baud_div, hv_ctrl_mode_t mode, int shift);

void    hv_ctrl_spi_send_16_wr(uint8_t addr, uint8_t wdata);
uint8_t hv_ctrl_spi_send_16_rd(uint8_t addr, uint8_t wdata);

void    hv_ctrl_spi_send_12_wr(uint8_t addr, uint8_t wdata);
uint8_t hv_ctrl_spi_send_12_rd(uint8_t addr, uint8_t wdata);

void    hv_ctrl_spi_send_8_wr(uint8_t addr, uint8_t wdata);
uint8_t hv_ctrl_spi_send_8_rd(uint8_t addr, uint8_t wdata);  // status byte read only

uint8_t hv_ctrl_get_status_byte(void);

/*RPY*/
void hv_ctrl_spi_wait_finish(); // wait for last transfer to finish 

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

void hv_ctrl_handler_init(void);

void hv_ctrl_handler_register(hv_ctrl_irq_t irq, callback_t callback);

void hv_ctrl_enable_irq(hv_ctrl_irq_t irq, bool enable);

hv_ctrl_irq_status_t hv_ctrl_get_irq_status(void);

void hv_ctrl_clear_all_irq_events(void);


#define hv_ctrl_handler_register(irq,cb)  irq_handler_register(VIC_IRQ_HV_CTRL,irq,cb)

#define hv_ctrl_enable_irq(irq,en)  {         \
  if (en) irq_enable(VIC_IRQ_HV_CTRL,irq);  \
  else    irq_disable(VIC_IRQ_HV_CTRL,irq); \
}

#define hv_ctrl_get_irq_status()  ((hv_ctrl_irq_status_t)(unsigned short)irq_get_status(VIC_IRQ_HV_CTRL))

#define hv_ctrl_clear_all_irq_events()  irq_clear_all_events(VIC_IRQ_HV_CTRL)

/*RPY*/
void hv_ctrl_irq_clear_event(int sno);

#endif /* HAVE_HV_CTRL_H */

