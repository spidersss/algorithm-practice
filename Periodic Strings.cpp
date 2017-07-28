#include<stdio.h>
#include<string.h>
#define maxn 100

int main(){
	char s[maxn];
	int flag = 0;
	int k = 0;
	scanf("%s", s);
	for(int i = 2; i < strlen(s); i++){
		for(int j = 0; (i + j) < strlen(s); j++){
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
	printf("Period = %d", k);
	return 0;
}
