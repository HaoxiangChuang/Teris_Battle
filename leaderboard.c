typedef leaderboard{
	char name[20];
	int score;
}Leaderboard;

void rank(void){
	
	FILE *file;
	char name[20];
	int score;
	int size=0;
	
	file=fopen("save.txt","r");
	
	while(!feof(file)){
		fscanf(file,"%s%d",name,&score);
		size++;
		
	rewind(file);
	Leaderboard player[size];
	for(int i=0;i<size;i++)
		fscanf(file,"%s%d",player.name,&player.score);
	}
	
	int hold;
	char temp[30];
	
	for(int i=0;i<size;i++){
		if(player[size+1].score<player[size].score){
			hold=player[size].score;
			player[size].score=player[size+1].score;
			player[size+1].score=hold;
			
			temp=player[size].name;
			player[size].name=player[size+1].name;
			player[size+1].name=temp;
		}
	}
	
	printf("¡@ ¡@      ¹CÀ¸±Æ¦æº]\n");
	printf("¡@ **************************\n¡@ RANK    NAME        SCORE\n");
	for(i=0;i<size;i++)
	{
		printf("¡@ %d.      %-15s%2d\n",i+1,player[i].name,player[i].score);
	}
	printf("¡@ **************************\n");
	
	fclose(file);
	
	
	
	
}
