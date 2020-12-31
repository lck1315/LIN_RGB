#ifndef __HV_CTRL_BF_H__
#define __HV_CTRL_BF_H__

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

#ifndef BASE_ADDR_HV_CTRL
#define BASE_ADDR_HV_CTRL 0x0480U
#endif

#define NUMBER_HV_CTRL 1

typedef enum {
  HV_CTRL                        = (int)BASE_ADDR_HV_CTRL
} hv_ctrl_num_t;

// Register bit field definitions

/* HV_CTRL_SPI_SEND */

#define MSK_HV_CTRL_SPI_SEND_DATA                           (0xff)    /* [ 7:0] */
#define SFT_HV_CTRL_SPI_SEND_DATA                           (0)
#define MSK_HV_CTRL_SPI_SEND_ADDR                           (0x7f)    /* [14:8] */
#define SFT_HV_CTRL_SPI_SEND_ADDR                           (8)
#define MSK_HV_CTRL_SPI_SEND_WRITE                          (0x1)     /* [15] */
#define SFT_HV_CTRL_SPI_SEND_WRITE                          (15)
#define BIT_HV_CTRL_SPI_SEND_WRITE                          (0x8000)  /* [15] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  write                         :    1;       /* [15] */
  volatile unsigned long  addr                          :    7;       /* [14:8] */
  volatile unsigned long  data                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short data                          :    8;       /* [ 7:0] */
  volatile unsigned short addr                          :    7;       /* [14:8] */
  volatile unsigned short write                         :    1;       /* [15] */
#endif
} _PACKED_ hv_ctrl_spi_send_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile hv_ctrl_spi_send_bf bf;
} _PACKED_ hv_ctrl_spi_send_t;


/* HV_CTRL_SPI_RDATA */

#define MSK_HV_CTRL_SPI_RDATA_DATA                          (0xff)    /* [ 7:0] */
#define SFT_HV_CTRL_SPI_RDATA_DATA                          (0)
#define MSK_HV_CTRL_SPI_RDATA_STATUS                        (0xff)    /* [15:8] */
#define SFT_HV_CTRL_SPI_RDATA_STATUS                        (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  status                        :    8;       /* [15:8] */
  volatile unsigned long  data                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short data                          :    8;       /* [ 7:0] */
  volatile unsigned short status                        :    8;       /* [15:8] */
#endif
} _PACKED_ hv_ctrl_spi_rdata_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile hv_ctrl_spi_rdata_bf bf;
} _PACKED_ hv_ctrl_spi_rdata_t;


/* HV_CTRL_POST_SHIFT_DELAY */

#define MSK_HV_CTRL_POST_SHIFT_DELAY                        (0xff)    /* [ 7:0] */

typedef unsigned short hv_ctrl_post_shift_delay_t;                    /* [ 7:0] */


/* HV_CTRL_CCTIMER_SEL */

#define MSK_HV_CTRL_CCTIMER_SEL                             (0xf)     /* [ 3:0] */

typedef unsigned short hv_ctrl_cctimer_sel_t;                         /* [ 3:0] */


/* HV_CTRL_SPI_CONFIG */

#define MSK_HV_CTRL_SPI_CONFIG_BAUD_DIV                     (0x3f)    /* [ 5:0] */
#define SFT_HV_CTRL_SPI_CONFIG_BAUD_DIV                     (0)
#define MSK_HV_CTRL_SPI_CONFIG_MODE                         (0x3)     /* [ 7:6] */
#define SFT_HV_CTRL_SPI_CONFIG_MODE                         (6)
#define MSK_HV_CTRL_SPI_CONFIG_SHIFT                        (0x7)     /* [10:8] */
#define SFT_HV_CTRL_SPI_CONFIG_SHIFT                        (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   21;
  volatile unsigned long  shift                         :    3;       /* [10:8] */
  volatile unsigned long  mode                          :    2;       /* [ 7:6] */
  volatile unsigned long  baud_div                      :    6;       /* [ 5:0] */
#else
  volatile unsigned short baud_div                      :    6;       /* [ 5:0] */
  volatile unsigned short mode                          :    2;       /* [ 7:6] */
  volatile unsigned short shift                         :    3;       /* [10:8] */
  volatile unsigned short reserved                      :    5;
#endif
} _PACKED_ hv_ctrl_spi_config_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile hv_ctrl_spi_config_bf bf;
} _PACKED_ hv_ctrl_spi_config_t;


/* HV_CTRL_IRQ_STATUS */

