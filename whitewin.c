#include <stdio.h>
void whitewin(void) {

	FILE *file;
	char word[20] = "�մѳ�";

	file = fopen("save.txt", "a+");
	fprintf(file, "%3s", word);
	printf("\n");
}
