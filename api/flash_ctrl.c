#include "flash_ctrl.h"
#include "utils.h"

void flash_erase_mass(flash_ctrl_num_t flash_ctrl_no) {

  typedef uintptr_t (*fn_ptr)(void);

   static volatile uint16_t code[] = {
     0x40b2,  // MOV  #0xA540, &0x0604   ; switch to MB mass erase
     0xa540,
     FLASH_CTRL+ADDR_FLASH_CTRL_MODE,
     0x43b2,  // MOV  #0xFFFF, &addr     ; start mass erase
     0xFFFE,
              // erase_busy:
     0xb392,  // BIT  #0x0001, &0x0606   ; check busy bit
     FLASH_CTRL+ADDR_FLASH_CTRL_STATUS,
     0x23fd,  // JNZ  erase_busy         ; loop while busy
     0x40b2,  // MOV  #0xA501, &0x0604   ; swtich to MB read
     0xa501,
     FLASH_CTRL+ADDR_FLASH_CTRL_MODE,
     0x3FFF   // JMP $+0                 ; stay in endless loop
  };


  /* allow FLASH MB erase (FLASH control module) */
  flash_unprotect_area(flash_ctrl_no, FLASH_MB_ALL);

  /* correct address in funclet */
  switch(flash_ctrl_no){
    case  FLASH_CTRL:
      break;

    case  FLASH_EE_CTRL:
      code[0x04 / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_MODE;
      code[0x0c / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_STATUS;
      code[0x14 / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_MODE;
      break;
  }
   /* call code in RAM ... mass erase WILL NOT RETURN !!! */
   ((fn_ptr)code)();

}

int16_t flash_erase_pages(flash_ctrl_num_t flash_ctrl_no, uintptr_t *dptr, uint16_t pages) {

  typedef uintptr_t (*fn_ptr)(void);

  static volatile uint16_t code[] = {
    0x40b2,  // MOV  #0xA510, &0x0604   ; switch to MB page erase
    0xa510,
    FLASH_CTRL+ADDR_FLASH_CTRL_MODE,
    0x43b2,  // MOV  #0xFFFF, &addr     ; start page erase
    0x0000,  //                         ; code + 0x08
             // erase_busy:
    0xb392,  // BIT  #0x0001, &0x0606   ; check busy bit
    FLASH_CTRL+ADDR_FLASH_CTRL_STATUS,
    0x23fd,  // JNZ  erase_busy         ; loop while busy
    0x40b2,  // MOV  #0xA501, &0x0604   ; swtich to MB read
    0xa501,
    FLASH_CTRL+ADDR_FLASH_CTRL_MODE,
    0x4130   // RET                     ; return to C program
  };

  uint16_t  prot_config;
  uint16_t  p;

  /* check destination pointer
     - check if valid
     - check word alignment
     - check if value fits FLASH area
     - check page alignment
  */
  switch(flash_ctrl_no){
    case  FLASH_CTRL:
      if ((dptr == NULL) ||
        ((uintptr_t)dptr & 0x1) ||
        !isInsideFLASH((uintptr_t)dptr) ||
        ((uintptr_t)dptr & (FLASH_PAGE_SIZE - 1))
      ) {
        return -1;
      }
      break;

    case  FLASH_EE_CTRL:
      if ((dptr == NULL) ||
        ((uintptr_t)dptr & 0x1) ||
        !isInsideFLASH_EE((uintptr_t)dptr) ||
        ((uintptr_t)dptr & (FLASH_PAGE_SIZE - 1))
     ) {
       return -1;
     }
     break;
  }

  /* check pages
     - check number of pages
  */
  if (pages == 0) {
    return -1;
  }

  /* allow FLASH MB erase (FLASH control module) */
  prot_config = flash_unprotect_area(flash_ctrl_no, (flash_areas)0xFFFF);

  /* correct address in funclet */
  switch(flash_ctrl_no){
    case  FLASH_CTRL:
      break;

    case  FLASH_EE_CTRL:
      code[0x04 / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_MODE;
      code[0x0c / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_STATUS;
      code[0x14 / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_MODE;
      break;
  }

  for (p = 0; p < pages; p++) {

    /* fix page start address */
    code[0x08 / 2] = (uintptr_t)dptr;
    /* call code in RAM ... erase one page */
    ((fn_ptr)code)();

    /* increment dest pointer one page */
    dptr = dptr + FLASH_PAGE_SIZE / 2;  // dptr is word pointer
  }

  /* restore FLASH protection config (FLASH control module) */
  flash_protect_area(flash_ctrl_no, (flash_areas)prot_config);

  return (int16_t)pages;
}

int16_t flash_program_rows(flash_ctrl_num_t flash_ctrl_no, uintptr_t *sptr, uintptr_t *dptr, uint16_t words) {

  typedef uintptr_t (*fn_ptr)(void);
  uintptr_t *data;

  static volatile uint16_t code[] = {
    0x1204,  // PUSH R4
    0x1205,  // PUSH R5
    0x1206,  // PUSH R6
    0x40b2,  // MOV  #0xA504, &0x0604   ; switch to MB prog
    0xa504,
    FLASH_CTRL+ADDR_FLASH_CTRL_MODE,
    0x4034,  // MOV  #0x40, R4          ; data length
    0x0040,

    0x4035,  // MOV  #data, R5          ; source pointer
    0x0000,  //                         ; code + 0x12
    0x4036,  // MOV  #dptr, R6          ; destination pointer
    0x0000,  //                         ; code + 0x16
             // write_loop:
    0x9304,  // CMP  #0, R4             ; check word counter
    0x2408,  // JEQ  write_end
    0x8314,  // DEC  R4                 ; decrement word counter
    0x45b6,  // MOV  @R5+, 0(R6)        ; write data word to flash
    0x0000,
    0x5326,  // INCD R6                 ; advance destination pointer
             // write_busy:
    0xb392,  // BIT  #0x0001, &0x0606   ; check busy bit
    FLASH_CTRL+ADDR_FLASH_CTRL_STATUS,
    0x23fd,  // JNZ  write_busy         ; loop while busy
    0x3ff6,  // JMP  write_loop
             // write_end:
    0x40b2,  // MOV  #0xA501, &0x0604   ; swtich to MB read
    0xa501,
    FLASH_CTRL+ADDR_FLASH_CTRL_MODE,
    0x4136,  // POP  R6
    0x4135,  // POP  R5
    0x4134,  // POP  R4
    0x4130,  // RET                     ; return to C program
             // data:                   ; code + 0x3A
    0xffff, 0xffff, 0xffff, 0xffff,  // ; space for 64 words to program
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,

    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,

    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,

    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff,
    0xffff, 0xffff, 0xffff, 0xffff
  };

  uint16_t  prot_config;
  uint16_t  w, n, r;

  /* check source pointer
     - check if valid
     - check word alignment
     - check if value fits RAM area
  */
  if ((sptr == NULL) ||
    ((uintptr_t)sptr & 0x1) ||
    !isInsideRAM((uintptr_t)sptr) ||
    !isInsideRAM((uintptr_t)sptr + words*2 - 1)
  ) {
    return -1;
  }
  /* check destination pointer
     - check if valid
     - check word alignment
     - check if value fits FLASH area
  */
  switch(flash_ctrl_no){
    case  FLASH_CTRL:
      if ((dptr == NULL) ||
        ((uintptr_t)dptr & 0x1) ||
        !isInsideFLASH((uintptr_t)dptr) ||
        !isInsideFLASH((uintptr_t)dptr + words*2 - 1)
      ) {
        return -1;
      }
      break;

    case  FLASH_EE_CTRL:
      if ((dptr == NULL) ||
        ((uintptr_t)dptr & 0x1) ||
        !isInsideFLASH_EE((uintptr_t)dptr) ||
        !isInsideFLASH_EE((uintptr_t)dptr + words*2 - 1)
      ) {
        return -1;
      }
      break;
  }

  /* check words
     - check number of words
  */
  if (words == 0) {
    return -1;
  }

  /* allow FLASH MB program (FLASH control module) */
  prot_config = flash_unprotect_area(flash_ctrl_no, (flash_areas)0xFFFF);

  /* correct address in funclet */
  switch(flash_ctrl_no){
    case  FLASH_CTRL:
      break;

    case  FLASH_EE_CTRL:
      code[0x0a / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_MODE;
      code[0x26 / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_STATUS;
      code[0x30 / 2] = (uintptr_t)FLASH_EE_CTRL+ADDR_FLASH_CTRL_MODE;
      break;
  }

  w = 0;
  r = 0;
  while (w < words) {

    /* fix source data and destination address */
    data = (uintptr_t *)(code + (0x3A / 2));
    code[0x12 / 2] = (uintptr_t)data;
    code[0x16 / 2] = (uintptr_t)dptr;

    /* copy source data into RAM data area */
    n = 0;
    while ((n < (FLASH_ROW_SIZE / 2)) && (w < words)) {
      *data++ = *sptr++;
      n++;
      w++;
    }

    /* call code in RAM ... program one row */
    ((fn_ptr)code)();

    /* verify programed FLASH area */
    data = (uintptr_t *)(code + (0x3A / 2));
    n = 0;
    while ((n < (FLASH_ROW_SIZE / 2)) && (r < words)) {
      if (*dptr++ != *data++) {
        /* restore FLASH protection config (FLASH control module) */
        flash_protect_area(flash_ctrl_no, (flash_areas)prot_config);

        return (int16_t)r;  /* when program verify error */
      }
      n++;
      r++;
    }
  }

  /* restore FLASH protection config (FLASH control module) */
  flash_protect_area(flash_ctrl_no, (flash_areas)prot_config);

  return (int16_t)words;
}

int16_t flash_from_ram(flash_ctrl_num_t flash_ctrl_no, uintptr_t *sptr, uintptr_t *dptr, uint16_t words) {

  uint16_t  pages;
  int16_t   ret;
  uintptr_t dst_base;
  uintptr_t dst_max;

  /* nothing to copy */
  if (words == 0) {
    return 0;
  }

  dst_base = (uintptr_t)dptr & ~((uintptr_t)(FLASH_PAGE_SIZE - 1));  /* page aligned dst address */
  dst_max  = (uintptr_t)dptr + (words * 2) - 1;                      /* dst data area max address */

  pages = 1 + ((dst_max - dst_base) / FLASH_PAGE_SIZE);  /* number of pages to erase to cover dst data area */

  /* erase FLASH pages and verify erased area */
  ret = flash_erase_pages(flash_ctrl_no, (uintptr_t *)dst_base, pages);
  if (ret != (int16_t)pages) {
    return -1;  /* erase failed */
  }

  /* program FLASH rows and verify programmed area */
  ret = flash_program_rows(flash_ctrl_no, sptr, dptr, words);
  if (ret < 0) {
    return -1;
  }
  return ret;
}

uint16_t flash_get_page_base_addr(flash_ctrl_num_t flash_ctrl_no, uint16_t page) {

  if (page >= FLASH_NUM_PAGES) return 0;

  switch(flash_ctrl_no){
    case  FLASH_CTRL:
      return BASE_ADDR_IMEM + (page * FLASH_PAGE_SIZE);
      break;

    case  FLASH_EE_CTRL:
      return (page * FLASH_PAGE_SIZE);  // without base address value !
      break;
  }
  return 0;
}

uint16_t flash_get_row_base_addr(flash_ctrl_num_t flash_ctrl_no, uint16_t page, uint16_t row_in_page) {

  uint16_t addr;

  if (row_in_page >= (FLASH_PAGE_SIZE / FLASH_ROW_SIZE)) return 0;

  addr = flash_get_page_base_addr(flash_ctrl_no, page);
  addr += (row_in_page * FLASH_ROW_SIZE);
  return addr;
}

uint16_t flash_protect_area(flash_ctrl_num_t flash_ctrl_no, flash_areas areas) {

  uint16_t prot;
  uint16_t pre_value = 0;

  prot = READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_L) & 0x00FF;
  pre_value += (prot << 0);
  prot &= ~((areas >> 0) & 0x00FF);
  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_L, (0xA500 | prot));

  prot = READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_H) & 0x00FF;
  pre_value += (prot << 8);
  prot &= ~((areas >> 8) & 0x00FF);
  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_H, (0xA500 | prot));

  return pre_value;
}

uint16_t flash_unprotect_area(flash_ctrl_num_t flash_ctrl_no, flash_areas areas) {

  uint16_t prot;
  uint16_t pre_value = 0;

  prot = READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_L) & 0x00FF;
  pre_value += (prot << 0);
  prot |= ((areas >> 0) & 0x00FF);
  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_L, (0xA500 | prot));

  prot = READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_H) & 0x00FF;
  pre_value += (prot << 8);
  prot |= ((areas >> 8) & 0x00FF);
  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_H, (0xA500 | prot));

  return pre_value;
}

