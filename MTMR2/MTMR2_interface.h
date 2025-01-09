#ifndef MTMR2_INTERFACE_H_
#define MTMR2_INTERFACE_H_


typedef enum {
	MTMR2_Disable = 0,
	MTMR2_Enable = 1
} Interrupt_Mode;



/*****************          Timer 2           ********************/
typedef enum {
	MTMR2_OVF = 0,
	MTMR2_CTC = 1
} Timer2_Modes;


void MTMR2_Init();
void MTMR2_setPreload(u8 Copy_u8PreloadValue);
void MTMR2_setCompareValue(u8 Copy_u8CompareValue);
void MTMR2_Interrupt(Timer2_Modes Copy_TimerMode, Interrupt_Mode Copy_IntMode);
u8 MTMR2_GetTCNT2Value();
void MTMR2_OVF_SetCallback(void (*Copy_PvoidFuncPtr)(void));
void MTMR2_CTC_SetCallback(void (*Copy_PvoidFuncPtr)(void));



/*****************          Delay Functions         ********************/

void MTMRS_delay_us(u32 Copy_u32DelayTime, void (*Copy_PvoidFuncPtr)(void));
void MTMRS_delay_ms(u32 Copy_u32DelayTime, void (*Copy_PvoidFuncPtr)(void));


#endif /* MTMR2_INTERFACE_H_ */
