#include <stdlib.h>
#include "utils.h"
#include "user.h"

int main(void)
{
	//ϵͳ���ó�ʼ��//
	LCD_DriverInit();
	Key_Init();
	GPIO_Init();
	__enable_irq();
	//������ʼ��//
	uint8_t Key_Prev = 1;
	uint8_t ui8Key = 1;
	int start_time = N_SysTick;
	//��ѭ��
	while(1)
	{
		ui8ButtonKeyValue &= ~(KEY_LEFT_ENTER+KEY_RIGHT_EXIT);
		//-----���в˵���ʾ����-------
		DrawMenu(ui8Key);
		while((ui8ButtonKeyValue&KEY_LEFT_ENTER) == 0)
		{
			ui8Key = ui8Value;
			if(ui8Key != Key_Prev)
			{
				DrawMenu(ui8Key);
				Key_Prev = ui8Key;
			}
		}
		//-----����Demo����-------
		ui8ButtonKeyValue &= ~(KEY_LEFT_ENTER+KEY_RIGHT_EXIT);		//ȷ�Ϻ��˳�����������
		switch(ui8Key)
		{
			case 1:Button_control(); break;
			case 2:Sound_Mode(); break;
			case 3:Sound_Detect(); break;//�������
			case 4:Clock_Mode();break; //ʱ��
			case 5:Timer();break;
		}
		DrawMenu(ui8Key);					//�ָ�ԭ�˵�����
	}
}
