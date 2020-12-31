#ifndef HAVE_FLASH_CTRL_H
#define HAVE_FLASH_CTRL_H

#include "base.h"
#include "core_base.h"

#include "flash_ctrl_bf.h"

#include "vic.h"

typedef enum {
  FLASH_MB_NO       = 0x0000,
  FLASH_MB_ALL      = 0xFFFF,
  FLASH_MB_AREA_00  = 0x0001,  /* offset : 0x0000 - 0x07FF */
  FLASH_MB_AREA_01  = 0x0002,  /* offset : 0x0800 - 0x0FFF */
  FLASH_MB_AREA_02  = 0x0004,  /* offset : 0x1000 - 0x17FF */
  FLASH_MB_AREA_03  = 0x0008,  /* offset : 0x1800 - 0x1FFF */
  FLASH_MB_AREA_04  = 0x0010,  /* offset : 0x2000 - 0x27FF */
  FLASH_MB_AREA_05  = 0x0020,  /* offset : 0x2800 - 0x2FFF */
  FLASH_MB_AREA_06  = 0x0040,  /* offset : 0x3000 - 0x37FF */
  FLASH_MB_AREA_07  = 0x0080,  /* offset : 0x3800 - 0x3FFF */
  FLASH_MB_AREA_08  = 0x0100,  /* offset : 0x4000 - 0x47FF */
  FLASH_MB_AREA_09  = 0x0200,  /* offset : 0x4800 - 0x4FFF */
  FLASH_MB_AREA_10  = 0x0400,  /* offset : 0x5000 - 0x57FF */
  FLASH_MB_AREA_11  = 0x0800,  /* offset : 0x5800 - 0x5FFF */
  FLASH_MB_AREA_12  = 0x1000,  /* offset : 0x6000 - 0x67FF */
  FLASH_MB_AREA_13  = 0x2000,  /* offset : 0x6800 - 0x6FFF */
  FLASH_MB_AREA_14  = 0x4000,  /* offset : 0x7000 - 0x77FF */
  FLASH_MB_AREA_15  = 0x8000   /* offset : 0x7800 - 0x7FFF */
} flash_areas;

typedef enum {
  FLASH_FREQ_24MHZ    = 0x0,
  FLASH_FREQ_12MHZ    = 0x1,
  FLASH_FREQ_08MHZ    = 0x2,
  FLASH_FREQ_04MHZ    = 0x3
} flash_freq_config;

typedef enum {
  FLASH_BUSY          = 0x0,
  FLASH_INCOMPLETE    = 0x1,
  FLASH_WRITE_ERROR   = 0x2
} flash_status_t;


#define FLASH_NUM_PAGES  64
#define FLASH_ROW_SIZE   0x0080
#define FLASH_PAGE_SIZE  0x0200

#define isInsideRAM(addr)      (NON_ZERO_TO_ONE(((addr) >= (uintptr_t)BASE_ADDR_DMEM) && ((addr) <= (uintptr_t)(BASE_ADDR_DMEM+INST_SIZE_DMEM-1))))
#define isInsideFLASH(addr)    (NON_ZERO_TO_ONE(((addr) >= (uintptr_t)BASE_ADDR_IMEM) && ((addr) <= (uintptr_t)(BASE_ADDR_IMEM+INST_SIZE_IMEM-1))))
#define isInsideFLASH_EE(addr) (NON_ZERO_TO_ONE(((addr) >= (uintptr_t)BASE_ADDR_SYS_ROM) && ((addr) < (uintptr_t)(BASE_ADDR_IMEM))))

/* ======================================================================= */
/* MODULE HANDLING                                                         */
/* ======================================================================= */

void     flash_erase_mass(flash_ctrl_num_t flash_ctrl_no);
int16_t  flash_erase_pages(flash_ctrl_num_t flash_ctrl_no, uintptr_t *dptr, uint16_t pages);
int16_t  flash_program_rows(flash_ctrl_num_t flash_ctrl_no, uintptr_t *sptr, uintptr_t *dptr, uint16_t words);

int16_t  flash_from_ram(flash_ctrl_num_t flash_ctrl_no, uintptr_t *sptr, uintptr_t *dptr, uint16_t words);

uint16_t flash_get_page_base_addr(flash_ctrl_num_t flash_ctrl_no, uint16_t page);
uint16_t flash_get_row_base_addr(flash_ctrl_num_t flash_ctrl_no, uint16_t page, uint16_t row_in_page);

uint16_t flash_protect_area(flash_ctrl_num_t flash_ctrl_no, flash_areas areas);
uint16_t flash_unprotect_area(flash_ctrl_num_t flash_ctrl_no, flash_areas areas);

uint16_t flash_status(flash_ctrl_num_t flash_ctrl_no);
uint16_t flash_ecc_failure_addr(flash_ctrl_num_t flash_ctrl_no);
uint16_t get_flash_mode(flash_ctrl_num_t flash_ctrl_no);

void     flash_set_freq_config(flash_ctrl_num_t flash_ctrl_no, flash_freq_config freq);
void     flash_set_area_lock(flash_ctrl_num_t flash_ctrl_no, flash_areas areas);

uint16_t flash_get_area_lock(flash_ctrl_num_t flash_ctrl_no);

#endif /* HAVE_FLASH_CTRL_H */

