#include "DHT11.h"


//void DHT11_Reset(void)
//{
//	 GPIO_ResetBits(GPIOB, GPIO_Pin_6);//����
//   delay_ms(20);	
//	
//	 GPIO_SetBits(GPIOB, GPIO_Pin_6); //����
//	 Delay_us(30);
//	
//}
//void DHT11_Init(void)
//{
//   GPIO_InitTypeDef GPIO_InitStruct;
//	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //GPIOBʹ��
//	
//	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//ͨ������ ������ʼ�ź�
//	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;       //GPIOB 6
//	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//	 GPIO_Init(GPIOB, &GPIO_InitStruct);
//	
//	 
//	 // ������ʼ�ź�
//	 GPIO_SetBits(GPIOB, GPIO_Pin_6);    // ������
//	 delay_ms(100);                     // �ȴ��������ȶ�
//	
//   DHT11_Reset();                    //��λ
//}
//	

//// ���DHT11��Ӧ
//uint8_t DHT11_Check(void)
//{
//    uint8_t retry = 0;
//	  
//    // �ȴ�DHT11����
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_SET && retry < 100);
//	  Delay_us(1);
//	
//	  if(retry >= 100) return 1;  // ��Ӧ��ʱ
//}
//	  
//	 //����������ģʽ   ��������
//	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
//	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6;
//	 GPIO_Init(GPIOB, &GPIO_InitStruct);
//	 
//	 
//	 //�ӻ���Ӧ
//	 while(!(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_RESET));//�͵�ƽ�ж�
//	 Delay_us(45);
//	 while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_RESET);//�ߵ�ƽ�ж�
//	 Delay_us(45);
//	 
//	 
//	 
//	 
//   //�жϵ͵�ƽ   Ϊ�͵�ƽ ���Կ�ʼ��������
//	 while(!(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_RESET));
//	 Delay_us(13);
//	 
//	 if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_SET)//�ߵ�ƽ
//	 {  
//		    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_SET)
//				 ;
//				Delay_us(28s);
//		 
//		  Delay_us(118);
//		  if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==Bit_SET)
//				 ;//����1
//	 }
//	
//	 
//	 
//	 



//	 


//}


#include <stdio.h>

//// ȫ�ֱ����洢��ʪ������
//uint8_t dht11_data[5] = {0, 0, 0, 0, 0};  // ʪ���������֡�ʪ��С�����֡��¶��������֡��¶�С�����֡�У���

//// ��������
//uint8_t DHT11_ReadData(void);
//void DHT11_Reset(void);
//uint8_t DHT11_Check(void);
//uint8_t DHT11_ReadBit(void);
//uint8_t DHT11_ReadByte(void);

//// ��ʼ��DHT11������
//void DHT11_Init(void)
//{
//    GPIO_InitTypeDef GPIO_InitStruct;
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // GPIOBʹ��
//    
//    // ����Ϊ���ģʽ��׼��������ʼ�ź�
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // ͨ���������
//    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;         // GPIOB 6
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOB, &GPIO_InitStruct);
//    
//    // ������ʼ�ź�
//    GPIO_SetBits(GPIOB, GPIO_Pin_6);   // ������
//    delay_ms(100);                    // �ȴ��������ȶ�
//    
//    DHT11_Reset();                    // ���͸�λ�ź�
//}

//// ���͸�λ�źŲ������Ӧ
//uint8_t DHT11_ReadData(void)
//{
//    uint8_t i, j;
//    
//    DHT11_Reset();
//    
//    // �����Ӧ
//    if(DHT11_Check() == 0)
//    {
//        // ��ȡ40λ����
//        for(i = 0; i < 5; i++)  // ��ȡ5���ֽ�
//        {
//            for(j = 0; j < 8; j++)  // ��ȡÿ���ֽڵ�8λ
//            {
//                dht11_data[i] <<= 1;
//                dht11_data[i] |= DHT11_ReadBit();
//            }
//        }
//        
//        // У�����֤
//        if(dht11_data[4] == (dht11_data[0] + dht11_data[1] + dht11_data[2] + dht11_data[3]))
//            return 1;  // У��ɹ�
//        else
//            return 0;  // У��ʧ��
//    }
//    else
//    {
//        return 0;  // ��Ӧʧ��
//    }
//}

//// ���͸�λ�ź�
//void DHT11_Reset(void)
//{
//    // ����������ʼ�ź�
//    GPIO_ResetBits(GPIOB, GPIO_Pin_6);  // ����
//    delay_ms(20);                       // ����18ms
//    
//    GPIO_SetBits(GPIOB, GPIO_Pin_6);    // ����
//    Delay_us(30);                       // 20-40us
//}

//// ���DHT11��Ӧ
//uint8_t DHT11_Check(void)
//{
//    uint8_t retry = 0;
//    
//    // �ȴ�DHT11����
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_SET && retry < 100)
//    {
//        retry++;
//        Delay_us(1);
//    }
//    
//    if(retry >= 100) return 1;  // ��Ӧ��ʱ
//    
//    retry = 0;
//    
//    // �ȴ�DHT11����
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_RESET && retry < 100)
//    {
//        retry++;
//        Delay_us(1);
//    }
//    
//    if(retry >= 100) return 1;  // ��Ӧ��ʱ
//    
//    return 0;  // ��Ӧ����
//}

//// ��ȡһ��λ
//uint8_t DHT11_ReadBit(void)
//{
//    uint8_t retry = 0;
//    
//    // �ȴ��͵�ƽ����
//    while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_RESET && retry < 100)
//    {
//        retry++;
//        Delay_us(1);
//    }
//    
//    Delay_us(40);  // �ȴ�40us����ʱ����Ǹߵ�ƽ��Ϊ1���͵�ƽ��Ϊ0
//    
//    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) == Bit_SET)
//        return 1;
//    else
//        return 0;
//}

//// ��ȡһ���ֽ�
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

//// ��ȡ�¶�ֵ���������֣�
//uint8_t DHT11_GetTemperature(void)
//{
//    return dht11_data[2];
//}

//// ��ȡʪ��ֵ���������֣�
//uint8_t DHT11_GetHumidity(void)
//{
//    return dht11_data[0];
//}



uint8_t  dat11[5]={0x00,0x00,0x00,0x00,0x00};    //�洢��ȡ����ʪ����Ϣ
uint32_t sum=0;         //���У��ʱ�����
 
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
  
	if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==0)  //�����ȡ���͵�ƽ��֤��DHT11��Ӧ
  {
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==0&&t<100)//������Ӧ�źŵ͵�ƽʣ��60us���ȴ���ߵ�ƽ
		{
			Delay_us(1);
			t++;			
		}
		t=0;//����100us�Զ��������У����⿨��
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)==1&&t<100)//������Ӧ�źŸߵ�ƽ80us���ȴ���͵�ƽ
		{
				Delay_us(1);
				t++;			
		}
		t=0;
		for(i=0;i<5;i++)  //����40λ����--
		{
				dat11[i]=DHT_Read_Byte();//����1���ֽ�
		}
		Delay_us(50);//�����ź�
	}
	
	sum=dat11[0]+dat11[1]+dat11[2]+dat11[3];
	if(dat11[4]==(u8)sum)  //У��  
	{
		printf("ʪ�ȣ�%d\r\n�¶ȣ�%d\r\n",dat11[0],dat11[2]);
		return 1;    
	}
	else
	return 0; 
}