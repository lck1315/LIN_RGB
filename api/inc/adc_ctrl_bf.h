#ifndef __ADC_CTRL_BF_H__
#define __ADC_CTRL_BF_H__

#ifdef __CC_ARM
#ifndef _PACKED_
#define _PACKED_ __packed
#endif
#endif

#ifdef __ARMCC_VERSION
#ifndef _PACKED_
#define _PACKED_ __packed
#endif
#endif

#ifdef __GNUC__
#ifndef _PACKED_
#define _PACKED_ __attribute__ ((packed))
#endif
#endif

#ifdef __IARC__
#pragma pack(1)
#ifndef _PACKED_
#define _PACKED_
#endif
#endif

#ifdef __IAR_SYSTEMS_ICC__
#pragma pack(1)
#ifndef _PACKED_
#define _PACKED_
#endif
#endif

#ifdef _MSC_VER
#ifndef _PACKED_
#define _PACKED_
#endif
#endif

#ifndef _PACKED_
#error "UNKNOWN COMPILER"
#endif

// Instance base addresses

#ifndef BASE_ADDR_ADC_CTRL
#define BASE_ADDR_ADC_CTRL 0x0400U
#endif

#define NUMBER_ADC_CTRL 1

typedef enum {
  ADC_CTRL                       = (int)BASE_ADDR_ADC_CTRL
} adc_ctrl_num_t;

// Register bit field definitions

/* ADC_CTRL_REG_TRIGGER */

#define MSK_ADC_CTRL_REG_TRIGGER                            (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_reg_trigger_t;                        /* [15:0] */


/* ADC_CTRL_PWM0_CONFIG */

#define MSK_ADC_CTRL_PWM0_CONFIG                            (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_pwm0_config_t;                        /* [15:0] */


/* ADC_CTRL_PWM1_CONFIG */

#define MSK_ADC_CTRL_PWM1_CONFIG                            (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_pwm1_config_t;                        /* [15:0] */


/* ADC_CTRL_PWM2_CONFIG */

#define MSK_ADC_CTRL_PWM2_CONFIG                            (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_pwm2_config_t;                        /* [15:0] */


/* ADC_CTRL_PWM3_CONFIG */

#define MSK_ADC_CTRL_PWM3_CONFIG                            (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_pwm3_config_t;                        /* [15:0] */


/* ADC_CTRL_CONTROL */

#define MSK_ADC_CTRL_CONTROL_CYCLIC                         (0x1)     /* [0] */
#define SFT_ADC_CTRL_CONTROL_CYCLIC                         (0)
#define BIT_ADC_CTRL_CONTROL_CYCLIC                         (0x1)     /* [0] */
#define MSK_ADC_CTRL_CONTROL_CH13_SEL                       (0x1)     /* [1] */
#define SFT_ADC_CTRL_CONTROL_CH13_SEL                       (1)
#define BIT_ADC_CTRL_CONTROL_CH13_SEL                       (0x2)     /* [1] */
#define MSK_ADC_CTRL_CONTROL_CH14_SEL                       (0x1)     /* [2] */
#define SFT_ADC_CTRL_CONTROL_CH14_SEL                       (2)
#define BIT_ADC_CTRL_CONTROL_CH14_SEL                       (0x4)     /* [2] */
#define MSK_ADC_CTRL_CONTROL_CH15_SEL                       (0x1)     /* [3] */
#define SFT_ADC_CTRL_CONTROL_CH15_SEL                       (3)
#define BIT_ADC_CTRL_CONTROL_CH15_SEL                       (0x8)     /* [3] */
#define MSK_ADC_CTRL_CONTROL_ADC_MUX_ADDR                   (0x7f)    /* [14:8] */
#define SFT_ADC_CTRL_CONTROL_ADC_MUX_ADDR                   (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   17;
  volatile unsigned long  adc_mux_addr                  :    7;       /* [14:8] */
  volatile unsigned long  reserved7                     :    4;       /* [ 7:4] */
  volatile unsigned long  ch15_sel                      :    1;       /* [3] */
  volatile unsigned long  ch14_sel                      :    1;       /* [2] */
  volatile unsigned long  ch13_sel                      :    1;       /* [1] */
  volatile unsigned long  cyclic                        :    1;       /* [0] */
