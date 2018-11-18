#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "oled.h"
#include "dht11.h"
 
extern u8 nonside[];


/************************************************
 ALIENTEK战舰STM32开发板实验1
 跑马灯实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


 int main(void)
{	
	 u8* temperature;
	 u8* humidity;
	 u8 t;
	 
	 
	delay_init();	    //延时函数初始化	  
	vLED_Init();		  	//初始化与LED连接的硬件接口
	LCD_Init();
	
	 while(DHT11_Init())	//DHT11初始化	
		 
	{
		LCD_Print(5, 0, "DHT11 Error",TYPE8X16,TYPE8X16);
		delay_ms(200);
	}
	LCD_Print(5, 0, "徐林东的OLED",TYPE8X16,TYPE8X16);
	LCD_Print(0, 25, "Temp:   °C",TYPE8X16,TYPE6X8);
	LCD_Print(0, 44, "Humi:    %",TYPE8X16,TYPE6X8);
	LCD_Print(35, 25, "32",TYPE8X16,TYPE6X8);
	LCD_Print(35, 44, "68",TYPE8X16,TYPE6X8);
	
	
	while(1)
	{	    	    
 		if(t%10==0)			//每100ms读取一次
		{									  
			DHT11_Read_Data(&temperature,&humidity);	//读取温湿度值					    
//			LCD_Print(35,25,temperature,TYPE8X16,TYPE6X8);//显示温度	   		   
//			LCD_Print(35,44,humidity,TYPE8X16,TYPE6X8);//显示湿度	 	 
			LCD_Put_Column(35,25,temperature);//显示温度	  
			LCD_Put_Column(35,44,humidity);//显示湿度	 	 
			
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
//		delay_ms(300);	 //延时300ms
//		LED0=1;
//		LED1=0;
//		delay_ms(300);	//延时300ms
	}
}
	
	 
//	Draw_BMP(0,48,nonside); 

 
	
