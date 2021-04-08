#include <msp430.h>
#include "buzzer.h"

void  __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char count = 0;
  static char count_2 = 0;
  if (++count == 125){
    sounds();
    count = 0;
  }
}
