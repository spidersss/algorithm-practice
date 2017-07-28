#include<stdio.h>
#include<string.h>
#define maxn 100
int repeat(int *s, int n)
{
	int flag = 0;
	int k = 0;
	for(int i = 2; i < n; i++){
		for(int j = 0; (i + j) < n; j++){
			if(s[j] != s[i+j]){
				flag = 0;
				break;
			}
			else flag = 1;
		}
		if(flag == 1){
			k = i;
			break;
		}
	}
	return k;
}
int main(){
	int a=0, b=0, c=0;
	scanf("%d%d", &a, &b);
	int s[maxn];
	printf("%d.", int(a/b));
	a *= 10;
	for(int i = 0; i < maxn; i++){
		c = a/b;
		s[i] = c;
		a = (a % b) * 10;
		
	}
	int d = repeat(s,maxn);
	for(int i = 0; i < d; i++) printf("%d", s[i]);
	printf("\n");
	printf("%d",repeat(s, maxn));
	return 0;
}
