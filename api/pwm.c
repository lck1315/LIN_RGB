
#include "pwm.h"
#include "adc_ctrl.h"

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void pwm_config_prescaler(pwm_ch_t ch, uint8_t val) {

  switch (ch) {
    case PWM_CH0 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PRESCALER0, val); break;
    case PWM_CH1 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PRESCALER1, val); break;
    case PWM_CH2 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PRESCALER2, val); break;
    case PWM_CH3 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PRESCALER3, val); break;
  }
}

void pwm_config_period(pwm_ch_t ch, uint16_t val) {

  switch (ch) {
    case PWM_CH0 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PERIOD0, val); break;
    case PWM_CH1 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PERIOD1, val); break;
    case PWM_CH2 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PERIOD2, val); break;
    case PWM_CH3 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_PERIOD3, val); break;
  }
}

void pwm_config_start(pwm_ch_t ch, uint16_t val) {

  switch (ch) {
    case PWM_CH0 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_START0, val); break;
    case PWM_CH1 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_START1, val); break;
    case PWM_CH2 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_START2, val); break;
    case PWM_CH3 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_START3, val); break;
  }
}

void pwm_config_stop(pwm_ch_t ch, uint16_t val) {

  switch (ch) {
    case PWM_CH0 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_STOP0, val); break;
    case PWM_CH1 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_STOP1, val); break;
    case PWM_CH2 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_STOP2, val); break;
    case PWM_CH3 : WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_STOP3, val); break;
  }
}

void pwm_config_polarity(pwm_ch_t ch, bool inverse) {

  pwm_polarity_t  pol;

  pol.val = READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_POLARITY);
  switch (ch) {
    case PWM_CH0 : if (inverse) {
        pol.bf.pwm_polarity |= 0x1;
      } else {
        pol.bf.pwm_polarity &= 0xE;
      } break;
    case PWM_CH1 : if (inverse) {
        pol.bf.pwm_polarity |= 0x2;
      } else {
        pol.bf.pwm_polarity &= 0xD;
      } break;
    case PWM_CH2 : if (inverse) {
        pol.bf.pwm_polarity |= 0x4;
      } else {
        pol.bf.pwm_polarity &= 0xB;
      } break;
    case PWM_CH3 : if (inverse) {
        pol.bf.pwm_polarity |= 0x8;
      } else {
        pol.bf.pwm_polarity &= 0x7;
      } break;
  }
  WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_POLARITY, pol.val);
}

void pwm_enable(pwm_ch_t ch, bool enable) {

  pwm_control_t  ctrl;

  ctrl.val = READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_CONTROL);
  switch (ch) {
    case PWM_CH0 : ctrl.bf.pwm_0_enable = enable ? 1 : 0; break;
    case PWM_CH1 : ctrl.bf.pwm_1_enable = enable ? 1 : 0; break;
    case PWM_CH2 : ctrl.bf.pwm_2_enable = enable ? 1 : 0; break;
    case PWM_CH3 : ctrl.bf.pwm_3_enable = enable ? 1 : 0; break;
  }
  WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_CONTROL, ctrl.val);
}

uint16_t pwm_get_counter(pwm_ch_t ch) {

  switch (ch) {
    case PWM_CH0 : return READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_COUNTER0); break;
    case PWM_CH1 : return READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_COUNTER1); break;
    case PWM_CH2 : return READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_COUNTER2); break;
    case PWM_CH3 : return READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_COUNTER3); break;
  }
  return 0;
}

void pwm_set_trigger_delay(pwm_ch_t ch, uint16_t val) {

  // sets PWM channel dependent trigger delay inside ADC CTRL module ...
  switch (ch) {
    case PWM_CH0 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY0, val); break;
    case PWM_CH1 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY1, val); break;
    case PWM_CH2 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY2, val); break;
    case PWM_CH3 : WRITE_REG_16(BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY3, val); break;
  }
}


/*RPY*/ //added pwm_term access methods
void pwm_config_term(pwm_ch_t ch, bool on) {

  pwm_polarity_t  pol;

  pol.val = READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_POLARITY);
  switch (ch) {
    case PWM_CH0 : if (on) {
        pol.bf.pwm_term |= 0x1;
      } else {
        pol.bf.pwm_term &= 0xE;
      } break;
    case PWM_CH1 : if (on) {
        pol.bf.pwm_term |= 0x2;
      } else {
        pol.bf.pwm_term &= 0xD;
      } break;
    case PWM_CH2 : if (on) {
        pol.bf.pwm_term |= 0x4;
      } else {
        pol.bf.pwm_term &= 0xB;
      } break;
    case PWM_CH3 : if (on) {
        pol.bf.pwm_term |= 0x8;
      } else {
        pol.bf.pwm_term &= 0x7;
      } break;
  }
  WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_POLARITY, pol.val);
}

/*RPY*/ //added pwm_zero access methods
void pwm_config_zero(pwm_ch_t ch, bool on) {

  pwm_polarity_t  pol;

  pol.val = READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_POLARITY);
  switch (ch) {
    case PWM_CH0 : if (on) {
        pol.bf.pwm_zero |= 0x1;
      } else {
        pol.bf.pwm_zero &= 0xE;
      } break;
    case PWM_CH1 : if (on) {
        pol.bf.pwm_zero |= 0x2;
      } else {
        pol.bf.pwm_zero &= 0xD;
      } break;
    case PWM_CH2 : if (on) {
        pol.bf.pwm_zero |= 0x4;
      } else {
        pol.bf.pwm_zero &= 0xB;
      } break;
    case PWM_CH3 : if (on) {
        pol.bf.pwm_zero |= 0x8;
      } else {
        pol.bf.pwm_zero &= 0x7;
      } break;
  }
  WRITE_REG_16(BASE_ADDR_PWM + ADDR_PWM_POLARITY, pol.val);
}

/*RPY*/ // added check for pwm being active
bool pwm_status_running() {

  pwm_status_t stat;

  stat.val = READ_REG_U16(BASE_ADDR_PWM + ADDR_PWM_STATUS);
  
  return stat.bf.running?true:false;
}


/* ======================================================================= */
/* INTERRUPT HANDLING                                                      */
/* ======================================================================= */

#include "vic.h"
#include "vic_irq.h"

volatile static callback_t callback[PWM_NUM_IRQS];

void pwm_handler_init(void) {

  irq_handler_init(VIC_IRQ_PWM, PWM_NUM_IRQS, (callback_t *)callback, BASE_ADDR_PWM + ADDR_PWM_IRQ_VENABLE);
}

