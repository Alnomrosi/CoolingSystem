/*
 * DC_Motor.c
 *
 *  Created on: Mar 5, 2023
 *      Author: LENOVO
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_int.h"

#include "TIMER0_int.h"
#include "TIMER0_types.h"

#include "DcMotor_cfg.h"
#include "DcMotor_types.h"
#include "DcMotor_init.h"

void H_DcMotor_Void_ChangeDirection(MOTOR_DIR Copy_MotorDir)
{
	if(Copy_MotorDir == RIGHT_DIR)
	{
		M_Dio_void_setPinValue(DC_MOTOR_IN1_PIN, DIO_HIGH);
		M_Dio_void_setPinValue(DC_MOTOR_IN2_PIN, DIO_LOW);

	}
	else if (Copy_MotorDir == LEFT_DIR)
	{
		M_Dio_void_setPinValue(DC_MOTOR_IN1_PIN, DIO_LOW);
		M_Dio_void_setPinValue(DC_MOTOR_IN2_PIN, DIO_HIGH);
	}

}

void H_DcMotor_Void_STOP()
{
	M_Dio_void_setPinValue(DC_MOTOR_IN1_PIN, DIO_LOW);
	M_Dio_void_setPinValue(DC_MOTOR_IN2_PIN, DIO_LOW);
	M_TIMER0_Void_StopOCR0();
}


void H_DcMotor_Void_Start(u16 Copy_Frequancy, u16 Copy_DutyCycle)
{
	M_TIMER0_Void_Init(PHASE_PWM_MODE, WG_SET_OC0);
	M_TIMER0_void_SetPhaseCorrectPWM(Copy_Frequancy, Copy_DutyCycle);

}




