/* LIB Layer */
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "MGIE_interface.h"
#include "MGIE_private.h"
#include "MGIE_config.h"

void MGIE_voidEnable(void){
    SET_BIT(PRIVATE_SREG, PRIVATE_SREG_I);
}
void MGIE_voidDisable(void){
    CLR_BIT(PRIVATE_SREG, PRIVATE_SREG_I);
}
