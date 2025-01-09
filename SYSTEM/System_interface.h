#ifndef SYSTEM_INTERFACE_H_
#define SYSTEM_INTERFACE_H_


#define ALERTS_PORT				MDIO_PORTD

#define RUNNING_LED_PIN			MDIO_PIN_6
#define PAUSED_LED_PIN			MDIO_PIN_1
#define ERROR_LED_PIN			MDIO_PIN_7
#define BUZZER_PIN				MDIO_PIN_0



typedef enum {
	SYSTEM_RUNNING,
	SYSTEM_PAUSED,
	SYSTEM_ERROR_SORTING,
	SYSTEM_UNDEFINED_COLOR
} SystemStatus;

#define ERROR_WAIT_TIME		5

extern SystemStatus System_eStateFlag;

extern u8 System_u8NumOfObjects;
extern u16 System_u16TimeSorting;
extern u8 System_u8NumOfErrors;



void ShowColor(Color Copy_eOutputColor);
Color DetectObjectColor();

void CalculateTime();

/* Rokaya */
void LogNumOfObjects();
void LogTimeSpentSorting();
void LogNumOfErrors();

void SystemRunningLedOn();
void SystemRunningLedOff();

void SystemPausedLedOn();
void SystemPausedLedOff();

void SystemErrorLedOn();
void SystemErrorLedOff();

void SystemBuzzerOn();
void SystemBuzzerOff();

#endif /* SYSTEM_INTERFACE_H_ */
