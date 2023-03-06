/*
 * LCD_priv.h
 *
 *  Created on: Feb 19, 2023
 *      Author: LENOVO
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_

//static void H_LCD_void_latchByte(u8 copy_u8Byte);

#define LCD_CLEAR_DISP		0x01	//YES
#define LCD_RETURN_HOME 	0x02
#define LCD_ENTRY_MODE  	0x06	//YES
#define LCD_DISPLAY_ON		0x0c	//YES
#define LCD_DISPLAY_OFF		0x00
#define LCD_FUNCTION_SET	0x38
#define LCD_SET_CGRAM_P1

#endif /* LCD_LCD_PRIV_H_ */
