#ifndef BSP_SYS_H
#define BSP_SYS_H

#include "gd32f4xx.h"
#include "systick.h"

//bit_word_addr =bit_band_base +(byte_offset×32)+(bit_number×4)
#define WORD_ADDR(offset,number) (volatile unsigned long *)(0x42000000+(offset*32)+(number*4))
//#define WORD_ADDR(offset,number) REG(0x42000000+(offset<<5)+(number<<2))
	
#define GPIO_OFFSET(gpio) ((gpio)+0x14U-0x40000000)

//#define LED_WORD(led) *(WORD_ADDR(GPIO_OFFSET(LED_PORT[led]),LED_NUMBER[led]))

//#define GPIOE_OFFSET (GPIOE+0x14U-0x40000000)

//#define PE(n)  *(WORD_ADDR(GPIOE_OFFSET,n))

//#define GPIOD_OFFSET (GPIOD+0x14U-0x40000000)

//#define PD(n)  *(WORD_ADDR(GPIOD_OFFSET,n))

//#define GPIOG_OFFSET (GPIOG+0x14U-0x40000000)

//#define PG(n)  *(WORD_ADDR(GPIOG_OFFSET,n))

//#define GPIOA_OFFSET (GPIOA+0x14U-0x40000000)

//#define PA(n)  *(WORD_ADDR(GPIOA_OFFSET,n))

//#define WORD(gpio,n)  *(WORD_ADDR(GPIO_OFFSET(gpio),n))

#define WORD(led)  *(WORD_ADDR(GPIO_OFFSET(LED_PORT[led]),LED_NUMBER[led]))
//我也不知道为什么，反正一开始写完他跑不了，一步步给他喂进去他能跑
//存疑！！！！！









#endif



