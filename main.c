/* LIB Layer */
#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#define F_CPU 8000000U
#include <util/delay.h>

/* MCAL Layer */
#include "MDIO/MDIO_interface.h"
#include "MTMR1/MTMR1_interface.h"
#include "MTWI/MTWI_interface.h"
#include "MGIE/MGIE_interface.h"
#include "MTMR0/MTMR0_interface.h"
#include "MEXTI/MEXTI_interface.h"
#include "MTMR2/MTMR2_interface.h"

/* HAL Layer */
#include "HSERVO/HSERVO_interface.h"
#include "HLCD/HLCD_interface.h"
#include "HKPD/HKPD_interface.h"
#include "HEEPROM/HEEPROM_interface.h"
#include "HSORT/HSORT_interface.h"
#include "HTCS3200/HTCS3200_interface.h"

/* System & UI */
#include "SYSTEM/System_interface.h"
#include "UI/UI.h"

u16 display_time(){
	HLCD_Init();
	HLCD_u8SetCursor(HLCD_LINE_2, 0);
	HLCD_voidWriteNumber(System_u16TimeSorting);
}

int main(){
	MDIO_Init();
	MTMR0_Init();
//	MUART_Init();
	HTCS3200_Init();
	HSORT_Init();
	HLCD_Init();
	MTMR2_Init();
	MTWI_InitMaster(0);

	HTCS3200_voidDisable();
	MGIE_voidEnable();
	CalculateTime();


	Color Local_eBasketOneColor;
	Color Local_eBasketTwoColor;
	Color Local_eBasketThreeColor;

	welcome();
	Local_eBasketOneColor 	= colour_4_basket_1();
	Local_eBasketTwoColor 	= colour_4_basket_2();
	Local_eBasketThreeColor = colour_4_basket_3();


	u16 local_u16StartTime;
	u16 Local_u16EndTime;

	u8 local_u8PauseInput = HKPD_NO_KEY_PRESSED;

	while(1){


		switch(System_eStateFlag){
			case SYSTEM_RUNNING:

				HLCD_Init();
				display_current_status(System_eStateFlag);
				display_count(System_u8NumOfObjects);

				SystemRunningLedOn();
				SystemPausedLedOff();
				SystemErrorLedOff();

				HSORT_DCOn();

				Color Local_eOutputColor = DetectObjectColor();
				local_u16StartTime = System_u16TimeSorting;

				if(Local_eOutputColor == Local_eBasketOneColor){
					while(HSORT_GetIRValue() != IR0_ACTIVE){
						local_u8PauseInput = HKPD_NO_KEY_PRESSED;
						HKPD_u8GetPressedKey(&local_u8PauseInput);
						if(local_u8PauseInput == '4'){
							System_eStateFlag = SYSTEM_PAUSED;
							break;
						}

						if(System_u16TimeSorting - local_u16StartTime >= ERROR_WAIT_TIME){
							System_eStateFlag = SYSTEM_ERROR_SORTING;
							break;
						}
					}
					if(System_eStateFlag == SYSTEM_RUNNING){
						_delay_ms(200);
						HSORT_DCOff();
						HSORT_ServoAct(SERVO0);
						System_u8NumOfObjects++;
						LogNumOfObjects();
					}
				}
				else if(Local_eOutputColor == Local_eBasketTwoColor){
					while(HSORT_GetIRValue() != IR1_ACTIVE){
						local_u8PauseInput = HKPD_NO_KEY_PRESSED;
						HKPD_u8GetPressedKey(&local_u8PauseInput);
						if(local_u8PauseInput == '4'){
							System_eStateFlag = SYSTEM_PAUSED;
							break;
						}

						if(System_u16TimeSorting - local_u16StartTime >= ERROR_WAIT_TIME){
							System_eStateFlag = SYSTEM_ERROR_SORTING;
							break;
						}
					}
					if(System_eStateFlag == SYSTEM_RUNNING){
						_delay_ms(200);
						HSORT_DCOff();
						HSORT_ServoAct(SERVO1);
						System_u8NumOfObjects++;
						LogNumOfObjects();
					}
				}
				else if(Local_eOutputColor == Local_eBasketThreeColor){
					while(HSORT_GetIRValue() != IR2_ACTIVE){
						local_u8PauseInput = HKPD_NO_KEY_PRESSED;
						HKPD_u8GetPressedKey(&local_u8PauseInput);
						if(local_u8PauseInput == '4'){
							System_eStateFlag = SYSTEM_PAUSED;
							break;
						}

						if(System_u16TimeSorting - local_u16StartTime >= ERROR_WAIT_TIME){
							System_eStateFlag = SYSTEM_ERROR_SORTING;
							break;
						}
					}
					if(System_eStateFlag == SYSTEM_RUNNING){
						_delay_ms(200);
						HSORT_DCOff();
						HSORT_ServoAct(SERVO2);
						System_u8NumOfObjects++;
						LogNumOfObjects();
					}
				}
				else if (Local_eOutputColor == COLOR_NOT_DEFINED){

				}
			break;

			case SYSTEM_PAUSED:

				HSORT_DCOff();
				SystemPausedLedOn();
				SystemRunningLedOff();
				SystemErrorLedOff();

				HLCD_Init();
				display_current_status(System_eStateFlag);


				LogTimeSpentSorting();
				System_u16TimeSorting= 0;


				local_u8PauseInput = HKPD_NO_KEY_PRESSED;
				while(local_u8PauseInput == HKPD_NO_KEY_PRESSED){
					HKPD_u8GetPressedKey(&local_u8PauseInput);
				}
				if(local_u8PauseInput = '4'){
					System_eStateFlag = SYSTEM_RUNNING;
				}

			break;

			case SYSTEM_UNDEFINED_COLOR:
				HSORT_DCOff();
				SystemErrorLedOn();
				SystemRunningLedOff();
				SystemPausedLedOff();

				HLCD_Init();
				display_current_status(System_eStateFlag);

				LogTimeSpentSorting();
				System_u16TimeSorting= 0;

				System_u8NumOfErrors++;
				LogNumOfErrors();

				local_u8PauseInput = HKPD_NO_KEY_PRESSED;
				while(local_u8PauseInput == HKPD_NO_KEY_PRESSED){
					HKPD_u8GetPressedKey(&local_u8PauseInput);
				}
				if(local_u8PauseInput = '4'){
					System_eStateFlag = SYSTEM_RUNNING;
				}

			break;

			case SYSTEM_ERROR_SORTING:

				HSORT_DCOff();
				SystemErrorLedOn();
				SystemRunningLedOff();
				SystemPausedLedOff();

				HLCD_Init();
				display_current_status(System_eStateFlag);
				HLCD_u8SetCursor(HLCD_LINE_2, 7);
				HLCD_voidWriteString("|4.Silent");

				LogTimeSpentSorting();
				System_u16TimeSorting= 0;

				System_u8NumOfErrors++;
				LogNumOfErrors();

				local_u8PauseInput = HKPD_NO_KEY_PRESSED;
				while(local_u8PauseInput == HKPD_NO_KEY_PRESSED){

					SystemErrorLedOn();
					SystemBuzzerOn();
					_delay_ms(50);
					SystemErrorLedOff();
					SystemBuzzerOff();
					_delay_ms(70);

					HKPD_u8GetPressedKey(&local_u8PauseInput);
				}
				if(local_u8PauseInput = '4'){
					HLCD_u8SetCursor(HLCD_LINE_2, 7);
					HLCD_voidWriteString("   |4.Run");
					SystemErrorLedOn();
					SystemBuzzerOff();

				}
				local_u8PauseInput = HKPD_NO_KEY_PRESSED;
				while(local_u8PauseInput == HKPD_NO_KEY_PRESSED){
					HKPD_u8GetPressedKey(&local_u8PauseInput);
				}
				if(local_u8PauseInput = '4'){
					System_eStateFlag = SYSTEM_RUNNING;
				}
			break;

			default:
			break;

		}
	}
}

