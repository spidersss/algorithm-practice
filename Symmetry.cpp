#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
map<int, int> point;
vector<int> X;
int main(){
	int x,y;
	while(cin>>x>>y){
		if(point.count(x) != 0) break;
		point[x] = y;
		X.push_back(x);
		//cout<<x<<","<<point[x]<<endl;
	}
	long long sum = 0;
	for(int i = 0; i < X.size(); i++){
		sum += X[i];
	}
	double SymX = double(sum)/double(X.size());
	//cout<<SymX<<endl;
	int flag = 1;
	for(int i = 0; i < X.size(); i++){
		//cout<<round(2.0*SymX - double(X[i]))<<endl;
		if(point[X[i]] != point[round(2.0*SymX - double(X[i]))]){
			flag = 0;
			break;
		}
	}
	if(flag) cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
	return 0;
}
