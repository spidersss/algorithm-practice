#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
queue<int> qu;
int works[10];
int time = 0;
int times = 0;
int flag = 0;
int order = 0;
void print(const int level){
	for(int i =0; i < qu.size(); i++){
		//cout<<"level"<<level<<endl;
		//cout<<"abs(qu.front())"<<abs(qu.front())<<endl;
		if(abs(qu.front())== level){
			if(qu.front() == flag){
				cout<<"time = "<<time+1<<endl;
			}
			if(times == order){
				cout<<"time = "<<time+1<<endl;
			}
			qu.pop();
			//cout<<"timeA "<<time<<" ";
			time++;//打印的时间； 
			times++;//次序转换的次数；
			break;
		}
		else{
			if(times == order){
				flag = -1*qu.front();
				//cout<<"qu.front"<<flag<<endl;
				qu.push(flag);
			}
			else qu.push(qu.front());
			qu.pop();
			//cout<<"timeB "<<time<<" ";
			times++;//次序转换的次数； 
		}
	}
}
int main(){
	memset(works, 0 ,sizeof(works));
	int x;
	while(cin>>x){
		if(x == 0) break;
		qu.push(x);
		works[0] ++;
		works[x] ++;
	}
	cin>>order;
	//cout<<order<<endl;
	/*for(int i = 0; i < 10; i++){
		cout<<works[i]<<" ";
	}*/
	for(int i = 9; i > 0; i--){
		if(works[i] == 0) continue;
		else{
			for(int j = works[i]; j > 0; j--){
				print(i);
			}
		}
	}
	return 0;
}
