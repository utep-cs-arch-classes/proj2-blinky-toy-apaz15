#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

#define SWITCHES (BIT0 | BIT1 | BIT2 | BIT3)

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed, switch1, switch2, switch3, switch4; /* effectively boolean */

#endif // included
