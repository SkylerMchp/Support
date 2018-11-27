#ifndef CAN_H
#define	CAN_H
extern uint8_t CAN_rx_buf[8];
extern uint8_t CAN_rec_flag;
extern void init_CAN(void);
extern void CanSendBuffer(uint16_t id, uint8_t * ptr, uint8_t len);  
//*********************************************************************
#define  Frame_SF   0   //��֡
#define  Frame_FF   1   //��֡
#define  Frame_CF   2   //����֡
#define  Frame_FCF  3   //����֡
//***************** �Ự����ģʽ **************************
#define  CMODE_STD_Mode          0X01  // ��׼���ģʽ
#define  CMODE_ProgrammingMode   0X02  // ���ģʽ
#define  CMODE_ECU_Ex_Mode       0X03  // ECU��չ���ģʽ
//*********************************************************
//******************* ack *********************************
#define  NAckCode_NonSupportFun     0x12  // ��֧���ӹ���
#define  NAckCode_InvalidFormat     0x13  // ����ȷ����Ϣ���Ȼ���Ч��ʽ
#define  NAckCode_InvalidCondition  0x22  // ��������
#define  NAckCode_RequestOutOfRange 0x31  // ���󳬳���Χ
#define  NAckCode_KeyInvalid        0x35  // ��Կ��Ч
#define  NAckCode_KeyAttemptOut     0x37  // ��Կ���Դ���������ֵ
#define  NAckCode_InvalidAddress    0x74  // �鴫�����зǷ���ַ
#define  NAckCode_InvalidByteCount  0x75  // �鴫�����зǷ��ֽڼ���
#define  P2can_server_Max     50           // P2can_server_Max 50MS  (50)          1Bit = 1ms
#define  P2_p_can_server_Max  500          // P2��can_server_Max 5000MS(500=0x1f4)  1Bit = 10ms
#define  S3server             2500         // 2500 * 2mS = 5S // �������������Ϣ����ʱ���˳���Ĭ�����ģʽ��ʱ��
//******* ���п��Ʒ��� **************
#define   MemoryErase  0xDFFF              // �����ڴ�
#define   MemoryCheck  0xDFFE              // ����ڴ�������
extern    unsigned long  MemoryStartAdd;   // �ڴ���ʼ��ַ
extern    unsigned long  MemoryLen;        // �ڴ��С(����)
extern    unsigned char  MemoryExAdd;      // �����ڴ���չ�ֽ�
extern    unsigned long  MemoryCheckValue; // �ڴ�У��ֵ
extern    unsigned char  DataFormat;       // ���ݸ�ʽ��ʶ��
extern    unsigned char  DataBlockNum;     // ���ݿ���
extern    unsigned char  FlashBuf[64];     // ������³������ݵĻ�����
//******* �������� **************
#define   Service_SessionControl   0x10      // ��ϻỰ���� 
#define   Service_ECUReset         0x11      // ECU��λ
#define   Service_RoutineControl   0x31      // ���п��� 
#define   Service_RequestDownload  0x34      // ��������
#define   Service_DataTransfer     0x36      // ���ݴ���
#define   Service_TransferExit     0X37      // �����˳�
#define  NegativeAckFlay  0x7F   // ����Ӧ��
#define  AckWaitFlay      0x78   // ������������Ӧδ����
//*********************************************************
#define  CRC32_InitValue  0x00000000  // 0xffffffff  CRC32��ʼֵ
//*********************************************************
#endif