#else
  volatile unsigned short cyclic                        :    1;       /* [0] */
  volatile unsigned short ch13_sel                      :    1;       /* [1] */
  volatile unsigned short ch14_sel                      :    1;       /* [2] */
  volatile unsigned short ch15_sel                      :    1;       /* [3] */
  volatile unsigned short reserved7                     :    4;       /* [ 7:4] */
  volatile unsigned short adc_mux_addr                  :    7;       /* [14:8] */
  volatile unsigned short reserved                      :    1;
#endif
} _PACKED_ adc_ctrl_control_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile adc_ctrl_control_bf bf;
} _PACKED_ adc_ctrl_control_t;


/* ADC_CTRL_STATUS */

#define MSK_ADC_CTRL_STATUS                                 (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_status_t;                             /* [15:0] */


/* ADC_CTRL_MUX_DELAY */

#define MSK_ADC_CTRL_MUX_DELAY                              (0x3ff)   /* [ 9:0] */

typedef unsigned short adc_ctrl_mux_delay_t;                          /* [ 9:0] */


/* ADC_CTRL_SAMPLE_EXT */

#define MSK_ADC_CTRL_SAMPLE_EXT_CYCLES                      (0xff)    /* [ 7:0] */
#define SFT_ADC_CTRL_SAMPLE_EXT_CYCLES                      (0)
#define MSK_ADC_CTRL_SAMPLE_EXT_CYCLES_VT                   (0xff)    /* [15:8] */
#define SFT_ADC_CTRL_SAMPLE_EXT_CYCLES_VT                   (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  cycles_vt                     :    8;       /* [15:8] */
  volatile unsigned long  cycles                        :    8;       /* [ 7:0] */
#else
  volatile unsigned short cycles                        :    8;       /* [ 7:0] */
  volatile unsigned short cycles_vt                     :    8;       /* [15:8] */
#endif
} _PACKED_ adc_ctrl_sample_ext_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile adc_ctrl_sample_ext_bf bf;
} _PACKED_ adc_ctrl_sample_ext_t;


/* ADC_CTRL_DMA_BASE_ADDR */

#define MSK_ADC_CTRL_DMA_BASE_ADDR                          (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_dma_base_addr_t;                      /* [15:0] */


/* ADC_CTRL_ADC_OFFSET */

#define MSK_ADC_CTRL_ADC_OFFSET                             (0x1fff)  /* [12:0] */

typedef unsigned short adc_ctrl_adc_offset_t;                         /* [12:0] */


/* ADC_CTRL_ADC_GAIN */

#define MSK_ADC_CTRL_ADC_GAIN                               (0x1fff)  /* [12:0] */

typedef unsigned short adc_ctrl_adc_gain_t;                           /* [12:0] */


/* ADC_CTRL_TRIGGER_DELAY */

#define MSK_ADC_CTRL_TRIGGER_DELAY                          (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_trigger_delay_t;                      /* [15:0] */


/* ADC_CTRL_IRQ_STATUS0 */

#define MSK_ADC_CTRL_IRQ_STATUS0                            (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_irq_status0_t;                        /* [15:0] */


/* ADC_CTRL_IRQ_STATUS1 */

#define MSK_ADC_CTRL_IRQ_STATUS1_EVT_COPY                   (0xf)     /* [ 3:0] */
#define SFT_ADC_CTRL_IRQ_STATUS1_EVT_COPY                   (0)
#define MSK_ADC_CTRL_IRQ_STATUS1_READY                      (0x1)     /* [4] */
#define SFT_ADC_CTRL_IRQ_STATUS1_READY                      (4)
#define BIT_ADC_CTRL_IRQ_STATUS1_READY                      (0x10)    /* [4] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   27;
  volatile unsigned long  ready                         :    1;       /* [4] */
  volatile unsigned long  evt_copy                      :    4;       /* [ 3:0] */
