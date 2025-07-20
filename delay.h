#ifndef _DELAY_H_
#define _DELAY_H_

#include "stm32f10x.h"


extern uint32_t led1_running[2];
extern uint32_t led2_running[2];

void delay_ms(uint32_t tim);
void Delay_us(u32 tim);
void Delay_ms(u32 tim);

void Systick_Init(uint32_t tick);




#endif
