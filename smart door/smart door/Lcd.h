/*
 * Lcd.h
 *
 * Created: 8/7/2024 7:28:52 AM
 *  Author: Ritaj
 */ 

#ifndef LCD_H_
#define LCD_H_
#define LCD_DATA_PORT PORTD
#define LCD_CTRL_PORT PORTC
#define RS_PIN PC0
#define RW_PIN PC1
#define E_PIN  PC2
void LCD_Command(unsigned char x){
	LCD_DATA_PORT=x;
	LCD_CTRL_PORT&=~(1<<RS_PIN);
	LCD_CTRL_PORT&=~(1<<RW_PIN);
	LCD_CTRL_PORT|=(1<<E_PIN);
	_delay_ms(1);
	LCD_CTRL_PORT&=~(1<<E_PIN);
	
	
}
void LCD_data( char data){
	LCD_DATA_PORT=data;
	LCD_CTRL_PORT|=(1<<RS_PIN);
	LCD_CTRL_PORT&=~(1<<RW_PIN);
	LCD_CTRL_PORT|=(1<<E_PIN);
	_delay_ms(1);
	LCD_CTRL_PORT&=~(1<<E_PIN);
	_delay_ms(1);
	
}

void LCD_string(const char *str){
	for (int i=0;str[i]!='\0';i++)
	{
		LCD_data(str[i]);
		_delay_ms(100);
	}
}

void LCD_init(){
	DDRD=0xff;
	DDRC|=(1<<RS_PIN)|(1<<RW_PIN)|(1<<E_PIN);
	_delay_ms(20);
	LCD_Command(0x38);
	LCD_Command(0x0E);
	LCD_Command(0x01);
	_delay_ms(2);
}




#endif /* LCD_H_ */
