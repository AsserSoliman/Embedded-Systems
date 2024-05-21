/*
 * HAL_LED.h
 *
 * Created: 20/05/2024 12:09:35
 *  Author: Asser Soliman
 */ 


#ifndef HAL_LED_H_
#define HAL_LED_H_

#include "../../MCAL_Layer/DIO/MCAL_DIO.h"

typedef enum{
	LED_OFF,
	LED_ON
	}led_state_t;

typedef struct{
	uint8_t port  :3;
	uint8_t pin   :4;
	uint8_t state :1;
	}led_t;

Std_ReturnType hal_led_intialize(led_t* led);
Std_ReturnType hal_led_on(led_t* led);
Std_ReturnType hal_led_off(led_t* led);
Std_ReturnType hal_led_toggle(led_t* led);

#endif /* HAL_LED_H_ */