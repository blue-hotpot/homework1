#include "exercise.h"
#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"



uint16_t number=0;

void bsp_led_config(led_type ledx)
{
	rcu_periph_clock_enable(LED_RCU[ledx]);
	gpio_mode_set(LED_PORT[ledx],GPIO_MODE_OUTPUT,GPIO_PUPD_NONE,LED_PIN[ledx]);
	gpio_output_options_set(LED_PORT[ledx],GPIO_OTYPE_PP,GPIO_OSPEED_25MHZ,LED_PIN[ledx]);
}


void timer_config(uint16_t pre,uint16_t per)
{
	timer_parameter_struct timer_struct;
	
	rcu_periph_clock_enable(RCU_TIMER5);
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);
	
	timer_struct.prescaler = pre-1;                         
    timer_struct.alignedmode = TIMER_COUNTER_EDGE;                       
    timer_struct.counterdirection = TIMER_COUNTER_UP;                  
    timer_struct.clockdivision = TIMER_CKDIV_DIV1;                     
    timer_struct.period = per;                            
    timer_struct.repetitioncounter = 0;
	
	nvic_irq_enable(TIMER5_DAC_IRQn,3,2);
	
	timer_deinit(TIMER5);
	timer_init(TIMER5,&timer_struct);
	timer_interrupt_enable(TIMER5,TIMER_INT_UP);
	timer_enable(TIMER5);
}

void TIMER5_DAC_IRQHandler(void)
{
	
	if(timer_interrupt_flag_get(TIMER5,TIMER_INT_UP)==SET)
	{
		//gpio_bit_toggle(LED_PORT[number],LED_PIN[number]);
		//LED_WORD(number)=~(LED_WORD(number));
		//LED_WORD=~(LED_WORD);
		WORD(number)=~(WORD(number));
		number=(number+1)%4;
		timer_interrupt_flag_clear(TIMER5,TIMER_INT_UP);
	}
}



