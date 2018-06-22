#include <stdio.h>
void whitewin(void) {

	FILE *file;
	char word[10] = "¥Õ´Ñ³Ó";

	file = fopen("save.txt", "a+");
	fprintf(file, "%10s", word);
	printf("\n");
}
