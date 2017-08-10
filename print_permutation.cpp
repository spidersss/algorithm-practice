#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100;
void print_permutation(int n, int* A, int cur){
	if(cur == n){
		for(int i =0 ; i < n; i++) printf("%d", A[i]);
		printf("\n");
	}
	else for(int i = 1; i <= n; i++){
		int ok = 1;
		for(int j = 0; j < cur; j++)
			if(A[j] == i) ok = 0;
		if(ok){
			A[cur] = i;
			print_permutation(n, A, cur + 1);
		}
	}
}

int main(){
	int A[maxn];
	memset(A, 0, sizeof(A));
	int n;
	cin>>n;
	print_permutation(n, A, 0);
	return 0;
}
