#include<stdio.h>
#include<string.h>
#define maxn 100

int main(){
	char s1[maxn], s2[maxn];
	char c;
	int i = 0;
	while((c=getchar()) != ' '){
		s1[i] = c;
		i++;
	}
	i = 0;
	while((c=getchar()) != '\n'){
		s2[i] = c;
		i++;
	}
	if(strlen(s1)<=strlen(s2)){
		int flag = 0;
		for(int i = 0; i < strlen(s2); i++){
			if(s1[0] == s2[i]){
				flag = 1;
				for(int j = 0; j < strlen(s1); j++){
					if(s1[j] != s2[i+j]){
						flag = 0;
						break;
					}
				}
			}
		}
		if(flag == 0) printf("No!");
		else if(flag == 1) printf("Yes!");
		else printf("Error!");
	}
	else printf("No!");
	return 0;
}
