void save(int score){
	
	FILE *file;
	char name[20];

	file=fopen("save.txt","a");
	printf("請輸入你的名字");
	scanf("%s",&name);
	fprintf(file,"%-8s%d\n",name,score);
	printf("\n");
}
