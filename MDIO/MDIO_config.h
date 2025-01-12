#ifndef MDIO_CONFIG_H
#define MDIO_CONFIG_H

/* Direction Configurations */
/* Options: 1 - PRIVATE_INPUT */
/* 		    2 - PRIVATE_OUTPUT */

/* Configuration for PORTA Pins Direction */
#define MDIO_PA0_DIR	PRIVATE_OUTPUT	// LCD CTRL RS
#define MDIO_PA1_DIR	PRIVATE_OUTPUT  // LCD CTRL RW
#define MDIO_PA2_DIR	PRIVATE_OUTPUT  // LCD CTRL EN
#define MDIO_PA3_DIR	PRIVATE_OUTPUT  // KPD R1
#define MDIO_PA4_DIR	PRIVATE_INPUT   // KPD C1
#define MDIO_PA5_DIR	PRIVATE_INPUT   // KPD C2
#define MDIO_PA6_DIR	PRIVATE_INPUT   // KPD C3
#define MDIO_PA7_DIR	PRIVATE_INPUT   // KPD C4

/* Configuration for PORTB Pins Direction */
#define MDIO_PB0_DIR	PRIVATE_OUTPUT  // TCS3200 S0
#define MDIO_PB1_DIR	PRIVATE_OUTPUT  // TCS3200 S1
#define MDIO_PB2_DIR	PRIVATE_OUTPUT  // TCS3200 S2
#define MDIO_PB3_DIR	PRIVATE_OUTPUT  // TCS3200 S3
#define MDIO_PB4_DIR	PRIVATE_OUTPUT	// LCD D4
#define MDIO_PB5_DIR	PRIVATE_OUTPUT  // LCD D5
#define MDIO_PB6_DIR	PRIVATE_OUTPUT  // LCD D6
#define MDIO_PB7_DIR	PRIVATE_OUTPUT  // LCD D7

/* Configuration for PORTC Pins Direction */
#define MDIO_PC0_DIR	PRIVATE_INPUT	// EEPROM SCL
#define MDIO_PC1_DIR	PRIVATE_INPUT	// EEPROM SDA
#define MDIO_PC2_DIR	PRIVATE_OUTPUT	// SORT SERVO CTRL0
#define MDIO_PC3_DIR	PRIVATE_OUTPUT	// SORT SERVO CTRL1
#define MDIO_PC4_DIR	PRIVATE_INPUT	// SORT IR OUT0
#define MDIO_PC5_DIR	PRIVATE_INPUT	// SORT IR OUT1
#define MDIO_PC6_DIR	PRIVATE_INPUT	// SORT IR OUT2
#define MDIO_PC7_DIR	PRIVATE_OUTPUT	// SORT DC CTRL

/* Configuration for PORTD Pins Direction */
#define MDIO_PD0_DIR	PRIVATE_OUTPUT	//  BUZZER
#define MDIO_PD1_DIR	PRIVATE_OUTPUT	// PAUSED LED
#define MDIO_PD2_DIR	PRIVATE_INPUT   // TCS3200 EXTI0 OUTPUT
#define MDIO_PD3_DIR	PRIVATE_INPUT	// SORT IRS OUT
#define MDIO_PD4_DIR	PRIVATE_OUTPUT  // DC PWM OUTPUT
#define MDIO_PD5_DIR	PRIVATE_OUTPUT 	// SORT PWM OUTPUT
#define MDIO_PD6_DIR	PRIVATE_OUTPUT	// OK LED
#define MDIO_PD7_DIR	PRIVATE_OUTPUT	// ERROR LED




/* Values Configurations */
/* Options: 1 - PRIVATE_OUTPUT_HIGH 	*/
/* 		    2 - PRIVATE_OUTPUT_LOW 		*/
/*			3 - PRIVATE_INPUT_FLOATING	*/
/*			4 - PRIVATE_INPUT_PULLEDUP	*/

