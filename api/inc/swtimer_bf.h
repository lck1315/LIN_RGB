#ifndef __SWTIMER_BF_H__
#define __SWTIMER_BF_H__

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

#ifndef BASE_ADDR_SWTIMER
#define BASE_ADDR_SWTIMER 0x00C0U
#endif

#define NUMBER_SWTIMER 1

typedef enum {
  SWTIMER                        = (int)BASE_ADDR_SWTIMER
} swtimer_num_t;

// Register bit field definitions

/* SWTIMER_CONFIG */

#define MSK_SWTIMER_CONFIG_ENABLES                          (0x3)     /* [ 1:0] */
#define SFT_SWTIMER_CONFIG_ENABLES                          (0)
#define MSK_SWTIMER_CONFIG_CNT_AUTO_RELOADS                 (0x3)     /* [ 3:2] */
#define SFT_SWTIMER_CONFIG_CNT_AUTO_RELOADS                 (2)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   28;
  volatile unsigned long  cnt_auto_reloads              :    2;       /* [ 3:2] */
  volatile unsigned long  enables                       :    2;       /* [ 1:0] */
#else
  volatile unsigned short enables                       :    2;       /* [ 1:0] */
  volatile unsigned short cnt_auto_reloads              :    2;       /* [ 3:2] */
  volatile unsigned short reserved                      :   12;
#endif
} _PACKED_ swtimer_config_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile swtimer_config_bf bf;
} _PACKED_ swtimer_config_t;


/* SWTIMER_COMMAND */

#define MSK_SWTIMER_COMMAND_CNT_RELOAD_CMD                  (0x3)     /* [ 1:0] */
#define SFT_SWTIMER_COMMAND_CNT_RELOAD_CMD                  (0)
#define MSK_SWTIMER_COMMAND_DIV_RELOAD_CMD                  (0x3)     /* [ 3:2] */
#define SFT_SWTIMER_COMMAND_DIV_RELOAD_CMD                  (2)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   28;
  volatile unsigned long  div_reload_cmd                :    2;       /* [ 3:2] */
  volatile unsigned long  cnt_reload_cmd                :    2;       /* [ 1:0] */
#else
  volatile unsigned short cnt_reload_cmd                :    2;       /* [ 1:0] */
  volatile unsigned short div_reload_cmd                :    2;       /* [ 3:2] */
  volatile unsigned short reserved                      :   12;
#endif
} _PACKED_ swtimer_command_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile swtimer_command_bf bf;
} _PACKED_ swtimer_command_t;


/* SWTIMER_CNT_RELOAD */

#define MSK_SWTIMER_CNT_RELOAD                              (0xffff)  /* [15:0] */

typedef unsigned short swtimer_cnt_reload_t;                          /* [15:0] */


/* SWTIMER_DIV_RELOAD */

#define MSK_SWTIMER_DIV_RELOAD                              (0xff)    /* [ 7:0] */

typedef unsigned short swtimer_div_reload_t;                          /* [ 7:0] */


/* SWTIMER_CNT_VALUE */

#define MSK_SWTIMER_CNT_VALUE                               (0xffff)  /* [15:0] */

typedef unsigned short swtimer_cnt_value_t;                           /* [15:0] */


/* SWTIMER_IRQ_STATUS */

#define MSK_SWTIMER_IRQ_STATUS_EVT_CNT_ZERO                 (0x3)     /* [ 1:0] */
#define SFT_SWTIMER_IRQ_STATUS_EVT_CNT_ZERO                 (0)
#define MSK_SWTIMER_IRQ_STATUS_EVT_DIV_ZERO                 (0x3)     /* [ 3:2] */
#define SFT_SWTIMER_IRQ_STATUS_EVT_DIV_ZERO                 (2)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   28;
  volatile unsigned long  evt_div_zero                  :    2;       /* [ 3:2] */
  volatile unsigned long  evt_cnt_zero                  :    2;       /* [ 1:0] */
#else
  volatile unsigned short evt_cnt_zero                  :    2;       /* [ 1:0] */
  volatile unsigned short evt_div_zero                  :    2;       /* [ 3:2] */
  volatile unsigned short reserved                      :   12;
#endif
} _PACKED_ swtimer_irq_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile swtimer_irq_status_bf bf;
} _PACKED_ swtimer_irq_status_t;


/* SWTIMER_IRQ_MASK */

#define MSK_SWTIMER_IRQ_MASK                                (0xf)     /* [ 3:0] */

typedef unsigned short swtimer_irq_mask_t;                            /* [ 3:0] */


/* SWTIMER_IRQ_VENABLE */

