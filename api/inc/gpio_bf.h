#ifndef __GPIO_BF_H__
#define __GPIO_BF_H__

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

#ifndef BASE_ADDR_GPIO
#define BASE_ADDR_GPIO 0x0200U
#endif

#define NUMBER_GPIO 1

typedef enum {
  GPIO                           = (int)BASE_ADDR_GPIO
} gpio_num_t;

// Register bit field definitions

/* GPIO_DIRECTION */

#define MSK_GPIO_DIRECTION                                  (0xff)    /* [ 7:0] */

typedef unsigned short gpio_direction_t;                              /* [ 7:0] */


/* GPIO_DRIVER */

#define MSK_GPIO_DRIVER                                     (0xff)    /* [ 7:0] */

typedef unsigned short gpio_driver_t;                                 /* [ 7:0] */


/* GPIO_DATAOUT */

#define MSK_GPIO_DATAOUT                                    (0xff)    /* [ 7:0] */

typedef unsigned short gpio_dataout_t;                                /* [ 7:0] */


/* GPIO_INPUT_ENABLE */

#define MSK_GPIO_INPUT_ENABLE                               (0xff)    /* [ 7:0] */

typedef unsigned short gpio_input_enable_t;                           /* [ 7:0] */


/* GPIO_DIRECTION_LOCK */

#define MSK_GPIO_DIRECTION_LOCK                             (0xff)    /* [ 7:0] */

typedef unsigned short gpio_direction_lock_t;                         /* [ 7:0] */


/* GPIO_IRQ_STATUS */

#define MSK_GPIO_IRQ_STATUS_EVT_POS_0                       (0x1)     /* [0] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_0                       (0)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_0                       (0x1)     /* [0] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_0                       (0x1)     /* [1] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_0                       (1)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_0                       (0x2)     /* [1] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_1                       (0x1)     /* [2] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_1                       (2)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_1                       (0x4)     /* [2] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_1                       (0x1)     /* [3] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_1                       (3)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_1                       (0x8)     /* [3] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_2                       (0x1)     /* [4] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_2                       (4)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_2                       (0x10)    /* [4] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_2                       (0x1)     /* [5] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_2                       (5)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_2                       (0x20)    /* [5] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_3                       (0x1)     /* [6] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_3                       (6)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_3                       (0x40)    /* [6] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_3                       (0x1)     /* [7] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_3                       (7)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_3                       (0x80)    /* [7] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_4                       (0x1)     /* [8] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_4                       (8)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_4                       (0x100)   /* [8] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_4                       (0x1)     /* [9] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_4                       (9)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_4                       (0x200)   /* [9] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_5                       (0x1)     /* [10] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_5                       (10)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_5                       (0x400)   /* [10] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_5                       (0x1)     /* [11] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_5                       (11)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_5                       (0x800)   /* [11] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_6                       (0x1)     /* [12] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_6                       (12)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_6                       (0x1000)  /* [12] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_6                       (0x1)     /* [13] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_6                       (13)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_6                       (0x2000)  /* [13] */
#define MSK_GPIO_IRQ_STATUS_EVT_POS_7                       (0x1)     /* [14] */
#define SFT_GPIO_IRQ_STATUS_EVT_POS_7                       (14)
#define BIT_GPIO_IRQ_STATUS_EVT_POS_7                       (0x4000)  /* [14] */
#define MSK_GPIO_IRQ_STATUS_EVT_NEG_7                       (0x1)     /* [15] */
#define SFT_GPIO_IRQ_STATUS_EVT_NEG_7                       (15)
#define BIT_GPIO_IRQ_STATUS_EVT_NEG_7                       (0x8000)  /* [15] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  evt_neg_7                     :    1;       /* [15] */
  volatile unsigned long  evt_pos_7                     :    1;       /* [14] */
  volatile unsigned long  evt_neg_6                     :    1;       /* [13] */
  volatile unsigned long  evt_pos_6                     :    1;       /* [12] */
  volatile unsigned long  evt_neg_5                     :    1;       /* [11] */
  volatile unsigned long  evt_pos_5                     :    1;       /* [10] */
  volatile unsigned long  evt_neg_4                     :    1;       /* [9] */
  volatile unsigned long  evt_pos_4                     :    1;       /* [8] */
  volatile unsigned long  evt_neg_3                     :    1;       /* [7] */
  volatile unsigned long  evt_pos_3                     :    1;       /* [6] */
  volatile unsigned long  evt_neg_2                     :    1;       /* [5] */
  volatile unsigned long  evt_pos_2                     :    1;       /* [4] */
  volatile unsigned long  evt_neg_1                     :    1;       /* [3] */
  volatile unsigned long  evt_pos_1                     :    1;       /* [2] */
  volatile unsigned long  evt_neg_0                     :    1;       /* [1] */
  volatile unsigned long  evt_pos_0                     :    1;       /* [0] */
