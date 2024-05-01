/**************************************************************************/
/*******************    Author : Mohammed Ali Saber  **********************/
/*******************    Layer  : MCAL                **********************/
/*******************    Component: EXTI              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 24/11/2023            **********************/
/**************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define LOW_LEVEL   	1
#define ON_CHANGE   	2
#define FALLING_EDGE	3
#define RISING_EDGE		4

#define ENABLED 	1
#define DISABLED	2

#define INT0  1
#define INT1  2
#define INT2  3


void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

u8 EXTI_u8Int0SetSenseCotrol(u8 Copy_u8Sense);
u8 EXTI_u8Int1SetSenseCotrol(u8 Copy_u8Sense);
u8 EXTI_u8Int2SetSenseCotrol(u8 Copy_u8Sense);

u8 EXTI_u8IntEnable(u8 Copy_u8Int);
u8 EXTI_u8IntDisable(u8 Copy_u8Int);

u8 EXTI_u8SetCallBack(void(*Copy_pvInt0Func)(void));



#endif
