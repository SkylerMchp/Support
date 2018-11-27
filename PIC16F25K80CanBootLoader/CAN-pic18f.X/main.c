#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "init_device.h"
#include "CAN.h"
#include"flash.h"
#pragma config RETEN = OFF      // VREG Sleep Enable bit (Ultra low-power regulator is Disabled (Controlled by REGSLP bit))
#pragma config INTOSCSEL = HIGH // LF-INTOSC Low-power Enable bit (LF-INTOSC in High-power mode during Sleep)
#pragma config SOSCSEL = HIGH   // SOSC Power Selection and mode Configuration bits (High Power SOSC circuit selected)
#pragma config XINST = OFF       // Extended Instruction Set (Enabled)
// CONFIG1H
#pragma config FOSC = HS1       // Oscillator (HS oscillator (Medium power, 4 MHz - 16 MHz))
#pragma config PLLCFG = ON      // PLL x4 Enable bit (Enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor (Disabled)
#pragma config IESO = OFF       // Internal External Oscillator Switch Over Mode (Disabled)
// CONFIG2L
#pragma config PWRTEN = OFF     // Power Up Timer (Disabled)
#pragma config BOREN = SBORDIS  // Brown Out Detect (Enabled in hardware, SBOREN disabled)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (1.8V)
#pragma config BORPWR = ZPBORMV // BORMV Power level (ZPBORMV instead of BORMV is selected)
// CONFIG2H
#pragma config WDTEN = SWDTDIS  // Watchdog Timer (WDT enabled in hardware; SWDTEN bit disabled)
#pragma config WDTPS = 1048576  // Watchdog Postscaler (1:1048576)
// CONFIG3H
#ifdef CANUSE_PORTC
    #pragma config CANMX = PORTC    // ECAN Mux bit (ECAN TX and RX pins are located on RC6 and RC7, respectively)
#else
    #pragma config CANMX = PORTB    // ECAN Mux bit (ECAN TX and RX pins are located on RC6 and RC7, respectively)
#endif
#pragma config MSSPMSK = MSK7   // MSSP address masking (7 Bit address masking mode)
#pragma config MCLRE = ON       // Master Clear Enable (MCLR Enabled, RE3 Disabled)
// CONFIG4L
#pragma config STVREN = ON      // Stack Overflow Reset (Enabled)
#pragma config BBSIZ = BB2K     // Boot Block Size (2K word Boot Block size)
// CONFIG5L
#pragma config CP0 = OFF        // Code Protect 00800-01FFF (Disabled)
#pragma config CP1 = OFF        // Code Protect 02000-03FFF (Disabled)
#pragma config CP2 = OFF        // Code Protect 04000-05FFF (Disabled)
#pragma config CP3 = OFF        // Code Protect 06000-07FFF (Disabled)
// CONFIG5H
#pragma config CPB = OFF        // Code Protect Boot (Disabled)
#pragma config CPD = OFF        // Data EE Read Protect (Disabled)
// CONFIG6L
#pragma config WRT0 = OFF       // Table Write Protect 00800-01FFF (Disabled)
#pragma config WRT1 = OFF       // Table Write Protect 02000-03FFF (Disabled)
#pragma config WRT2 = OFF       // Table Write Protect 04000-05FFF (Disabled)
#pragma config WRT3 = OFF       // Table Write Protect 06000-07FFF (Disabled)
// CONFIG6H
#pragma config WRTC = OFF       // Config. Write Protect (Disabled)
#pragma config WRTB = OFF       // Table Write Protect Boot (Disabled)
#pragma config WRTD = OFF       // Data EE Write Protect (Disabled)
// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protect 00800-01FFF (Disabled)
#pragma config EBTR1 = OFF      // Table Read Protect 02000-03FFF (Disabled)
#pragma config EBTR2 = OFF      // Table Read Protect 04000-05FFF (Disabled)
#pragma config EBTR3 = OFF      // Table Read Protect 06000-07FFF (Disabled)
// CONFIG7H
#pragma config EBTRB = OFF      // Table Read Protect Boot (Disabled)
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON_USING and OFF.
#define _str(x)  #x
#define str(x)  _str(x)
/*****************************************************************
 *CAN BUS ROUTINE
 *Operation:       ISR
 *MCU:             PIC18F25K80
 *EXT XTAL:        8MHz 
 * 
 *CAN baudrate:    500K bps
 *CAN TX ID:       0x7DF
 *CAN RX ID:       0x707
 ****************************************************************/
