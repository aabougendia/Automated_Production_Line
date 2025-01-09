/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"

#define F_CPU 8000000U
#include <avr/delay.h>

/* MCAL Layer */
#include "../MDIO/MDIO_interface.h"

/* HAL Layer */
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"


void HLCD_Init(void){
	/* delay after power on */
	_delay_ms(31);

	/* Send function set command */
	HLCD_voidWriteCmd(0x02);	// 4-bit mode
	HLCD_voidWriteCmd(0x28);

	/* delay after function set */
	_delay_ms(5);

	/* Send display ON/OFF control Command */
	HLCD_voidWriteCmd(0x0C);	// Display is ON, Cursor is displayed, Cursor blinks

	/* delay after display ON/OFF */
	_delay_ms(5);

	/* Send Display Clear Command */
	HLCD_voidWriteCmd(0x01);
	_delay_ms(5);

	/* Send Entry Mode Set Command */
	HLCD_voidWriteCmd(0x06);		// display won't shift while writing

}


void HLCD_voidWriteCmd(u8 Copy_u8Cmd){
	/* Rs pin = 0  :  Select Command Register */
	MDIO_u8SetPinValue(HLCD_RS_PORT, HLCD_RS_PIN, MDIO_LOW);

	/* R/W pin = 0 : Write operation */
	MDIO_u8SetPinValue(HLCD_RW_PORT, HLCD_RW_PIN, MDIO_LOW);

	/* Enable pin = High */
	MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);


	/* Write Command */

	u8 Local_u8PrevPortVal;
	MDIO_u8GetPortValue(HLCD_DATA_PORT, &Local_u8PrevPortVal);

	u8 Local_u8UpperNibble = (Copy_u8Cmd & 0xF0) | (Local_u8PrevPortVal & 0x0F);
	u8 Local_u8LowerNibble = (Copy_u8Cmd << 4) | (Local_u8PrevPortVal & 0x0F);

    /* Send the higher nibble */
    MDIO_u8SetPortValue(HLCD_DATA_PORT, Local_u8UpperNibble);

    /* Toggle the Enable pin */
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);
    _delay_ms(5);
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_LOW);

    /* Wait for the upper nibble to be processed */
    _delay_ms(5);

    /* Send the lower nibble */
    MDIO_u8SetPortValue(HLCD_DATA_PORT, Local_u8LowerNibble);

    /* Toggle the Enable pin */
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);
    _delay_ms(5);
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_LOW);

}


void HLCD_voidWriteChar(u8 Copy_u8Char){
	/* Rs pin = 1  :  Select Data Register */
	MDIO_u8SetPinValue(HLCD_RS_PORT, HLCD_RS_PIN, MDIO_HIGH);

	/* R/W pin = 0 : Write operation */
	MDIO_u8SetPinValue(HLCD_RW_PORT, HLCD_RW_PIN, MDIO_LOW);

	/* Enable pin = High */
	MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);

	/* Write Char */

	u8 Local_u8PrevPortVal;
	MDIO_u8GetPortValue(HLCD_DATA_PORT, &Local_u8PrevPortVal);

	u8 Local_u8UpperNibble = (Copy_u8Char & 0xF0) | (Local_u8PrevPortVal & 0x0F);
	u8 Local_u8LowerNibble = (Copy_u8Char << 4) | (Local_u8PrevPortVal & 0x0F);

    /* Send the higher nibble */
    MDIO_u8SetPortValue(HLCD_DATA_PORT, Local_u8UpperNibble);

    /* Toggle the Enable pin */
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);
    _delay_ms(5);
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_LOW);

    /* Wait for the upper nibble to be processed */
    _delay_ms(5);

    /* Send the lower nibble */
    MDIO_u8SetPortValue(HLCD_DATA_PORT, Local_u8LowerNibble);

    /* Toggle the Enable pin */
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_HIGH);
    _delay_ms(5);
    MDIO_u8SetPinValue(HLCD_EN_PORT, HLCD_EN_PIN, MDIO_LOW);

}



u8 HLCD_u8SetCursor(u8 Copy_u8LineNum, u8 Copy_u8CharNum){
	u8 Local_u8ErrorState = STD_TYPE_OK;
	if(Copy_u8CharNum < 40){
		switch(Copy_u8LineNum){
		case HLCD_LINE_1:
			HLCD_voidWriteCmd(0x80 + Copy_u8CharNum);
			break;
		case HLCD_LINE_2:
			HLCD_voidWriteCmd(0xC0 + Copy_u8CharNum);
			break;
		default:
			Local_u8ErrorState = STD_TYPE_NOK;
		}
	}
	else {
		Local_u8ErrorState = STD_TYPE_NOK;
	}

	return Local_u8ErrorState;
}

void HLCD_voidWriteString(u8* Copy_Pu8String){
	u8 Local_u8Index = 0;

	while(Copy_Pu8String[Local_u8Index] != '\0'){
		HLCD_voidWriteChar(Copy_Pu8String[Local_u8Index]);
		Local_u8Index++;
		//_delay_ms(200);
	}
}

void HLCD_voidWriteNumber(u16 Copy_u16Num){
	u32 Local_u32ReversedNum = 1;
	if(Copy_u16Num == 0){
		HLCD_voidWriteChar('0');
	}
	else{
		while(Copy_u16Num != 0){
			Local_u32ReversedNum  = Local_u32ReversedNum * 10 + Copy_u16Num % 10;
			Copy_u16Num /= 10;
		}

		while(Local_u32ReversedNum / 10 != 0){
			HLCD_voidWriteChar((Local_u32ReversedNum % 10) + '0');
			Local_u32ReversedNum /= 10;
		}
	}
}


void HLCD_voidWriteSpecialChar(u8* Copy_Pu8Char, u8 Copy_u8AddressLocation, u8 Copy_u8LineNum, u8 Copy_u8CharNum){
	u8 Local_u8Counter;

	/* Send command to make the address counter points to Address Location */
	HLCD_voidWriteCmd(0x40 + (8 * Copy_u8AddressLocation));

	/* Draw Char in memory (CGRAM) */
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++){
		HLCD_voidWriteChar(Copy_Pu8Char[Local_u8Counter]);
	}

	/* set the address counter back to the DDRAM on the passed position */
	HLCD_u8SetCursor(Copy_u8LineNum, Copy_u8CharNum);

	/* Display the Special Character on the LCD by passing the address 0 (where we stored the special character) */
	HLCD_voidWriteChar(Copy_u8AddressLocation);
}

void HLCD_voidClearDisplay(){
	HLCD_voidWriteCmd(0x01);
	_delay_ms(5);
}












