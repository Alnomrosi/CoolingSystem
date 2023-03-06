/*
 * DcMotor_init.h
 *
 *  Created on: Mar 5, 2023
 *      Author: LENOVO
 */

#ifndef DC_MOTOR_DCMOTOR_INIT_H_
#define DC_MOTOR_DCMOTOR_INIT_H_

#include "DcMotor_types.h"

void H_DcMotor_Void_ChangeDirection(MOTOR_DIR Copy_MotorDir);
void H_DcMotor_Void_STOP();
void H_DcMotor_Void_Start(u16 Copy_Frequancy, u16 Copy_DutyCycle);


#endif /* DC_MOTOR_DCMOTOR_INIT_H_ */
