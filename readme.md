C语言扫雷项目
=============
*该项目仅适用于Windows系统*
<br>
项目简介
---------
<pre>
     该项目使用C语言编写，是最基本的扫雷程序，目前仅仅完成了最基本的功能，包括布置雷区、绘制界面、获取鼠标信息、判断胜负、重新开始游戏等
</pre>

<br><br>
目前存在的问题
-----------
<pre>
    1.游戏依赖pic目录内的文件，使用时必须要把exe文件已经pic目录下载到同一文件夹(图片在pic目录内)。没有打包进exe中
    2.目前没有加入计时功能
    3.目前没有高分保存功能
    4.游戏算法较慢，在生成36*16 99雷的时候用了10秒才完成布雷和绘制
</pre>
<br><br>

*截图预览*

![扫雷](https://github.com/TOKISAKIKRM/Mine-sweeper/edit/master/readme_pic/微信截图_20191028104959.png)
![扫雷](https://github.com/TOKISAKIKRM/Mine-sweeper/edit/master/readme_pic/TIM截图20191028105033.jpg)
![扫雷](https://github.com/TOKISAKIKRM/Mine-sweeper/edit/master/readme_pic/TIM截图20191028105055.jpg)
![扫雷](https://github.com/TOKISAKIKRM/Mine-sweeper/edit/master/readme_pic/TIM截图20191028105308.jpg)

-------------
<br>
<br>
*项目思路*
<pre>
    1.创建一个二维数组，并往里面随机放雷，然后对数组简单加密
    2.用图片的方式打印出这个二维数组(即游戏的主界面)
    3.循环接收鼠标消息，左键翻开空白图盘，右键插旗子或取消旗子
    4.判断游戏是否能继续(胜利和失败)并且重新开始游戏
</pre>
<br>
<br>
*代码实现*
<pre>
<code>
    //1.1 创建一个二维数组
    #define ROW 36  //行数
    #define COL 16  //列数
    #define NUMBER 99//总雷数
    int map[ROW][COL];//申明一个ROW行COL列的二维数组

    //1.2 对数组进行随机布雷
    srand((unsigned)time(NULL));//设置随机数种子，头文件<Windows.h>

    for (int i = 0; i < ROW; i++) {				//数组初始化为0
		for (int j = 0; j < COL; j++) {
			map[i][j] = 0;
		}
	}

    int d = 0;			//布雷
	while (d < NUMBER) {
		//随机生成雷的行列
		int r;//行数
		int c;//列数
		r = rand() % ROW;
		c = rand() % COL;
		//防止重复
		while (map[r][c] == -1) {//用-1当做雷
			srand((unsigned)time(NULL));
			r = rand() % COL;
			c = rand() % ROW;
		}
		//输入雷
		map[r][c] = -1;
		//循环+1
		d++;
	}

    /*现在数组里已经被随机放入了NUMBER个雷*/

    //1.3   根据扫雷规则，把不是雷的部分显示九宫格内的雷数
    /*因为几个特殊位置会造成数组越界，所以分情况讨论*/
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
    /*此时数组初始化完成*/

    //1.4   对数组进行加密 全部+20 则打印的内容是-1+20 ~ 8+20
    for (i = 0; i < ROW; i++) {//全部加上20打印出空白格子
		for (j = 0; j < COL; j++) {
			map[i][j] += 20;
		}
	}
    /*此时数组加密完成，后续不会直接打印数字*/
    //2.1   载入对应图片,图片素材在pic内
        /*此处的头文件是 graphics.h 需要自行安装*/
    IMAGE IMAGE img[15];//用来存放图片
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
    
    /*此时图片已经载入完成*/

    //2.2   根据数组数字来打印图片
        #define SIZE 30//图片像素
        hwnd=initgraph(SIZE1 * ROW, SIZE1 * COL);//生成游戏界面
    	for (int i = 0; i < ROW; i++) {//遍历数组，并且根据数组内的数字打印图片
		for (int j = 0; j < COL; j++) {
			switch (map[i][j])
			{	
			case 0://数字0-8
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
			case -1://雷
				putimage(i * SIZE1, j * SIZE1, &img[11]);
				break;
			case 100://点击错误
				putimage(i * SIZE1, j * SIZE1, &img[12]);
			case 101://其余错误
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
    /*此时游戏打印出一堆空白方块以供点击*/

    //3.1    接收鼠标消息
    MOUSEMSG msg = { 0 };//初始化鼠标消息 该类型在easyx.h头文件中

    //3.2   对鼠标消息进行处理
        int r, c;//坐标
	    int flag;
	    flag = NUMBER;//旗子数量等于雷的数量
	    int number = NUMBER;//剩余雷的数量
    	while (1) {
		if (number == 0)//没有雷了就获胜
			gamewin();//胜利画面
		msg = GetMouseMsg();//获取鼠标消息
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://左键，翻开空白图片
			r = msg.x / SIZE1;
			c = msg.y / SIZE1;
			if (map[r][c] >= 19 && map[r][c] <= 28) {//如果是可点击范围
				if (map[r][c] == 20) {//如果打开的是0
					if_near_zero(r, c);//翻开零的九宫格
				}
				else {
					map[r][c] -= 20;//解密，减掉20出现原本的数字
				}
			}
				
			if (map[r][c] == -1){//如果翻开的是雷，游戏失败
				map[r][c] = 100;//100对应点开错误的雷
				gameover();//游戏结束代码
			}
			break;
		case WM_RBUTTONDOWN://右键，标记雷
			r = msg.x / SIZE1;
			c = msg.y / SIZE1;
			if (map[r][c] >= 19 && map[r][c] <= 28 && flag>0) {//这个范围是添加标记
				if ((map[r][c] - 20) == -1)//如果是雷就把雷-1
					number -= 1;
				map[r][c] += 50;//标记+50代表插了旗子
				flag--;
			}
			else if (map[r][c] >= 30) {//取消标记
				flag++;
				map[r][c] -= 50;//解密
				if ((map[r][c]) - 20 == -1)//如果取消的是雷就把雷去掉
					number += 1;
			}
			break;
		default:
			break;
		}
		drawmap();//这是第二部分的代码
	}
    /*此时代码可以正确响应指令*/

    //3.3   翻开零的九宫格
    /*扫雷游戏中，如果点开的一格是零，那代表九宫格内没有雷，应该自动把九宫格全部翻开。如果零的九宫格内还有零，就继续执行这个操作，所以我们要用到递归*/

    /*由于涉及到九宫格，所以还是要分情况讨论*/

void if_near_zero(int r, int c) {
	//先把零自己打开
	map[r][c] -= 20;
	int i, j;

	if (r == 0 && c == 0) {//左上角
		for (i = r ; i <= r + 1; i++) {
			for (j = c ; j <= c + 1; j++) {
				if (map[i][j] >= 19 && map[i][j] <= 28) {
					if (map[i][j] != 20 && map[i][j]!=19) {
						map[i][j] -= 20;
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
				}
				else if (map[i][j] == 20)
					if_near_zero(i, j);
			}
		}
	}
	}
}
    /*此时游戏可以正常运行*/

    //4.1   失败
    /*当点开雷的时候游戏结束*/

    /*接上文的gameover()函数*/
void gameover(void) {
	for (int i = 0; i < ROW; i++) {//把格子全部翻开来
		for (int j = 0; j < COL; j++) {
			if (map[i][j] > 30 && map[i][j] < 100) {
				map[i][j] -= 70;//-70是因为-50的旗子和20的空白加密
				if (map[i][j] != -1) {
					map[i][j] = 101;//101是插错了旗子的雷
				}
			}
			else if (map[i][j] <= 28 && map[i][j] >= 19)
				map[i][j] -= 20;
			else {
				map[i][j] = map[i][j];//废话qwq 当时不加出了错我也不知道为啥
			}
		}
	}
	drawmap();//绘制游戏界面，第二部分的代码
	MessageBox(hwnd, L"游戏失败",L"",MB_OK);//打印失败信息
	system("cls");//清空屏幕
	gameinit();//第一部分的代码，对数组初始化
	drawmap();//重新绘制新的游戏界面
	playgame();//开始游戏，第三部分的代码
}

    //4.2 胜利
    /*基本和上文一样*/
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
    /*代码到此结束*/
</code>
</pre>
