/*
 * LCD.h
 *
 *  Created on: Nov 16, 2019
 *      Author: Ahmed Rashad
 */

#ifndef LCD_H_
#define LCD_H_


#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"

#include "../DIO/DIO.h"

#include "LCD_CFG.h"




void LCD_vidTask (void);
void LCD_vidInit();
void LCD_vidWrite( uint8 u8Data);
void LCD_vidGotoXY(uint8 x , uint8 y);
void LCD_vidString (int8 I8String[]);
void lcd_vidClear();

#endif /* LCD_H_ */
