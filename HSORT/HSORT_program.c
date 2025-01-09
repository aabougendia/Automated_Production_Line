/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#define F_CPU 8000000U
#include <util/delay.h>

/* MCAL Layer */
#include "../MDIO/MDIO_interface.h"

/* HAL Layer */
#include "../HSERVO/HSERVO_interface.h"

#include "HSORT_interface.h"
#include "HSORT_private.h"
#include "HSORT_config.h"


void HSORT_Init(){
	HSERVO_Init();
	MTMR1_Init();
	MTMR1_voidSet_OCR1B_value(1500);
}
u8 HSORT_GetIRValue()
{
	u8* Sort_Port_Value;
	MDIO_u8GetPortValue(SORT_PORT,Sort_Port_Value);
	return (*Sort_Port_Value) & IR_MASK;

}

u8 HSORT_GetIRSValue(){

	u8 Local_u8IRSPinVal;
	MDIO_u8GetPinValue(IRS_PORT, IRS_OUT, &Local_u8IRSPinVal);

	return Local_u8IRSPinVal;
}

void HSORT_ServoAct(u8 Servo_Num)
{
	u8 Sort_Port_Value = 0x00;

	switch(Servo_Num)
	{
	case SERVO0:
		(Sort_Port_Value) &= ~(SERVO_MASK);
		(Sort_Port_Value) |= SERVO0_ACTIVE;
		break;
	case SERVO1:
		(Sort_Port_Value) &= ~(SERVO_MASK);
		(Sort_Port_Value) |= SERVO1_ACTIVE;
		break;
	case SERVO2:
		(Sort_Port_Value) &= ~(SERVO_MASK);
		(Sort_Port_Value) |= SERVO2_ACTIVE;
		break;
	}

	MDIO_u8SetPortValue(SORT_PORT, Sort_Port_Value);
	_delay_ms(50);

	HSERVO_voidSetAngle(180);
	_delay_ms(1000);
	HSERVO_voidSetAngle(0);
	_delay_ms(1000);

	MDIO_u8SetPortValue(SORT_PORT, SERVO_INACTIVE);
}


void HSORT_DCOn()
{
	MDIO_u8SetPinValue(SORT_PORT, DC_CTRL, MDIO_HIGH);
}


void HSORT_DCOff()
{
	MDIO_u8SetPinValue(SORT_PORT, DC_CTRL, MDIO_LOW);
}


