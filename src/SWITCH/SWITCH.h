/*
 * SWITCH.h
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "SWITCH_CFG.h"

void SW_vidFlag (uint8 PBN_no,uint8 * u8PTRtoFlag);
void SW_vidInit(void);
void SW_vidTask(void);
uint8 SW_u8Read(uint8 u8i);


#endif /* SWITCH_H_ */
