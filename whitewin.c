#include <stdio.h>
void whitewin(void){
	
	FILE *file;
	char word[20];
	
	file=fopen("save.txt","a");
	word="�մ� ��!"
	fprintf(file,"%6s\n",word);
	printf("\n");
}
