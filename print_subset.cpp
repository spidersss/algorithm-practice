#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn = 100;
int B[maxn];
void print_subset(int n, int* A, int cur) {
	for(int i = 0; i < cur; i++) printf("%d ", B[A[i]]); //��ӡ��ǰ����
	printf("\n");
	int s = cur ? A[cur-1]+1 : 0; //ȷ����ǰԪ�ص���С����ֵ	
	for(int i = s; i < n; i++) {
		A[cur] = i;
		print_subset(n, A, cur+1); //�ݹ鹹���Ӽ�
	}
}
int main(){
	int n;
	cin>>n;
	int A[maxn];
	for(int i = 0; i < n; i++){
		cin>>B[i];
	}
	memset(A, 0, sizeof(A));
	print_subset(n, A, 0);
	return 0;
}
