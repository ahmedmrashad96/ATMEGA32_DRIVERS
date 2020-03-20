/*
 * TEST.c
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */
#include "TEST_LOCAL.h"


#include "../UART/UART.h"
void TEST_DIO(void)
{
	DIO_vidInit();
	TIMER_vidInit();
	Enable_Global_Interrupt();
	LCD_vidInit();
	SW_vidInit();
	_Debug("ana hena");
	_Debug("ana hena tany");
//	while (0)
//	{
//		LCD_vidGotoXY(0,0);
//		switch (SW_u8Read(1))
//		{
//
//		case PrePushed:
//			LCD_vidString("PRE-PUSH");
//			break;
//		case SWITCH_STATE_Error:
//			LCD_vidString("ERROR   ");
//			break;
//		case PreReleased:
//			LCD_vidString("PRE-REL ");
//			break;
//		case Released:
//			LCD_vidString("RELEASED");
//			break;
//		case Pushed:
//			LCD_vidString("PUSHED  ");
//			break;
//		}
//	}
}

ISR(TIMER0_COMP_VECTOR_NUM)
{
	LCD_vidTask();
	SW_vidTask();
}
