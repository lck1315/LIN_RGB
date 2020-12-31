#ifndef __PWM_BF_H__
#define __PWM_BF_H__

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

#ifndef BASE_ADDR_PWM
#define BASE_ADDR_PWM 0x0440U
#endif

#define NUMBER_PWM 1

typedef enum {
  PWM                            = (int)BASE_ADDR_PWM
} pwm_num_t;

// Register bit field definitions

/* PWM_CONTROL */

#define MSK_PWM_CONTROL_PWM_0_ENABLE                        (0x1)     /* [0] */
#define SFT_PWM_CONTROL_PWM_0_ENABLE                        (0)
#define BIT_PWM_CONTROL_PWM_0_ENABLE                        (0x1)     /* [0] */
#define MSK_PWM_CONTROL_PWM_1_ENABLE                        (0x1)     /* [1] */
#define SFT_PWM_CONTROL_PWM_1_ENABLE                        (1)
#define BIT_PWM_CONTROL_PWM_1_ENABLE                        (0x2)     /* [1] */
#define MSK_PWM_CONTROL_PWM_2_ENABLE                        (0x1)     /* [2] */
#define SFT_PWM_CONTROL_PWM_2_ENABLE                        (2)
#define BIT_PWM_CONTROL_PWM_2_ENABLE                        (0x4)     /* [2] */
#define MSK_PWM_CONTROL_PWM_3_ENABLE                        (0x1)     /* [3] */
#define SFT_PWM_CONTROL_PWM_3_ENABLE                        (3)
#define BIT_PWM_CONTROL_PWM_3_ENABLE                        (0x8)     /* [3] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   28;
  volatile unsigned long  pwm_3_enable                  :    1;       /* [3] */
  volatile unsigned long  pwm_2_enable                  :    1;       /* [2] */
  volatile unsigned long  pwm_1_enable                  :    1;       /* [1] */
  volatile unsigned long  pwm_0_enable                  :    1;       /* [0] */
#else
  volatile unsigned short pwm_0_enable                  :    1;       /* [0] */
  volatile unsigned short pwm_1_enable                  :    1;       /* [1] */
  volatile unsigned short pwm_2_enable                  :    1;       /* [2] */
  volatile unsigned short pwm_3_enable                  :    1;       /* [3] */
  volatile unsigned short reserved                      :   12;
#endif
} _PACKED_ pwm_control_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile pwm_control_bf bf;
} _PACKED_ pwm_control_t;


/* PWM_STATUS */

#define MSK_PWM_STATUS_PWM0                                 (0x1)     /* [0] */
#define SFT_PWM_STATUS_PWM0                                 (0)
#define BIT_PWM_STATUS_PWM0                                 (0x1)     /* [0] */
#define MSK_PWM_STATUS_PWM1                                 (0x1)     /* [1] */
#define SFT_PWM_STATUS_PWM1                                 (1)
#define BIT_PWM_STATUS_PWM1                                 (0x2)     /* [1] */
#define MSK_PWM_STATUS_PWM2                                 (0x1)     /* [2] */
#define SFT_PWM_STATUS_PWM2                                 (2)
#define BIT_PWM_STATUS_PWM2                                 (0x4)     /* [2] */
#define MSK_PWM_STATUS_PWM3                                 (0x1)     /* [3] */
#define SFT_PWM_STATUS_PWM3                                 (3)
#define BIT_PWM_STATUS_PWM3                                 (0x8)     /* [3] */
#define MSK_PWM_STATUS_RUNNING                              (0x1)     /* [4] */
#define SFT_PWM_STATUS_RUNNING                              (4)
#define BIT_PWM_STATUS_RUNNING                              (0x10)    /* [4] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   27;
  volatile unsigned long  running                       :    1;       /* [4] */
  volatile unsigned long  pwm3                          :    1;       /* [3] */
  volatile unsigned long  pwm2                          :    1;       /* [2] */
  volatile unsigned long  pwm1                          :    1;       /* [1] */
  volatile unsigned long  pwm0                          :    1;       /* [0] */
#else
  volatile unsigned short pwm0                          :    1;       /* [0] */
  volatile unsigned short pwm1                          :    1;       /* [1] */
  volatile unsigned short pwm2                          :    1;       /* [2] */
  volatile unsigned short pwm3                          :    1;       /* [3] */
  volatile unsigned short running                       :    1;       /* [4] */
  volatile unsigned short reserved                      :   11;
#endif
} _PACKED_ pwm_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile pwm_status_bf bf;
} _PACKED_ pwm_status_t;


