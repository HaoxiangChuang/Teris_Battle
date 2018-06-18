#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int x, int y);//控制光標。X表示橫坐標，Y表示縱坐標
void console();//設置控制台窗口大小，為了讓程序運行得更好看
void my_print();//設置介面
void my_randout();//隨機出現方塊，並列印在提示區
void my_printblock();//列印 4*4 的方格來顯示方塊
void my_up();//旋轉
void my_down();//下移
void my_lift();//左移
void my_right();//右移
void clear();//消除整行
void gameover();//遊戲結束
//void my_stop();//遊戲暫停
int tem[4][4];//用4*4的方格來控制方塊的操作和顯示 這個作為傳值媒介
int block[4][4];//提示區的方塊
int BLOCK[4][4];//正在下落的方塊
int scope[25][34] = { 0 };//操作的範圍 這裡要注意，一個方格是占兩個橫坐標單位的
int point_x, point_y;//方格的左上角坐標
int fen = 0;//得分
bool check = true;//檢查方塊還能不能下落
int block0[4][4] = { { 0, 1, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 } }; // 7 個方塊 用數組表示 正「7」
int block1[4][4] = { { 0, 1, 1, 0 }, { 0, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } }; // 反「7」
int block2[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 1, 1 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } }; // 反「z」
int block3[4][4] = { { 0, 0, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } }; // 正「z」
int block4[4][4] = { { 0, 0, 0, 0 }, { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 } }; // 倒「T」
int block5[4][4] = { { 0, 0, 0, 0 }, { 0, 1, 1, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } }; // 正方形
int block6[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 0, 0, 0, 0 } }; // 直條
void main() {
	srand((unsigned)time(NULL));//設置隨機數種子
	char key;
	int i, j;
	int time = 0; //控制下落時間
	console();
	my_print();
	my_randout();
	while (true) { //死循環
		if (check) { //如果沒有正在下落的方塊就執行if裡面的
			check = false;
			point_x = 14;//方塊最初出現的地方
			point_y = 0;
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					BLOCK[i][j] = block[i][j];//將提示區的方塊數組傳到下落的方塊數組
				}
			}
			my_printblock();//在point_x,point_y顯示方塊。
			my_randout();//提示區隨機換一個方塊
		}
		if (_kbhit()) { //檢測，如果有按鍵就執行if裡面的
			key = _getch();//捕獲按鍵
			switch (key) {
			case 72: my_up(); //上
				break;
			case 75: my_lift(); //左
				break;
			case 77: my_right(); //右
				break;
			case 80: my_down(); //下
				break;
			// case 32: my_stop(); //空格 暫停或開始
			// 	break;
			case 27: exit(0); //Esc 退出
			}
		}
		Sleep(30);//等待0.03秒 0.03秒才能執行一個按鍵 也降低CPU
		if (0 == ++time % 30) { //控制下落的時間=30*30毫秒
			my_down();//時間到自動下落一格
		}

		if (true == check) { //當不能下落時
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (1 == BLOCK[i][j])
						scope[point_x / 2 + j][point_y + i] = BLOCK[i][j];
					//把下落的方塊賦值給操作區的數組，這裡的point_x除以2是因為一個小格子占兩個橫坐標
				}
			}
			my_printblock();
			clear();//如果有某一行滿了就消除
		}
	}
}
//設置窗口位置和大小，為了讓程序運行得更好看
void console() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 獲取標準輸出設備句柄
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // 窗口緩衝區信息
	GetConsoleScreenBufferInfo(hOut, &bInfo);// 獲取窗口緩衝區信息
	SetConsoleTitle("Teris Battle"); // 設置窗口的標題
	COORD size = { 80, 32 };//不能小於默認大小（80，25）
	SetConsoleScreenBufferSize(hOut, size); // 重新設置緩衝區大小*/
	SMALL_RECT rc = { 0, 0, 63, 31 }; //不能大於緩衝區大小
	SetConsoleWindowInfo(hOut, true, &rc);// 重置窗口大小
}
void my_print() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);//黑底亮藍字。
	for (int i = 1; i < 30; i++) {
		printf("■\t\t\t\t■ \n");
	}
	printf("■■■■■■■■■■■■■■■■■ \n");
	gotoxy(36, 0);
	printf("---------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮黃字。
	gotoxy(40, 3);
	printf("分 數： %d", fen);
	gotoxy(36, 6);
	printf("下一個方塊：");
	gotoxy(36, 14);
	printf("操作方法：");
	gotoxy(40, 16);
	printf("↑：旋轉 ↓：沉澱");
	gotoxy(40, 18);
	printf("→：右移 ←：左移");
	gotoxy(39, 20);
	printf("空格鍵：開始 / 暫停");
	gotoxy(39, 22);
	printf(" Esc：退出");
}
//設置光標輸出的位置函數。坐標不能為負數
void gotoxy(int x, int y) { //X表示橫坐標，Y表示縱坐標。
	HANDLE app;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	app = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(app, pos);
}
//旋轉 將4*4方格順時針旋轉
void my_up() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			tem[i][j] = BLOCK[i][j];
			if (1 == BLOCK[i][j]) {
				gotoxy(point_x + j * 2, point_y + i);
				printf(" ");
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			BLOCK[j][3 - i] = tem[i][j];
		}
	}
