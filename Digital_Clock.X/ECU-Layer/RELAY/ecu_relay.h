/* 
 * File:   ecu_relay.h
 * Author: lenovo
 *
 * Created on October 14, 2023, 9:27 PM
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/*Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*Section: Macro Declarations*/

/*Section: Macro Functions*/

/*Section: Data Type Declarations*/
typedef enum{
    RELAY_OFF,
    RELAY_ON
}relay_state_t;


typedef struct{
    uint8         port : 4;
    uint8         pin : 3;
    relay_state_t relay_state;
}relay_t;

/*Section: Functions Declarations*/
Std_ReturnType relay_inti(relay_t *relay);
Std_ReturnType relay_write(relay_t *relay, logic_t logic);


#endif	/* ECU_RELAY_H */

