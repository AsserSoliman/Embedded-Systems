/*
 * HAL_OPTOCOUPLER.c
 *
 * Created: 20/05/2024 18:19:23
 *  Author: Asser Soliman
 */ 
#include "HAL_OPTOCOUPLER.h"


Std_ReturnType hal_optocoupler_initalize(optocoupler_t* optocoupler)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == optocoupler || optocoupler->port >PORT_MAX_NUMBER || optocoupler->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{	
		pin_config_t temp = {.port=optocoupler->port,.pin=optocoupler->pin,.mode=OUTPUT};
		
		switch(optocoupler->state)
		{
			case OPTOCOUPLER_ON:
				temp.logic = HIGH;
				break;
			case OPTOCOUPLER_OFF:
				temp.logic = LOW;
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
		
		mcal_dio_pin_initalize(&temp);
	}
	
	return ret;
}

Std_ReturnType hal_optocoupler_on(optocoupler_t* optocoupler)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == optocoupler || optocoupler->port >PORT_MAX_NUMBER || optocoupler->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{	
		pin_config_t temp = {.port=optocoupler->port,.pin=optocoupler->pin};		
		mcal_dio_pin_high(&temp);
	}

	return ret;
}
Std_ReturnType hal_optocoupler_off(optocoupler_t* optocoupler)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == optocoupler || optocoupler->port >PORT_MAX_NUMBER || optocoupler->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t temp = {.port=optocoupler->port,.pin=optocoupler->pin};
		mcal_dio_pin_low(&temp);
	}

	return ret;
}
