#ifndef HLCD_CONFIG_H
#define HLCD_CONFIG_H

/* Configuration for Control Pins */
// Rs Pin
#define HLCD_RS_PORT		MDIO_PORTA
#define HLCD_RS_PIN			MDIO_PIN_0

// R/W Pin
#define HLCD_RW_PORT		MDIO_PORTA
#define HLCD_RW_PIN			MDIO_PIN_1

// Enable Pin
#define HLCD_EN_PORT		MDIO_PORTA
#define HLCD_EN_PIN			MDIO_PIN_2


/* Configuration for Data Pins */
#define HLCD_DATA_PORT		MDIO_PORTB



#endif
