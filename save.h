void save(int score){
	
	FILE *file;
	char name[20];

	file=fopen("save.txt","a");
	printf("�п�J�A���W�r");
	scanf("%s",&name);
	fprintf(file,"%-8s%d\n",name,score);
	printf("\n");
}
