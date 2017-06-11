#include <xc.h>
void delay(int x)
{volatile long int i;
    for(i=0;i<=x*1000;i++)
    {
        asm("NOP");
    }
}
void main(void) 
{   // 设置LED端口为输出
    TRISDbits.TRISD0=TRISDbits.TRISD1=TRISDbits.TRISD2=0;
    // 设置S1端口为输入
    TRISDbits.TRISD6=1;
    while(1)
    {
        // 如果S1端口为松开状态，则进行正常的红绿灯循环，如果S1被按下，则黄灯闪烁
        if (1==PORTDbits.RD6)    // 读取S1端口
        {
            LATD = 0;           // 端口D字节操作
            LATDbits.LATD2=1;   // 端口D2位操作
            delay(50);
            LATD = 0;
            LATDbits.LATD1=1;        
            delay(20);
            LATD = 0;
            LATDbits.LATD0=1;        
            delay(50);
        }
        else
        {
            LATDbits.LATD0=LATDbits.LATD2=0;
            LATDbits.LATD1=~LATDbits.LATD1;  delay(20);
        }
    }
    return;
}