#else
  volatile unsigned short evt_copy                      :    4;       /* [ 3:0] */
  volatile unsigned short ready                         :    1;       /* [4] */
  volatile unsigned short reserved                      :   11;
#endif
} _PACKED_ adc_ctrl_irq_status1_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile adc_ctrl_irq_status1_bf bf;
} _PACKED_ adc_ctrl_irq_status1_t;


/* ADC_CTRL_IRQ_MASK0 */

#define MSK_ADC_CTRL_IRQ_MASK0                              (0xffff)  /* [15:0] */

typedef unsigned short adc_ctrl_irq_mask0_t;                          /* [15:0] */


/* ADC_CTRL_IRQ_MASK1 */

#define MSK_ADC_CTRL_IRQ_MASK1                              (0x1f)    /* [ 4:0] */

typedef unsigned short adc_ctrl_irq_mask1_t;                          /* [ 4:0] */


/* ADC_CTRL_IRQ_VENABLE */

#define MSK_ADC_CTRL_IRQ_VENABLE                            (0x1f)    /* [ 4:0] */

typedef unsigned short adc_ctrl_irq_venable_t;                        /* [ 4:0] */


/* ADC_CTRL_IRQ_VDISABLE */

#define MSK_ADC_CTRL_IRQ_VDISABLE                           (0x1f)    /* [ 4:0] */

typedef unsigned short adc_ctrl_irq_vdisable_t;                       /* [ 4:0] */


/* ADC_CTRL_IRQ_VMAX */

#define MSK_ADC_CTRL_IRQ_VMAX                               (0x1f)    /* [ 4:0] */

typedef unsigned short adc_ctrl_irq_vmax_t;                           /* [ 4:0] */


/* ADC_CTRL_IRQ_VNO */

#define MSK_ADC_CTRL_IRQ_VNO                                (0x1f)    /* [ 4:0] */

typedef unsigned short adc_ctrl_irq_vno_t;                            /* [ 4:0] */



/* ADC_CTRL */

typedef struct {
  volatile adc_ctrl_reg_trigger_t                  reg_trigger;                    /* 0 */
  volatile adc_ctrl_pwm0_config_t                  pwm0_config;                    /* 2 */
  volatile adc_ctrl_pwm1_config_t                  pwm1_config;                    /* 4 */
  volatile adc_ctrl_pwm2_config_t                  pwm2_config;                    /* 6 */
  volatile adc_ctrl_pwm3_config_t                  pwm3_config;                    /* 8 */
  volatile adc_ctrl_control_t                      control;                       /* 10 */
  volatile adc_ctrl_status_t                       status;                        /* 12 */
  unsigned short                                   reserved0[1];
  volatile adc_ctrl_mux_delay_t                    mux_delay;                     /* 16 */
  volatile adc_ctrl_sample_ext_t                   sample_ext;                    /* 18 */
  volatile adc_ctrl_dma_base_addr_t                dma_base_addr;                 /* 20 */
  volatile adc_ctrl_adc_offset_t                   adc_offset;                    /* 22 */
  volatile adc_ctrl_adc_gain_t                     adc_gain;                      /* 24 */
  unsigned short                                   reserved1[3];
  volatile adc_ctrl_trigger_delay_t                trigger_delay0;                /* 32 */
  volatile adc_ctrl_trigger_delay_t                trigger_delay1;                /* 34 */
  volatile adc_ctrl_trigger_delay_t                trigger_delay2;                /* 36 */
  volatile adc_ctrl_trigger_delay_t                trigger_delay3;                /* 38 */
  unsigned short                                   reserved2[4];
  volatile adc_ctrl_irq_status0_t                  irq_status0;                   /* 48 */
  volatile adc_ctrl_irq_status1_t                  irq_status1;                   /* 50 */
  volatile adc_ctrl_irq_mask0_t                    irq_mask0;                     /* 52 */
  volatile adc_ctrl_irq_mask1_t                    irq_mask1;                     /* 54 */
  volatile adc_ctrl_irq_venable_t                  irq_venable;                   /* 56 */
  volatile adc_ctrl_irq_vdisable_t                 irq_vdisable;                  /* 58 */
  volatile adc_ctrl_irq_vmax_t                     irq_vmax;                      /* 60 */
  volatile adc_ctrl_irq_vno_t                      irq_vno;                       /* 62 */
} _PACKED_ adc_ctrl_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_ADC_CTRL 0x0400U ... ADC Control Module

