/*
 * Port_Lcfg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Lcfg.c
*  Module   : PORT
*  breif    : Config file for PORT Driver
*
*****************************************************************
*/
/******************************************
  INCLUDES
*******************************************/
#include "Std_Types.h"
#include "Port_types.h"
#include "Port_Cfg.h"


/******************************************
  Local Macros / Functions
*******************************************/


/******************************************
  Local Data
*******************************************/

/******************************************
  Global Data
*******************************************/

const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE]= {
		/*LCD PINS 4 bit mode */
        {PORT_PA2,
		PORT_PIN_LEVEL_LOW,
		 PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		 {PORT_PA3,
		 PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PB0,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PB1,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PB2,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PB4,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

        /*KEYPAD PINS Columns */
		{PORT_PD7,
		PORT_PIN_LEVEL_HIGH,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_PULLUP},
		{PORT_PD6,
		PORT_PIN_LEVEL_HIGH,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_PULLUP},
		{PORT_PD5,
		PORT_PIN_LEVEL_HIGH,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_PULLUP},
		{PORT_PD3,
		PORT_PIN_LEVEL_HIGH,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_PULLUP},

        /*KEYPAD PINS ROWS */
		{PORT_PC5,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PC4,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PC3,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		{PORT_PC2,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

        /*EXTI Pins */
        {PORT_PD2,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

		{PORT_PD3,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

		/*UltraSonic */
		{PORT_PD6,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_PULLUP},

		{PORT_PC0,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},
		/* ADC PIN */
		{PORT_PA0,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_INPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

		/* OCR0*/
		{PORT_PB3,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

		/* H-Bridge PINS*/
		{PORT_PB5,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING},

		{PORT_PB6,
		PORT_PIN_LEVEL_LOW,
		PORT_PINDIR_OUTPUT,
		PORT_PIN_IN_ATTATCH_FLOATING}



};
