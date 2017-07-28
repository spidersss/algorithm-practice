#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
struct Text{
	int lines;
	vector<string> words;
	Text(){
		lines = 0;
	}
};
vector<Text> texts;
Not(const string& str){
	cout<<"Not "<<str<<endl;
}
And(const string& str1, const string& str2){
	cout<<str1<<" And "<<str2<<endl;
}
Or(const string& str1, const string& str2){
	cout<<str1<<" Or "<<str2<<endl;
}
int main(){
	string s, str;
	Text text;
	int n;
	cin>>n;
	int i = 0;
	getchar();
	while(getline(cin,s)){
		text.words.push_back(s);
		text.lines++;
		//cout<<text.words.back()<<endl;
		/*ss<<s;
		while(ss>>str){
			cout<<"The "<<i<<" "<<str<<endl;
		}*/
		if(s == "") {
			//cout<<"blank"<<endl;
			texts.push_back(text);
			i++;
			text.words.clear();
			text.lines = 0;
		}
		if(i >= n )break;	
	}
	//cout<<texts[1].words[0]<<endl;
	string str1, str2, str3;
	while(cin>>str1){
		if(str1 == "END") break;
		if(str1 == "NOT"){
			cin>>str2;
			Not(str2);
		}
		else{
			cin>>str2;
			cin>>str3;
			if(str2 == "AND"){
				And(str1, str3);
			}
			else if(str2 == "OR"){
				Or(str1, str3);
			}
		}
	}
	return 0;
}
