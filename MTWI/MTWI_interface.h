/*
 * MTWI_interface.h
 *
 *  Created on: Nov 2, 2024
 *      Author: Asteroid
 */

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

void MTWI_InitSlave(u8 Copy_u8SlaveAddress);
void MTWI_InitMaster(u8 Copy_u8SlaveAddress);

void MTWI_voidSendStartCondition();
void MTWI_voidSendStopCondition();

void MTWI_voidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
void MTWI_voidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

void MTWI_voidSendData(u8 Copy_u8Data);
u8 MTWI_u8ReceiveData();
#endif /* MTWI_INTERFACE_H_ */
