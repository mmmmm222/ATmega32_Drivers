/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 16/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define OC0 DIO_u8PIN3

//------------------------------------------------------

#define PRESCALLER_MASK					0b11111000
#define NO_CLOCK_SOURCE              	0b00000000
#define NO_PRESCALER_FACTOR             0b00000001
#define DIVISION_FACTOR_8               0b00000010
#define DIVISION_FACTOR_64              0b00000011
#define DIVISION_FACTOR_256             0b00000100
#define DIVISION_FACTOR_1024            0b00000101
#define EXTERNAL_CLOCK_SOURCE_FALLING   0b00000110
#define EXTERNAL_CLOCK_SOURCE_RISING    0b00000111

//--------------------------------------------------------

#define ENABLE 		1
#define DISABLE 	0

#define NORMAL					1
#define PWM_PHASE_CORRECT       2
#define CTC                     3
#define FAST_PWM                4

#define DISCONNECTED            5
#define TOGGLE                  6
#define CLR                     7
#define SET                     8


#endif

