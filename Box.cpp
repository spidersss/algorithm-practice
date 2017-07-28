#include<stdio.h>
#include<string.h>
#define maxn 12

int main(){
	int arr[maxn];
	for(int i = 0; i < maxn; i++){
		int a;
		scanf("%d",&a);
		arr[i] = a;
	}
	int test[maxn];
	memset(test, 0 , sizeof(test));
	for(int i = 0; i < maxn; i++){
		int mark = 0;
		for(int j = 0; j < maxn; j++){
			if(arr[i]==test[j]){
				test[j]++;
				mark = 1;
				break;
			}
		}
		if(mark == 0){
			for(int j = 0; j < maxn; j++){
				if(test[j] == 0) {
				test[j] = arr[i];
				break;
				}
			}
		}
	}
	for(int i = 0; i < maxn; i++){
		printf("%d\n", test[i]);
	}
	int judge = 1;
	for(int i = 0; i < 3; i++){
		if(test[i] != 4) {
		judge = 0;
		break;
		}
	}
	if(judge == 1) printf("Yes!");
	else printf("No!");
	return 0;
}
