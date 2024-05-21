/*
 * HAL_RELAY.c
 *
 * Created: 20/05/2024 18:20:03
 *  Author: Asser Soliman
 */ 

#include "HAL_RELAY.h"


Std_ReturnType	 hal_relay_initalize(relay_t* relay)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == relay || relay->port > PORT_MAX_NUMBER || relay->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t temp = {.port=relay->port,.pin=relay->pin,.mode=OUTPUT};
		
		switch(relay->state)
		{
			case RELAY_ON:
				temp.logic = HIGH;
				break;
			case RELAY_OFF:
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

Std_ReturnType	 hal_relay_on(relay_t* relay)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == relay || relay->port > PORT_MAX_NUMBER || relay->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t temp = {.port=relay->port,.pin=relay->pin};	
		mcal_dio_pin_high(&temp);
	}
	
	return ret;
}

Std_ReturnType	 hal_relay_off(relay_t* relay)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == relay || relay->port > PORT_MAX_NUMBER || relay->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t temp = {.port=relay->port,.pin=relay->pin};
		mcal_dio_pin_low(&temp);
	}
	
	return ret;
}