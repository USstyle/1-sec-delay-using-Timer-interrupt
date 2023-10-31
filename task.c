/*
 * File:   task.c
 * Author: udits
 *
 * Created on 7 October, 2023, 9:36 AM
 */


#include <xc.h>
// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000
void init(void);
unsigned char c;
void main(void) {
    init();
    while(1)
    {
        
    }
    return;
}
void __interrupt() _ISR()
{   
    
    if(PIR1 & 0x01)//checking for flag bit 
    {   
       
        c++;
        if(c==20)
        {
            PORTB=~PORTB;//tilt PORTD
            c=0;
        }
        TMR1 = 15535;
        PIR1&=0xFE;//clear flag
    }
}
void init()
{
    TRISB=0x00;//directing  as output
    PORTB=0x00;//all off
    TMR1=15535;//timer pre-loading
    T1CON=0x01;//TMR1ON=1
    INTCON=0xC0;//PEIE=GIE=1
    PIE1=0x01;//TMR1IE=1
}
