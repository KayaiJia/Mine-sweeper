#include <stdio.h>
#include <Windows.h>
#include "head.h"
#include <stdlib.h>
extern HWND hwnd;
extern int map[ROW][COL];
void gamewin(void) {
	for (int i = 0; i < ROW; i++) {//�Ѹ���ȫ��������
		for (int j = 0; j < COL; j++) {
			if (map[i][j] > 30)
				map[i][j] -= 70;
			else if (map[i][j] <= 28 && map[i][j] >= 19)
				map[i][j] -= 20;
		}
	}
	drawmap();
	MessageBox(hwnd, L"��Ӯ�ˣ�", L"", MB_OK);
	system("cls");
	gameinit();
	drawmap();
	playgame();
}