/*
 * TIMER.c
 *
 *  Created on: Dec 10, 2019
 *      Author: Ahmed Rashad
 */

#include "TIMER_LOCAL.h"


static uint32 time=0;
void updatetime()
{
	time++;
}
uint32 millis()
{
	return time /(TIMER0_TICK_PER_SECOND/1000	);
}
void TIMER_vidInit()
{
	TCCR0_R =(0								<<TCCR0_FOC0_S	)
			|(Get_Bit(TIMER0_MODE,0)		<<TCCR0_WGM00_S	)
			|(Get_Bit(TIMER0_MODE,1)		<<TCCR0_WGM01_S	)
			|((TIMER0_OC0_MODE				<<TCCR0_COM_S	)&TCCR0_COM_M	)
			|((TIMER0_CLOCK					<<TCCR0_CS_S	)&TCCR0_CS_M	);

	TIMSK_R =(TIMER0_OVERFLOW_INT			<<TIMSK_TOIE0_S	)
			|(TIMER0_OCR_INT				<<TIMSK_OCIE0_S	);

	OCR0_R	= TIMER0_OCR0;
}

void _delay_ms(uint16 U16Time)
{
	uint16 U16i;
	uint8 TCT,OCT,TCNT,SS;
	SS = SREG;
	Disable_Global_Interrupt();
	TCT = TCCR0_R;
	OCT = OCR0_R;
	TCNT=TCNT0_R;
	TCCR0_R = (TIMER0_CLOCK_PRESCALAR_256|Get_Bit(TIMER0_MODE_CTC,0)<<TCCR0_WGM00_S|Get_Bit(TIMER0_MODE_CTC,1)<<TCCR0_WGM01_S);
	OCR0_R  = 200;
	for (U16i=0;U16i<U16Time;U16i++)
	{
		while(!Get_Bit(TIFR_R,1));
		Set_Bit(TIFR_R,1);
	}
	TCNT0_R=TCNT;
	TCCR0_R = TCT;
	OCR0_R = OCT;
	SREG=SS;
}

