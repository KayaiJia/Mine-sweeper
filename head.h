#pragma once
#define ROW 36	//����
#define COL 16	//����
#define NUMBER 99	//�׵ĸ���
#define SIZE1 30 //ͼƬ��Сd
#define add 20	//ͨ����Ԫ���л�״̬

void gameinit(void);
void drawmap(void);
void playgame(void);
void gameover(void);
void gamewin(void);
void if_near_zero(int r,int c);