/*
 * TIMER0_prog.c
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "avr/interrupt.h"
#include "Mcu_HW.h"
#include "TIMER0_priv.h"
#include "TIMER0_types.h"
#include "TIMER0_int.h"
//#include "LCD_Init.h"


void (*Timer0CallBackFunc[TIMER0_ARR_SIZE])(void) = {NULL} ;

u32 NoOfOverFlow = 0;
static u32 NoOfRemaning = 0;
 u32 Counter_NoOverFlow = 0 ;
static u32 Global_NoComparMatch = 0 ;

void M_TIMER0_Void_Init(TIMER0_MODE_TYPE Local_Mode,TIMER0_WG_TYPE Local_WG_Type)
{

	/*Clear Mode Bits */
	TIMER0_TCCR0 &= TIMER0_CLEAR_MODE_MASK ;

	/*Check the mode type */
	switch(Local_Mode)
	{
	case NORMAL_MODE:
		TIMER0_TCCR0 |= TIMER0_NORMAL_MODE_MASK ;
		break ;
	case PHASE_PWM_MODE:
		TIMER0_TCCR0 |= TIMER0_PWM_PHASE_MODE_MASK ;
		break ;
	case CTC_MODE:
		TIMER0_TCCR0 |= TIMER0_CTC_MODE_MASK ;
		break ;
	case FAST_PWM_MODE:
		TIMER0_TCCR0 |= TIMER0_PWM_FAST_MASK ;
		break ;
	}


	/*Check the wave generation signal */
	TIMER0_TCCR0 &= TIMER0_WG_CLEAR_ALL_MASK ;

	/* Check Wave Generation*/
	switch(Local_WG_Type)
	{
		case WG_NORMAL_PORT:
			TIMER0_TCCR0 |= TIMER0_WG_NORMAL_MASK ;
			break;

		case WG_TOGGLE_OC0:
			TIMER0_TCCR0 |= TIMER0_WG_TOGGLE_MASK ;
			break;

		case WG_CLEAR_OC0:
			TIMER0_TCCR0 |= TIMER0_WG_CLEAR_MASK ;
			break;

		case WG_SET_OC0:
			TIMER0_TCCR0 |= TIMER0_WG_SET_MASK;
			break;

		case WG_INVERTING:
			TIMER0_TCCR0 |= TIMER0_WG_INVERTING_MASK;
			break;

		case WG_NON_INVERTING:
			TIMER0_TCCR0 |= TIMER0_WG_NON_INVERTING_MASK;
			break;
		}
}

void M_TIMER0_Void_Start(TIMER0_PRESCALLER_SELECT Local_PrescallerSelect)
{
	/* Clear Prescaller */
	TIMER0_TCCR0 &= TIMER0_CLEAR_PRESCALLER_MASK ;

	/*Set Prescaller */
	TIMER0_TCCR0 |=  Local_PrescallerSelect;

}
void M_TIMER0_Void_Stop()
{
	TIMER0_TCCR0 |= TIMER0_CLEAR_PRESCALLER_MASK;

}

void M_TIMER0_Void_StopOCR0()
{
	/* Disable OCR0*/
	TIMER0_TCCR0 &= TIMER0_WG_CLEAR_ALL_MASK ;

}

u8 M_TIMER0_Void_GetCount(TIMER0_MODE_TYPE Local_Mode)
{
	u8 Local_ReturnCount  ;

	if (Local_Mode == NORMAL_MODE)
	{
	Local_ReturnCount = (256 * Counter_NoOverFlow) + TIMER0_TCNT0;
	}
	else if (Local_Mode == CTC_MODE)
	{
		Local_ReturnCount = 255 * Global_NoComparMatch;
	}


	return Local_ReturnCount ;
}


void M_TIMER0_setDelayTimeMilliSec(u32 Local_DelayTime, TIMER0_MODE_TYPE Local_Mode, TIMER0_PRESCALLER_SELECT Local_Prescaller)
{
	u32 Local_Prescaller_Arr[5] = {1,8,64,256,1024};

	f32 TickTime = (f32)Local_Prescaller_Arr[Local_Prescaller-1]/ F_CPU ;
	u32 DesiredTickS = 0;
	u32 CTC_Value = 0 ;



	/* Calculate the desired Tick*/
	 DesiredTickS = (f32)Local_DelayTime / TickTime ;

	if(Local_Mode == NORMAL_MODE)
	{
		 /*Store the numbers of over flow */
			 NoOfOverFlow = ( DesiredTickS/ 256 ) / 2  ;

		 /* Store the Number of remaining if found */
		 NoOfRemaning = DesiredTickS % 256;

		 /*if there is remaining then start from it */
		 if(NoOfRemaning != 0)
		 {
			 TIMER0_TCNT0 = 256 - NoOfRemaning ;
			 NoOfOverFlow++ ;

		 }
	}
	else if(Local_Mode == CTC_MODE)
	{
		CTC_Value = 255 ;
		u32 NoOfCompMatch = 0;

		while(DesiredTickS % CTC_Value)
		{
			CTC_Value -- ;
		}
		NoOfCompMatch = DesiredTickS % CTC_Value ;
		TIMER0_OCR0 = NoOfCompMatch;
	}
	else if(Local_Mode == FAST_PWM_MODE)
	{

	}
}


