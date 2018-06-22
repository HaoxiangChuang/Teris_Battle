#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "startscreen.h"
#include "save.h"
#include "whitewin.h"
#include "blackwin.h"
#include "leaderboard.h"
#define N 20

void create_board(char (*board)[N]);
void print_board(char (*board)[N]);
void print_info(int flag, int person);
void gotoxy(int xpos, int ypos);
int play_chess(char (*board)[N], int *person, int *x, int *y);
int check_board(char (*board)[N], int *person, int x, int y);

int main(void) {
    startscreen();
    int input;
    gotoxy(35, 15);
    printf("給我按1或\n");
    gotoxy(35, 17);
    printf("按2進排行榜\n");
    gotoxy(35, 19);
    printf("按3離開");
    scanf("%d", &input);
    while (input != 3) {
        if (input == 1) {
            system("cls");
            save();
            system("cls");
            system("color e0");
            char board[N][N];
            int person = 0, flag = 0, x = 0, y = 0;

            create_board(board);
            while (1) {
                print_board(board);
                print_info(flag, person);
                if (flag == 1) {
                    puts(" ");
                }
                if ((flag = play_chess(board, &person, &x, &y)) == -1 || flag == 3) {
                    continue;
                } else if (flag == 2) {
                    return 0;
                }
                flag = check_board(board, &person, x, y);
            }
        }
        if (input == 2) {
            leaderboard();
        }
        gotoxy(35, 30);
        printf("給我按1或\n");
        gotoxy(35, 32);
        printf("按2進排行榜\n");
        gotoxy(35, 36);
        printf("按3離開");
        scanf("%d", &input);
    }
    return 0;
    system("pause");
}

void create_board(char (*board)[N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = '+';
        }
    }

    return;
}

void print_board(char (*board)[N]) {
    int i, j;

    system("cls");
    printf("\n");
    printf("  ");
    for (i = 1; i < N; i++) {
        printf("%2d  ", i);
    }
    printf("\n");
    printf("  -----------------------------------------------------------------------------\n");
    for (i = 1; i < N; i++) {
        printf("%2d|", i);
        for (j = 1; j < N; j++) {
            printf("%-2c  ", board[i][j]);
        }
        printf("|\n\n");

    }
    printf("  -----------------------------------------------------------------------------\n");

    return;
}

void print_info(int flag, int person) {
    if (flag == 1) {
        if (person == 0) {
            blackwin();
            printf("黑棋 勝!!\n");
            return;
        } else {
            whitewin();
            printf("白棋 勝!!\n");
            return;
        }
    } else {
        if (flag == -1) {
            printf("錯誤!請再輸入一次!\n");
        }
        if (person == 0) {
            printf("換 黑棋!(按q離開遊戲)\n");
        } else {
            printf("換 白棋!(按q離開遊戲)\n");
        }
    }
}

int play_chess(char (*board)[N], int *person, int *x, int *y) {
    char choice;

    printf("輸入位置(x,y): ");
    while ((scanf("%d,%d", x, y) != 2) || *x < 0 || *x > N - 1 || *y < 0 || *y > N - 1) {
        choice = getchar();
        if (choice == 'q' && getchar() == '\n') {
            return 2;
        } else if (choice == 'r' && getchar() == '\n') {
            if (board[*x][*y] == '+') {
                printf("You have already rescinded!\n");
                return -1;
            }
            board[*x][*y] = '+';
            *person = (*person + 1) % 2;
            return 3;
        }
        return -1;
    }
    if (board[*x][*y] != '+') {
        return -1;
    }
    if (*person == 0) {
        board[*x][*y] = 'X';
    } else {
        board[*x][*y] = 'O';
    }

    return 0;
}

int check_board(char (*board)[N], int *person, int x, int y) {
    int i, j;
    int pos_x = x, pos_y = y;
    int cnt, sign;
    int a[4][2] = {{0, 1}, {1, 1}, { -1, 0}, { -1, 1}};

    for (i = 0; i < 4; i++) {
        cnt = sign = 1;
        j = 0;
        while (1) {
            pos_x += sign * a[i][j];
            pos_y += sign * a[i][j + 1];
            if ((board[pos_x][pos_y] == board[x][y]) && pos_x >= 0 && pos_x <= N - 1 && pos_y >= 0 && pos_y <= N - 1)
                cnt++;
            else {
                if (sign == -1) {
                    break;
                }
                sign = -1;
                pos_x = x;
                pos_y = y;
            }
            if (cnt == 5) {
                return 1;
            }
        }
    }
    *person = (*person + 1) % 2;

    return 0;
}
void gotoxy(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
