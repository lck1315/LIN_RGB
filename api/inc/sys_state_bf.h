#ifndef __SYS_STATE_BF_H__
#define __SYS_STATE_BF_H__

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

#ifndef BASE_ADDR_SYS_STATE
#define BASE_ADDR_SYS_STATE 0x0180U
#endif

#define NUMBER_SYS_STATE 1

typedef enum {
  SYS_STATE                      = (int)BASE_ADDR_SYS_STATE
} sys_state_num_t;

// Register bit field definitions

/* SYS_STATE_MODULE_ENABLE */

#define MSK_SYS_STATE_MODULE_ENABLE_SCI                     (0x1)     /* [0] */
#define SFT_SYS_STATE_MODULE_ENABLE_SCI                     (0)
#define BIT_SYS_STATE_MODULE_ENABLE_SCI                     (0x1)     /* [0] */
#define MSK_SYS_STATE_MODULE_ENABLE_GPIO                    (0x1)     /* [1] */
#define SFT_SYS_STATE_MODULE_ENABLE_GPIO                    (1)
#define BIT_SYS_STATE_MODULE_ENABLE_GPIO                    (0x2)     /* [1] */
#define MSK_SYS_STATE_MODULE_ENABLE_CCTIMER                 (0x1)     /* [2] */
#define SFT_SYS_STATE_MODULE_ENABLE_CCTIMER                 (2)
#define BIT_SYS_STATE_MODULE_ENABLE_CCTIMER                 (0x4)     /* [2] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   29;
  volatile unsigned long  cctimer                       :    1;       /* [2] */
  volatile unsigned long  gpio                          :    1;       /* [1] */
  volatile unsigned long  sci                           :    1;       /* [0] */
#else
  volatile unsigned short sci                           :    1;       /* [0] */
  volatile unsigned short gpio                          :    1;       /* [1] */
  volatile unsigned short cctimer                       :    1;       /* [2] */
  volatile unsigned short reserved                      :   13;
#endif
} _PACKED_ sys_state_module_enable_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_module_enable_bf bf;
} _PACKED_ sys_state_module_enable_t;


/* SYS_STATE_CONTROL */

#define MSK_SYS_STATE_CONTROL_SYS_CLK_SEL                   (0x3)     /* [ 1:0] */
#define SFT_SYS_STATE_CONTROL_SYS_CLK_SEL                   (0)
#define MSK_SYS_STATE_CONTROL_DS                            (0x1)     /* [2] */
#define SFT_SYS_STATE_CONTROL_DS                            (2)
#define BIT_SYS_STATE_CONTROL_DS                            (0x4)     /* [2] */
#define MSK_SYS_STATE_CONTROL_SEL_CLK_EXT                   (0x1)     /* [3] */
#define SFT_SYS_STATE_CONTROL_SEL_CLK_EXT                   (3)
#define BIT_SYS_STATE_CONTROL_SEL_CLK_EXT                   (0x8)     /* [3] */
#define MSK_SYS_STATE_CONTROL_IO2_SEL                       (0x3)     /* [ 5:4] */
#define SFT_SYS_STATE_CONTROL_IO2_SEL                       (4)
#define MSK_SYS_STATE_CONTROL_IO3_SEL                       (0x3)     /* [ 7:6] */
#define SFT_SYS_STATE_CONTROL_IO3_SEL                       (6)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   24;
  volatile unsigned long  io3_sel                       :    2;       /* [ 7:6] */
  volatile unsigned long  io2_sel                       :    2;       /* [ 5:4] */
  volatile unsigned long  sel_clk_ext                   :    1;       /* [3] */
  volatile unsigned long  ds                            :    1;       /* [2] */
  volatile unsigned long  sys_clk_sel                   :    2;       /* [ 1:0] */
#else
  volatile unsigned short sys_clk_sel                   :    2;       /* [ 1:0] */
  volatile unsigned short ds                            :    1;       /* [2] */
  volatile unsigned short sel_clk_ext                   :    1;       /* [3] */
  volatile unsigned short io2_sel                       :    2;       /* [ 5:4] */
  volatile unsigned short io3_sel                       :    2;       /* [ 7:6] */
  volatile unsigned short reserved                      :    8;
#endif
} _PACKED_ sys_state_control_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_control_bf bf;
} _PACKED_ sys_state_control_t;


/* SYS_STATE_RESET_STATUS */

