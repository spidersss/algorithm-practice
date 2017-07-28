#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<int> ducci(vector<int>& vec){
	vector<int> vec1;
	for(int i = 0; i < vec.size(); i++){
		if(i == vec.size()-1) vec1.push_back(abs(vec[i] - vec[0]));
		vec1.push_back(abs(vec[i] - vec[i-1]));
	}
	return vec1;
}
int main(){
	vector<int> se;
	int num;
	while(cin>>num){
		if(num == -1) break;
		se.push_back(num);
	}
	se.pop_back();
	vector<int> du;
	du.clear();
	du = ducci(se);
	for(int i = 0; i < du.size(); i++){
		cout<<se[i]<<" ";
	}
	return 0;
}
