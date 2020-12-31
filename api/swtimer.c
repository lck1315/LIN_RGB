
#include "swtimer.h"
#include "utils.h"

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void swtimer_set_command (swtimer_cmd_t command) {

  WRITE_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_COMMAND, command);
}

void swtimer_enable (swtimer_dev_t swtimer_dev, bool enable) {

  if ((uint16_t)swtimer_dev > (2 * TIMERS - 1)) return;
  if (enable) {
    BIS_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CONFIG, onehot16[swtimer_dev]);
  } else {
    BIC_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CONFIG, onehot16[swtimer_dev]);
  }
}

void swtimer_autoreload_enable (swtimer_dev_t swtimer_dev, bool enable) {

  swtimer_dev = (swtimer_dev_t)((int)swtimer_dev + TIMERS);
  if ((uint16_t)swtimer_dev > (2 * TIMERS - 1)) return;
  if (enable) {
    BIS_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CONFIG, onehot16[swtimer_dev]);
  } else {
    BIC_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CONFIG, onehot16[swtimer_dev]);
  }
}

void swtimer_set_counter_reload (swtimer_dev_t swtimer_dev, uint16_t val) {

  WRITE_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT0_RELOAD + (swtimer_dev * 2), val);
}

void swtimer_set_prescaler_reload (swtimer_dev_t swtimer_dev, uint16_t val) {

  WRITE_REG_16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_DIV0_RELOAD + (swtimer_dev * 2), val);
}

uint16_t swtimer_get_counter_value (swtimer_dev_t swtimer_dev) {

  return READ_REG_U16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT0_VALUE + (swtimer_dev * 2));
}

uint16_t swtimer_get_reload_value (swtimer_dev_t swtimer_dev){

  return READ_REG_U16(BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT0_RELOAD + (swtimer_dev * 2));
}

/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

#include "vic.h"
#include "vic_irq.h"

volatile static callback_t callback[SWTIMER_NUM_IRQS];

void swtimer_handler_init(void) {

  irq_handler_init(VIC_IRQ_SWTIMER, SWTIMER_NUM_IRQS, (callback_t *)callback, BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_VENABLE);
}

