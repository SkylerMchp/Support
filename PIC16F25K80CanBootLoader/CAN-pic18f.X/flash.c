#include <xc.h>
#include <stdint.h>
#include "init_device.h"
#include"flash.h"
#include"CAN.h"
//д����
void Write_Cycle(void)
{	EEPGD = 1;	CFGS = 0;
	WREN = 1;	CARRY = 0;
	if(GIE){CARRY = 1;}
	//IPEN = 0;  //��ֹ�ж����ȼ�
	GIE = 0;  	//��ȫ���ж�
        EECON2 = 0X55;	
        EECON2 = 0XAA;
	WR = 1; 	//1������/д���ڣ�0д�������
	NOP();	
        NOP();
	while(WR);	//�ȴ�д�������
	WREN = 0;	//0��ֹ�����洢����EEPROMд����
	if(CARRY){GIE = 1;}//IPEN=1�����ж�
}
//����FLASH����,ÿ�β���64���ֽ�
void Flash_Erasex(unsigned long address)
{	TBLPTRU = (address >> 8) >> 8;
	TBLPTRH = address >> 8;
	TBLPTRL = address;
	FREE = 1;  	//1 ����һ��WRд����ʱ��ִ�в���������0 ִֻ��д����
	Write_Cycle();
}
//����flash PROG_START��ʼ��0xffff�ĵ�ַ�ϵ�����,��סÿ�θ�����Ҫ���������Ĳ���.
void Erase_Whole_Flash(void)
{   unsigned int erase;
    erase = 0;
    while(erase <= 0x7fc0) 
    {   
        if ((BOOTSTART<=erase)&&(erase<BOOTEND))
        {
//            Erase ������Boot����Ĵ�����룬��ʱbootloader�ǲ��ܱ������ģ�
//            To Do��  
        }
        else
        {
            Flash_Erasex(erase);
        }
        erase += 64;
    }
    for(erase=0;erase<=6553;erase++){asm("NOP");}
}
#ifdef  DEBUG_TEST
unsigned char Flash_read(unsigned long flash_address)
{   unsigned char Flash_readdata;
    TBLPTRU = (flash_address >> 8) >> 8;
	TBLPTRH = flash_address >> 8;
	TBLPTRL = flash_address&0x0000ff;
    asm("TBLRD*");
    Flash_readdata = TABLAT;
    return Flash_readdata;
}
#endif
void Flash_Writex(unsigned long address,unsigned char *P,unsigned char length)
{   unsigned char i;
    TBLPTR = (address);
    NOP();
    EECON1=0;
    for(i=0; i< length;i++) 	//д64�ֽڵ�RAM
    {   TABLAT = *P;
        asm("TBLWT*+");
        P++;
    }
    TBLPTR = (address);
    FREE = 0;  			//ִֻ��д����
    Write_Cycle();
}