#else
  volatile unsigned short evt_pos_0                     :    1;       /* [0] */
  volatile unsigned short evt_neg_0                     :    1;       /* [1] */
  volatile unsigned short evt_pos_1                     :    1;       /* [2] */
  volatile unsigned short evt_neg_1                     :    1;       /* [3] */
  volatile unsigned short evt_pos_2                     :    1;       /* [4] */
  volatile unsigned short evt_neg_2                     :    1;       /* [5] */
  volatile unsigned short evt_pos_3                     :    1;       /* [6] */
  volatile unsigned short evt_neg_3                     :    1;       /* [7] */
  volatile unsigned short evt_pos_4                     :    1;       /* [8] */
  volatile unsigned short evt_neg_4                     :    1;       /* [9] */
  volatile unsigned short evt_pos_5                     :    1;       /* [10] */
  volatile unsigned short evt_neg_5                     :    1;       /* [11] */
  volatile unsigned short evt_pos_6                     :    1;       /* [12] */
  volatile unsigned short evt_neg_6                     :    1;       /* [13] */
  volatile unsigned short evt_pos_7                     :    1;       /* [14] */
  volatile unsigned short evt_neg_7                     :    1;       /* [15] */
#endif
} _PACKED_ gpio_irq_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile gpio_irq_status_bf bf;
} _PACKED_ gpio_irq_status_t;


/* GPIO_IRQ_MASK */

#define MSK_GPIO_IRQ_MASK                                   (0xffff)  /* [15:0] */

typedef unsigned short gpio_irq_mask_t;                               /* [15:0] */


/* GPIO_IRQ_VENABLE */

#define MSK_GPIO_IRQ_VENABLE                                (0xf)     /* [ 3:0] */

typedef unsigned short gpio_irq_venable_t;                            /* [ 3:0] */


/* GPIO_IRQ_VDISABLE */

#define MSK_GPIO_IRQ_VDISABLE                               (0xf)     /* [ 3:0] */

typedef unsigned short gpio_irq_vdisable_t;                           /* [ 3:0] */


/* GPIO_IRQ_VMAX */

#define MSK_GPIO_IRQ_VMAX                                   (0x1f)    /* [ 4:0] */

typedef unsigned short gpio_irq_vmax_t;                               /* [ 4:0] */


/* GPIO_IRQ_VNO */

#define MSK_GPIO_IRQ_VNO                                    (0x1f)    /* [ 4:0] */

typedef unsigned short gpio_irq_vno_t;                                /* [ 4:0] */



/* GPIO */

typedef struct {
  volatile gpio_direction_t                        data_out;                       /* 0 */
  volatile gpio_driver_t                           data_oe;                        /* 2 */
  volatile gpio_dataout_t                          data_in;                        /* 4 */
  volatile gpio_input_enable_t                     data_ie;                        /* 6 */
  volatile gpio_direction_lock_t                   direction_lock;                 /* 8 */
  unsigned short                                   reserved0[19];
  volatile gpio_irq_status_t                       irq_status;                    /* 48 */
  unsigned short                                   reserved1[1];
  volatile gpio_irq_mask_t                         irq_mask;                      /* 52 */
  unsigned short                                   reserved2[1];
  volatile gpio_irq_venable_t                      irq_venable;                   /* 56 */
  volatile gpio_irq_vdisable_t                     irq_vdisable;                  /* 58 */
  volatile gpio_irq_vmax_t                         irq_vmax;                      /* 60 */
  volatile gpio_irq_vno_t                          irq_vno;                       /* 62 */
} _PACKED_ gpio_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_GPIO 0x0200U ... GPIO Module

