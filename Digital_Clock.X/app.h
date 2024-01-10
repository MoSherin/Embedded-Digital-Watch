/* 
 * File:   app.h
 * Author: lenovo
 *
 * Created on October 2, 2023, 11:22 AM
 */

#ifndef APP_H
#define	APP_H


/*Section: Includes*/
#include "ECU-Layer/LED/ecu_led.h"
#include "ECU-Layer/BUTTON/ecu_button.h"
#include "ECU-Layer/RELAY/ecu_relay.h"
#include "ECU-Layer/MOTOR/ecu_motor.h"
#include "MCAL_Layer/Interupt/hal_ext_interupt.h"
#include "MCAL_Layer/Timer0/hal_timer0.h"

/*Section: Macro Declarations*/
#define ZERO                 0
#define DELAY                10
#define CLOCK_MODE           1
#define STOP_WATCH_MODE      2
#define SET_TIME_MODE        3
#define PAUSE_SET            1
#define PAUSE_RESET          2
#define ONE_SECOND           80 /* It's not exactly 100 millisecond due to using the delay function*/
#define ONE_MINUTE           60
#define ONE_HOUR             60
#define ONE_DAY              24
#define BLINK_DELAY          35
#define FLAG_IS_SET          0
#define FLAG_IS_RESET        1
#define SET_SECS             1
#define SET_MINS             2
#define SET_HOURS            3
#define MODE_RESET_VALUE     4
#define SET_MODE_RESET_VALUE 4
#define PAUSE_RESET_VALUE    3

/*Section: Macro Functions*/

/*Section: Functions Declarations*/
void set_time(void);
void diplay_time(uint8 hours, uint8 mins, uint8 secs);
void diplay_time_secs_blink(uint8 hours, uint8 mins, uint8 secs);
void diplay_time_mins_blink(uint8 hours, uint8 mins, uint8 secs);
void diplay_time_hours_blink(uint8 hours, uint8 mins, uint8 secs);
void IN0_APP_ISR(void);
void IN1_APP_ISR(void);
void IN2_APP_ISR(void);
void TMR0_APP_ISR(void);


/*Section: Data Type Declarations*/
EXT_Interupt_t mode_button = {Interupt_Pin(PORTB_INDEX, PIN0), .Edge = Rising_Edge, .EXT_InteruptHandler = IN0_APP_ISR, .source = INT0_PIN};
EXT_Interupt_t pause_button = {Interupt_Pin(PORTB_INDEX, PIN1), .Edge = Rising_Edge, .EXT_InteruptHandler = IN1_APP_ISR, .source = INT1_PIN};
EXT_Interupt_t reset_button = {Interupt_Pin(PORTB_INDEX, PIN2), .Edge = Rising_Edge, .EXT_InteruptHandler = IN2_APP_ISR, .source = INT2_PIN};


timer0_t timer = {.bit_mode = TIMER0_16BIT_MODE, .interrupt_priority = LOW_PRIORITY, .mode = TIMER0_CLOCK_MODE, 
                  .preload_value = 45536, .prescaler = TIMER0_PRESCALER_DISABLE, .timer0_interrupt_handler = TMR0_APP_ISR};


Std_ReturnType ret = E_OK;
uint8 mode = CLOCK_MODE;
uint8 pause = PAUSE_RESET;
uint8 hours = 7, mins = 17, secs = 55, milli_seconds;
uint8 stop_milli_seconds, stop_seconds, stop_minutes;
uint8 set_mode = SET_SECS;
uint8 set_millis;
uint8 delay_flag;

#endif	/* APP_H */

