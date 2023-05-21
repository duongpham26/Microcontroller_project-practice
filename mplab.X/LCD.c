#include "LCD.h"
#include <htc.h>
#define _XTAL_FREQ 8000000
void InitLCD(void)
{
    
    LCD_E               = 0;   // E  = 0
    LCD_RS              = 0;   // RS = 0
    LCD_Data_Bus_D4     = 0;    // Data bus = 0
    LCD_Data_Bus_D5     = 0;    // Data bus = 0
    LCD_Data_Bus_D6     = 0;    // Data bus = 0
    LCD_Data_Bus_D7     = 0;    // Data bus = 0
    LCD_E_Dir           = 0;   // Output
    LCD_RS_Dir          = 0;   // Output
    LCD_Data_Bus_Dir_D4 = 0;   // Output
    LCD_Data_Bus_Dir_D5 = 0;   //  Output
    LCD_Data_Bus_Dir_D6 = 0;   //  Output
    LCD_Data_Bus_Dir_D7 = 0;   //  Output
    
    // Reset process from datasheet 
    __delay_ms(40);
    LCD_PORT &= 0x0F;     
    LCD_PORT |= 0x30;      
    ToggleEpinOfLCD();      
    __delay_ms(6);
    LCD_PORT &= 0x0F;      
    LCD_PORT |= 0x30;      
    ToggleEpinOfLCD();      
    __delay_us(300);
    LCD_PORT &= 0x0F;      
    LCD_PORT |= 0x30;      
    ToggleEpinOfLCD();      
    __delay_ms(2);
    LCD_PORT &= 0x0F;     
    LCD_PORT |= 0x20;      
    ToggleEpinOfLCD();      
    __delay_ms(2);
    
    // Reset Process End 
    WriteCommandToLCD(0x28);    //function set
    WriteCommandToLCD(0x0D);    //display on,cursor off,blink on
    WriteCommandToLCD(0x01);    //clear display
    WriteCommandToLCD(0x06);    //entry mode, set increment
}

void ToggleEpinOfLCD(void)
{
    LCD_E = 1;                
    __delay_us(E_Delay);      
    LCD_E = 0;                
    __delay_us(E_Delay);
}

void WriteCommandToLCD(unsigned char Command)
{
    LCD_RS = 0;                
    LCD_PORT &= 0x0F;           
    LCD_PORT |= (Command&0xF0);     // Write high bit 
    ToggleEpinOfLCD();            
    LCD_PORT &= 0x0F;           
    LCD_PORT |= ((Command<<4)&0xF0); // Write Low bit
    ToggleEpinOfLCD();            
}

void WriteDataToLCD(char LCDChar)
{
    LCD_RS = 1;              
    LCD_PORT &= 0x0F;          
    LCD_PORT |= (LCDChar&0xF0);     // Write high bit 
    ToggleEpinOfLCD();          
    LCD_PORT &= 0x0F;           
    LCD_PORT |= ((LCDChar<<4)&0xF0); // Write Low bit
    ToggleEpinOfLCD();          
}

void WriteStringToLCD(const char *s)
{
    while(*s)
        WriteDataToLCD(*s++);   
}


void ClearLCDScreen(void)       // Clear the Screen and return cursor to zero position
{
    WriteCommandToLCD(0x01);    // Clear the screen
    __delay_ms(2);              // Delay for cursor to return at zero position

}

void GotoxyLCD(unsigned char col, unsigned char row)
{
	unsigned char address;
	if(row!=0)		
	{
        address=0xc0; //hang 1
        address += col;
    }		
	else
    {
        address=0x80; //hang 0
        address += col;
    }
    WriteCommandToLCD(address);	
    __delay_ms(40);
}
