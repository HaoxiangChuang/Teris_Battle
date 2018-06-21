
void startscreen() 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//¶Â©³«G¶À¦r¡C
	srand((unsigned)time(NULL));
	

	
int ch;
printf("-----------------------------------------------------------------------------------------\n");
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
printf("-----------------------------------------------------------------------------------------\n");

printf("Press enter to start_");
ch=getchar();

system("CLS");
}
//printf("Press any botton to continue");

