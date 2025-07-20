#include "DHT11.h"


//void DHT11_Reset(void)
//{
//	 GPIO_ResetBits(GPIOB, GPIO_Pin_6);//拉低
//   delay_ms(20);	
//	
//	 GPIO_SetBits(GPIOB, GPIO_Pin_6); //拉高
//	 Delay_us(30);
//	
//}
//void DHT11_Init(void)
//{
//   GPIO_InitTypeDef GPIO_InitStruct;
//	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //GPIOB使能
//	
//	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//通用推挽 输入起始信号
//	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;       //GPIOB 6
//	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	 GPIO_Init(GPIOB, &GPIO_InitStruct);
//	
//	 
//	 // 发送起始信号
//	 GPIO_SetBits(GPIOB, GPIO_Pin_6);    // 先拉高
//	 delay_ms(100);                     // 等待传感器稳定
//	
//   DHT11_Reset();                    //复位
//}
//	

//// 检测DHT11响应
//uint8_t DHT11_Check(void)
//{
//    uint8_t retry = 0;
//	  
//    // 等待DHT11拉低
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_SET && retry < 100);
//	  Delay_us(1);
//	
//	  if(retry >= 100) return 1;  // 响应超时
//}
//	  
//	 //主机改输入模式   上拉输入
//	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
//	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;
//	 GPIO_Init(GPIOB, &GPIO_InitStruct);
//	 
//	 
//	 //从机回应
//	 while(!(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_RESET));//低电平判断
//	 Delay_us(45);
//	 while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_RESET);//高电平判断
//	 Delay_us(45);
//	 
//	 
//	 
//	 
//   //判断低电平   为低电平 可以开始传输数据
//	 while(!(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_RESET));
//	 Delay_us(13);
//	 
//	 if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_SET)//高电平
//	 {  
//		    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_SET)
//				 ;
//				Delay_us(28s);
//		 
//		  Delay_us(118);
//		  if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_SET)
//				 ;//读出1
//	 }
//	
//	 
//	 
//	 



//	 


//}


#include <stdio.h>

//// 全局变量存储温湿度数据
//uint8_t dht11_data[5] = {0, 0, 0, 0, 0};  // 湿度整数部分、湿度小数部分、温度整数部分、温度小数部分、校验和

//// 函数声明
//uint8_t DHT11_ReadData(void);
//void DHT11_Reset(void);
//uint8_t DHT11_Check(void);
//uint8_t DHT11_ReadBit(void);
//uint8_t DHT11_ReadByte(void);

//// 初始化DHT11传感器
//void DHT11_Init(void)
//{
//    GPIO_InitTypeDef GPIO_InitStruct;
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // GPIOB使能
//    
//    // 配置为输出模式，准备发送起始信号
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // 通用推挽输出
//    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;         // GPIOB 6
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOB, &GPIO_InitStruct);
//    
//    // 发送起始信号
//    GPIO_SetBits(GPIOB, GPIO_Pin_6);   // 先拉高
//    delay_ms(100);                    // 等待传感器稳定
//    
//    DHT11_Reset();                    // 发送复位信号
//}

//// 发送复位信号并检测响应
//uint8_t DHT11_ReadData(void)
//{
//    uint8_t i, j;
//    
//    DHT11_Reset();
//    
//    // 检测响应
//    if(DHT11_Check() == 0)
//    {
//        // 读取40位数据
//        for(i = 0; i < 5; i++)  // 读取5个字节
//        {
//            for(j = 0; j < 8; j++)  // 读取每个字节的8位
//            {
//                dht11_data[i] <<= 1;
//                dht11_data[i] |= DHT11_ReadBit();
//            }
//        }
//        
//        // 校验和验证
//        if(dht11_data[4] == (dht11_data[0] + dht11_data[1] + dht11_data[2] + dht11_data[3]))
//            return 1;  // 校验成功
//        else
//            return 0;  // 校验失败
//    }
//    else
//    {
//        return 0;  // 响应失败
//    }
//}

