/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_Register.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 16/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


//--------------------------------------------------------------------------------

#define TCCR0 *((volatile u8 *)0x53)        /*Timer0 control register*/
#define TCCR0_CS00 	0                       /*Prescaler bit0*/
#define TCCR0_CS01 	1                       /*Prescaler bit1*/
#define TCCR0_CS02 	2                       /*Prescaler bit2*/
#define TCCR0_WGM01 3                       /*Waveform generation mode bit1*/
#define TCCR0_COM00 4						/*Compare Match Output (toggle , clr , set)*/
#define TCCR0_COM01 5						/*Compare Match Output (toggle , clr , set)*/
#define TCCR0_WGM00 6                       /*Waveform generation Mode bit0*/

//--------------------------------------------------------------------------------

#define TIMSK *((volatile u8 *)0x59)        /*Timer mask*/
#define TIMSK_TOIE0 0                       /*Timer Overflow Interrupt Enable*/
#define TIMSK_OCIE0 1                       /*Output compare 0 interrupt enable*/

//--------------------------------------------------------------------------------

#define OCR0 *((volatile u8 *)0x5C)         /*Output compare register 0 => the value which will be compared with TCNT0 in CTC mode*/

//--------------------------------------------------------------------------------

#define TCNT0 *((volatile u8 *)0x52)        // Timer Counting Register

//--------------------------------------------------------------------------------

#define TIFR *((volatile u8 *)0x58)        	// Timer mask
#define TIFR_TOV0	0						// Timer0 Overflow Flag
#define TIFR_OCF0	1						// CTC Compare Flag 0

//--------------------------------------------------------------------------------

#endif

