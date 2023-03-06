/*
 * ADC_cfg.h
 *
 *  Created on: Mar 3, 2023
 *      Author: LENOVO
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_types.h"
typedef struct{
	REFRANCE_SELECT		RefranceType;
	ADJUST_TYPE			AdjustableType;
	PRESCALLER_SELECT	PrescallerSelect;
}ADC_CONFIG;


#endif /* ADC_CFG_H_ */
