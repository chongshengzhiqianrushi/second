#include "delay.h"

void Delay_us(u32 tim)
{  
	 //微秒延时  1/72mhz   1us->72个（1/72mhz） 
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
tick--72  每隔1us进一次中断
重转载寄存器值  --  72
系统定时器时钟 72mhz   周期（1/72）
中断间隔 72*(1/72)  --- 1us

如何产生1ms延时    重转载寄存器写入 72000
*/

uint32_t time_run=0;
uint32_t led1_running[2]={0,1000};
uint32_t led2_running[2]={0,400};
void Systick_Init(uint32_t tick)
{
  SysTick_Config(tick);
	//参数如何填写产生1ms的延时
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