#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string> words, cowords;
int main(){
	string s;
	while(cin>>s){
		if(s[0]=='*') break;
		words.insert(s);
	}
	set<string>::iterator it;
	for(it = words.begin(); it!=words.end(); it++){
		for(set<string>::iterator it2=it; it2 != words.end(); it2++){
			string str = *it + *it2;
			if(words.find(str) != words.end()) cowords.insert(*(words.find(str)));
			str = *it2 + *it;
			if(words.find(str) != words.end()) cowords.insert(*(words.find(str)));
		}
	}
	for(it = cowords.begin();it!=cowords.end(); it++){
		cout<<*it<<" ";
	}
}
