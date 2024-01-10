/*
 * File:   app.c
 * Author: Mohamed Sherin Mohmaed
 *
 * Created on October 2, 2023, 10:28 AM
 */

#include "app.h"




int main() {
    ret = gpio_port_direction_inti(PORTC_INDEX, OUTPUT);
    ret = gpio_port_direction_inti(PORTD_INDEX, OUTPUT);
    EXT_Interupt_Init(&mode_button);
    EXT_Interupt_Init(&pause_button);
    EXT_Interupt_Init(&reset_button);
    timer0_inti(&timer);
    while(1)
    {
        switch(mode){
            case CLOCK_MODE:
                diplay_time(hours, mins, secs);
                break;
            case STOP_WATCH_MODE:
                diplay_time(stop_minutes, stop_seconds, stop_milli_seconds);
                break;
            case SET_TIME_MODE:
                diplay_time(hours, mins, secs);
                break;
        }
    }    
        return 0;
}


void diplay_time(uint8 hours, uint8 mins, uint8 secs){
    if(!(SET_TIME_MODE == mode && SET_HOURS == set_mode && FLAG_IS_RESET == delay_flag) || CLOCK_MODE == mode || STOP_WATCH_MODE == mode)
    {
        ret = gpio_port_write_logic(PORTD_INDEX, 0x01);
        ret = gpio_port_write_logic(PORTC_INDEX, hours / 10);
         __delay_ms(DELAY);

        ret = gpio_port_write_logic(PORTD_INDEX, 0x02);
        ret = gpio_port_write_logic(PORTC_INDEX, hours%10);
        __delay_ms(DELAY);
    }
    else {/* Nothing */}
    
    if(!(SET_TIME_MODE == mode && SET_MINS == set_mode && FLAG_IS_RESET == delay_flag) || CLOCK_MODE == mode || STOP_WATCH_MODE == mode)
    {
        ret = gpio_port_write_logic(PORTD_INDEX, 0x08);
        ret = gpio_port_write_logic(PORTC_INDEX, mins / 10);
        __delay_ms(DELAY);

        ret = gpio_port_write_logic(PORTD_INDEX, 0x10);
        ret = gpio_port_write_logic(PORTC_INDEX, mins%10);
        __delay_ms(DELAY);
    }
    else {/* Nothing */}

    if(!(SET_TIME_MODE == mode && SET_SECS == set_mode && FLAG_IS_RESET == delay_flag) || CLOCK_MODE == mode || STOP_WATCH_MODE == mode)
    {
        ret = gpio_port_write_logic(PORTD_INDEX, 0x40);
        ret = gpio_port_write_logic(PORTC_INDEX, secs / 10);
        __delay_ms(DELAY);

        ret = gpio_port_write_logic(PORTD_INDEX, 0x80);
        ret = gpio_port_write_logic(PORTC_INDEX, secs%10);
        __delay_ms(DELAY);
    }
    else {/* Nothing */}
    
}


void IN0_APP_ISR(void){
    mode++;
    if(MODE_RESET_VALUE == mode)
    {
        mode = CLOCK_MODE;
        set_mode = SET_SECS;
    }
    else if(STOP_WATCH_MODE == mode)
    {
        stop_milli_seconds = ZERO; stop_seconds = ZERO; stop_minutes = ZERO;
    }
    else {/* Nothing */}
}

void IN1_APP_ISR(void){
    if(SET_TIME_MODE == mode)
    {
        set_mode++;
        if(SET_MODE_RESET_VALUE == set_mode)
        {
            set_mode = SET_SECS;
        }
        else {/* Nothing */}
    }
    else if(STOP_WATCH_MODE == mode)
    {
     pause++;
     if(PAUSE_RESET_VALUE == pause)
     {
         pause = PAUSE_SET;
     }
     else {/* Nothing */}
    }
}
void IN2_APP_ISR(void){
    if(SET_TIME_MODE == mode)
    {
        switch(set_mode){
            case SET_SECS:
                secs = ZERO;
                break;
            case SET_MINS:
                mins++;
                break;
            case SET_HOURS:
                hours++;
                break;
        }
    }
    else
    {
        stop_milli_seconds = ZERO; stop_seconds = ZERO; stop_minutes = ZERO;
        if(PAUSE_SET == pause)
        {
            pause++;
        }
        else {/* Nothing */}
    }
    
}

void TMR0_APP_ISR(void){
    milli_seconds++;
    if(ONE_SECOND == milli_seconds)
    {
        milli_seconds = 0;
        secs++;
    }
    else if(ONE_MINUTE == secs)
    {
        mins++;
        secs = ZERO;
    }
    else if(ONE_HOUR == mins)
    {
        hours++;
        mins = ZERO;
    }
    else if(ONE_DAY == hours)
    {
    hours = ZERO;
    }
    else {}
    if(SET_TIME_MODE == mode)
    {
        set_millis++;
        if(BLINK_DELAY == set_millis)
        {
            set_millis = 0;
            if(FLAG_IS_SET == delay_flag)
            {
                delay_flag = FLAG_IS_RESET;
            }
            else
            {
                delay_flag = FLAG_IS_SET;
            }
        }
    }
    else if(STOP_WATCH_MODE == mode)
    {
        if(PAUSE_SET == pause)
        {
            stop_milli_seconds++;
            if(ONE_SECOND == stop_milli_seconds)
            {
                stop_milli_seconds = ZERO;
                stop_seconds++;
            }
            else if(ONE_MINUTE == stop_seconds)
            {
                stop_seconds = ZERO;
                stop_minutes++;
            }
            else if(ONE_HOUR == stop_minutes)
            {
                stop_minutes = ZERO;
            }
            else {/* Nothing */}
        }
        else {/* Nothing */}
    }
    else {/* Nothing */}
    
}