#define MSK_SWTIMER_IRQ_VENABLE                             (0x3)     /* [ 1:0] */

typedef unsigned short swtimer_irq_venable_t;                         /* [ 1:0] */


/* SWTIMER_IRQ_VDISABLE */

#define MSK_SWTIMER_IRQ_VDISABLE                            (0x3)     /* [ 1:0] */

typedef unsigned short swtimer_irq_vdisable_t;                        /* [ 1:0] */


/* SWTIMER_IRQ_VMAX */

#define MSK_SWTIMER_IRQ_VMAX                                (0x7)     /* [ 2:0] */

typedef unsigned short swtimer_irq_vmax_t;                            /* [ 2:0] */


/* SWTIMER_IRQ_VNO */

#define MSK_SWTIMER_IRQ_VNO                                 (0x7)     /* [ 2:0] */

typedef unsigned short swtimer_irq_vno_t;                             /* [ 2:0] */



/* SWTIMER */

typedef struct {
  volatile swtimer_config_t                        config;                         /* 0 */
  volatile swtimer_command_t                       command;                        /* 2 */
  volatile swtimer_cnt_reload_t                    cnt0_reload;                    /* 4 */
  volatile swtimer_cnt_reload_t                    cnt1_reload;                    /* 6 */
  volatile swtimer_div_reload_t                    div0_reload;                    /* 8 */
  volatile swtimer_div_reload_t                    div1_reload;                   /* 10 */
  volatile swtimer_cnt_value_t                     cnt0_value;                    /* 12 */
  volatile swtimer_cnt_value_t                     cnt1_value;                    /* 14 */
  unsigned short                                   reserved0[16];
  volatile swtimer_irq_status_t                    irq_status;                    /* 48 */
  unsigned short                                   reserved1[1];
  volatile swtimer_irq_mask_t                      irq_mask;                      /* 52 */
  unsigned short                                   reserved2[1];
  volatile swtimer_irq_venable_t                   irq_venable;                   /* 56 */
  volatile swtimer_irq_vdisable_t                  irq_vdisable;                  /* 58 */
  volatile swtimer_irq_vmax_t                      irq_vmax;                      /* 60 */
  volatile swtimer_irq_vno_t                       irq_vno;                       /* 62 */
} _PACKED_ swtimer_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_SWTIMER 0x00C0U ... Timer Module

#define ADDR_SWTIMER_CONFIG                                  (0x00U)
#define A_SWTIMER_CONFIG(ba)                                 ((ba) + ADDR_SWTIMER_CONFIG)
#define R_SWTIMER_CONFIG(ba)                                 (*(volatile unsigned short *)((unsigned int)A_SWTIMER_CONFIG(ba)))
#define RES_SWTIMER_CONFIG                                   (0x0U)
#define MSB_SWTIMER_CONFIG                                   3
#define LSB_SWTIMER_CONFIG                                   0
#define AADDR_SWTIMER_CONFIG                                 (BASE_ADDR_SWTIMER + ADDR_SWTIMER_CONFIG)
#define REG_SWTIMER_CONFIG                                   (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_CONFIG))

#define ADDR_SWTIMER_COMMAND                                 (0x02U)
#define A_SWTIMER_COMMAND(ba)                                ((ba) + ADDR_SWTIMER_COMMAND)
#define R_SWTIMER_COMMAND(ba)                                (*(volatile unsigned short *)((unsigned int)A_SWTIMER_COMMAND(ba)))
#define RES_SWTIMER_COMMAND                                  (0x0U)
#define MSB_SWTIMER_COMMAND                                  3
#define LSB_SWTIMER_COMMAND                                  0
#define AADDR_SWTIMER_COMMAND                                (BASE_ADDR_SWTIMER + ADDR_SWTIMER_COMMAND)
#define REG_SWTIMER_COMMAND                                  (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_COMMAND))

#define ADDR_SWTIMER_CNT0_RELOAD                             (0x04U)
#define A_SWTIMER_CNT0_RELOAD(ba)                            ((ba) + ADDR_SWTIMER_CNT0_RELOAD)
#define R_SWTIMER_CNT0_RELOAD(ba)                            (*(volatile unsigned short *)((unsigned int)A_SWTIMER_CNT0_RELOAD(ba)))
#define RES_SWTIMER_CNT0_RELOAD                              (0x0U)
#define MSB_SWTIMER_CNT0_RELOAD                              15
#define LSB_SWTIMER_CNT0_RELOAD                              0
#define AADDR_SWTIMER_CNT0_RELOAD                            (BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT0_RELOAD)
#define REG_SWTIMER_CNT0_RELOAD                              (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_CNT0_RELOAD))

