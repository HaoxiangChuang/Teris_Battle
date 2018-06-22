#include <stdio.h>
void blackwin(void) {

	FILE *file;
	char word[10] = "¶Â´Ñ³Ó";
	file = fopen("save.txt", "a+");
	fprintf(file, "%10s", word);
	printf("\n");
}
