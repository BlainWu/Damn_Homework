#include "user.h"
#include <stdlib.h>
#include "HMI.h"
uint16_t adc_result;
int CLOCKS_PER_SEC = 20; //ÿ��ʱ�ӿ��
void delay(long  n)
{
	long  i;
	for(i=0;i<n;i++);
}
void ADC0_init(void)
{
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;  //enable clock to PORTD
	PORTD->PCR[6] = 0x0000; //PTD6 to AI
	
	SIM->SCGC6 |= BIT27; // enable clock to ADC0
	ADC0->SC2 &= ~ BIT6; //software trigger
	
	ADC0->CFG1= BIT6+ BIT4+ BIT2; //bus clock div 4 & long sample time & single ended 12 bit 
	ADC0->CFG2=ADC_CFG2_MUXSEL_MASK; //adcse7b
}

void Sound_Detect(void)
{
	uint8_t crease_buffer;
	crease_buffer = ui8Value;//ȷ���˳��󻹱����ڽ����
	ADC0_init();
	GrClear(0);	
	GrString_GB2312("��ǰ����",0,4);
	N_SysTick = 0;
	while((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0)
	{
		if(N_SysTick >=60)
		{
			N_SysTick = 0;
			ADC0->SC1[0] = 0x07;  //start adc adcse7b;
			while(!(ADC0->SC1[0] & BIT7)); // wait until conversion complete
			adc_result = ADC0->R[0]; //read adc result 
			///
			//ģ�������������Ĵ���
			///
			GrString_GB2312("�ֱ�",4,11);
			GrStringNum(adc_result,0,4,6);
		}
	}
	ui8Value = crease_buffer;
}

void Sound_Mode(void)
{
	uint8_t crease_buffer;
	crease_buffer = ui8Value;//ȷ���˳��󻹱����ڽ����
	ADC0_init();
	GrClear(0);	
	int db,db_thr=300;
	GrString_GB2312("��������ģʽ",2,4);
	N_SysTick = 0;
	while((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0)
	{
		if(N_SysTick >=30)
		{
			N_SysTick = 0;
			ADC0->SC1[0] = 0x07;  //start adc adcse7b;
			while(!(ADC0->SC1[0] & BIT7)); // wait until conversion complete
			adc_result = ADC0->R[0]; //read adc result 
			///
			//ģ�������������Ĵ���
			///
			db = adc_result - 100;//��ٵļ������
			if (db >db_thr) //��������ֵ��ʱ�򣬵���
			{
					FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3��1
					FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //
					GrString_GB2312("����",4,6);
					delay(10000);//�ӳ�ʱ��
			}
			else
			{
					FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3��0
					FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; // 
					GrString_GB2312("�ڰ�",4,6);
			}
		}
	}
	ui8Value = crease_buffer;
}

void Button_control(void)
{
		uint8_t crease_buffer;
		crease_buffer = ui8Value;//ȷ���˳��󻹱����ڽ����
		GrClear(0);	
		GrString_GB2312("���¿���ģʽ",0,2);
		GrString_GB2312("�����¼��л�",2,2);
		int mode_num;
		mode_num = ui8Value;

		while(((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0) & ((mode_num ==1)||(mode_num ==0))) //��˸��ģʽ
		{
				mode_num = ui8Value;
				GrClear(0);	
				GrString_GB2312("�����л�ģʽ",0,2);
				GrString_GB2312("��˸",6,6);
				FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3��1
				FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //������ͬʱ���ڵڰ�����ʾ*
			mode_num = ui8Value;
				delay(5000000);//��ʱ
				mode_num = ui8Value;
				GrClear(0);	
				GrString_GB2312("�����л�ģʽ",0,2);
				FPTB->PCOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3��0
				FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //������Ϩ��*��ʧ
			mode_num = ui8Value;
				delay(5000000);//��ʱ
			mode_num = ui8Value;
		}
				while(((ui8ButtonKeyValue & KEY_RIGHT_EXIT) == 0) & (mode_num ==2)) //���ʵ�
		{
				mode_num = ui8Value;
				GrClear(0);	
				GrString_GB2312("�����л�ģʽ",0,2);
				GrString_GB2312("���ʵ�",6,5);
				FPTB->PSOR |= BIT0;
				FPTB->PDDR |= BIT0;
				GrString_GB2312("0",6,12);
			mode_num = ui8Value;
				delay(2000000);//��ʱ
				mode_num = ui8Value;
				FPTB->PCOR |= BIT0;
				FPTB->PDDR |= BIT0;
			mode_num = ui8Value;
				delay(2000000);//��ʱ
			  mode_num = ui8Value;
				FPTB->PSOR |= BIT1;
				FPTB->PDDR |= BIT1;
				GrString_GB2312("1",6,12);
			mode_num = ui8Value;
				delay(2000000);//��ʱ
			  mode_num = ui8Value;
				FPTB->PCOR |= BIT1;
				FPTB->PDDR |= BIT1;	
			  mode_num = ui8Value;
				delay(2000000);//��ʱ
				mode_num = ui8Value;
				FPTB->PSOR |= BIT2;
				FPTB->PDDR |= BIT2;
				mode_num = ui8Value;
				GrString_GB2312("2",6,12);
				mode_num = ui8Value;
				delay(2000000);//��ʱ
				mode_num = ui8Value;
				FPTB->PCOR |= BIT2;
				FPTB->PDDR |= BIT2;	
				mode_num = ui8Value;
				delay(2000000);//��ʱ
				mode_num = ui8Value;
				FPTB->PSOR |= BIT3;
				FPTB->PDDR |= BIT3;
				GrString_GB2312("3",6,12);
				mode_num = ui8Value;
				delay(2000000);//��ʱ
				mode_num = ui8Value;
				FPTB->PCOR |= BIT3;
				FPTB->PDDR |= BIT3;	
				mode_num = ui8Value;
				delay(2000000);//��ʱ
				mode_num = ui8Value;
		}
		while(((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0) & (mode_num ==3)) //�ǹ�ģʽ
		{
				mode_num = ui8Value;
				GrClear(0);	
				int a = rand(),choice;
				choice = a%4;
				GrString_GB2312("�����л�ģʽ",0,2);
				GrString_GB2312("�ǹ�",6,6);
				switch(choice)
				{
					case 0:
					{
						FPTB->PSOR |= BIT0; 
						FPTB->PDDR |= BIT0;
						GrString_GB2312("0",6,10);
						mode_num = ui8Value;
						delay(4000000);//��ʱ
						mode_num = ui8Value;
						FPTB->PCOR |= BIT0; 
						FPTB->PDDR |= BIT0;
					}break;
					case 1:
					{
						FPTB->PSOR |= BIT1; 
						FPTB->PDDR |= BIT1;
						GrString_GB2312("1",6,10);
						mode_num = ui8Value;
						delay(4000000);//��ʱ
						mode_num = ui8Value;
						FPTB->PCOR |= BIT1; 
						FPTB->PDDR |= BIT1;
					}break;
					case 2:
					{
						FPTB->PSOR |= BIT2; 
						FPTB->PDDR |= BIT2;
						GrString_GB2312("2",6,10);
						mode_num = ui8Value;
						delay(4000000);//��ʱ
						mode_num = ui8Value;
						FPTB->PCOR |= BIT2; 
						FPTB->PDDR |= BIT2;
					}break;
					case 3:
					{
						FPTB->PSOR |= BIT3; 
						FPTB->PDDR |= BIT3;
						GrString_GB2312("3",6,10);
						mode_num = ui8Value;
						delay(4000000);//��ʱ
						mode_num = ui8Value;
						FPTB->PCOR |= BIT3; 
						FPTB->PDDR |= BIT3;
					}break;
				}
		}
		ui8Value = crease_buffer;
}



void GPIO_Init(void)
{



	//tricolor led: PTB18/19,PTD1 output 
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;//enable clock to PORT B/D 	
	PORTB->PCR[0] = 0x0103;// PTB0->GPIO
	PORTB->PCR[1] = 0x0103;// PTB1->GPIO
	PORTB->PCR[2] = 0x0100;// PTB2->GPIO
	PORTB->PCR[3] = 0x0100;// PTB3->GPIO
	
	FPTB->PCOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3�����ʼ��
	FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; // 
}

void Clock_Mode(void)
{

	uint8_t crease_buffer;
	crease_buffer = ui8Value;//ȷ���˳��󻹱����ڽ����
	//---------//
	int hour=0,min=0,sec=0,total_secs=0;//��ʼ��ʱ����
	int pre_sec=0;
	while((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0)
	{
		total_secs = N_SysTick/CLOCKS_PER_SEC;
    sec = total_secs % 60;
    min = (total_secs / 60) % 60;
    hour = ((total_secs / 60) / 60) % 24;
		if(pre_sec != total_secs)
		{
			GrClear(0);	
			GrString_GB2312("��ǰʱ��",0,4);
			//�����ʾ
			GrStringNum(hour,0,4,2);
			GrString_GB2312("ʱ",4,4);
			GrStringNum(min,0,4,6);
			GrString_GB2312("��",4,8);
			GrStringNum(sec,0,4,10);
			GrString_GB2312("��",4,12);
			pre_sec = total_secs;
		}
	}
	ui8Value = crease_buffer;
}

void Timer(void)
{
		uint8_t crease_buffer;
		crease_buffer = ui8Value;//ȷ���˳��󻹱����ڽ����
		int start_buffer = freeValue , pre_value = freeValue;
		int mins=1;//�趨�ķ�����
		int sec,min,total_secs,start_time,pre_sec,left_time;//����ʱ���õ��Ĳ���
		int seted = 0,finished=0;
		GrClear(0);	
		GrString_GB2312("�����÷�����",0,2);
		GrStringNum(mins,0,4,6);
		GrString_GB2312("����",4,8);
		while(((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0) && (finished ==0))
		{
			if((pre_value != freeValue)& (seted==0))//���������������ˢ�½���
			{
				mins = (freeValue - start_buffer)+1;
				if(mins < 1)
					mins = 1; //��������С��1min
				if(freeValue<start_buffer)
					freeValue = start_buffer; //ֻ�������ܼ�С
				GrClear(0);	
				GrString_GB2312("�����÷�����",0,2);
				GrStringNum(mins,0,4,6);
				GrString_GB2312("����",4,8);
				pre_value = freeValue;
			}
			if(((ui8ButtonKeyValue & KEY_LEFT_ENTER) != 0)&(seted==0)) //ȷ��
			{
				start_time = N_SysTick/CLOCKS_PER_SEC;//��ʼʱ֡��
				total_secs = mins * 60;//�趨������
				pre_sec = total_secs;
				seted = 1 ;
			}
			while((seted==1) && ((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0))
			{
					left_time = total_secs-(N_SysTick/CLOCKS_PER_SEC - start_time);
					sec = left_time % 60;
					min = (left_time / 60) % 60;
					if(pre_sec != left_time)
					{
						GrClear(0);	
						GrString_GB2312("��ǰʱ��",0,4);
						//�����ʾ
						GrStringNum(min,0,4,4);
						GrString_GB2312("��",4,6);
						GrStringNum(sec,0,4,8);
						GrString_GB2312("��",4,10);
						pre_sec = left_time;
					}
					if(left_time < 1)
					{
						GrClear(0);	
						FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3��1
						FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //
						GrString_GB2312("ʱ�䵽��",4,5);
						delay(2000000);//�ӳ�ʱ��
						FPTB->PCOR |= BIT0+BIT1+BIT2+BIT3; //�����B 0 1 2 3��0
						FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //
						finished = 1;
					}
			}
		}
		ui8Value = crease_buffer;
}