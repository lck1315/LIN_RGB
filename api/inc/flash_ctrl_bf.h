#ifndef __FLASH_CTRL_BF_H__
#define __FLASH_CTRL_BF_H__

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

#ifndef BASE_ADDR_FLASH_CTRL
#define BASE_ADDR_FLASH_CTRL 0x0600U
#endif
#ifndef BASE_ADDR_FLASH_EE_CTRL
#define BASE_ADDR_FLASH_EE_CTRL 0x0640U
#endif

#define MULTIPLE_FLASH_CTRL
#define NUMBER_FLASH_CTRL 2

typedef enum {
  FLASH_CTRL                     = (int)BASE_ADDR_FLASH_CTRL,
  FLASH_EE_CTRL                  = (int)BASE_ADDR_FLASH_EE_CTRL
} flash_ctrl_num_t;

// Register bit field definitions

/* FLASH_CTRL_AREA_MAIN_L */

#define MSK_FLASH_CTRL_AREA_MAIN_L_AREA                     (0xff)    /* [ 7:0] */
#define SFT_FLASH_CTRL_AREA_MAIN_L_AREA                     (0)
#define MSK_FLASH_CTRL_AREA_MAIN_L_PASS                     (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_AREA_MAIN_L_PASS                     (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  area                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short area                          :    8;       /* [ 7:0] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_area_main_l_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_area_main_l_bf bf;
} _PACKED_ flash_ctrl_area_main_l_t;


/* FLASH_CTRL_AREA_MAIN_H */

#define MSK_FLASH_CTRL_AREA_MAIN_H_AREA                     (0xff)    /* [ 7:0] */
#define SFT_FLASH_CTRL_AREA_MAIN_H_AREA                     (0)
#define MSK_FLASH_CTRL_AREA_MAIN_H_PASS                     (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_AREA_MAIN_H_PASS                     (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  area                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short area                          :    8;       /* [ 7:0] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_area_main_h_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_area_main_h_bf bf;
} _PACKED_ flash_ctrl_area_main_h_t;


/* FLASH_CTRL_MODE */

#define MSK_FLASH_CTRL_MODE_MODE                            (0xff)    /* [ 7:0] */
#define SFT_FLASH_CTRL_MODE_MODE                            (0)
#define MSK_FLASH_CTRL_MODE_PASS                            (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_MODE_PASS                            (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  mode                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short mode                          :    8;       /* [ 7:0] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_mode_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_mode_bf bf;
} _PACKED_ flash_ctrl_mode_t;


/* FLASH_CTRL_STATUS */

#define MSK_FLASH_CTRL_STATUS_BUSY                          (0x1)     /* [0] */
#define SFT_FLASH_CTRL_STATUS_BUSY                          (0)
#define BIT_FLASH_CTRL_STATUS_BUSY                          (0x1)     /* [0] */
#define MSK_FLASH_CTRL_STATUS_INCOMPLETE                    (0x1)     /* [1] */
#define SFT_FLASH_CTRL_STATUS_INCOMPLETE                    (1)
#define BIT_FLASH_CTRL_STATUS_INCOMPLETE                    (0x2)     /* [1] */
#define MSK_FLASH_CTRL_STATUS_WRITE_ERROR                   (0x1)     /* [2] */
#define SFT_FLASH_CTRL_STATUS_WRITE_ERROR                   (2)
#define BIT_FLASH_CTRL_STATUS_WRITE_ERROR                   (0x4)     /* [2] */
#define MSK_FLASH_CTRL_STATUS_RECALL_BUSY                   (0x1)     /* [3] */
#define SFT_FLASH_CTRL_STATUS_RECALL_BUSY                   (3)
#define BIT_FLASH_CTRL_STATUS_RECALL_BUSY                   (0x8)     /* [3] */

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   28;
  volatile unsigned long  recall_busy                   :    1;       /* [3] */
  volatile unsigned long  write_error                   :    1;       /* [2] */
  volatile unsigned long  incomplete                    :    1;       /* [1] */
  volatile unsigned long  busy                          :    1;       /* [0] */
#else
  volatile unsigned short busy                          :    1;       /* [0] */
  volatile unsigned short incomplete                    :    1;       /* [1] */
  volatile unsigned short write_error                   :    1;       /* [2] */
  volatile unsigned short recall_busy                   :    1;       /* [3] */
  volatile unsigned short reserved                      :   12;
#endif
} _PACKED_ flash_ctrl_status_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_status_bf bf;
} _PACKED_ flash_ctrl_status_t;


/* FLASH_CTRL_BIT_ERROR_ADDR */

#define MSK_FLASH_CTRL_BIT_ERROR_ADDR                       (0xffff)  /* [15:0] */

typedef unsigned short flash_ctrl_bit_error_addr_t;                   /* [15:0] */