/* PWM_POLARITY */

#define MSK_PWM_POLARITY_PWM_POLARITY                       (0xf)     /* [ 3:0] */
#define SFT_PWM_POLARITY_PWM_POLARITY                       (0)
#define MSK_PWM_POLARITY_PWM_TERM                           (0xf)     /* [ 7:4] */
#define SFT_PWM_POLARITY_PWM_TERM                           (4)
#define MSK_PWM_POLARITY_PWM_ZERO                           (0xf)     /* [11:8] */
#define SFT_PWM_POLARITY_PWM_ZERO                           (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   20;
  volatile unsigned long  pwm_zero                      :    4;       /* [11:8] */
  volatile unsigned long  pwm_term                      :    4;       /* [ 7:4] */
  volatile unsigned long  pwm_polarity                  :    4;       /* [ 3:0] */
#else
  volatile unsigned short pwm_polarity                  :    4;       /* [ 3:0] */
  volatile unsigned short pwm_term                      :    4;       /* [ 7:4] */
  volatile unsigned short pwm_zero                      :    4;       /* [11:8] */
  volatile unsigned short reserved                      :    4;
#endif
} _PACKED_ pwm_polarity_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile pwm_polarity_bf bf;
} _PACKED_ pwm_polarity_t;


/* PWM_PRESCALER */

#define MSK_PWM_PRESCALER                                   (0xff)    /* [ 7:0] */

typedef unsigned short pwm_prescaler_t;                               /* [ 7:0] */


/* PWM_PERIOD */

#define MSK_PWM_PERIOD                                      (0xffff)  /* [15:0] */

typedef unsigned short pwm_period_t;                                  /* [15:0] */


/* PWM_START */

#define MSK_PWM_START                                       (0xffff)  /* [15:0] */

typedef unsigned short pwm_start_t;                                   /* [15:0] */


/* PWM_STOP */

#define MSK_PWM_STOP                                        (0xffff)  /* [15:0] */

typedef unsigned short pwm_stop_t;                                    /* [15:0] */


/* PWM_COUNTER */

#define MSK_PWM_COUNTER                                     (0xffff)  /* [15:0] */

typedef unsigned short pwm_counter_t;                                 /* [15:0] */


/* PWM_IRQ_STATUS */

#define MSK_PWM_IRQ_STATUS_EVT_PERIOD0                      (0x1)     /* [0] */
#define SFT_PWM_IRQ_STATUS_EVT_PERIOD0                      (0)
#define BIT_PWM_IRQ_STATUS_EVT_PERIOD0                      (0x1)     /* [0] */
#define MSK_PWM_IRQ_STATUS_EVT_START0                       (0x1)     /* [1] */
#define SFT_PWM_IRQ_STATUS_EVT_START0                       (1)
#define BIT_PWM_IRQ_STATUS_EVT_START0                       (0x2)     /* [1] */
#define MSK_PWM_IRQ_STATUS_EVT_STOP0                        (0x1)     /* [2] */
#define SFT_PWM_IRQ_STATUS_EVT_STOP0                        (2)
#define BIT_PWM_IRQ_STATUS_EVT_STOP0                        (0x4)     /* [2] */
#define MSK_PWM_IRQ_STATUS_EVT_PERIOD1                      (0x1)     /* [3] */
#define SFT_PWM_IRQ_STATUS_EVT_PERIOD1                      (3)
#define BIT_PWM_IRQ_STATUS_EVT_PERIOD1                      (0x8)     /* [3] */
#define MSK_PWM_IRQ_STATUS_EVT_START1                       (0x1)     /* [4] */
#define SFT_PWM_IRQ_STATUS_EVT_START1                       (4)
#define BIT_PWM_IRQ_STATUS_EVT_START1                       (0x10)    /* [4] */
#define MSK_PWM_IRQ_STATUS_EVT_STOP1                        (0x1)     /* [5] */
#define SFT_PWM_IRQ_STATUS_EVT_STOP1                        (5)
#define BIT_PWM_IRQ_STATUS_EVT_STOP1                        (0x20)    /* [5] */
#define MSK_PWM_IRQ_STATUS_EVT_PERIOD2                      (0x1)     /* [6] */
#define SFT_PWM_IRQ_STATUS_EVT_PERIOD2                      (6)
#define BIT_PWM_IRQ_STATUS_EVT_PERIOD2                      (0x40)    /* [6] */
#define MSK_PWM_IRQ_STATUS_EVT_START2                       (0x1)     /* [7] */
#define SFT_PWM_IRQ_STATUS_EVT_START2                       (7)
#define BIT_PWM_IRQ_STATUS_EVT_START2                       (0x80)    /* [7] */
#define MSK_PWM_IRQ_STATUS_EVT_STOP2                        (0x1)     /* [8] */
#define SFT_PWM_IRQ_STATUS_EVT_STOP2                        (8)
#define BIT_PWM_IRQ_STATUS_EVT_STOP2                        (0x100)   /* [8] */
#define MSK_PWM_IRQ_STATUS_EVT_PERIOD3                      (0x1)     /* [9] */
#define SFT_PWM_IRQ_STATUS_EVT_PERIOD3                      (9)
#define BIT_PWM_IRQ_STATUS_EVT_PERIOD3                      (0x200)   /* [9] */
#define MSK_PWM_IRQ_STATUS_EVT_START3                       (0x1)     /* [10] */
#define SFT_PWM_IRQ_STATUS_EVT_START3                       (10)
#define BIT_PWM_IRQ_STATUS_EVT_START3                       (0x400)   /* [10] */
#define MSK_PWM_IRQ_STATUS_EVT_STOP3                        (0x1)     /* [11] */
#define SFT_PWM_IRQ_STATUS_EVT_STOP3                        (11)
#define BIT_PWM_IRQ_STATUS_EVT_STOP3                        (0x800)   /* [11] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   20;
  volatile unsigned long  evt_stop3                     :    1;       /* [11] */
  volatile unsigned long  evt_start3                    :    1;       /* [10] */
  volatile unsigned long  evt_period3                   :    1;       /* [9] */
  volatile unsigned long  evt_stop2                     :    1;       /* [8] */
  volatile unsigned long  evt_start2                    :    1;       /* [7] */
  volatile unsigned long  evt_period2                   :    1;       /* [6] */
  volatile unsigned long  evt_stop1                     :    1;       /* [5] */
  volatile unsigned long  evt_start1                    :    1;       /* [4] */
  volatile unsigned long  evt_period1                   :    1;       /* [3] */
  volatile unsigned long  evt_stop0                     :    1;       /* [2] */
  volatile unsigned long  evt_start0                    :    1;       /* [1] */
  volatile unsigned long  evt_period0                   :    1;       /* [0] */
