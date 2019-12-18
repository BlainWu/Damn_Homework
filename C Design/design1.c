#include <system.h>
void config(void) //配置分频系数
{
  cmcon = 0x07; /*to access digital porta*/
  trisa = 0xff; //porta做输入
  trisb = 0x00;//portb做输出
  portb = 0x00;//初始化输出为00
}/*end of config*/

void delay_1s(void) 
{
	int count=25000;  
	while(count)//clock rate = 3Mhz
	{
		count --;
	}
}/*end of delay*/

void main()
{
	unsigned char inbyte,outbyte;
	int flag_button=0,flag_clear=0;//两个变量分别用作按键指示和清零指示
	config();
	while(1)
	{
		inbyte = porta;
		outbyte = 0x00;
		while(inbyte & 0x01)//开始按钮检测RA0
		{
			flag_button=1;
			break;
		}
		
		while(inbyte & 0x02)//清零按钮检测RA1
		{
			flag_button=0;
			portb = 0x00;//数字归零
			break;
		}
		while(flag_button)
		{
			delay_1s();
			portb ++;
			if(portb > 0x09)//个位为a以后清零
			{
				portb &= 0xf0;
				flag_clear=1;
			}
			if(flag_clear)
			{
				portb += 0x10;
				flag_clear=1;
			}
			if(porta & 0x01)//暂停按钮RA0
			{
				delay_1s();//确保不会导致按键过快
				flag_button=0;
			}
		}
	}
}