#define MSK_SYS_STATE_RESET_STATUS_POR                      (0x1)     /* [0] */
#define SFT_SYS_STATE_RESET_STATUS_POR                      (0)
#define BIT_SYS_STATE_RESET_STATUS_POR                      (0x1)     /* [0] */
#define MSK_SYS_STATE_RESET_STATUS_VDDIO_OK                 (0x1)     /* [1] */
#define SFT_SYS_STATE_RESET_STATUS_VDDIO_OK                 (1)
#define BIT_SYS_STATE_RESET_STATUS_VDDIO_OK                 (0x2)     /* [1] */
#define MSK_SYS_STATE_RESET_STATUS_VDDC_OK                  (0x1)     /* [2] */
#define SFT_SYS_STATE_RESET_STATUS_VDDC_OK                  (2)
#define BIT_SYS_STATE_RESET_STATUS_VDDC_OK                  (0x4)     /* [2] */
#define MSK_SYS_STATE_RESET_STATUS_NRST                     (0x1)     /* [3] */
#define SFT_SYS_STATE_RESET_STATUS_NRST                     (3)
#define BIT_SYS_STATE_RESET_STATUS_NRST                     (0x8)     /* [3] */
#define MSK_SYS_STATE_RESET_STATUS_NRSTD2D                  (0x1)     /* [4] */
#define SFT_SYS_STATE_RESET_STATUS_NRSTD2D                  (4)
#define BIT_SYS_STATE_RESET_STATUS_NRSTD2D                  (0x10)    /* [4] */
#define MSK_SYS_STATE_RESET_STATUS_SYS_CLK_FAIL             (0x1)     /* [5] */
#define SFT_SYS_STATE_RESET_STATUS_SYS_CLK_FAIL             (5)
#define BIT_SYS_STATE_RESET_STATUS_SYS_CLK_FAIL             (0x20)    /* [5] */
#define MSK_SYS_STATE_RESET_STATUS_WATCHDOG                 (0x1)     /* [6] */
#define SFT_SYS_STATE_RESET_STATUS_WATCHDOG                 (6)
#define BIT_SYS_STATE_RESET_STATUS_WATCHDOG                 (0x40)    /* [6] */
#define MSK_SYS_STATE_RESET_STATUS_SOFTWARE                 (0x1)     /* [7] */
#define SFT_SYS_STATE_RESET_STATUS_SOFTWARE                 (7)
#define BIT_SYS_STATE_RESET_STATUS_SOFTWARE                 (0x80)    /* [7] */
#define MSK_SYS_STATE_RESET_STATUS_SRAM_PARITY              (0x1)     /* [8] */
#define SFT_SYS_STATE_RESET_STATUS_SRAM_PARITY              (8)
#define BIT_SYS_STATE_RESET_STATUS_SRAM_PARITY              (0x100)   /* [8] */
#define MSK_SYS_STATE_RESET_STATUS_FLASH_2BIT_ERR           (0x1)     /* [9] */
#define SFT_SYS_STATE_RESET_STATUS_FLASH_2BIT_ERR           (9)
#define BIT_SYS_STATE_RESET_STATUS_FLASH_2BIT_ERR           (0x200)   /* [9] */
#define MSK_SYS_STATE_RESET_STATUS_FLASH_1BIT_ERR           (0x1)     /* [10] */
#define SFT_SYS_STATE_RESET_STATUS_FLASH_1BIT_ERR           (10)
#define BIT_SYS_STATE_RESET_STATUS_FLASH_1BIT_ERR           (0x400)   /* [10] */
#define MSK_SYS_STATE_RESET_STATUS_FLASH_2BIT_ERR_EE        (0x1)     /* [11] */
#define SFT_SYS_STATE_RESET_STATUS_FLASH_2BIT_ERR_EE        (11)
#define BIT_SYS_STATE_RESET_STATUS_FLASH_2BIT_ERR_EE        (0x800)   /* [11] */
#define MSK_SYS_STATE_RESET_STATUS_FLASH_1BIT_ERR_EE        (0x1)     /* [12] */
#define SFT_SYS_STATE_RESET_STATUS_FLASH_1BIT_ERR_EE        (12)
#define BIT_SYS_STATE_RESET_STATUS_FLASH_1BIT_ERR_EE        (0x1000)  /* [12] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   19;
  volatile unsigned long  flash_1bit_err_ee             :    1;       /* [12] */
  volatile unsigned long  flash_2bit_err_ee             :    1;       /* [11] */
  volatile unsigned long  flash_1bit_err                :    1;       /* [10] */
  volatile unsigned long  flash_2bit_err                :    1;       /* [9] */
  volatile unsigned long  sram_parity                   :    1;       /* [8] */
  volatile unsigned long  software                      :    1;       /* [7] */
  volatile unsigned long  watchdog                      :    1;       /* [6] */
  volatile unsigned long  sys_clk_fail                  :    1;       /* [5] */
  volatile unsigned long  nrstd2d                       :    1;       /* [4] */
  volatile unsigned long  nrst                          :    1;       /* [3] */
  volatile unsigned long  vddc_ok                       :    1;       /* [2] */
  volatile unsigned long  vddio_ok                      :    1;       /* [1] */
  volatile unsigned long  por                           :    1;       /* [0] */