#else
  volatile unsigned short evt_period0                   :    1;       /* [0] */
  volatile unsigned short evt_start0                    :    1;       /* [1] */
  volatile unsigned short evt_stop0                     :    1;       /* [2] */
  volatile unsigned short evt_period1                   :    1;       /* [3] */
  volatile unsigned short evt_start1                    :    1;       /* [4] */
  volatile unsigned short evt_stop1                     :    1;       /* [5] */
  volatile unsigned short evt_period2                   :    1;       /* [6] */
  volatile unsigned short evt_start2                    :    1;       /* [7] */
  volatile unsigned short evt_stop2                     :    1;       /* [8] */
  volatile unsigned short evt_period3                   :    1;       /* [9] */
  volatile unsigned short evt_start3                    :    1;       /* [10] */
  volatile unsigned short evt_stop3                     :    1;       /* [11] */
  volatile unsigned short reserved                      :    4;
#endif
} _PACKED_ pwm_irq_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile pwm_irq_status_bf bf;
} _PACKED_ pwm_irq_status_t;


/* PWM_IRQ_MASK */

#define MSK_PWM_IRQ_MASK                                    (0xfff)   /* [11:0] */

typedef unsigned short pwm_irq_mask_t;                                /* [11:0] */


/* PWM_IRQ_VENABLE */

#define MSK_PWM_IRQ_VENABLE                                 (0xf)     /* [ 3:0] */

typedef unsigned short pwm_irq_venable_t;                             /* [ 3:0] */


/* PWM_IRQ_VDISABLE */

#define MSK_PWM_IRQ_VDISABLE                                (0xf)     /* [ 3:0] */

typedef unsigned short pwm_irq_vdisable_t;                            /* [ 3:0] */


/* PWM_IRQ_VMAX */

#define MSK_PWM_IRQ_VMAX                                    (0xf)     /* [ 3:0] */

typedef unsigned short pwm_irq_vmax_t;                                /* [ 3:0] */


/* PWM_IRQ_VNO */

#define MSK_PWM_IRQ_VNO                                     (0xf)     /* [ 3:0] */

typedef unsigned short pwm_irq_vno_t;                                 /* [ 3:0] */



/* PWM */