#define ADDR_SWTIMER_CNT1_RELOAD                             (0x06U)
#define A_SWTIMER_CNT1_RELOAD(ba)                            ((ba) + ADDR_SWTIMER_CNT1_RELOAD)
#define R_SWTIMER_CNT1_RELOAD(ba)                            (*(volatile unsigned short *)((unsigned int)A_SWTIMER_CNT1_RELOAD(ba)))
#define RES_SWTIMER_CNT1_RELOAD                              (0x0U)
#define MSB_SWTIMER_CNT1_RELOAD                              15
#define LSB_SWTIMER_CNT1_RELOAD                              0
#define AADDR_SWTIMER_CNT1_RELOAD                            (BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT1_RELOAD)
#define REG_SWTIMER_CNT1_RELOAD                              (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_CNT1_RELOAD))

#define ADDR_SWTIMER_DIV0_RELOAD                             (0x08U)
#define A_SWTIMER_DIV0_RELOAD(ba)                            ((ba) + ADDR_SWTIMER_DIV0_RELOAD)
#define R_SWTIMER_DIV0_RELOAD(ba)                            (*(volatile unsigned short *)((unsigned int)A_SWTIMER_DIV0_RELOAD(ba)))
#define RES_SWTIMER_DIV0_RELOAD                              (0x0U)
#define MSB_SWTIMER_DIV0_RELOAD                              7
#define LSB_SWTIMER_DIV0_RELOAD                              0
#define AADDR_SWTIMER_DIV0_RELOAD                            (BASE_ADDR_SWTIMER + ADDR_SWTIMER_DIV0_RELOAD)
#define REG_SWTIMER_DIV0_RELOAD                              (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_DIV0_RELOAD))

#define ADDR_SWTIMER_DIV1_RELOAD                             (0x0AU)
#define A_SWTIMER_DIV1_RELOAD(ba)                            ((ba) + ADDR_SWTIMER_DIV1_RELOAD)
#define R_SWTIMER_DIV1_RELOAD(ba)                            (*(volatile unsigned short *)((unsigned int)A_SWTIMER_DIV1_RELOAD(ba)))
#define RES_SWTIMER_DIV1_RELOAD                              (0x0U)
#define MSB_SWTIMER_DIV1_RELOAD                              7
#define LSB_SWTIMER_DIV1_RELOAD                              0
#define AADDR_SWTIMER_DIV1_RELOAD                            (BASE_ADDR_SWTIMER + ADDR_SWTIMER_DIV1_RELOAD)
#define REG_SWTIMER_DIV1_RELOAD                              (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_DIV1_RELOAD))

#define ADDR_SWTIMER_CNT0_VALUE                              (0x0CU)
#define A_SWTIMER_CNT0_VALUE(ba)                             ((ba) + ADDR_SWTIMER_CNT0_VALUE)
#define R_SWTIMER_CNT0_VALUE(ba)                             (*(volatile unsigned short *)((unsigned int)A_SWTIMER_CNT0_VALUE(ba)))
#define RES_SWTIMER_CNT0_VALUE                               (0x0U)
#define MSB_SWTIMER_CNT0_VALUE                               15
#define LSB_SWTIMER_CNT0_VALUE                               0
#define AADDR_SWTIMER_CNT0_VALUE                             (BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT0_VALUE)
#define REG_SWTIMER_CNT0_VALUE                               (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_CNT0_VALUE))

#define ADDR_SWTIMER_CNT1_VALUE                              (0x0EU)
#define A_SWTIMER_CNT1_VALUE(ba)                             ((ba) + ADDR_SWTIMER_CNT1_VALUE)
#define R_SWTIMER_CNT1_VALUE(ba)                             (*(volatile unsigned short *)((unsigned int)A_SWTIMER_CNT1_VALUE(ba)))
#define RES_SWTIMER_CNT1_VALUE                               (0x0U)
#define MSB_SWTIMER_CNT1_VALUE                               15
#define LSB_SWTIMER_CNT1_VALUE                               0
#define AADDR_SWTIMER_CNT1_VALUE                             (BASE_ADDR_SWTIMER + ADDR_SWTIMER_CNT1_VALUE)
#define REG_SWTIMER_CNT1_VALUE                               (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_CNT1_VALUE))

