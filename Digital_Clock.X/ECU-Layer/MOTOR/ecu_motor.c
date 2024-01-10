#include "ecu_motor.h"

Std_ReturnType motor_inti(motor_t * motor){
    Std_ReturnType ret = E_OK;
    if(motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_1 = {.port = motor->port, .pin = motor->pin_1, .direction = OUTPUT, .logic = LOW};
        pin_config_t pin_2 = {.port = motor->port, .pin = motor->pin_2, .direction = OUTPUT, .logic = LOW};
        ret = gpio_pin_inti(&pin_1);
        ret = gpio_pin_inti(&pin_2);
    }
    return ret;
}
Std_ReturnType motor_forward(motor_t * motor){
     Std_ReturnType ret = E_OK;
    if(motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_1 = {.port = motor->port, .pin = motor->pin_1, .direction = OUTPUT, .logic = LOW};
        pin_config_t pin_2 = {.port = motor->port, .pin = motor->pin_2, .direction = OUTPUT, .logic = LOW};
        ret = gpio_pin_write_logic(&pin_1, HIGH);
        ret = gpio_pin_write_logic(&pin_2, LOW);
    }
    return ret;
}
Std_ReturnType motor_backward(motor_t * motor){
     Std_ReturnType ret = E_OK;
    if(motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_1 = {.port = motor->port, .pin = motor->pin_1, .direction = OUTPUT, .logic = LOW};
        pin_config_t pin_2 = {.port = motor->port, .pin = motor->pin_2, .direction = OUTPUT, .logic = LOW};
        ret = gpio_pin_write_logic(&pin_1, LOW);
        ret = gpio_pin_write_logic(&pin_2, HIGH);
    }
    return ret;
}
Std_ReturnType motor_stop(motor_t * motor){
    Std_ReturnType ret = E_OK;
    if(motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t pin_1 = {.port = motor->port, .pin = motor->pin_1, .direction = OUTPUT, .logic = LOW};
        pin_config_t pin_2 = {.port = motor->port, .pin = motor->pin_2, .direction = OUTPUT, .logic = LOW};
        ret = gpio_pin_write_logic(&pin_1, LOW);
        ret = gpio_pin_write_logic(&pin_2, LOW);
    }
    return ret;
}
