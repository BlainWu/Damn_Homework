#include "user.h"
//---------------------��غ궨��-------------------------

#define MaxValue 7
//---------------------��ر�������-----------------------

uint8_t ui8ButtonKeyValue = 0,ui8Value=1;
int freeValue = 100;

//----�˵��ַ�������----
char *cMenuString[] = {
	"     Сҹ��",
	"1.����ѡ��ģʽ",
	"2.��������ģʽ",
	"3.�ֱ����",
	"4.����ʱ��",
	"5.��ʱ��"
};

#define TOTAL_MENU 5

static void ButtonKey_Init(void)
{		
  //key: PTA1 A2  D4 A12, INPUT PULL-UP
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK+SIM_SCGC5_PORTE_MASK;  //enable clock to PORTA
	PORTA->PCR[16]  = 0x0103; //PTA16 GPIO, Pull-up
	PORTA->PCR[17]  = 0x0103; //PTA17 GPIO, Pull-up
	PORTE->PCR[0] = 0x0103; //PTE0 GPIO, Pull-up
	PORTE->PCR[1]  = 0x0103; //PTE1 GPIO, Pull-up
	FPTA->PDDR &=~(BIT16 + BIT17);	
	FPTE->PDDR &=~(BIT0 + BIT1);
}


void SysTick_Init(void) //10ms
{
	SysTick->LOAD=209715-1;
	SysTick->CTRL = 0x07; //start,clk=sysclk=20.97152MHz,INTEN
}

void Key_Init(void)
{	
	ButtonKey_Init();
	SysTick_Init();
}

static void KEY_Left_Onclick()  
{
	ui8ButtonKeyValue |= KEY_LEFT_ENTER;
}

static void KEY_Right_Onclick()
{
	ui8ButtonKeyValue |= KEY_RIGHT_EXIT;
}
static void KEY_Up_Onclick()
{
	freeValue++;
	if(ui8Value>1)
		ui8Value--;
	else
		ui8Value = TOTAL_MENU;
}
static void KEY_Down_Onclick()
{
	freeValue--;
	if(ui8Value<TOTAL_MENU)
		ui8Value++;
	else
		ui8Value = 1;
}
//===========��ʱɨ�跨�жϻ�е��������Ҫ����Systick�ж��е���============
void Key_IODect(void)
{
	static unsigned char KEY1_Now=0;	//����ֵ������ʱ�豣��
	unsigned char KEY1_Past=0;
	static unsigned char KEY2_Now=0;	//����ֵ������ʱ�豣��
	unsigned char KEY2_Past=0;
	static uint8_t KEY3_Now=0,KEY4_Now=0;
	uint8_t KEY3_Past=0,KEY4_Past=0;
	
	KEY1_Past = KEY1_Now;
	KEY2_Past = KEY2_Now;
	KEY3_Past = KEY3_Now;
	KEY4_Past = KEY4_Now;
	
	
	//-----��ѯPTA17������Ĵ���-----
	if(FPTA->PDIR & BIT17)
		KEY1_Now=1;
	else
		KEY1_Now=0;
	//-----ǰһ�θߵ�ƽ����һ�ε͵�ƽ��˵����������-----
	if((KEY1_Past==1)&&(KEY1_Now==0))
		KEY_Up_Onclick();

	//-----��ѯPTE0������Ĵ���-----
	if(FPTE->PDIR & BIT0)
		KEY2_Now=1;
	else
		KEY2_Now=0;
	//-----ǰһ�θߵ�ƽ����һ�ε͵�ƽ��˵����������-----
	if((KEY2_Past==1)&&(KEY2_Now==0))
		KEY_Right_Onclick();

		//-----��ѯPTE1������Ĵ���-----
	if(FPTE->PDIR & BIT1)
		KEY3_Now=1;
	else
		KEY3_Now=0;
	//-----ǰһ�θߵ�ƽ����һ�ε͵�ƽ��˵����������-----
	if((KEY3_Past==1)&&(KEY3_Now==0))
		KEY_Left_Onclick();
	
	//-----��ѯPTA16������Ĵ���----- 
	if(FPTA->PDIR & BIT16)
		KEY4_Now=1;
	else
		KEY4_Now=0;
	//-----ǰһ�θߵ�ƽ����һ�ε͵�ƽ��˵����������-----
	if((KEY4_Past==1)&&(KEY4_Now==0))
		KEY_Down_Onclick();
}

void DrawMenu( uint8_t ui8SelectNum)
{
	uint8_t i8Forward,i8Backward;
	//--------����ѡ�в˵���--------
	GrClearDisplay(0x00);							//����	
	INVERSECOLOR;											//�ڵװ���
	GrString_GB2312(cMenuString[ui8SelectNum],4,0);
	NORMALCOLOR;											//���������Ĭ�ϸĻذ׵׺���
	//--------�����������˵���--------
	GrString_GB2312(cMenuString[0],0,0);	//������

	if(ui8SelectNum <= 1)
		i8Forward = TOTAL_MENU;
	else
		i8Forward = ui8SelectNum -1;

	if(ui8SelectNum >= TOTAL_MENU)
		i8Backward = 1;
	else
		i8Backward = ui8SelectNum + 1;

	GrString_GB2312(cMenuString[i8Forward],  2,0);	//����ѡ�в˵����ǰһ���˵���
	GrString_GB2312(cMenuString[i8Backward], 6,0);	//����ѡ�в˵����ǰһ���˵���

}