/* FLASH_CTRL_WORD_CONFIG */

#define MSK_FLASH_CTRL_WORD_CONFIG_CONFIG                   (0x3f)    /* [ 5:0] */
#define SFT_FLASH_CTRL_WORD_CONFIG_CONFIG                   (0)
#define MSK_FLASH_CTRL_WORD_CONFIG_PASS                     (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_WORD_CONFIG_PASS                     (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  reserved7                     :    2;       /* [ 7:6] */
  volatile unsigned long  config                        :    6;       /* [ 5:0] */
#else
  volatile unsigned short config                        :    6;       /* [ 5:0] */
  volatile unsigned short reserved7                     :    2;       /* [ 7:6] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_word_config_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_word_config_bf bf;
} _PACKED_ flash_ctrl_word_config_t;


/* FLASH_CTRL_FREQ_CONFIG */

#define MSK_FLASH_CTRL_FREQ_CONFIG_CONFIG                   (0x3)     /* [ 1:0] */
#define SFT_FLASH_CTRL_FREQ_CONFIG_CONFIG                   (0)
#define MSK_FLASH_CTRL_FREQ_CONFIG_PASS                     (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_FREQ_CONFIG_PASS                     (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  reserved7                     :    6;       /* [ 7:2] */
  volatile unsigned long  config                        :    2;       /* [ 1:0] */
#else
  volatile unsigned short config                        :    2;       /* [ 1:0] */
  volatile unsigned short reserved7                     :    6;       /* [ 7:2] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_freq_config_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_freq_config_bf bf;
} _PACKED_ flash_ctrl_freq_config_t;


/* FLASH_CTRL_AREA_MAIN_L_LOCK */

#define MSK_FLASH_CTRL_AREA_MAIN_L_LOCK_AREA                (0xff)    /* [ 7:0] */
#define SFT_FLASH_CTRL_AREA_MAIN_L_LOCK_AREA                (0)
#define MSK_FLASH_CTRL_AREA_MAIN_L_LOCK_PASS                (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_AREA_MAIN_L_LOCK_PASS                (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  area                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short area                          :    8;       /* [ 7:0] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_area_main_l_lock_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_area_main_l_lock_bf bf;
} _PACKED_ flash_ctrl_area_main_l_lock_t;


/* FLASH_CTRL_AREA_MAIN_H_LOCK */

#define MSK_FLASH_CTRL_AREA_MAIN_H_LOCK_AREA                (0xff)    /* [ 7:0] */
#define SFT_FLASH_CTRL_AREA_MAIN_H_LOCK_AREA                (0)
#define MSK_FLASH_CTRL_AREA_MAIN_H_LOCK_PASS                (0xff)    /* [15:8] */
#define SFT_FLASH_CTRL_AREA_MAIN_H_LOCK_PASS                (8)

typedef struct {
#ifdef SPARC
  volatile unsigned long  reserved                      :   16;
  volatile unsigned long  pass                          :    8;       /* [15:8] */
  volatile unsigned long  area                          :    8;       /* [ 7:0] */
#else
  volatile unsigned short area                          :    8;       /* [ 7:0] */
  volatile unsigned short pass                          :    8;       /* [15:8] */
#endif
} _PACKED_ flash_ctrl_area_main_h_lock_bf;

typedef union {
#ifdef SPARC
  volatile unsigned long  val;
#else
  volatile unsigned short val;
#endif
  volatile flash_ctrl_area_main_h_lock_bf bf;
} _PACKED_ flash_ctrl_area_main_h_lock_t;



/* FLASH_CTRL */

typedef struct {
  volatile flash_ctrl_area_main_l_t                area_main_l;                    /* 0 */
  volatile flash_ctrl_area_main_h_t                area_main_h;                    /* 2 */
  volatile flash_ctrl_mode_t                       mode;                           /* 4 */
  volatile flash_ctrl_status_t                     status;                         /* 6 */
  unsigned short                                   reserved0[2];
  volatile flash_ctrl_bit_error_addr_t             bit_error_addr;                /* 12 */
  volatile flash_ctrl_word_config_t                word_config;                   /* 14 */
  volatile flash_ctrl_freq_config_t                freq_config;                   /* 16 */
  unsigned short                                   reserved1[7];
  volatile flash_ctrl_area_main_l_lock_t           area_main_l_lock;              /* 32 */
  volatile flash_ctrl_area_main_h_lock_t           area_main_h_lock;              /* 34 */
} _PACKED_ flash_ctrl_t;

#ifdef __IARC__
#pragma pack()
#endif

// Register definitions for module
// Instance base address BASE_ADDR_FLASH_CTRL 0x0600U ... FLASH Control Module
// Instance base address BASE_ADDR_FLASH_EE_CTRL 0x0640U ... FLASH EE Control Module

