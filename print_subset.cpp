#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn = 100;
void print_subset(int n, int* A, int cur) {
	for(int i = 0; i < cur; i++) printf("%d ", A[i]); //打印当前集合
	printf("\n");
	int s = cur ? A[cur-1]+1 : 0; //确定当前元素的最小可能值	
	for(int i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n, A, cur+1); //递归构造子集
	}
}
int main(){
	int n;
	cin>>n;
	int A[maxn];
	memset(A, 0, sizeof(A));
	print_subset(n, A, 0);
	return 0;
}
