#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
void ducci(vector<int>& vec, vector<int>& vec1){
	for(int i = 0; i < vec.size(); i++){
		if(i == vec.size()-1) vec1.push_back(abs(vec[i] - vec[0]));
		else vec1.push_back(abs(vec[i] - vec[i+1]));
	}
}
bool IsEqual(const vector<int>& vec1, const vector<int>& vec2){
	if(vec1.size() != vec2.size()) {
	cout<<"Error!"<<endl;
	return false;
	}
	for(int i = 0; i < vec1.size(); i++){
		if(vec2[i] != vec1[i]) return false;
	}
	return true;
}
void eva(const vector<int>& vec, vector<int>& vec1){
	for(int i = 0; i < vec.size(); i++){
		vec1.push_back(vec[i]);
	}
}
int main(){
	vector<int> se;
	int num;
	while(cin>>num){
		if(num == -1) break;
		se.push_back(num);
	}
	//se.pop_back();
	vector<int> du;
	vector<int> zero;
	for(int i = 0; i < se.size(); i++){
		cout<<se[i]<<" ";
		zero.push_back(0);
		//cout<<zero[i]<<"\n";
	}
	cout<<"\n";
	/*ducci(se,du);
	for(int i = 0; i < du.size();i++){
		cout<<du[i]<<" ";
	}*/
	for(int i = 0; i < 1000; i++)
	{
		du.clear();
		ducci(se,du);
		for(int i = 0; i < du.size(); i++){
			cout<<du[i]<<" ";
		}
		cout<<"\n";
		if(IsEqual(du,se) || IsEqual(du,zero)) {
			cout<<"Yes!"<<endl;
			return 0;
			break;
		}
		se.clear();
		eva(du,se);
	}
	cout<<"No!"<<endl;
	return 0;
}
