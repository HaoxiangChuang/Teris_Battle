#include <stdio.h>
void save(void) {

	FILE *file;
	char name1[20];
	char name2[20];

	file = fopen("save.txt", "r+");
	printf("�п�J���a1���W�r");
	scanf("%s", &name1);
	printf("�п�J���a2���W�r");
	scanf("%s", &name2);
	fprintf(file, "%-8s%s", name1, name2);
	printf("\n");
	fclose(file);
}