#define ADDR_SWTIMER_IRQ_STATUS                              (0x30U)
#define A_SWTIMER_IRQ_STATUS(ba)                             ((ba) + ADDR_SWTIMER_IRQ_STATUS)
#define R_SWTIMER_IRQ_STATUS(ba)                             (*(volatile unsigned short *)((unsigned int)A_SWTIMER_IRQ_STATUS(ba)))
#define RES_SWTIMER_IRQ_STATUS                               (0x0U)
#define MSB_SWTIMER_IRQ_STATUS                               3
#define LSB_SWTIMER_IRQ_STATUS                               0
#define AADDR_SWTIMER_IRQ_STATUS                             (BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_STATUS)
#define REG_SWTIMER_IRQ_STATUS                               (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_IRQ_STATUS))

#define ADDR_SWTIMER_IRQ_MASK                                (0x34U)
#define A_SWTIMER_IRQ_MASK(ba)                               ((ba) + ADDR_SWTIMER_IRQ_MASK)
#define R_SWTIMER_IRQ_MASK(ba)                               (*(volatile unsigned short *)((unsigned int)A_SWTIMER_IRQ_MASK(ba)))
#define RES_SWTIMER_IRQ_MASK                                 (0x0U)
#define MSB_SWTIMER_IRQ_MASK                                 3
#define LSB_SWTIMER_IRQ_MASK                                 0
#define AADDR_SWTIMER_IRQ_MASK                               (BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_MASK)
#define REG_SWTIMER_IRQ_MASK                                 (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_IRQ_MASK))

#define ADDR_SWTIMER_IRQ_VENABLE                             (0x38U)
#define A_SWTIMER_IRQ_VENABLE(ba)                            ((ba) + ADDR_SWTIMER_IRQ_VENABLE)
#define R_SWTIMER_IRQ_VENABLE(ba)                            (*(volatile unsigned short *)((unsigned int)A_SWTIMER_IRQ_VENABLE(ba)))
#define RES_SWTIMER_IRQ_VENABLE                              (0x0U)
#define MSB_SWTIMER_IRQ_VENABLE                              1
#define LSB_SWTIMER_IRQ_VENABLE                              0
#define AADDR_SWTIMER_IRQ_VENABLE                            (BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_VENABLE)
#define REG_SWTIMER_IRQ_VENABLE                              (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_IRQ_VENABLE))

#define ADDR_SWTIMER_IRQ_VDISABLE                            (0x3AU)
#define A_SWTIMER_IRQ_VDISABLE(ba)                           ((ba) + ADDR_SWTIMER_IRQ_VDISABLE)
#define R_SWTIMER_IRQ_VDISABLE(ba)                           (*(volatile unsigned short *)((unsigned int)A_SWTIMER_IRQ_VDISABLE(ba)))
#define RES_SWTIMER_IRQ_VDISABLE                             (0x0U)
#define MSB_SWTIMER_IRQ_VDISABLE                             1
#define LSB_SWTIMER_IRQ_VDISABLE                             0
#define AADDR_SWTIMER_IRQ_VDISABLE                           (BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_VDISABLE)
#define REG_SWTIMER_IRQ_VDISABLE                             (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_IRQ_VDISABLE))

#define ADDR_SWTIMER_IRQ_VMAX                                (0x3CU)
#define A_SWTIMER_IRQ_VMAX(ba)                               ((ba) + ADDR_SWTIMER_IRQ_VMAX)
#define R_SWTIMER_IRQ_VMAX(ba)                               (*(volatile unsigned short *)((unsigned int)A_SWTIMER_IRQ_VMAX(ba)))
#define RES_SWTIMER_IRQ_VMAX                                 (0x4U)
#define MSB_SWTIMER_IRQ_VMAX                                 2
#define LSB_SWTIMER_IRQ_VMAX                                 0
#define AADDR_SWTIMER_IRQ_VMAX                               (BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_VMAX)
#define REG_SWTIMER_IRQ_VMAX                                 (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_IRQ_VMAX))

#define ADDR_SWTIMER_IRQ_VNO                                 (0x3EU)
#define A_SWTIMER_IRQ_VNO(ba)                                ((ba) + ADDR_SWTIMER_IRQ_VNO)
#define R_SWTIMER_IRQ_VNO(ba)                                (*(volatile unsigned short *)((unsigned int)A_SWTIMER_IRQ_VNO(ba)))
#define RES_SWTIMER_IRQ_VNO                                  (0x4U)
#define MSB_SWTIMER_IRQ_VNO                                  2
#define LSB_SWTIMER_IRQ_VNO                                  0
#define AADDR_SWTIMER_IRQ_VNO                                (BASE_ADDR_SWTIMER + ADDR_SWTIMER_IRQ_VNO)
#define REG_SWTIMER_IRQ_VNO                                  (*(volatile unsigned short *)((unsigned int)AADDR_SWTIMER_IRQ_VNO))




#endif
