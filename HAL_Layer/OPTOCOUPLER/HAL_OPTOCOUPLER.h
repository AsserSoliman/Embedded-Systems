/*
 * HAL_OPTOCOUPLER.h
 *
 * Created: 20/05/2024 18:19:37
 *  Author: Asser Soliman
 */ 


#ifndef HAL_OPTOCOUPLER_H_
#define HAL_OPTOCOUPLER_H_

#include "../../MCAL_Layer/DIO/MCAL_DIO.h"

typedef	enum{
	OPTOCOUPLER_ON,
	OPTOCOUPLER_OFF
	}optocoupler_state_t;

typedef struct{
	uint8_t port :3;
	uint8_t pin  :4;
	uint8_t state:1;
	}optocoupler_t;

Std_ReturnType hal_optocoupler_initalize(optocoupler_t* optocoupler);
Std_ReturnType hal_optocoupler_on(optocoupler_t* optocoupler);
Std_ReturnType hal_optocoupler_off(optocoupler_t* optocoupler);

#endif /* HAL_OPTOCOUPLER_H_ */