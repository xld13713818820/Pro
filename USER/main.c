#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"
#include "dht11.h"
 
extern u8 nonside[];


/************************************************
 ALIENTEKս��STM32������ʵ��1
 �����ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/


 int main(void)
{	
	 u8* temperature;
	 u8* humidity;
	 u8 t;
	 
	 
	delay_init();	    //��ʱ������ʼ��	  
	vLED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	LCD_Init();
	
	 while(DHT11_Init())	//DHT11��ʼ��	
		 
	{
		LCD_Print(5, 0, "DHT11 Error",TYPE8X16,TYPE8X16);
		delay_ms(200);
	}
	LCD_Print(5, 0, "���ֶ���OLED",TYPE8X16,TYPE8X16);
	LCD_Print(0, 25, "Temp:   ��C",TYPE8X16,TYPE6X8);
	LCD_Print(0, 44, "Humi:    %",TYPE8X16,TYPE6X8);
	LCD_Print(35, 25, "32",TYPE8X16,TYPE6X8);
	LCD_Print(35, 44, "68",TYPE8X16,TYPE6X8);
	
	
	while(1)
	{	    	    
 		if(t%10==0)			//ÿ100ms��ȡһ��
		{									  
			DHT11_Read_Data(&temperature,&humidity);	//��ȡ��ʪ��ֵ					    
//			LCD_Print(35,25,temperature,TYPE8X16,TYPE6X8);//��ʾ�¶�	   		   
//			LCD_Print(35,44,humidity,TYPE8X16,TYPE6X8);//��ʾʪ��	 	 
			LCD_Put_Column(35,25,temperature);//��ʾ�¶�	  
			LCD_Put_Column(35,44,humidity);//��ʾʪ��	 	 
			
		}				   
	 	delay_ms(10);
		t++;
		if(t == 20)
		{
			t = 0;
			LED0 = !LED0;
			LED1 = !LED1;
		}
		
		
		
//		LED0=0;
//		LED1=1;
//		delay_ms(300);	 //��ʱ300ms
//		LED0=1;
//		LED1=0;
//		delay_ms(300);	//��ʱ300ms
	}
}
	
	 
//	Draw_BMP(0,48,nonside); 

 
	
