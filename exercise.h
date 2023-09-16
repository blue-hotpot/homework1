#ifndef _BSP_EXCISE_
#define _BSP_EXCISE_

#include "gd32f4xx.h"
#include "systick.h"

static unsigned long LED_RCU[4]={RCU_GPIOE,RCU_GPIOD,RCU_GPIOG,RCU_GPIOA};
//PE3,PD7,PG3,PA5
static unsigned long LED_PORT[4]={GPIOE,GPIOD,GPIOG,GPIOA};
static unsigned long LED_PIN[4]={GPIO_PIN_3,GPIO_PIN_7,GPIO_PIN_3,GPIO_PIN_5};
static unsigned long LED_NUMBER[4]={3,7,3,5};


typedef enum
{
	LED1=0,
	LED2=1,
	LED3=2,
	LED4=3,
}led_type;

void bsp_led_config(led_type ledx);
void timer_config(uint16_t pre,uint16_t per);

#endif


