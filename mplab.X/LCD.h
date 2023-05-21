#ifndef __LCD
#define __LCD


#define LCD_E              RD0    
#define LCD_RS             RD1     
#define LCD_Data_Bus_D4    RD4    
#define LCD_Data_Bus_D5    RD5    
#define LCD_Data_Bus_D6    RD6    
#define LCD_Data_Bus_D7    RD7 

#define LCD_E_Dir               TRISD0
#define LCD_RS_Dir              TRISD1
#define LCD_Data_Bus_Dir_D4     TRISD4
#define LCD_Data_Bus_Dir_D5     TRISD5
#define LCD_Data_Bus_Dir_D6     TRISD6
#define LCD_Data_Bus_Dir_D7     TRISD7
#define LCD_PORT PORTD
#define E_Delay       500


void InitLCD(void);//khoi tao lcd
void ToggleEpinOfLCD(void);
void WriteDataToLCD(char LCDChar);//Hien thi ky tu len lcd
void WriteStringToLCD(const char *s);//Hieu thi mot chuoi len LCD
void ClearLCDScreen(void);//Clear lcd
void WriteCommandToLCD(unsigned char);//ghi mot lenh len lcd
void GotoxyLCD(unsigned char, unsigned char);// dua con tro ?en vi tri cot, hang bat ki

#endif