#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int x, int y);//������СCX��ܾ�СAY����a����
void console();//�]�m����x���f�j�p�A���F���{�ǹB��o��n��
void my_print();//�]�m����
void my_randout();//�H���X�{����A�æC�L�b���ܰ�
void my_printblock();//�C�L 4*4 ��������ܤ��
void my_up();//����
void my_down();//�U��
void my_lift();//����
void my_right();//�k��
void clear();//�������
void gameover();//�C������
//void my_stop();//�C���Ȱ�
int tem[4][4];//��4*4�����ӱ��������ާ@�M��� �o�ӧ@���ǭȴC��
int block[4][4];//���ܰϪ����
int BLOCK[4][4];//���b�U�������
int scope[25][34] = { 0 };//�ާ@���d�� �o�̭n�`�N�A�@�Ӥ��O�e��Ӿ�г�쪺
int point_x, point_y;//��檺���W������
int fen = 0;//�o��
bool check = true;//�ˬd����ٯण��U��
int block0[4][4] = { { 0, 1, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 0 } }; // 7 �Ӥ�� �μƲժ�� ���u7�v
int block1[4][4] = { { 0, 1, 1, 0 }, { 0, 1, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 0, 0 } }; // �ϡu7�v
int block2[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 1, 1 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } }; // �ϡuz�v
int block3[4][4] = { { 0, 0, 0, 0 }, { 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } }; // ���uz�v
int block4[4][4] = { { 0, 0, 0, 0 }, { 0, 1, 0, 0 }, { 1, 1, 1, 0 }, { 0, 0, 0, 0 } }; // �ˡuT�v
int block5[4][4] = { { 0, 0, 0, 0 }, { 0, 1, 1, 0 }, { 0, 1, 1, 0 }, { 0, 0, 0, 0 } }; // �����
int block6[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 1, 1, 1, 1 }, { 0, 0, 0, 0 } }; // ����
void main() {
	srand((unsigned)time(NULL));//�]�m�H���ƺؤl
	char key;
	int i, j;
	int time = 0; //����U���ɶ�
	console();
	my_print();
	my_randout();
	while (true) { //���`��
		if (check) { //�p�G�S�����b�U��������N����if�̭���
			check = false;
			point_x = 14;//����̪�X�{���a��
			point_y = 0;
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					BLOCK[i][j] = block[i][j];//�N���ܰϪ�����ƲնǨ�U��������Ʋ�
				}
			}
			my_printblock();//�bpoint_x,point_y��ܤ���C
			my_randout();//���ܰ��H�����@�Ӥ��
		}
		if (_kbhit()) { //�˴��A�p�G������N����if�̭���
			key = _getch();//�������
			switch (key) {
			case 72: my_up(); //�W
				break;
			case 75: my_lift(); //��
				break;
			case 77: my_right(); //�k
				break;
			case 80: my_down(); //�U
				break;
			// case 32: my_stop(); //�Ů� �Ȱ��ζ}�l
			// 	break;
			case 27: exit(0); //Esc �h�X
			}
		}
		Sleep(30);//����0.03�� 0.03��~�����@�ӫ��� �]���CCPU
		if (0 == ++time % 30) { //����U�����ɶ�=30*30�@��
			my_down();//�ɶ���۰ʤU���@��
		}

		if (true == check) { //����U����
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (1 == BLOCK[i][j])
						scope[point_x / 2 + j][point_y + i] = BLOCK[i][j];
					//��U���������ȵ��ާ@�Ϫ��ƲաA�o�̪�point_x���H2�O�]���@�Ӥp��l�e��Ӿ��
				}
			}
			my_printblock();
			clear();//�p�G���Y�@�溡�F�N����
		}
	}
}
//�]�m���f��m�M�j�p�A���F���{�ǹB��o��n��
void console() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ����зǿ�X�]�ƥy�`
	CONSOLE_SCREEN_BUFFER_INFO bInfo; // ���f�w�İϫH��
	GetConsoleScreenBufferInfo(hOut, &bInfo);// ������f�w�İϫH��
	SetConsoleTitle("Teris Battle"); // �]�m���f�����D
	COORD size = { 80, 32 };//����p���q�{�j�p�]80�A25�^
	SetConsoleScreenBufferSize(hOut, size); // ���s�]�m�w�İϤj�p*/
	SMALL_RECT rc = { 0, 0, 63, 31 }; //����j��w�İϤj�p
	SetConsoleWindowInfo(hOut, true, &rc);// ���m���f�j�p
}
void my_print() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);//�©��G�Ŧr�C
	for (int i = 1; i < 30; i++) {
		printf("��\t\t\t\t�� \n");
	}
	printf("���������������������������������� \n");
	gotoxy(36, 0);
	printf("---------------------------");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r�C
	gotoxy(40, 3);
	printf("�� �ơG %d", fen);
	gotoxy(36, 6);
	printf("�U�@�Ӥ���G");
	gotoxy(36, 14);
	printf("�ާ@��k�G");
	gotoxy(40, 16);
	printf("���G���� ���G�I��");
	gotoxy(40, 18);
	printf("���G�k�� ���G����");
	gotoxy(39, 20);
	printf("�Ů���G�}�l / �Ȱ�");
	gotoxy(39, 22);
	printf(" Esc�G�h�X");
}
//�]�m���п�X����m��ơC���Ф��ର�t��
void gotoxy(int x, int y) { //X��ܾ�СAY����a���СC
	HANDLE app;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	app = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(app, pos);
}
//���� �N4*4��涶�ɰw����
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
//�H�W������C
//�U������������W�X�ج[�d��
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 4; i++) {
			if (1 == BLOCK[i][j] && point_x < 2) {
				point_x += 2;
			} else if (1 == BLOCK[i][3 - j] && point_x > 24) {
				point_x -= 2;
			}
		}
	}
	my_printblock();//���ध��ߧY��ܥX��
}
//����
void my_lift() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[j][i] && (point_x + 2 * i - 1 < 2 || 1 == scope[point_x / 2 + i - 1][point_y + j])) {
				return;//�p�G����t �Ϊ̬O����w�g���F���
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				gotoxy(point_x + j * 2, point_y + i);
				printf(" ");//�⤧�e������
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
				return;//�p�G����t �Ϊ̬O�k��w�g���F���
			}
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				gotoxy(point_x + j * 2, point_y + i);
				printf(" ");//�⤧�e������
			}
		}
	}
	point_x += 2;
	my_printblock();
}
void my_down() {
	int i, j;
	if (true == check) {
		return;//����U������������
	}
	gotoxy(point_x, point_y);
	for (i = 3; i > 0; i--) { //�˴��Ӥ���ٯण��U��
		for (j = 0; j < 4; j++) {
			if (1 == BLOCK[i][j]) {
				if (1 == scope[point_x / 2 + j][point_y + i + 1] || point_y + i + 1 > 28) { //��̤U��άO�U���w�g�����
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
				printf(" ");//��U���A�����H�e�����
			}
		}
	}
	point_y++;
	my_printblock();//�b�U�@�����
}
//�Ȱ�
// void my_stop() {
// 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
// 	gotoxy(10, 10); printf(" ");
// 	gotoxy(10, 11); printf(" ���������� ");
// 	gotoxy(10, 12); printf(" �� �� ");
// 	gotoxy(10, 13); printf(" �� �� ");
// 	gotoxy(10, 14); printf(" ���������� ");
// 	gotoxy(10, 15); printf(" �� ");
// 	gotoxy(10, 16); printf(" �� ");
// 	gotoxy(10, 17); printf(" �� ");
// 	gotoxy(10, 18); printf(" ");
// 	if (32 == _getch()) { //�ε��ݿ�J�r�Ź�{�Ȱ� 32���Ů�
// 		gotoxy(10, 10); printf(" ");
// 		gotoxy(10, 11); printf(" ���������� ");
// 		gotoxy(10, 12); printf(" �� ");
// 		gotoxy(10, 13); printf(" �� ");
// 		gotoxy(10, 14); printf(" ���������� ");
// 		gotoxy(10, 15); printf(" �� ");
// 		gotoxy(10, 16); printf(" �� ");
// 		gotoxy(10, 17); printf(" ���������� ");
// 		gotoxy(10, 18); printf(" ");
// 		Sleep(1000);
// 		gotoxy(10, 10); printf(" ");
// 		gotoxy(10, 11); printf(" ���������� ");
// 		gotoxy(10, 12); printf(" �� ");
// 		gotoxy(10, 13); printf(" �� ");
// 		gotoxy(10, 14); printf(" ���������� ");
// 		gotoxy(10, 15); printf(" �� ");
// 		gotoxy(10, 16); printf(" �� ");
// 		gotoxy(10, 17); printf(" ���������� ");
// 		gotoxy(10, 18); printf(" ");
// 		Sleep(1000);
// 		gotoxy(10, 10); printf(" ");
// 		gotoxy(10, 11); printf(" ���� ");
// 		gotoxy(10, 12); printf(" ������ ");
// 		gotoxy(10, 13); printf(" ���� ");
// 		gotoxy(10, 14); printf(" ���� ");
// 		gotoxy(10, 15); printf(" ���� ");
// 		gotoxy(10, 16); printf(" ���� ");
// 		gotoxy(10, 17); printf(" �������� ");
// 		gotoxy(10, 18); printf(" ");
// 		Sleep(1000);
// 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
// 		for (int i = 0; i < 9; i++) { //�N�Ȱ����\������A����ܥX��
// 			gotoxy(10, 10 + i);
// 			for (int j = 0; j < 7; j++) {
// 				if (1 == scope[5 + j][10 + i]) {
// 					printf("��");
// 				} else {
// 					printf(" ");
// 				}
// 			}
// 		}
// 	}
// }
//����
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
						printf("��");
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
	switch (m) {//�P�_�@�������F�X��A�ӳ]�m�o����
	case 1: fen += 100;
		break;
	case 2: fen += 230;
		break;
	case 3: fen += 438;
		break;
	case 4: fen += 854;
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G����r�C
	gotoxy(40, 3);
	printf("�� �ơG %d", fen);
	for (j = 7; j < 11; j++) {
		if (1 == scope[j][4])
			gameover();
	}
}
//�H���X�{���
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
	switch (rand() % 4) { //�A�]�m�H�����઺��V
	case 0:
		break;
	case 1:
		for (i = 0; i < 4; i++) { //���ɰw90��
			for (j = 0; j < 4; j++) {
				block[j][3 - i] = tem[i][j];
			}
		}
		break;
	case 2:
		for (i = 0; i < 4; i++) { //��180��
			for (j = 0; j < 4; j++) {
				block[3 - i][3 - j] = tem[i][j];
			}
		}
		break;
	case 3:
		for (i = 0; i < 4; i++) { //��270��
			for (j = 0; j < 4; j++) {
				block[3 - j][i] = tem[i][j];
			}
		}
		break;
	}
//�C�L���ܰϪ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r�C
	for (i = 0; i < 4; i++) {
		gotoxy(44, 8 + i);
		for (j = 0; j < 4; j++) {
			if (1 == block[i][j]) {
				printf("��");
			} else {
				printf(" ");
			}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//�©��զr
}
//��ܤ��
void my_printblock() {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (point_x / 2 + j > 0) {
				if (1 == scope[point_x / 2 + j][point_y + i]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					gotoxy(point_x + j * 2, point_y + i);
					printf("��");
				} else if (1 == BLOCK[i][j]) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					gotoxy(point_x + j * 2, point_y + i);
					printf("��");
				}
			}
		}
	}
}
void gameover() {
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	// gotoxy(4, 10); printf(" ");
	// gotoxy(4, 11); printf(" ������ �� �� �������� �������� ");
	// gotoxy(4, 12); printf(" �� �� �� �� �� �� �� ");
	// gotoxy(4, 13); printf(" �� �� �� �� �������� �������� ");
	// gotoxy(4, 14); printf(" �� �� �� �� �� ���� ");
	// gotoxy(4, 15); printf(" ������ �� �������� �� �� ");
	// gotoxy(4, 16); printf(" ");
	gotoxy(32, 17); printf("�Ů���G����\tEsc�G�h�X");
	switch (_getch()) {
	case 32: system("cls");//�M��
		console();
		my_print();//��X����
		my_randout();
		memset(scope, 0, sizeof(int) * 25 * 34);//�ƲղM�s
		fen = 0;
		break;
	case 27: exit(0);
		break;
	}
}
