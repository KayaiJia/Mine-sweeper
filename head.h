#pragma once
#define ROW 36	//行数
#define COL 16	//列数
#define NUMBER 99	//雷的个数
#define SIZE1 30 //图片大小d
#define add 20	//通过该元素切换状态

void gameinit(void);
void drawmap(void);
void playgame(void);
void gameover(void);
void gamewin(void);
void if_near_zero(int r,int c);