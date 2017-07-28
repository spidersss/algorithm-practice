#include<stdio.h>
#include<string.h>
#define maxn 100
char s[maxn];
int main(){
	int c=0;
	int flag=0;
	float fzl=0;
	float sum=0;
	scanf("%s", s);
	for(int i = 0; i < strlen(s); i++){
		if(s[i]>=65 && s[i]<=90){
			switch (s[i]){
				case 'C': fzl = 12.01; break;
				case 'H': fzl = 1.008; break;
				case 'O': fzl = 16.00; break;
				case 'N': fzl = 14.01; break;
				default: fzl = 0;break;
			}	
		}
		else { continue;}
		
		if(s[i+1] != '\0' && (s[i+1]>=48 && s[i+1]<=57)){
		sum += fzl * float(int(s[i+1])-48);
	}
		else sum += fzl;
	}
	printf("Moler Mass = %.3f", sum);
	return 0;
}
