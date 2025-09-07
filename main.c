#include "stm32f10x.h"
#include "stm32f10x_gpio.h"



void delay_ms(volatile unsigned int time) {
    for(unsigned int i=0; i<time*8000; i++); 
}
void GPIO_Configure_LED(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_13;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;  
    GPIO_Init(GPIOA, &gpio);
}


int main(void) {
    GPIO_Configure_LED();
		GPIO_ResetBits(GPIOA,GPIO_Pin_13);
    while (1) {
       GPIO_SetBits(GPIOA,GPIO_Pin_13);
			delay_ms(500);
			GPIO_ResetBits(GPIOA,GPIO_Pin_13);
			delay_ms(500);
    }
}