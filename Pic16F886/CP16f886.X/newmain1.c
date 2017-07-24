#include <xc.h>
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
//-------------中断服务程序------------------------------------  
void interrupt isr()  
{  
    if(TMR2IE==1&&TMR2IF==1) 
    {TMR2IF=0;} 
}
void SpwmInit() 
{ 
    OSCCON=0x7f;//using inner 8M osc 
    TRISC1=1; 
    TRISC2=1; 
    //TRISD = 0; 
    PR2=0x27; 
    CCP1CON=0x0f|0x00; 
    CCPR1L=0x14; 
    TMR2IF=0; 
    T2CON=0; 
    GIE=0; 
    TMR2IE=1; 
    PEIE=1; 
    TMR2ON=1; 
} 

void main()  
{ 
    SpwmInit(); 
    TRISC1=0; 
    TRISC2=0; 
    while(1); 
}
