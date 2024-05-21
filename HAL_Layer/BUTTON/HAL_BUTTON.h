/*
 * HAL_LED.h
 *
 * Created: 20/05/2024 12:10:06
 *  Author: Asser Soliman
 */ 


#ifndef HAL_BUTTON_H_
#define HAL_BUTTON_H_

#include "../../MCAL_Layer/DIO/MCAL_DIO.h"

typedef enum{
	ACTIVE_HIGH,
	ACTIVE_LOW
	}button_type_t;
	
typedef enum{
	BUTTON_PRESSED,
	BUTTON_RELEASED
	}button_state_t;

typedef struct{
	uint8_t port:3;
	uint8_t pin:3;
	uint8_t type:2;
	}button_t;
	
Std_ReturnType hal_button_inialize(button_t* button);
Std_ReturnType hal_button_read(button_t* button,button_state_t* state);

#endif /* HAL_LED_H_ */1