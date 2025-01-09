/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"

#define F_CPU 8000000U
#include <avr/delay.h>

/* MCAL Layer */
#include "../MDIO/MDIO_interface.h"

/* HAL Layer */
#include "HKPD_interface.h"
#include "HKPD_private.h"
#include "HKPD_config.h"

static u8 HKPD_Au8RowPins[4] = {HKPD_R1_PIN, HKPD_R2_PIN, HKPD_R3_PIN, HKPD_R4_PIN};
static u8 HKPD_Au8ColPins[4] = {HKPD_C1_PIN, HKPD_C2_PIN, HKPD_C3_PIN, HKPD_C4_PIN};

static u8 HKPD_Au8Keys[4][4] = HKPD_KPD;

u8 HKPD_u8GetPressedKey(u8* Copy_Pu8KeyPressed){
	u8 Local_u8ErrorState = STD_TYPE_NOK;

	u8 Local_u8RowCounter;
	u8 Local_u8ColCounter;

	u8 Local_u8PinVal;


	if(Copy_Pu8KeyPressed != STD_TYPE_NULL){
		Local_u8ErrorState = STD_TYPE_OK;


		*Copy_Pu8KeyPressed = HKPD_NO_KEY_PRESSED;

		for(Local_u8RowCounter = 0; Local_u8RowCounter < 1; Local_u8RowCounter++){


			/* Activate Each Row by setting it to LOW */
			MDIO_u8SetPinValue(HKPD_ROWS_PORT, HKPD_Au8RowPins[Local_u8RowCounter], MDIO_LOW);

			/* Check Cols */
			for(Local_u8ColCounter = 0; Local_u8ColCounter < 4; Local_u8ColCounter++){



				MDIO_u8GetPinValue(HKPD_COLS_PORT, HKPD_Au8ColPins[Local_u8ColCounter], &Local_u8PinVal);



				if(Local_u8PinVal == MDIO_LOW){
					/* Bouncing effect : apply delay for debouncing */
					_delay_ms(20);


					/* Wait till user release the switch */
					while(Local_u8PinVal == MDIO_LOW){
						MDIO_u8GetPinValue(HKPD_COLS_PORT, HKPD_Au8ColPins[Local_u8ColCounter], &Local_u8PinVal);
					}

					*Copy_Pu8KeyPressed = HKPD_Au8Keys[Local_u8RowCounter][Local_u8ColCounter];
				}
			}
			/* Deactivate for current Row */
			MDIO_u8SetPinValue(HKPD_ROWS_PORT, HKPD_Au8RowPins[Local_u8RowCounter], MDIO_HIGH);
		}

	}


	return Local_u8ErrorState;
}
