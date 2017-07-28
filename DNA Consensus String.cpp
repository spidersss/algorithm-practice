#include<stdio.h>
#include<string.h>
#define maxm 50
#define maxn 1000
int main(){
	char s[maxm][maxn];
	int m,n;
	scanf("%d%d",&m,&n);
	int j = 0;
	char c;
	c=getchar();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n+1; j++){
			c = getchar();
			if(c != '\n') s[i][j] = c;
			else break;
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++)
		printf("%c ", s[i][j]);
		printf("\n");
	}
	int C[4][1];
	int Hamming = 0;
	for(int j=0; j < n; j++){
		for(int i = 0; i < 4; i++){
			C[i][0] = 0;
		}
		for(int i=0; i < m; i++){
			switch(s[i][j]){
				case 'A': C[0][0]++; break;
				case 'C': C[1][0]++; break;
				case 'G': C[2][0]++; break;
				case 'T': C[3][0]++; break;
				default: printf("Error!"); break;
			}
		}
		int num=0, flag = 0;
		for(int i=0; i<4; i++){
			if(C[i][0]>=num){
				num = C[i][0];
				flag = i;
			}
		}
		Hamming += (m - num);
		switch(flag){
			case 0: printf("A"); break;
			case 1: printf("C"); break;
			case 2: printf("G"); break;
			case 3: printf("T"); break;
			default: printf("Creation Error!"); break;
		}
		
	}
	printf("\n%d\n",Hamming);
	return 0;
}
