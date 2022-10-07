

// Lcd module connections
sbit LCD_RS at LATD4_bit;
sbit LCD_EN at LATD5_bit;
sbit LCD_D4 at LATD0_bit;
sbit LCD_D5 at LATD1_bit;
sbit LCD_D6 at LATD2_bit;
sbit LCD_D7 at LATD3_bit;

sbit LCD_RS_Direction at TRISD4_bit;
sbit LCD_EN_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;

char txt1[] = "JB_BMS";

 float Battery_Voltage_1;
 float Battery_Voltage_2;
 float Battery_Voltage_3;
 float Battery_Voltage_4;
 unsigned char Voltage1_string[14];
 unsigned char Voltage2_string[14];
 unsigned char Voltage3_string[14];
 unsigned char Voltage4_string[14];

void main() {

 TRISA = 0b00001111;
 TRISB = 0;
 TRISC = 0;
 TRISD = 0;
 
 ANSELA = 0b00001111;
 ANSELB = 0;
 ANSELC = 0;
 ANSELD = 0;

 
 //OSCCON: OSCILLATOR CONTROL REGISTER
 IRCF2_bit = 1;
 IRCF1_bit = 1;
 IRCF0_bit = 1;          //111 = 16 MHz     110 = 8 MHz

 Lcd_Init();                        // Initialize LCD

 Lcd_Cmd(_LCD_CLEAR);               // Clear display
 Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
 
 // ADC_Init();
 
  ADC_Init_Advanced(_ADC_INTERNAL_FVRH4);
   LATB0_bit = 0;

 while(1){





   
   Battery_Voltage_1 = ADC_Get_Sample(0);              //THE ONLY REAL KNOWN VOLTAGE
   Battery_Voltage_1 = 0.004 * Battery_Voltage_1;
   floatToStr(Battery_Voltage_1, Voltage1_String);
   Lcd_Out(1,4,Voltage1_string);
   Delay_ms(30);


   Battery_Voltage_2 = ADC_Get_Sample(1);
   Battery_Voltage_2 = 0.004 * Battery_Voltage_2;
   Battery_Voltage_2 = Battery_Voltage_2 * 2;
   Battery_Voltage_2 = Battery_Voltage_2 - Battery_Voltage_1;

   floatToStr(Battery_Voltage_2, Voltage2_String);
   Lcd_Out(2,4,Voltage2_string);
   Delay_ms(30);

   Battery_Voltage_3 = ADC_Get_Sample(2);
   Battery_Voltage_3 = 0.004 * Battery_Voltage_3;
   Battery_Voltage_3 = Battery_Voltage_3 * 3;
   Battery_Voltage_3 = Battery_Voltage_3 - Battery_Voltage_1;
   Battery_Voltage_3 = Battery_Voltage_3 - Battery_Voltage_2;
   floatToStr(Battery_Voltage_3, Voltage3_String);
   Lcd_Out(3,0,Voltage3_string);
   Delay_ms(30);
   
   Battery_Voltage_4 = ADC_Get_Sample(3);
   Battery_Voltage_4 = 0.004 * Battery_Voltage_4;
   Battery_Voltage_4 = Battery_Voltage_4 * 4;
   Battery_Voltage_4 = Battery_Voltage_4 - Battery_Voltage_1;
   Battery_Voltage_4 = Battery_Voltage_4 - Battery_Voltage_2;
   Battery_Voltage_4 = Battery_Voltage_4 - Battery_Voltage_3;

   floatToStr(Battery_Voltage_4, Voltage4_String);
   Lcd_Out(4,0,Voltage4_string);
   Delay_ms(30);


 
 
 
 
 
 }









}