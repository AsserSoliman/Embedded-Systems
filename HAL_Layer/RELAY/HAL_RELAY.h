/*
 * HAL_RELAY.h
 *
 * Created: 20/05/2024 18:20:21
 *  Author: Asser Soliman
 */ 


#ifndef HAL_RELAY_H_
#define HAL_RELAY_H_

#include "../../MCAL_Layer/DIO/MCAL_DIO.h"

typedef enum{
	RELAY_ON,
	RELAY_OFF
}relay_status_t;

typedef struct{
	uint8_t port:3;
	uint8_t pin:4;
	uint8_t state:1;
}relay_t;

Std_ReturnType	 hal_relay_initalize(relay_t* relay);
Std_ReturnType	 hal_relay_on(relay_t* relay);
Std_ReturnType	 hal_relay_off(relay_t* relay);



#endif /* HAL_RELAY_H_ */