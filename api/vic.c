#include "base.h"
#include "types.h"
#include "utils.h"

#include "h430.h"
#include "vic.h"
#include "vic_bf.h"

#define __ALLOW_NESTED_IRQS__

static callback_t *vbase[VIC_NUM_IRQS];  // holds pointers to "module callback function arrays"
static uintptr_t   rbase[VIC_NUM_IRQS];  // holds pointers to "module VENABLE registers"

typedef void (*sfn_ptr)(uintptr_t);

#ifdef __ICC430__
  #pragma language=extended
/* #pragma vector=0 */
#endif
_INTERRUPT_ vic_handler(void) {

  int pno;
  int sno;
#ifdef __ALLOW_NESTED_IRQS__
  int pvmax;
  int svmax;
#endif
  callback_t *sptr;
  sfn_ptr sfn;

  pno = READ_REG_U16(BASE_ADDR_VIC + ADDR_VIC_IRQ_VNO);  // P VNO

  // disable non initialized but asserting primary irq number ...
  if ((vbase[pno] == NULL) || (rbase[pno] == 0)) {
    WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_IRQ_VDISABLE, pno);  // P VDISABLE
    return;
  }

  sno = READ_REG_U16(rbase[pno] + 6);  // S VNO
  sptr = vbase[pno] + sno;

  WRITE_REG_16(rbase[pno] + 6, sno);  // S VNO ... clear related event

#ifdef __ALLOW_NESTED_IRQS__
  // save current VMAXs ...
  pvmax = READ_REG_U16(BASE_ADDR_VIC + ADDR_VIC_IRQ_VMAX);   // P VMAX
  svmax = READ_REG_U16(rbase[pno] + 4);                      // S VMAX

  // set appropriate VMAX values ...
  WRITE_REG_16(rbase[pno] + 4, sno);                         // S VMAX
  WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_IRQ_VMAX, pno + 1);  // P VMAX

  // allow IRQs (incl. 2 pre NOPs to be sure that masks got active !) ...
  cpu_enable_irqs();
#endif

  // call registered secondary IRQ handler ...
  sfn = (sfn_ptr)(*sptr);
  if (sfn != NULL) {
    sfn(sno);
  }

#ifdef __ALLOW_NESTED_IRQS__
  // deny IRQs ...
  cpu_disable_irqs();

  // restore previous VMAXs ...
  WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_IRQ_VMAX, pvmax);  // P VMAX
  WRITE_REG_16(rbase[pno] + 4, svmax);                     // S VMAX
#endif
}

const uintptr_t *vic_handler_ptr = (const uintptr_t *)vic_handler;

void vic_handler_init(void) {

  int i;

  cli();
  WRITE_REG_32(BASE_ADDR_VIC + ADDR_VIC_IRQ_MASK, 0);  // P MASK ... clear
  for (i = 0; i < VIC_NUM_IRQS; i++) {
    vbase[i] = (callback_t *)(NULL);
    rbase[i] = 0;
  }
  WRITE_MEM_PTR(BASE_ADDR_VIC + ADDR_VIC_TABLE_BASE, (uintptr_t)&vic_handler_ptr);
  WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_TABLE_TYPE, 1);
  sei();
}

void cli(void) {

  WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_MAIN_ENABLE, 0);
}

void sei(void) {

  WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_MAIN_ENABLE, 1);
}

void irq_handler_init(vic_irq_t pno, int svnum, callback_t *svbase, uintptr_t srbase) {

  int i;
  callback_t *sptr;

  vbase[pno] = svbase;
  rbase[pno] = srbase;

  WRITE_REG_32(rbase[pno] - 4, 0);  // S MASK ... clear

  sptr = svbase;
  for (i = 0; i < svnum; i++) {
    *sptr++ = (callback_t)NULL;
  }
}

void irq_handler_register(vic_irq_t pno, int sno, callback_t callback) {

  WRITE_MEM_PTR((uintptr_t)(vbase[pno] + sno), (uintptr_t)callback);

  WRITE_REG_16(BASE_ADDR_VIC + ADDR_VIC_IRQ_VENABLE, pno);  // P VENABLE
}

void irq_enable(vic_irq_t pno, int sno) {

  WRITE_REG_16(rbase[pno] + 0, sno);  // S VENABLE
}

void irq_disable(vic_irq_t pno, int sno) {

  WRITE_REG_16(rbase[pno] + 2, sno);  // S VDISABLE
}

uint32_t irq_get_status(vic_irq_t pno) {

  return READ_REG_U32(rbase[pno] - 8);
}

void irq_clear_all_events(vic_irq_t pno) {

  WRITE_REG_32(rbase[pno] - 8, 0xFFFFFFFF);
}

/*RPY*/ //clear dedicated IRQ event
void irq_clear_event(vic_irq_t pno,int sno)
{  
  WRITE_REG_32(rbase[pno] - 8, (1<<sno));
}