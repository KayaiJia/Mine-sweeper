#include <stdio.h>
#include "head.h"

extern int map[ROW][COL];
extern int con;

void if_near_zero(int r, int c) {
	//�Ȱ����Լ���
	map[r][c] -= 20;
	con++;
	int i, j;

	if (r == 0 && c == 0) {//���Ͻ�
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
	else if (r == 0 && c == COL - 1) {//���½�
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
	else if (r == 0 && c != 0 && c!=COL-1) {//���
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
	else if (r == ROW-1 && c == 0) {//���Ͻ�
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
	else if (r == ROW - 1 && c == COL-1) {//���½�
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
	else if (r == ROW - 1 && c !=0 && c!=COL-1) {//�ұ�
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
	else if (r != ROW - 1 && c ==0 && r!=0) {//�ϱ�
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
	else if (r != ROW - 1 && c == COL-1 && r != 0) {//�±�
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