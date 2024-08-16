# Smart Door System

This project implements a smart door system using an AVR microcontroller. It features a keypad for password and user ID input, and an LCD display for user feedback.

## Features

- Password-protected access
- User ID recognition
- LCD display for system messages
- Keypad input for password and user ID

## Hardware Requirements

- AVR microcontroller (e.g., ATmega32)
- 16x2 LCD display
- 4x4 Matrix keypad
- DC Motor (connected to PORTB0)
- Resistors and connecting wires as needed

## Software Requirements

- AVR-GCC compiler
- AVRDUDE (for flashing the microcontroller)
- Proteus (for simulation)

## File Structure

- `main.c`: Contains the main program logic
- `Lcd.h`: Header file for LCD functions
- `Keybad.h`: Header file for keypad functions

## Setup and Usage

1. Connect the hardware components as per the circuit diagram.
2. Compile the code using AVR-GCC.
3. Flash the compiled code to the AVR microcontroller.
4. Power on the system.

## Operation

1. The system prompts for a password on the LCD.
2. Enter the 4-digit password using the keypad.
3. If the password is correct, you'll be prompted to enter a 2-digit user ID.
4. If the user ID is valid, a welcome message is displayed along with the user's name.
5. The DC motor turns on to indicate successful access.
6. If the password is incorrect or the user ID is not found, appropriate error messages are displayed.

## Proteus Simulation

1. Open the Proteus simulation file.
2. Ensure all components are properly connected as per the circuit diagram.
3. Load the compiled hex file into the microcontroller in the simulation.
4. Run the simulation and interact with the keypad to test the system.

## Notes

- The default password is set to "1234".
- The system supports 4 user IDs: 01, 02, 03, and 04, corresponding to Rito, John, Rahaf, and Tifa respectively.
- Adjust the delay timings in the code if needed for your specific setup.

## Troubleshooting

- If the LCD doesn't display correctly, check the connections and contrast adjustment.
- Ensure the keypad is properly connected and functioning.
- Verify that the DC motor is connected to the correct port (PORTB0).
