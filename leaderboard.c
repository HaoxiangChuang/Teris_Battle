typedef struct leaderboard{
	char name1[20];
	char name2[20];
}Leaderboard;

void rank(void){
	
	FILE *file;
	char name1[20];
	char name2[20];
	int size=0;
	
	file=fopen("save.txt","r");
	
	while(!feof(file)){
		fscanf(file,"%s%s",name1,name2);
		size++;
		
	rewind(file);
	Leaderboard player[size];
	for(int i=0;i<size;i++)
		fscanf(file,"%s%s",player.name1,&player.name2);
	}
	
	
	printf("　 　      遊戲戰績\n");
	printf("　 **************************\n");
	for(i=0;i<size;i++)
	{
		printf("　 第%d.場      %-15s%2s\n",i+1,player[i].name1,player[i].name2);
	}
	printf("　 **************************\n");
	
	fclose(file);
	
	
	
	
}