#else
  volatile unsigned short por                           :    1;       /* [0] */
  volatile unsigned short vddio_ok                      :    1;       /* [1] */
  volatile unsigned short vddc_ok                       :    1;       /* [2] */
  volatile unsigned short nrst                          :    1;       /* [3] */
  volatile unsigned short nrstd2d                       :    1;       /* [4] */
  volatile unsigned short sys_clk_fail                  :    1;       /* [5] */
  volatile unsigned short watchdog                      :    1;       /* [6] */
  volatile unsigned short software                      :    1;       /* [7] */
  volatile unsigned short sram_parity                   :    1;       /* [8] */
  volatile unsigned short flash_2bit_err                :    1;       /* [9] */
  volatile unsigned short flash_1bit_err                :    1;       /* [10] */
  volatile unsigned short flash_2bit_err_ee             :    1;       /* [11] */
  volatile unsigned short flash_1bit_err_ee             :    1;       /* [12] */
  volatile unsigned short reserved                      :    3;
#endif
} _PACKED_ sys_state_reset_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_reset_status_bf bf;
} _PACKED_ sys_state_reset_status_t;


/* SYS_STATE__RESET_STATUS_CLEAR */

#define MSK_SYS_STATE__RESET_STATUS_CLEAR                   (0x1)     /* [0] */

typedef unsigned short sys_state__reset_status_clear_t;               /* [0] */


/* SYS_STATE_RESET_ENABLE */

#define MSK_SYS_STATE_RESET_ENABLE_WATCHDOG                 (0x1)     /* [0] */
#define SFT_SYS_STATE_RESET_ENABLE_WATCHDOG                 (0)
#define BIT_SYS_STATE_RESET_ENABLE_WATCHDOG                 (0x1)     /* [0] */
#define MSK_SYS_STATE_RESET_ENABLE_SOFTWARE                 (0x1)     /* [1] */
#define SFT_SYS_STATE_RESET_ENABLE_SOFTWARE                 (1)
#define BIT_SYS_STATE_RESET_ENABLE_SOFTWARE                 (0x2)     /* [1] */
#define MSK_SYS_STATE_RESET_ENABLE_SRAM_PARITY              (0x1)     /* [2] */
#define SFT_SYS_STATE_RESET_ENABLE_SRAM_PARITY              (2)
#define BIT_SYS_STATE_RESET_ENABLE_SRAM_PARITY              (0x4)     /* [2] */
#define MSK_SYS_STATE_RESET_ENABLE_FLASH_2BIT_ERR           (0x1)     /* [3] */
#define SFT_SYS_STATE_RESET_ENABLE_FLASH_2BIT_ERR           (3)
#define BIT_SYS_STATE_RESET_ENABLE_FLASH_2BIT_ERR           (0x8)     /* [3] */
#define MSK_SYS_STATE_RESET_ENABLE_FLASH_1BIT_ERR           (0x1)     /* [4] */
#define SFT_SYS_STATE_RESET_ENABLE_FLASH_1BIT_ERR           (4)
#define BIT_SYS_STATE_RESET_ENABLE_FLASH_1BIT_ERR           (0x10)    /* [4] */
#define MSK_SYS_STATE_RESET_ENABLE_FLASH_2BIT_ERR_EE        (0x1)     /* [5] */
#define SFT_SYS_STATE_RESET_ENABLE_FLASH_2BIT_ERR_EE        (5)
#define BIT_SYS_STATE_RESET_ENABLE_FLASH_2BIT_ERR_EE        (0x20)    /* [5] */
#define MSK_SYS_STATE_RESET_ENABLE_FLASH_1BIT_ERR_EE        (0x1)     /* [6] */
#define SFT_SYS_STATE_RESET_ENABLE_FLASH_1BIT_ERR_EE        (6)
#define BIT_SYS_STATE_RESET_ENABLE_FLASH_1BIT_ERR_EE        (0x40)    /* [6] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   25;
  volatile unsigned long  flash_1bit_err_ee             :    1;       /* [6] */
  volatile unsigned long  flash_2bit_err_ee             :    1;       /* [5] */
  volatile unsigned long  flash_1bit_err                :    1;       /* [4] */
  volatile unsigned long  flash_2bit_err                :    1;       /* [3] */
  volatile unsigned long  sram_parity                   :    1;       /* [2] */
  volatile unsigned long  software                      :    1;       /* [1] */
  volatile unsigned long  watchdog                      :    1;       /* [0] */
#else
  volatile unsigned short watchdog                      :    1;       /* [0] */
  volatile unsigned short software                      :    1;       /* [1] */
  volatile unsigned short sram_parity                   :    1;       /* [2] */
  volatile unsigned short flash_2bit_err                :    1;       /* [3] */
  volatile unsigned short flash_1bit_err                :    1;       /* [4] */
  volatile unsigned short flash_2bit_err_ee             :    1;       /* [5] */
  volatile unsigned short flash_1bit_err_ee             :    1;       /* [6] */
  volatile unsigned short reserved                      :    9;
#endif
} _PACKED_ sys_state_reset_enable_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_reset_enable_bf bf;
} _PACKED_ sys_state_reset_enable_t;


/* SYS_STATE_SW_RESET */

