/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "MEXTI_interface.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"

/* Array of Pointers to function to be called from ISRs */
static void(*MEXTI_APfEXTI[3])(void) = {STD_TYPE_NULL, STD_TYPE_NULL, STD_TYPE_NULL};

u8 MEXTI_u8Enable(MEXTI_IntNum Copy_eIntNum, MEXTI_IntSrc Copy_eIntSrc){
	u8 Local_u8ErrorState = STD_TYPE_OK;
		switch(Copy_eIntNum){
			case MEXTI_INT0:
				if(Copy_eIntSrc == MEXTI_FALLING_EDGE){
					/* Select Falling Edge as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);

					/* Enable INT0 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT0);
				}
				else if (Copy_eIntSrc == MEXTI_RISING_EDGE){
					/* Select Rising Edge as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);

					/* Enable INT0 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT0);
				}
				else if (Copy_eIntSrc == MEXTI_LOW_LEVEL){
					/* Select Low Level as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);

					/* Enable INT0 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT0);
				}
				else if (Copy_eIntSrc == MEXTI_ANY_LOGICAL_CHANGE){
					/* Select Any Logical Change as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);

					/* Enable INT0 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT0);
				}
				else {
					Local_u8ErrorState = STD_TYPE_NOK;
				}
				break;
			case MEXTI_INT1:
				if(Copy_eIntSrc == MEXTI_FALLING_EDGE){
					/* Select Falling Edge as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);

					/* Enable INT1 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT1);
				}
				else if (Copy_eIntSrc == MEXTI_RISING_EDGE){
					/* Select Rising Edge as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);

					/* Enable INT1*/
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT1);
				}
				else if (Copy_eIntSrc == MEXTI_LOW_LEVEL){
					/* Select Low Level as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);

					/* Enable INT0 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT1);
				}
				else if (Copy_eIntSrc == MEXTI_ANY_LOGICAL_CHANGE){
					/* Select Any Logical Change as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);

					/* Enable INT1 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT1);
				}
				else {
					Local_u8ErrorState = STD_TYPE_NOK;
				}
				break;
			case MEXTI_INT2:
				if(Copy_eIntSrc == MEXTI_FALLING_EDGE){
					/* Select Falling Edge as a trigger source */
					CLR_BIT(PRIVATE_MCUCSR, PRIVATE_MCUCSR_ISC2);

					/* Enable INT2 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT2);
				}
				else if (Copy_eIntSrc == MEXTI_RISING_EDGE){
					/* Select Falling Edge as a trigger source */
					SET_BIT(PRIVATE_MCUCSR, PRIVATE_MCUCSR_ISC2);

					/* Enable INT2 */
					SET_BIT(PRIVATE_GICR, PRIVATE_GICR_INT2);
				}
				else{
					Local_u8ErrorState = STD_TYPE_NOK;
				}
				break;
			default:
				Local_u8ErrorState = STD_TYPE_NOK;
		}
		return Local_u8ErrorState;
}
u8 MEXTI_u8Disable(MEXTI_IntNum Copy_eIntNum){
    u8 Local_u8ErrorState = STD_TYPE_OK;
    switch(Copy_eIntNum){
        case MEXTI_INT0:
            /* Disable INT0 */
            CLR_BIT(PRIVATE_GICR, PRIVATE_GICR_INT0);
            break;
        case MEXTI_INT1:
            /* Disable INT1 */
            CLR_BIT(PRIVATE_GICR, PRIVATE_GICR_INT1);
            break;
        case MEXTI_INT2:
            /* Disable INT0 */
            CLR_BIT(PRIVATE_GICR, PRIVATE_GICR_INT2);
            break;
    }
    return Local_u8ErrorState;
}

