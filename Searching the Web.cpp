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
int Find(const string& str, int n){
	for(int i = 0; i < texts[n].words.size(); i++){
		stringstream s1;
		s1.clear();
		string s2;
		s2.clear();
		s1 << texts[n].words[i];
		while(s1 >> s2){
			if(s2 == str) return i;
		}
	}
	return -1;
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
			cout<<"第"<<i<<"篇" <<endl;
			text.words.clear();
			text.lines = 0;
		}
		if(i >= n ){
			cout<<"Finished!"<<endl;
			break;	
		}
	}
	//getchar();
	//cout<<texts[1].words[0]<<endl;
	string STR, str1, str2, str3;
	while(getline(cin, STR)){
		stringstream ss;
		ss.clear();
		ss << STR;
		if(STR.find("END") != string::npos) break;
		if(STR.find("NOT") != string::npos){
			ss>>str1;
			ss>>str2;
			for(int i = 0; i < texts.size(); i++){
				if(Find(str2, i) < 0){
					for(int j = 0; j < texts[i].words.size(); j++){
						cout<<texts[i].words[j]<<endl;
					}
				}
			}
			
		}
		else if(STR.find("AND") != string::npos) {
			ss>>str1>>str2>>str3;
			for(int i = 0; i < texts.size(); i++){
				if(Find(str1, i) >= 0 && Find(str3, i) >= 0){
				cout<<"第"<<i+1<<"篇，" <<"第" <<Find(str1,i)+1<<"行："<<texts[i].words[Find(str1,i)]<<endl;
				cout<<"第"<<i+1<<"篇，" <<"第" <<Find(str3,i)+1<<"行："<<texts[i].words[Find(str3,i)]<<endl;
				}
			}
		}	
		else if(STR.find("OR") != string::npos){
			ss>>str1>>str2>>str3;
			for(int i = 0; i < texts.size(); i++){
				if(Find(str1, i) >= 0 || Find(str3, i) >= 0){
				if(Find(str1, i) >= 0){
				cout<<"第"<<i+1<<"篇，" <<"第" <<Find(str1,i)+1<<"行："<<texts[i].words[Find(str1,i)]<<endl;
				}
				if(Find(str3, i) >= 0){cout<<"第"<<i+1<<"篇，"<<"第" <<Find(str3,i)+1<<"行："<<texts[i].words[Find(str3,i)]<<endl;
				}
				}
			}
		}
		else {
			ss>>str1;
			for(int i = 0; i < texts.size(); i++){
				if(Find(str1, i) >= 0) cout<<"第"<<i+1<<"篇，" <<"第" <<Find(str1,i)+1<<"行："<<texts[i].words[Find(str1,i)]<<endl;
			}
		}
		STR.clear();
		str1.clear();
		str2.clear();
		str3.clear();
		
	}
	return 0;
}
