#include <stdio.h>
#include <Windows.h>
#include "head.h"
#include <easyx.h>
#include <stdlib.h>

extern int map[ROW][COL];
extern int con;
void playgame(void) {
	int r, c;
	int flag;
	flag = NUMBER;
	con = 0;
	int number = NUMBER;
	MOUSEMSG msg = { 0 };//��ʼ�������Ϣ
	while (1) {
		if (number == 0)//û�����˾ͻ�ʤ
			gamewin();
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://����������հ�ͼƬ
			r = msg.x / SIZE1;
			c = msg.y / SIZE1;
			if (map[r][c] >= 19 && map[r][c] <= 28) {
				if (map[r][c] == 20) {//����򿪵���0
					if_near_zero(r, c);
				}
				else {
					map[r][c] -= 20;
					con++;
				}
			}
				
			if (map[r][c] == -1){//������������ף���Ϸʧ��
				map[r][c] = 100;
				gameover();
			}
			break;
		case WM_RBUTTONDOWN://�Ҽ��������
			r = msg.x / SIZE1;
			c = msg.y / SIZE1;
			if (map[r][c] >= 19 && map[r][c] <= 28 && flag>0) {//�����Χ����ӱ��
				if ((map[r][c] - 20) == -1)//������׾Ͱ���-1
					number -= 1;
				map[r][c] += 50;//���+50
				flag--;
			}
			else if (map[r][c] >= 30) {//ȡ�����
				flag++;
				map[r][c] -= 50;
				if ((map[r][c]) - 20 == -1)//���ȡ�������׾Ͱ���ȥ��
					number -= 1;
			}
			break;
		default:
			break;
		}
		drawmap();
	}
}