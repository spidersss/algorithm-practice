#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
vector<string> check;
vector<int> var;
int stree(vector<int> vari){
	return vari[0]&&(vari[1] || vari[2]);
}
int main(){
	string str;
	while(cin>>str){
		if(str[0] == '*') break;
		check.push_back(str);
	}
	for(int i = 0; i < check.size(); i++){
		var.clear();
		for(int j = 0; j < strlen(&(check[i][0])); j++){
			var.push_back(check[i][j]-'0');
		}
		cout<<stree(var);
	}
	cout<<endl;	
	return 0;
}
