#include <stdlib.h>
#include "utils.h"
#include "user.h"

int main(void)
{
	//系统设置初始化//
	LCD_DriverInit();
	Key_Init();
	GPIO_Init();
	__enable_irq();
	//参数初始化//
	uint8_t Key_Prev = 1;
	uint8_t ui8Key = 1;
	int start_time = N_SysTick;
	//主循环
	while(1)
	{
		ui8ButtonKeyValue &= ~(KEY_LEFT_ENTER+KEY_RIGHT_EXIT);
		//-----运行菜单显示程序-------
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
		//-----运行Demo程序-------
		ui8ButtonKeyValue &= ~(KEY_LEFT_ENTER+KEY_RIGHT_EXIT);		//确认和退出按键都清零
		switch(ui8Key)
		{
			case 1:Button_control(); break;
			case 2:Sound_Mode(); break;
			case 3:Sound_Detect(); break;//声音检测
			case 4:Clock_Mode();break; //时钟
			case 5:Timer();break;
		}
		DrawMenu(ui8Key);					//恢复原菜单界面
	}
}
