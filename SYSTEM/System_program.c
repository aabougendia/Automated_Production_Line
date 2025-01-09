/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#define F_CPU 8000000U
#include <util/delay.h>

/* MCAL Layer */
#include "../MDIO/MDIO_interface.h"
#include "../MTMR1/MTMR1_interface.h"
#include "../MTWI/MTWI_interface.h"
#include "../MGIE/MGIE_interface.h"
#include "../MTMR0/MTMR0_interface.h"
#include "../MEXTI/MEXTI_interface.h"
#include "../MTMR2/MTMR2_interface.h"

/* HAL Layer */
#include "../HSERVO/HSERVO_interface.h"
#include "../HLCD/HLCD_interface.h"
#include "../HKPD/HKPD_interface.h"
#include "../HEEPROM/HEEPROM_interface.h"
#include "../HSORT/HSORT_interface.h"
#include "../HTCS3200/HTCS3200_interface.h"


#include "System_interface.h"

SystemStatus System_eStateFlag = SYSTEM_RUNNING;

u8 System_u8NumOfObjects = 0;
u16 System_u16TimeSorting = 0;
u8 System_u8NumOfErrors = 0;

Color DetectObjectColor(){

	while(HSORT_GetIRSValue() == IRS_INACTIVE){
		_delay_ms(20);
		u8 input = HKPD_NO_KEY_PRESSED;
		HKPD_u8GetPressedKey(&input);
		if(input == '4'){
			System_eStateFlag = SYSTEM_PAUSED;
			break;
		}
	}

	_delay_ms(400);
	HSORT_DCOff();

	HTCS3200_voidEnable();

	_delay_ms(100);
	Color Local_eOutputColor = HTCS3200_eGetColor();
//	ShowColor(Local_eOutputColor);

	_delay_ms(100);
	HTCS3200_voidDisable();

	HSORT_DCOn();

	return Local_eOutputColor;
}

void IncrementTime(){
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;

	if(Local_u16Counter == 4000){
		System_u16TimeSorting++;
		Local_u16Counter = 0;
	}

}

void CalculateTime(){
	MTMR2_Interrupt(MTMR2_OVF, MTMR2_Enable);
	MTMR2_OVF_SetCallback(IncrementTime);
}


void LogNumOfObjects()
{
	HEEPROM_voidWriteByte(HEEPROM_DEVICE1, 200, System_u8NumOfObjects);
}
void LogTimeSpentSorting()
{
	HEEPROM_voidWriteByte(HEEPROM_DEVICE1, 220, System_u16TimeSorting);
}
void LogNumOfErrors()
{
	HEEPROM_voidWriteByte(HEEPROM_DEVICE1, 250, System_u8NumOfErrors);
}

void SystemRunningLedOn()
{
	MDIO_u8SetPinValue(ALERTS_PORT, RUNNING_LED_PIN, MDIO_HIGH);
}
void SystemRunningLedOff()
{
	MDIO_u8SetPinValue(ALERTS_PORT, RUNNING_LED_PIN, MDIO_LOW);
}

void SystemPausedLedOn()
{
	MDIO_u8SetPinValue(ALERTS_PORT, PAUSED_LED_PIN, MDIO_HIGH);
}
void SystemPausedLedOff()
{
	MDIO_u8SetPinValue(ALERTS_PORT, PAUSED_LED_PIN, MDIO_LOW);
}

void SystemErrorLedOn()
{
	MDIO_u8SetPinValue(ALERTS_PORT, ERROR_LED_PIN, MDIO_HIGH);
}
void SystemErrorLedOff()
{
	MDIO_u8SetPinValue(ALERTS_PORT, ERROR_LED_PIN, MDIO_LOW);
}

void SystemBuzzerOn()
{
	MDIO_u8SetPinValue(ALERTS_PORT, BUZZER_PIN, MDIO_HIGH);
}
void SystemBuzzerOff()
{
	MDIO_u8SetPinValue(ALERTS_PORT, BUZZER_PIN, MDIO_LOW);
}