#define MSK_SYS_STATE_SW_RESET_POR_FLAG                     (0x1)     /* [0] */
#define SFT_SYS_STATE_SW_RESET_POR_FLAG                     (0)
#define BIT_SYS_STATE_SW_RESET_POR_FLAG                     (0x1)     /* [0] */
#define MSK_SYS_STATE_SW_RESET_SW_RESET                     (0x1)     /* [1] */
#define SFT_SYS_STATE_SW_RESET_SW_RESET                     (1)
#define BIT_SYS_STATE_SW_RESET_SW_RESET                     (0x2)     /* [1] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   30;
  volatile unsigned long  sw_reset                      :    1;       /* [1] */
  volatile unsigned long  por_flag                      :    1;       /* [0] */
#else
  volatile unsigned short por_flag                      :    1;       /* [0] */
  volatile unsigned short sw_reset                      :    1;       /* [1] */
  volatile unsigned short reserved                      :   14;
#endif
} _PACKED_ sys_state_sw_reset_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_sw_reset_bf bf;
} _PACKED_ sys_state_sw_reset_t;


/* SYS_STATE_SIGNATURE */

#define MSK_SYS_STATE_SIGNATURE                             (0xffff)  /* [15:0] */

typedef unsigned short sys_state_signature_t;                         /* [15:0] */


/* SYS_STATE_CALIBRATION_LOCK */

#define MSK_SYS_STATE_CALIBRATION_LOCK                      (0x1)     /* [0] */

typedef unsigned short sys_state_calibration_lock_t;                  /* [0] */


/* SYS_STATE_CALIBRATION */

#define MSK_SYS_STATE_CALIBRATION_CAL_VREF                  (0x7)     /* [ 2:0] */
#define SFT_SYS_STATE_CALIBRATION_CAL_VREF                  (0)
#define MSK_SYS_STATE_CALIBRATION_CAL_BGAP                  (0xf)     /* [ 7:4] */
#define SFT_SYS_STATE_CALIBRATION_CAL_BGAP                  (4)
#define MSK_SYS_STATE_CALIBRATION_CAL_SYS_OSC               (0xff)    /* [15:8] */
#define SFT_SYS_STATE_CALIBRATION_CAL_SYS_OSC               (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  cal_sys_osc                   :    8;       /* [15:8] */
  volatile unsigned long  cal_bgap                      :    4;       /* [ 7:4] */
  volatile unsigned long  reserved3                     :    1;       /* [3] */
  volatile unsigned long  cal_vref                      :    3;       /* [ 2:0] */
#else
  volatile unsigned short cal_vref                      :    3;       /* [ 2:0] */
  volatile unsigned short reserved3                     :    1;       /* [3] */
  volatile unsigned short cal_bgap                      :    4;       /* [ 7:4] */
  volatile unsigned short cal_sys_osc                   :    8;       /* [15:8] */
#endif
} _PACKED_ sys_state_calibration_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_calibration_bf bf;
} _PACKED_ sys_state_calibration_t;


/* SYS_STATE_CUSTOMER_ID */

#define MSK_SYS_STATE_CUSTOMER_ID                           (0xff)    /* [ 7:0] */

typedef unsigned short sys_state_customer_id_t;                       /* [ 7:0] */


/* SYS_STATE_DEVICE_ID */

#define MSK_SYS_STATE_DEVICE_ID                             (0xf)     /* [ 3:0] */

typedef unsigned short sys_state_device_id_t;                         /* [ 3:0] */


/* SYS_STATE_IRQ_STATUS */

#define MSK_SYS_STATE_IRQ_STATUS_WATCHDOG                   (0x1)     /* [0] */
#define SFT_SYS_STATE_IRQ_STATUS_WATCHDOG                   (0)
#define BIT_SYS_STATE_IRQ_STATUS_WATCHDOG                   (0x1)     /* [0] */
#define MSK_SYS_STATE_IRQ_STATUS_SOFTWARE                   (0x1)     /* [1] */
#define SFT_SYS_STATE_IRQ_STATUS_SOFTWARE                   (1)
#define BIT_SYS_STATE_IRQ_STATUS_SOFTWARE                   (0x2)     /* [1] */
#define MSK_SYS_STATE_IRQ_STATUS_SRAM_PARITY                (0x1)     /* [2] */
#define SFT_SYS_STATE_IRQ_STATUS_SRAM_PARITY                (2)
#define BIT_SYS_STATE_IRQ_STATUS_SRAM_PARITY                (0x4)     /* [2] */
#define MSK_SYS_STATE_IRQ_STATUS_FLASH_2BIT_ERR             (0x1)     /* [3] */
#define SFT_SYS_STATE_IRQ_STATUS_FLASH_2BIT_ERR             (3)
#define BIT_SYS_STATE_IRQ_STATUS_FLASH_2BIT_ERR             (0x8)     /* [3] */
#define MSK_SYS_STATE_IRQ_STATUS_FLASH_1BIT_ERR             (0x1)     /* [4] */
#define SFT_SYS_STATE_IRQ_STATUS_FLASH_1BIT_ERR             (4)
#define BIT_SYS_STATE_IRQ_STATUS_FLASH_1BIT_ERR             (0x10)    /* [4] */
#define MSK_SYS_STATE_IRQ_STATUS_FLASH_2BIT_ERR_EE          (0x1)     /* [5] */
#define SFT_SYS_STATE_IRQ_STATUS_FLASH_2BIT_ERR_EE          (5)
#define BIT_SYS_STATE_IRQ_STATUS_FLASH_2BIT_ERR_EE          (0x20)    /* [5] */
#define MSK_SYS_STATE_IRQ_STATUS_FLASH_1BIT_ERR_EE          (0x1)     /* [6] */
#define SFT_SYS_STATE_IRQ_STATUS_FLASH_1BIT_ERR_EE          (6)
#define BIT_SYS_STATE_IRQ_STATUS_FLASH_1BIT_ERR_EE          (0x40)    /* [6] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   25;
  volatile unsigned long  flash_1bit_err_ee             :    1;       /* [6] */
  volatile unsigned long  flash_2bit_err_ee             :    1;       /* [5] */
  volatile unsigned long  flash_1bit_err                :    1;       /* [4] */
  volatile unsigned long  flash_2bit_err                :    1;       /* [3] */
  volatile unsigned long  sram_parity                   :    1;       /* [2] */
  volatile unsigned long  software                      :    1;       /* [1] */
  volatile unsigned long  watchdog                      :    1;       /* [0] */
