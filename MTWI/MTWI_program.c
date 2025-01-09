/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "MTWI_interface.h"
#include "MTWI_private.h"
#include "MTWI_config.h"

void MTWI_InitSlave(u8 Copy_u8SlaveAddress){
	/* Assign Slave address */
	TWAR = Copy_u8SlaveAddress;
	/* Enable Ack */
	SET_BIT(TWCR, TWCR_TWEA);
	/* Enable Peripheral */
	SET_BIT(TWCR, TWCR_TWEN);

}
void MTWI_InitMaster(u8 Copy_u8SlaveAddress){
	/* Assign Slave address */
	TWAR = Copy_u8SlaveAddress;
	/* Enable Ack */
	SET_BIT(TWCR, TWCR_TWEA);

	/* Set Prescaler (Freq)*/
	TWBR = 12;
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);

	/* Enable Peripheral */
	SET_BIT(TWCR, TWCR_TWEN);
}

void MTWI_voidSendStartCondition(){
	/* Set start condition bit */
	SET_BIT(TWCR, TWCR_TWSTA);

	/* Polling on flag */
	while(!(GET_BIT(TWCR, TWCR_TWINT)));


}
void MTWI_voidSendStopCondition(){
	/* Set stop condition bit */
	SET_BIT(TWCR, TWCR_TWSTO);
}

void MTWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress){
	/* Assign Slave Address we want to read (left 7-bits) */
	TWDR = Copy_u8SlaveAddress << 1;
	/* Select Read */
	SET_BIT(TWDR, 0);

	/* End start condition */
	CLR_BIT(TWCR, TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Waiting on flag */
	while(!(GET_BIT(TWCR, TWCR_TWINT)));

}
void MTWI_voidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress){
	/* Assign Slave Address we want to read (left 7-bits) */
	TWDR = Copy_u8SlaveAddress << 1;
	/* Select Write */
	CLR_BIT(TWDR, 0);

	/* End start condition */
	CLR_BIT(TWCR, TWCR_TWSTA);

	/* Clear Flag */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Waiting on flag */
	while(!(GET_BIT(TWCR, TWCR_TWINT)));
}

void MTWI_voidSendData(u8 Copy_u8Data){
	/* Send Action on Data Bus */
	TWDR = Copy_u8Data;

	/* Clear Flag */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Waiting on flag */
	while(!(GET_BIT(TWCR, TWCR_TWINT)));
}
u8 MTWI_u8ReceiveData(){

	/* Clear Flag */
	SET_BIT(TWCR, TWCR_TWINT);

	/* Waiting on flag */
	while(!(GET_BIT(TWCR, TWCR_TWINT)));

	return TWDR;
}