#define ADDR_ADC_CTRL_REG_TRIGGER                            (0x00U)
#define A_ADC_CTRL_REG_TRIGGER(ba)                           ((ba) + ADDR_ADC_CTRL_REG_TRIGGER)
#define R_ADC_CTRL_REG_TRIGGER(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_REG_TRIGGER(ba)))
#define RES_ADC_CTRL_REG_TRIGGER                             (0x0U)
#define MSB_ADC_CTRL_REG_TRIGGER                             15
#define LSB_ADC_CTRL_REG_TRIGGER                             0
#define AADDR_ADC_CTRL_REG_TRIGGER                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_REG_TRIGGER)
#define REG_ADC_CTRL_REG_TRIGGER                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_REG_TRIGGER))

#define ADDR_ADC_CTRL_PWM0_CONFIG                            (0x02U)
#define A_ADC_CTRL_PWM0_CONFIG(ba)                           ((ba) + ADDR_ADC_CTRL_PWM0_CONFIG)
#define R_ADC_CTRL_PWM0_CONFIG(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_PWM0_CONFIG(ba)))
#define RES_ADC_CTRL_PWM0_CONFIG                             (0x0U)
#define MSB_ADC_CTRL_PWM0_CONFIG                             15
#define LSB_ADC_CTRL_PWM0_CONFIG                             0
#define AADDR_ADC_CTRL_PWM0_CONFIG                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM0_CONFIG)
#define REG_ADC_CTRL_PWM0_CONFIG                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_PWM0_CONFIG))

#define ADDR_ADC_CTRL_PWM1_CONFIG                            (0x04U)
#define A_ADC_CTRL_PWM1_CONFIG(ba)                           ((ba) + ADDR_ADC_CTRL_PWM1_CONFIG)
#define R_ADC_CTRL_PWM1_CONFIG(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_PWM1_CONFIG(ba)))
#define RES_ADC_CTRL_PWM1_CONFIG                             (0x0U)
#define MSB_ADC_CTRL_PWM1_CONFIG                             15
#define LSB_ADC_CTRL_PWM1_CONFIG                             0
#define AADDR_ADC_CTRL_PWM1_CONFIG                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM1_CONFIG)
#define REG_ADC_CTRL_PWM1_CONFIG                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_PWM1_CONFIG))

#define ADDR_ADC_CTRL_PWM2_CONFIG                            (0x06U)
#define A_ADC_CTRL_PWM2_CONFIG(ba)                           ((ba) + ADDR_ADC_CTRL_PWM2_CONFIG)
#define R_ADC_CTRL_PWM2_CONFIG(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_PWM2_CONFIG(ba)))
#define RES_ADC_CTRL_PWM2_CONFIG                             (0x0U)
#define MSB_ADC_CTRL_PWM2_CONFIG                             15
#define LSB_ADC_CTRL_PWM2_CONFIG                             0
#define AADDR_ADC_CTRL_PWM2_CONFIG                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM2_CONFIG)
#define REG_ADC_CTRL_PWM2_CONFIG                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_PWM2_CONFIG))

