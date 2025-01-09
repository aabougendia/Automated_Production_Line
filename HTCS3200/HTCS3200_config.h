#ifndef HTCS3200_CONFIG_H_
#define HTCS3200_CONFIG_H_


#define HTCS3200_PORT			MDIO_PORTB

#define HTCS3200_S0				MDIO_PIN_0
#define HTCS3200_S1				MDIO_PIN_1
#define HTCS3200_S2				MDIO_PIN_2
#define HTCS3200_S3				MDIO_PIN_3


/* Frequency Scale Configuration */
/* Options: */
/* 1. PRIVATE_SCALE_0	*/
/* 2. PRIVATE_SCALE_2	*/
/* 3. PRIVATE_SCALE_20	*/
/* 4. PRIVATE_SCALE_100 */

#define HTCS3200_FREQ_SCALE		PRIVATE_SCALE_2


#endif /* HTCS3200_CONFIG_H_ */
