#include<stdio.h>
#include<string.h>

int main(){
	int a[4];
	int num = 0;
	scanf("%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
	for(int i = 0; i < 4; i++){
		printf("%d ", a[i]);
	}
	return 0;
	
}
