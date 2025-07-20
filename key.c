#include "key.h"

void key_config(void)
{
   GPIO_InitTypeDef GPIO_InitStruct;
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	 
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_2;

	 GPIO_Init(GPIOE, &GPIO_InitStruct);
}

void key_ctrl(void)
{
   if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==0)//按下低电平
	 {
	     delay_ms(200);
		   if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==0)
			 {
			    			GPIOB->ODR ^=(0X01<<5);
			 }
			 while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==0);
	 }
}

