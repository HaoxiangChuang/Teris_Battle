#include <stdio.h>
void blackwin(void) {

	FILE *file;
	char word[20] = "�´ѳ�";
	file = fopen("save.txt", "a+");
	fprintf(file, "%3s", word);
	printf("\n");
}
