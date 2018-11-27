#include <xc.h> 
#include <stdint.h>
#include <string.h>
#include "CAN.h"
#include "flash.h"
/**
 * Baud rate: 100kbps           
 * System frequency: 8000000 Hz        
 * Time quanta: 8              
 * Sample point: 1-1-4-2
 * Sample point: 75.00%
 */
uint8_t CAN_rx_buf[8]={1,2,3,4,5,6,7,8};
uint8_t*pTXB0D = (uint8_t*)0xF26 ;
uint16_t wtime=0;
void init_CAN(void)
{   uint16_t  CAN_RX_Adress = 0x707;
    CAN_TX_DIR=DIROUT;
    CAN_TX_LAT=0;
    CAN_RX_DIR=DIRIN;
    CANCON = 0x80;
    while((CANSTAT&0X80) == 0){;}
    BRGCON1 = 0x13;         // 50K 4M
//  BRGCON1 = 0x27;     
    BRGCON2 = 0x98;     
    BRGCON3 = 0x01;    
    RXB0SIDL = (CAN_RX_Adress<<5) & 0xe0; 	
    RXB0SIDH = (CAN_RX_Adress>>3) & 0xff;
    RXB0CON = 0X20;     
    RXB0DLC = 0X08;
    RXF0SIDL = (CAN_RX_Adress<<5) & 0xe0; 	
    RXF0SIDH = (CAN_RX_Adress>>3) & 0xff;
    RXM0SIDL = 0Xe0; 	
    RXM0SIDH = 0Xff; 	
    CANCON = 0X00;
    while((CANSTAT&0XE0) != 0){;}
    PIR5 = 0X00;
    TRISCbits.TRISC1 = 0;
    LATCbits.LATC1 = 1;
}
void CanSendBuffer(uint16_t tx_id, uint8_t * ptr, uint8_t len)
{
    TXB0CONbits.TXREQ = 0;
    TXB0DLC = len;
    TXB0SIDL = (tx_id<<5) & 0xe0;           
    TXB0SIDH = (tx_id>>3) & 0xff;
    memcpy(pTXB0D,ptr,len);
    TXB0CONbits.TXREQ = 1;
    wtime =0;
    while((TXB0CONbits.TXREQ == 1)&&(wtime < 40000)){wtime++;}
}

#ifdef  DEBUG_TEST

void CanSendByte(uint16_t tx_id, unsigned char x)
{   TXB0CONbits.TXREQ = 0;
    TXB0DLC = 1;
    TXB0SIDL = (tx_id<<5) & 0xe0;           TXB0SIDH = (tx_id>>3) & 0xff;
    memcpy(pTXB0D,&x,1);
    TXB0CONbits.TXREQ = 1;
    wtime =0;
    while((TXB0CONbits.TXREQ == 1)&&(wtime < 40000)){wtime++;}
}

#endif