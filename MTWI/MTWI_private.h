
#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_

#define TWCR		*((volatile u8*) 0x56)
#define TWCR_TWINT	7
#define TWCR_TWEA	6
#define TWCR_TWSTA	5
#define TWCR_TWSTO	4
#define TWCR_TWEN	2

#define TWDR		*((volatile u8*) 0x23)
#define TWAR		*((volatile u8*) 0x22)
#define TWSR		*((volatile u8*) 0x21)
#define TWBR		*((volatile u8*) 0x20)

#endif /* MTWI_PRIVATE_H_ */
