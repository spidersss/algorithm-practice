#include<stdio.h>
#include<string.h>
#define maxn 20
int main(){
	char c;
	int count[maxn];
	memset(count, 0, sizeof(count));
	while((c=getchar()) != '\n'){
		count[int(c)-48]++;
	}
	for( int i = 0; i < 10; i++)
	printf("%d : %d\n",i,count[i]);
	return 0;
}
