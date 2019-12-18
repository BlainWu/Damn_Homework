#include <system.h>
void config(void) //���÷�Ƶϵ��
{
  cmcon = 0x07; /*to access digital porta*/
  trisa = 0xff; //porta������
  trisb = 0x00;//portb�����
  portb = 0x00;//��ʼ�����Ϊ00
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
	int flag_button=0,flag_clear=0;//���������ֱ���������ָʾ������ָʾ
	config();
	while(1)
	{
		inbyte = porta;
		outbyte = 0x00;
		while(inbyte & 0x01)//��ʼ��ť���RA0
		{
			flag_button=1;
			break;
		}
		
		while(inbyte & 0x02)//���㰴ť���RA1
		{
			flag_button=0;
			portb = 0x00;//���ֹ���
			break;
		}
		while(flag_button)
		{
			delay_1s();
			portb ++;
			if(portb > 0x09)//��λΪa�Ժ�����
			{
				portb &= 0xf0;
				flag_clear=1;
			}
			if(flag_clear)
			{
				portb += 0x10;
				flag_clear=1;
			}
			if(porta & 0x01)//��ͣ��ťRA0
			{
				delay_1s();//ȷ�����ᵼ�°�������
				flag_button=0;
			}
		}
	}
}