u8 MEXTI_voidSelectEdge(MEXTI_IntNum Copy_eIntNum, MEXTI_IntSrc Copy_eIntSrc){
	u8 Local_u8ErrorState = STD_TYPE_OK;
		switch(Copy_eIntNum){
			case MEXTI_INT0:
				if(Copy_eIntSrc == MEXTI_FALLING_EDGE){
					/* Select Falling Edge as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);
				}
				else if (Copy_eIntSrc == MEXTI_RISING_EDGE){
					/* Select Rising Edge as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);
				}
				else if (Copy_eIntSrc == MEXTI_LOW_LEVEL){
					/* Select Low Level as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);
				}
				else if (Copy_eIntSrc == MEXTI_ANY_LOGICAL_CHANGE){
					/* Select Any Logical Change as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC00);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC01);
				}
				else {
					Local_u8ErrorState = STD_TYPE_NOK;
				}
				break;
			case MEXTI_INT1:
				if(Copy_eIntSrc == MEXTI_FALLING_EDGE){
					/* Select Falling Edge as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);
				}
				else if (Copy_eIntSrc == MEXTI_RISING_EDGE){
					/* Select Rising Edge as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);
				}
				else if (Copy_eIntSrc == MEXTI_LOW_LEVEL){
					/* Select Low Level as a trigger source */
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);
				}
				else if (Copy_eIntSrc == MEXTI_ANY_LOGICAL_CHANGE){
					/* Select Any Logical Change as a trigger source */
					SET_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC10);
					CLR_BIT(PRIVATE_MCUCR, PRIVATE_MCUCR_ISC11);
				}
				else {
					Local_u8ErrorState = STD_TYPE_NOK;
				}
				break;
			case MEXTI_INT2:
				if(Copy_eIntSrc == MEXTI_FALLING_EDGE){
					/* Select Falling Edge as a trigger source */
					CLR_BIT(PRIVATE_MCUCSR, PRIVATE_MCUCSR_ISC2);
				}
				else if (Copy_eIntSrc == MEXTI_RISING_EDGE){
					/* Select Falling Edge as a trigger source */
					SET_BIT(PRIVATE_MCUCSR, PRIVATE_MCUCSR_ISC2);
				}
				else{
					Local_u8ErrorState = STD_TYPE_NOK;
				}
				break;
			default:
				Local_u8ErrorState = STD_TYPE_NOK;
		}
		return Local_u8ErrorState;
}

u8 MEXTI_u8SetCallback(MEXTI_IntNum Copy_eIntNum, void(*Copy_Pf)(void)) {
    u8 Local_u8ErrorState = STD_TYPE_OK;
    if (Copy_eIntNum <= MEXTI_INT2 && Copy_Pf != STD_TYPE_NULL) {
        MEXTI_APfEXTI[Copy_eIntNum] = Copy_Pf;
    }
    else {
        Local_u8ErrorState = STD_TYPE_NOK;
    }
    return Local_u8ErrorState;
}

u8 MEXTI_u8GetEXTI0Flag(){
	return GET_BIT(PRIVATE_GIFR, PRIVATE_GIFR_INTF0);
}
void MEXTI_u8ClearEXTI0Flag(){
	SET_BIT(PRIVATE_GIFR, PRIVATE_GIFR_INTF0);
}

/* Prototype of ISR EXTI0 */
void __vector_1(void)	__attribute__((signal));
/* Implementation of ISR */
void __vector_1(void){
    if(MEXTI_APfEXTI[MEXTI_INT0] != STD_TYPE_NULL){
        MEXTI_APfEXTI[MEXTI_INT0]();
    }
}

/* Prototype of ISR EXTI1 */
void __vector_2(void)	__attribute__((signal));
/* Implementation of ISR */
void __vector_2(void){
    if(MEXTI_APfEXTI[MEXTI_INT1] != STD_TYPE_NULL){
        MEXTI_APfEXTI[MEXTI_INT1]();
    }
}

/* Prototype of ISR EXTI2 */
void __vector_3(void)	__attribute__((signal));
/* Implementation of ISR */
void __vector_3(void){
    if(MEXTI_APfEXTI[MEXTI_INT2] != STD_TYPE_NULL){
        MEXTI_APfEXTI[MEXTI_INT2]();
    }
}


