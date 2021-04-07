#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  static char count = 0;
  
  if (++blink_count == 1) {
    controller();
    //counting7();
    //simple_state();
    blink_count = 0;
  }
  if(++count == 250){
    change();
    count = 0;
  }
}
