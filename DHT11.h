#ifndef _DHT11_H_
#define _DHT11_H_

#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"

#define DHT11_HIGH      GPIO_SetBits(GPIOC, GPIO_Pin_4)
#define DHT11_LOW       GPIO_ResetBits(GPIOC, GPIO_Pin_4)
 


// 声明全局变量（不要定义）
extern uint8_t dat11[5];  // 确保变量名一致
extern uint32_t sum;

// 函数声明
void DHT_GPIO_Config_Output(void);
void DHT_GPIO_Config_Input(void);
uint8_t DHT_Read_Byte(void);
uint8_t DHT_Read(void);


#endif