#define MSK_HV_CTRL_IRQ_STATUS_RDATA_STATUS                 (0xff)    /* [ 7:0] */
#define SFT_HV_CTRL_IRQ_STATUS_RDATA_STATUS                 (0)
#define MSK_HV_CTRL_IRQ_STATUS_MISO_IRQ                     (0x1)     /* [8] */
#define SFT_HV_CTRL_IRQ_STATUS_MISO_IRQ                     (8)
#define BIT_HV_CTRL_IRQ_STATUS_MISO_IRQ                     (0x100)   /* [8] */
#define MSK_HV_CTRL_IRQ_STATUS_EOT                          (0x1)     /* [9] */
#define SFT_HV_CTRL_IRQ_STATUS_EOT                          (9)
#define BIT_HV_CTRL_IRQ_STATUS_EOT                          (0x200)   /* [9] */
#define MSK_HV_CTRL_IRQ_STATUS_EOT_SEND                     (0x1)     /* [10] */
#define SFT_HV_CTRL_IRQ_STATUS_EOT_SEND                     (10)
#define BIT_HV_CTRL_IRQ_STATUS_EOT_SEND                     (0x400)   /* [10] */
#define MSK_HV_CTRL_IRQ_STATUS_READY_WR                     (0x1)     /* [11] */
#define SFT_HV_CTRL_IRQ_STATUS_READY_WR                     (11)
#define BIT_HV_CTRL_IRQ_STATUS_READY_WR                     (0x800)   /* [11] */
#define MSK_HV_CTRL_IRQ_STATUS_READY_RD                     (0x1)     /* [12] */
#define SFT_HV_CTRL_IRQ_STATUS_READY_RD                     (12)
#define BIT_HV_CTRL_IRQ_STATUS_READY_RD                     (0x1000)  /* [12] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   19;
  volatile unsigned long  ready_rd                      :    1;       /* [12] */
  volatile unsigned long  ready_wr                      :    1;       /* [11] */
  volatile unsigned long  eot_send                      :    1;       /* [10] */
  volatile unsigned long  eot                           :    1;       /* [9] */
  volatile unsigned long  miso_irq                      :    1;       /* [8] */
  volatile unsigned long  rdata_status                  :    8;       /* [ 7:0] */
#else
  volatile unsigned short rdata_status                  :    8;       /* [ 7:0] */
  volatile unsigned short miso_irq                      :    1;       /* [8] */
  volatile unsigned short eot                           :    1;       /* [9] */
  volatile unsigned short eot_send                      :    1;       /* [10] */
  volatile unsigned short ready_wr                      :    1;       /* [11] */
  volatile unsigned short ready_rd                      :    1;       /* [12] */
  volatile unsigned short reserved                      :    3;
#endif
} _PACKED_ hv_ctrl_irq_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile hv_ctrl_irq_status_bf bf;
} _PACKED_ hv_ctrl_irq_status_t;


/* HV_CTRL_IRQ_MASK */

#define MSK_HV_CTRL_IRQ_MASK                                (0x1fff)  /* [12:0] */

typedef unsigned short hv_ctrl_irq_mask_t;                            /* [12:0] */


/* HV_CTRL_IRQ_VENABLE */

#define MSK_HV_CTRL_IRQ_VENABLE                             (0xf)     /* [ 3:0] */

typedef unsigned short hv_ctrl_irq_venable_t;                         /* [ 3:0] */


/* HV_CTRL_IRQ_VDISABLE */

#define MSK_HV_CTRL_IRQ_VDISABLE                            (0xf)     /* [ 3:0] */

typedef unsigned short hv_ctrl_irq_vdisable_t;                        /* [ 3:0] */


/* HV_CTRL_IRQ_VMAX */

#define MSK_HV_CTRL_IRQ_VMAX                                (0xf)     /* [ 3:0] */

typedef unsigned short hv_ctrl_irq_vmax_t;                            /* [ 3:0] */


/* HV_CTRL_IRQ_VNO */

#define MSK_HV_CTRL_IRQ_VNO                                 (0xf)     /* [ 3:0] */

typedef unsigned short hv_ctrl_irq_vno_t;                             /* [ 3:0] */



/* HV_CTRL */

