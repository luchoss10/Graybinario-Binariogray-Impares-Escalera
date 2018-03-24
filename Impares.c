#include <16f887.h>                   
#FUSES NOWDT, NOPUT, INTRC_IO, NOPROTECT, NOBROWNOUT, NOWRT
#use delay (internal=8M)          
#define LCD_ENABLE_PIN  PIN_D1                                    ////
#define LCD_RS_PIN      PIN_D0                                   ////
#define LCD_RW_PIN      PIN_B2                                    ////
#define LCD_DATA4       PIN_B4                                    ////
#define LCD_DATA5       PIN_B5                                    ////
#define LCD_DATA6       PIN_B6                                    ////
#define LCD_DATA7       PIN_B7 
#INCLUDE <lcd.c> //Libreria LCD

void main()
{
   //setup_oscillator(OSC_8MHZ|OSC_INTRC);
   //set_tris_d(0);//Por defecto es el puerto D por lo tanto lo establecemos como salida
   lcd_init();                            //Inicializamos LCD
   printf(lcd_putc,"Impares:");
   while(true){
   for(int i=1; i<=100; i++){
   if((i%2) != 0){
   lcd_gotoxy(1,2);
   printf(lcd_putc,"%u", i);//"Hola Mundo"
   delay_ms(500);
   }
   }
   lcd_gotoxy(1,2);
   printf(lcd_putc,"  ");
   }
}
