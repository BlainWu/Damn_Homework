#include <system.h>
unsigned int adc_value=0;
unsigned char inbyte;
void config(void) //���÷�Ƶϵ��
{
	trisa = 0xe1; // A0��Ϊ��ѹ���룬A34��ΪLEDƬѡ��A1���Ʒ�������A2����LED
	trisb = 0x00; //b���пڶ�Ϊ����ˣ���LED���
	portb = 0x00;//��ʼ�����Ϊ00
}

void delay(int num)//�򵥵��ӳٺ���
{
	while(num--);
}

void ADC(void)
{	
	int i;
	adcon1 = 0x8e; //ADCON1�ľ�����Ϣ����Ʊ���
	/* set up porta for analogue on A0, Digital A1 A2 A3 A4 */
	adcon0 = 0xc1; //ADCON0�ľ�����Ϣ����Ʊ���
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
		porta |= 0x08;//ѡ��RA3�����ƵͶ�λLED
		portb = adresl;//����Ͷ�λ����
		porta &= ~0x08;//�ر�RA3,ֹͣ���ƵͶ�λLED
		porta |= 0x10;//ѡ��RA4�����Ƹ߶�λLED
		portb =(adresh&0x03);
		porta &~0x10;//�ر�RA4,ֹͣ���Ƹ߶�λLED
		
		adc_value=((adresh&0x03)<<8) + adresl;//��������adc��ʮ��λ��﷽ʽ
		
		if(adc_value>0x1f3) //2.44V��1000ppm 0x1f3
		{
			porta |= 0x06;//�򿪵���ͷ�����
		}
		else
		{
			porta &= ~0x06;//�رյ���ͷ�����
		}
		delay(10000);
	}
}                            

