/*
 * DIO.C
 *
 * This file contains the Source Code of the DIO Driver
 *
 *  Created on: Mar 16, 2020
 *      Author: Ahmed Rashad
 */



#include "DIO_LOCAL.h"

void DIO_vidInit (void)
{
	//DIO Initialization function
	if(INT0_SENSE < INTERRUPT_SENSE_OFF )
	{
		MCUCR_R &= ~(MCUCR_ISC0_M);
		MCUCR_R |= ((INT0_SENSE<<MCUCR_ISC0_S)&(MCUCR_ISC0_M));

	}
	if(INT0_SENSE < INTERRUPT_SENSE_OFF )
	{
		MCUCR_R &= ~(MCUCR_ISC1_M);
		MCUCR_R |= ((INT1_SENSE<<MCUCR_ISC1_S)&(MCUCR_ISC0_M));
	}
	if((INT1_SENSE < INTERRUPT_SENSE_OFF )&&(INT1_SENSE < INTERRUPT_SENSE_ANYCHANGE ))
	{
		Assign_Bit(MCUCSR_R,MCUCR_ISC2,Get_Bit(INT1_SENSE,0));

	}
}

uint8 DIO_u8SetPinDir (uint8  u8PinNum , uint8 u8Dir)
{
	/*
	 * Setting pin direction
	 * 		Pin number 		: 	PORTx_n 	n= 	0:7		x=	A:D
	 *		Pin Direction	:	OUTPUT	/	INPUT 	/ INPUT_PULLUP
	 *
	 */
	// initializing the status of the functions
	uint8 u8Status=ERROR;
	// checking the inputs of the functions
	if ((u8PinNum<DIO_PINS_MAX)&&(u8Dir<DIO_PIN_DIR_MAX))
	{
		u8Status = SUCCESS;
		// calculating the port no.
		switch(u8PinNum/8)
		{
		case PORT_A : //PORTA
			// Write pin direction

			Assign_Bit(DDRA ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTA,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		case PORT_B : //PORTB
			// Write pin direction
			Assign_Bit(DDRB ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTB,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		case PORT_C : //PORTC
			// Write pin direction
			Assign_Bit(DDRC ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTC,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		case PORT_D : //PORTD
			// Write pin direction
			Assign_Bit(DDRD ,u8PinNum % 8, Get_Bit(u8Dir,0) );
			// Write pin pullup state
			Assign_Bit(PORTD,u8PinNum % 8, Get_Bit(u8Dir,1) );
			break;
		default:
			u8Status=ERROR;
			break;
		}

	}
	return u8Status;

}

uint8 DIO_u8WritePin (uint8 u8PinNum , uint8 u8Data)
{
	/*
	 * Writing to pin
	 * 		Pin number 		: 	PORTx_n 	n= 	0:7		x=	A:D
	 *		Pin Data		:	HIGH	/	LOW
	 *
	 */
	// initializing the status of the functions
	uint8 u8Status=ERROR;
	// checking the inputs of the functions
	if ((u8PinNum<DIO_PINS_MAX)&&(u8Data<DIO_DATA_ERROR))
	{
		u8Status=SUCCESS;
		// calculating the port no.
		switch(u8PinNum/8)
		{
		case PORT_A : //PORTA
			// Write pin values
			Assign_Bit(PORTA ,u8PinNum % 8, u8Data );
			break;
		case PORT_B : //PORTB
			// Write pin values
			Assign_Bit(PORTB ,u8PinNum % 8, u8Data );
			break;
		case PORT_C : //PORTC
			// Write pin values
			Assign_Bit(PORTC ,u8PinNum % 8, u8Data );
			break;
		case PORT_D : //PORTD
			// Write pin values
			Assign_Bit(PORTD ,u8PinNum % 8, u8Data );
			break;
		default:
			u8Status=ERROR;
			break;
		}

	}
	return u8Status;
}

uint8 DIO_u8ReadPin (uint8 u8PinNum )
{
	/*
	 * Reading from pin
	 * 		Pin number 		: 	PORTx_n 	n= 	0:7		x=	A:D
	 */
	// initializing the status of the functions
	uint8 u8Data=DIO_DATA_ERROR;
	// checking the inputs of the functions
	if (u8PinNum<DIO_PINS_MAX)
	{
		// calculating the port no.
		switch(u8PinNum/8)
		{
		case PORT_A : //PORTA
			//Read from pin
			u8Data= Get_Bit(PINA ,u8PinNum % 8);
			break;
		case PORT_B : //PORTB
			//Read from pin
			u8Data= Get_Bit(PINB ,u8PinNum % 8);
			break;
		case PORT_C : //PORTC
			//Read from pin
			u8Data= Get_Bit(PINC ,u8PinNum % 8);
			break;
		case PORT_D : //PORTD
			//Read from pin
			u8Data= Get_Bit(PIND ,u8PinNum % 8);
			break;
		default:
			u8Data= DIO_DATA_ERROR;
			break;
		}
	}
	return u8Data;
}

void DIO_vidEnableInt(uint8 u8IntNum)
{
	switch (u8IntNum)
	{
	case 0:
		Set_Bit(GICR,6);
		break;
	case 1:
		Set_Bit(GICR,7);
		break;
	case 2:
		Set_Bit(GICR,5);
		break;
	default:
		break;
	}

}
void DIO_vidDisableInt(uint8 u8IntNum)
{
	switch (u8IntNum)
	{
	case 0:
		Clear_Bit(GICR,6);
		break;
	case 1:
		Clear_Bit(GICR,7);
		break;
	case 2:
		Clear_Bit(GICR,5);
		break;
	default:
		break;
	}

}
static void dummy (){}

static void (*pfun_low[3])(void)= {dummy,dummy,dummy};
static void (*pfun_rise[3])(void)= {dummy,dummy,dummy};
static void (*pfun_fall[3])(void)= {dummy,dummy,dummy};
static void (*pfun[3])(void)= {dummy,dummy,dummy};


void DIO_vidSetCallback_Low(uint8 u8IntNum , void  (*fun)(void))
{
	pfun_low [u8IntNum] = fun;
}
void DIO_vidSetCallback_Rising(uint8 u8IntNum , void  (*fun)(void))
{
	pfun_rise [u8IntNum] = fun;
}
void DIO_vidSetCallback_Falling(uint8 u8IntNum , void  (*fun)(void))
{
	pfun_fall [u8IntNum] = fun;
}
void DIO_vidSetCallback_AnyChange(uint8 u8IntNum , void  (*fun)(void))
{
	pfun [u8IntNum] = fun;
}
ISR(INT0_VECTOR_NUM)
{

	pfun[0]();
	if(Get_Bit(PIND,2))
	{

		pfun_rise[0]();
	}
	else
	{

		pfun_fall[0]();
	}
}
ISR(INT1_VECTOR_NUM)
{
	pfun[1]();
	if(Get_Bit(PIND,3))
	{
		pfun_rise[1]();
	}
	else
	{
		pfun_fall[1]();
	}
}
ISR(INT2_VECTOR_NUM)
{
	pfun[2]();
	if(Get_Bit(PINB,2))
	{
		pfun_rise[2]();
	}
	else
	{
		pfun_fall[2]();
	}
}
