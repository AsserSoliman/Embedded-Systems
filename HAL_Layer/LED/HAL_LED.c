/*
 * HAL_LED.c
 *
 * Created: 20/05/2024 12:10:28
 *  Author: Asser Soliman
 */ 

#include "HAL_LED.h"

Std_ReturnType hal_led_intialize(led_t* led)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == led || led->port > PORT_MAX_NUMBER || led->pin >PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t pin = {.port=led->port,.pin=led->pin,.mode=OUTPUT};
		
		switch(led->state)
		{
			case LED_OFF:
				pin.logic = LOW;
				break;
			case LED_ON:
				pin.logic = HIGH;
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
		mcal_dio_pin_initalize(&pin); 
	}
	return ret;
}

Std_ReturnType hal_led_on(led_t* led)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == led || led->port > PORT_MAX_NUMBER || led->pin >PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t pin = {.port=led->port,.pin=led->pin};
		mcal_dio_pin_high(&pin);
	}
	return ret;
}

Std_ReturnType hal_led_off(led_t* led)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == led || led->port > PORT_MAX_NUMBER || led->pin >PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t pin = {.port=led->port,.pin=led->pin};
		mcal_dio_pin_low(&pin);
	}
	return ret;
}

Std_ReturnType hal_led_toggle(led_t* led)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == led || led->port > PORT_MAX_NUMBER || led->pin >PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t pin = {.port=led->port,.pin=led->pin};
		mcal_dio_pin_toggle(&pin);
	}
	return ret;
	
}