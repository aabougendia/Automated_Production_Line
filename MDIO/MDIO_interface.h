#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

/* Define PORT ID */
#define MDIO_PORTA                  0
#define MDIO_PORTB                  1
#define MDIO_PORTC                  2
#define MDIO_PORTD                  3

/* Define PIN ID */
#define MDIO_PIN_0                  0
#define MDIO_PIN_1                  1
#define MDIO_PIN_2                  2
#define MDIO_PIN_3                  3
#define MDIO_PIN_4                  4
#define MDIO_PIN_5                  5
#define MDIO_PIN_6                  6
#define MDIO_PIN_7                  7

/* Define Pin Directions */
#define MDIO_OUTPUT                 0
#define MDIO_INPUT_FLOATING         1
#define MDIO_INPUT_PULLEDUP         2

/* Define PIN Values */
#define MDIO_HIGH                   1
#define MDIO_LOW                    0



void MDIO_Init();

u8 MDIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection);
u8 MDIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);

u8 MDIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
u8 MDIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);

u8 MDIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8* Copy_Pu8ReturnedPinValue);
u8 MDIO_u8GetPortValue(u8 Copy_u8PortId, u8* Copy_Pu8ReturnedPortValue);

#endif
