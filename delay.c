#include "delay.h"

void Delay_us(u32 tim)
{  
	 //΢����ʱ  1/72mhz   1us->72����1/72mhz�� 
   while(tim--)
	 {
	  		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		__NOP();__NOP();
	 }
}
void Delay_ms(u32 tim)
{
    while(tim--)
		{
	     Delay_us(1000);	
		}
}

/*
tick--72  ÿ��1us��һ���ж�
��ת�ؼĴ���ֵ  --  72
ϵͳ��ʱ��ʱ�� 72mhz   ���ڣ�1/72��
�жϼ�� 72*(1/72)  --- 1us

��β���1ms��ʱ    ��ת�ؼĴ���д�� 72000
*/

uint32_t time_run=0;
uint32_t led1_running[2]={0,1000};
uint32_t led2_running[2]={0,400};
void Systick_Init(uint32_t tick)
{
  SysTick_Config(tick);
	//���������д����1ms����ʱ
}

void SysTick_Handler(void)
{
  time_run++;
	led1_running[0]++;
	led2_running[0]++;
}

void delay_ms(uint32_t tim)
{
  u32 val=0;
	val=tim+time_run;
	while(val>time_run);
}