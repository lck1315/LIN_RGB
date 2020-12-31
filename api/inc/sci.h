#ifndef __SCI_H__
#define __SCI_H__

#include "base.h"

#include "sci_bf.h"
#include "sci_irq.h"

#include "vic.h"

#define P52133

/* ======================================================================= */
/* SCI constants                                                           */
/* ======================================================================= */

typedef enum
{
  SCI_FRAME_ERROR = 0x0001,
  SCI_MEAS_FINISHED = 0x0002,
  SCI_MEAS_RUNNING = 0x0004,
  SCI_RECEIVE_OVERRUN = 0x0008,
  SCI_BREAK_RECEIVED = 0x0010,
  SCI_RECEIVE_DATAREG_FULL = 0x0020,
  SCI_TRANSMIT_COMPLETE = 0x0040,
  SCI_TRANSMIT_DATAREG_EMPTY = 0x0080,
  SCI_AUTO_MEAS_TRIGGERED = 0x0100,
  SCI_AUTO_BAUD_TRIGGERED = 0x0200,
  SCI_SYNC_ERROR = 0x0400,
} sci_status;

typedef enum
{
  SCI_SEND_BREAK = 0x01,
  SCI_ENABLE_MEAS_IRQ = 0x02,
  SCI_ENABLE_RECEIVER = 0x04,
  SCI_ENABLE_TRANSMITTER = 0x08,
  SCI_ENABLE_BREAK_IRQ = 0x10,
  SCI_ENABLE_RECEIVE_IRQ = 0x20,
  SCI_ENABLE_LIN_MODE = 0x40,
  SCI_ENABLE_TRANSMIT_IRQ = 0x80
} sci_cfg;

typedef enum
{
  SCI_BAUD_8MHZ_2400 = 6668,
  SCI_BAUD_8MHZ_4800 = 3334,
  SCI_BAUD_8MHZ_9600 = 1667,
  SCI_BAUD_8MHZ_19200 = 833,
  SCI_BAUD_8MHZ_20000 = 800,
  SCI_BAUD_8MHZ_28800 = 556,
  SCI_BAUD_8MHZ_38400 = 417,
  SCI_BAUD_8MHZ_48000 = 333,
  SCI_BAUD_8MHZ_57600 = 278,
  SCI_BAUD_8MHZ_115200 = 139
} sci_baud;

#define SCI_BAUD_4MHZ_2400 ((SCI_BAUD_8MHZ_2400)*3 / 6)
#define SCI_BAUD_4MHZ_4800 ((SCI_BAUD_8MHZ_4800)*3 / 6)
#define SCI_BAUD_4MHZ_9600 ((SCI_BAUD_8MHZ_9600)*3 / 6)
#define SCI_BAUD_4MHZ_19200 ((SCI_BAUD_8MHZ_19200)*3 / 6)
#define SCI_BAUD_4MHZ_20000 ((SCI_BAUD_8MHZ_20000)*3 / 6)
#define SCI_BAUD_4MHZ_28800 ((SCI_BAUD_8MHZ_28800)*3 / 6)
#define SCI_BAUD_4MHZ_38400 ((SCI_BAUD_8MHZ_38400)*3 / 6)
#define SCI_BAUD_4MHZ_48000 ((SCI_BAUD_8MHZ_48000)*3 / 6)
#define SCI_BAUD_4MHZ_57600 ((SCI_BAUD_8MHZ_57600)*3 / 6)
#define SCI_BAUD_4MHZ_115200 ((SCI_BAUD_8MHZ_115200)*3 / 6)

#define SCI_BAUD_12MHZ_2400 ((SCI_BAUD_8MHZ_2400)*3 / 2)
#define SCI_BAUD_12MHZ_4800 ((SCI_BAUD_8MHZ_4800)*3 / 2)
#define SCI_BAUD_12MHZ_9600 ((SCI_BAUD_8MHZ_9600)*3 / 2)
#define SCI_BAUD_12MHZ_19200 ((SCI_BAUD_8MHZ_19200)*3 / 2)
#define SCI_BAUD_12MHZ_20000 ((SCI_BAUD_8MHZ_20000)*3 / 2)
#define SCI_BAUD_12MHZ_28800 ((SCI_BAUD_8MHZ_28800)*3 / 2)
#define SCI_BAUD_12MHZ_38400 ((SCI_BAUD_8MHZ_38400)*3 / 2)
#define SCI_BAUD_12MHZ_48000 ((SCI_BAUD_8MHZ_48000)*3 / 2)
#define SCI_BAUD_12MHZ_57600 ((SCI_BAUD_8MHZ_57600)*3 / 2)
#define SCI_BAUD_12MHZ_115200 ((SCI_BAUD_8MHZ_115200)*3 / 2)