typedef struct {
  volatile hv_ctrl_spi_send_t                      spi_send;                       /* 0 */
  unsigned short                                   reserved0[1];
  volatile hv_ctrl_spi_rdata_t                     spi_rdata;                      /* 4 */
  volatile hv_ctrl_post_shift_delay_t              post_shift_delay;               /* 6 */
  volatile hv_ctrl_cctimer_sel_t                   cctimer_sel;                    /* 8 */
  volatile hv_ctrl_spi_config_t                    spi_config;                    /* 10 */
  unsigned short                                   reserved1[18];
  volatile hv_ctrl_irq_status_t                    irq_status;                    /* 48 */
  unsigned short                                   reserved2[1];
  volatile hv_ctrl_irq_mask_t                      irq_mask;                      /* 52 */
  unsigned short                                   reserved3[1];
  volatile hv_ctrl_irq_venable_t                   irq_venable;                   /* 56 */
  volatile hv_ctrl_irq_vdisable_t                  irq_vdisable;                  /* 58 */
  volatile hv_ctrl_irq_vmax_t                      irq_vmax;                      /* 60 */
  volatile hv_ctrl_irq_vno_t                       irq_vno;                       /* 62 */
} _PACKED_ hv_ctrl_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_HV_CTRL 0x0480U ... Analog Part Controller Module

#define ADDR_HV_CTRL_SPI_SEND                                (0x00U)
#define A_HV_CTRL_SPI_SEND(ba)                               ((ba) + ADDR_HV_CTRL_SPI_SEND)
#define R_HV_CTRL_SPI_SEND(ba)                               (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_SPI_SEND(ba)))
#define RES_HV_CTRL_SPI_SEND                                 (0x0U)
#define MSB_HV_CTRL_SPI_SEND                                 15
#define LSB_HV_CTRL_SPI_SEND                                 0
#define AADDR_HV_CTRL_SPI_SEND                               (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_SEND)
#define REG_HV_CTRL_SPI_SEND                                 (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_SPI_SEND))

#define ADDR_HV_CTRL_SPI_RDATA                               (0x04U)
#define A_HV_CTRL_SPI_RDATA(ba)                              ((ba) + ADDR_HV_CTRL_SPI_RDATA)
#define R_HV_CTRL_SPI_RDATA(ba)                              (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_SPI_RDATA(ba)))
#define RES_HV_CTRL_SPI_RDATA                                (0x0U)
#define MSB_HV_CTRL_SPI_RDATA                                15
#define LSB_HV_CTRL_SPI_RDATA                                0
#define AADDR_HV_CTRL_SPI_RDATA                              (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_RDATA)
#define REG_HV_CTRL_SPI_RDATA                                (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_SPI_RDATA))

#define ADDR_HV_CTRL_POST_SHIFT_DELAY                        (0x06U)
#define A_HV_CTRL_POST_SHIFT_DELAY(ba)                       ((ba) + ADDR_HV_CTRL_POST_SHIFT_DELAY)
#define R_HV_CTRL_POST_SHIFT_DELAY(ba)                       (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_POST_SHIFT_DELAY(ba)))
#define RES_HV_CTRL_POST_SHIFT_DELAY                         (0x0U)
#define MSB_HV_CTRL_POST_SHIFT_DELAY                         7
#define LSB_HV_CTRL_POST_SHIFT_DELAY                         0
#define AADDR_HV_CTRL_POST_SHIFT_DELAY                       (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_POST_SHIFT_DELAY)
#define REG_HV_CTRL_POST_SHIFT_DELAY                         (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_POST_SHIFT_DELAY))

#define ADDR_HV_CTRL_CCTIMER_SEL                             (0x08U)
#define A_HV_CTRL_CCTIMER_SEL(ba)                            ((ba) + ADDR_HV_CTRL_CCTIMER_SEL)
#define R_HV_CTRL_CCTIMER_SEL(ba)                            (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_CCTIMER_SEL(ba)))
#define RES_HV_CTRL_CCTIMER_SEL                              (0x0U)
#define MSB_HV_CTRL_CCTIMER_SEL                              3
#define LSB_HV_CTRL_CCTIMER_SEL                              0
#define AADDR_HV_CTRL_CCTIMER_SEL                            (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_CCTIMER_SEL)
#define REG_HV_CTRL_CCTIMER_SEL                              (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_CCTIMER_SEL))

#define ADDR_HV_CTRL_SPI_CONFIG                              (0x0AU)
#define A_HV_CTRL_SPI_CONFIG(ba)                             ((ba) + ADDR_HV_CTRL_SPI_CONFIG)
#define R_HV_CTRL_SPI_CONFIG(ba)                             (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_SPI_CONFIG(ba)))
#define RES_HV_CTRL_SPI_CONFIG                               (0x407U)
#define MSB_HV_CTRL_SPI_CONFIG                               10
#define LSB_HV_CTRL_SPI_CONFIG                               0
#define AADDR_HV_CTRL_SPI_CONFIG                             (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_SPI_CONFIG)
#define REG_HV_CTRL_SPI_CONFIG                               (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_SPI_CONFIG))

