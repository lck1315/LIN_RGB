#ifndef __VIC_BF_H__
#define __VIC_BF_H__

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

#ifndef BASE_ADDR_VIC
#define BASE_ADDR_VIC 0x0040U
#endif

#define NUMBER_VIC 1

typedef enum {
  VIC                            = (int)BASE_ADDR_VIC
} vic_num_t;

// Register bit field definitions

/* VIC_TABLE_BASE */

#define MSK_VIC_TABLE_BASE                                  (0xffff)  /* [15:0] */

typedef unsigned short vic_table_base_t;                              /* [15:0] */


/* VIC_TABLE_TYPE */

#define MSK_VIC_TABLE_TYPE                                  (0x1)     /* [0] */

typedef unsigned short vic_table_type_t;                              /* [0] */


/* VIC_MAIN_ENABLE */

#define MSK_VIC_MAIN_ENABLE                                 (0x1)     /* [0] */

typedef unsigned short vic_main_enable_t;                             /* [0] */


/* VIC_IRQ_STATUS0 */

#define MSK_VIC_IRQ_STATUS0_SYS_STATE                       (0x1)     /* [0] */
#define SFT_VIC_IRQ_STATUS0_SYS_STATE                       (0)
#define BIT_VIC_IRQ_STATUS0_SYS_STATE                       (0x1)     /* [0] */
#define MSK_VIC_IRQ_STATUS0_WDOG                            (0x1)     /* [1] */
#define SFT_VIC_IRQ_STATUS0_WDOG                            (1)
#define BIT_VIC_IRQ_STATUS0_WDOG                            (0x2)     /* [1] */
#define MSK_VIC_IRQ_STATUS0_DIVIDER                         (0x1)     /* [2] */
#define SFT_VIC_IRQ_STATUS0_DIVIDER                         (2)
#define BIT_VIC_IRQ_STATUS0_DIVIDER                         (0x4)     /* [2] */
#define MSK_VIC_IRQ_STATUS0_HV_CTRL                         (0x1)     /* [3] */
#define SFT_VIC_IRQ_STATUS0_HV_CTRL                         (3)
#define BIT_VIC_IRQ_STATUS0_HV_CTRL                         (0x8)     /* [3] */
#define MSK_VIC_IRQ_STATUS0_ADC_CTRL                        (0x1)     /* [4] */
#define SFT_VIC_IRQ_STATUS0_ADC_CTRL                        (4)
#define BIT_VIC_IRQ_STATUS0_ADC_CTRL                        (0x10)    /* [4] */
#define MSK_VIC_IRQ_STATUS0_PWM                             (0x1)     /* [5] */
#define SFT_VIC_IRQ_STATUS0_PWM                             (5)
#define BIT_VIC_IRQ_STATUS0_PWM                             (0x20)    /* [5] */
#define MSK_VIC_IRQ_STATUS0_SCI                             (0x1)     /* [6] */
#define SFT_VIC_IRQ_STATUS0_SCI                             (6)
#define BIT_VIC_IRQ_STATUS0_SCI                             (0x40)    /* [6] */
#define MSK_VIC_IRQ_STATUS0_SWTIMER                         (0x1)     /* [7] */
#define SFT_VIC_IRQ_STATUS0_SWTIMER                         (7)
#define BIT_VIC_IRQ_STATUS0_SWTIMER                         (0x80)    /* [7] */
#define MSK_VIC_IRQ_STATUS0_GPIO                            (0x1)     /* [8] */
#define SFT_VIC_IRQ_STATUS0_GPIO                            (8)
#define BIT_VIC_IRQ_STATUS0_GPIO                            (0x100)   /* [8] */
#define MSK_VIC_IRQ_STATUS0_CCTIMER                         (0x1)     /* [9] */
#define SFT_VIC_IRQ_STATUS0_CCTIMER                         (9)
#define BIT_VIC_IRQ_STATUS0_CCTIMER                         (0x200)   /* [9] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   22;
  volatile unsigned long  cctimer                       :    1;       /* [9] */
  volatile unsigned long  gpio                          :    1;       /* [8] */
  volatile unsigned long  swtimer                       :    1;       /* [7] */
  volatile unsigned long  sci                           :    1;       /* [6] */
  volatile unsigned long  pwm                           :    1;       /* [5] */
  volatile unsigned long  adc_ctrl                      :    1;       /* [4] */
  volatile unsigned long  hv_ctrl                       :    1;       /* [3] */
  volatile unsigned long  divider                       :    1;       /* [2] */
  volatile unsigned long  wdog                          :    1;       /* [1] */
  volatile unsigned long  sys_state                     :    1;       /* [0] */
#else
  volatile unsigned short sys_state                     :    1;       /* [0] */
  volatile unsigned short wdog                          :    1;       /* [1] */
  volatile unsigned short divider                       :    1;       /* [2] */
  volatile unsigned short hv_ctrl                       :    1;       /* [3] */
  volatile unsigned short adc_ctrl                      :    1;       /* [4] */
  volatile unsigned short pwm                           :    1;       /* [5] */
  volatile unsigned short sci                           :    1;       /* [6] */
  volatile unsigned short swtimer                       :    1;       /* [7] */
  volatile unsigned short gpio                          :    1;       /* [8] */
  volatile unsigned short cctimer                       :    1;       /* [9] */
  volatile unsigned short reserved                      :    6;
