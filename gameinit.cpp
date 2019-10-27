//��ʼ����Ϸ
#include "head.h"
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

extern int map[ROW][COL];
extern IMAGE img[15];
extern HWND hwnd;
void gameinit(void) {
	hwnd=initgraph(SIZE1 * ROW, SIZE1 * COL);

	loadimage(&img[0], L"pic\\0.png", SIZE1, SIZE1);//0-8������
	loadimage(&img[1], L"pic\\1.png", SIZE1, SIZE1);
	loadimage(&img[2], L"pic\\2.png", SIZE1, SIZE1);
	loadimage(&img[3], L"pic\\3.png", SIZE1, SIZE1);
	loadimage(&img[4], L"pic\\4.png", SIZE1, SIZE1);
	loadimage(&img[5], L"pic\\5.png", SIZE1, SIZE1);
	loadimage(&img[6], L"pic\\6.png", SIZE1, SIZE1);
	loadimage(&img[7], L"pic\\7.png", SIZE1, SIZE1);
	loadimage(&img[8], L"pic\\8.png", SIZE1, SIZE1);
	loadimage(&img[9], L"pic\\9.png", SIZE1, SIZE1);//����
	loadimage(&img[10], L"pic\\10.png", SIZE1, SIZE1);//�������
	loadimage(&img[11], L"pic\\11.png", SIZE1, SIZE1);//��
	loadimage(&img[12], L"pic\\12.png", SIZE1, SIZE1);//����˴������
	loadimage(&img[13], L"pic\\13.png", SIZE1, SIZE1);//��ȷ����
	loadimage(&img[14], L"pic\\14.png", SIZE1, SIZE1);//�հ�
	/*
		Ԫ��			ͼƬ
		0-8				0-8.png			8+20=28
		-1				11.png			-1+20=19
		19-28			14.png
		>30				9.png
	*/
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < ROW; i++) {				//�����ʼ��Ϊ0
		for (j = 0; j < COL; j++) {
			map[i][j] = 0;
		}
	}
	//-1��ʾ��	��NUMBER����
	int d = 0;			//����
	while (d < NUMBER) {
		//��������׵�����
		int r;//����
		int c;//����
		r = rand() % ROW;
		c = rand() % COL;
		//��ֹ�ظ�
		while (map[r][c] == -1) {
			srand((unsigned)time(NULL));
			r = rand() % COL;
			c = rand() % ROW;
		}
		//������
		map[r][c] = -1;
		//ѭ��+1
		d++;
	}
	//��������Χ������
	int k = 1;
	int n;	//n����Χ�׵ĸ���
	int a, b;	//a���У�b����
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			n = 0;
			if (map[i][j] != -1) {				//�����һ������
				if (i == 0) {					//������������һ��
					if (j == 0) {				//��������Ͻǵ�һ��
						for (a = 0; a <= 1; a++) {
							for (b = 1; b <= 1; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else if (j == COL - 1) {	//������Ͻ�һ��
						for (a = 0; a <= 1; a++) {
							for (b = -1; b <= 0; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else {			//������һ�г�ȥ������
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
				else if (i == ROW - 1) {//�����һ��
					if (j == 0) {//���½�һ��
						for (a = -1; a <= 0; a++) {
							for (b = 0; b <= 1; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else if  (j == COL - 1) {//���½�һ��
						for (a = -1; a <= 0; a++) {
							for (b = -1; b <= 0; b++) {
								if (map[i + a][j + b] == -1) {
									n++;
								}
							}
						}
						map[i][j] = n;
					}
					else {//������һ�г�ȥ������
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
				else if (j == 0) {//����ߵ�һ��
					for (a = -1; a <= 1; a++) {
						for (b = 0; b <= 1; b++) {
							if (map[i + a][j + b] == -1) {
								n++;
							}
						}
					}
					map[i][j] = n;
				}
				else if (j == COL - 1) {//���ұߵĵط�
					for (a = -1; a <= 1; a++) {
						for (b = -1; b <= 0; b++) {
							if (map[i + a][j + b] == -1) {
								n++;
							}
						}
					}
					map[i][j] = n;
				}
				else {//�м�ĸ���
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
	for (i = 0; i < ROW; i++) {//ȫ������20��ӡ���հ׸���
		for (j = 0; j < COL; j++) {
			map[i][j] += 20;
		}
	}
 }