typedef struct {
  volatile pwm_control_t                           control;                        /* 0 */
  unsigned short                                   reserved0[1];
  volatile pwm_status_t                            status;                         /* 4 */
  volatile pwm_polarity_t                          polarity;                       /* 6 */
  volatile pwm_prescaler_t                         prescaler0;                     /* 8 */
  volatile pwm_prescaler_t                         prescaler1;                    /* 10 */
  volatile pwm_prescaler_t                         prescaler2;                    /* 12 */
  volatile pwm_prescaler_t                         prescaler3;                    /* 14 */
  volatile pwm_period_t                            period0;                       /* 16 */
  volatile pwm_start_t                             start0;                        /* 18 */
  volatile pwm_stop_t                              stop0;                         /* 20 */
  volatile pwm_counter_t                           counter0;                      /* 22 */
  volatile pwm_period_t                            period1;                       /* 24 */
  volatile pwm_start_t                             start1;                        /* 26 */
  volatile pwm_stop_t                              stop1;                         /* 28 */
  volatile pwm_counter_t                           counter1;                      /* 30 */
  volatile pwm_period_t                            period2;                       /* 32 */
  volatile pwm_start_t                             start2;                        /* 34 */
  volatile pwm_stop_t                              stop2;                         /* 36 */
  volatile pwm_counter_t                           counter2;                      /* 38 */
  volatile pwm_period_t                            period3;                       /* 40 */
  volatile pwm_start_t                             start3;                        /* 42 */
  volatile pwm_stop_t                              stop3;                         /* 44 */
  volatile pwm_counter_t                           counter3;                      /* 46 */
  volatile pwm_irq_status_t                        irq_status;                    /* 48 */
  unsigned short                                   reserved1[1];
  volatile pwm_irq_mask_t                          irq_mask;                      /* 52 */
  unsigned short                                   reserved2[1];
  volatile pwm_irq_venable_t                       irq_venable;                   /* 56 */
  volatile pwm_irq_vdisable_t                      irq_vdisable;                  /* 58 */
  volatile pwm_irq_vmax_t                          irq_vmax;                      /* 60 */
  volatile pwm_irq_vno_t                           irq_vno;                       /* 62 */
} _PACKED_ pwm_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_PWM 0x0440U ... PWM Module

#define ADDR_PWM_CONTROL                                     (0x00U)
#define A_PWM_CONTROL(ba)                                    ((ba) + ADDR_PWM_CONTROL)
#define R_PWM_CONTROL(ba)                                    (*(volatile unsigned short *)((unsigned int)A_PWM_CONTROL(ba)))
#define RES_PWM_CONTROL                                      (0x0U)
#define MSB_PWM_CONTROL                                      3
#define LSB_PWM_CONTROL                                      0
#define AADDR_PWM_CONTROL                                    (BASE_ADDR_PWM + ADDR_PWM_CONTROL)
#define REG_PWM_CONTROL                                      (*(volatile unsigned short *)((unsigned int)AADDR_PWM_CONTROL))

#define ADDR_PWM_STATUS                                      (0x04U)
#define A_PWM_STATUS(ba)                                     ((ba) + ADDR_PWM_STATUS)
#define R_PWM_STATUS(ba)                                     (*(volatile unsigned short *)((unsigned int)A_PWM_STATUS(ba)))
#define RES_PWM_STATUS                                       (0x0U)
#define MSB_PWM_STATUS                                       4
#define LSB_PWM_STATUS                                       0
#define AADDR_PWM_STATUS                                     (BASE_ADDR_PWM + ADDR_PWM_STATUS)
#define REG_PWM_STATUS                                       (*(volatile unsigned short *)((unsigned int)AADDR_PWM_STATUS))

#define ADDR_PWM_POLARITY                                    (0x06U)
#define A_PWM_POLARITY(ba)                                   ((ba) + ADDR_PWM_POLARITY)
#define R_PWM_POLARITY(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_POLARITY(ba)))
#define RES_PWM_POLARITY                                     (0x0U)
#define MSB_PWM_POLARITY                                     11
#define LSB_PWM_POLARITY                                     0
#define AADDR_PWM_POLARITY                                   (BASE_ADDR_PWM + ADDR_PWM_POLARITY)
#define REG_PWM_POLARITY                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_POLARITY))

#define ADDR_PWM_PRESCALER0                                  (0x08U)
#define A_PWM_PRESCALER0(ba)                                 ((ba) + ADDR_PWM_PRESCALER0)
#define R_PWM_PRESCALER0(ba)                                 (*(volatile unsigned short *)((unsigned int)A_PWM_PRESCALER0(ba)))
#define RES_PWM_PRESCALER0                                   (0x0U)
#define MSB_PWM_PRESCALER0                                   7
#define LSB_PWM_PRESCALER0                                   0
#define AADDR_PWM_PRESCALER0                                 (BASE_ADDR_PWM + ADDR_PWM_PRESCALER0)
#define REG_PWM_PRESCALER0                                   (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PRESCALER0))

