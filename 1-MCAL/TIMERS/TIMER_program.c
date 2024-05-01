	/*
	 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_program.c   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	 *
	 *  Author  : Mohamed Ali Saber
	 *  Date    : 16/3/2024
	 *  Version : V_1.00
	 *  Layer   : MCAL
	 *
	 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "Timer_register.h"

static void (*GlobalpvCallbackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
	#if TIMER0_MODE == CTC

		CLR_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);
		OCR0 = CTC_COMPARE_VALUE;
		#if CTC_INTERRUPT_STATE == ENABLE
			SET_BIT(TIMSK,TIMSK_OCIE0);

		#elif CTC_INTERRUPT_STATE == DISBLE
			CLR_BIT(TIMSK,TIMSK_OCIE0);

		#else
		#error "Wrong CTC INERRUPT STATE choice"

		#endif

		#if CTC_OUTPUT_MODE == TOGGLE

		#elif CTC_OUTPUT_MODE == DISCONNECTED

		#elif CTC_OUTPUT_MODE == SET


		#elif CTC_OUTPUT_MODE == CLR

		#else
		#error "Wrong CTC MODE choice"

		#endif
//----------------------
	#elif TIMER0_MODE == NORMAL
		CLR_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);
		TCNT0 = TIMER0_PRELOAD_VALUE;
		#if TIMER0_OVERFLOW_INTERRUPT_STATE == ENABLE
			SET_BIT(TIMSK,TIMSK_TOIE0);
		#elif TIMER0_OVERFLOW_INTERRUPT_STATE == DISBLE
			CLR_BIT(TIMSK,TIMSK_TOIE0);
		#else
			#error "Wrong OVERFLOW INERRUPT STATE choice"

		#endif
//----------------------
	#elif TIMER0_MODE == FAST_PWM
		SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);

	#elif TIMER0_MODE == PWM_PHASE_CORRECT
		SET_BIT(TCCR0,TCCR0_WGM00);
		CLR_BIT(TCCR0,TCCR0_WGM01);

	#else
	#error "Wrong TIMER MODE choice"

	#endif

//------------------------------------------------------------------------------------

	//Set the Required Prescaler
	TCCR0 &= PRESCALLER_MASK;
	TCCR0 |= TIMER0_PRESCALLER;

//--------------------------------------------------------------------------

}
	u8 Timer0_u8SetCallBack(void(*Copy_pvCallBackFunc)(void))
	{
		u8 Local_u8ErrorStatus=OK;

		if(Copy_pvCallBackFunc != NULL)
		{
			GlobalpvCallbackFunc = Copy_pvCallBackFunc;
		}
		else
		{
			Local_u8ErrorStatus = NULL_POINTER;
		}

		return Local_u8ErrorStatus;
	}

//------------------------------------------------------------------------------

	void __vector_10 (void) __attribute__((signal));
	void __vector_10 (void)
	{
		static u16 Local_u16Counter = 0;
		Local_u16Counter++;
		if(Local_u16Counter == CTC_NOTIFICATIONS_NUMBER && GlobalpvCallbackFunc != NULL)
		{
			GlobalpvCallbackFunc();
			Local_u16Counter = 0;
		}

	}

