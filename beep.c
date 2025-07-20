#include "beep.h"

void beep(void)
{
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);// πƒ‹ ±÷”
 
	 	
	 GPIO_InitTypeDef GPIO_InitStruct;
	
	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

 	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8;
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz ;

	
	 GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void beep_flash(void)
{
   GPIO_SetBits(GPIOB, GPIO_Pin_8);
	 delay_ms(1000);
	 GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	 delay_ms(1000);
	 
}