#define ADDR_ADC_CTRL_PWM3_CONFIG                            (0x08U)
#define A_ADC_CTRL_PWM3_CONFIG(ba)                           ((ba) + ADDR_ADC_CTRL_PWM3_CONFIG)
#define R_ADC_CTRL_PWM3_CONFIG(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_PWM3_CONFIG(ba)))
#define RES_ADC_CTRL_PWM3_CONFIG                             (0x0U)
#define MSB_ADC_CTRL_PWM3_CONFIG                             15
#define LSB_ADC_CTRL_PWM3_CONFIG                             0
#define AADDR_ADC_CTRL_PWM3_CONFIG                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_PWM3_CONFIG)
#define REG_ADC_CTRL_PWM3_CONFIG                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_PWM3_CONFIG))

#define ADDR_ADC_CTRL_CONTROL                                (0x0AU)
#define A_ADC_CTRL_CONTROL(ba)                               ((ba) + ADDR_ADC_CTRL_CONTROL)
#define R_ADC_CTRL_CONTROL(ba)                               (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_CONTROL(ba)))
#define RES_ADC_CTRL_CONTROL                                 (0x0U)
#define MSB_ADC_CTRL_CONTROL                                 14
#define LSB_ADC_CTRL_CONTROL                                 0
#define AADDR_ADC_CTRL_CONTROL                               (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_CONTROL)
#define REG_ADC_CTRL_CONTROL                                 (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_CONTROL))

#define ADDR_ADC_CTRL_STATUS                                 (0x0CU)
#define A_ADC_CTRL_STATUS(ba)                                ((ba) + ADDR_ADC_CTRL_STATUS)
#define R_ADC_CTRL_STATUS(ba)                                (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_STATUS(ba)))
#define RES_ADC_CTRL_STATUS                                  (0x0U)
#define MSB_ADC_CTRL_STATUS                                  15
#define LSB_ADC_CTRL_STATUS                                  0
#define AADDR_ADC_CTRL_STATUS                                (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_STATUS)
#define REG_ADC_CTRL_STATUS                                  (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_STATUS))

#define ADDR_ADC_CTRL_MUX_DELAY                              (0x10U)
#define A_ADC_CTRL_MUX_DELAY(ba)                             ((ba) + ADDR_ADC_CTRL_MUX_DELAY)
#define R_ADC_CTRL_MUX_DELAY(ba)                             (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_MUX_DELAY(ba)))
#define RES_ADC_CTRL_MUX_DELAY                               (0x0U)
#define MSB_ADC_CTRL_MUX_DELAY                               9
#define LSB_ADC_CTRL_MUX_DELAY                               0
#define AADDR_ADC_CTRL_MUX_DELAY                             (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_MUX_DELAY)
#define REG_ADC_CTRL_MUX_DELAY                               (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_MUX_DELAY))

#define ADDR_ADC_CTRL_SAMPLE_EXT                             (0x12U)
#define A_ADC_CTRL_SAMPLE_EXT(ba)                            ((ba) + ADDR_ADC_CTRL_SAMPLE_EXT)
#define R_ADC_CTRL_SAMPLE_EXT(ba)                            (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_SAMPLE_EXT(ba)))
#define RES_ADC_CTRL_SAMPLE_EXT                              (0x1e00U)
#define MSB_ADC_CTRL_SAMPLE_EXT                              15
#define LSB_ADC_CTRL_SAMPLE_EXT                              0
#define AADDR_ADC_CTRL_SAMPLE_EXT                            (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_SAMPLE_EXT)
#define REG_ADC_CTRL_SAMPLE_EXT                              (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_SAMPLE_EXT))