#else
  volatile unsigned short watchdog                      :    1;       /* [0] */
  volatile unsigned short software                      :    1;       /* [1] */
  volatile unsigned short sram_parity                   :    1;       /* [2] */
  volatile unsigned short flash_2bit_err                :    1;       /* [3] */
  volatile unsigned short flash_1bit_err                :    1;       /* [4] */
  volatile unsigned short flash_2bit_err_ee             :    1;       /* [5] */
  volatile unsigned short flash_1bit_err_ee             :    1;       /* [6] */
  volatile unsigned short reserved                      :    9;
#endif
} _PACKED_ sys_state_irq_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile sys_state_irq_status_bf bf;
} _PACKED_ sys_state_irq_status_t;


/* SYS_STATE_IRQ_MASK */

#define MSK_SYS_STATE_IRQ_MASK                              (0x7f)    /* [ 6:0] */

typedef unsigned short sys_state_irq_mask_t;                          /* [ 6:0] */


/* SYS_STATE_IRQ_VENABLE */

#define MSK_SYS_STATE_IRQ_VENABLE                           (0x7)     /* [ 2:0] */

typedef unsigned short sys_state_irq_venable_t;                       /* [ 2:0] */


/* SYS_STATE_IRQ_VDISABLE */

#define MSK_SYS_STATE_IRQ_VDISABLE                          (0x7)     /* [ 2:0] */

typedef unsigned short sys_state_irq_vdisable_t;                      /* [ 2:0] */


/* SYS_STATE_IRQ_VMAX */

#define MSK_SYS_STATE_IRQ_VMAX                              (0x7)     /* [ 2:0] */

typedef unsigned short sys_state_irq_vmax_t;                          /* [ 2:0] */


/* SYS_STATE_IRQ_VNO */

#define MSK_SYS_STATE_IRQ_VNO                               (0x7)     /* [ 2:0] */

typedef unsigned short sys_state_irq_vno_t;                           /* [ 2:0] */



/* SYS_STATE */

typedef struct {
  volatile sys_state_module_enable_t               module_enable;                  /* 0 */
  volatile sys_state_control_t                     control;                        /* 2 */
  volatile sys_state_reset_status_t                reset_status;                   /* 4 */
  volatile sys_state__reset_status_clear_t         reset_status_clear;             /* 6 */
  volatile sys_state_reset_enable_t                reset_enable;                   /* 8 */
  volatile sys_state_sw_reset_t                    sw_reset;                      /* 10 */
  unsigned short                                   reserved0[2];
  volatile sys_state_signature_t                   signature_0;                   /* 16 */
  volatile sys_state_signature_t                   signature_1;                   /* 18 */
  volatile sys_state_signature_t                   signature_2;                   /* 20 */
  volatile sys_state_signature_t                   signature_3;                   /* 22 */
  unsigned short                                   reserved1[4];
  volatile sys_state_calibration_lock_t            calibration_lock;              /* 32 */
  volatile sys_state_calibration_t                 calibration;                   /* 34 */
  volatile sys_state_customer_id_t                 customer_id;                   /* 36 */
  volatile sys_state_device_id_t                   device_id;                     /* 38 */
  unsigned short                                   reserved2[4];
  volatile sys_state_irq_status_t                  irq_status;                    /* 48 */
  unsigned short                                   reserved3[1];
  volatile sys_state_irq_mask_t                    irq_mask;                      /* 52 */
  unsigned short                                   reserved4[1];
  volatile sys_state_irq_venable_t                 irq_venable;                   /* 56 */
  volatile sys_state_irq_vdisable_t                irq_vdisable;                  /* 58 */
  volatile sys_state_irq_vmax_t                    irq_vmax;                      /* 60 */
  volatile sys_state_irq_vno_t                     irq_vno;                       /* 62 */
} _PACKED_ sys_state_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_SYS_STATE 0x0180U ... System State Module

