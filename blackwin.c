#include <stdio.h>
void blackwin(void) {

	FILE *file;
	char word[20] = "¶Â´Ñ³Ó";
	file = fopen("save.txt", "a+");
	fprintf(file, "%3s", word);
	printf("\n");
}
