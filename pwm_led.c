#include "pwm_led.h"

void PWM_Init(void)
{
	  TIM_OCInitTypeDef TIM_OCInitStruct;
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
		GPIO_InitTypeDef GPIO_InitStruct;
	  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	  // 使能AFIO时钟（必须步骤）
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	  GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); // 配置TIM3部分重映射（CH2从PA7→PB5）



	  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5;
	  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	  GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	  //TIM_InternalClockConfig(TIM2);
	  TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	  TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	  TIM_TimeBaseInitStruct.TIM_Period= 1000 - 1;
	  TIM_TimeBaseInitStruct.TIM_Prescaler= 72 - 1;
	  TIM_TimeBaseInitStruct.TIM_RepetitionCounter= 0;
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);
	  

	  TIM_OCStructInit(&TIM_OCInitStruct);
	  TIM_OCInitStruct.TIM_OCMode= TIM_OCMode_PWM1;
	  TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_High;
	  TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
	  TIM_OCInitStruct.TIM_Pulse=0;
	  TIM_OC2Init(TIM3, &TIM_OCInitStruct);
	
    TIM_Cmd(TIM3, ENABLE);

}


void PWM_Setcompare2(uint16_t Compare)
{
   TIM_SetCompare2(TIM3, Compare);
}



//void Servo_Init(void)
//{
//   PWM_Init();
//}

//void Servo_SetAngle(float Angle)
//{
//  PWM_Setcompare1(Angle / 180 * 2000 + 500);
//}






//// 设置舵机角度 (0-180度)
//void Servo_SetAngle(uint8_t angle)
//{
//    uint16_t pulse_width = 500 + (angle * 11.11f);
//    if(pulse_width < 500) pulse_width = 500;
//    if(pulse_width > 2500) pulse_width = 2500;
//    TIM_SetCompare1(TIM3, pulse_width);
//}