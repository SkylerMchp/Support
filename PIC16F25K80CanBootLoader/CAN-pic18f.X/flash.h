#ifndef __FLASH_H_
#define __FLASH_H_
//#define DEBUG_TEST
#define DIROUT  0
#define DIRIN   1
//  25K80 有两个CAN端口，一个在PORTC一个在PORTB，在这里做选择。
#define CANUSE_PORTC

#ifdef CANUSE_PORTC
    #define CAN_RX_DIR    TRISCbits.TRISC7
    #define CAN_TX_DIR    TRISCbits.TRISC6
    #define CAN_RX_PORT   PORTCbits.RC7
    #define CAN_TX_LAT    LATCbits.LATC6
#else
    #define CAN_RX_DIR    TRISBbits.TRISB3
    #define CAN_TX_DIR    TRISBbits.TRISB2
    #define CAN_RX_PORT   PORTBbits.RB3
    #define CAN_TX_LAT    LATBbits.LATB2
#endif
extern void Flash_Erasex(unsigned long address);
extern void Erase_Whole_Flash(void);
extern void Flash_Write(unsigned long address,unsigned char *P);
extern persistent near unsigned char buff[8];  //8字节编程缓冲区
extern persistent near unsigned char DO_NOT_INCREMENT;
extern persistent near unsigned char index;
extern void clear_buffer(void);
extern void flash8(void);
extern unsigned char EEPROM_Read(unsigned char Adress);
extern void EEPROM_Write(unsigned int Adress,unsigned char data);
extern void Flash_Writex(unsigned long address,unsigned char *P,unsigned char length);
extern unsigned char Flash_read(unsigned long flash_address);
/*
 * 0000~0400  ：    起始地址，存放公共变量起始值等信息
 * 0400~09CF  ：    Bootloader程序区域
 * 09D0~7FC0  ：    程序区域 
 */
#define  BOOTSTART  0x400           //Bootloader程序开始
#define  BOOTEND      0x9CF
#define  BOOT64BLOCK_START  (BOOTSTART/64)
#define  BOOT64BLOCK_END      ((BOOTEND+1)/64)
/*
 * 1500:    App 地址
 */
#define  NEW_RESET_VECTOR            0x1500 //Bootloader程序开始
#define  NEW_INTERRUPT_VECTOR_HIGH   0x1518
#define  NEW_INTERRUPT_VECTOR_LOW    0x1508

#endif