#define ADDR_SYS_STATE_MODULE_ENABLE                         (0x00U)
#define A_SYS_STATE_MODULE_ENABLE(ba)                        ((ba) + ADDR_SYS_STATE_MODULE_ENABLE)
#define R_SYS_STATE_MODULE_ENABLE(ba)                        (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_MODULE_ENABLE(ba)))
#define RES_SYS_STATE_MODULE_ENABLE                          (0x0U)
#define MSB_SYS_STATE_MODULE_ENABLE                          2
#define LSB_SYS_STATE_MODULE_ENABLE                          0
#define AADDR_SYS_STATE_MODULE_ENABLE                        (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_MODULE_ENABLE)
#define REG_SYS_STATE_MODULE_ENABLE                          (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_MODULE_ENABLE))

#define ADDR_SYS_STATE_CONTROL                               (0x02U)
#define A_SYS_STATE_CONTROL(ba)                              ((ba) + ADDR_SYS_STATE_CONTROL)
#define R_SYS_STATE_CONTROL(ba)                              (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_CONTROL(ba)))
#define RES_SYS_STATE_CONTROL                                (0x3U)
#define MSB_SYS_STATE_CONTROL                                7
#define LSB_SYS_STATE_CONTROL                                0
#define AADDR_SYS_STATE_CONTROL                              (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CONTROL)
#define REG_SYS_STATE_CONTROL                                (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_CONTROL))

#define ADDR_SYS_STATE_RESET_STATUS                          (0x04U)
#define A_SYS_STATE_RESET_STATUS(ba)                         ((ba) + ADDR_SYS_STATE_RESET_STATUS)
#define R_SYS_STATE_RESET_STATUS(ba)                         (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_RESET_STATUS(ba)))
#define RES_SYS_STATE_RESET_STATUS                           (0x1U)
#define MSB_SYS_STATE_RESET_STATUS                           12
#define LSB_SYS_STATE_RESET_STATUS                           0
#define AADDR_SYS_STATE_RESET_STATUS                         (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_RESET_STATUS)
#define REG_SYS_STATE_RESET_STATUS                           (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_RESET_STATUS))

#define ADDR_SYS_STATE_RESET_STATUS_CLEAR                    (0x06U)
#define A_SYS_STATE_RESET_STATUS_CLEAR(ba)                   ((ba) + ADDR_SYS_STATE_RESET_STATUS_CLEAR)
#define R_SYS_STATE_RESET_STATUS_CLEAR(ba)                   (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_RESET_STATUS_CLEAR(ba)))
#define RES_SYS_STATE_RESET_STATUS_CLEAR                     (0x0U)
#define MSB_SYS_STATE_RESET_STATUS_CLEAR                     0
#define LSB_SYS_STATE_RESET_STATUS_CLEAR                     0
#define AADDR_SYS_STATE_RESET_STATUS_CLEAR                   (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_RESET_STATUS_CLEAR)
#define REG_SYS_STATE_RESET_STATUS_CLEAR                     (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_RESET_STATUS_CLEAR))

#define ADDR_SYS_STATE_RESET_ENABLE                          (0x08U)
#define A_SYS_STATE_RESET_ENABLE(ba)                         ((ba) + ADDR_SYS_STATE_RESET_ENABLE)
#define R_SYS_STATE_RESET_ENABLE(ba)                         (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_RESET_ENABLE(ba)))
#define RES_SYS_STATE_RESET_ENABLE                           (0x0U)
#define MSB_SYS_STATE_RESET_ENABLE                           6
#define LSB_SYS_STATE_RESET_ENABLE                           0
#define AADDR_SYS_STATE_RESET_ENABLE                         (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_RESET_ENABLE)
#define REG_SYS_STATE_RESET_ENABLE                           (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_RESET_ENABLE))

#define ADDR_SYS_STATE_SW_RESET                              (0x0AU)
#define A_SYS_STATE_SW_RESET(ba)                             ((ba) + ADDR_SYS_STATE_SW_RESET)
#define R_SYS_STATE_SW_RESET(ba)                             (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_SW_RESET(ba)))
#define RES_SYS_STATE_SW_RESET                               (0x1U)
#define MSB_SYS_STATE_SW_RESET                               1
#define LSB_SYS_STATE_SW_RESET                               0
#define AADDR_SYS_STATE_SW_RESET                             (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_SW_RESET)
#define REG_SYS_STATE_SW_RESET                               (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_SW_RESET))

#define ADDR_SYS_STATE_SIGNATURE_0                           (0x10U)
#define A_SYS_STATE_SIGNATURE_0(ba)                          ((ba) + ADDR_SYS_STATE_SIGNATURE_0)
#define R_SYS_STATE_SIGNATURE_0(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_SIGNATURE_0(ba)))
#define RES_SYS_STATE_SIGNATURE_0                            (0x0U)
#define MSB_SYS_STATE_SIGNATURE_0                            15
#define LSB_SYS_STATE_SIGNATURE_0                            0
#define AADDR_SYS_STATE_SIGNATURE_0                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_SIGNATURE_0)
#define REG_SYS_STATE_SIGNATURE_0                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_SIGNATURE_0))

