#include <stdio.h>
void save(void) {

	FILE *file;
	char name1[10];
	char name2[10];

	file = fopen("save.txt", "r+");
	printf("�п�J���a1���W�r");
	scanf("%s", &name1);
	printf("�п�J���a2���W�r");
	scanf("%s", &name2);
	fprintf(file, "%10s%10s", name1, name2);
	printf("\n");
	fclose(file);
}
