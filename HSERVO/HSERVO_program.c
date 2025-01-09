/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MDIO/MDIO_interface.h"
#include "../MTMR1/MTMR1_interface.h"

/* HAL Layer */
#include "HSERVO_interface.h"
#include "HSERVO_private.h"
#include "HSERVO_config.h"


void HSERVO_Init(){
	MTMR1_voidSet_ICR1_value(2499);
	MTMR1_voidSet_OCR1A_Value(HSERVO_ZERO_ANGLE_VAL);
}
void HSERVO_voidSetAngle(u8 Copy_u8Angle){
	u16 Local_u16_OCR1A_Val;
	Local_u16_OCR1A_Val = (u16)(((HSERVO_180_ANGLE_VAL - HSERVO_ZERO_ANGLE_VAL) / 180.0) * Copy_u8Angle + HSERVO_ZERO_ANGLE_VAL);
	MTMR1_voidSet_OCR1A_Value(Local_u16_OCR1A_Val);
}
