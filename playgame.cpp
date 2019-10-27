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
	MOUSEMSG msg = { 0 };//初始化鼠标消息
	while (1) {
		if (number == 0)//没有雷了就获胜
			gamewin();
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://左键，翻开空白图片
			r = msg.x / SIZE1;
			c = msg.y / SIZE1;
			if (map[r][c] >= 19 && map[r][c] <= 28) {
				if (map[r][c] == 20) {//如果打开的是0
					if_near_zero(r, c);
				}
				else {
					map[r][c] -= 20;
					con++;
				}
			}
				
			if (map[r][c] == -1){//如果翻开的是雷，游戏失败
				map[r][c] = 100;
				gameover();
			}
			break;
		case WM_RBUTTONDOWN://右键，标记雷
			r = msg.x / SIZE1;
			c = msg.y / SIZE1;
			if (map[r][c] >= 19 && map[r][c] <= 28 && flag>0) {//这个范围是添加标记
				if ((map[r][c] - 20) == -1)//如果是雷就把雷-1
					number -= 1;
				map[r][c] += 50;//标记+50
				flag--;
			}
			else if (map[r][c] >= 30) {//取消标记
				flag++;
				map[r][c] -= 50;
				if ((map[r][c]) - 20 == -1)//如果取消的是雷就把雷去掉
					number -= 1;
			}
			break;
		default:
			break;
		}
		drawmap();
	}
}