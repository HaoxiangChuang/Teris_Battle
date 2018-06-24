#include<stdio.h>
#include<stdlib.h>
typedef struct leaderboard {
	char name1[10];
	char name2[10];
	char win[10];
} Leaderboard;

void leaderboard(void) {

	FILE *file;
	char NAME1[10];
	char NAME2[10];
	char WIN[10];
	int size = 0;

	file = fopen("save.txt", "a+");

	while (!feof(file)) {
		fscanf(file, "%s %s %s", NAME1, NAME2, WIN);
		size++;
	}
	rewind(file);
	Leaderboard player[size];
	for (int i = 0; i < size; i++) {
		fscanf(file, "%s%s%s", player[i].name1, player[i].name2, player[i].win);
	}


	printf("\n\n                                    遊戲戰績\n\n\n");
	printf("                                   黑棋            白棋\n");
	for (int j = 0; j < size; j++) {
		printf("　                    第 % d場      % -15s % 2s % 2s\n", j + 1, player[j].name1, player[j].name2, player[j].win);
	}

	fclose(file);
	system("pause");
}
