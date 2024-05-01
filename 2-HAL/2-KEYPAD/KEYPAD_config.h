/**************************************************************************/
/*******************    Author : Mohamed ali saber   **********************/
/*******************    Layer  : HAL                 **********************/
/*******************    Component: KEYPAD              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 27/11/2023            **********************/
/**************************************************************************/

/* pre peocessor file guard*/

#ifndef KEYPAD_config_H_
#define KEYPAD_config_H_

#define KEYPAD_PORT         	DIO_u8PORTB

/* here the user will select which pins on port(A) he will connect the 4 pins connected to the columns of the KPD  to*/
/*the columns is output high*/

#define KEYPAD_COLUMN0_PIN		DIO_u8PIN0
#define KEYPAD_COLUMN1_PIN		DIO_u8PIN1
#define KEYPAD_COLUMN2_PIN		DIO_u8PIN2
#define KEYPAD_COLUMN3_PIN		DIO_u8PIN3


/* here the user will select which pins on port(A) he will connect the 4 pins connected to the rows of the KPD  to*/
/*the rows is input pulled up*/
#define KEYPAD_ROW0_PIN			DIO_u8PIN4
#define KEYPAD_ROW1_PIN			DIO_u8PIN5
#define KEYPAD_ROW2_PIN			DIO_u8PIN6
#define KEYPAD_ROW3_PIN			DIO_u8PIN7

/* the value which the user select to indicate that the is no pressed key on the kpd*/
#define KEYPAD_NO_PRESSED_KEY	18

/* the user will select the values which will be return of every switch when pressed */
#define KEYPAD_ARR_VALUES		{{7,8,9,'/'},{4,5,6,'x'},{1,2,3,'-'},{'c',0,'=','+'}}

#endif
