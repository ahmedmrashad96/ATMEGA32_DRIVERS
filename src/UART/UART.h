/*
 * UART.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Ahmed Rashad
 */

#ifndef UART_H_
#define UART_H_

#include "UART_CFG.h"

void UART_vidInit(void);
void UART_vidSendChar(uint8 u8Data);
uint8 UART_u8RecieveChar(void);
uint8 UART_u8DataReady();
uint8 UART_u8GetUdr();
void UART_vidSendString(uint8 u8Data[], uint8 length);
void _Debug(int8 u8Data[]);
void UART_vidRecieveString(uint8 u8Data[], uint8* length);

#endif /* UART_H_ */
