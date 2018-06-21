#include <stdio.h>
void blackwin(void){
	
	FILE *file;
	char word[20];
	
	file=fopen("save.txt","a");
	word="¶Â´Ñ ³Ó!"
	fprintf(file,"%6s\n",word);
	printf("\n");
}
