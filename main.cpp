#include <stdio.h>
#include <Windows.h>
#include "head.h"
#include <graphics.h>
int map[ROW][COL];
IMAGE img[15];//´æ·ÅÍ¼Æ¬
HWND hwnd;
int con = 0;//¼ÆÊý
int main(void) {
	gameinit();
	drawmap();
	playgame();
	return 0;
}