#define ADDR_GPIO_DATA_OUT                                   (0x00U)
#define A_GPIO_DATA_OUT(ba)                                  ((ba) + ADDR_GPIO_DATA_OUT)
#define R_GPIO_DATA_OUT(ba)                                  (*(volatile unsigned short *)((unsigned int)A_GPIO_DATA_OUT(ba)))
#define RES_GPIO_DATA_OUT                                    (0x0U)
#define MSB_GPIO_DATA_OUT                                    7
#define LSB_GPIO_DATA_OUT                                    0
#define AADDR_GPIO_DATA_OUT                                  (BASE_ADDR_GPIO + ADDR_GPIO_DATA_OUT)
#define REG_GPIO_DATA_OUT                                    (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_DATA_OUT))

#define ADDR_GPIO_DATA_OE                                    (0x02U)
#define A_GPIO_DATA_OE(ba)                                   ((ba) + ADDR_GPIO_DATA_OE)
#define R_GPIO_DATA_OE(ba)                                   (*(volatile unsigned short *)((unsigned int)A_GPIO_DATA_OE(ba)))
#define RES_GPIO_DATA_OE                                     (0x0U)
#define MSB_GPIO_DATA_OE                                     7
#define LSB_GPIO_DATA_OE                                     0
#define AADDR_GPIO_DATA_OE                                   (BASE_ADDR_GPIO + ADDR_GPIO_DATA_OE)
#define REG_GPIO_DATA_OE                                     (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_DATA_OE))

#define ADDR_GPIO_DATA_IN                                    (0x04U)
#define A_GPIO_DATA_IN(ba)                                   ((ba) + ADDR_GPIO_DATA_IN)
#define R_GPIO_DATA_IN(ba)                                   (*(volatile unsigned short *)((unsigned int)A_GPIO_DATA_IN(ba)))
#define RES_GPIO_DATA_IN                                     (0x0U)
#define MSB_GPIO_DATA_IN                                     7
#define LSB_GPIO_DATA_IN                                     0
#define AADDR_GPIO_DATA_IN                                   (BASE_ADDR_GPIO + ADDR_GPIO_DATA_IN)
#define REG_GPIO_DATA_IN                                     (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_DATA_IN))

#define ADDR_GPIO_DATA_IE                                    (0x06U)
#define A_GPIO_DATA_IE(ba)                                   ((ba) + ADDR_GPIO_DATA_IE)
#define R_GPIO_DATA_IE(ba)                                   (*(volatile unsigned short *)((unsigned int)A_GPIO_DATA_IE(ba)))
#define RES_GPIO_DATA_IE                                     (0x0U)
#define MSB_GPIO_DATA_IE                                     7
#define LSB_GPIO_DATA_IE                                     0
#define AADDR_GPIO_DATA_IE                                   (BASE_ADDR_GPIO + ADDR_GPIO_DATA_IE)
#define REG_GPIO_DATA_IE                                     (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_DATA_IE))

#define ADDR_GPIO_DIRECTION_LOCK                             (0x08U)
#define A_GPIO_DIRECTION_LOCK(ba)                            ((ba) + ADDR_GPIO_DIRECTION_LOCK)
#define R_GPIO_DIRECTION_LOCK(ba)                            (*(volatile unsigned short *)((unsigned int)A_GPIO_DIRECTION_LOCK(ba)))
#define RES_GPIO_DIRECTION_LOCK                              (0x0U)
#define MSB_GPIO_DIRECTION_LOCK                              7
#define LSB_GPIO_DIRECTION_LOCK                              0
#define AADDR_GPIO_DIRECTION_LOCK                            (BASE_ADDR_GPIO + ADDR_GPIO_DIRECTION_LOCK)
#define REG_GPIO_DIRECTION_LOCK                              (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_DIRECTION_LOCK))

#define ADDR_GPIO_IRQ_STATUS                                 (0x30U)
#define A_GPIO_IRQ_STATUS(ba)                                ((ba) + ADDR_GPIO_IRQ_STATUS)
#define R_GPIO_IRQ_STATUS(ba)                                (*(volatile unsigned short *)((unsigned int)A_GPIO_IRQ_STATUS(ba)))
#define RES_GPIO_IRQ_STATUS                                  (0x0U)
#define MSB_GPIO_IRQ_STATUS                                  15
#define LSB_GPIO_IRQ_STATUS                                  0
#define AADDR_GPIO_IRQ_STATUS                                (BASE_ADDR_GPIO + ADDR_GPIO_IRQ_STATUS)
#define REG_GPIO_IRQ_STATUS                                  (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_IRQ_STATUS))

