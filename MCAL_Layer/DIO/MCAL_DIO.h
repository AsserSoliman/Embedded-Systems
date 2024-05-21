/*
 * MCAL_DIO.h
 *
 * Created: 17/05/2024 11:51:35
 *  Author: Asser Soliman
 */ 

#ifndef _MCAL_DIO_H_
#define _MCAL_DIO_H_

#include <stdio.h>
#include <stdlib.h>
#include "../Std_Types.h"

#define BIT_MASK	(0X01)

// MCU Specifications
#define PLATFORM 8             // Type
#define F_CPU 8000000UL		   // Clock Rate

#include <util/delay.h>

#if PLATFORM == 8
	#define HWREG(_X) (*((volatile uint8_t*)(_X)))		// 8 Bit MCU
#elif PLATFORM == 16
	#define HWREG(_X) (*((volatile uint16_t*)(_X)))		// 16 Bit MCU
#endif


// Bit Manipulation
#define SET_BIT(A,BIT_POS)     (A |=  (BIT_MASK << BIT_POS))
#define CLEAR_BIT(A,BIT_POS)   (A &= ~(BIT_MASK << BIT_POS))
#define TOGGLE_BIT(A,BIT_POS)  (A ^=  (BIT_MASK << BIT_POS))
#define READ_BIT(A,BIT_POS)	   ((A >> BIT_POS) & BIT_MASK)

// Max Numbers
#define PORT_MAX_NUMBER	3
#define PIN_MAX_NUMBER	7


// Data types

typedef enum{
	INPUT,
	OUTPUT
	}mode_t;

typedef enum{
	LOW,
	HIGH
}logic_t;

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}pin_t;

typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
}port_t;

typedef struct{
	uint8_t port:  3;
	uint8_t pin:   3;
	uint8_t mode:  1;
	uint8_t logic: 1;
	}pin_config_t;
	
typedef struct{
	uint8_t port:  4;
	uint8_t mode:  2;
	uint8_t logic: 2;
}port_config_t;


// Pin Functions 
Std_ReturnType mcal_dio_pin_initalize			(pin_config_t* config);
Std_ReturnType mcal_dio_pin_low					(pin_config_t* config);
Std_ReturnType mcal_dio_pin_high				(pin_config_t* config);
Std_ReturnType mcal_dio_pin_toggle				(pin_config_t* config);
Std_ReturnType mcal_dio_pin_read				(pin_config_t* config, logic_t* logic);
Std_ReturnType mcal_dio_pin_set_direction		(pin_config_t* config, mode_t mode);
Std_ReturnType mcal_dio_pin_get_direction		(pin_config_t* config, mode_t* mode);

// Port Functions
Std_ReturnType mcal_dio_port_initalize			(port_config_t* config);
Std_ReturnType mcal_dio_port_low				(port_config_t* config);
Std_ReturnType mcal_dio_port_high				(port_config_t* config);
Std_ReturnType mcal_dio_port_toggle				(port_config_t* config);
Std_ReturnType mcal_dio_port_read				(port_config_t* config, logic_t* logic);
Std_ReturnType mcal_dio_port_set_direction		(port_config_t* config, mode_t mode);
Std_ReturnType mcal_dio_port_get_direction		(port_config_t* config, mode_t* mode);

#endif /* _MCAL_DIO_H_ */