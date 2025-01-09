/*
 * TMR0_interface.h
 *
 *  Created on: Nov 30, 2024
 *      Author: Asteroid
 */

#ifndef MTMR0_INTERFACE_H_
#define MTMR0_INTERFACE_H_


typedef enum {
	MTMR0_Disable = 0,
	MTMR0_Enable = 1
} TMR0_Interrupt_Mode;



/*****************          Timer 0           ********************/
typedef enum {
	MTMR0_OVF = 0,
	MTMR0_CTC = 1
} Timer0_Modes;


void MTMR0_Init();
void MTMR0_setPreload(u8 Copy_u8PreloadValue);
void MTMR0_setCompareValue(u8 Copy_u8CompareValue);
void MTMR0_Interrupt(Timer0_Modes Copy_TimerMode, TMR0_Interrupt_Mode Copy_IntMode);
u8 MTMR0_GetTCNT0Value();
void MTMR0_OVF_SetCallback(void (*Copy_PvoidFuncPtr)(void));
void MTMR0_CTC_SetCallback(void (*Copy_PvoidFuncPtr)(void));



/*****************          Delay Functions         ********************/

void MTMRS_delay_us(u32 Copy_u32DelayTime, void (*Copy_PvoidFuncPtr)(void));
void MTMRS_delay_ms(u32 Copy_u32DelayTime, void (*Copy_PvoidFuncPtr)(void));


#endif /* MTMR0_INTERFACE_H_ */
