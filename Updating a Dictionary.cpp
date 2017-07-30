#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

/*void split(const string& src, const string& separator, vector<string>& dest)
{
    string str = src;
    string substring;
    string::size_type start = 0, index;

    do
    {
        index = str.find_first_of(separator,start);
        if (index != string::npos)
        {    
            substring = str.substr(start,index-start);
            dest.push_back(substring);
            start = str.find_first_not_of(separator,index);
            if (start == string::npos) return;
        }
    }while(index != string::npos);
    
    //the last token
    substring = str.substr(start);
    dest.push_back(substring);
}*/
set<string> change;
map<string, int> dict1;
map<string, int> dict2;
void Change(const char c){
	change.clear();
	map<string, int>::iterator it1, it2;
	int flag = 1;
	switch(c){
		case '+':
			for(it2 = dict2.begin(); it2 != dict2.end(); it2++){
			flag = 1;
			for(it1 = dict1.begin(); it1 != dict1.end(); it1 ++){
				if(it1->first == it2->first){
					flag = 0;
				}
			}
			if(flag == 1 ){
				change.insert(it2->first);
				}
			}
			break;
		case '-': 
			for(it1 = dict1.begin(); it1 != dict1.end(); it1++){
				flag = 1;
				for(it2 = dict2.begin(); it2 != dict2.end(); it2++ ){
				if(it1->first == it2->first){
					flag = 0;
					}
				}
				if(flag == 1 ){
					change.insert(it1->first);
				}
		
			}
			break;
		case '*':
			for(it2 = dict2.begin(); it2 != dict2.end(); it2++){
			for(it1 = dict1.begin(); it1 != dict1.end(); it1 ++){
				if(it1->first == it2->first){
					if(it2->second != it1->second) change.insert(it1->first);
				}
			}
			break;
		default:{
			cout<<"Error!"<<endl;
			break;
			}
		}
	}
}
int main(){
	char k;
	int v;
	string s;
	int i = 0;
	while(i < 2){
		v = 0;
		s.clear();
		while(cin>>k){
			if(k == '{' ) continue;
			if(k == ',')  {
				s.clear();
				continue;
			}
			if(k == '}') break;
			if(k == ':'){
				cin>>v;
				if(i == 0){
					dict1[s] = v;
				}
				else{
					dict2[s] = v;
				}
			}
			else{
				s.append(&k,1);
			}
		}
		i++;
	}
	
	/*for(it = dict1.begin(); it != dict1.end(); it++){
		cout<<it->first<<":"<<it->second<<endl;
	}
	for(it = dict2.begin(); it != dict2.end(); it++){
		cout<<it->first<<":"<<it->second<<endl;
	}*/
	int flag = 0;
	set<string>::iterator it;
	Change('+');
	if(change.size() != 0){
		flag = 1;
		cout<<"+";
		for(it = change.begin(); ; ){
			cout<<*it;
			it++;
			if(it == change.end()) {
			cout<<endl;
			break;
			}	
			else cout<<",";
		}
	}
	Change('-');
	if(change.size() != 0){
		flag = 1;
		cout<<"-";
		for(it = change.begin(); ; ){
			cout<<*it;
			it++;
			if(it == change.end()) {
			cout<<endl;
			break;
			}	
			else cout<<",";
		}
	}
	Change('*');
	if(change.size() != 0){
		flag = 1;
		cout<<"*";
		for(it = change.begin(); ; ){
			cout<<*it;
			it++;
			if(it == change.end()) {
			cout<<endl;
			break;
			}	
			else cout<<",";
		}
	}
	if(flag == 0) cout<<"No changes!"<<endl;
	
	return 0;
}