#define BOOTDELAYTIME 30
unsigned char delay_boot,bootloader_flag;
void main(void)
{   init_CAN();
    CanSendBuffer(0x7df,CAN_rx_buf,8);
    T0CON = 0x87;
    //8M/128 *1000 = 62.5   1ms   
    TMR0H = 0xE7;
    TMR0L = 0x95;
    delay_boot = 0;
    bootloader_flag = 0;
    while(delay_boot < BOOTDELAYTIME)
    {   
        if(INTCONbits.T0IF == 1) 
        {   
            INTCONbits.T0IF = 0;
            TMR0H = 0xE7;
            TMR0L = 0x95;
            delay_boot++;
            //  等待升级的倒计时
            CanSendBuffer(0x7df,&delay_boot,sizeof(delay_boot));
            if ((BOOTDELAYTIME-1)==delay_boot) 
            {   
                //  没有升级请求，跳入运行空间执行正常程序。
                unsigned char ch[]={'G','o','t','o','A','p','p'};
                CanSendBuffer(0x7df,ch,sizeof(ch));
                STKPTR = 0x00;
                asm ("pagesel " str(NEW_RESET_VECTOR));
                asm ("goto  "  str(NEW_RESET_VECTOR));
            }
        }
        if(PIR5bits.RXB0IF == 1)
        {   
            //  在倒计时内收到中断请求，做升级相关工作。
            PIR5bits.RXB0IF = 0;
            RXB0CONbits.RXFUL = 0;
            CAN_rx_buf[0]=RXB0D0;            CAN_rx_buf[1]=RXB0D1;
            CAN_rx_buf[2]=RXB0D2;            CAN_rx_buf[3]=RXB0D3;
            CAN_rx_buf[4]=RXB0D4;            CAN_rx_buf[5]=RXB0D5;
            CAN_rx_buf[6]=RXB0D6;            CAN_rx_buf[7]=RXB0D7;
            switch ( CAN_rx_buf[0]) 
            {
                case 0xAA:                  //擦除0x1600-0xffff地址块
                {   
                    //  擦除Flash
                    Erase_Whole_Flash();
                    unsigned char ch[]={'A','c','k','-','-','-',0xAA};
                    CanSendBuffer(0x7df,ch,sizeof(ch));
                    bootloader_flag = 1;
                    break;
                }
            }
            delay_boot = 200;
            CanSendBuffer(0x7df,CAN_rx_buf,8);
        }
    }
    while(1)
    {   
        //进入升级程序
        if(bootloader_flag == 1)
        {
            #define ENDFLGDELAYTIME 0xFFFFF
            static unsigned char chdata[64];
            static unsigned char cStartFlg=0;
            static unsigned long cEndFlg=ENDFLGDELAYTIME;
            static unsigned char i=0,j=0;
            static unsigned int k=0;
            static unsigned long addrpoint=0;   //PROG_START
            //收到CAN数据
            if(PIR5bits.RXB0IF == 1)
            {   
                if(0==cStartFlg)
                {   //初次进入升级，做升级初始化的事情在这里：
                    //发送一个启动信息：
                    unsigned char ch[]={0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66};
                    CanSendBuffer(0x7df,ch,sizeof(ch));
                    // Todo:
                    // 这段代码只是在启动的时候执行一次初始化的动作，所以以后就用标志位将其关闭
                    cStartFlg = 1;
                }
                PIR5bits.RXB0IF     = 0;        // 关闭接收标志
                RXB0CONbits.RXFUL   = 0;
                //  如果跳出之后没有继续跳入，则认为接收关闭了。
                //  只要升级还在继续，则结束标志倒计时就会被更新，
                //  程序认为升级还木有结束
                cEndFlg = ENDFLGDELAYTIME;                
                CAN_rx_buf[0]=RXB0D0;                CAN_rx_buf[1]=RXB0D1;
                CAN_rx_buf[2]=RXB0D2;                CAN_rx_buf[3]=RXB0D3;
                CAN_rx_buf[4]=RXB0D4;                CAN_rx_buf[5]=RXB0D5;
                CAN_rx_buf[6]=RXB0D6;                CAN_rx_buf[7]=RXB0D7;
                CanSendBuffer(0x7df,CAN_rx_buf,8);
                {   //  i是一次CAN接收的buffer的计数器
                    //  j是一次flash写入的buffer的计数器
                    //  k是写入总块数的计数器
                    //  如果最后不足64个byte，则补足FF之后写入，这个工作由外部程序完成，这样可以节约MCU。 
                    for(i=0;i<8;i++){chdata[j++]=CAN_rx_buf[i];}
                    if(j>=63)
                    {
                        // 写入一块，记数+1，0x400~0x800这1K的空间作为Bootloader本身的空间，不必擦写。
                        if ((BOOT64BLOCK_START<=k)&&(k<BOOT64BLOCK_END))
                        {
                            // ToDo: 指针运行在BootLoader区域
                        }
                        else
                        {
                            //指针运行在APP程序区域，擦写程序
                            Flash_Writex(addrpoint,chdata,64);                        
                        }
                        //  块内指针运行归零
                        j=0;
                        // 写入一块，记数+1，0x400~0x800这1K的空间作为Bootloader本身的空间，不必擦写。
                        k++;
                        addrpoint+=64;
                    }
                }
            }
            else
            {
                if(1==cStartFlg)
                {   
                    //  当升级启动之后，结束标志则进行倒计时，做延时处理
                    cEndFlg--;
                    if (0==cEndFlg)
                    {   // 等到计时结束，说明没有信息读入，升级结束：
                        //发送一个结束信息：
                        unsigned char chs[]={0x77,0x77,0x77,0x77,0x77,0x77,0x77,0x77};
                        CanSendBuffer(0x7df,chs,sizeof(chs));
                        // Todo Bootloader Received finished:
                        if (j<63)
                        {
                            for(i=j;i<=63;i++){chdata[i]=0xFF;}
                            Flash_Writex(addrpoint,chdata,64);
                        }
                    }
                }
            }
        }
    }
}
