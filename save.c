#include <stdio.h>
void save(void) {

	FILE *file;
	char name1[10];
	char name2[10];

	file = fopen("save.txt", "r+");
	printf("請輸入玩家1的名字");
	scanf("%s", &name1);
	printf("請輸入玩家2的名字");
	scanf("%s", &name2);
	fprintf(file, "%10s%10s", name1, name2);
	printf("\n");
	fclose(file);
}
