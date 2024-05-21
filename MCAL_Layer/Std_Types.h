/*
 * Std_Types.h
 *
 * Created: 17/05/2024 12:00:48
 *  Author: Asser Soliman
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char uint8_t;
typedef signed   char sint8_t; 

typedef unsigned int uint16_t;
typedef signed   int sint16_t;

typedef unsigned long int uint32_t;
typedef signed   long int sint32_t;

typedef unsigned long long int uint64_t;
typedef signed   long long int sint64_t;

typedef float f32;

typedef uint8_t Std_ReturnType;

typedef enum{
	E_OK,
	E_NOT_OK
}ret_t;

#endif /* STD_TYPES_H_ */