//// 发送复位信号
//void DHT11_Reset(void)
//{
//    // 主机发送起始信号
//    GPIO_ResetBits(GPIOB, GPIO_Pin_6);  // 拉低
//    delay_ms(20);                       // 至少18ms
//    
//    GPIO_SetBits(GPIOB, GPIO_Pin_6);    // 拉高
//    Delay_us(30);                       // 20-40us
//}

//// 检测DHT11响应
//uint8_t DHT11_Check(void)
//{
//    uint8_t retry = 0;
//    
//    // 等待DHT11拉低
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_SET && retry < 100)
//    {
//        retry++;
//        Delay_us(1);
//    }
//    
//    if(retry >= 100) return 1;  // 响应超时
//    
//    retry = 0;
//    
//    // 等待DHT11拉高
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_RESET && retry < 100)
//    {
//        retry++;
//        Delay_us(1);
//    }
//    
//    if(retry >= 100) return 1;  // 响应超时
//    
//    return 0;  // 响应正常
//}

//// 读取一个位
//uint8_t DHT11_ReadBit(void)
//{
//    uint8_t retry = 0;
//    
//    // 等待低电平结束
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_RESET && retry < 100)
//    {
//        retry++;
//        Delay_us(1);
//    }
//    
//    Delay_us(40);  // 等待40us，此时如果是高电平则为1，低电平则为0
//    
//    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_SET)
//        return 1;
//    else
//        return 0;
//}

//// 读取一个字节
//uint8_t DHT11_ReadByte(void)
//{
//    uint8_t i, dat;
//    dat = 0;
//    
//    for(i = 0; i < 8; i++)
//    {
//        dat <<= 1;
//        dat |= DHT11_ReadBit();
//    }
//    
//    return dat;
//}

//// 获取温度值（整数部分）
//uint8_t DHT11_GetTemperature(void)
//{
//    return dht11_data[2];
//}

//// 获取湿度值（整数部分）
//uint8_t DHT11_GetHumidity(void)
//{
//    return dht11_data[0];
//}



uint8_t  dat11[5]={0x00,0x00,0x00,0x00,0x00};    //存储读取的温湿度信息
uint32_t sum=0;         //存放校验时的求和
 
void DHT_GPIO_Config_Output(void)
{		
	GPIO_InitTypeDef GPIO_InitStruct;	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}
 
void DHT_GPIO_Config_Input(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}

uint8_t DHT_Read_Byte(void)
{
	uint8_t temp;  
	uint8_t ReadDat=0; 
	uint8_t t = 0;
	uint8_t i; 
	
	for(i=0; i<8; i++)
	{
    while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)==0&&t<60)
    {
		   Delay_us(1);
			 t++;
		}
    t=0;
    Delay_us(30);
    temp=0;
    if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)==1) temp=1;
    
    while(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4)==1&&t<100)
    {
		  Delay_us(1);
			t++;
		}			
		t=0;
		ReadDat<<=1;
		ReadDat|=temp;
	}
		return ReadDat;
}

uint8_t DHT_Read(void)
{
  
	uint8_t i;
	uint8_t t = 0;
	
	DHT_GPIO_Config_Output();
	
	DHT11_LOW;
	Delay_us(18);
	
	DHT11_HIGH;
	Delay_us(40);
	DHT_GPIO_Config_Input();
  
	Delay_us(20);
  
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==0)  //如果读取到低电平，证明DHT11响应
  {
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==0&&t<100)//接收响应信号低电平剩余60us，等待变高电平
		{
			Delay_us(1);
			t++;			
		}
		t=0;//超过100us自动向下运行，以免卡死
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==1&&t<100)//接收响应信号高电平80us，等待变低电平
		{
				Delay_us(1);
				t++;			
		}
		t=0;
		for(i=0;i<5;i++)  //接收40位数据--
		{
				dat11[i]=DHT_Read_Byte();//读出1个字节
		}
		Delay_us(50);//结束信号
	}
	
	sum=dat11[0]+dat11[1]+dat11[2]+dat11[3];
	if(dat11[4]==(u8)sum)  //校验  
	{
		printf("湿度：%d\r\n温度：%d\r\n",dat11[0],dat11[2]);
		return 1;    
	}
	else
	return 0; 
}