#define ADDR_FLASH_CTRL_AREA_MAIN_L                          (0x00U)
#define A_FLASH_CTRL_AREA_MAIN_L(ba)                         ((ba) + ADDR_FLASH_CTRL_AREA_MAIN_L)
#define R_FLASH_CTRL_AREA_MAIN_L(ba)                         (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_AREA_MAIN_L(ba)))
#define RES_FLASH_CTRL_AREA_MAIN_L                           (0x9600U)
#define MSB_FLASH_CTRL_AREA_MAIN_L                           15
#define LSB_FLASH_CTRL_AREA_MAIN_L                           0
#define AADDR_FLASH_CTRL_AREA_MAIN_L                         (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_L)
#define AADDR_FLASH_EE_CTRL_AREA_MAIN_L                      (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_L)
#define REG_FLASH_CTRL_AREA_MAIN_L                           (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_AREA_MAIN_L))
#define REG_FLASH_EE_CTRL_AREA_MAIN_L                        (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_AREA_MAIN_L))

#define ADDR_FLASH_CTRL_AREA_MAIN_H                          (0x02U)
#define A_FLASH_CTRL_AREA_MAIN_H(ba)                         ((ba) + ADDR_FLASH_CTRL_AREA_MAIN_H)
#define R_FLASH_CTRL_AREA_MAIN_H(ba)                         (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_AREA_MAIN_H(ba)))
#define RES_FLASH_CTRL_AREA_MAIN_H                           (0x9600U)
#define MSB_FLASH_CTRL_AREA_MAIN_H                           15
#define LSB_FLASH_CTRL_AREA_MAIN_H                           0
#define AADDR_FLASH_CTRL_AREA_MAIN_H                         (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_H)
#define AADDR_FLASH_EE_CTRL_AREA_MAIN_H                      (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_H)
#define REG_FLASH_CTRL_AREA_MAIN_H                           (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_AREA_MAIN_H))
#define REG_FLASH_EE_CTRL_AREA_MAIN_H                        (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_AREA_MAIN_H))

#define ADDR_FLASH_CTRL_MODE                                 (0x04U)
#define A_FLASH_CTRL_MODE(ba)                                ((ba) + ADDR_FLASH_CTRL_MODE)
#define R_FLASH_CTRL_MODE(ba)                                (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_MODE(ba)))
#define RES_FLASH_CTRL_MODE                                  (0x9601U)
#define MSB_FLASH_CTRL_MODE                                  15
#define LSB_FLASH_CTRL_MODE                                  0
#define AADDR_FLASH_CTRL_MODE                                (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_MODE)
#define AADDR_FLASH_EE_CTRL_MODE                             (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_MODE)
#define REG_FLASH_CTRL_MODE                                  (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_MODE))
#define REG_FLASH_EE_CTRL_MODE                               (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_MODE))

#define ADDR_FLASH_CTRL_STATUS                               (0x06U)
#define A_FLASH_CTRL_STATUS(ba)                              ((ba) + ADDR_FLASH_CTRL_STATUS)
#define R_FLASH_CTRL_STATUS(ba)                              (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_STATUS(ba)))
#define RES_FLASH_CTRL_STATUS                                (0x0U)
#define MSB_FLASH_CTRL_STATUS                                3
#define LSB_FLASH_CTRL_STATUS                                0
#define AADDR_FLASH_CTRL_STATUS                              (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_STATUS)
#define AADDR_FLASH_EE_CTRL_STATUS                           (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_STATUS)
#define REG_FLASH_CTRL_STATUS                                (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_STATUS))
#define REG_FLASH_EE_CTRL_STATUS                             (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_STATUS))

#define ADDR_FLASH_CTRL_BIT_ERROR_ADDR                       (0x0CU)
#define A_FLASH_CTRL_BIT_ERROR_ADDR(ba)                      ((ba) + ADDR_FLASH_CTRL_BIT_ERROR_ADDR)
#define R_FLASH_CTRL_BIT_ERROR_ADDR(ba)                      (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_BIT_ERROR_ADDR(ba)))
#define RES_FLASH_CTRL_BIT_ERROR_ADDR                        (0x0U)
#define MSB_FLASH_CTRL_BIT_ERROR_ADDR                        15
#define LSB_FLASH_CTRL_BIT_ERROR_ADDR                        0
#define AADDR_FLASH_CTRL_BIT_ERROR_ADDR                      (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_BIT_ERROR_ADDR)
#define AADDR_FLASH_EE_CTRL_BIT_ERROR_ADDR                   (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_BIT_ERROR_ADDR)
#define REG_FLASH_CTRL_BIT_ERROR_ADDR                        (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_BIT_ERROR_ADDR))
#define REG_FLASH_EE_CTRL_BIT_ERROR_ADDR                     (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_BIT_ERROR_ADDR))