#define ADDR_GPIO_IRQ_MASK                                   (0x34U)
#define A_GPIO_IRQ_MASK(ba)                                  ((ba) + ADDR_GPIO_IRQ_MASK)
#define R_GPIO_IRQ_MASK(ba)                                  (*(volatile unsigned short *)((unsigned int)A_GPIO_IRQ_MASK(ba)))
#define RES_GPIO_IRQ_MASK                                    (0x0U)
#define MSB_GPIO_IRQ_MASK                                    15
#define LSB_GPIO_IRQ_MASK                                    0
#define AADDR_GPIO_IRQ_MASK                                  (BASE_ADDR_GPIO + ADDR_GPIO_IRQ_MASK)
#define REG_GPIO_IRQ_MASK                                    (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_IRQ_MASK))

#define ADDR_GPIO_IRQ_VENABLE                                (0x38U)
#define A_GPIO_IRQ_VENABLE(ba)                               ((ba) + ADDR_GPIO_IRQ_VENABLE)
#define R_GPIO_IRQ_VENABLE(ba)                               (*(volatile unsigned short *)((unsigned int)A_GPIO_IRQ_VENABLE(ba)))
#define RES_GPIO_IRQ_VENABLE                                 (0x0U)
#define MSB_GPIO_IRQ_VENABLE                                 3
#define LSB_GPIO_IRQ_VENABLE                                 0
#define AADDR_GPIO_IRQ_VENABLE                               (BASE_ADDR_GPIO + ADDR_GPIO_IRQ_VENABLE)
#define REG_GPIO_IRQ_VENABLE                                 (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_IRQ_VENABLE))

#define ADDR_GPIO_IRQ_VDISABLE                               (0x3AU)
#define A_GPIO_IRQ_VDISABLE(ba)                              ((ba) + ADDR_GPIO_IRQ_VDISABLE)
#define R_GPIO_IRQ_VDISABLE(ba)                              (*(volatile unsigned short *)((unsigned int)A_GPIO_IRQ_VDISABLE(ba)))
#define RES_GPIO_IRQ_VDISABLE                                (0x0U)
#define MSB_GPIO_IRQ_VDISABLE                                3
#define LSB_GPIO_IRQ_VDISABLE                                0
#define AADDR_GPIO_IRQ_VDISABLE                              (BASE_ADDR_GPIO + ADDR_GPIO_IRQ_VDISABLE)
#define REG_GPIO_IRQ_VDISABLE                                (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_IRQ_VDISABLE))

#define ADDR_GPIO_IRQ_VMAX                                   (0x3CU)
#define A_GPIO_IRQ_VMAX(ba)                                  ((ba) + ADDR_GPIO_IRQ_VMAX)
#define R_GPIO_IRQ_VMAX(ba)                                  (*(volatile unsigned short *)((unsigned int)A_GPIO_IRQ_VMAX(ba)))
#define RES_GPIO_IRQ_VMAX                                    (0x10U)
#define MSB_GPIO_IRQ_VMAX                                    4
#define LSB_GPIO_IRQ_VMAX                                    0
#define AADDR_GPIO_IRQ_VMAX                                  (BASE_ADDR_GPIO + ADDR_GPIO_IRQ_VMAX)
#define REG_GPIO_IRQ_VMAX                                    (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_IRQ_VMAX))

#define ADDR_GPIO_IRQ_VNO                                    (0x3EU)
#define A_GPIO_IRQ_VNO(ba)                                   ((ba) + ADDR_GPIO_IRQ_VNO)
#define R_GPIO_IRQ_VNO(ba)                                   (*(volatile unsigned short *)((unsigned int)A_GPIO_IRQ_VNO(ba)))
#define RES_GPIO_IRQ_VNO                                     (0x10U)
#define MSB_GPIO_IRQ_VNO                                     4
#define LSB_GPIO_IRQ_VNO                                     0
#define AADDR_GPIO_IRQ_VNO                                   (BASE_ADDR_GPIO + ADDR_GPIO_IRQ_VNO)
#define REG_GPIO_IRQ_VNO                                     (*(volatile unsigned short *)((unsigned int)AADDR_GPIO_IRQ_VNO))




#endif
