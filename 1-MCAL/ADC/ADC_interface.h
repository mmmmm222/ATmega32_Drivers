/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_interface.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Karem Zamel
 *  Layer  : MCAL
 *  SWC    : ADC
 *
 */ 
 

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct 
{
	u8*  Channel ;
	u16* Result  ;
	u8   Size    ;
	void (*NotificationFunc)(void);
}Chain_t ;

void ADC_voidInit               ( void                                                                             );
u8   ADC_u8GetResultSync        ( u8 Copy_u8Channel , u16* Copy_pu16Result                                         );
u8   ADC_u8StartConversionAsynch( u8 Copy_u8Channel , u16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) );
u8   ADC_u8StartChainAsynch     ( Chain_t * Copy_Chain);

void ADC_voidEnable           (void);
void ADC_voidDisable          (void);
void ADC_voidInterruptEnable  (void);
void ADC_voidInterruptDisable (void);

u8 ADC_u8SetPrescaler (u8 Copy_u8Prescaler);
s32 Map(s32 MinInput , s32 MaxInput , s32 MinOutput , s32 MaxOutput ,s32 ReadValue);

#endif /* ADC_INTERFACE_H_ */
