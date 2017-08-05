#include<iostream>
#include<deque>
using namespace std;

deque<int> c;
int main(){
	int i;
	while(cin>>i){
		if(i == 0) break;
		c.push_back(i);
	}
	deque<int>::iterator it;
	it = c.begin();
	cout<<*(it+2)<<endl;
}
