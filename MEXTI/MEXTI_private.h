#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

#define PRIVATE_MCUCR			*((volatile u8*)0x55)
#define PRIVATE_MCUCR_ISC00           0
#define PRIVATE_MCUCR_ISC01           1
#define PRIVATE_MCUCR_ISC10           2
#define PRIVATE_MCUCR_ISC11           3

#define PRIVATE_MCUCSR			*((volatile u8*)0x54)
#define PRIVATE_MCUCSR_ISC2     6

#define PRIVATE_GICR			*((volatile u8*)0x5B)
#define PRIVATE_GICR_INT0       6
#define PRIVATE_GICR_INT1       7
#define PRIVATE_GICR_INT2       5

#define PRIVATE_GIFR			*((volatile u8*)0x5A)
#define PRIVATE_GIFR_INTF0      6
#define PRIVATE_GIFR_INTF1      7
#define PRIVATE_GIFR_INTF2      5

#endif
