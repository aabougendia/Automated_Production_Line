/*
 * TMR0_interface.h
 *
 *  Created on: Nov 30, 2024
 *      Author: Asteroid
 */

#ifndef MTMR1_INTERFACE_H_
#define MTMR1_INTERFACE_H_


typedef enum {
	MTMR1_Disable = 0,
	MTMR1_Enable = 1
} TMR1_Interrupt_Mode;


/*****************          Timer 1           ********************/

typedef enum {
	MTMR1_OVF = 0,
	MTMR1_CTC_A = 1,
	MTMR1_CTC_B = 2
} Timer1_Modes;


void MTMR1_Init();
void MTMR1_setPreload(u16 Copy_u16PreloadValue);
void MTMR1_Interrupt(Timer1_Modes Copy_TimerMode, TMR1_Interrupt_Mode Copy_IntMode);
void MTMR1_voidSet_OCR1A_Value(u16 Copy_u16_OCR1A_Value);
void MTMR1_voidSet_OCR1B_value(u16 Copy_u16_OCR1B_Value);
void MTMR1_voidSet_ICR1_value(u16 Copy_u16_ICR1_Value);
void MTMR1_OVF_SetCallback(void (*Copy_PvoidFuncPtr)(void));
void MTMR1_CMA_SetCallback(void (*Copy_PvoidFuncPtr)(void));
void MTMR1_CMB_SetCallback(void (*Copy_PvoidFuncPtr)(void));



/*****************          Timer 1 - ICU         ********************/
typedef enum {
	MICU_FALLING_EDGE = 0,
	MICU_RISING_EDGE = 1
} MICU_edgeMode;

void MICU_voidSelectEdge(MICU_edgeMode Copy_EdgeMode);
void MICU_voidGetICR1Val(u16* Copy_Pu16ICR1Val);
void MICU_voidInterruptEnable();
void MICU_voidInterruptDisable();
void MICU_voidSetCallBack(void (*Copy_PvoidFuncPtr)(void));


#endif /* MTMR1_INTERFACE_H_ */
