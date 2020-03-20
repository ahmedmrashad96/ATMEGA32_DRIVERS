/*
 * TIMER.h
 *
 *  Created on: Dec 10, 2019
 *      Author: Ahmed Rashad
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER_CFG.h"

void TIMER_vidInit();
void _delay_ms(uint16 U16Time);
void updatetime();
uint32 millis();

#endif /* TIMER_H_ */
