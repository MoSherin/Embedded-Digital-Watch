#include "ecu_relay.h"

Std_ReturnType relay_inti(relay_t *relay){
    Std_ReturnType ret = E_OK;
    if(relay == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t relay_pin = {.port = relay->port, .pin = relay->pin, .direction = OUTPUT, .logic = LOW};
        ret = gpio_pin_inti(&relay_pin);
    }
    return ret;
}
Std_ReturnType relay_write(relay_t *relay, logic_t logic){
    Std_ReturnType ret = E_OK;
    if(relay == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config_t relay_pin = {.port = relay->port, .pin = relay->pin, .direction = OUTPUT, .logic = LOW};
        ret = gpio_pin_write_logic(&relay_pin, logic);
    }
    return ret;
}
