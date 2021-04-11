#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
static char blink_count = 0;
static char count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){
  if(++blink_count == 200){
    // controller();
    simple_state();
    blink_count = 0;
  }
  /*if(++count == 250){
    change();
    count = 0;
    }*/
}

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

