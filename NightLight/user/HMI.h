#ifndef __HMI_H__
#define __HMI_H__
//*****************************************************************************
//
// Include Files
//
//*****************************************************************************
#include "user.h"

#define 	KEY_LEFT_ENTER 		(BIT1)
#define 	KEY_RIGHT_EXIT 		(BIT2)

extern uint8_t 	ui8ButtonKeyValue,ui8Value;
extern char *cMenuString[];

//-----外部函数声明-----
void Key_Init(void);
void Key_IODect(void);
void DrawMenu( uint8_t ui8SelectNum);
#endif

