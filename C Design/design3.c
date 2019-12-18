#include <system.h>
unsigned int adc_value=0;
unsigned char inbyte;
void config(void) //配置分频系数
{
	trisa = 0xe1; // A0作为电压输入，A34作为LED片选，A1控制蜂鸣器，A2控制LED
	trisb = 0x00; //b所有口都为输出端，做LED输出
	portb = 0x00;//初始化输出为00
}

void delay(int num)//简单的延迟函数
{
	while(num--);
}

void ADC(void)
{	
	int i;
	adcon1 = 0x8e; //ADCON1的具体信息见设计报告
	/* set up porta for analogue on A0, Digital A1 A2 A3 A4 */
	adcon0 = 0xc1; //ADCON0的具体信息见设计报告
	/* set adc internal clock input on ch0 and enable adc*/
	for(i=0;i<10;i++); /*  wait a while for adc to settle*/ 	
	adcon0 |= 0x04;  /* start the adc*/
	while((adcon0 & 0x04)==0x04);/* keep reading the adccon0 register until done 0*/	
}
void main(void) 
{
	config();
	adc_value=0;
	while(1)
	{
		ADC();
		porta |= 0x08;//选中RA3，控制低二位LED
		portb = adresl;//输出低二位数字
		porta &= ~0x08;//关闭RA3,停止控制低二位LED
		porta |= 0x10;//选中RA4，控制高二位LED
		portb =(adresh&0x03);
		porta &~0x10;//关闭RA4,停止控制高二位LED
		
		adc_value=((adresh&0x03)<<8) + adresl;//计算所得adc的十六位表达方式
		
		if(adc_value>0x1f3) //2.44V，1000ppm 0x1f3
		{
			porta |= 0x06;//打开电机和蜂鸣器
		}
		else
		{
			porta &= ~0x06;//关闭电机和蜂鸣器
		}
		delay(10000);
	}
}                            