#define ADDR_PWM_PRESCALER1                                  (0x0AU)
#define A_PWM_PRESCALER1(ba)                                 ((ba) + ADDR_PWM_PRESCALER1)
#define R_PWM_PRESCALER1(ba)                                 (*(volatile unsigned short *)((unsigned int)A_PWM_PRESCALER1(ba)))
#define RES_PWM_PRESCALER1                                   (0x0U)
#define MSB_PWM_PRESCALER1                                   7
#define LSB_PWM_PRESCALER1                                   0
#define AADDR_PWM_PRESCALER1                                 (BASE_ADDR_PWM + ADDR_PWM_PRESCALER1)
#define REG_PWM_PRESCALER1                                   (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PRESCALER1))

#define ADDR_PWM_PRESCALER2                                  (0x0CU)
#define A_PWM_PRESCALER2(ba)                                 ((ba) + ADDR_PWM_PRESCALER2)
#define R_PWM_PRESCALER2(ba)                                 (*(volatile unsigned short *)((unsigned int)A_PWM_PRESCALER2(ba)))
#define RES_PWM_PRESCALER2                                   (0x0U)
#define MSB_PWM_PRESCALER2                                   7
#define LSB_PWM_PRESCALER2                                   0
#define AADDR_PWM_PRESCALER2                                 (BASE_ADDR_PWM + ADDR_PWM_PRESCALER2)
#define REG_PWM_PRESCALER2                                   (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PRESCALER2))

#define ADDR_PWM_PRESCALER3                                  (0x0EU)
#define A_PWM_PRESCALER3(ba)                                 ((ba) + ADDR_PWM_PRESCALER3)
#define R_PWM_PRESCALER3(ba)                                 (*(volatile unsigned short *)((unsigned int)A_PWM_PRESCALER3(ba)))
#define RES_PWM_PRESCALER3                                   (0x0U)
#define MSB_PWM_PRESCALER3                                   7
#define LSB_PWM_PRESCALER3                                   0
#define AADDR_PWM_PRESCALER3                                 (BASE_ADDR_PWM + ADDR_PWM_PRESCALER3)
#define REG_PWM_PRESCALER3                                   (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PRESCALER3))

#define ADDR_PWM_PERIOD0                                     (0x10U)
#define A_PWM_PERIOD0(ba)                                    ((ba) + ADDR_PWM_PERIOD0)
#define R_PWM_PERIOD0(ba)                                    (*(volatile unsigned short *)((unsigned int)A_PWM_PERIOD0(ba)))
#define RES_PWM_PERIOD0                                      (0x0U)
#define MSB_PWM_PERIOD0                                      15
#define LSB_PWM_PERIOD0                                      0
#define AADDR_PWM_PERIOD0                                    (BASE_ADDR_PWM + ADDR_PWM_PERIOD0)
#define REG_PWM_PERIOD0                                      (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PERIOD0))

#define ADDR_PWM_START0                                      (0x12U)
#define A_PWM_START0(ba)                                     ((ba) + ADDR_PWM_START0)
#define R_PWM_START0(ba)                                     (*(volatile unsigned short *)((unsigned int)A_PWM_START0(ba)))
#define RES_PWM_START0                                       (0x0U)
#define MSB_PWM_START0                                       15
#define LSB_PWM_START0                                       0
#define AADDR_PWM_START0                                     (BASE_ADDR_PWM + ADDR_PWM_START0)
#define REG_PWM_START0                                       (*(volatile unsigned short *)((unsigned int)AADDR_PWM_START0))

#define ADDR_PWM_STOP0                                       (0x14U)
#define A_PWM_STOP0(ba)                                      ((ba) + ADDR_PWM_STOP0)
#define R_PWM_STOP0(ba)                                      (*(volatile unsigned short *)((unsigned int)A_PWM_STOP0(ba)))
#define RES_PWM_STOP0                                        (0x0U)
#define MSB_PWM_STOP0                                        15
#define LSB_PWM_STOP0                                        0
#define AADDR_PWM_STOP0                                      (BASE_ADDR_PWM + ADDR_PWM_STOP0)
#define REG_PWM_STOP0                                        (*(volatile unsigned short *)((unsigned int)AADDR_PWM_STOP0))

