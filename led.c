#include "led.h"


void led_config(void)
{
  	GPIO_InitTypeDef GPIO_InitTypeDef={0};//����ṹ��
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��ʱ��
	   
		GPIO_InitTypeDef.GPIO_Mode=GPIO_Mode_Out_PP;
		GPIO_InitTypeDef.GPIO_Pin=GPIO_Pin_5;               //PB5
		GPIO_InitTypeDef.GPIO_Speed=GPIO_Speed_2MHz;
		
	  GPIO_Init(GPIOB, &GPIO_InitTypeDef);//��ʼ��
	
}

void led_blink(void)
{
   GPIO_ResetBits(GPIOB, GPIO_Pin_5);	
   delay_ms(1000);
	                                                                    
	 GPIO_SetBits(GPIOB, GPIO_Pin_5);
	 delay_ms(1000);
}

