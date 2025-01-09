#ifndef HKPD_CONFIG_H
#define HKPD_CONFIG_H


#define HKPD_ROWS_PORT		MDIO_PORTA

#define HKPD_R1_PIN			MDIO_PIN_3
#define HKPD_R2_PIN			MDIO_PIN_0
#define HKPD_R3_PIN			MDIO_PIN_0
#define HKPD_R4_PIN			MDIO_PIN_0


#define HKPD_COLS_PORT		MDIO_PORTA

#define HKPD_C1_PIN			MDIO_PIN_4
#define HKPD_C2_PIN			MDIO_PIN_5
#define HKPD_C3_PIN			MDIO_PIN_6
#define HKPD_C4_PIN			MDIO_PIN_7


#define HKPD_KPD			{'1', '2', '3', '4', \
							 '4', '5', '6', '-', \
							 '7', '8', '9', '*', \
							 '0', '%', '/', '='	 \
	}

#endif