#define ADDR_ADC_CTRL_DMA_BASE_ADDR                          (0x14U)
#define A_ADC_CTRL_DMA_BASE_ADDR(ba)                         ((ba) + ADDR_ADC_CTRL_DMA_BASE_ADDR)
#define R_ADC_CTRL_DMA_BASE_ADDR(ba)                         (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_DMA_BASE_ADDR(ba)))
#define RES_ADC_CTRL_DMA_BASE_ADDR                           (0x0U)
#define MSB_ADC_CTRL_DMA_BASE_ADDR                           15
#define LSB_ADC_CTRL_DMA_BASE_ADDR                           0
#define AADDR_ADC_CTRL_DMA_BASE_ADDR                         (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_DMA_BASE_ADDR)
#define REG_ADC_CTRL_DMA_BASE_ADDR                           (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_DMA_BASE_ADDR))

#define ADDR_ADC_CTRL_ADC_OFFSET                             (0x16U)
#define A_ADC_CTRL_ADC_OFFSET(ba)                            ((ba) + ADDR_ADC_CTRL_ADC_OFFSET)
#define R_ADC_CTRL_ADC_OFFSET(ba)                            (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_ADC_OFFSET(ba)))
#define RES_ADC_CTRL_ADC_OFFSET                              (0x0U)
#define MSB_ADC_CTRL_ADC_OFFSET                              12
#define LSB_ADC_CTRL_ADC_OFFSET                              0
#define AADDR_ADC_CTRL_ADC_OFFSET                            (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_ADC_OFFSET)
#define REG_ADC_CTRL_ADC_OFFSET                              (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_ADC_OFFSET))

#define ADDR_ADC_CTRL_ADC_GAIN                               (0x18U)
#define A_ADC_CTRL_ADC_GAIN(ba)                              ((ba) + ADDR_ADC_CTRL_ADC_GAIN)
#define R_ADC_CTRL_ADC_GAIN(ba)                              (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_ADC_GAIN(ba)))
#define RES_ADC_CTRL_ADC_GAIN                                (0x1000U)
#define MSB_ADC_CTRL_ADC_GAIN                                12
#define LSB_ADC_CTRL_ADC_GAIN                                0
#define AADDR_ADC_CTRL_ADC_GAIN                              (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_ADC_GAIN)
#define REG_ADC_CTRL_ADC_GAIN                                (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_ADC_GAIN))

#define ADDR_ADC_CTRL_TRIGGER_DELAY0                         (0x20U)
#define A_ADC_CTRL_TRIGGER_DELAY0(ba)                        ((ba) + ADDR_ADC_CTRL_TRIGGER_DELAY0)
#define R_ADC_CTRL_TRIGGER_DELAY0(ba)                        (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_TRIGGER_DELAY0(ba)))
#define RES_ADC_CTRL_TRIGGER_DELAY0                          (0x0U)
#define MSB_ADC_CTRL_TRIGGER_DELAY0                          15
#define LSB_ADC_CTRL_TRIGGER_DELAY0                          0
#define AADDR_ADC_CTRL_TRIGGER_DELAY0                        (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY0)
#define REG_ADC_CTRL_TRIGGER_DELAY0                          (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_TRIGGER_DELAY0))

#define ADDR_ADC_CTRL_TRIGGER_DELAY1                         (0x22U)
#define A_ADC_CTRL_TRIGGER_DELAY1(ba)                        ((ba) + ADDR_ADC_CTRL_TRIGGER_DELAY1)
#define R_ADC_CTRL_TRIGGER_DELAY1(ba)                        (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_TRIGGER_DELAY1(ba)))
#define RES_ADC_CTRL_TRIGGER_DELAY1                          (0x0U)
#define MSB_ADC_CTRL_TRIGGER_DELAY1                          15
#define LSB_ADC_CTRL_TRIGGER_DELAY1                          0
#define AADDR_ADC_CTRL_TRIGGER_DELAY1                        (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY1)
#define REG_ADC_CTRL_TRIGGER_DELAY1                          (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_TRIGGER_DELAY1))

