
void startscreen() 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);//�©��G���r�C
	srand((unsigned)time(NULL));
	

	
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

printf("Press enter to start_");
ch=getchar();

system("CLS");
}
//printf("Press any botton to continue");

