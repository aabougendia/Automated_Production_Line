#ifndef HEEPROM_INTERFACE_H_
#define HEEPROM_INTERFACE_H_

#define HEEPROM_DEVICE1		0
#define HEEPROM_DEVICE2		1

void HEEPROM_voidWriteByte(u8 Copy_u8Device, u16 Copy_u16Location, u8 Copy_u8Data);
u8 HEEPROM_u8ReadByte(u8 Copy_u8Device, u16 Copy_u16Location);

#endif /* HEEPROM_INTERFACE_H_ */
