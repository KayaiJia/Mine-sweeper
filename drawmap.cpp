#include <stdio.h>
#include "head.h"
#include <graphics.h>

extern int map[ROW][COL];
extern IMAGE img[15];
void drawmap(void) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			switch (map[i][j])
			{	
			case 0://Êý×Ö0-8
				putimage(i * SIZE1,j*SIZE1,&img[0]);
				break;
			case 1:
				putimage(i * SIZE1, j * SIZE1, &img[1]);
				break;
			case 2:
				putimage(i * SIZE1, j * SIZE1, &img[2]);
				break;
			case 3:
				putimage(i * SIZE1, j * SIZE1, &img[3]);
				break;
			case 4:
				putimage(i * SIZE1, j * SIZE1, &img[4]);
				break;
			case 5:
				putimage(i * SIZE1, j * SIZE1, &img[5]);
				break;
			case 6:
				putimage(i * SIZE1, j * SIZE1, &img[6]);
				break;
			case 7:
				putimage(i * SIZE1, j * SIZE1, &img[7]);
				break;
			case 8:
				putimage(i * SIZE1, j * SIZE1, &img[8]);
				break;
			case -1://À×
				putimage(i * SIZE1, j * SIZE1, &img[11]);
				break;
			case 100://µã»÷´íÎó
				putimage(i * SIZE1, j * SIZE1, &img[12]);
			case 101://ÆäÓà´íÎó
				putimage(i * SIZE1, j * SIZE1, &img[10]);
			default:
				if (map[i][j]<=28 && map[i][j]>=19)
					putimage(i * SIZE1, j * SIZE1, &img[14]);
				if (map[i][j]>=30 && map[i][j]<100)
					putimage(i * SIZE1, j * SIZE1, &img[9]);
				break;
			}
		}
		printf("\n");
	}
}