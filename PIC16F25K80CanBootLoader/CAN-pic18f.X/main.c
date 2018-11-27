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
            //  �ȴ������ĵ���ʱ
            CanSendBuffer(0x7df,&delay_boot,sizeof(delay_boot));
            if ((BOOTDELAYTIME-1)==delay_boot) 
            {   
                //  û�����������������пռ�ִ����������
                unsigned char ch[]={'G','o','t','o','A','p','p'};
                CanSendBuffer(0x7df,ch,sizeof(ch));
                STKPTR = 0x00;
                asm ("pagesel " str(NEW_RESET_VECTOR));
                asm ("goto  "  str(NEW_RESET_VECTOR));
            }
        }
        if(PIR5bits.RXB0IF == 1)
        {   
            //  �ڵ���ʱ���յ��ж�������������ع�����
            PIR5bits.RXB0IF = 0;
            RXB0CONbits.RXFUL = 0;
            CAN_rx_buf[0]=RXB0D0;            CAN_rx_buf[1]=RXB0D1;
            CAN_rx_buf[2]=RXB0D2;            CAN_rx_buf[3]=RXB0D3;
            CAN_rx_buf[4]=RXB0D4;            CAN_rx_buf[5]=RXB0D5;
            CAN_rx_buf[6]=RXB0D6;            CAN_rx_buf[7]=RXB0D7;
            switch ( CAN_rx_buf[0]) 
            {
                case 0xAA:                  //����0x1600-0xffff��ַ��
                {   
                    //  ����Flash
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
        //������������
        if(bootloader_flag == 1)
        {
            #define ENDFLGDELAYTIME 0xFFFFF
            static unsigned char chdata[64];
            static unsigned char cStartFlg=0;
            static unsigned long cEndFlg=ENDFLGDELAYTIME;
            static unsigned char i=0,j=0;
            static unsigned int k=0;
            static unsigned long addrpoint=0;   //PROG_START
            //�յ�CAN����
            if(PIR5bits.RXB0IF == 1)
            {   
                if(0==cStartFlg)
                {   //���ν�����������������ʼ�������������
                    //����һ��������Ϣ��
                    unsigned char ch[]={0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66};
                    CanSendBuffer(0x7df,ch,sizeof(ch));
                    // Todo:
                    // ��δ���ֻ����������ʱ��ִ��һ�γ�ʼ���Ķ����������Ժ���ñ�־λ����ر�
                    cStartFlg = 1;
                }
                PIR5bits.RXB0IF     = 0;        // �رս��ձ�־
                RXB0CONbits.RXFUL   = 0;
                //  �������֮��û�м������룬����Ϊ���չر��ˡ�
                //  ֻҪ�������ڼ������������־����ʱ�ͻᱻ���£�
                //  ������Ϊ������ľ�н���
                cEndFlg = ENDFLGDELAYTIME;                
                CAN_rx_buf[0]=RXB0D0;                CAN_rx_buf[1]=RXB0D1;
                CAN_rx_buf[2]=RXB0D2;                CAN_rx_buf[3]=RXB0D3;
                CAN_rx_buf[4]=RXB0D4;                CAN_rx_buf[5]=RXB0D5;
                CAN_rx_buf[6]=RXB0D6;                CAN_rx_buf[7]=RXB0D7;
                CanSendBuffer(0x7df,CAN_rx_buf,8);
                {   //  i��һ��CAN���յ�buffer�ļ�����
                    //  j��һ��flashд���buffer�ļ�����
                    //  k��д���ܿ����ļ�����
                    //  ��������64��byte������FF֮��д�룬����������ⲿ������ɣ��������Խ�ԼMCU�� 
                    for(i=0;i<8;i++){chdata[j++]=CAN_rx_buf[i];}
                    if(j>=63)
                    {
                        // д��һ�飬����+1��0x400~0x800��1K�Ŀռ���ΪBootloader����Ŀռ䣬���ز�д��
                        if ((BOOT64BLOCK_START<=k)&&(k<BOOT64BLOCK_END))
                        {
                            // ToDo: ָ��������BootLoader����
                        }
                        else
                        {
                            //ָ��������APP�������򣬲�д����
                            Flash_Writex(addrpoint,chdata,64);                        
                        }
                        //  ����ָ�����й���
                        j=0;
                        // д��һ�飬����+1��0x400~0x800��1K�Ŀռ���ΪBootloader����Ŀռ䣬���ز�д��
                        k++;
                        addrpoint+=64;
                    }
                }
            }
            else
            {
                if(1==cStartFlg)
                {   
                    //  ����������֮�󣬽�����־����е���ʱ������ʱ����
                    cEndFlg--;
                    if (0==cEndFlg)
                    {   // �ȵ���ʱ������˵��û����Ϣ���룬����������
                        //����һ��������Ϣ��
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
