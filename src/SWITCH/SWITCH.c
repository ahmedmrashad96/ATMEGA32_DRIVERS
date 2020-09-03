/*
 * SWITCH.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#include "SWITCH_LOCAL.h"


#ifdef SWITCH_CONNECTION
#	if  SWITCH_CONNECTION == PULLDOWN
#		define SWITCH_CON	INPUT
#		define SWITCH_PUSH	HIGH
#		define SWITCH_REL	LOW
#	elif (SWITCH_CONNECTION == PULLUP)
#		define SWITCH_CON	INPUT_PULLUP
#		define SWITCH_PUSH	LOW
#		define SWITCH_REL	HIGH
#	endif
#else
#	error "SWITCH_CONNECTION not defined"
#endif

static	uint8 PBN[PBN_COUNT] = {PBN_0,PBN_1,PBN_2};
static	uint8 PBN_state[PBN_COUNT] = {SWITCH_STATE_Error};

static uint8 * u8Ptr[PBN_COUNT];

void SW_vidFlag (uint8 PBN_no,uint8 * u8PTRtoFlag)
{
	u8Ptr[PBN_no]=u8PTRtoFlag;
}
void SW_vidInit(void)
{
	uint8 u8i;
	for (u8i=0 ;u8i<PBN_COUNT;u8i++)
	{
		DIO_u8SetPinDir(PBN[u8i],SWITCH_CON);
	}


}


void SW_vidTask(void)
{
	static uint8 counter[PBN_COUNT] = {0},u8i=0;

	if (u8i < PBN_COUNT)
	{
		switch (PBN_state[u8i])
		{
		case Released 	:
			if (DIO_u8ReadPin(PBN[u8i])==SWITCH_PUSH)
				PBN_state[u8i] = PrePushed;
			break;
		case PrePushed	:
			if (DIO_u8ReadPin(PBN[u8i])==SWITCH_PUSH)
				counter[u8i]++;
			if (counter[u8i]>=SENS_COUNT)
			{
				counter[u8i]=0;
				PBN_state[u8i] = Pushed;
				*u8Ptr[u8i]=1;
			}
			break;
		case Pushed		:
			if (DIO_u8ReadPin(PBN[u8i])==SWITCH_REL)
				PBN_state[u8i] = PreReleased;
			break;
		case PreReleased:
			if (DIO_u8ReadPin(PBN[u8i])==SWITCH_REL)
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
	return PBN_state[u8PBN];
}
