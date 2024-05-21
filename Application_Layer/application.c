/*
 * AVR.c
 *
 * Created: 17/05/2024 11:25:02
 * Author : Asser Soliman
 */ 

#include "application.h"
#include "avr/delay.h"
led_t x1 = {.port=PORTA,.pin=PIN2,.state=LED_ON};
button_t x2 = {.port=PORTD,.pin=PIN7,.type=ACTIVE_LOW};
relay_t x3 = {.port=PORTC,.pin=PIN0,.state=RELAY_OFF};
optocoupler_t x4 = {.port=PORTD,.pin=PIN7,.state=OPTOCOUPLER_OFF};

int main(void)
{	
	initalize();
	
    /* Replace with your application code */
    while (1) 
    {	
		
		
	}
}

void initalize(void)
{
	
	
	hal_relay_initalize(&x3);
}

