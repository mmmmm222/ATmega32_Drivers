/**************************************************************************/
/*******************    Author : Mohammed Ali Saber  **********************/
/*******************    Layer  : MCAL                **********************/
/*******************    Component: EXTI              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 24/11/2023            **********************/
/**************************************************************************/

#ifndef EXTI_config_H_
#define EXTI_config_H_
/*the configuration of the sense*/
/*options
 *
		 * low level
		 * on change
		 * falling edge
		 * rising edge
*
*/

#define INT0_SENSE		LOW_LEVEL
#define INT1_SENSE		FALLING_EDGE
#define INT2_SENSE		RISING_EDGE

/*the configuration of the SIE*/
/*options
		 * ENABLED
		 * DISABLED
*/
#define INT0_INITIAL_STATUS		ENABLED
#define INT1_INITIAL_STATUS		ENABLED
#define INT2_INITIAL_STATUS		DISABLED

#endif
