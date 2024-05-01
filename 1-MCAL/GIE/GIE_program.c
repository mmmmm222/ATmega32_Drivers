/**************************************************************************/
/*******************    Author : Mohammed Ali Saber  **********************/
/*******************    Layer  : MCAL                **********************/
/*******************    Component: EXTI              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 24/11/2023            **********************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG ,SREG_I);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG ,SREG_I);
}
