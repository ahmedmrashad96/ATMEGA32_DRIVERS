/*
 * SCHEDULER.c
 *
 *  Created on: Mar 17, 2020
 *      Author: Ahmed Rashad
 */

#include "SCHEDULER_LOCAL.h"


static uint8 scheduler=0;
void SCHEDULER_vidStart ()
{

	uint8 u8index;
	while(1)
	{
		if(scheduler)
		{

			for(u8index=0;u8index<Task_Count;u8index++)
			{

				if(Tasks[u8index].u16Offset==0)
				{
					Tasks[u8index].u16Offset=Tasks[u8index].u16Periodicity-1;
					Tasks[u8index].TaskFunPtr();
				}
				else
				{
					Tasks[u8index].u16Offset--;
				}
			}
			scheduler=0;
		}
	}

}

static void SCHEDULER_vidTask ()
{
	scheduler=1;

}

void SCHEDULER_vidInit ()
{
	TIMER_vidInit();
	TIMER_vidSetCallback(SCHEDULER_vidTask);
	Enable_Global_Interrupt();

}
