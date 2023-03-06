/*
 * main.c
 *
 *  Created on: Feb 25, 2023
 *      Author: LENOVO
 */

/***********************************************************************************************************************
 *		Includes
 *********************************************************************************************************************/
#include "avr/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Port_int.h"
#include "LCD_priv.h"
#include "LCD_cfg.h"
#include "LCD_types.h"
#include "LCD_Init.h"
#include "ADC_cfg.h"
#include "ADC_init.h"
#include "DcMotor_cfg.h"
#include "DcMotor_init.h"
#include "LM32_init.h"

/***********************************************************************************************************************
 *				Local Variables
 *********************************************************************************************************************/
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
#define MOTOR_FREQ		122
#define DutyCycle_50	205
#define DutyCycle_80	8


void main()
{
/***********************************************************************************************************************
 *				Local Variables
 *********************************************************************************************************************/
u16 Local_Temprature = 0 ;

/***********************************************************************************************************************
 *						Initiations Sections
 *********************************************************************************************************************/
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	H_LM32_Void_Init();

	while(1)
	{
		/*Check Temperature and display it on LCD */
		Local_Temprature = H_LM32_U16_ReadTemperature(CH_ADC0);
		H_LCD_void_gotoXY(0, 0);
		H_LCD_void_sendString("Temperature: ");
		H_LCD_void_sendIntNum(Local_Temprature);


		/*Check Temperature Conditions */
		if(Local_Temprature < 25)
		{
			H_DcMotor_Void_STOP();
		}
		else if (Local_Temprature > 25 && Local_Temprature < 35 )
		{
			H_DcMotor_Void_STOP();
			H_DcMotor_Void_Start(MOTOR_FREQ, DutyCycle_50); //50
			H_DcMotor_Void_ChangeDirection(RIGHT_DIR);
		}
		else if (Local_Temprature > 35 )
		{
			H_DcMotor_Void_STOP();
			H_DcMotor_Void_Start(MOTOR_FREQ,DutyCycle_80);	// 10
			H_DcMotor_Void_ChangeDirection(RIGHT_DIR);
		}


	}

}


