/*
 * ADC_prog.c
 *
 *  Created on: Mar 3, 2023
 *      Author: LENOVO
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"

#include "ADC_cfg.h"
#include "ADC_priv.h"
#include "ADC_types.h"
#include "ADC_init.h"




void M_ADC_Void_Init(const ADC_CONFIG *Ptr_ConfigType)
{

	ADC_ADMUX &= ADC_CLEAR_REF_ADJUST ;

	/*Configure the Reference Type */
	switch(Ptr_ConfigType->RefranceType)
	{
	case ADC_AREF_OFF:
		ADC_ADMUX |= ADC_AREF_OFF << ADC_REF_SET_BIT ;
		break;
	case ADC_AVCC:
		ADC_ADMUX |= ADC_AVCC << ADC_REF_SET_BIT ;
		break;
	case ADC_INTERNAL:
		ADC_ADMUX |= ADC_INTERNAL << ADC_REF_SET_BIT ;
		break;
	}

	/* Configure the Adjustable type*/
	switch(Ptr_ConfigType->AdjustableType)
	{
	case ADC_RIGHT_ADJUST:
		CLR_BIT(ADC_ADMUX,ADMUX_ADLAR);
	break;

	case ADC_LEFT_ADJUST:
		SET_BIT(ADC_ADMUX,ADMUX_ADLAR);
	break;
	}

	/* Configure the Adjustable type*/

	switch(Ptr_ConfigType->PrescallerSelect)
	{
	case DIV_FACT_2:
		ADC_ADCSRA |= Ptr_ConfigType->PrescallerSelect ;
		break;

	case DIV_FACT_128:
		ADC_ADCSRA |= Ptr_ConfigType->PrescallerSelect ;
		break;
	}

	/*Enable ADC */
	SET_BIT(ADC_ADCSRA,ADCSRA_ADEN);
}


u16 M_ADC_Void_GetDigitalValueSynchNonBlocking(ADC_CHANNEL_TYPE Copy_ChannelType)
{
	u8 ConversionFlag = 0 ;
	u16 Local_Counter = 0 ;

	u16 Local_ConversionValue = 0;
	/* Clear Channel*/
	ADC_ADMUX &= ADC_CLEAR_CHANNEL ;

	/* Set Channel bits */
	ADC_ADMUX |= Copy_ChannelType ;

	/* Start Conversion */
	SET_BIT(ADC_ADCSRA,ADCSRA_ADSC);

	if (ConversionFlag == 0)
	{
		while((GET_BIT(ADC_ADCSRA,ADCSRA_ADSC) == 1) || (Local_Counter == 50000))
		{
			Local_Counter ++ ;
		}

		/* Rest Counter */
		Local_Counter = 0;

		/*Calculate Value of Conversion */
		ConversionFlag = 1;
		}


	return ADC_ADCL;
}


