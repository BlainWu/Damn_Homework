#include "user.h"
#include <stdlib.h>
#include "HMI.h"
uint16_t adc_result;
int CLOCKS_PER_SEC = 20; //每秒时钟跨度
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
	crease_buffer = ui8Value;//确保退出后还保存在进入口
	ADC0_init();
	GrClear(0);	
	GrString_GB2312("当前音量",0,4);
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
			//模拟量到数字量的处理
			///
			GrString_GB2312("分贝",4,11);
			GrStringNum(adc_result,0,4,6);
		}
	}
	ui8Value = crease_buffer;
}

void Sound_Mode(void)
{
	uint8_t crease_buffer;
	crease_buffer = ui8Value;//确保退出后还保存在进入口
	ADC0_init();
	GrClear(0);	
	int db,db_thr=300;
	GrString_GB2312("声音控制模式",2,4);
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
			//模拟量到数字量的处理
			///
			db = adc_result - 100;//虚假的计算过程
			if (db >db_thr) //当超过阈值的时候，灯亮
			{
					FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置1
					FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //
					GrString_GB2312("照亮",4,6);
					delay(10000);//延长时间
			}
			else
			{
					FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置0
					FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; // 
					GrString_GB2312("黑暗",4,6);
			}
		}
	}
	ui8Value = crease_buffer;
}