#define ADDR_SYS_STATE_SIGNATURE_1                           (0x12U)
#define A_SYS_STATE_SIGNATURE_1(ba)                          ((ba) + ADDR_SYS_STATE_SIGNATURE_1)
#define R_SYS_STATE_SIGNATURE_1(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_SIGNATURE_1(ba)))
#define RES_SYS_STATE_SIGNATURE_1                            (0x0U)
#define MSB_SYS_STATE_SIGNATURE_1                            15
#define LSB_SYS_STATE_SIGNATURE_1                            0
#define AADDR_SYS_STATE_SIGNATURE_1                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_SIGNATURE_1)
#define REG_SYS_STATE_SIGNATURE_1                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_SIGNATURE_1))

#define ADDR_SYS_STATE_SIGNATURE_2                           (0x14U)
#define A_SYS_STATE_SIGNATURE_2(ba)                          ((ba) + ADDR_SYS_STATE_SIGNATURE_2)
#define R_SYS_STATE_SIGNATURE_2(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_SIGNATURE_2(ba)))
#define RES_SYS_STATE_SIGNATURE_2                            (0x0U)
#define MSB_SYS_STATE_SIGNATURE_2                            15
#define LSB_SYS_STATE_SIGNATURE_2                            0
#define AADDR_SYS_STATE_SIGNATURE_2                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_SIGNATURE_2)
#define REG_SYS_STATE_SIGNATURE_2                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_SIGNATURE_2))

#define ADDR_SYS_STATE_SIGNATURE_3                           (0x16U)
#define A_SYS_STATE_SIGNATURE_3(ba)                          ((ba) + ADDR_SYS_STATE_SIGNATURE_3)
#define R_SYS_STATE_SIGNATURE_3(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_SIGNATURE_3(ba)))
#define RES_SYS_STATE_SIGNATURE_3                            (0x0U)
#define MSB_SYS_STATE_SIGNATURE_3                            15
#define LSB_SYS_STATE_SIGNATURE_3                            0
#define AADDR_SYS_STATE_SIGNATURE_3                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_SIGNATURE_3)
#define REG_SYS_STATE_SIGNATURE_3                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_SIGNATURE_3))

#define ADDR_SYS_STATE_CALIBRATION_LOCK                      (0x20U)
#define A_SYS_STATE_CALIBRATION_LOCK(ba)                     ((ba) + ADDR_SYS_STATE_CALIBRATION_LOCK)
#define R_SYS_STATE_CALIBRATION_LOCK(ba)                     (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_CALIBRATION_LOCK(ba)))
#define RES_SYS_STATE_CALIBRATION_LOCK                       (0x0U)
#define MSB_SYS_STATE_CALIBRATION_LOCK                       0
#define LSB_SYS_STATE_CALIBRATION_LOCK                       0
#define AADDR_SYS_STATE_CALIBRATION_LOCK                     (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CALIBRATION_LOCK)
#define REG_SYS_STATE_CALIBRATION_LOCK                       (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_CALIBRATION_LOCK))

#define ADDR_SYS_STATE_CALIBRATION                           (0x22U)
#define A_SYS_STATE_CALIBRATION(ba)                          ((ba) + ADDR_SYS_STATE_CALIBRATION)
#define R_SYS_STATE_CALIBRATION(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_CALIBRATION(ba)))
#define RES_SYS_STATE_CALIBRATION                            (0x84U)
#define MSB_SYS_STATE_CALIBRATION                            15
#define LSB_SYS_STATE_CALIBRATION                            0
#define AADDR_SYS_STATE_CALIBRATION                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CALIBRATION)
#define REG_SYS_STATE_CALIBRATION                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_CALIBRATION))

#define ADDR_SYS_STATE_CUSTOMER_ID                           (0x24U)
#define A_SYS_STATE_CUSTOMER_ID(ba)                          ((ba) + ADDR_SYS_STATE_CUSTOMER_ID)
#define R_SYS_STATE_CUSTOMER_ID(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_CUSTOMER_ID(ba)))
#define RES_SYS_STATE_CUSTOMER_ID                            (0xffU)
#define MSB_SYS_STATE_CUSTOMER_ID                            7
#define LSB_SYS_STATE_CUSTOMER_ID                            0
#define AADDR_SYS_STATE_CUSTOMER_ID                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_CUSTOMER_ID)
#define REG_SYS_STATE_CUSTOMER_ID                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_CUSTOMER_ID))

#define ADDR_SYS_STATE_DEVICE_ID                             (0x26U)
#define A_SYS_STATE_DEVICE_ID(ba)                            ((ba) + ADDR_SYS_STATE_DEVICE_ID)
#define R_SYS_STATE_DEVICE_ID(ba)                            (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_DEVICE_ID(ba)))
#define RES_SYS_STATE_DEVICE_ID                              (0x0U)
#define MSB_SYS_STATE_DEVICE_ID                              3
#define LSB_SYS_STATE_DEVICE_ID                              0
#define AADDR_SYS_STATE_DEVICE_ID                            (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_DEVICE_ID)
#define REG_SYS_STATE_DEVICE_ID                              (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_DEVICE_ID))

