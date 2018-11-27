
#include <xc.h>
#include <stdint.h>
#include "init_device.h"
#include "CAN.h"

void interrupt XISR(void)
{

    if(PIR5bits.RXB0IF == 1)
    {
        PIR5bits.RXB0IF = 0;
        RXB0CONbits.RXFUL = 0;
        
        CAN_rx_buf[0]=RXB0D0;
        CAN_rx_buf[1]=RXB0D1;
        CAN_rx_buf[2]=RXB0D2;
        CAN_rx_buf[3]=RXB0D3;
        CAN_rx_buf[4]=RXB0D4;
        CAN_rx_buf[5]=RXB0D5;
        CAN_rx_buf[6]=RXB0D6;
        CAN_rx_buf[7]=RXB0D7;
        CAN_rec_flag = 1;
    }
    

  
}




































