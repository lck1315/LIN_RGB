
#include "hv_ctrl.h"

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void hv_ctrl_set_post_shift_delay(uint16_t delay) {

  WRITE_REG_16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_POST_SHIFT_DELAY, (delay > 255) ? 255 : delay);
}

void hv_ctrl_cctimer_sel(uint16_t val) {

  WRITE_REG_16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_CCTIMER_SEL, val);
}

void hv_ctrl_spi_configure(int baud_div, hv_ctrl_mode_t mode, int shift) {

  hv_ctrl_spi_config_t  hv_ctrl_spi_config;

  hv_ctrl_spi_config.val = 0;
  hv_ctrl_spi_config.bf.baud_div = (baud_div > 63) ? 63 : baud_div;
  hv_ctrl_spi_config.bf.mode     = mode;
  hv_ctrl_spi_config.bf.shift    = (shift > 7) ? 7 : shift;

  WRITE_REG_16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_CONFIG, hv_ctrl_spi_config.val);
}

void hv_ctrl_spi_send_16_wr(uint8_t addr, uint8_t wdata) {

  hv_ctrl_spi_send_t  hv_ctrl_spi_send;

  while (!(READ_REG_U16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_STATUS) & BIT_HV_CTRL_IRQ_STATUS_READY_WR));

  hv_ctrl_spi_send.val      = 0;
  hv_ctrl_spi_send.bf.write = 1;
  hv_ctrl_spi_send.bf.addr  = addr;
  hv_ctrl_spi_send.bf.data  = wdata;

  WRITE_REG_16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_SEND, hv_ctrl_spi_send.val);
}

void hv_ctrl_spi_send_12_wr(uint8_t addr, uint8_t wdata) {

  hv_ctrl_spi_send_16_wr(addr, ((wdata & 0xF) << 4));
}

void hv_ctrl_spi_send_8_wr(uint8_t addr, uint8_t wdata) {

  hv_ctrl_spi_send_16_rd((addr << 4), ((wdata & 0x1F) << 3));
}

static volatile uint8_t status_byte = 0;

uint8_t hv_ctrl_spi_send_16_rd(uint8_t addr, uint8_t wdata) {

  hv_ctrl_spi_send_t    hv_ctrl_spi_send;
  hv_ctrl_spi_rdata_t   hv_ctrl_spi_rdata;

  while (!(READ_REG_U16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_STATUS) & BIT_HV_CTRL_IRQ_STATUS_READY_WR));

  hv_ctrl_spi_send.val      = 0;
  hv_ctrl_spi_send.bf.write = 0;
  hv_ctrl_spi_send.bf.addr  = addr;
  hv_ctrl_spi_send.bf.data  = wdata;

  WRITE_REG_16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_SEND, hv_ctrl_spi_send.val);

  while (!(READ_REG_U16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_STATUS) & BIT_HV_CTRL_IRQ_STATUS_READY_RD));

  hv_ctrl_spi_rdata.val = READ_REG_U16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_RDATA);
  status_byte = (uint8_t)hv_ctrl_spi_rdata.bf.status;
  return (uint8_t)hv_ctrl_spi_rdata.bf.data;
}


/*RPY*/
void hv_ctrl_spi_wait_finish() 
{ 
  while (!(READ_REG_U16(BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_STATUS) & BIT_HV_CTRL_IRQ_STATUS_READY_RD));
}


uint8_t hv_ctrl_spi_send_12_rd(uint8_t addr, uint8_t wdata) {

  return (hv_ctrl_spi_send_16_rd(addr, ((wdata & 0xF) << 4)) >> 4);
}

uint8_t hv_ctrl_spi_send_8_rd(uint8_t addr, uint8_t wdata) {

  hv_ctrl_spi_send_16_rd((addr << 4), ((wdata & 0x1F) << 3));
  return (status_byte & 0x1F);
}

uint8_t hv_ctrl_get_status_byte(void) {

  return status_byte;
}

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

#include "vic.h"
#include "vic_irq.h"

volatile static callback_t callback[HV_CTRL_NUM_IRQS];

void hv_ctrl_handler_init(void) {

  irq_handler_init(VIC_IRQ_HV_CTRL, HV_CTRL_NUM_IRQS, (callback_t *)callback, BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_VENABLE);
}

/*RPY*/ //clear dedicated IRQ event
void hv_ctrl_irq_clear_event(int sno)
{  
  irq_clear_event(VIC_IRQ_HV_CTRL,sno);
}
