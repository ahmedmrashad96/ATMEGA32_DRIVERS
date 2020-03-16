/*
 * TEST.c
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */
#include "TEST_LOCAL.h"
#include "TEST_CFG.h"

void TEST_DIO(void)
{
	if(DIO_u8Init())
	{
		DIO_u8SetPinDir(PORTA_0,OUTPUT);
		DIO_u8WritePin (PORTA_0,HIGH);
		DIO_u8SetPinDir(PORTA_1,INPUT_PULLUP);
		DIO_u8SetPinDir(PORTA_2,OUTPUT);
		while (1)
		DIO_u8WritePin (PORTA_2,DIO_u8ReadPin(PORTA_1));
	}
}
