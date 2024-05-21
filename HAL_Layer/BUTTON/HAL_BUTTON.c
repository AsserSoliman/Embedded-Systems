/*
 * HAL_BUTTON.c
 *
 * Created: 20/05/2024 12:10:50
 *  Author: Asser Soliman
 */ 

#include "HAL_BUTTON.h"

Std_ReturnType hal_button_inialize(button_t* button)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == button || button->port > PORT_MAX_NUMBER || button->pin >PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t temp = {.port= button->port,.pin= button->pin,.mode=INPUT};
		mcal_dio_pin_initalize(&temp);
	}
	return ret;
}

Std_ReturnType hal_button_read(button_t* button,button_state_t* state)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == button || button->port > PORT_MAX_NUMBER || button->pin >PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		pin_config_t temp = {.port= button->port,.pin= button->pin,.mode=INPUT};
		logic_t logic;
		mcal_dio_pin_read(&temp,&logic);
		
		switch(button->type)
		{
			case ACTIVE_HIGH:
				if(logic == HIGH)
				{
					*state = BUTTON_PRESSED;
				}
				else
				{
					*state = BUTTON_RELEASED;
				}
				break;
			case ACTIVE_LOW:
				if(logic == LOW)
				{
					*state = BUTTON_RELEASED;
				}
				else
				{
					*state = BUTTON_PRESSED;
				}
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	return ret;
}