#include<stdio.h>
#include<string.h>
#define maxn 17
int pos[maxn][maxn];
int bpos[maxn][maxn];
void r_next(){
	for(int i = 0; i < maxn; i++)
	for(int j = 0; j < maxn; j++){
		switch(pos[i][j]){
			case 1: pos[i][maxn - 1] = -1; pos[i][maxn - 2] = -1; pos[i][maxn - 3] = -1; break;
			case 2: for(int k = 0; k < maxn; k++){ if(k == j) || k == i) continue; pos[i][k] = -1;pos[k][j] = -1;} break;
		}
	}
}

void b_next(){
	pos[i][j] = -1;//其后位置置-1； 
} 

int check(){
	
}
int main(){
	memset(pos, 0, sizeof(pos));
	memset(bpos, 0, sizeof(bpos));
	char c, int pos_x = 0, int pos_y = 0;
	for(;;){
		scanf("%c %d %d", c, &pos_x, &pos_y);
		if(c == '0') break;
		switch(c){
			case 'G': pos[pos_x][pos_y] = 1; break;
			case 'R': pos[pos_x][pos_y] = 2; break;
			case 'H': pos[pos_x][pos_y] = 3; break;
			case 'C': pos[pos_x][pos_y] = 4; break;
			default: printf("Error!"); break;
		}
	}
	bpos[pos_x][pos_y] = 1; 
	r_next(); //红方下一步的可能位置
	b_next(); //黑方下一步的可能位置
	if(check()){//check判断bpos里的位置是否被pos全部覆盖 
		printf("Win!");
	} 
	else printf("Continue!");
	return 0;
}
