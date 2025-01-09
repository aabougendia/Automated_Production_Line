/* LIB Layer */

#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"	// private before config
#include "MDIO_config.h"


void MDIO_Init(){
	/* Set Initial Directions for All PORTS */
	PRIVATE_DDRA_REG = PRIVATE_CONC(MDIO_PA7_DIR,
									MDIO_PA6_DIR,
									MDIO_PA5_DIR,
									MDIO_PA4_DIR,
									MDIO_PA3_DIR,
									MDIO_PA2_DIR,
									MDIO_PA1_DIR,
									MDIO_PA0_DIR);

	PRIVATE_DDRB_REG = PRIVATE_CONC(MDIO_PB7_DIR,
									MDIO_PB6_DIR,
									MDIO_PB5_DIR,
									MDIO_PB4_DIR,
									MDIO_PB3_DIR,
									MDIO_PB2_DIR,
									MDIO_PB1_DIR,
									MDIO_PB0_DIR);

	PRIVATE_DDRC_REG = PRIVATE_CONC(MDIO_PC7_DIR,
									MDIO_PC6_DIR,
									MDIO_PC5_DIR,
									MDIO_PC4_DIR,
									MDIO_PC3_DIR,
									MDIO_PC2_DIR,
									MDIO_PC1_DIR,
									MDIO_PC0_DIR);

	PRIVATE_DDRD_REG = PRIVATE_CONC(MDIO_PD7_DIR,
									MDIO_PD6_DIR,
									MDIO_PD5_DIR,
									MDIO_PD4_DIR,
									MDIO_PD3_DIR,
									MDIO_PD2_DIR,
									MDIO_PD1_DIR,
									MDIO_PD0_DIR);



	/* Set Initial Values for All Pins */
	PRIVATE_PORTA_REG = PRIVATE_CONC(MDIO_PA7_INIT_VAL,
									 MDIO_PA6_INIT_VAL,
									 MDIO_PA5_INIT_VAL,
									 MDIO_PA4_INIT_VAL,
									 MDIO_PA3_INIT_VAL,
									 MDIO_PA2_INIT_VAL,
									 MDIO_PA1_INIT_VAL,
									 MDIO_PA0_INIT_VAL);

	PRIVATE_PORTB_REG = PRIVATE_CONC(MDIO_PB7_INIT_VAL,
									 MDIO_PB6_INIT_VAL,
									 MDIO_PB5_INIT_VAL,
									 MDIO_PB4_INIT_VAL,
									 MDIO_PB3_INIT_VAL,
									 MDIO_PB2_INIT_VAL,
									 MDIO_PB1_INIT_VAL,
									 MDIO_PB0_INIT_VAL);

	PRIVATE_PORTC_REG = PRIVATE_CONC(MDIO_PC7_INIT_VAL,
									 MDIO_PC6_INIT_VAL,
									 MDIO_PC5_INIT_VAL,
									 MDIO_PC4_INIT_VAL,
									 MDIO_PC3_INIT_VAL,
									 MDIO_PC2_INIT_VAL,
									 MDIO_PC1_INIT_VAL,
									 MDIO_PC0_INIT_VAL);

	PRIVATE_PORTD_REG = PRIVATE_CONC(MDIO_PD7_INIT_VAL,
									 MDIO_PD6_INIT_VAL,
									 MDIO_PD5_INIT_VAL,
									 MDIO_PD4_INIT_VAL,
									 MDIO_PD3_INIT_VAL,
									 MDIO_PD2_INIT_VAL,
									 MDIO_PD1_INIT_VAL,
									 MDIO_PD0_INIT_VAL);
}


