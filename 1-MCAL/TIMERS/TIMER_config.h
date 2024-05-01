/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 16/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*
 	options :
 	- NORMAL
 	- PWM_PHASE_CORRECT
 	- CTC
 	- FAST_PWM
*/
#define TIMER0_MODE			CTC

//--------------------------------------------------------------------

/*
 	options :
 	- DISCONNECTED
 	- TOGGLE
 	- CLR
 	- SET
*/
#define  CTC_OUTPUT_MODE	DISCONNECTED

//--------------------------------------------------------------------

/*
 	options :
 	- NO_CLOCK_SOURCE
 	- NO_PRESCALER_FACTOR
 	- DIVISION_FACTOR_8
 	- DIVISION_FACTOR_64
 	- DIVISION_FACTOR_256
 	- DIVISION_FACTOR_1024
 	- EXTERNAL_CLOCK_SOURCE_FALLING
 	- EXTERNAL_CLOCK_SOURCE_RISING
*/

#define TIMER0_PRESCALLER	DIVISION_FACTOR_8

//--------------------------------------------------------------------

#define TIMER0_PRELOAD_VALUE		0
#define CTC_COMPARE_VALUE			250
#define CTC_NOTIFICATIONS_NUMBER	400

//--------------------------------------------------------------------

/*
 	options :
 	- ENABLE
 	- DISABLE
*/

#define TIMER0_OVERFLOW_INTERRUPT_STATE		DISABLE

//--------------------------------------------------------------------

/*
 	options :
 	- ENABLE
 	- DISABLE
*/

#define CTC_INTERRUPT_STATE		ENABLE

//--------------------------------------------------------------------




#endif
