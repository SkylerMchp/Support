#include <xc.h>
#include <stdint.h>
#include "init_device.h"
#include"flash.h"
#include"CAN.h"
//写周期
void Write_Cycle(void)
{	EEPGD = 1;	CFGS = 0;
	WREN = 1;	CARRY = 0;
	if(GIE){CARRY = 1;}
	//IPEN = 0;  //禁止中断优先级
	GIE = 0;  	//关全局中断
        EECON2 = 0X55;	
        EECON2 = 0XAA;
	WR = 1; 	//1启动读/写周期；0写周期完成
	NOP();	
        NOP();
	while(WR);	//等待写周期完成
	WREN = 0;	//0禁止向程序存储器或EEPROM写操作
	if(CARRY){GIE = 1;}//IPEN=1，开中断
}
//擦除FLASH函数,每次擦除64个字节
void Flash_Erasex(unsigned long address)
{	TBLPTRU = (address >> 8) >> 8;
	TBLPTRH = address >> 8;
	TBLPTRL = address;
	FREE = 1;  	//1 在下一次WR写周期时，执行擦除操作；0 只执行写操作
	Write_Cycle();
}
//擦除flash PROG_START起始到0xffff的地址上的数据,记住每次更新需要进行这样的操作.
void Erase_Whole_Flash(void)
{   unsigned int erase;
    erase = 0;
    while(erase <= 0x7fc0) 
    {   
        if ((BOOTSTART<=erase)&&(erase<BOOTEND))
        {
//            Erase 运行在Boot区域的处理代码，此时bootloader是不能被擦除的：
//            To Do：  
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
    for(i=0; i< length;i++) 	//写64字节到RAM
    {   TABLAT = *P;
        asm("TBLWT*+");
        P++;
    }
    TBLPTR = (address);
    FREE = 0;  			//只执行写操作
    Write_Cycle();
}


