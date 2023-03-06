/*
 * ADC_init.h
 *
 *  Created on: Mar 3, 2023
 *      Author: LENOVO
 */


#ifndef ADC_ADC_INIT_H_
#define ADC_ADC_INIT_H_

#include "ADC_types.h"

void M_ADC_Void_Init(const ADC_CONFIG *Ptr_ConfigType);
u16 M_ADC_Void_GetDigitalValueSynchNonBlocking (ADC_CHANNEL_TYPE Copy_ChannelType);

u16 ADC_getDigitalValueAsynchCallBack();

#endif /* ADC_ADC_INIT_H_ */
