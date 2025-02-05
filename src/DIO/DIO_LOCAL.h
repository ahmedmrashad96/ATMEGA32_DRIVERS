/*
 * DIO_LOCAL.h
 *
 *  This file contains the Locals of the DIO Driver
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */

#ifndef DIO_LOCAL_H_
#define DIO_LOCAL_H_

#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"
#include "../COMMON/INTERRUPT.h"
#include "DIO_CFG.h"

#define PORTA			*((volatile uint8 *)(0x3B))
#define DDRA			*((volatile uint8 *)(0x3A))
#define PINA			*((volatile uint8 *)(0x39))

#define PORTB			*((volatile uint8 *)(0x38))
#define DDRB			*((volatile uint8 *)(0x37))
#define PINB			*((volatile uint8 *)(0x36))

#define PORTC			*((volatile uint8 *)(0x35))
#define DDRC			*((volatile uint8 *)(0x34))
#define PINC			*((volatile uint8 *)(0x33))

#define PORTD			*((volatile uint8 *)(0x32))
#define DDRD			*((volatile uint8 *)(0x31))
#define PIND			*((volatile uint8 *)(0x30))

#define MCUCR_R   		*((volatile uint8 *)(0x55))
#define MCUCR_ISC0_S	(0x0)
#define MCUCR_ISC0_M	(0x3)
#define MCUCR_ISC1_S	(0x2)
#define MCUCR_ISC1_M	(0xC)

#define MCUCSR_R  		*((volatile uint8 *)(0x54))
#define MCUCR_ISC2		(6)
#endif /* DIO_LOCAL_H_ */
