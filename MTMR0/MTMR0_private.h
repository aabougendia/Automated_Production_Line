/*
 * MTMR0_private.h
 *
 *  Created on: Nov 30, 2024
 *      Author: Asteroid
 */

#ifndef MTMR0_PRIVATE_H_
#define MTMR0_PRIVATE_H_


#define PRIVATE_TCCR0                   													*((volatile u8*) 0x53)
#define PRIVATE_TCCR0_CS00              													0
#define PRIVATE_TCCR0_CS01              													1
#define PRIVATE_TCCR0_CS02              													2
#define PRIVATE_TCCR0_WGM01             													3
#define PRIVATE_TCCR0_COM00             													4
#define PRIVATE_TCCR0_COM01             													5
#define PRIVATE_TCCR0_WGM00             													6
#define PRIVATE_TCCR0_FOC0              													7

#define PRIVATE_TCNT0                   													*((volatile u8*) 0x52)

#define PRIVATE_OCR0                    													*((volatile u8*) 0x5C)

#define PRIVATE_TIMSK                   													*((volatile u8*) 0x59)
#define PRIVATE_TIMSK_TOIE0             													0
#define PRIVATE_TIMSK_OCIE0             													1
#define PRIVATE_TIMSK_TOIE1             													2
#define PRIVATE_TIMSK_OCIE1B            													3
#define PRIVATE_TIMSK_OCIE1A            													4
#define PRIVATE_TIMSK_TICIE1            													5
#define PRIVATE_TIMSK_TOIE2             													6
#define PRIVATE_TIMSK_OCIE2             													7


#define PRIVATE_TIFR                   														*((volatile u8*) 0x58)
#define PRIVATE_TIFR_TOV0               													0
#define PRIVATE_TIFR_OCF0               													1
#define PRIVATE_TIFR_TOV1               													2
#define PRIVATE_TIFR_OCF1B              													3
#define PRIVATE_TIFR_OCF1A              													4
#define PRIVATE_TIFR_ICF1               													5
#define PRIVATE_TIFR_TOV2               													6
#define PRIVATE_TIFR_OCF2               													7

#define PRIVATE_SFIOR                  														*((volatile u8*) 0x50)
#define PRIVATE_SFIOR_PSR10             													0
#define PRIVATE_SFIOR_PSR2              													1


#define PRIVATE_TCCR1A                  													*((volatile u8*) 0x4F)
#define PRIVATE_TCCR1A_WGM10            													0
#define PRIVATE_TCCR1A_WGM11            													1
#define PRIVATE_TCCR1A_FOC1B            													2
#define PRIVATE_TCCR1A_FOC1A            													3
#define PRIVATE_TCCR1A_COM1B0           													4
#define PRIVATE_TCCR1A_COM1B1           													5
#define PRIVATE_TCCR1A_COM1A0           													6
#define PRIVATE_TCCR1A_COM1A1           													7

#define PRIVATE_TCCR1B                  													*((volatile u8*) 0x4E)
#define PRIVATE_TCCR1B_CS10             													0
#define PRIVATE_TCCR1B_CS11             													1
#define PRIVATE_TCCR1B_CS12             													2
#define PRIVATE_TCCR1B_WGM12            													3
#define PRIVATE_TCCR1B_WGM13            													4
#define PRIVATE_TCCR1B_ICES1            													6
#define PRIVATE_TCCR1B_ICNC1            													7

#define PRIVATE_TCNT1H                  													*((volatile u8*) 0x4D)
#define PRIVATE_TCNT1L                  													*((volatile u8*) 0x4C)
#define PRIVATE_TCNT1                   													*((volatile u16*) 0x4C)

#define PRIVATE_OCR1AH                  													*((volatile u8*) 0x4B)
#define PRIVATE_OCR1AL                  													*((volatile u8*) 0x4A)
#define PRIVATE_OCR1A                   													*((volatile u16*) 0x4A)

#define PRIVATE_OCR1BH                  													*((volatile u8*) 0x49)
#define PRIVATE_OCR1BL                  													*((volatile u8*) 0x48)
#define PRIVATE_OCR1B                   													*((volatile u16*) 0x48)

