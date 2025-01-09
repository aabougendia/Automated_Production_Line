#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H

//#define MEXTI_INT0                  0
//#define MEXTI_INT1                  1
//#define MEXTI_INT2                  2
//
//#define MEXTI_FALLING_EDGE          0
//#define MEXTI_RISING_EDGE           1
//#define MEXTI_LOW_LEVEL             2
//#define MEXTI_ANY_LOGICAL_CHANGE    3


typedef enum {
	MEXTI_INT0 = 0,
	MEXTI_INT1,
	MEXTI_INT2
} MEXTI_IntNum;

typedef enum {
	MEXTI_FALLING_EDGE = 0,
	MEXTI_RISING_EDGE,
	MEXTI_LOW_LEVEL,
	MEXTI_ANY_LOGICAL_CHANGE
} MEXTI_IntSrc;

u8 MEXTI_u8Enable(u8 Copy_u8ExtIntNum, u8 Copy_u8IntSrc);
u8 MEXTI_u8Disable(u8 Copy_u8ExtIntNum);

u8 MEXTI_voidSelectEdge(MEXTI_IntNum Copy_eIntNum, MEXTI_IntSrc Copy_eIntSrc);

u8 MEXTI_u8SetCallback(u8 Copy_u8ExtIntNum, void(*Copy_Pf)(void));
u8 MEXTI_u8GetEXTI0Flag();
void MEXTI_u8ClearEXTI0Flag();

#endif
