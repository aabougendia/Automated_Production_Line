#ifndef HSORT_INTERFACE_H_
#define HSORT_INTERFACE_H_

#define IR_MASK		 			0b1110000

#define IR_INACTIVE				0b1110000
#define IR0_ACTIVE				0b1100000
#define IR1_ACTIVE				0b1010000
#define IR2_ACTIVE				0b1000000
#define IR3_ACTIVE				0b0110000

#define IRS_ACTIVE				0
#define IRS_INACTIVE			1


#define SERVO0					0
#define SERVO1					1
#define SERVO2					2
#define SERVO_DEACTIVATE		3

void HSORT_Init();
u8 HSORT_GetIRValue();
u8 HSORT_GetIRSValue();
void HSORT_ServoAct(u8 Servo_Num);
void HSORT_DCOn();
void HSORT_DCOff();


#endif /* HSORT_INTERFACE_H_ */
