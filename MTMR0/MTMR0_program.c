/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "MTMR0_interface.h"
#include "MTMR0_private.h"
#include "MTMR0_config.h"


/******************          Timer 0           ********************/

static void (*MTMR0_Pvoid_OVF_FunctionPtr)(void) = STD_TYPE_NULL;
static void (*MTMR0_Pvoid_CTC_FunctionPtr)(void) = STD_TYPE_NULL;

void MTMR0_Init(){
	/* Select Timer Mode */
	PRIVATE_TCCR0 |= MTMR0_MODE;

	/* Select Compare Output Mode On OC0 */
#if MTMR0_MODE == PRIVATE_TMR0_MODE_CTC
	PRIVATE_TCCR0 |= MTMR0_NON_PWM_CM_OUTPUT_MODE_OC0;

#elif MTMR0_MODE == PRIVATE_TMR0_MODE_FAST_PWM
	PRIVATE_TCCR0 |= MTMR0_FAST_PWM_CM_OUTPUT_MODE_OC0;

#elif MTMR0_MODE == PRIVATE_TMR0_MODE_PHASE_CORRECT_PWM
	PRIVATE_TCCR0 |= MTMR0_PHASE_CORRECT_PWM_CM_OUTPUT_MODE_OC0;

#endif
	/* Select CLK Prescaler */
	PRIVATE_TCCR0 |= MTMR0_CLK_PRESCALER;
}

void MTMR0_setPreload(u8 Copy_u8PreloadValue){
	PRIVATE_TCNT0 = Copy_u8PreloadValue;
}

void MTMR0_setCompareValue(u8 Copy_u8CompareValue){
	PRIVATE_OCR0 = Copy_u8CompareValue;
}
void MTMR0_Interrupt(Timer0_Modes Copy_TimerMode, TMR0_Interrupt_Mode Copy_IntMode){
	switch (Copy_TimerMode){
		case MTMR0_OVF:
			switch(Copy_IntMode){
				case MTMR0_Enable:
					SET_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_TOIE0);
					break;
				case MTMR0_Disable:
					CLR_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_TOIE0);
					break;
			}
			break;
		case MTMR0_CTC:
			switch(Copy_IntMode){
				case MTMR0_Enable:
					SET_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_OCIE0);
					break;
				case MTMR0_Disable:
					CLR_BIT(PRIVATE_TIMSK, PRIVATE_TIMSK_OCIE0);
					break;
			}
			break;
	}
}
u8 MTMR0_GetTCNT0Value(){
	return PRIVATE_TCNT0;
}
void MTMR0_OVF_SetCallback(void (*Copy_PvoidFuncPtr)(void)){
	MTMR0_Pvoid_OVF_FunctionPtr = Copy_PvoidFuncPtr;
}

void MTMR0_CTC_SetCallback(void (*Copy_PvoidFuncPtr)(void)){
	MTMR0_Pvoid_CTC_FunctionPtr = Copy_PvoidFuncPtr;
}

/* Timer0 OVF ISR */
void __vector_11(void)		__attribute__((signal));
void __vector_11(void){
	MTMR0_Pvoid_OVF_FunctionPtr();
}

/* Timer0 CTC ISR */
void __vector_10(void)		__attribute__((signal));
void __vector_10(void){
	MTMR0_Pvoid_CTC_FunctionPtr();
}


