#include <stdio.h>
#include <windows.h>
void gotoxy(int xpos, int ypos);
void startscreen() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//¶Â©³«G¶À¦r¡C
	int ch;
	printf("----------------------------------------------------------------------------------------\n");
	printf("-¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½           ¡½¡½¡½¡½¡½¡½¡½¡½                ¡½        ¡½    ¡½   - \n");
	printf("-        ¡½                                   ¡½              ¡½¡½¡½¡½¡½  ¡½¡½¡½¡½¡½¡½ - \n");
	printf("-        ¡½                                 ¡½                 ¡½ ¡½¡½      ¡½    ¡½   - \n");
	printf("-        ¡½                               ¡½                  ¡½  ¡½ ¡½     ¡½¡½¡½¡½   - \n");
	printf("-   ¡½¡½¡½¡½¡½¡½¡½¡½          ¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½     ¡½   ¡½  ¡½    ¡½    ¡½   - \n");
	printf("-        ¡½       ¡½                      ¡½                      ¡½        ¡½¡½¡½¡½   - \n");
	printf("-        ¡½       ¡½                      ¡½                      ¡½        ¡½    ¡½   - \n");
	printf("-        ¡½       ¡½                      ¡½                      ¡½      ¡½¡½¡½¡½¡½¡½ - \n");
	printf("-        ¡½       ¡½                    ¡½¡½                      ¡½         ¡½    ¡½  - \n");
	printf("- ¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½¡½                  ¡½                      ¡½       ¡½        ¡½- \n");
	printf("----------------------------------------------------------------------------------------\n");
	gotoxy(35, 12);
	printf("«öEnterÁä¶}©l");
	ch = getchar();
}

