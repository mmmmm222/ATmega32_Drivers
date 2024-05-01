/**************************************************************************/
/*******************    Author : Mohammed Ali Saber  **********************/
/*******************    Layer  : MCAL                **********************/
/*******************    Component: EXTI              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 28/1/2024            **********************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"


/*global pointer to function*/
void (*EXTI_pvInt0Func)(void) = NULL;


void EXTI_voidInt0Init(void)
{
	/*set sense CTRL for INT0 to falling edge*/
	#if INT0_SENSE ==LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);

	#elif INT0_SENSE ==ON_CHANGE
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);

	#elif INT0_SENSE ==FALLING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);

	#elif INT0_SENSE ==RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);

	#else
	#error "wrong INT0 sense control choice"

	#endif

	/*configure the SEI for INT0*/

	#if INT0_INITIAL_STATUS == ENABLED
		SET_BIT(GICR ,GICR_INT0);

	#elif INT0_INITIAL_STATUS == DISABLED
		CLR_BIT(GICR ,GICR_INT0);

	#else
	#error "wrong configuration for SEI INT0"

	#endif
}


void EXTI_voidInt1Init(void)
{
	/*set sense CTRL for INT1 to falling edge*/
	#if INT1_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

	#elif INT1_SENSE == ON_CHANGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);

	#elif INT1_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);

	#elif INT1_SENSE == RISING_EDGE
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);

	#else
	#error "wrong INT0 sense control choice"

	#endif

	/*configure the SEI for INT0*/

		#if INT1_INITIAL_STATUS == ENABLED
			SET_BIT(GICR ,GICR_INT1);

		#elif INT1_INITIAL_STATUS == DISABLED
			CLR_BIT(GICR ,GICR_INT1);

		#else
		#error "wrong configuration for SEI INT0"

		#endif
}

void EXTI_voidInt2Init(void)
{
	/*set sense CTRL for INT2 to falling edge*/
	#if INT2_SENSE == FALLING_EDGE
		CLR_BIT(MCUCSR,MCUCSR_INT2);

	#elif INT2_SENSE == RISING_EDGE
		SET_BIT(MCUCSR,MCUCSR_INT2);

	#else
	#error "wrong INT0 sense control choice"

	#endif


	/*configure the SEI for INT0*/

		#if INT2_INITIAL_STATUS == ENABLED
			SET_BIT(GICR ,GICR_INT2);

		#elif INT2_INITIAL_STATUS == DISABLED
			CLR_BIT(GICR ,GICR_INT2);

		#else
		#error "wrong configuration for SEI INT0"

		#endif
}



u8 EXTI_u8Int0SetSenseCotrol(u8 Copy_u8Sense)
{
	u8 Local_u8Error = OK;

		switch (Copy_u8Sense)
		{

		case LOW_LEVEL:		CLR_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00);break;
		case ON_CHANGE: 	CLR_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00);break;
		case FALLING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00);break;
		case RISING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00);break;
		default:			Local_u8Error = NOK;

		}
	return Local_u8Error;
}

u8 EXTI_u8Int1SetSenseCotrol(u8 Copy_u8Sense)
{
	u8 Local_u8Error = OK;

		switch (Copy_u8Sense)
		{

		case LOW_LEVEL:		CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11);break;
		case ON_CHANGE: 	SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11);break;
		case FALLING_EDGE: 	CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11);break;
		case RISING_EDGE: 	SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11);break;
		default:			Local_u8Error = NOK;

		}
	return Local_u8Error;
}


u8 EXTI_u8Int2SetSenseCotrol(u8 Copy_u8Sense)
{
	u8 Local_u8Error = OK;
	switch (Copy_u8Sense)
		{

		case FALLING_EDGE: 	CLR_BIT(MCUCSR,MCUCSR_INT2);;break;
		case RISING_EDGE: 	SET_BIT(MCUCSR,MCUCSR_INT2);;break;
		default:			Local_u8Error = NOK;

		}
	return Local_u8Error;

}

u8 EXTI_u8IntEnable(u8 Copy_u8Int)
{
	u8 Local_u8Error = OK;
	switch(Copy_u8Int)
	{
	case INT0 :SET_BIT(GICR ,GICR_INT0);break;
	case INT1 :SET_BIT(GICR ,GICR_INT1);break;
	case INT2 :SET_BIT(GICR ,GICR_INT2);break;
	default   :Local_u8Error = NOK;
	}
	return Local_u8Error;
}



u8 EXTI_u8IntDisable(u8 Copy_u8Int)
{
	u8 Local_u8Error = OK;
		switch(Copy_u8Int)
		{
		case INT0 :CLR_BIT(GICR ,GICR_INT0);break;
		case INT1 :CLR_BIT(GICR ,GICR_INT1);break;
		case INT2 :CLR_BIT(GICR ,GICR_INT2);break;
		default   :Local_u8Error = NOK;
		}
		return Local_u8Error;

}

u8 EXTI_u8SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorStatus = OK;

	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func!= NULL)
	{
	EXTI_pvInt0Func();

	}
}
