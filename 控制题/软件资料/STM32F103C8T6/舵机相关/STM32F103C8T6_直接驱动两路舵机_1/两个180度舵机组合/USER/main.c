#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "math.h"
 

// int main(void)
//{		
//	u8 dir=1;
//	float led0pwmval;
//	float exp_angle=0;


//	delay_init();	    	                               //��ʱ������ʼ��	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
//	uart_init(115200);	                               //���ڳ�ʼ��Ϊ115200
// 	LED_Init();			        	                           //LED�˿ڳ�ʼ��
//  TIM4_PWM_Init(19999,71);	                         //��Ƶ��PWMƵ��=72000000/20000/72=50Hz

//	
//	
//   	while(1)
//	{
//		led0pwmval=Expect_angle_to_CCR(exp_angle);
//		
//		TIM_SetCompare2(TIM4,led0pwmval);	
//		delay_ms(100);	
//		
//		if(dir)  exp_angle++;
//		else     
//		{
//			
//		while(1)
//		    {
//					delay_ms(500);
//		    }
//	  }
//		
// 		if(exp_angle> 179) dir=0;
//	}

//}	










	
 int main(void)
 {		
	u8 dir=1;
  u8 dir2 =1 ;	 
	float led0pwmval;
	 float led0pwmval2;
	float exp_angle=0;
	float exp_angle2=0;
  u8 i=0;

	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
 	TIM3_PWM_Init(19999,71);	 //��Ƶ��PWMƵ��=72000000/20000/72=50Hz
  TIM4_PWM_Init(19999,71);	 //��Ƶ��PWMƵ��=72000000/20000/72=50Hz
	TIM_SetCompare2(TIM3,500);
	TIM_SetCompare2(TIM4,500);	
	 

   	while(1)
	{
 		

		
		led0pwmval=Expect_angle_to_CCR(exp_angle);
		
		TIM_SetCompare2(TIM4,led0pwmval);	
		if( ((int)exp_angle % 5)  == 0) 
    {
			for(i=0; i<99;i++)
			{
			delay_ms(100);
			}

		}
		else delay_ms(100);	
		
		if(dir)  exp_angle++;
		
		else     
		{
			
		while(1)
		{
		led0pwmval2=Expect_angle_to_CCR(exp_angle2);
		TIM_SetCompare2(TIM3,led0pwmval2);
			
		if( ((int)exp_angle2 % 5)  == 0) 
    {
			for(i=0; i<99;i++)
			{
			delay_ms(100);
			}
		}
		else delay_ms(100);
		
		
		
			if(dir2)  exp_angle2++;
			
			else 
			{
				while(1)
				{
				delay_ms(500);
				}
					
			}
				
			
			
			if(exp_angle2> 179) dir2=0;
		
		}
		}
			

 		  
		
		
		if(exp_angle> 179) dir=0;
								 	   
	}	 
 }