//以上為旋轉。
//下面為防止旋轉後超出框架範圍
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 4; i++) {
			if (1 == BLOCK[i][j] && point_x < 2) {
				point_x += 2;
			} else if (1 == BLOCK[i][3 - j] && point_x > 24) {
				point_x -= 2;
			}
		}
	}
	my_printblock();//旋轉之後立即顯示出來
}
//左移
void my_lift() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[j][i] && (point_x + 2 * i - 1 < 2 || 1 == scope[point_x / 2 + i - 1][point_y + j])) {
				return;//如果到邊緣 或者是左邊已經有了方塊
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				gotoxy(point_x + j * 2, point_y + i);
				printf(" ");//把之前的擦掉
			}
		}
	}
	point_x -= 2;
	my_printblock();
}
void my_right() {
	int i, j;
	for (i = 3; i > 0; i--) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[j][i] && (point_x + 2 * i + 2 > 30 || 1 == scope[point_x / 2 + i + 1][point_y + j])) {
				return;//如果到邊緣 或者是右邊已經有了方塊
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				gotoxy(point_x + j * 2, point_y + i);
				printf(" ");//把之前的擦掉
			}
		}
	}
	point_x += 2;
	my_printblock();
}
void my_down() {
	int i, j;
	if (true == check) {
		return;//不能下落直接不執行
	}
	gotoxy(point_x, point_y);
	for (i = 3; i > 0; i--) { //檢測該方格還能不能下落
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				if (1 == scope[point_x / 2 + j][point_y + i + 1] || point_y + i + 1 > 28) { //到最下邊或是下面已經有方格
					check = true;
					return;
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				gotoxy(point_x + j * 2, point_y + i);
				printf(" ");//能下落，擦除以前的方格
			}
		}
	}
	point_y++;
	my_printblock();//在下一格顯示
}
//暫停
// void my_stop() {
// 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
// 	gotoxy(10, 10); printf(" ");
// 	gotoxy(10, 11); printf(" ■■■■■ ");
// 	gotoxy(10, 12); printf(" ■ ■ ");
// 	gotoxy(10, 13); printf(" ■ ■ ");
// 	gotoxy(10, 14); printf(" ■■■■■ ");
// 	gotoxy(10, 15); printf(" ■ ");
// 	gotoxy(10, 16); printf(" ■ ");
// 	gotoxy(10, 17); printf(" ■ ");
// 	gotoxy(10, 18); printf(" ");
// 	if (32 == _getch()) { //用等待輸入字符實現暫停 32為空格
// 		gotoxy(10, 10); printf(" ");
// 		gotoxy(10, 11); printf(" ■■■■■ ");
// 		gotoxy(10, 12); printf(" ■ ");
// 		gotoxy(10, 13); printf(" ■ ");
// 		gotoxy(10, 14); printf(" ■■■■■ ");
// 		gotoxy(10, 15); printf(" ■ ");
// 		gotoxy(10, 16); printf(" ■ ");
// 		gotoxy(10, 17); printf(" ■■■■■ ");
// 		gotoxy(10, 18); printf(" ");
// 		Sleep(1000);
// 		gotoxy(10, 10); printf(" ");
// 		gotoxy(10, 11); printf(" ■■■■■ ");
// 		gotoxy(10, 12); printf(" ■ ");
// 		gotoxy(10, 13); printf(" ■ ");
// 		gotoxy(10, 14); printf(" ■■■■■ ");
// 		gotoxy(10, 15); printf(" ■ ");
// 		gotoxy(10, 16); printf(" ■ ");
// 		gotoxy(10, 17); printf(" ■■■■■ ");
// 		gotoxy(10, 18); printf(" ");
// 		Sleep(1000);
// 		gotoxy(10, 10); printf(" ");
// 		gotoxy(10, 11); printf(" ■■ ");
// 		gotoxy(10, 12); printf(" ■■■ ");
// 		gotoxy(10, 13); printf(" ■■ ");
// 		gotoxy(10, 14); printf(" ■■ ");
// 		gotoxy(10, 15); printf(" ■■ ");
// 		gotoxy(10, 16); printf(" ■■ ");
// 		gotoxy(10, 17); printf(" ■■■■ ");
// 		gotoxy(10, 18); printf(" ");
// 		Sleep(1000);
// 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
// 		for (int i = 0; i < 9; i++) { //將暫停掩蓋的方塊再次顯示出來
// 			gotoxy(10, 10 + i);
// 			for (int j = 0; j < 7; j++) {
// 				if (1 == scope[5 + j][10 + i]) {
// 					printf("■");
// 				} else {
// 					printf(" ");
// 				}
// 			}
// 		}
// 	}
// }
//消除
void clear() {
	int i, j, k, m = 0;
	for (i = point_y + 3; i >= point_y; i--) {
		for (j = 1; j < 16; j++) {
			if (0 == scope[j][i]) {
				break;
			}
		}
		if (16 == j) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			m++;
			for (k = i; k > 3; k--) {
				for (j = 1; j < 16; j++) {
					scope[j][k] = scope[j][k - 1];
					gotoxy(j * 2, k);
					if (1 == scope[j][k]) {
						printf("■");
					} else {
						printf(" ");
					}
				}
			}
			for (j = 1; j < 16; j++) {
				scope[j][4] = 0;
			}
			i++;
		}
	}
	switch (m) {//判斷一次消除了幾行，來設置得分數
	case 1: fen += 100;
		break;
	case 2: fen += 230;
		break;
	case 3: fen += 438;
		break;
	case 4: fen += 854;
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮黃色字。
	gotoxy(40, 3);
	printf("分 數： %d", fen);
	for (j = 7; j < 11; j++) {
		if (1 == scope[j][4])
			gameover();
	}
}
//隨機出現方塊
void my_randout() {
	int i, j;
	switch (rand() % 7) {
	case 0:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block0[i][j];
			}
		}
		break;
	case 1:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block1[i][j];
			}
		}
		break;
	case 2:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block2[i][j];
			}
		}
		break;
	case 3:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block3[i][j];
			}
		}
		break;
	case 4:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block4[i][j];
			}
		}
		break;
	case 5:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block5[i][j];
			}
		}
		break;
	case 6:
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				block[i][j] = block6[i][j];
			}
		}
		break;
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			tem[i][j] = block[i][j];
		}
	}
	switch (rand() % 4) { //再設置隨機旋轉的方向
	case 0:
		break;
	case 1:
		for (i = 0; i < 4; i++) { //順時針90度
			for (j = 0; j < 4; j++) {
				block[j][3 - i] = tem[i][j];
			}
		}
		break;
	case 2:
		for (i = 0; i < 4; i++) { //順180度
			for (j = 0; j < 4; j++) {
				block[3 - i][3 - j] = tem[i][j];
			}
		}
		break;
	case 3:
		for (i = 0; i < 4; i++) { //順270度
			for (j = 0; j < 4; j++) {
				block[3 - j][i] = tem[i][j];
			}
		}
		break;
	}