void Button_control(void)
{
		uint8_t crease_buffer;
		crease_buffer = ui8Value;//确保退出后还保存在进入口
		GrClear(0);	
		GrString_GB2312("按下控制模式",0,2);
		GrString_GB2312("按上下键切换",2,2);
		int mode_num;
		mode_num = ui8Value;

		while(((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0) & ((mode_num ==1)||(mode_num ==0))) //闪烁灯模式
		{
				mode_num = ui8Value;
				GrClear(0);	
				GrString_GB2312("按下切换模式",0,2);
				GrString_GB2312("闪烁",6,6);
				FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置1
				FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //灯亮的同时，在第八行显示*
			mode_num = ui8Value;
				delay(5000000);//延时
				mode_num = ui8Value;
				GrClear(0);	
				GrString_GB2312("按下切换模式",0,2);
				FPTB->PCOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置0
				FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //灯亮的熄灭，*消失
			mode_num = ui8Value;
				delay(5000000);//延时
			mode_num = ui8Value;
		}
				while(((ui8ButtonKeyValue & KEY_RIGHT_EXIT) == 0) & (mode_num ==2)) //流彩灯
		{
				mode_num = ui8Value;
				GrClear(0);	
				GrString_GB2312("按下切换模式",0,2);
				GrString_GB2312("流彩灯",6,5);
				FPTB->PSOR |= BIT0;
				FPTB->PDDR |= BIT0;
				GrString_GB2312("0",6,12);
			mode_num = ui8Value;
				delay(2000000);//延时
				mode_num = ui8Value;
				FPTB->PCOR |= BIT0;
				FPTB->PDDR |= BIT0;
			mode_num = ui8Value;
				delay(2000000);//延时
			  mode_num = ui8Value;
				FPTB->PSOR |= BIT1;
				FPTB->PDDR |= BIT1;
				GrString_GB2312("1",6,12);
			mode_num = ui8Value;
				delay(2000000);//延时
			  mode_num = ui8Value;
				FPTB->PCOR |= BIT1;
				FPTB->PDDR |= BIT1;	
			  mode_num = ui8Value;
				delay(2000000);//延时
				mode_num = ui8Value;
				FPTB->PSOR |= BIT2;
				FPTB->PDDR |= BIT2;
				mode_num = ui8Value;
				GrString_GB2312("2",6,12);
				mode_num = ui8Value;
				delay(2000000);//延时
				mode_num = ui8Value;
				FPTB->PCOR |= BIT2;
				FPTB->PDDR |= BIT2;	
				mode_num = ui8Value;
				delay(2000000);//延时
				mode_num = ui8Value;
				FPTB->PSOR |= BIT3;
				FPTB->PDDR |= BIT3;
				GrString_GB2312("3",6,12);
				mode_num = ui8Value;
				delay(2000000);//延时
				mode_num = ui8Value;
				FPTB->PCOR |= BIT3;
				FPTB->PDDR |= BIT3;	
				mode_num = ui8Value;
				delay(2000000);//延时
				mode_num = ui8Value;
		}
		while(((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0) & (mode_num ==3)) //星光模式
		{
				mode_num = ui8Value;
				GrClear(0);	
				int a = rand(),choice;
				choice = a%4;
				GrString_GB2312("按下切换模式",0,2);
				GrString_GB2312("星光",6,6);
				switch(choice)
				{
					case 0:
					{
						FPTB->PSOR |= BIT0; 
						FPTB->PDDR |= BIT0;
						GrString_GB2312("0",6,10);
						mode_num = ui8Value;
						delay(4000000);//延时
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
						delay(4000000);//延时
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
						delay(4000000);//延时
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
						delay(4000000);//延时
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
	
	FPTB->PCOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置零初始化
	FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; // 
}

void Clock_Mode(void)
{

	uint8_t crease_buffer;
	crease_buffer = ui8Value;//确保退出后还保存在进入口
	//---------//
	int hour=0,min=0,sec=0,total_secs=0;//初始化时分秒
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
			GrString_GB2312("当前时间",0,4);
			//输出显示
			GrStringNum(hour,0,4,2);
			GrString_GB2312("时",4,4);
			GrStringNum(min,0,4,6);
			GrString_GB2312("分",4,8);
			GrStringNum(sec,0,4,10);
			GrString_GB2312("秒",4,12);
			pre_sec = total_secs;
		}
	}
	ui8Value = crease_buffer;
}

void Timer(void)
{
		uint8_t crease_buffer;
		crease_buffer = ui8Value;//确保退出后还保存在进入口
		int start_buffer = freeValue , pre_value = freeValue;
		int mins=1;//设定的分钟数
		int sec,min,total_secs,start_time,pre_sec,left_time;//倒计时所用到的参数
		int seted = 0,finished=0;
		GrClear(0);	
		GrString_GB2312("请设置分钟数",0,2);
		GrStringNum(mins,0,4,6);
		GrString_GB2312("分钟",4,8);
		while(((ui8ButtonKeyValue&KEY_RIGHT_EXIT) == 0) && (finished ==0))
		{
			if((pre_value != freeValue)& (seted==0))//如果分钟数更换，刷新界面
			{
				mins = (freeValue - start_buffer)+1;
				if(mins < 1)
					mins = 1; //分钟数不小于1min
				if(freeValue<start_buffer)
					freeValue = start_buffer; //只能增大不能减小
				GrClear(0);	
				GrString_GB2312("请设置分钟数",0,2);
				GrStringNum(mins,0,4,6);
				GrString_GB2312("分钟",4,8);
				pre_value = freeValue;
			}
			if(((ui8ButtonKeyValue & KEY_LEFT_ENTER) != 0)&(seted==0)) //确定
			{
				start_time = N_SysTick/CLOCKS_PER_SEC;//开始时帧数
				total_secs = mins * 60;//设定总秒数
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
						GrString_GB2312("当前时间",0,4);
						//输出显示
						GrStringNum(min,0,4,4);
						GrString_GB2312("分",4,6);
						GrStringNum(sec,0,4,8);
						GrString_GB2312("秒",4,10);
						pre_sec = left_time;
					}
					if(left_time < 1)
					{
						GrClear(0);	
						FPTB->PSOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置1
						FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //
						GrString_GB2312("时间到！",4,5);
						delay(2000000);//延长时间
						FPTB->PCOR |= BIT0+BIT1+BIT2+BIT3; //输出口B 0 1 2 3置0
						FPTB->PDDR |= BIT0+BIT1+BIT2+BIT3; //
						finished = 1;
					}
			}
		}
		ui8Value = crease_buffer;
}