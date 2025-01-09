/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#define F_CPU 8000000U
#include <util/delay.h>

/* MCAL Layer */
#include "../MDIO/MDIO_interface.h"
#include "../MTMR0/MTMR0_interface.h"
#include "../MEXTI/MEXTI_interface.h"
#include "../MGIE/MGIE_interface.h"

/* HAL Layer */
#include "HTCS3200_interface.h"
#include "HTCS3200_private.h"
#include "HTCS3200_config.h"


volatile static u32 HTCS3200_u32TimerOVFCount = 0;

volatile static u32 HTCS3200_u16FirstReading;
volatile static u32 HTCS3200_u16SecondReading;


void HTCS3200_voidSetFilter(Sensor_Filter Copy_eFilter){

	switch(Copy_eFilter){
		case HTCS3200_FILTER_RED:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S2, MDIO_LOW);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S3, MDIO_LOW);
			break;
		case HTCS3200_FILTER_BLUE:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S2, MDIO_LOW);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S3, MDIO_HIGH);
			break;
		case HTCS3200_FILTER_CLEAR:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S2, MDIO_HIGH);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S3, MDIO_LOW);
			break;
		case HTCS3200_FILTER_GREEN:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S2, MDIO_HIGH);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S3, MDIO_HIGH);
			break;
	}
}

void HTCS3200_IncrementOVFs(){
	HTCS3200_u32TimerOVFCount++;
}

void HTCS3200_voidTakeReading(){
	static u8 Local_u8EdgeCount = 0;
	static u8 Local_u8ColorFlag = 0;	// Red: 0, Green: 1, Blue: 2

	Local_u8EdgeCount++;
	if(Local_u8EdgeCount == 1){
		HTCS3200_u32TimerOVFCount = 0;
	}
	else if(Local_u8EdgeCount == 2){
		HTCS3200_u16FirstReading = (HTCS3200_u32TimerOVFCount * 256) + MTMR0_GetTCNT0Value();
	}
	else if (Local_u8EdgeCount == 3){

		HTCS3200_u16SecondReading = (HTCS3200_u32TimerOVFCount * 256) + MTMR0_GetTCNT0Value();

		switch (Local_u8ColorFlag){
			case 0: // Red
				if(HTCS3200_u16SecondReading < HTCS3200_u16FirstReading){
					HTCS3200_u16RedPeriodicTime = (256 - HTCS3200_u16FirstReading) + HTCS3200_u16SecondReading;
				}
				else {
					HTCS3200_u16RedPeriodicTime = HTCS3200_u16SecondReading - HTCS3200_u16FirstReading;
				}

				HTCS3200_u8RedVal = HTCS3200_u8MapToRGB(HTCS3200_u16RedPeriodicTime, MIN_COLOR, MAX_COLOR);

				HTCS3200_voidSetFilter(HTCS3200_FILTER_GREEN);

				Local_u8ColorFlag = 1;
				break;

			case 1: // Green
				if(HTCS3200_u16SecondReading < HTCS3200_u16FirstReading){
					HTCS3200_u16GreenPeriodicTime = (256 - HTCS3200_u16FirstReading) + HTCS3200_u16SecondReading;
				}
				else {
					HTCS3200_u16GreenPeriodicTime = HTCS3200_u16SecondReading - HTCS3200_u16FirstReading;
				}

				HTCS3200_u8GreenVal = HTCS3200_u8MapToRGB(HTCS3200_u16GreenPeriodicTime, MIN_COLOR, MAX_COLOR);

				HTCS3200_voidSetFilter(HTCS3200_FILTER_BLUE);

				Local_u8ColorFlag = 2;
				break;

			case 2: // Blue
				if(HTCS3200_u16SecondReading < HTCS3200_u16FirstReading){
					HTCS3200_u16BluePeriodicTime = (256 - HTCS3200_u16FirstReading) + HTCS3200_u16SecondReading;
				}
				else {
					HTCS3200_u16BluePeriodicTime = HTCS3200_u16SecondReading - HTCS3200_u16FirstReading;
				}

				HTCS3200_u8BlueVal = HTCS3200_u8MapToRGB(HTCS3200_u16BluePeriodicTime, MIN_COLOR, MAX_COLOR);

				HTCS3200_voidSetFilter(HTCS3200_FILTER_RED);

				Local_u8ColorFlag = 0;
				break;
		}

		_delay_ms(100);
		Local_u8EdgeCount = 0;
		HTCS3200_u32TimerOVFCount = 0;
	}
}
void HTCS3200_Init(){
	switch(HTCS3200_FREQ_SCALE){
		case PRIVATE_SCALE_0:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S0, MDIO_LOW);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S1, MDIO_LOW);
			break;
		case PRIVATE_SCALE_2:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S0, MDIO_LOW);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S1, MDIO_HIGH);
			break;
		case PRIVATE_SCALE_20:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S0, MDIO_HIGH);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S1, MDIO_LOW);
			break;
		case PRIVATE_SCALE_100:
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S0, MDIO_HIGH);
			MDIO_u8SetPinValue(HTCS3200_PORT, HTCS3200_S1, MDIO_HIGH);
			break;
	}



	HTCS3200_voidSetFilter(HTCS3200_FILTER_RED);
	_delay_ms(100);

	MTMR0_OVF_SetCallback(HTCS3200_IncrementOVFs);
	MEXTI_u8SetCallback(MEXTI_INT0, HTCS3200_voidTakeReading);

	MEXTI_u8Enable(MEXTI_INT0, MEXTI_RISING_EDGE);
	MTMR0_Interrupt(MTMR0_OVF, MTMR0_Enable);

