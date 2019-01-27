#pragma config FMIIEN = ON              // Ethernet RMII/MII Enable (MII Enabled)
#pragma config FETHIO = ON              // Ethernet I/O Pin Select (Default Ethernet I/O)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = ON            // USB USBID Selection (Controlled by the USB Module)
#pragma config FPLLIDIV = DIV_8         // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_34_68_MHZ// System PLL Input Range (34-68 MHz Input)
#pragma config FPLLICLK = PLL_FRC       // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_128       // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_32        // System PLL Output Clock Divider (32x Divider)
#pragma config UPLLFSEL = FREQ_24MHZ    // USB PLL Input Frequency Selection (USB PLL input is 24 MHz)
#pragma config FNOSC = FRCDIV           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enable SOSC)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON              // Deadman Timer Enable (Deadman Timer is enabled)
#pragma config DEBUG = ON               // Background Debugger Enable (Debugger is enabled)
#pragma config JTAGEN = ON              // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FECCCON = OFF_UNLOCKED   // Dynamic Flash ECC Configuration (ECC and Dynamic ECC are disabled (ECCCON bits are writable))
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable bit (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_2X       // Primary Oscillator Gain Control bits (2x gain setting)
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot (Normal EJTAG functionality)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)
#include <xc.h>
int main(int argc, char** argv) 
{
int result[3];
    /* initialize ADC calibration setting */
    ADC0CFG = DEVADC0;
    ADC1CFG = DEVADC1;
    ADC2CFG = DEVADC2;
    ADC3CFG = DEVADC3;
    ADC4CFG = DEVADC4;
    //ADC5CFG = DEVADC5;
    //ADC6CFG = DEVADC6;
    ADC7CFG = DEVADC7;
    /* Configure ADCCON1 */
    ADCCON1 = 0; // No ADCCON1 features are enabled including: Stop-in-Idle, turbo,
    // CVD mode, Fractional mode and scan trigger source.
    /* Configure ADCCON2 */
    ADCCON2 = 0; // Since, we are using only the Class 1 inputs, no setting is
    // required for ADCDIV
    /* Initialize warm up time register */
    ADCANCON = 0;
    ADCANCONbits.WKUPCLKCNT = 5; // Wakeup exponent = 32 * TADx
    /* Clock setting */
    ADCCON3 = 0;
    ADCCON3bits.ADCSEL = 0; // Select input clock source
    ADCCON3bits.CONCLKDIV = 1; // Control clock frequency is half of input clock
    ADCCON3bits.VREFSEL = 0; // Select AVDD and AVSS as reference source
    /* Select ADC sample time and conversion clock */
    ADC0TIMEbits.ADCDIV = 1; // ADC0 clock frequency is half of control clock = TAD0
    ADC0TIMEbits.SAMC = 5; // ADC0 sampling time = 5 * TAD0
    ADC0TIMEbits.SELRES = 3; // ADC0 resolution is 12 bits
    ADC1TIMEbits.ADCDIV = 1; // ADC1 clock frequency is half of control clock = TAD1
    ADC1TIMEbits.SAMC = 5; // ADC1 sampling time = 5 * TAD1
    ADC1TIMEbits.SELRES = 3; // ADC1 resolution is 12 bits
    ADC2TIMEbits.ADCDIV = 1; // ADC2 clock frequency is half of control clock = TAD2
    ADC2TIMEbits.SAMC = 5; // ADC2 sampling time = 5 * TAD2
    ADC2TIMEbits.SELRES = 3; // ADC2 resolution is 12 bits
    /* Select analog input for ADC modules, no presync trigger, not sync sampling */
    ADCTRGMODEbits.SH0ALT = 0; // ADC0 = AN0
    ADCTRGMODEbits.SH1ALT = 0; // ADC1 = AN1
    ADCTRGMODEbits.SH2ALT = 0; // ADC2 = AN2
    /* Select ADC input mode */
    ADCIMCON1bits.SIGN0 = 0; // unsigned data format
    ADCIMCON1bits.DIFF0 = 0; // Single ended mode
    ADCIMCON1bits.SIGN1 = 0; // unsigned data format
    ADCIMCON1bits.DIFF1 = 0; // Single ended mode
    ADCIMCON1bits.SIGN2 = 0; // unsigned data format
    ADCIMCON1bits.DIFF2 = 0; // Single ended mode
    /* Configure ADCGIRQENx */
    ADCGIRQEN1 = 0; // No interrupts are used
    ADCGIRQEN2 = 0;
    /* Configure ADCCSSx */
    ADCCSS1 = 0; // No scanning is used
    ADCCSS2 = 0;
    /* Configure ADCCMPCONx */
    ADCCMPCON1 = 0; // No digital comparators are used. Setting the ADCCMPCONx
    ADCCMPCON2 = 0; // register to '0' ensures that the comparator is disabled.
    ADCCMPCON3 = 0; // Other registers are ¡°don't care¡±.
    ADCCMPCON4 = 0;
    ADCCMPCON5 = 0;
    ADCCMPCON6 = 0;
    /* Configure ADCFLTRx */
    ADCFLTR1 = 0; // No oversampling filters are used.
    ADCFLTR2 = 0;
    ADCFLTR3 = 0;
    ADCFLTR4 = 0;
    ADCFLTR5 = 0;
    ADCFLTR6 = 0;
    /* Set up the trigger sources */
    ADCTRGSNSbits.LVL0 = 0;     // Edge trigger
    ADCTRGSNSbits.LVL1 = 0;     // Edge trigger
    ADCTRGSNSbits.LVL2 = 0;     // Edge trigger
    ADCTRG1bits.TRGSRC0 = 1;    // Set AN0 to trigger from software.
    ADCTRG1bits.TRGSRC1 = 1;    // Set AN1 to trigger from software.
    ADCTRG1bits.TRGSRC2 = 1;    // Set AN2 to trigger from software.
    /* Early interrupt */
    ADCEIEN1 = 0; // No early interrupt
    ADCEIEN2 = 0;
                                    /* Turn the ADC on */
    ADCCON1bits.ON = 1;             /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY);    // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT);      // Wait if there is a fault with the reference voltage
    /* Enable clock to analog circuit */
    ADCANCONbits.ANEN0 = 1;         // Enable the clock to analog bias
    ADCANCONbits.ANEN1 = 1;         // Enable the clock to analog bias
    ADCANCONbits.ANEN2 = 1;         // Enable the clock to analog bias
    /* Wait for ADC to be ready */
    while(!ADCANCONbits.WKRDY0);    // Wait until ADC0 is ready
    while(!ADCANCONbits.WKRDY1);    // Wait until ADC1 is ready
    while(!ADCANCONbits.WKRDY2);    // Wait until ADC2 is ready
    /* Enable the ADC module */
    ADCCON3bits.DIGEN0 = 1;         // Enable ADC0
    ADCCON3bits.DIGEN1 = 1;         // Enable ADC1
    ADCCON3bits.DIGEN2 = 1;         // Enable ADC2
    while(1)
    {                                               /* Trigger a conversion */
        ADCCON3bits.GSWTRG = 1;                     /* Wait the conversions to complete */
        while (ADCDSTAT1bits.ARDY0 == 0);           /* fetch the result */
        result[0] = ADCDATA0;
        while (ADCDSTAT1bits.ARDY1 == 0);           /* fetch the result */
        result[1] = ADCDATA1;
        while (ADCDSTAT1bits.ARDY2 == 0);           /* fetch the result */
        result[2] = ADCDATA2;
    }
    return (1);
}