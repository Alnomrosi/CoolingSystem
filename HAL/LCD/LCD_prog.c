/*
 * LCD_prog.h
 *
 *  Created on: Feb 19, 2023
 *      Author: LENOVO
 */


#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_types.h"
#include "Dio_int.h"

#include "LCD_cfg.h"
#include "LCD_priv.h"
#include "LCD_types.h"
#include "LCD_Init.h"

static void H_LCD_void_latchByte(u8 copy_u8Byte);
/******************************************
  syntax : static void H_LCD_void_latchByte(u8 copy_u8Byte);

  Description : LatchByte

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  u8 copy_u8Byte
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
static void H_LCD_void_latchByte(u8 copy_u8Byte)
{

	M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
	M_Dio_void_setPinValue(LCD_D0_PIN,GET_BIT(copy_u8Byte,4));
	M_Dio_void_setPinValue(LCD_D1_PIN,GET_BIT(copy_u8Byte,5));
	M_Dio_void_setPinValue(LCD_D2_PIN,GET_BIT(copy_u8Byte,6));
	M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,7));
	M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);

	M_Dio_void_setPinValue(LCD_D0_PIN,GET_BIT(copy_u8Byte,0));
	M_Dio_void_setPinValue(LCD_D1_PIN,GET_BIT(copy_u8Byte,1));
	M_Dio_void_setPinValue(LCD_D2_PIN,GET_BIT(copy_u8Byte,2));
	M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,3));
	M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);

}

/******************************************
  syntax : H_LCD_void_Init()

  Description : LCD Initlization

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  Non
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_Init()
{
	_delay_ms(50);
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_LOW);
#if(LCD_MODE == _4_BIT_MODE)
	_delay_ms(1);
	H_LCD_void_sendCommand(0x02);
	_delay_ms(1);
	H_LCD_void_sendCommand(0x28);
	_delay_ms(1);
#endif

	H_LCD_void_sendCommand(LCD_DISPLAY_ON);
	_delay_ms(1);
	H_LCD_void_sendCommand(LCD_ENTRY_MODE);
	_delay_ms(1);

}
/******************************************
  syntax : void H_LCD_void_sendCommand(u8 copy_u8command)

  Description : LCD Send Command

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  u8 copy_u8command
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_sendCommand(u8 copy_u8command)
{
	/* RS = O*/
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_LOW);
	H_LCD_void_latchByte(copy_u8command);
}

/******************************************
  syntax : void H_LCD_void_sendData(u8 copy_u8data )

  Description : LCD Send Command

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  u8 copy_u8data
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_sendData(u8 copy_u8data )
{
	/* RS = 1*/
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_HIGH);
	H_LCD_void_latchByte(copy_u8data);

}

/******************************************
  syntax : void H_LCD_void_sendString(const s8 * pstr)

  Description : LCD Send Command

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  const s8 * pstr
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_sendString(const s8 * pstr)
{
	u8 Local_u8Counter = 0 ;

	/* loop to display all characters till Null Charactar*/
	while(pstr[Local_u8Counter] != '\0')
	{
		H_LCD_void_sendData(pstr[Local_u8Counter]);
		Local_u8Counter ++ ;
	}

}
/******************************************
  syntax : void H_LCD_void_sendIntNum(s32 copy_s32Num)

  Description : LCD Send Signed Integral Number

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  copy_s32Num
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
/* Local Variable to save the numbers digits*/
	s32 Local_Variable[8] = {0} ;
	u8 Local_Counter = 0 ;

	if (copy_s32Num == 0)
	{
		/* Commented this line because happen an error while reading data */
//		H_LCD_void_sendData('0');
	}

/* Check if the number is negative */
if (copy_s32Num < 0)
{
	/*Remove Negative Sign from number*/
	copy_s32Num = copy_s32Num * -1 ;
	/*Send Negative Sign */
	H_LCD_void_sendData('-');
}
/* While loop to split the Numbers and save it in Local_Variable*/
	while (copy_s32Num != 0)
	{
	Local_Variable[Local_Counter] = copy_s32Num % 10 ;
	copy_s32Num = copy_s32Num / 10 ;
	Local_Counter ++ ;

	}
/* For loop to send the numbers using SendData*/
	for (Local_Counter --; Local_Counter < '0' ; Local_Counter--)
	{
		 H_LCD_void_sendData('0' + Local_Variable[Local_Counter]);
	}
}

/******************************************
  syntax : void H_LCD_void_sendIntNum(s32 copy_s32Num)

  Description : LCD Send Signed Integral Number

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  copy_s32Num
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 Local_Address = 0 ;
	if (copy_u8Row == 0)
	{
		Local_Address = copy_u8Col ;
	}
	else if (copy_u8Row == 1)
	{
		Local_Address = copy_u8Col + 0x40;
	}

H_LCD_void_sendCommand(Local_Address + 128);

}

/******************************************
  syntax : void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)


  Description : Create Custom character

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  copy_s32Num
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{
	u8 Local_Counter = 0 ;

	/* Set CGRAM Address */
	H_LCD_void_sendCommand(0x40 + (copy_u8charCode*8));

	/* Store the 5x7 Symbol/Character in the CGRAM */
	for (Local_Counter = 0;Local_Counter <= 7;Local_Counter ++)
	{
		H_LCD_void_sendData(ArrPattern[Local_Counter]);

	}
	/* Set DDRAM Address */
	H_LCD_void_sendCommand(0x80 + copy_u8charCode);
}

/******************************************
  syntax : H_LCD_void_displayCustomChar(u8 copy_u8charCode)

  Description : Display the custom character

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  u8 copy_u8charCode
  parameters (out) :  Non
  Return Value     :  Non
******************************************/
void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{

/* Write the Symbol located in copy_u8charCode Location */
		H_LCD_void_sendData(copy_u8charCode);
}




