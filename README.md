# Embedded Digital Watch

This repository contains the source code and documentation for a digital watch project. The project utilizes a 7-segment display, push buttons, a 7447 decoder, resistors, and a PIC18F4620 microcontroller. The project makes use of the Timer 0 and External Interrupts modules in the PIC18F4620 microcontroller for accurate timekeeping and user interaction.

## Features

- Clock Mode: Displays the time accurately in hours, minutes, and seconds.
- Stopwatch Mode: Starts counting minutes, seconds, and milliseconds when the pause button is pressed and resets when the reset button is pressed.
- Set Time Mode: Allows you to set the time of the clock (hours, minutes, and seconds). The seconds are displayed as blinking digits, indicating that they can be changed. Pressing the reset button increments the value, and pressing the pause button toggles between hours and minutes for editing. Once the desired time is set, pressing the mode button saves and displays the new time on the clock.

## Hardware Requirements

- PIC18F4620 microcontroller
- 7-segment display module
- 7447 decoder
- Push buttons
- Resistors (for current limiting)
- Supporting circuitry (wiring, capacitors, etc.)

## Software Requirements

- MPLAB X IDE
- XC8 compiler

## Usage

1. Connect the hardware components (7-segment display, 7447 decoder, push buttons, resistors, and microcontroller) following the provided circuit diagram.
2. Open the project in MPLAB X IDE.
3. Build and program the code onto the PIC18F4620 microcontroller.
4. Power up the embedded system.
5. The watch will start in the clock mode, displaying the default time (7:17:55) in hours, minutes, and seconds.
6. To switch to the stopwatch mode, press the mode button and the pause button to start and pause the timer. Press the reset button to reset the stopwatch back to zero.
7. To enter the set time mode, press the mode button. The seconds digits will start blinking, indicating that they can be changed. Use the reset button to increment the value. Press the pause button to toggle between hours and minutes for editing. Once the desired time is set, press the mode button to save and display the new time.
8. Repeat steps 5-7 as needed to utilize the different modes of the digital watch.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.
