/**************************************************************************/
/*******************    Author : Mohamed ali saber   **********************/
/*******************    Layer  : HAL                 **********************/
/*******************    Component: KEYPAD              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 27/11/2023            **********************/
/**************************************************************************/

#include "STD_TYPES.h" //first include ever
/*here we are in HAL so we include files from MCAL*/

/* but we don't include PORT because the main only will include it*/

/* we include the interface file only*/

#include "DIO_interface.h"

/*then we include our component files*/

#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"


u8 KEYPAD_u8GetPressedKey(void)
{
	/*the only variable in our program which carry the value of the pressed key BUT in the beginning it carries the value which the user choosed to indicate the is no pressed key until it change */
	u32 Local_u8PressedKey = KEYPAD_NO_PRESSED_KEY ;
	u8 Local_u8PinState;
	/*defining the array which has the values of our kpd*/
	static u8 Local_u8KEYPADArr[ROW_NUMBER][COLUMN_NUMBER] = KEYPAD_ARR_VALUES;
	/*the iterators of the two for loops on for column the other for rows*/
	u8 Local_u8ColumnIndix = 0;
	u8 Local_u8RowIndix = 0;
	/* get the pins which the user connected his kpd to on the mcu to loop on them to activate the columns on by one and read the rows to know which reads low */
	static u8 Local_u8ColumnArr[COLUMN_NUMBER] = {KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
	static u8 Local_u8RowArr[ROW_NUMBER] = {KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};

	for(Local_u8ColumnIndix = 0; Local_u8ColumnIndix < COLUMN_NUMBER; Local_u8ColumnIndix++)
	{
		/*first step to activate current coulum by set in to low*/
		DIO_u8SetPinValue(KEYPAD_PORT,Local_u8ColumnArr[Local_u8ColumnIndix],DIO_u8PIN_LOW);

		for(Local_u8RowIndix=0; Local_u8RowIndix<ROW_NUMBER; Local_u8RowIndix++)
		{
			DIO_u8GetPinValue(KEYPAD_PORT,Local_u8RowArr[Local_u8RowIndix],&Local_u8PinState);

			/*check if the switch is pressed*/
			if(DIO_u8PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KEYPADArr[Local_u8RowIndix][Local_u8ColumnIndix];
				/*polling => type of busy waiting*/
				/*here i want the program to recall the getpin func. while the user is pushing the key */
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KEYPAD_PORT,Local_u8RowArr[Local_u8RowIndix],&Local_u8PinState);
				}
				/* the program will return the value when the user pullup his hand from the switch*/
				return Local_u8PressedKey;
			}
		}

		/*DeActivate the current column*/
		DIO_u8SetPinValue(KEYPAD_PORT,Local_u8ColumnArr[Local_u8ColumnIndix],DIO_u8PIN_HIGH);

	}

	return Local_u8PressedKey;
}