#define ADDR_HV_CTRL_IRQ_STATUS                              (0x30U)
#define A_HV_CTRL_IRQ_STATUS(ba)                             ((ba) + ADDR_HV_CTRL_IRQ_STATUS)
#define R_HV_CTRL_IRQ_STATUS(ba)                             (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_IRQ_STATUS(ba)))
#define RES_HV_CTRL_IRQ_STATUS                               (0x0U)
#define MSB_HV_CTRL_IRQ_STATUS                               12
#define LSB_HV_CTRL_IRQ_STATUS                               0
#define AADDR_HV_CTRL_IRQ_STATUS                             (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_STATUS)
#define REG_HV_CTRL_IRQ_STATUS                               (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_IRQ_STATUS))

#define ADDR_HV_CTRL_IRQ_MASK                                (0x34U)
#define A_HV_CTRL_IRQ_MASK(ba)                               ((ba) + ADDR_HV_CTRL_IRQ_MASK)
#define R_HV_CTRL_IRQ_MASK(ba)                               (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_IRQ_MASK(ba)))
#define RES_HV_CTRL_IRQ_MASK                                 (0x0U)
#define MSB_HV_CTRL_IRQ_MASK                                 12
#define LSB_HV_CTRL_IRQ_MASK                                 0
#define AADDR_HV_CTRL_IRQ_MASK                               (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_MASK)
#define REG_HV_CTRL_IRQ_MASK                                 (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_IRQ_MASK))

#define ADDR_HV_CTRL_IRQ_VENABLE                             (0x38U)
#define A_HV_CTRL_IRQ_VENABLE(ba)                            ((ba) + ADDR_HV_CTRL_IRQ_VENABLE)
#define R_HV_CTRL_IRQ_VENABLE(ba)                            (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_IRQ_VENABLE(ba)))
#define RES_HV_CTRL_IRQ_VENABLE                              (0x0U)
#define MSB_HV_CTRL_IRQ_VENABLE                              3
#define LSB_HV_CTRL_IRQ_VENABLE                              0
#define AADDR_HV_CTRL_IRQ_VENABLE                            (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_VENABLE)
#define REG_HV_CTRL_IRQ_VENABLE                              (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_IRQ_VENABLE))

#define ADDR_HV_CTRL_IRQ_VDISABLE                            (0x3AU)
#define A_HV_CTRL_IRQ_VDISABLE(ba)                           ((ba) + ADDR_HV_CTRL_IRQ_VDISABLE)
#define R_HV_CTRL_IRQ_VDISABLE(ba)                           (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_IRQ_VDISABLE(ba)))
#define RES_HV_CTRL_IRQ_VDISABLE                             (0x0U)
#define MSB_HV_CTRL_IRQ_VDISABLE                             3
#define LSB_HV_CTRL_IRQ_VDISABLE                             0
#define AADDR_HV_CTRL_IRQ_VDISABLE                           (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_VDISABLE)
#define REG_HV_CTRL_IRQ_VDISABLE                             (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_IRQ_VDISABLE))

#define ADDR_HV_CTRL_IRQ_VMAX                                (0x3CU)
#define A_HV_CTRL_IRQ_VMAX(ba)                               ((ba) + ADDR_HV_CTRL_IRQ_VMAX)
#define R_HV_CTRL_IRQ_VMAX(ba)                               (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_IRQ_VMAX(ba)))
#define RES_HV_CTRL_IRQ_VMAX                                 (0xdU)
#define MSB_HV_CTRL_IRQ_VMAX                                 3
#define LSB_HV_CTRL_IRQ_VMAX                                 0
#define AADDR_HV_CTRL_IRQ_VMAX                               (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_VMAX)
#define REG_HV_CTRL_IRQ_VMAX                                 (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_IRQ_VMAX))

#define ADDR_HV_CTRL_IRQ_VNO                                 (0x3EU)
#define A_HV_CTRL_IRQ_VNO(ba)                                ((ba) + ADDR_HV_CTRL_IRQ_VNO)
#define R_HV_CTRL_IRQ_VNO(ba)                                (*(volatile unsigned short *)((unsigned int)A_HV_CTRL_IRQ_VNO(ba)))
#define RES_HV_CTRL_IRQ_VNO                                  (0xdU)
#define MSB_HV_CTRL_IRQ_VNO                                  3
#define LSB_HV_CTRL_IRQ_VNO                                  0
#define AADDR_HV_CTRL_IRQ_VNO                                (BASE_ADDR_HV_CTRL + ADDR_HV_CTRL_IRQ_VNO)
#define REG_HV_CTRL_IRQ_VNO                                  (*(volatile unsigned short *)((unsigned int)AADDR_HV_CTRL_IRQ_VNO))




#endif