//列印提示區的方塊
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//黑底亮紅字。
	for (i = 0; i < 4; i++) {
		gotoxy(44, 8 + i);
		for (j = 0; j < 4; j++) {
			if (1 == block[i][j]) {
				printf("■");
			} else {
				printf(" ");
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//黑底白字
}
//顯示方格
void my_printblock() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (point_x / 2 + j > 0) {
				if (1 == scope[point_x / 2 + j][point_y + i]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					gotoxy(point_x + j * 2, point_y + i);
					printf("■");
				} else if (1 == BLOCK[i][j]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					gotoxy(point_x + j * 2, point_y + i);
					printf("■");
				}
			}
		}
	}
}
void gameover() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	// gotoxy(4, 10); printf(" ");
	// gotoxy(4, 11); printf(" ■■■ ■ ■ ■■■■ ■■■■ ");
	// gotoxy(4, 12); printf(" ■ ■ ■ ■ ■ ■ ■ ");
	// gotoxy(4, 13); printf(" ■ ■ ■ ■ ■■■■ ■■■■ ");
	// gotoxy(4, 14); printf(" ■ ■ ■ ■ ■ ■■ ");
	// gotoxy(4, 15); printf(" ■■■ ■ ■■■■ ■ ■ ");
	// gotoxy(4, 16); printf(" ");
	gotoxy(32, 17); printf("空格鍵：重來\tEsc：退出");
	switch (_getch()) {
	case 32: system("cls");//清屏
		console();
		my_print();//輸出介面
		my_randout();
		memset(scope, 0, sizeof(int) * 25 * 34);//數組清零
		fen = 0;
		break;
	case 27: exit(0);
		break;
	}
}
