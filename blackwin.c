#include <stdio.h>
void blackwin(void){
	
	FILE *file;
	char word[20];
	
	file=fopen("save.txt","a");
	word="�´� ��!"
	fprintf(file,"%6s\n",word);
	printf("\n");
}
