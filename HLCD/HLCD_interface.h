#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

#define HLCD_LINE_1			1
#define HLCD_LINE_2			2

#define HLCD_ADD_LOC_1		0
#define HLCD_ADD_LOC_2		1
#define HLCD_ADD_LOC_3		2
#define HLCD_ADD_LOC_4		3
#define HLCD_ADD_LOC_5	 	4
#define HLCD_ADD_LOC_6		5
#define HLCD_ADD_LOC_7		6
#define HLCD_ADD_LOC_8		7


void HLCD_Init(void);

u8 HLCD_u8SetCursor(u8 Copy_u8LineNum, u8 Copy_u8CharNum);

void HLCD_voidWriteCmd(u8 Copy_u8Cmd);
void HLCD_voidWriteChar(u8 Copy_u8Char);

void HLCD_voidWriteString(u8* Copy_Pu8String);
void HLCD_voidWriteNumber(u16 Copy_u16Num);
void HLCD_voidClearDisplay();

void HLCD_voidWriteSpecialChar(u8* Copy_Pu8Char, u8 Copy_u8AddressLocation, u8 Copy_u8LineNum, u8 Copy_u8CharNum);


#endif
