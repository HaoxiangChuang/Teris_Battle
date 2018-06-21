#include<stdio.h>
#include<stdlib.h>
typedef struct leaderboard {
	char name1[20];
	char name2[20];
} Leaderboard;

void rank(void) {

	FILE *file;
	char NAME1[20];
	char NAME2[20];
	int size = 0;

	file = fopen("save.txt", "r");

	while (!feof(file)) {
		fscanf(file, "%s%s", NAME1, NAME2);
		size++;
	}
	rewind(file);
	Leaderboard player[size];
	for (int i = 0; i < size; i++) {
		fscanf(file, "%s%s", player->name1, player->name2);
	}


	printf("　 　      遊戲戰績\n");
	printf("　 **************************\n");
	for (int j = 0; j < size; j++) {
		printf("　 第%d場      %-15s%2s\n", j + 1, player[j].name1, player[j].name2);
	}
	printf("　 **************************\n");

	fclose(file);
}
