#include <stdio.h>
void save(void){
	
	FILE *file;
	char name1[20];
	char name2[20];

	file=fopen("save.txt","a");
	printf("請輸入玩家1的名字");
	scanf("%s",&name1);
	printf("請輸入玩家2的名字");
	scanf("%s",&name2);
	fprintf(file,"%-8s%s\n",name1,name2);
	printf("\n");
}
