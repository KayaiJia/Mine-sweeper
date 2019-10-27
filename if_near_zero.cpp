#include <stdio.h>
#include "head.h"

extern int map[ROW][COL];
extern int con;

void if_near_zero(int r, int c) {
	//先把零自己打开
	map[r][c] -= 20;
	con++;
	int i, j;

	if (r == 0 && c == 0) {//左上角
		for (i = r ; i <= r + 1; i++) {
			for (j = c ; j <= c + 1; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j]!=19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r == 0 && c == COL - 1) {//左下角
		for (i = r; i <= r + 1; i++) {
			for (j = c-1; j <= c; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r == 0 && c != 0 && c!=COL-1) {//左边
		for (i = r; i <= r + 1; i++) {
			for (j = c - 1; j <= c+1; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r == ROW-1 && c == 0) {//右上角
		for (i = r-1; i <= r; i++) {
			for (j = c; j <= c + 1; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r == ROW - 1 && c == COL-1) {//右下角
		for (i = r - 1; i <= r; i++) {
			for (j = c-1; j <= c; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r == ROW - 1 && c !=0 && c!=COL-1) {//右边
		for (i = r - 1; i <= r; i++) {
			for (j = c - 1; j <= c+1; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r != ROW - 1 && c ==0 && r!=0) {//上边
		for (i = r - 1; i <= r + 1; i++) {
			for (j = c; j <= c+1; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else if (r != ROW - 1 && c == COL-1 && r != 0) {//下边
		for (i = r - 1; i <= r + 1; i++) {
			for (j = c-1; j <= c; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j] != 19) {
						map[i][j] -= 20;
						con++;
					}
					else if (map[i][j] == 20)
						if_near_zero(i, j);
				}
			}
		}
	}
	else {
	for (i = r - 1; i <= r + 1; i++) {
		for (j = c - 1; j <= c+1; j++) {
			if (map[i][j] >= 19 && map[i][j] <= 28) {
				if (map[i][j] != 20 && map[i][j] != 19) {
					map[i][j] -= 20;
					con++;
				}
				else if (map[i][j] == 20)
					if_near_zero(i, j);
			}
		}
	}
	}
}