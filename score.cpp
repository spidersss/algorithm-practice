#include<stdio.h>
#include<string.h>

int main(){
	int c=0;
	int flag=0;
	int sum=0;
	while((c=getchar())!='\n'){
		if(c == 'o' )flag = 0;
		else if(c == 'x') flag+=1;
		else printf("Error!");
		sum += flag; 
		}
	printf("score = %d", sum);
	return 0;
}
