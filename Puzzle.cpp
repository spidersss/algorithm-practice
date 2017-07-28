#include<stdio.h>
#include<string.h>
#define maxn 5
int main(){
	char s[5][5];
	char c;
	int pos[2];
	
	for(int i = 0; i < 5; i++)
	for(int j = 0; j < 5; j++){
		if((c=getchar()) != '\n'){
			s[i][j] = c;
			if(c == ' ') {
			pos[0]=i;
			pos[1]=j;
		}
		}
		else break;
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++)
		printf("%c ", s[i][j]);
		printf("\n");
	}
	c = getchar();
	while((c=getchar()) != '0'){
		switch(c){
			case 'A': s[pos[0]][pos[1]]=s[pos[0]-1][pos[1]]; s[pos[0]-1][pos[1]] = ' '; pos[0]-=1;break;
			case 'B': s[pos[0]][pos[1]]=s[pos[0]+1][pos[1]]; s[pos[0]+1][pos[1]] = ' '; pos[0]+=1;break;
			case 'L': s[pos[0]][pos[1]]=s[pos[0]][pos[1]-1]; s[pos[0]][pos[1]-1] = ' '; pos[1]-=1;break;
			case 'R': s[pos[0]][pos[1]]=s[pos[0]][pos[1]+1]; s[pos[0]][pos[1]+1] = ' '; pos[1]+=1;break;
			default: printf("This puzzle has no final configuration."); break;
		}
	}
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++)
		printf("%c ", s[i][j]);
		printf("\n");
	}
	return 0;
}
