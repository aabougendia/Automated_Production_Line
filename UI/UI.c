//Library includes
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#define F_CPU 8000000U
#include <util/delay.h>

//DIO includes
#include "../MDIO/MDIO_interface.h"

//LCD includes
#include "../HLCD/HLCD_interface.h"

//Keypad includes
#include "../HKPD/HKPD_interface.h"


#include "../HTCS3200/HTCS3200_interface.h"
#include "../SYSTEM/System_interface.h"

#include "../UI/UI.h"

void welcome(void){
	HLCD_voidWriteString("Welcome to our");
	HLCD_u8SetCursor(HLCD_LINE_2, 4);
	HLCD_voidWriteString("Project");

	_delay_ms(2000);
	HLCD_voidClearDisplay();
}

Color colour_4_basket_1(void){
	HLCD_voidWriteString("Choose color for");
	HLCD_u8SetCursor(HLCD_LINE_2, 0);
	HLCD_voidWriteString("Basket 1");

	_delay_ms(2000);
	HLCD_voidClearDisplay();

	HLCD_voidWriteString("1.RED  2.GREEN");
	HLCD_u8SetCursor(HLCD_LINE_2, 0);
	HLCD_voidWriteString("3.BLUE");


	u8 basket_1_color = HKPD_NO_KEY_PRESSED;

	while(basket_1_color == HKPD_NO_KEY_PRESSED){

		HKPD_u8GetPressedKey(&basket_1_color);
	}
	if(basket_1_color == '1'){
		return COLOR_RED;
	}
	else if(basket_1_color == '2')
		return COLOR_GREEN;
	else if(basket_1_color == '3')
		return COLOR_BLUE;
	}

Color colour_4_basket_2(void){
	HLCD_voidClearDisplay();
	HLCD_voidWriteString("Choose color for");
		HLCD_u8SetCursor(HLCD_LINE_2, 0);
		HLCD_voidWriteString("Basket 2");

		_delay_ms(2000);
		HLCD_voidClearDisplay();

		HLCD_voidWriteString("1.RED  2.GREEN");
		HLCD_u8SetCursor(HLCD_LINE_2, 0);
		HLCD_voidWriteString("3.BLUE");

		u8 basket_2_color = HKPD_NO_KEY_PRESSED;
		while(basket_2_color == HKPD_NO_KEY_PRESSED){
			HKPD_u8GetPressedKey(&basket_2_color);
		}
		if(basket_2_color == '1')
			return COLOR_RED;
		else if(basket_2_color == '2')
			return COLOR_GREEN;
		else if(basket_2_color == '3')
			return COLOR_BLUE;
		}

Color colour_4_basket_3(void){
	HLCD_voidClearDisplay();
	HLCD_voidWriteString("Choose color for");
		HLCD_u8SetCursor(HLCD_LINE_2, 0);
		HLCD_voidWriteString("Basket 3");

		_delay_ms(2000);
		HLCD_voidClearDisplay();

		HLCD_voidWriteString("1.RED  2.GREEN");
		HLCD_u8SetCursor(HLCD_LINE_2, 0);
		HLCD_voidWriteString("3.BLUE");

		u8 basket_3_color = HKPD_NO_KEY_PRESSED;
		while(basket_3_color == HKPD_NO_KEY_PRESSED){
			HKPD_u8GetPressedKey(&basket_3_color);
		}
		if(basket_3_color == '1')
			return COLOR_RED;
		else if(basket_3_color == '2')
			return COLOR_GREEN;
		else if(basket_3_color == '3')
			return COLOR_BLUE;
		}


void display_current_status(SystemStatus Copy_eStatus){
	if(Copy_eStatus == SYSTEM_RUNNING){
		HLCD_Init();
		HLCD_voidWriteString("SYSTEM RUNNING");
		HLCD_u8SetCursor(HLCD_LINE_2, 8);
		HLCD_voidWriteString("|4.Pause");
	}
	else if(Copy_eStatus == SYSTEM_PAUSED){
		HLCD_Init();
		HLCD_voidWriteString("SYSTEM PAUSED");
		HLCD_u8SetCursor(HLCD_LINE_2, 10);
		HLCD_voidWriteString("|4.Run");

	}
	else if (Copy_eStatus == SYSTEM_UNDEFINED_COLOR){
		HLCD_Init();
		HLCD_voidWriteString("UNDEFINED COLOR");
		HLCD_u8SetCursor(HLCD_LINE_2, 10);
		HLCD_voidWriteString("|4.Run");
	}
	else if (Copy_eStatus == SYSTEM_ERROR_SORTING){
		HLCD_Init();
		HLCD_voidWriteString("SORTING ERROR");
	}
}
void display_count(u8 count){
	HLCD_u8SetCursor(HLCD_LINE_2, 0);
	HLCD_voidWriteString("Count:");
	HLCD_voidWriteNumber(count);
}

