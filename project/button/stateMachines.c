#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
static char control = 0;

void controller(){
  
  if(control == 0){
    led_25();
  }
  else if(control == 1){
    led_50();
  }
  else if(control == 2){
    led_75();
  }
  else if(control == 3){
    red_always_on();
    green_always_on();
  }
  else {
    P1OUT &= (0xff ^ LEDS) | 0;
  }
}
void change(){
  if(control == 0)
    control = 1;
  else if(control == 1)
    control = 2;
  else if(control == 2)
    control = 3;
  else if(control == 3)
    control = 4;
  else
    control = 0;
}
void red_always_on(){
  red_on = 1;
  led_changed = 1;
  led_update();
}
void green_always_on(){
  green_on = 1;
  led_changed = 1;
  led_update();
}
void simple_state(){
  static char state = 0;
  if(state == 0){
    red_on = 1;
    green_on = 0;
    state = 1;
  } else {
    red_on = 0;
    green_on = 1;
    state = 0;
  }
  led_changed = 1;
  led_update();
}
void led_75(){
  static char state = 0;
  int i;
  if(state == 0){
    red_on = 0;
    green_on = 0;
    state = 1;
  } else if(state == 1){
    red_on = 1;
    green_on = 1;
    state = 2;
  } else if(state == 2){
    red_on = 1;
    green_on = 1;
    state = 3;
  } else if(state == 3){
    red_on = 1;
    green_on = 1;
    state = 0;
  }
  
  led_changed = 1;
  led_update();
}
void led_50(){
  static char state = 0;
  if(state == 0){
    red_on = 0;
    green_on = 0;
    state = 1;
  } else {
    red_on = 1;
    green_on = 1;
    state = 0;
  }
  led_changed = 1;
  led_update();
}
void led_25(){
  static char state = 0;
  if(state == 0){
    red_on = 0;
    green_on = 0;
    state = 1;
  } else if(state == 1){
    red_on = 0;
    green_on = 0;
    state = 2;
  } else if(state == 2){
    red_on = 0;
    green_on = 0;
    state = 3;
  } else if(state == 3){
    red_on = 1;
    green_on = 1;
    state = 0;
  }
  led_changed = 1;
  led_update();
}
void counting7(){
  static char state = 0;
  switch(state){
  case 0:
    red_on = 0;
    green_on = 0;
    state = 1;
    break;
  case 1:
    red_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 0;
    green_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 0;
    green_on = 0;
    state = 4;
    break;
  case 4:
    red_on = 0;
    green_on = 1;
    state = 5;
    break;
  case 5:
    red_on = 0;
    green_on = 0;
    state = 6;
    break;
  case 6:
    red_on = 0;
    green_on = 1;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