#define ADDR_PWM_COUNTER0                                    (0x16U)
#define A_PWM_COUNTER0(ba)                                   ((ba) + ADDR_PWM_COUNTER0)
#define R_PWM_COUNTER0(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_COUNTER0(ba)))
#define RES_PWM_COUNTER0                                     (0x0U)
#define MSB_PWM_COUNTER0                                     15
#define LSB_PWM_COUNTER0                                     0
#define AADDR_PWM_COUNTER0                                   (BASE_ADDR_PWM + ADDR_PWM_COUNTER0)
#define REG_PWM_COUNTER0                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_COUNTER0))

#define ADDR_PWM_PERIOD1                                     (0x18U)
#define A_PWM_PERIOD1(ba)                                    ((ba) + ADDR_PWM_PERIOD1)
#define R_PWM_PERIOD1(ba)                                    (*(volatile unsigned short *)((unsigned int)A_PWM_PERIOD1(ba)))
#define RES_PWM_PERIOD1                                      (0x0U)
#define MSB_PWM_PERIOD1                                      15
#define LSB_PWM_PERIOD1                                      0
#define AADDR_PWM_PERIOD1                                    (BASE_ADDR_PWM + ADDR_PWM_PERIOD1)
#define REG_PWM_PERIOD1                                      (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PERIOD1))

#define ADDR_PWM_START1                                      (0x1AU)
#define A_PWM_START1(ba)                                     ((ba) + ADDR_PWM_START1)
#define R_PWM_START1(ba)                                     (*(volatile unsigned short *)((unsigned int)A_PWM_START1(ba)))
#define RES_PWM_START1                                       (0x0U)
#define MSB_PWM_START1                                       15
#define LSB_PWM_START1                                       0
#define AADDR_PWM_START1                                     (BASE_ADDR_PWM + ADDR_PWM_START1)
#define REG_PWM_START1                                       (*(volatile unsigned short *)((unsigned int)AADDR_PWM_START1))

#define ADDR_PWM_STOP1                                       (0x1CU)
#define A_PWM_STOP1(ba)                                      ((ba) + ADDR_PWM_STOP1)
#define R_PWM_STOP1(ba)                                      (*(volatile unsigned short *)((unsigned int)A_PWM_STOP1(ba)))
#define RES_PWM_STOP1                                        (0x0U)
#define MSB_PWM_STOP1                                        15
#define LSB_PWM_STOP1                                        0
#define AADDR_PWM_STOP1                                      (BASE_ADDR_PWM + ADDR_PWM_STOP1)
#define REG_PWM_STOP1                                        (*(volatile unsigned short *)((unsigned int)AADDR_PWM_STOP1))

#define ADDR_PWM_COUNTER1                                    (0x1EU)
#define A_PWM_COUNTER1(ba)                                   ((ba) + ADDR_PWM_COUNTER1)
#define R_PWM_COUNTER1(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_COUNTER1(ba)))
#define RES_PWM_COUNTER1                                     (0x0U)
#define MSB_PWM_COUNTER1                                     15
#define LSB_PWM_COUNTER1                                     0
#define AADDR_PWM_COUNTER1                                   (BASE_ADDR_PWM + ADDR_PWM_COUNTER1)
#define REG_PWM_COUNTER1                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_COUNTER1))

#define ADDR_PWM_PERIOD2                                     (0x20U)
#define A_PWM_PERIOD2(ba)                                    ((ba) + ADDR_PWM_PERIOD2)
#define R_PWM_PERIOD2(ba)                                    (*(volatile unsigned short *)((unsigned int)A_PWM_PERIOD2(ba)))
#define RES_PWM_PERIOD2                                      (0x0U)
#define MSB_PWM_PERIOD2                                      15
#define LSB_PWM_PERIOD2                                      0
#define AADDR_PWM_PERIOD2                                    (BASE_ADDR_PWM + ADDR_PWM_PERIOD2)
#define REG_PWM_PERIOD2                                      (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PERIOD2))

#define ADDR_PWM_START2                                      (0x22U)
#define A_PWM_START2(ba)                                     ((ba) + ADDR_PWM_START2)
#define R_PWM_START2(ba)                                     (*(volatile unsigned short *)((unsigned int)A_PWM_START2(ba)))
#define RES_PWM_START2                                       (0x0U)
#define MSB_PWM_START2                                       15
#define LSB_PWM_START2                                       0
#define AADDR_PWM_START2                                     (BASE_ADDR_PWM + ADDR_PWM_START2)
#define REG_PWM_START2                                       (*(volatile unsigned short *)((unsigned int)AADDR_PWM_START2))