#define PRIVATE_ICR1H                   													*((volatile u8*) 0x47)
#define PRIVATE_ICR1L                   													*((volatile u8*) 0x46)
#define PRIVATE_ICR1                    													*((volatile u16*) 0x46)

#define PRIVATE_TCCR2                   													*((volatile u8*) 0x45)
#define PRIVATE_TCCR2_CS20              													0
#define PRIVATE_TCCR2_CS21              													1
#define PRIVATE_TCCR2_CS22              													2
#define PRIVATE_TCCR2_WGM21             													3
#define PRIVATE_TCCR2_COM20             													4
#define PRIVATE_TCCR2_COM21             													5
#define PRIVATE_TCCR2_WGM20             													6
#define PRIVATE_TCCR2_FOC2              													7

#define PRIVATE_TCNT2                   													*((volatile u8*) 0x44)

#define PRIVATE_OCR2                    													*((volatile u8*) 0x43)

#define PRIVATE_ASSR                    													*((volatile u8*) 0x42)
#define PRIVATE_ASSR_TCR2UB             													0
#define PRIVATE_ASSR_OCR2UB             													1
#define PRIVATE_ASSR_TCN2UB             													2
#define PRIVATE_ASSR_AS2                													3



/******************          Timer 0           ********************/

#define PRIVATE_TMR0_MODE_NORMAL															0b00000000
#define PRIVATE_TMR0_MODE_PHASE_CORRECT_PWM													0b01000000
#define PRIVATE_TMR0_MODE_CTC																0b00001000
#define PRIVATE_TMR0_MODE_FAST_PWM															0b01001000

#define PRIVATE_TMR0_NON_PWM_CM_OUTPUT_MODE_OC0_DISCONNECTED								0b00000000
#define PRIVATE_TMR0_NON_PWM_CM_OUTPUT_MODE_TOGGLE_OC0_ON_CM								0b00010000
#define PRIVATE_TMR0_NON_PWM_CM_OUTPUT_MODE_CLEAR_OC0_ON_CM									0b00100000
#define PRIVATE_TMR0_NON_PWM_CM_OUTPUT_MODE_SET_OC0_ON_CM									0b00110000

#define PRIVATE_TMR0_FAST_PWM_CM_OUTPUT_MODE_OC0_DISCONNECTED								0b00000000
#define PRIVATE_TMR0_FAST_PWM_CM_OUTPUT_MODE_RESERVED										0b00010000
#define PRIVATE_TMR0_FAST_PWM_CM_OUTPUT_MODE_OC0_CLR_ON_CM_SET_AT_TOP						0b00100000
#define PRIVATE_TMR0_FAST_PWM_CM_OUTPUT_MODE_OC0_SET_ON_CM_CLR_AT_TOP						0b00110000

#define PRIVATE_TMR0_PHASE_CORRECT_PWM_CM_OUTPUT_MODE_OC0_DISCONNECTED						0b00000000
#define PRIVATE_TMR0_PHASE_CORRECT_PWM_CM_OUTPUT_MODE_RESERVED								0b00010000
#define PRIVATE_TMR0_PHASE_CORRECT_PWM_CM_OUTPUT_MODE_OC0_CLR_UP_SET_DOWN					0b00100000
#define PRIVATE_TMR0_PHASE_CORRECT_PWM_CM_OUTPUT_MODE_OC0_SET_UP_CLR_DOWN					0b00110000




#define PRIVATE_TMR0_CLK_NO_CLK_SRC															0b00000000
#define PRIVATE_TMR0_CLK_NO_PRESCALER														0b00000001
#define PRIVATE_TMR0_CLK_PRESCALER_8														0b00000010
#define PRIVATE_TMR0_CLK_PRESCALER_64														0b00000011
#define PRIVATE_TMR0_CLK_PRESCALER_256														0b00000100
#define PRIVATE_TMR0_CLK_PRESCALER_1024														0b00000101
#define PRIVATE_TMR0_CLK_EXT_CLK_ON_T0_FALLING												0b00000110
#define PRIVATE_TMR0_CLK_EXT_CLK_ON_T0_RISING 												0b00000111



#endif /* MTMR0_PRIVATE_H_ */