#define ADDR_ADC_CTRL_TRIGGER_DELAY2                         (0x24U)
#define A_ADC_CTRL_TRIGGER_DELAY2(ba)                        ((ba) + ADDR_ADC_CTRL_TRIGGER_DELAY2)
#define R_ADC_CTRL_TRIGGER_DELAY2(ba)                        (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_TRIGGER_DELAY2(ba)))
#define RES_ADC_CTRL_TRIGGER_DELAY2                          (0x0U)
#define MSB_ADC_CTRL_TRIGGER_DELAY2                          15
#define LSB_ADC_CTRL_TRIGGER_DELAY2                          0
#define AADDR_ADC_CTRL_TRIGGER_DELAY2                        (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY2)
#define REG_ADC_CTRL_TRIGGER_DELAY2                          (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_TRIGGER_DELAY2))

#define ADDR_ADC_CTRL_TRIGGER_DELAY3                         (0x26U)
#define A_ADC_CTRL_TRIGGER_DELAY3(ba)                        ((ba) + ADDR_ADC_CTRL_TRIGGER_DELAY3)
#define R_ADC_CTRL_TRIGGER_DELAY3(ba)                        (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_TRIGGER_DELAY3(ba)))
#define RES_ADC_CTRL_TRIGGER_DELAY3                          (0x0U)
#define MSB_ADC_CTRL_TRIGGER_DELAY3                          15
#define LSB_ADC_CTRL_TRIGGER_DELAY3                          0
#define AADDR_ADC_CTRL_TRIGGER_DELAY3                        (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_TRIGGER_DELAY3)
#define REG_ADC_CTRL_TRIGGER_DELAY3                          (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_TRIGGER_DELAY3))

#define ADDR_ADC_CTRL_IRQ_STATUS0                            (0x30U)
#define A_ADC_CTRL_IRQ_STATUS0(ba)                           ((ba) + ADDR_ADC_CTRL_IRQ_STATUS0)
#define R_ADC_CTRL_IRQ_STATUS0(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_STATUS0(ba)))
#define RES_ADC_CTRL_IRQ_STATUS0                             (0x0U)
#define MSB_ADC_CTRL_IRQ_STATUS0                             15
#define LSB_ADC_CTRL_IRQ_STATUS0                             0
#define AADDR_ADC_CTRL_IRQ_STATUS0                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_STATUS0)
#define REG_ADC_CTRL_IRQ_STATUS0                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_STATUS0))

#define ADDR_ADC_CTRL_IRQ_STATUS1                            (0x32U)
#define A_ADC_CTRL_IRQ_STATUS1(ba)                           ((ba) + ADDR_ADC_CTRL_IRQ_STATUS1)
#define R_ADC_CTRL_IRQ_STATUS1(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_STATUS1(ba)))
#define RES_ADC_CTRL_IRQ_STATUS1                             (0x0U)
#define MSB_ADC_CTRL_IRQ_STATUS1                             4
#define LSB_ADC_CTRL_IRQ_STATUS1                             0
#define AADDR_ADC_CTRL_IRQ_STATUS1                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_STATUS1)
#define REG_ADC_CTRL_IRQ_STATUS1                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_STATUS1))

#define ADDR_ADC_CTRL_IRQ_MASK0                              (0x34U)
#define A_ADC_CTRL_IRQ_MASK0(ba)                             ((ba) + ADDR_ADC_CTRL_IRQ_MASK0)
#define R_ADC_CTRL_IRQ_MASK0(ba)                             (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_MASK0(ba)))
#define RES_ADC_CTRL_IRQ_MASK0                               (0x0U)
#define MSB_ADC_CTRL_IRQ_MASK0                               15
#define LSB_ADC_CTRL_IRQ_MASK0                               0
#define AADDR_ADC_CTRL_IRQ_MASK0                             (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_MASK0)
#define REG_ADC_CTRL_IRQ_MASK0                               (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_MASK0))