#define ADDR_PWM_STOP2                                       (0x24U)
#define A_PWM_STOP2(ba)                                      ((ba) + ADDR_PWM_STOP2)
#define R_PWM_STOP2(ba)                                      (*(volatile unsigned short *)((unsigned int)A_PWM_STOP2(ba)))
#define RES_PWM_STOP2                                        (0x0U)
#define MSB_PWM_STOP2                                        15
#define LSB_PWM_STOP2                                        0
#define AADDR_PWM_STOP2                                      (BASE_ADDR_PWM + ADDR_PWM_STOP2)
#define REG_PWM_STOP2                                        (*(volatile unsigned short *)((unsigned int)AADDR_PWM_STOP2))

#define ADDR_PWM_COUNTER2                                    (0x26U)
#define A_PWM_COUNTER2(ba)                                   ((ba) + ADDR_PWM_COUNTER2)
#define R_PWM_COUNTER2(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_COUNTER2(ba)))
#define RES_PWM_COUNTER2                                     (0x0U)
#define MSB_PWM_COUNTER2                                     15
#define LSB_PWM_COUNTER2                                     0
#define AADDR_PWM_COUNTER2                                   (BASE_ADDR_PWM + ADDR_PWM_COUNTER2)
#define REG_PWM_COUNTER2                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_COUNTER2))

#define ADDR_PWM_PERIOD3                                     (0x28U)
#define A_PWM_PERIOD3(ba)                                    ((ba) + ADDR_PWM_PERIOD3)
#define R_PWM_PERIOD3(ba)                                    (*(volatile unsigned short *)((unsigned int)A_PWM_PERIOD3(ba)))
#define RES_PWM_PERIOD3                                      (0x0U)
#define MSB_PWM_PERIOD3                                      15
#define LSB_PWM_PERIOD3                                      0
#define AADDR_PWM_PERIOD3                                    (BASE_ADDR_PWM + ADDR_PWM_PERIOD3)
#define REG_PWM_PERIOD3                                      (*(volatile unsigned short *)((unsigned int)AADDR_PWM_PERIOD3))

#define ADDR_PWM_START3                                      (0x2AU)
#define A_PWM_START3(ba)                                     ((ba) + ADDR_PWM_START3)
#define R_PWM_START3(ba)                                     (*(volatile unsigned short *)((unsigned int)A_PWM_START3(ba)))
#define RES_PWM_START3                                       (0x0U)
#define MSB_PWM_START3                                       15
#define LSB_PWM_START3                                       0
#define AADDR_PWM_START3                                     (BASE_ADDR_PWM + ADDR_PWM_START3)
#define REG_PWM_START3                                       (*(volatile unsigned short *)((unsigned int)AADDR_PWM_START3))

#define ADDR_PWM_STOP3                                       (0x2CU)
#define A_PWM_STOP3(ba)                                      ((ba) + ADDR_PWM_STOP3)
#define R_PWM_STOP3(ba)                                      (*(volatile unsigned short *)((unsigned int)A_PWM_STOP3(ba)))
#define RES_PWM_STOP3                                        (0x0U)
#define MSB_PWM_STOP3                                        15
#define LSB_PWM_STOP3                                        0
#define AADDR_PWM_STOP3                                      (BASE_ADDR_PWM + ADDR_PWM_STOP3)
#define REG_PWM_STOP3                                        (*(volatile unsigned short *)((unsigned int)AADDR_PWM_STOP3))

#define ADDR_PWM_COUNTER3                                    (0x2EU)
#define A_PWM_COUNTER3(ba)                                   ((ba) + ADDR_PWM_COUNTER3)
#define R_PWM_COUNTER3(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_COUNTER3(ba)))
#define RES_PWM_COUNTER3                                     (0x0U)
#define MSB_PWM_COUNTER3                                     15
#define LSB_PWM_COUNTER3                                     0
#define AADDR_PWM_COUNTER3                                   (BASE_ADDR_PWM + ADDR_PWM_COUNTER3)
#define REG_PWM_COUNTER3                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_COUNTER3))

#define ADDR_PWM_IRQ_STATUS                                  (0x30U)
#define A_PWM_IRQ_STATUS(ba)                                 ((ba) + ADDR_PWM_IRQ_STATUS)
#define R_PWM_IRQ_STATUS(ba)                                 (*(volatile unsigned short *)((unsigned int)A_PWM_IRQ_STATUS(ba)))
#define RES_PWM_IRQ_STATUS                                   (0x0U)
#define MSB_PWM_IRQ_STATUS                                   11
#define LSB_PWM_IRQ_STATUS                                   0
#define AADDR_PWM_IRQ_STATUS                                 (BASE_ADDR_PWM + ADDR_PWM_IRQ_STATUS)
#define REG_PWM_IRQ_STATUS                                   (*(volatile unsigned short *)((unsigned int)AADDR_PWM_IRQ_STATUS))

