/*
 * ADC_types.h
 *
 *  Created on: Mar 3, 2023
 *      Author: LENOVO
 */

#ifndef ADC_ADC_TYPES_H_
#define ADC_ADC_TYPES_H_

typedef enum{
	ADC_AREF_OFF,
	ADC_AVCC,
	ADC_INTERNAL = 3

}REFRANCE_SELECT;

typedef enum{
	ADC_RIGHT_ADJUST,
	ADC_LEFT_ADJUST

}ADJUST_TYPE;

typedef enum{
	DIV_FACT_2,
//	DIV_FACT_R2,
//	DIV_FACT_4,
//	DIV_FACT_8,
//	DIV_FACT_16,
//	DIV_FACT_32,
//	DIV_FACT_64,
	DIV_FACT_128

}PRESCALLER_SELECT;

typedef enum{
	ENABLE_AUTO_TRIGG,
	DISABLE_AUTO_TRIGG

}AUTO_TRIGG_SELECT;

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7

}ADC_CHANNEL_TYPE;

#endif /* ADC_ADC_TYPES_H_ */
