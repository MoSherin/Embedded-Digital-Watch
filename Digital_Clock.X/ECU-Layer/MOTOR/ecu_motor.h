/* 
 * File:   ecu_motor.h
 * Author: lenovo
 *
 * Created on October 14, 2023, 10:38 PM
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H

/*Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*Section: Macro Declarations*/

/*Section: Macro Functions*/

/*Section: Data Type Declarations*/
typedef enum{
    MOTOR_OFF,
    MOTOR_ON
}motor_state_t;

typedef struct{
    uint8 port  : 3;
    uint8 pin_1 : 3;
    uint8 pin_2 : 3;
}motor_t;
/*Section: Functions Declarations*/
Std_ReturnType motor_inti(motor_t * motor);
Std_ReturnType motor_forward(motor_t * motor);
Std_ReturnType motor_backward(motor_t * motor);
Std_ReturnType motor_stop(motor_t * motor);

#endif	/* ECU_MOTOR_H */