/* Set Pin Direction */
u8 MDIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection){
    u8 Local_u8ErrorState = STD_TYPE_OK;
    /* Check for Direction input */
    if(Copy_u8PinDirection <= MDIO_PIN_7){
        switch (Copy_u8PortId) {
            case MDIO_PORTA:
                switch (Copy_u8PinDirection) {
                    case MDIO_OUTPUT:
                        SET_BIT(PRIVATE_DDRA_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_FLOATING:
                        CLR_BIT(PRIVATE_DDRA_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_PULLEDUP:
                        CLR_BIT(PRIVATE_DDRA_REG, Copy_u8PinId);    // Set DDR register to input
                        SET_BIT(PRIVATE_PORTA_REG, Copy_u8PinId);   // Activate pull-up resistor
                        break;
                    default:
                        Local_u8ErrorState = STD_TYPE_NOK;
                }
                break;
            case MDIO_PORTB:
                switch (Copy_u8PinDirection) {
                    case MDIO_OUTPUT:
                        SET_BIT(PRIVATE_DDRB_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_FLOATING:
                        CLR_BIT(PRIVATE_DDRB_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_PULLEDUP:
                        CLR_BIT(PRIVATE_DDRB_REG, Copy_u8PinId);    // Set DDR register to input
                        SET_BIT(PRIVATE_PORTB_REG, Copy_u8PinId);   // Activate pull-up resistor
                        break;
                    default:
                        Local_u8ErrorState = STD_TYPE_NOK;
                }
                break;
            case MDIO_PORTC:
                switch (Copy_u8PinDirection) {
                    case MDIO_OUTPUT:
                        SET_BIT(PRIVATE_DDRC_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_FLOATING:
                        CLR_BIT(PRIVATE_DDRC_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_PULLEDUP:
                        CLR_BIT(PRIVATE_DDRC_REG, Copy_u8PinId);    // Set DDR register to input
                        SET_BIT(PRIVATE_PORTC_REG, Copy_u8PinId);   // Activate pull-up resistor
                        break;
                    default:
                        Local_u8ErrorState = STD_TYPE_NOK;
                }
                break;
            case MDIO_PORTD:
                switch (Copy_u8PinDirection) {
                    case MDIO_OUTPUT:
                        SET_BIT(PRIVATE_DDRD_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_FLOATING:
                        CLR_BIT(PRIVATE_DDRD_REG, Copy_u8PinId);
                        break;
                    case MDIO_INPUT_PULLEDUP:
                        CLR_BIT(PRIVATE_DDRD_REG, Copy_u8PinId);    // Set DDR register to input
                        SET_BIT(PRIVATE_PORTD_REG, Copy_u8PinId);   // Activate pull-up resistor
                        break;
                    default:
                        Local_u8ErrorState = STD_TYPE_NOK;
                }
                break;
            default:
                Local_u8ErrorState = STD_TYPE_NOK;
        }
    }
    else {
        Local_u8ErrorState = STD_TYPE_NOK;
    }

    return Local_u8ErrorState;
}

/* Set Port Direction */
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection){
    u8 Local_ErrorState = STD_TYPE_OK;

    switch (Copy_u8PortId) {
        case MDIO_PORTA:
            switch (Copy_u8PortDirection) {
                case MDIO_OUTPUT:
                    PRIVATE_DDRA_REG = 0xFF;
                    break;
                case MDIO_INPUT_FLOATING:
                    PRIVATE_DDRA_REG = 0x00;
                    break;
                case MDIO_INPUT_PULLEDUP:
                    PRIVATE_DDRA_REG = 0x00;
                    PRIVATE_PORTA_REG = 0xFF;
                    break;
                default:
                    Local_ErrorState = STD_TYPE_NOK;
            }
            break;
        case MDIO_PORTB:
            switch (Copy_u8PortDirection) {
                case MDIO_OUTPUT:
                    PRIVATE_DDRB_REG = 0xFF;
                    break;
                case MDIO_INPUT_FLOATING:
                    PRIVATE_DDRB_REG = 0x00;
                    break;
                case MDIO_INPUT_PULLEDUP:
                    PRIVATE_DDRB_REG = 0x00;
                    PRIVATE_PORTB_REG = 0xFF;
                    break;
                default:
                    Local_ErrorState = STD_TYPE_NOK;
            }
            break;
        case MDIO_PORTC:
            switch (Copy_u8PortDirection) {
                case MDIO_OUTPUT:
                    PRIVATE_DDRC_REG = 0xFF;
                    break;
                case MDIO_INPUT_FLOATING:
                    PRIVATE_DDRC_REG = 0x00;
                    break;
                case MDIO_INPUT_PULLEDUP:
                    PRIVATE_DDRC_REG = 0x00;
                    PRIVATE_PORTC_REG = 0xFF;
                    break;
                default:
                    Local_ErrorState = STD_TYPE_NOK;
            }
            break;
        case MDIO_PORTD:
            switch (Copy_u8PortDirection) {
                case MDIO_OUTPUT:
                    PRIVATE_DDRD_REG = 0xFF;
                    break;
                case MDIO_INPUT_FLOATING:
                    PRIVATE_DDRD_REG = 0x00;
                    break;
                case MDIO_INPUT_PULLEDUP:
                    PRIVATE_DDRD_REG = 0x00;
                    PRIVATE_PORTD_REG = 0xFF;
                    break;
                default:
                    Local_ErrorState = STD_TYPE_NOK;
            }
            break;
        default:
            Local_ErrorState = STD_TYPE_NOK;
    }
    return Local_ErrorState;
}

/* Set Pin Value */
u8 MDIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue){
    u8 Local_ErrorState = STD_TYPE_OK;
    if((Copy_u8PinId <= MDIO_PIN_7) && (Copy_u8PortId <= MDIO_PORTD) && (Copy_u8PinValue <= MDIO_HIGH)){    // Checking the PIN ID withing the allowed range
        switch (Copy_u8PortId) {
            case MDIO_PORTA:
                switch (Copy_u8PinValue) {
                    case MDIO_HIGH:
                        SET_BIT(PRIVATE_PORTA_REG, Copy_u8PinId);
                        break;
                    case MDIO_LOW:
                        CLR_BIT(PRIVATE_PORTA_REG, Copy_u8PinId);
                        break;
                    default:
                        Local_ErrorState = STD_TYPE_NOK;
                }
                break;
            case MDIO_PORTB:
                switch (Copy_u8PinValue) {
                    case MDIO_HIGH:
                        SET_BIT(PRIVATE_PORTB_REG, Copy_u8PinId);
                        break;
                    case MDIO_LOW:
                        CLR_BIT(PRIVATE_PORTB_REG, Copy_u8PinId);
                        break;
                    default:
                        Local_ErrorState = STD_TYPE_NOK;
                }
                break;
            case MDIO_PORTC:
                switch (Copy_u8PinValue) {
                    case MDIO_HIGH:
                        SET_BIT(PRIVATE_PORTC_REG, Copy_u8PinId);
                        break;
                    case MDIO_LOW:
                        CLR_BIT(PRIVATE_PORTC_REG, Copy_u8PinId);
                        break;
                    default:
                        Local_ErrorState = STD_TYPE_NOK;
                }
                break;
            case MDIO_PORTD:
                switch (Copy_u8PinValue) {
                    case MDIO_HIGH:
                        SET_BIT(PRIVATE_PORTD_REG, Copy_u8PinId);
                        break;
                    case MDIO_LOW:
                        CLR_BIT(PRIVATE_PORTD_REG, Copy_u8PinId);
                        break;
                    default:
                        Local_ErrorState = STD_TYPE_NOK;
                }
                break;
            default:
                Local_ErrorState = STD_TYPE_NOK;
        }
    }
    else {
        Local_ErrorState = STD_TYPE_NOK;
    }

    return Local_ErrorState;
}

u8 MDIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue){
    u8 Local_ErrorState = STD_TYPE_OK;

    switch (Copy_u8PortId) {
        case MDIO_PORTA:
            PRIVATE_PORTA_REG = Copy_u8PortValue;
            break;
        case MDIO_PORTB:
            PRIVATE_PORTB_REG = Copy_u8PortValue;
            break;
        case MDIO_PORTC:
            PRIVATE_PORTC_REG = Copy_u8PortValue;
            break;
        case MDIO_PORTD:
            PRIVATE_PORTD_REG = Copy_u8PortValue;
            break;
        default:
            Local_ErrorState = STD_TYPE_NOK;
    }

    return Local_ErrorState;
}

u8 MDIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_Pu8ReturnedPinValue){
    u8 Local_ErrorState = STD_TYPE_OK;
    if((Copy_u8PortId <= MDIO_PORTD) && (Copy_u8PinId <= MDIO_PIN_7) && (Copy_Pu8ReturnedPinValue != STD_TYPE_NULL)){
        switch (Copy_u8PortId) {
            case MDIO_PORTA:
                *Copy_Pu8ReturnedPinValue = GET_BIT(PRIVATE_PINA_REG, Copy_u8PinId);
                break;
            case MDIO_PORTB:
                *Copy_Pu8ReturnedPinValue = GET_BIT(PRIVATE_PINB_REG, Copy_u8PinId);
                break;
            case MDIO_PORTC:
                *Copy_Pu8ReturnedPinValue = GET_BIT(PRIVATE_PINC_REG, Copy_u8PinId);
                break;
            case MDIO_PORTD:
                *Copy_Pu8ReturnedPinValue = GET_BIT(PRIVATE_PIND_REG, Copy_u8PinId);
                break;
            default:
                Local_ErrorState = STD_TYPE_NOK;
        }
    }
    else {
        Local_ErrorState = STD_TYPE_NOK;
    }

    return Local_ErrorState;
}

u8 MDIO_u8GetPortValue(u8 Copy_u8PortId, u8* Copy_Pu8ReturnedPortValue){
    u8 Local_ErrorState = STD_TYPE_OK;
    if((Copy_u8PortId <= MDIO_PORTD) && (Copy_Pu8ReturnedPortValue != STD_TYPE_NULL)) {
        switch (Copy_u8PortId) {
            case MDIO_PORTA:
                *Copy_Pu8ReturnedPortValue = PRIVATE_PINA_REG;
                break;
            case MDIO_PORTB:
                *Copy_Pu8ReturnedPortValue = PRIVATE_PINB_REG;
                break;
            case MDIO_PORTC:
                *Copy_Pu8ReturnedPortValue = PRIVATE_PINC_REG;
                break;
            case MDIO_PORTD:
                *Copy_Pu8ReturnedPortValue = PRIVATE_PIND_REG;
                break;
            default:
                Local_ErrorState = STD_TYPE_NOK;
        }
    }
    else {
        Local_ErrorState = STD_TYPE_NOK;
    }

    return Local_ErrorState;
}
