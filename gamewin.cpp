#include <stdio.h>
#include <Windows.h>
#include "head.h"
#include <stdlib.h>
extern HWND hwnd;
extern int map[ROW][COL];
void gamewin(void) {
	for (int i = 0; i < ROW; i++) {//把格子全部翻开来
		for (int j = 0; j < COL; j++) {
			if (map[i][j] > 30)
				map[i][j] -= 70;
			else if (map[i][j] <= 28 && map[i][j] >= 19)
				map[i][j] -= 20;
		}
	}
	drawmap();
	MessageBox(hwnd, L"你赢了！", L"", MB_OK);
	system("cls");
	gameinit();
	drawmap();
	playgame();
}