void flash_set_area_lock(flash_ctrl_num_t flash_ctrl_no, flash_areas areas){

  uint16_t prot;

  prot = ((areas >> 0) & 0x00FF);
  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_L_LOCK, (0xA500 | prot));

  prot = ((areas >> 8) & 0x00FF);
  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_H_LOCK, (0xA500 | prot));
}

uint16_t flash_get_area_lock(flash_ctrl_num_t flash_ctrl_no){

  uint16_t lock = 0;

  lock += (READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_L_LOCK) & 0x00FF) << 0;
  lock += (READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_AREA_MAIN_H_LOCK) & 0x00FF) << 8;

  return lock;
}

uint16_t flash_status(flash_ctrl_num_t flash_ctrl_no) {

  return READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_STATUS);
}

uint16_t flash_ecc_failure_addr(flash_ctrl_num_t flash_ctrl_no){

  return READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_BIT_ERROR_ADDR);
}

uint16_t get_flash_mode(flash_ctrl_num_t flash_ctrl_no){

  return READ_REG_U16(flash_ctrl_no + ADDR_FLASH_CTRL_MODE);
}

void flash_set_freq_config(flash_ctrl_num_t flash_ctrl_no, flash_freq_config freq){

  WRITE_REG_16(flash_ctrl_no + ADDR_FLASH_CTRL_FREQ_CONFIG,(0xA500 | (freq & 0x00FF)));
}

