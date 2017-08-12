#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

void print_subset(int n, int s, int* arr){
	for(int i = 0; i < n; i++)
		if(s&(1<<i)) printf("%d ", arr[i]);
	printf("\n");
}
int main(){
	vector<int> arr;
	int a;
	while(cin>>a){
		if(a == -1) break;
		arr.push_back(a);
	}
	for(int i = 0; i < (1<<(arr.size())) ; i++) print_subset(arr.size(), i, &arr[0]);
	
	
	return 0;
}
