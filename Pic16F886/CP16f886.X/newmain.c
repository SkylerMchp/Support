#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
#if 1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
#endif
#include <xc.h>
void delay()
{   volatile long int i;
    for(i=0;i<=0xFF;i++)
    {asm("NOP");}
}

void TIMER2_INIT()
{
        TMR2 = 0;
        PR2 = 255;
        TMR2IF = 0;
        T2CKPS0 = 1;
        T2CKPS1 = 0;
        TMR2ON = 1;
}

void interrupt ISR(void)
{
        if(TMR2IF == 1)
        {
                TMR2IF = 0;
        }        
}

void main(void) {
    
    volatile int i;

//    TIMER2_INIT();
    TRISB = 0;      
    PORTB=0x01;
//    TMR2 = 0x00;
    while(1)
    {
        
        PORTB=0x00;
        delay();
        PORTB=0xFF;
        delay();
    }
    return;
}