#define ADDR_FLASH_CTRL_WORD_CONFIG                          (0x0EU)
#define A_FLASH_CTRL_WORD_CONFIG(ba)                         ((ba) + ADDR_FLASH_CTRL_WORD_CONFIG)
#define R_FLASH_CTRL_WORD_CONFIG(ba)                         (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_WORD_CONFIG(ba)))
#define RES_FLASH_CTRL_WORD_CONFIG                           (0x963fU)
#define MSB_FLASH_CTRL_WORD_CONFIG                           15
#define LSB_FLASH_CTRL_WORD_CONFIG                           0
#define AADDR_FLASH_CTRL_WORD_CONFIG                         (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_WORD_CONFIG)
#define AADDR_FLASH_EE_CTRL_WORD_CONFIG                      (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_WORD_CONFIG)
#define REG_FLASH_CTRL_WORD_CONFIG                           (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_WORD_CONFIG))
#define REG_FLASH_EE_CTRL_WORD_CONFIG                        (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_WORD_CONFIG))

#define ADDR_FLASH_CTRL_FREQ_CONFIG                          (0x10U)
#define A_FLASH_CTRL_FREQ_CONFIG(ba)                         ((ba) + ADDR_FLASH_CTRL_FREQ_CONFIG)
#define R_FLASH_CTRL_FREQ_CONFIG(ba)                         (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_FREQ_CONFIG(ba)))
#define RES_FLASH_CTRL_FREQ_CONFIG                           (0x9603U)
#define MSB_FLASH_CTRL_FREQ_CONFIG                           15
#define LSB_FLASH_CTRL_FREQ_CONFIG                           0
#define AADDR_FLASH_CTRL_FREQ_CONFIG                         (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_FREQ_CONFIG)
#define AADDR_FLASH_EE_CTRL_FREQ_CONFIG                      (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_FREQ_CONFIG)
#define REG_FLASH_CTRL_FREQ_CONFIG                           (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_FREQ_CONFIG))
#define REG_FLASH_EE_CTRL_FREQ_CONFIG                        (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_FREQ_CONFIG))

#define ADDR_FLASH_CTRL_AREA_MAIN_L_LOCK                     (0x20U)
#define A_FLASH_CTRL_AREA_MAIN_L_LOCK(ba)                    ((ba) + ADDR_FLASH_CTRL_AREA_MAIN_L_LOCK)
#define R_FLASH_CTRL_AREA_MAIN_L_LOCK(ba)                    (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_AREA_MAIN_L_LOCK(ba)))
#define RES_FLASH_CTRL_AREA_MAIN_L_LOCK                      (0x9600U)
#define MSB_FLASH_CTRL_AREA_MAIN_L_LOCK                      15
#define LSB_FLASH_CTRL_AREA_MAIN_L_LOCK                      0
#define AADDR_FLASH_CTRL_AREA_MAIN_L_LOCK                    (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_L_LOCK)
#define AADDR_FLASH_EE_CTRL_AREA_MAIN_L_LOCK                 (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_L_LOCK)
#define REG_FLASH_CTRL_AREA_MAIN_L_LOCK                      (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_AREA_MAIN_L_LOCK))
#define REG_FLASH_EE_CTRL_AREA_MAIN_L_LOCK                   (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_AREA_MAIN_L_LOCK))

#define ADDR_FLASH_CTRL_AREA_MAIN_H_LOCK                     (0x22U)
#define A_FLASH_CTRL_AREA_MAIN_H_LOCK(ba)                    ((ba) + ADDR_FLASH_CTRL_AREA_MAIN_H_LOCK)
#define R_FLASH_CTRL_AREA_MAIN_H_LOCK(ba)                    (*(volatile unsigned short *)((unsigned int)A_FLASH_CTRL_AREA_MAIN_H_LOCK(ba)))
#define RES_FLASH_CTRL_AREA_MAIN_H_LOCK                      (0x9600U)
#define MSB_FLASH_CTRL_AREA_MAIN_H_LOCK                      15
#define LSB_FLASH_CTRL_AREA_MAIN_H_LOCK                      0
#define AADDR_FLASH_CTRL_AREA_MAIN_H_LOCK                    (BASE_ADDR_FLASH_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_H_LOCK)
#define AADDR_FLASH_EE_CTRL_AREA_MAIN_H_LOCK                 (BASE_ADDR_FLASH_EE_CTRL + ADDR_FLASH_CTRL_AREA_MAIN_H_LOCK)
#define REG_FLASH_CTRL_AREA_MAIN_H_LOCK                      (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_CTRL_AREA_MAIN_H_LOCK))
#define REG_FLASH_EE_CTRL_AREA_MAIN_H_LOCK                   (*(volatile unsigned short *)((unsigned int)AADDR_FLASH_EE_CTRL_AREA_MAIN_H_LOCK))




#endif