#define SCI_BAUD_24MHZ_2400 ((SCI_BAUD_8MHZ_2400)*3)
#define SCI_BAUD_24MHZ_4800 ((SCI_BAUD_8MHZ_4800)*3)
#define SCI_BAUD_24MHZ_9600 ((SCI_BAUD_8MHZ_9600)*3)
#define SCI_BAUD_24MHZ_19200 ((SCI_BAUD_8MHZ_19200)*3)
#define SCI_BAUD_24MHZ_20000 ((SCI_BAUD_8MHZ_20000)*3)
#define SCI_BAUD_24MHZ_28800 ((SCI_BAUD_8MHZ_28800)*3)
#define SCI_BAUD_24MHZ_38400 ((SCI_BAUD_8MHZ_38400)*3)
#define SCI_BAUD_24MHZ_48000 ((SCI_BAUD_8MHZ_48000)*3)
#define SCI_BAUD_24MHZ_57600 ((SCI_BAUD_8MHZ_57600)*3)
#define SCI_BAUD_24MHZ_115200 ((SCI_BAUD_8MHZ_115200)*3)

typedef enum
{
  SCI_MEAS_BAUD = 0x0,
  SCI_MEAS_BREAK = 0x1
} sci_meas_mode;

typedef enum
{
  SCI_AUTO_OFF = 0x0,
  SCI_AUTO_MEAS = 0x1,
  SCI_AUTO_BAUD = 0x2,
  SCI_AUTO_BOTH = 0x3
} sci_auto_mode;

/*RPY*/

typedef enum
{

  SCI_FEAT_CBM = 0x01,
  SCI_FEAT_TXD_TOUT = 0x02,
  SCI_FEAT_TIMER = 0x03,
  SCI_FEAT_DMA = 0x04,

  SCI_FEAT_VER_MASK = 0xf0

} sci_features;

#define SCI_ADDIRQ_RXD_FALLING BIT_SCI_ADDON_INTERRUPT_STATUS_RXD_FALLING
#define SCI_ADDIRQ_RXD_RISING BIT_SCI_ADDON_INTERRUPT_STATUS_RXD_RISING
#define SCI_ADDIRQ_TXD_TIMEOUT BIT_SCI_ADDON_INTERRUPT_STATUS_TXD_TIMEOUT
#define SCI_ADDIRQ_SCI_TIMER_CMP BIT_SCI_ADDON_INTERRUPT_STATUS_SCI_TIMER_CMP
#define SCI_ADDIRQ_SCI_TIMER_OV BIT_SCI_ADDON_INTERRUPT_STATUS_SCI_TIMER_OV
#define SCI_ADDIRQ_TX_DMA_FINISHED BIT_SCI_ADDON_INTERRUPT_STATUS_TX_DMA_FINISHED
#define SCI_ADDIRQ_RX_DMA_FINISHED BIT_SCI_ADDON_INTERRUPT_STATUS_RX_DMA_FINISHED
#define SCI_ADDIRQ_LIN_BUS_COLLISION BIT_SCI_ADDON_INTERRUPT_STATUS_LIN_BUS_COLLISION

#define SCI_ADDIRQ_ALL (0xff)

/*---*/

#define SCI(base_addr) ((_PACKED_ sci_t *)(base_addr))

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void sci_set_config(sci_cfg cfg);
void sci_reset_config(sci_cfg cfg);

void sci_transmit(uint8_t data);
uint8_t sci_receive(void);

bool sci_transmit_byte(uint8_t data, bool blocking);
bool sci_receive_byte(uint8_t *data, bool blocking);

sci_status sci_get_status(void);

void sci_set_baud_rate(sci_baud baud_rate);
uint16_t sci_get_baud_rate(void);

void sci_set_auto_mode(sci_auto_mode auto_mode);
void sci_set_meas_mode(sci_meas_mode meas_mode);
uint16_t sci_get_meas_value(void);

void sci_meas_enable(void);
void sci_meas_disable(void);

void sci_set_dbc_filter(uint8_t dbc);
uint8_t sci_get_dbc_filter(void);

void sci_bus_collision_detect(bool val);
void sci_timer_enable(bool val);
void sci_timer_prepare(bool val);
void sci_timeout_enable(bool val);
void sci_disable(bool val);
void sci_set_txd(bool val);
bool sci_get_rxd(void);

/*RPY*/

uint16_t sci_get_features(void);

void sci_set_data(uint8_t byte);
uint8_t sci_get_data(void);

sci_irq_t sci_get_pending_irq(void);
void sci_reset_pending_irq(int num);
void sci_disable_all_irqs();

void sci_setup_tx_dma(uint8_t *buf, uint16_t len);
void sci_setup_rx_dma(uint8_t *buf, uint16_t len);
void sci_stop_tx_dma(void);
void sci_stop_rx_dma(void);

void sci_set_timer_compare(uint16_t cmp);
uint16_t sci_get_timer_counter(void);
uint16_t sci_get_timer_compare(void);

void sci_enable_addon_irq(uint16_t mask, bool en);
void sci_reset_addon_irq(uint16_t mask);

/*---*/

/* ======================================================================= */
/* SCI instance define include                                             */
/* ======================================================================= */

#include "sci_inst.h"

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

void sci_handler_init(sci_num_t sci_no);

void sci_handler_register(sci_num_t sci_no, sci_irq_t irq, callback_t callback);

void sci_enable_irq(sci_num_t sci_no, sci_irq_t irq, bool enable);

uint16_t sci_get_irq_status(sci_num_t sci_no);

void sci_clear_all_irq_events(sci_num_t sci_no);

#endif /* __SCI_H__ */
