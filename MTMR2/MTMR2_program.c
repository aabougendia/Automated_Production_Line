/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "MTMR2_config.h"
#include "MTMR2_interface.h"
#include "MTMR2_private.h"


/******************          Timer 2           ********************/

static void (*MTMR2_Pvoid_OVF_FunctionPtr)(void) = STD_TYPE_NULL;
static void (*MTMR2_Pvoid_CTC_FunctionPtr)(void) = STD_TYPE_NULL;

void MTMR2_Init(){
	/* Select Timer Mode */
	PRIVATE_TCCR2 |= MTMR2_MODE;

	/* Select Compare Output Mode On OC2 */
#if MTMR2_MODE == PRIVATE_TMR2_MODE_CTC
	PRIVATE_TCCR2 |= MTMR2_NON_PWM_CM_OUTPUT_MODE_OC2;

#elif MTMR2_MODE == PRIVATE_TMR2_MODE_FAST_PWM
	PRIVATE_TCCR2 |= MTMR2_FAST_PWM_CM_OUTPUT_MODE_OC2;

#elif MTMR2_MODE == PRIVATE_TMR2_MODE_PHASE_CORRECT_PWM
	PRIVATE_TCCR2 |= MTMR2_PHASE_CORRECT_PWM_CM_OUTPUT_MODE_OC2;

#endif
	/* Select CLK Prescaler */
	PRIVATE_TCCR2 |= MTMR2_CLK_PRESCALER;
}

void MTMR2_setPreload(u8 Copy_u8PreloadValue){
	PRIVATE_TCNT2 = Copy_u8PreloadValue;
}

void MTMR2_setCompareValue(u8 Copy_u8CompareValue){
	PRIVATE_OCR2 = Copy_u8CompareValue;
}
void MTMR2_Interrupt(Timer2_Modes Copy_TimerMode, Interrupt_Mode Copy_IntMode){
	switch (Copy_TimerMode){
		case MTMR2_OVF:
			switch(Copy_IntMode){
				case MTMR2_Enable:
					SET_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_TOIE2);
					break;
				case MTMR2_Disable:
					CLR_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_TOIE2);
					break;
			}
			break;
		case MTMR2_CTC:
			switch(Copy_IntMode){
				case MTMR2_Enable:
					SET_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_OCIE2);
					break;
				case MTMR2_Disable:
					CLR_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_OCIE2);
					break;
			}
			break;
	}
}
u8 MTMR2_GetTCNT2Value(){
	return PRIVATE_TCNT2;
}
void MTMR2_OVF_SetCallback(void (*Copy_PvoidFuncPtr)(void)){
	MTMR2_Pvoid_OVF_FunctionPtr = Copy_PvoidFuncPtr;
}

void MTMR2_CTC_SetCallback(void (*Copy_PvoidFuncPtr)(void)){
	MTMR2_Pvoid_CTC_FunctionPtr = Copy_PvoidFuncPtr;
}

/* Timer2 OVF ISR */
void __vector_5(void)		__attribute__((signal));
void __vector_5(void){
	MTMR2_Pvoid_OVF_FunctionPtr();
}

/* Timer2 CTC ISR */
void __vector_4(void)		__attribute__((signal));
void __vector_4(void){
	MTMR2_Pvoid_CTC_FunctionPtr();
}


