#ifndef _ADC_DMA_H_
#define _ADC_DMA_H_

#include "stm32f10x.h"
#include "stdio.h"
#include "string.h"
#include "delay.h"

void ADC3_DMA_IN6_Init(void);

void ADC3_Rx_DMA(void);


void  DMA_ADC_GET_Data(void);
#endif