#define ADDR_ADC_CTRL_IRQ_MASK1                              (0x36U)
#define A_ADC_CTRL_IRQ_MASK1(ba)                             ((ba) + ADDR_ADC_CTRL_IRQ_MASK1)
#define R_ADC_CTRL_IRQ_MASK1(ba)                             (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_MASK1(ba)))
#define RES_ADC_CTRL_IRQ_MASK1                               (0x0U)
#define MSB_ADC_CTRL_IRQ_MASK1                               4
#define LSB_ADC_CTRL_IRQ_MASK1                               0
#define AADDR_ADC_CTRL_IRQ_MASK1                             (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_MASK1)
#define REG_ADC_CTRL_IRQ_MASK1                               (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_MASK1))

#define ADDR_ADC_CTRL_IRQ_VENABLE                            (0x38U)
#define A_ADC_CTRL_IRQ_VENABLE(ba)                           ((ba) + ADDR_ADC_CTRL_IRQ_VENABLE)
#define R_ADC_CTRL_IRQ_VENABLE(ba)                           (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_VENABLE(ba)))
#define RES_ADC_CTRL_IRQ_VENABLE                             (0x0U)
#define MSB_ADC_CTRL_IRQ_VENABLE                             4
#define LSB_ADC_CTRL_IRQ_VENABLE                             0
#define AADDR_ADC_CTRL_IRQ_VENABLE                           (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_VENABLE)
#define REG_ADC_CTRL_IRQ_VENABLE                             (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_VENABLE))

#define ADDR_ADC_CTRL_IRQ_VDISABLE                           (0x3AU)
#define A_ADC_CTRL_IRQ_VDISABLE(ba)                          ((ba) + ADDR_ADC_CTRL_IRQ_VDISABLE)
#define R_ADC_CTRL_IRQ_VDISABLE(ba)                          (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_VDISABLE(ba)))
#define RES_ADC_CTRL_IRQ_VDISABLE                            (0x0U)
#define MSB_ADC_CTRL_IRQ_VDISABLE                            4
#define LSB_ADC_CTRL_IRQ_VDISABLE                            0
#define AADDR_ADC_CTRL_IRQ_VDISABLE                          (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_VDISABLE)
#define REG_ADC_CTRL_IRQ_VDISABLE                            (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_VDISABLE))

#define ADDR_ADC_CTRL_IRQ_VMAX                               (0x3CU)
#define A_ADC_CTRL_IRQ_VMAX(ba)                              ((ba) + ADDR_ADC_CTRL_IRQ_VMAX)
#define R_ADC_CTRL_IRQ_VMAX(ba)                              (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_VMAX(ba)))
#define RES_ADC_CTRL_IRQ_VMAX                                (0x16U)
#define MSB_ADC_CTRL_IRQ_VMAX                                4
#define LSB_ADC_CTRL_IRQ_VMAX                                0
#define AADDR_ADC_CTRL_IRQ_VMAX                              (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_VMAX)
#define REG_ADC_CTRL_IRQ_VMAX                                (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_VMAX))

#define ADDR_ADC_CTRL_IRQ_VNO                                (0x3EU)
#define A_ADC_CTRL_IRQ_VNO(ba)                               ((ba) + ADDR_ADC_CTRL_IRQ_VNO)
#define R_ADC_CTRL_IRQ_VNO(ba)                               (*(volatile unsigned short *)((unsigned int)A_ADC_CTRL_IRQ_VNO(ba)))
#define RES_ADC_CTRL_IRQ_VNO                                 (0x16U)
#define MSB_ADC_CTRL_IRQ_VNO                                 4
#define LSB_ADC_CTRL_IRQ_VNO                                 0
#define AADDR_ADC_CTRL_IRQ_VNO                               (BASE_ADDR_ADC_CTRL + ADDR_ADC_CTRL_IRQ_VNO)
#define REG_ADC_CTRL_IRQ_VNO                                 (*(volatile unsigned short *)((unsigned int)AADDR_ADC_CTRL_IRQ_VNO))




#endif
