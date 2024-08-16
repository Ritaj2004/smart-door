/*
 * smart door.c
 *
 * Created: 8/16/2024 6:35:58 AM
 * Author : Ritaj
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"
#include "Keybad.h"
#include <string.h>

int main(void)
{   DDRB=0xff;
	char userID[3];
	char inputPassword[5];
	char correctPassword[5] = "1234";
	char userInfo[4][2][10] = {
		{"01", "Rito"},
		{"02", "John"},
		{"03", "Rahaf"},
		{"04", "Tifa"}
	};

	LCD_init();
	
	while (1)
	{
		LCD_Command(0x80); // Set cursor to the beginning of the first line
		LCD_string("Password:");
		keypad_scan(inputPassword, 4); // Get the 4-digit password
       
		if (strcmp(inputPassword, correctPassword) == 0) // Check if the password is correct
		{
			LCD_Command(0x01); // Clear LCD
			LCD_string(" ID:");
			keypad_scan(userID, 2); // Get the 2-digit user ID

			int found = 0;
			for (int i = 0; i < 4; i++)
			{
				if (strcmp(userID, userInfo[i][0]) == 0)
				{
					LCD_Command(0x01); // Clear LCD
					PORTB=0b00000001;
					LCD_string(" Welcome ");
					LCD_string(userInfo[i][1]);
					found = 1;
					break;
				}
			}

			if (!found)
			{
				LCD_Command(0xC0); // Clear LCD
				LCD_string(" ID Not Found");
			}
		}
		else
		{
			LCD_Command(0xC0); // Clear LCD
			LCD_string(" Wrong Password");
		}
		_delay_ms(1000);
        PORTB=0b00000000;
		_delay_ms(1000); // Delay before the next loop iteration
		LCD_Command(0x01); // Clear LCD for the next input
	}
}

