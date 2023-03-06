/*
 * Mcu_HW.h
 *
 *  Created on: Feb 17, 2023
 *      Author: m.alnomrsi
 */
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Mcu_HW.h
*
*  breif    : this file contains all registers addresses
*
*****************************************************************
*/

#ifndef MCU_HW_H_
#define MCU_HW_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
//-------------------DIO-------------------
#define PORTA_REG (*((volatile u8*)0x3B))
#define DDRA_REG  (*((volatile u8*)0x3A))
#define PINA_REG  (*((volatile u8*)0x39))

#define PORTB_REG (*((volatile u8*)0x38))
#define DDRB_REG  (*((volatile u8*)0x37))
#define PINB_REG  (*((volatile u8*)0x36))

#define PORTC_REG (*((volatile u8*)0x35))
#define DDRC_REG  (*((volatile u8*)0x34))
#define PINC_REG  (*((volatile u8*)0x33))

#define PORTD_REG (*((volatile u8*)0x32))
#define DDRD_REG  (*((volatile u8*)0x31))
#define PIND_REG  (*((volatile u8*)0x30))
//------------------ END of DIO------------



//-----------------Interrupt-------------------
#define EXTI_MCUCR	(*((volatile u8*)0x55))
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0
#define EXTI_MCUCSR	(*((volatile u8*)0x54))


#define EXTI_GICR (*((volatile u8*)0x5B))
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

#define EXTI_GIFR (*((volatile u8*)0x5A))
#define GIFR_INTF	1 7
#define GIFR_INTF0 6
#define GIFR_INTF2 5

#define GLI_SREG (*((volatile u8*)0x5F))
#define SREG_GIE 7


//---------------Interrupt of DIO------------


//----------------TIMER0------------------
#define TIMER0_TCCR0 (*((volatile u8*)0x53))
#define TCCR0_FOC0	7
#define TCCR0_WGM00	6
#define TCCR0_COM00	5
#define TCCR0_COM01	4
#define TCCR0_WGM01	3
#define TCCR0_CS02	2
#define TCCR0_CS01	1
#define TCCR0_CS00	0

	/* Counter Register	 */

#define TIMER0_TCNT0 (*((volatile u8*) 0x52))

	/* Output compair Register	 */
#define TIMER0_OCR0	 (*((volatile u8*) 0x5C))

	/* Interrupt Mask Register	 */
#define TIMER0_TIMSK (*((volatile u8*)0x59))
#define TIMSK_OCIE0 1
#define TIMSK_TOIE0 0

#define TIMER0_TIFR (*((volatile u8*) 0x58))
#define TIFR_OCF0 1
#define TIFR_TOV0 0
//---------------End of TIMER0------------


//----------------TIMER0------------------
#define TIMER1_TCCR1A          (*((volatile u8*)0x4F)) //Timer Control Register
#define TCCR1A_COM1A1   7                     //channelA compare match output mode bit1
#define TCCR1A_COM1A0   6                     //channelA compare match output mode bit0
#define TCCR1A_WGM11    1                     //Wave form generation mode bit1
#define TCCR1A_WGM10    0                     //wave form generation mode bit0


#define TIMER1_TCCR1B          (*((volatile u16*)0x4E)) //Timer1 control register B
#define TCCR1B_ICES1    6                      //Input capture edge selection
#define TCCR1B_WGM13    4                      //Waveform generation mode bit3
#define TCCR1B_WGM12    3                      //Waveform generation mode bit 2
#define TCCR1B_CS12     2                      //prescaller bit2
#define TCCR1B_CS11     1                      //prescaller bit1
#define TCCR1B_CS10     0                      //Prescaller bit0

#define TIMER1_OCR1A           (*((volatile u16*)0x4A)) //channelA output compare match register

#define TIMER1_ICR1            (*((volatile u16*)0x46)) //Input capture register

#define TIMER1_TCNT1           (*((volatile u16*)0x4C)) //Timer1 register

#define TIMER1_TIMSK			(*((volatile u8*)0x59)) //Timer1 Iterrupt
#define TIMSK_TICIE1			5
#define TIMSK_OCIE1A			4
#define TIMSK_OCIE1B			3
#define TIMSK_TOIE1				2

#define TIMER1_TIFR			(*((volatile u8*)0x58)) //Timer1 Iterrupt
#define TIFR_ICF1			5
#define TIFR_OCF1A			4
#define TIFR_OCF1B			3
//---------------End of TIMER1------------



//----------------Start ADC------------------

#define ADC_ADMUX     			*((volatile u8*)0x27) //ADC MULTIPLIXER SELECTION REGISTER
#define ADMUX_REFS1        	7           //REFERENCE SELECTION BIT1
#define ADMUX_REFS0       	6           //reference selection bit0
#define ADMUX_ADLAR        	5           //ADC left adjust result


#define ADC_ADCSRA    			*((volatile u8*)0x26)  //ADC control and status register A

#define ADCSRA_ADEN        	7            //ADC ENABLE
#define ADCSRA_ADSC        	6            ///START CONVERSION
#define ADCSRA_ADATE       	5            //AUTO TRIGER ENABLE
#define ADCSRA_ADIF        	4            // INTERRUPT FLAG
#define ADCSRA_ADIE        	3            // INTERRUPT ENABLE
#define ADCSRA_ADPS2       	2            //PRESCALLER BIT2
#define ADCSRA_ADPS1       	1            //PRESCALLER BIT1
#define ADCSRA_ADPS0       	0            //PRESCALLER BIT0


#define ADC_ADCH      			*((volatile u8*)0x25)  //ADC high register

#define ADC_ADCL      			*((volatile u16*)0x24)  //ADC Low register

//---------------End of ADC------------




//----------------USART------------------
/*USART Control and status register A - UCSRA*/
#define USART_UCSRA                 *((volatile u8*)0x2b)
#define UCSRA_RXC             7  /*receive complete flag is set when receive is complete*/
#define UCSRA_TXC             6  /*transmit flag is set when transmit is complete*/
#define UCSRA_UDRE            5  /*data register empty flag is set if the register is empty and ready to send data */
#define UCSRA_FE              4  /*the flag is set when a frame error occurred - set this bit to zero*/
#define UCSRA_DOR             3  /*the flag is set when a data over run is detected - set this bit to zero*/
#define UCSRA_PE              2  /*the flag is set when a parity error occurred - set this bit to zero*/
#define UCSRA_U2X             1  /*setting this bit will double the speed of the transfer rate*/
#define UCSRA_MPCM            0  /*multi processor mode for synchronous operation*/


/*USART Control and status register B - UCSRB*/
#define USART_UCSRB                *((volatile u8*)0x2a)



/*USART Control and status register C - UCSRC*/
#define USART_UCSRC                *((volatile u8*)0x40)



#define USART_UBBRH                *((volatile u8*)0x40)
/*Baud rate registers*/
#define USART_UBBRL                *((volatile u8*)0x29)
#define USART_URSEL					15 	//selects between accessing the UBRRH or the UCSRC Register

//---------------End of USART------------



//----------------TIMER0------------------
//---------------End of TIMER1------------
/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

#endif /* MCU_HW_H_ */
