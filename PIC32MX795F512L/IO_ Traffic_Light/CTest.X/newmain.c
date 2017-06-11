#include <xc.h>
void delay(int x)
{volatile long int i;
    for(i=0;i<=x*1000;i++)
    {
        asm("NOP");
    }
}
void main(void) 
{   // ����LED�˿�Ϊ���
    TRISDbits.TRISD0=TRISDbits.TRISD1=TRISDbits.TRISD2=0;
    // ����S1�˿�Ϊ����
    TRISDbits.TRISD6=1;
    while(1)
    {
        // ���S1�˿�Ϊ�ɿ�״̬������������ĺ��̵�ѭ�������S1�����£���Ƶ���˸
        if (1==PORTDbits.RD6)    // ��ȡS1�˿�
        {
            LATD = 0;           // �˿�D�ֽڲ���
            LATDbits.LATD2=1;   // �˿�D2λ����
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