#define ADDR_PWM_IRQ_MASK                                    (0x34U)
#define A_PWM_IRQ_MASK(ba)                                   ((ba) + ADDR_PWM_IRQ_MASK)
#define R_PWM_IRQ_MASK(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_IRQ_MASK(ba)))
#define RES_PWM_IRQ_MASK                                     (0x0U)
#define MSB_PWM_IRQ_MASK                                     11
#define LSB_PWM_IRQ_MASK                                     0
#define AADDR_PWM_IRQ_MASK                                   (BASE_ADDR_PWM + ADDR_PWM_IRQ_MASK)
#define REG_PWM_IRQ_MASK                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_IRQ_MASK))

#define ADDR_PWM_IRQ_VENABLE                                 (0x38U)
#define A_PWM_IRQ_VENABLE(ba)                                ((ba) + ADDR_PWM_IRQ_VENABLE)
#define R_PWM_IRQ_VENABLE(ba)                                (*(volatile unsigned short *)((unsigned int)A_PWM_IRQ_VENABLE(ba)))
#define RES_PWM_IRQ_VENABLE                                  (0x0U)
#define MSB_PWM_IRQ_VENABLE                                  3
#define LSB_PWM_IRQ_VENABLE                                  0
#define AADDR_PWM_IRQ_VENABLE                                (BASE_ADDR_PWM + ADDR_PWM_IRQ_VENABLE)
#define REG_PWM_IRQ_VENABLE                                  (*(volatile unsigned short *)((unsigned int)AADDR_PWM_IRQ_VENABLE))

#define ADDR_PWM_IRQ_VDISABLE                                (0x3AU)
#define A_PWM_IRQ_VDISABLE(ba)                               ((ba) + ADDR_PWM_IRQ_VDISABLE)
#define R_PWM_IRQ_VDISABLE(ba)                               (*(volatile unsigned short *)((unsigned int)A_PWM_IRQ_VDISABLE(ba)))
#define RES_PWM_IRQ_VDISABLE                                 (0x0U)
#define MSB_PWM_IRQ_VDISABLE                                 3
#define LSB_PWM_IRQ_VDISABLE                                 0
#define AADDR_PWM_IRQ_VDISABLE                               (BASE_ADDR_PWM + ADDR_PWM_IRQ_VDISABLE)
#define REG_PWM_IRQ_VDISABLE                                 (*(volatile unsigned short *)((unsigned int)AADDR_PWM_IRQ_VDISABLE))

#define ADDR_PWM_IRQ_VMAX                                    (0x3CU)
#define A_PWM_IRQ_VMAX(ba)                                   ((ba) + ADDR_PWM_IRQ_VMAX)
#define R_PWM_IRQ_VMAX(ba)                                   (*(volatile unsigned short *)((unsigned int)A_PWM_IRQ_VMAX(ba)))
#define RES_PWM_IRQ_VMAX                                     (0xcU)
#define MSB_PWM_IRQ_VMAX                                     3
#define LSB_PWM_IRQ_VMAX                                     0
#define AADDR_PWM_IRQ_VMAX                                   (BASE_ADDR_PWM + ADDR_PWM_IRQ_VMAX)
#define REG_PWM_IRQ_VMAX                                     (*(volatile unsigned short *)((unsigned int)AADDR_PWM_IRQ_VMAX))

#define ADDR_PWM_IRQ_VNO                                     (0x3EU)
#define A_PWM_IRQ_VNO(ba)                                    ((ba) + ADDR_PWM_IRQ_VNO)
#define R_PWM_IRQ_VNO(ba)                                    (*(volatile unsigned short *)((unsigned int)A_PWM_IRQ_VNO(ba)))
#define RES_PWM_IRQ_VNO                                      (0xcU)
#define MSB_PWM_IRQ_VNO                                      3
#define LSB_PWM_IRQ_VNO                                      0
#define AADDR_PWM_IRQ_VNO                                    (BASE_ADDR_PWM + ADDR_PWM_IRQ_VNO)
#define REG_PWM_IRQ_VNO                                      (*(volatile unsigned short *)((unsigned int)AADDR_PWM_IRQ_VNO))




#endif
