#include <stdio.h>
#include <Windows.h>
#include "head.h"
#include <stdlib.h>
extern HWND hwnd;
extern int map[ROW][COL];
void gameover(void) {
	for (int i = 0; i < ROW; i++) {//把格子全部翻开来
		for (int j = 0; j < COL; j++) {
			if (map[i][j] > 30 && map[i][j] < 100) {
				map[i][j] -= 70;
				if (map[i][j] != -1) {
					map[i][j] = 101;
				}
			}
			else if (map[i][j] <= 28 && map[i][j] >= 19)
				map[i][j] -= 20;
			else {
				map[i][j] = map[i][j];
			}
		}
	}
	drawmap();
	MessageBox(hwnd, L"游戏失败",L"",MB_OK);
	system("cls");
	gameinit();
	drawmap();
	playgame();
}