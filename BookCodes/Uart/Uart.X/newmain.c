/*** DEVCFG0 ***/
#pragma config DEBUG =      ON
#pragma config JTAGEN =     OFF
#pragma config ICESEL =     ICS_PGx2
#pragma config TRCEN =      OFF
#pragma config BOOTISA =    MIPS32
#pragma config FECCCON =    OFF_UNLOCKED
#pragma config FSLEEP =     OFF
#pragma config DBGPER =     PG_ALL
#pragma config SMCLR =      MCLR_NORM
#pragma config SOSCGAIN =   GAIN_LEVEL_3
#pragma config SOSCBOOST =  ON
#pragma config POSCGAIN =   GAIN_LEVEL_3
#pragma config POSCBOOST =  ON
#pragma config EJTAGBEN =   NORMAL
#pragma config CP =         OFF
/*** DEVCFG1 ***/
#pragma config FNOSC =      FRCDIV
#pragma config DMTINTV =    WIN_127_128
#pragma config FSOSCEN =    OFF
#pragma config IESO =       OFF
#pragma config POSCMOD =    OFF
#pragma config OSCIOFNC =   OFF
#pragma config FCKSM =      CSECME
#pragma config WDTPS =      PS1048576
#pragma config WDTSPGM =    STOP
#pragma config FWDTEN =     OFF
#pragma config WINDIS =     NORMAL
#pragma config FWDTWINSZ =  WINSZ_25
#pragma config DMTCNT =     DMT31
#pragma config FDMTEN =     OFF
/*** DEVCFG2 ***/
#pragma config FPLLIDIV =   DIV_1
#pragma config FPLLRNG =    RANGE_5_10_MHZ
#pragma config FPLLICLK =   PLL_FRC
#pragma config FPLLMULT =   MUL_50
#pragma config FPLLODIV =   DIV_2
#pragma config UPLLFSEL =   FREQ_24MHZ
/*** DEVCFG3 ***/
#pragma config USERID =     0xffff
#pragma config FMIIEN =     ON
#pragma config FETHIO =     ON
#pragma config PGL1WAY =    ON
#pragma config PMDL1WAY =   ON
#pragma config IOL1WAY =    ON
#pragma config FUSBIDIO =   ON
/*** BF1SEQ0 ***/
#pragma config TSEQ =       0x0000
#pragma config CSEQ =       0xffff
#include <xc.h>
char UART1_getc(void) 
{
    while (!U1STAbits.URXDA);   // wait until character received
    return U1RXREG;             // read character
}
void UART1_putc (char c)
{
    while (U1STAbits.UTXBF);    // wait until transmit buffer not full
    U1TXREG = c;                // transmit character
}
void UART1_puts (char *s)
{
    while (*s != '\0') UART1_putc (*s++);
}
void main(void)
{
    unsigned char c;
    U1RXR=0;    // RD2 as Uart1 RX --> Pin110
    RPD3R=0x01; // RD3 as Uart1 TX --> Pin111
    U1STAbits.UTXEN = 1;   // enable transmit pin
    U1STAbits.URXEN = 1;   // enable receive pin
    U1BRG           = 0x67;
    U1MODESET       = 0x08;
    U1MODEbits.ON   = 1;   // enable UART
    UART1_puts("\r\nHello, World!\r\nPlease press a key.\r\n");
    while(1)
    {   c = UART1_getc();
        UART1_putc('[');
        UART1_putc (c);
        UART1_puts("]\r\n"); 
    }
    return;
}
