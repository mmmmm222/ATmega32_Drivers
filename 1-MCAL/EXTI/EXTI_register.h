/**************************************************************************/
/*******************    Author : Mohammed Ali Saber  **********************/
/*******************    Layer  : MCAL                **********************/
/*******************    Component: EXTI              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 24/11/2023            **********************/
/**************************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/*HERE we get the register address */
#define GICR            *((volatile u8*)0x5B)
/*the pins which we are interested in inside this register*/
/**/
#define GICR_INT1       7
#define GICR_INT0       6
#define GICR_INT2       5

/*HERE we get the register address */
#define GIFR            *((volatile u8*)0x5A)

/*HERE we get the register address */
/*Interrupt Sense Control 0 & 1*/
#define MCUCR           *((volatile u8*)0x55)
/*the pins which we are interested in inside this register*/
#define MCUCR_ISC11     3
#define MCUCR_ISC10     2
#define MCUCR_ISC01     1
#define MCUCR_ISC00     0

/*HERE we get the register address */
/* Interrupt Sense Control 2 */
#define MCUCSR           *((volatile u8*)0x54)
/*the pins which we are interested in inside this register*/
#define MCUCSR_INT2       6


#endif