/* Configuration for PORTA Pins Initial Values */
#define MDIO_PA0_INIT_VAL		PRIVATE_OUTPUT_LOW        // LCD CTRL RS
#define MDIO_PA1_INIT_VAL		PRIVATE_OUTPUT_LOW        // LCD CTRL RW
#define MDIO_PA2_INIT_VAL		PRIVATE_OUTPUT_LOW        // LCD CTRL EN
#define MDIO_PA3_INIT_VAL		PRIVATE_OUTPUT_HIGH       // KPD R1
#define MDIO_PA4_INIT_VAL		PRIVATE_INPUT_PULLEDUP    // KPD C1
#define MDIO_PA5_INIT_VAL		PRIVATE_INPUT_PULLEDUP    // KPD C2
#define MDIO_PA6_INIT_VAL		PRIVATE_INPUT_PULLEDUP    // KPD C3
#define MDIO_PA7_INIT_VAL		PRIVATE_INPUT_PULLEDUP    // KPD C4

/* Configuration for PORTB Pins Initial Values */
#define MDIO_PB0_INIT_VAL		PRIVATE_OUTPUT_LOW    // TCS3200 S0
#define MDIO_PB1_INIT_VAL		PRIVATE_OUTPUT_LOW    // TCS3200 S1
#define MDIO_PB2_INIT_VAL		PRIVATE_OUTPUT_LOW    // TCS3200 S2
#define MDIO_PB3_INIT_VAL		PRIVATE_OUTPUT_LOW    // TCS3200 S3
#define MDIO_PB4_INIT_VAL		PRIVATE_OUTPUT_LOW    // LCD D4
#define MDIO_PB5_INIT_VAL		PRIVATE_OUTPUT_LOW    // LCD D5
#define MDIO_PB6_INIT_VAL		PRIVATE_OUTPUT_LOW    // LCD D6
#define MDIO_PB7_INIT_VAL		PRIVATE_OUTPUT_LOW    // LCD D7

/* Configuration for PORTC Pins Initial Values */
#define MDIO_PC0_INIT_VAL		PRIVATE_INPUT_FLOATING  // EEPROM SCL
#define MDIO_PC1_INIT_VAL		PRIVATE_INPUT_FLOATING  // EEPROM SDA
#define MDIO_PC2_INIT_VAL		PRIVATE_OUTPUT_HIGH     // SORT SERVO CTRL0
#define MDIO_PC3_INIT_VAL		PRIVATE_OUTPUT_HIGH     // SORT SERVO CTRL1
#define MDIO_PC4_INIT_VAL		PRIVATE_INPUT_PULLEDUP  // SORT IR OUT0
#define MDIO_PC5_INIT_VAL		PRIVATE_INPUT_PULLEDUP  // SORT IR OUT1
#define MDIO_PC6_INIT_VAL		PRIVATE_INPUT_PULLEDUP  // SORT IR OUT2
#define MDIO_PC7_INIT_VAL		PRIVATE_OUTPUT_LOW      // SORT DC CTRL

/* Configuration for PORTD Pins Initial Values */
#define MDIO_PD0_INIT_VAL		PRIVATE_OUTPUT_LOW  	// BUZZER
#define MDIO_PD1_INIT_VAL		PRIVATE_OUTPUT_LOW      // PAUSED LED
#define MDIO_PD2_INIT_VAL		PRIVATE_INPUT_FLOATING  // TCS3200 EXTI0 OUTPUT
#define MDIO_PD3_INIT_VAL		PRIVATE_INPUT_PULLEDUP  // SORT IRS OUT
#define MDIO_PD4_INIT_VAL		PRIVATE_OUTPUT_LOW      // DC PWM OUTPUT
#define MDIO_PD5_INIT_VAL		PRIVATE_OUTPUT_LOW      // SORT PWM OUTPUT
#define MDIO_PD6_INIT_VAL		PRIVATE_OUTPUT_LOW      // OK LED
#define MDIO_PD7_INIT_VAL		PRIVATE_OUTPUT_LOW      // ERROR LED



#endif
