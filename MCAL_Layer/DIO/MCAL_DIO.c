/*
 * MCAL_DIO.c
 *
 * Created: 20/05/2024 12:23:16
 *  Author: Asser Soliman
 */ 

#include "MCAL_DIO.h"



uint8_t* DDR_registers [4] = {(uint8_t*)0X3A,(uint8_t*)0X37,(uint8_t*)0X34,(uint8_t*)0X31};
uint8_t* PORT_registers[4] = {(uint8_t*)0X3B,(uint8_t*)0X38,(uint8_t*)0X35,(uint8_t*)0X32};
uint8_t* PIN_registers [4] = {(uint8_t*)0X39,(uint8_t*)0X36,(uint8_t*)0X33,(uint8_t*)0X30};

Std_ReturnType mcal_dio_pin_initalize			(pin_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(config->mode)
		{
			case INPUT:
				CLEAR_BIT(*DDR_registers[config->port],config->pin);
				break;
			case OUTPUT:
				SET_BIT(*DDR_registers[config->port],config->pin);
				if(config->logic == HIGH)
				{
					SET_BIT(*PORT_registers[config->port],config->pin);
				}
				else
				{
					CLEAR_BIT(*PORT_registers[config->port],config->pin);
				}
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	
	return ret;
}

Std_ReturnType mcal_dio_pin_low					(pin_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		CLEAR_BIT(*PORT_registers[config->port],config->pin);
	}
	
	return ret;
	
}

Std_ReturnType mcal_dio_pin_high				(pin_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		SET_BIT(*PORT_registers[config->port],config->pin);
	}
	
	return ret;	
}

Std_ReturnType mcal_dio_pin_toggle				(pin_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		TOGGLE_BIT(*PORT_registers[config->port],config->pin);
	}
	
	return ret;
}

Std_ReturnType mcal_dio_pin_read				(pin_config_t* config, logic_t* logic)
{	
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER || NULL == logic)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*logic = READ_BIT(*PIN_registers[config->port],config->pin);
	}
	
	return ret;
}

Std_ReturnType mcal_dio_pin_set_direction		(pin_config_t* config, mode_t mode)
{	
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{	
		switch(mode)
		{
			case INPUT:
				CLEAR_BIT(*DDR_registers[config->port],config->pin);
				break;
			case OUTPUT:
				SET_BIT(*DDR_registers[config->port],config->pin);
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	
	return ret;
}

Std_ReturnType mcal_dio_pin_get_direction		(pin_config_t* config, mode_t* mode)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port > PORT_MAX_NUMBER || config->pin > PIN_MAX_NUMBER || NULL == mode)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*mode = READ_BIT(*DDR_registers[config->port],config->pin);
	}
	
	return ret;
}


Std_ReturnType mcal_dio_port_initalize			(port_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port >PORT_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(config->mode)
		{
			case INPUT:
				*DDR_registers[config->port] &= 0X00;
				break;
			case OUTPUT:
				*DDR_registers[config->port] |= 0XFF;
				break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	
	return ret;
}

Std_ReturnType mcal_dio_port_low				(port_config_t* config)
{	
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port >PORT_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*PORT_registers[config->port] &= 0X00;
	}
	
	return ret;
}

Std_ReturnType mcal_dio_port_high				(port_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port >PORT_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*PORT_registers[config->port] |= 0XFF;
	}
	
	return ret;
}

Std_ReturnType mcal_dio_port_toggle				(port_config_t* config)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port >PORT_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*PORT_registers[config->port] ^= 0XFF;
	}
	
	return ret;
}

Std_ReturnType mcal_dio_port_read				(port_config_t* config, logic_t* logic)
{
		Std_ReturnType ret = E_OK;
		
		if(NULL == config || config->port >PORT_MAX_NUMBER)
		{
			ret = E_NOT_OK;
		}
		else
		{
			*logic = *PORT_registers[config->port] & 0XFF;
		}
		
		return ret;
	
}
Std_ReturnType mcal_dio_port_set_direction		(port_config_t* config, mode_t mode)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port >PORT_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(mode)
		{
			case INPUT:
				*DDR_registers[config->port] &= 0X00;
				break;
			case OUTPUT:
				*DDR_registers[config->port] |= 0XFF;
				 break;
			default:
				ret = E_NOT_OK;
				break;
		}
	}
	
	return ret;
}

Std_ReturnType mcal_dio_port_get_direction		(port_config_t* config, mode_t* mode)
{
	Std_ReturnType ret = E_OK;
	
	if(NULL == config || config->port >PORT_MAX_NUMBER)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*mode = *DDR_registers[config->port] & 0XFF;
	}
	
	return ret;
}