void M_TIMER0_EnableInt(TIMER0_INTERRUPT_TYPE Local_InterruptType)
{
	if (Local_InterruptType == COMPARE_MATCH)
	{
		SET_BIT(TIMER0_TIMSK, TIMSK_OCIE0);
	}
	else if (Local_InterruptType == OVRER_FLOW)
	{
		SET_BIT(TIMER0_TIMSK, TIMSK_TOIE0);
	}
	else
	{
		/* No Interrupt in PWM Modes */
	}

}

void M_TIMER0_void_SetPhaseCorrectPWM(u16 Copy_Frequancy, u16 Copy_DutyCycle)
{
	TIMER0_TCCR0 &= TIMER0_CLEAR_MODE_MASK ;
	TIMER0_TCCR0 |= TIMER0_PWM_PHASE_MODE_MASK ;

	u16 FreqnacyArr[5] = {31250,3906,488,122,30};
	u8 LocalCounter = 0 ;
	u16 Local_Frequancy = 0 ;

	for(LocalCounter = 0 ; LocalCounter < 5 ; LocalCounter ++)
	{
		if(FreqnacyArr[LocalCounter] > Copy_Frequancy )
		{

			Local_Frequancy = FreqnacyArr[LocalCounter+1] ;

		}
	}

	for (LocalCounter = 0 ; LocalCounter < 5 ; LocalCounter ++)
	{
		if (Local_Frequancy ==FreqnacyArr[LocalCounter] )
		{
			Local_Frequancy = LocalCounter;
			break ;
		}
	}

	u8 X = 0 ;

	/* Set the value of Duty cycle to generate PWM */
	TIMER0_OCR0 =  (Copy_DutyCycle * 256) /100  ;
	X = TIMER0_OCR0 ;
	M_TIMER0_Void_Start(Local_Frequancy);
}

void M_TIMER0_DisableInt()
{
	CLR_BIT(TIMER0_TIMSK, TIMSK_OCIE0);
	CLR_BIT(TIMER0_TIMSK, TIMSK_TOIE0);
}


void M_TIMER0_setCallBack(TIMER0_INTERRUPT_TYPE Local_InterruptType ,void(*Local_CallBackFunc)(void))
{


	if (Local_CallBackFunc != NULL)
	{
		switch(Local_InterruptType)
		{
		case OVRER_FLOW:

			Timer0CallBackFunc[0] = Local_CallBackFunc ;
			break;

		case COMPARE_MATCH:
			Timer0CallBackFunc[1] = Local_CallBackFunc ;
			break;
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	Counter_NoOverFlow++ ;



	if (Counter_NoOverFlow == NoOfOverFlow)
	{
		Timer0CallBackFunc[0]();
		Counter_NoOverFlow = 0 ;
		TIMER0_TCNT0 = 256 - NoOfRemaning ;

	}

}


ISR(TIMER0_COMP_vect)
{

}


/*
 * TIMER0_priv.h
 *
 *  Created on: Feb 24, 2023
 *      Author: LENOVO
 */

#ifndef TIMER0_TIMER0_PRIV_H_
#define TIMER0_TIMER0_PRIV_H_

#define TIMER0_CLEAR_MODE_MASK			0xB7	// 0xD7

#define TIMER0_CLEAR_PRESCALLER_MASK	0xF8

#define TIMER0_NORMAL_MODE_MASK			0x00
#define TIMER0_PWM_PHASE_MODE_MASK		0x40
#define TIMER0_CTC_MODE_MASK			0x08
#define TIMER0_PWM_FAST_MASK			0x48

#define TIMER0_WG_CLEAR_ALL_MASK		0xCF

#define TIMER0_WG_NORMAL_MASK			0x00
#define TIMER0_WG_TOGGLE_MASK			0x10
#define TIMER0_WG_CLEAR_MASK			0x20
#define TIMER0_WG_SET_MASK				0x30
#define TIMER0_WG_NON_INVERTING_MASK	0x20
#define TIMER0_WG_INVERTING_MASK		0x30

/* Prescaller */
/*
#define NO_CLK_PRESCALLER_MASK			0xF8
#define CLK_NO_PRESCALLER_MASK			0x00
#define CLK_8_PRESCALLER_MASK			0x02
#define CLK_64_PRESCALLER_MASK			0x03
#define CLK_256_PRESCALLER_MASK			0x04
#define CLK_1024_PRESCALLER_MASK		0x05
*/

/* Pointer to function array size */

#define TIMER0_ARR_SIZE					2


#endif /* TIMER0_TIMER0_PRIV_H_ */
