/*
 * LM32_prog.c
 *
 *  Created on: Mar 3, 2023
 *      Author: LENOVO
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_cfg.h"
#include "ADC_init.h"
#include "ADC_types.h"
#include "LM32_types.h"
#include "LM32_init.h"

extern const ADC_CONFIG ADC_ConfigArrA[1];
void H_LM32_Void_Init()
{
	M_ADC_Void_Init(ADC_ConfigArrA);
}


u16 H_LM32_U16_ReadTemperature(ADC_CHANNEL_NAME Copy_ChannelName)
{
	u16 ADC_VALUE= 0 ;
	u16 Local_ConversionValue = 0;

	/* Pass the ADC value*/
	ADC_VALUE = M_ADC_Void_GetDigitalValueSynchNonBlocking(Copy_ChannelName) ;

	Local_ConversionValue = ((ADC_VALUE *5) /10)/2 ; // LM32 equation


	return  Local_ConversionValue ;

}