#endif
} _PACKED_ vic_irq_status0_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile vic_irq_status0_bf bf;
} _PACKED_ vic_irq_status0_t;


/* VIC_IRQ_MASK0 */

#define MSK_VIC_IRQ_MASK0                                   (0x3ff)   /* [ 9:0] */

typedef unsigned short vic_irq_mask0_t;                               /* [ 9:0] */


/* VIC_IRQ_VENABLE */

#define MSK_VIC_IRQ_VENABLE                                 (0xf)     /* [ 3:0] */

typedef unsigned short vic_irq_venable_t;                             /* [ 3:0] */


/* VIC_IRQ_VDISABLE */

#define MSK_VIC_IRQ_VDISABLE                                (0xf)     /* [ 3:0] */

typedef unsigned short vic_irq_vdisable_t;                            /* [ 3:0] */


/* VIC_IRQ_VMAX */

#define MSK_VIC_IRQ_VMAX                                    (0xf)     /* [ 3:0] */

typedef unsigned short vic_irq_vmax_t;                                /* [ 3:0] */


/* VIC_IRQ_VNO */

#define MSK_VIC_IRQ_VNO                                     (0xf)     /* [ 3:0] */

typedef unsigned short vic_irq_vno_t;                                 /* [ 3:0] */



/* VIC */

typedef struct {
  volatile vic_table_base_t                        table_base;                     /* 0 */
  volatile vic_table_type_t                        table_type;                     /* 2 */
  volatile vic_main_enable_t                       main_enable;                    /* 4 */
  unsigned short                                   reserved0[21];
  volatile vic_irq_status0_t                       irq_status;                    /* 48 */
  unsigned short                                   reserved1[1];
  volatile vic_irq_mask0_t                         irq_mask;                      /* 52 */
  unsigned short                                   reserved2[1];
  volatile vic_irq_venable_t                       irq_venable;                   /* 56 */
  volatile vic_irq_vdisable_t                      irq_vdisable;                  /* 58 */
  volatile vic_irq_vmax_t                          irq_vmax;                      /* 60 */
  volatile vic_irq_vno_t                           irq_vno;                       /* 62 */
} _PACKED_ vic_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_VIC 0x0040U ... Vector Interrupt Controller Module

#define ADDR_VIC_TABLE_BASE                                  (0x00U)
#define A_VIC_TABLE_BASE(ba)                                 ((ba) + ADDR_VIC_TABLE_BASE)
#define R_VIC_TABLE_BASE(ba)                                 (*(volatile unsigned short *)((unsigned int)A_VIC_TABLE_BASE(ba)))
#define RES_VIC_TABLE_BASE                                   (0x0U)
#define MSB_VIC_TABLE_BASE                                   15
#define LSB_VIC_TABLE_BASE                                   0
#define AADDR_VIC_TABLE_BASE                                 (BASE_ADDR_VIC + ADDR_VIC_TABLE_BASE)
#define REG_VIC_TABLE_BASE                                   (*(volatile unsigned short *)((unsigned int)AADDR_VIC_TABLE_BASE))

#define ADDR_VIC_TABLE_TYPE                                  (0x02U)
#define A_VIC_TABLE_TYPE(ba)                                 ((ba) + ADDR_VIC_TABLE_TYPE)
#define R_VIC_TABLE_TYPE(ba)                                 (*(volatile unsigned short *)((unsigned int)A_VIC_TABLE_TYPE(ba)))
#define RES_VIC_TABLE_TYPE                                   (0x0U)
#define MSB_VIC_TABLE_TYPE                                   0
#define LSB_VIC_TABLE_TYPE                                   0
#define AADDR_VIC_TABLE_TYPE                                 (BASE_ADDR_VIC + ADDR_VIC_TABLE_TYPE)
#define REG_VIC_TABLE_TYPE                                   (*(volatile unsigned short *)((unsigned int)AADDR_VIC_TABLE_TYPE))

#define ADDR_VIC_MAIN_ENABLE                                 (0x04U)
#define A_VIC_MAIN_ENABLE(ba)                                ((ba) + ADDR_VIC_MAIN_ENABLE)
#define R_VIC_MAIN_ENABLE(ba)                                (*(volatile unsigned short *)((unsigned int)A_VIC_MAIN_ENABLE(ba)))
#define RES_VIC_MAIN_ENABLE                                  (0x1U)
#define MSB_VIC_MAIN_ENABLE                                  0
#define LSB_VIC_MAIN_ENABLE                                  0
#define AADDR_VIC_MAIN_ENABLE                                (BASE_ADDR_VIC + ADDR_VIC_MAIN_ENABLE)
#define REG_VIC_MAIN_ENABLE                                  (*(volatile unsigned short *)((unsigned int)AADDR_VIC_MAIN_ENABLE))

