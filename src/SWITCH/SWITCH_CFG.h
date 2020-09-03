/*
 * SWITCH_CFG.h
 *
 *  Created on: Dec 21, 2019
 *      Author: Ahmed Rashad
 */

#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_


enum SWITCH_STATE{
	Released	=0,
	Pushed		=1,
	PreReleased =2,
	PrePushed	=3,
	SWITCH_STATE_Error
};



#define PULLUP		0
#define PULLDOWN 	1





#define SWITCH_CONNECTION	PULLDOWN
#define SENS_COUNT  3
#define PBN_COUNT	1

#define PBN_0	PORTD_0
#define PBN_1	PORTD_1
#define PBN_2	PORTD_2


#endif /* SWITCH_CFG_H_ */
