//初始化游戏
#include "head.h"
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

extern int map[ROW][COL];
extern IMAGE img[15];
extern HWND hwnd;
void gameinit(void) {
	hwnd=initgraph(SIZE1 * ROW, SIZE1 * COL);

	loadimage(&img[0], L"pic\\0.png", SIZE1, SIZE1);//0-8是数字
	loadimage(&img[1], L"pic\\1.png", SIZE1, SIZE1);
	loadimage(&img[2], L"pic\\2.png", SIZE1, SIZE1);
	loadimage(&img[3], L"pic\\3.png", SIZE1, SIZE1);
	loadimage(&img[4], L"pic\\4.png", SIZE1, SIZE1);
	loadimage(&img[5], L"pic\\5.png", SIZE1, SIZE1);
	loadimage(&img[6], L"pic\\6.png", SIZE1, SIZE1);
	loadimage(&img[7], L"pic\\7.png", SIZE1, SIZE1);
	loadimage(&img[8], L"pic\\8.png", SIZE1, SIZE1);
	loadimage(&img[9], L"pic\\9.png", SIZE1, SIZE1);//旗子
	loadimage(&img[10], L"pic\\10.png", SIZE1, SIZE1);//错误的雷
	loadimage(&img[11], L"pic\\11.png", SIZE1, SIZE1);//雷
	loadimage(&img[12], L"pic\\12.png", SIZE1, SIZE1);//点击了错误的雷
	loadimage(&img[13], L"pic\\13.png", SIZE1, SIZE1);//正确的雷
	loadimage(&img[14], L"pic\\14.png", SIZE1, SIZE1);//空白
	/*
		元素			图片
		0-8				0-8.png			8+20=28
		-1				11.png			-1+20=19
		19-28			14.png
		>30				9.png
	*/
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < ROW; i++) {				//数组初始化为0
		for (j = 0; j < COL; j++) {
			map[i][j] = 0;
		}
	}
	//-1表示雷	有NUMBER个雷
	int d = 0;			//布雷
	while (d < NUMBER) {
		//随机生成雷的行列
		int r;//行数
		int c;//列数
		r = rand() % ROW;
		c = rand() % COL;
		//防止重复
		while (map[r][c] == -1) {
			srand((unsigned)time(NULL));
			r = rand() % COL;
			c = rand() % ROW;
		}
		//输入雷
		map[r][c] = -1;
		//循环+1
		d++;
	}
	//生成雷周围的数字
	int k = 1;
	int n;	//n是周围雷的个数
	int a, b;	//a是行，b是列
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			n = 0;
			if (map[i][j] != -1) {				//如果这一格不是雷
				if (i == 0) {					//如果是最上面的一行
					if (j == 0) {				//如果是左上角的一格
						for (a = 0; a <= 1; a++) {
							for (b = 1; b <= 1; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else if (j == COL - 1) {	//如果右上角一格
						for (a = 0; a <= 1; a++) {
							for (b = -1; b <= 0; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else {			//最上面一行出去两个角
						for (a = 0; a <= 1; a++) {
							for (b = -1; b <= 1; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
				}
				else if (i == ROW - 1) {//最底下一行
					if (j == 0) {//左下角一格
						for (a = -1; a <= 0; a++) {
							for (b = 0; b <= 1; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else if  (j == COL - 1) {//右下角一格
						for (a = -1; a <= 0; a++) {
							for (b = -1; b <= 0; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else {//最下面一行除去两个角
						for (a = -1; a <= 0; a++) {
							for (b = -1; b <= 1; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
				}
				else if (j == 0) {//最左边的一行
					for (a = -1; a <= 1; a++) {
						for (b = 0; b <= 1; b++) {
							if (map[i + a][j + b] == -1) {
								n++;
							}
						}
					}
					map[i][j] = n;
				}
				else if (j == COL - 1) {//最右边的地方
					for (a = -1; a <= 1; a++) {
						for (b = -1; b <= 0; b++) {
							if (map[i + a][j + b] == -1) {
								n++;
							}
						}
					}
					map[i][j] = n;
				}
				else {//中间的格子
					for (a = -1; a <= 1; a++) {
						for (b = -1; b <= 1; b++) {
							if (map[i + a][j + b] == -1) {
								n++;
							}
						}
					}
					map[i][j] = n;
				}
			}
			
		}
	}
	for (i = 0; i < ROW; i++) {//全部加上20打印出空白格子
		for (j = 0; j < COL; j++) {
			map[i][j] += 20;
		}
	}
 }