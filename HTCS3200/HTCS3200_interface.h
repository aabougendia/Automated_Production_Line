#ifndef HTCS3200_INTERFACE_H_
#define HTCS3200_INTERFACE_H_

#define U32_MAX 4294967295
#define MICROSECONDS_PER_SECOND 1000000

#define MIN_COLOR 2000
#define MAX_COLOR 12000

typedef enum {
	HTCS3200_FILTER_RED,
	HTCS3200_FILTER_BLUE,
	HTCS3200_FILTER_CLEAR,
	HTCS3200_FILTER_GREEN

} Sensor_Filter;

typedef enum {
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	OBJECT_NOT_FOUND,
	COLOR_NOT_DEFINED
} Color;

u16 HTCS3200_u16R1;
u16 HTCS3200_u16RedPeriodicTime;
u16 HTCS3200_u16GreenPeriodicTime;
u16 HTCS3200_u16BluePeriodicTime;


u8 HTCS3200_u8RedVal;
u8 HTCS3200_u8GreenVal;
u8 HTCS3200_u8BlueVal;

Color HTCS3200_eOutputColor;


void HTCS3200_Init();
void HTCS3200_voidEnable();
void HTCS3200_voidDisable();

void HTCS3200_voidTakeReading();
void HTCS3200_voidSetFilter(Sensor_Filter Copy_eFilter);
u8 HTCS3200_u8MapToRGB(u32 Copy_u32InputValue, u32 Copy_u32InputMin, u32 Copy_u32InputMax);
Color HTCS3200_eGetColor();

#endif /* HTCS3200_INTERFACE_H_ */
