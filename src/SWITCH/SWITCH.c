/*
 * SWITCH.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#include "SWITCH_LOCAL.h"

static	uint8 PBN[PBN_COUNT] = {};
static	uint8 PBN_state[PBN_COUNT] = {SWITCH_STATE_Error};
static	uint8 u8Count=0;


void SW_vidInit(void)
{

}

uint8 SW_u8AddPBN (uint8 u8NewPBN)
{
	uint8 u8i=0,u8Flag=0;
	if (u8Count>=PBN_COUNT)
	{
		u8Flag =1;
	}
	for ( ;(u8i<u8Count) && (!u8Flag) ;u8i++)
	{
		if (PBN[u8i]==u8NewPBN)
		{
			u8Flag =1;
		}
	}
	if (!u8Flag)
	{
		PBN[u8Count++]=u8NewPBN;
		DIO_u8SetPinDir(u8NewPBN,INPUT_PULLUP);
	}
	return !u8Flag;
}

void SW_vidTask(void)
{
	static uint8 counter[PBN_COUNT] = {0},u8i=0;

	if (u8i < u8Count)
	{
		switch (PBN_state[u8i])
		{
		case Released 	:
			if (DIO_u8ReadPin(PBN[u8i])==LOW)
				PBN_state[u8i] = PrePushed;
			break;
		case PrePushed	:
			if (DIO_u8ReadPin(PBN[u8i])==LOW)
				counter[u8i]++;
			if (counter[u8i]>=SENS_COUNT)
			{
				counter[u8i]=0;
				PBN_state[u8i] = Pushed;
			}
			break;
		case Pushed		:
			if (DIO_u8ReadPin(PBN[u8i])==HIGH)
				PBN_state[u8i] = PreReleased;
			break;
		case PreReleased:
			if (DIO_u8ReadPin(PBN[u8i])==HIGH)
				counter[u8i]++;
			if (counter[u8i]>=SENS_COUNT)
			{
				counter[u8i]=0;
				PBN_state[u8i] = Released;
			}
			break;
		default:
			PBN_state[u8i] = Released;
			break;
		}
		u8i++;
	}
	else
	{
		u8i=0;
	}
}

uint8 SW_u8Read(uint8 u8PBN)
{
	uint8 u8i = 0,state=SWITCH_STATE_Error;
	for( ;(u8i<u8Count)&&(state==SWITCH_STATE_Error);u8i++)
	{
		if (PBN[u8i]==u8PBN)
		{
			state =PBN_state[u8i];
		}
	}
	return state;
}
