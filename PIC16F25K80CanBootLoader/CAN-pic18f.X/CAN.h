#ifndef CAN_H
#define	CAN_H
extern uint8_t CAN_rx_buf[8];
extern uint8_t CAN_rec_flag;
extern void init_CAN(void);
extern void CanSendBuffer(uint16_t id, uint8_t * ptr, uint8_t len);  
//*********************************************************************
#define  Frame_SF   0   //单帧
#define  Frame_FF   1   //首帧
#define  Frame_CF   2   //连续帧
#define  Frame_FCF  3   //流控帧
//***************** 会话控制模式 **************************
#define  CMODE_STD_Mode          0X01  // 标准诊断模式
#define  CMODE_ProgrammingMode   0X02  // 编程模式
#define  CMODE_ECU_Ex_Mode       0X03  // ECU扩展诊断模式
//*********************************************************
//******************* ack *********************************
#define  NAckCode_NonSupportFun     0x12  // 不支持子功能
#define  NAckCode_InvalidFormat     0x13  // 不正确的消息长度或无效格式
#define  NAckCode_InvalidCondition  0x22  // 条件不符
#define  NAckCode_RequestOutOfRange 0x31  // 请求超出范围
#define  NAckCode_KeyInvalid        0x35  // 密钥无效
#define  NAckCode_KeyAttemptOut     0x37  // 密钥尝试次数超过限值
#define  NAckCode_InvalidAddress    0x74  // 块传送中有非法地址
#define  NAckCode_InvalidByteCount  0x75  // 块传送中有非法字节计数
#define  P2can_server_Max     50           // P2can_server_Max 50MS  (50)          1Bit = 1ms
#define  P2_p_can_server_Max  500          // P2’can_server_Max 5000MS(500=0x1f4)  1Bit = 10ms
#define  S3server             2500         // 2500 * 2mS = 5S // 当无诊断请求消息出现时，退出非默认诊断模式的时间
//******* 例行控制服务 **************
#define   MemoryErase  0xDFFF              // 擦除内存
#define   MemoryCheck  0xDFFE              // 检查内存完整性
extern    unsigned long  MemoryStartAdd;   // 内存起始地址
extern    unsigned long  MemoryLen;        // 内存大小(长度)
extern    unsigned char  MemoryExAdd;      // 擦除内存扩展字节
extern    unsigned long  MemoryCheckValue; // 内存校验值
extern    unsigned char  DataFormat;       // 数据格式标识符
extern    unsigned char  DataBlockNum;     // 数据块编号
extern    unsigned char  FlashBuf[64];     // 储存更新程序数据的缓冲区
//******* 服务类型 **************
#define   Service_SessionControl   0x10      // 诊断会话控制 
#define   Service_ECUReset         0x11      // ECU复位
#define   Service_RoutineControl   0x31      // 例行控制 
#define   Service_RequestDownload  0x34      // 请求下载
#define   Service_DataTransfer     0x36      // 数据传输
#define   Service_TransferExit     0X37      // 传送退出
#define  NegativeAckFlay  0x7F   // 消极应答
#define  AckWaitFlay      0x78   // 请求正常，回应未决定
//*********************************************************
#define  CRC32_InitValue  0x00000000  // 0xffffffff  CRC32初始值
//*********************************************************
#endif