//	MGIE_voidEnable();

}

void HTCS3200_voidEnable(){
	MEXTI_u8Enable(MEXTI_INT0, MEXTI_RISING_EDGE);
	MTMR0_Interrupt(MTMR0_OVF, MTMR0_Enable);
}
void HTCS3200_voidDisable(){
	MEXTI_u8Disable(MEXTI_INT0);
	MTMR0_Interrupt(MTMR0_OVF, MTMR0_Disable);
}

u8 HTCS3200_u8MapToRGB(u32 Copy_u32InputValue, u32 Copy_u32InputMin, u32 Copy_u32InputMax){

	if (Copy_u32InputValue <= Copy_u32InputMin) {
		return 255;
	} else if (Copy_u32InputValue >= Copy_u32InputMax) {
		return 0;
	} else {
		return 255UL - (u8)(((Copy_u32InputValue - Copy_u32InputMin) * 255UL) / (Copy_u32InputMax - Copy_u32InputMin));
	}

}


Color HTCS3200_eGetColor(){
	Color Local_eOutputColor;

	if((HTCS3200_u8RedVal > HTCS3200_u8GreenVal) && (HTCS3200_u8RedVal > HTCS3200_u8BlueVal)){
		Local_eOutputColor = COLOR_RED;
	}
	else if ((HTCS3200_u8GreenVal > HTCS3200_u8RedVal) && (HTCS3200_u8GreenVal > HTCS3200_u8BlueVal)){
		Local_eOutputColor = COLOR_GREEN;
	}
	else if ((HTCS3200_u8BlueVal > HTCS3200_u8RedVal) && (HTCS3200_u8BlueVal > HTCS3200_u8GreenVal)){
		Local_eOutputColor = COLOR_BLUE;
	}
	else if ((HTCS3200_u8RedVal == 0) && (HTCS3200_u8GreenVal == 0) && (HTCS3200_u8BlueVal == 0)){
		Local_eOutputColor = OBJECT_NOT_FOUND;
	}
	else {
		Local_eOutputColor = COLOR_NOT_DEFINED;
	}

	return Local_eOutputColor;
}
