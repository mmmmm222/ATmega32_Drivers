/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 16/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void TIMER0_voidInit(void);

u8 Timer0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void));

#endif

