#include <stdio.h>
#include <windows.h>
void startscreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r�C
	int ch;
	printf("-----------------------------------------------------------------------------------------\n");
	printf("-����������������������           ����������������                ��        ��    ��   - \n");
	printf("-        ��                                   ��              ����������  ������������ - \n");
	printf("-        ��                                 ��                 �� ����      ��    ��   - \n");
	printf("-        ��                               ��                  ��  �� ��     ��������   - \n");
	printf("-   ����������������          ��������������������������     ��   ��  ��    ��    ��   - \n");
	printf("-        ��       ��                      ��                      ��        ��������   - \n");
	printf("-        ��       ��                      ��                      ��        ��    ��   - \n");
	printf("-        ��       ��                      ��                      ��      ������������ - \n");
	printf("-        ��       ��                    ����                      ��         ��    ��  - \n");
	printf("- ����������������������                  ��                      ��       ��        ��- \n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("Press enter to start");
	ch = getchar();
	system("cls");
}