#define ADDR_SYS_STATE_IRQ_STATUS                            (0x30U)
#define A_SYS_STATE_IRQ_STATUS(ba)                           ((ba) + ADDR_SYS_STATE_IRQ_STATUS)
#define R_SYS_STATE_IRQ_STATUS(ba)                           (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_IRQ_STATUS(ba)))
#define RES_SYS_STATE_IRQ_STATUS                             (0x0U)
#define MSB_SYS_STATE_IRQ_STATUS                             6
#define LSB_SYS_STATE_IRQ_STATUS                             0
#define AADDR_SYS_STATE_IRQ_STATUS                           (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_STATUS)
#define REG_SYS_STATE_IRQ_STATUS                             (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_IRQ_STATUS))

#define ADDR_SYS_STATE_IRQ_MASK                              (0x34U)
#define A_SYS_STATE_IRQ_MASK(ba)                             ((ba) + ADDR_SYS_STATE_IRQ_MASK)
#define R_SYS_STATE_IRQ_MASK(ba)                             (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_IRQ_MASK(ba)))
#define RES_SYS_STATE_IRQ_MASK                               (0x0U)
#define MSB_SYS_STATE_IRQ_MASK                               6
#define LSB_SYS_STATE_IRQ_MASK                               0
#define AADDR_SYS_STATE_IRQ_MASK                             (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_MASK)
#define REG_SYS_STATE_IRQ_MASK                               (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_IRQ_MASK))

#define ADDR_SYS_STATE_IRQ_VENABLE                           (0x38U)
#define A_SYS_STATE_IRQ_VENABLE(ba)                          ((ba) + ADDR_SYS_STATE_IRQ_VENABLE)
#define R_SYS_STATE_IRQ_VENABLE(ba)                          (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_IRQ_VENABLE(ba)))
#define RES_SYS_STATE_IRQ_VENABLE                            (0x0U)
#define MSB_SYS_STATE_IRQ_VENABLE                            2
#define LSB_SYS_STATE_IRQ_VENABLE                            0
#define AADDR_SYS_STATE_IRQ_VENABLE                          (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_VENABLE)
#define REG_SYS_STATE_IRQ_VENABLE                            (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_IRQ_VENABLE))

#define ADDR_SYS_STATE_IRQ_VDISABLE                          (0x3AU)
#define A_SYS_STATE_IRQ_VDISABLE(ba)                         ((ba) + ADDR_SYS_STATE_IRQ_VDISABLE)
#define R_SYS_STATE_IRQ_VDISABLE(ba)                         (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_IRQ_VDISABLE(ba)))
#define RES_SYS_STATE_IRQ_VDISABLE                           (0x0U)
#define MSB_SYS_STATE_IRQ_VDISABLE                           2
#define LSB_SYS_STATE_IRQ_VDISABLE                           0
#define AADDR_SYS_STATE_IRQ_VDISABLE                         (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_VDISABLE)
#define REG_SYS_STATE_IRQ_VDISABLE                           (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_IRQ_VDISABLE))

#define ADDR_SYS_STATE_IRQ_VMAX                              (0x3CU)
#define A_SYS_STATE_IRQ_VMAX(ba)                             ((ba) + ADDR_SYS_STATE_IRQ_VMAX)
#define R_SYS_STATE_IRQ_VMAX(ba)                             (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_IRQ_VMAX(ba)))
#define RES_SYS_STATE_IRQ_VMAX                               (0x7U)
#define MSB_SYS_STATE_IRQ_VMAX                               2
#define LSB_SYS_STATE_IRQ_VMAX                               0
#define AADDR_SYS_STATE_IRQ_VMAX                             (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_VMAX)
#define REG_SYS_STATE_IRQ_VMAX                               (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_IRQ_VMAX))

#define ADDR_SYS_STATE_IRQ_VNO                               (0x3EU)
#define A_SYS_STATE_IRQ_VNO(ba)                              ((ba) + ADDR_SYS_STATE_IRQ_VNO)
#define R_SYS_STATE_IRQ_VNO(ba)                              (*(volatile unsigned short *)((unsigned int)A_SYS_STATE_IRQ_VNO(ba)))
#define RES_SYS_STATE_IRQ_VNO                                (0x7U)
#define MSB_SYS_STATE_IRQ_VNO                                2
#define LSB_SYS_STATE_IRQ_VNO                                0
#define AADDR_SYS_STATE_IRQ_VNO                              (BASE_ADDR_SYS_STATE + ADDR_SYS_STATE_IRQ_VNO)
#define REG_SYS_STATE_IRQ_VNO                                (*(volatile unsigned short *)((unsigned int)AADDR_SYS_STATE_IRQ_VNO))




#endif
