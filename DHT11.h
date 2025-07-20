#ifndef _DHT11_H_
#define _DHT11_H_

#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"

#define DHT11_HIGH      GPIO_SetBits(GPIOC, GPIO_Pin_4)
#define DHT11_LOW       GPIO_ResetBits(GPIOC, GPIO_Pin_4)
 


// ����ȫ�ֱ�������Ҫ���壩
extern uint8_t dat11[5];  // ȷ��������һ��
extern uint32_t sum;

// ��������
void DHT_GPIO_Config_Output(void);
void DHT_GPIO_Config_Input(void);
uint8_t DHT_Read_Byte(void);
uint8_t DHT_Read(void);


#endif