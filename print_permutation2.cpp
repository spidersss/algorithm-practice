#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100;
void print_permutation(int n,int* P, int* A, int cur){
	if(cur == n){
		for(int i =0 ; i < n; i++) printf("%d", A[i]);
		printf("\n");
	}
	else for(int i = 0; i <= n; i++)if(!i||P[i]!=P[i-1]){
		int c1 = 0, c2 = 0;
		for(int j = 0; j < cur; j++) if(A[j] == P[i]) c1++;
		for(int j = 0; j < n; j++) if(P[i] == P[j]) c2++;
		if(c1 < c2) {
			A[cur] = P[i];
			print_permutation(n, P, A, cur+1);
		}
	}
}

int main(){
	int A[maxn];
	memset(A, 0, sizeof(A));
	int n;
	cin>>n;
	int P[maxn];
	memset(P, 0, sizeof(P));
	for(int i = 0; i < n; i++) cin>>P[i];
	print_permutation(n, P,  A, 0);
	return 0;
}
