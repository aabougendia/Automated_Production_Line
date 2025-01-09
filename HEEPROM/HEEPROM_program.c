/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#define F_CPU 8000000U
#include <util/delay.h>

/* MCAL Layer */
#include "../MTWI/MTWI_interface.h"

/* HAL Layer */
#include "HEEPROM_interface.h"


void HEEPROM_voidWriteByte(u8 Copy_u8Device, u16 Copy_u16Location, u8 Copy_u8Data){
	u8 Local_u8Address = (0b01010000) | (Copy_u8Device << 2) | (Copy_u16Location >> 8);

	/* Start Condition */
	MTWI_voidSendStartCondition();

	/* Send Slave Address to EEPROM Module */
	MTWI_voidSendSlaveAddressWithWrite(Local_u8Address);

	/* Send Byte location we want to write */
	MTWI_voidSendData((u8)Copy_u16Location);

	/* Send data to write on Byte location */
	MTWI_voidSendData(Copy_u8Data);

	/* Stop Condition */
	MTWI_voidSendStopCondition();

	/* Delay after write */
	_delay_ms(10);
}
u8 HEEPROM_u8ReadByte(u8 Copy_u8Device, u16 Copy_u16Location){

		u8 Local_u8Data;
		u8 Local_u8Address = (0b01010000) | (Copy_u8Device << 2) | (Copy_u16Location >> 8);

		MTWI_voidSendStartCondition();

		/* Send Slave Address to EEPROM Module */
		MTWI_voidSendSlaveAddressWithWrite(Local_u8Address);

		/* Send Byte location we want to write */
		MTWI_voidSendData((u8)Copy_u16Location);

		/* Repeated Start to read byte */
		MTWI_voidSendStartCondition();

		/* Send Slave Address to read */
		MTWI_voidSendSlaveAddressWithRead(Local_u8Address);

		/* Read data */
		Local_u8Data = MTWI_u8ReceiveData();

		/* Stop Condition */
		MTWI_voidSendStopCondition();

		/* Return data */
		return Local_u8Data;

}
