#include<iostream>
#include<cstring>
#include<deque>

using namespace std;
deque<char> sentence;
void check(){ //检查式子是否合法； 
	deque<char>::iterator it;
	for(it = sentence.begin(); it != sentence.end(); it++){
		if(*it == '('){
			if((it+1) == sentence.end()) continue;
			if(*(it+1) == ')'){
				sentence.erase(it);
				it++;
				sentence.erase(it);
				check();
				break;
			}
			else continue;
		}
		else if(*it == '['){
			if((it+1) == sentence.end()) continue;
			if(*(it+1) == ']'){
				sentence.erase(it);
				it++;
				sentence.erase(it);
				check();
				break;
			}
			else continue;
		}
		else continue;
	}
	return ;
}
int main(){
	char c;
	while(cin>>c) {
		if(c == '#') break;
		sentence.push_back(c);
	}
	check();
	if(sentence.empty()) cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
	return 0;
}
