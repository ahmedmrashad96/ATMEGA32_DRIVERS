/*
 * DIO.h
 *
 *  This file contains the Prototypes of the DIO Driver
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */

#ifndef DIO_H_
#define DIO_H_
// the return values of function
enum DIO_STATUS{
	ERROR = 0,
	SUCCESS=1
};

// the values of pins in reading and writing
enum DIO_DATA{
	LOW		=0,	HIGH	=1,
	DIO_DATA_ERROR
};

// the values of pins' directions
enum DIO_PIN_DIR{
	INPUT		 =0,	OUTPUT 	=1,
	INPUT_PULLUP =2,
	DIO_PIN_DIR_MAX
};

// the port names
enum DIO_PORT_NAMES{
	PORT_A = 0,
	PORT_B = 1,
	PORT_C = 2,
	PORT_D = 3,
	PORT_MAX
};

// the values of pins' names
enum DIO_PINS {
	PORTA_0= 0,	PORTA_1= 1,	PORTA_2= 2,	PORTA_3= 3,	PORTA_4= 4,	PORTA_5= 5,	PORTA_6= 6,	PORTA_7= 7,
	PORTB_0= 8,	PORTB_1= 9,	PORTB_2=10,	PORTB_3=11,	PORTB_4=12,	PORTB_5=13,	PORTB_6=14,	PORTB_7=15,
	PORTC_0=16,	PORTC_1=17,	PORTC_2=18,	PORTC_3=19,	PORTC_4=20,	PORTC_5=21,	PORTC_6=22,	PORTC_7=23,
	PORTD_0=24,	PORTD_1=25,	PORTD_2=26,	PORTD_3=27,	PORTD_4=28,	PORTD_5=29,	PORTD_6=30,	PORTD_7=31,
	DIO_PINS_MAX
};

#define INTERRUPT_SENSE_LOW			(0x0)
#define INTERRUPT_SENSE_ANYCHANGE 	(0x1)
#define INTERRUPT_SENSE_FALLING		(0x2)
#define INTERRUPT_SENSE_RISING		(0x3)
#define INTERRUPT_SENSE_OFF			(0x4)





void 	DIO_vidInit 		(void);
uint8	DIO_u8SetPinDir (uint8 U8PinNum , uint8 U8Dir);
uint8 	DIO_u8WritePin 	(uint8 U8PinNum , uint8 U8Data);
uint8   DIO_u8ReadPin 	(uint8 U8PinNum);

void DIO_vidSetCallback_Low(uint8 u8IntNum , void  (*fun)(void));
void DIO_vidSetCallback_Rising(uint8 u8IntNum , void  (*fun)(void));
void DIO_vidSetCallback_Falling(uint8 u8IntNum , void  (*fun)(void));
void DIO_vidSetCallback_AnyChange(uint8 u8IntNum , void  (*fun)(void));
void DIO_vidEnableInt(uint8 u8IntNum);
void DIO_vidDisableInt(uint8 u8IntNum);

#endif /* DIO_H_ */