#define ADDR_VIC_IRQ_STATUS                                  (0x30U)
#define A_VIC_IRQ_STATUS(ba)                                 ((ba) + ADDR_VIC_IRQ_STATUS)
#define R_VIC_IRQ_STATUS(ba)                                 (*(volatile unsigned short *)((unsigned int)A_VIC_IRQ_STATUS(ba)))
#define RES_VIC_IRQ_STATUS                                   (0x0U)
#define MSB_VIC_IRQ_STATUS                                   9
#define LSB_VIC_IRQ_STATUS                                   0
#define AADDR_VIC_IRQ_STATUS                                 (BASE_ADDR_VIC + ADDR_VIC_IRQ_STATUS)
#define REG_VIC_IRQ_STATUS                                   (*(volatile unsigned short *)((unsigned int)AADDR_VIC_IRQ_STATUS))

#define ADDR_VIC_IRQ_MASK                                    (0x34U)
#define A_VIC_IRQ_MASK(ba)                                   ((ba) + ADDR_VIC_IRQ_MASK)
#define R_VIC_IRQ_MASK(ba)                                   (*(volatile unsigned short *)((unsigned int)A_VIC_IRQ_MASK(ba)))
#define RES_VIC_IRQ_MASK                                     (0x0U)
#define MSB_VIC_IRQ_MASK                                     9
#define LSB_VIC_IRQ_MASK                                     0
#define AADDR_VIC_IRQ_MASK                                   (BASE_ADDR_VIC + ADDR_VIC_IRQ_MASK)
#define REG_VIC_IRQ_MASK                                     (*(volatile unsigned short *)((unsigned int)AADDR_VIC_IRQ_MASK))

#define ADDR_VIC_IRQ_VENABLE                                 (0x38U)
#define A_VIC_IRQ_VENABLE(ba)                                ((ba) + ADDR_VIC_IRQ_VENABLE)
#define R_VIC_IRQ_VENABLE(ba)                                (*(volatile unsigned short *)((unsigned int)A_VIC_IRQ_VENABLE(ba)))
#define RES_VIC_IRQ_VENABLE                                  (0x0U)
#define MSB_VIC_IRQ_VENABLE                                  3
#define LSB_VIC_IRQ_VENABLE                                  0
#define AADDR_VIC_IRQ_VENABLE                                (BASE_ADDR_VIC + ADDR_VIC_IRQ_VENABLE)
#define REG_VIC_IRQ_VENABLE                                  (*(volatile unsigned short *)((unsigned int)AADDR_VIC_IRQ_VENABLE))

#define ADDR_VIC_IRQ_VDISABLE                                (0x3AU)
#define A_VIC_IRQ_VDISABLE(ba)                               ((ba) + ADDR_VIC_IRQ_VDISABLE)
#define R_VIC_IRQ_VDISABLE(ba)                               (*(volatile unsigned short *)((unsigned int)A_VIC_IRQ_VDISABLE(ba)))
#define RES_VIC_IRQ_VDISABLE                                 (0x0U)
#define MSB_VIC_IRQ_VDISABLE                                 3
#define LSB_VIC_IRQ_VDISABLE                                 0
#define AADDR_VIC_IRQ_VDISABLE                               (BASE_ADDR_VIC + ADDR_VIC_IRQ_VDISABLE)
#define REG_VIC_IRQ_VDISABLE                                 (*(volatile unsigned short *)((unsigned int)AADDR_VIC_IRQ_VDISABLE))

#define ADDR_VIC_IRQ_VMAX                                    (0x3CU)
#define A_VIC_IRQ_VMAX(ba)                                   ((ba) + ADDR_VIC_IRQ_VMAX)
#define R_VIC_IRQ_VMAX(ba)                                   (*(volatile unsigned short *)((unsigned int)A_VIC_IRQ_VMAX(ba)))
#define RES_VIC_IRQ_VMAX                                     (0xaU)
#define MSB_VIC_IRQ_VMAX                                     3
#define LSB_VIC_IRQ_VMAX                                     0
#define AADDR_VIC_IRQ_VMAX                                   (BASE_ADDR_VIC + ADDR_VIC_IRQ_VMAX)
#define REG_VIC_IRQ_VMAX                                     (*(volatile unsigned short *)((unsigned int)AADDR_VIC_IRQ_VMAX))

#define ADDR_VIC_IRQ_VNO                                     (0x3EU)
#define A_VIC_IRQ_VNO(ba)                                    ((ba) + ADDR_VIC_IRQ_VNO)
#define R_VIC_IRQ_VNO(ba)                                    (*(volatile unsigned short *)((unsigned int)A_VIC_IRQ_VNO(ba)))
#define RES_VIC_IRQ_VNO                                      (0xaU)
#define MSB_VIC_IRQ_VNO                                      3
#define LSB_VIC_IRQ_VNO                                      0
#define AADDR_VIC_IRQ_VNO                                    (BASE_ADDR_VIC + ADDR_VIC_IRQ_VNO)
#define REG_VIC_IRQ_VNO                                      (*(volatile unsigned short *)((unsigned int)AADDR_VIC_IRQ_VNO))




#endif
