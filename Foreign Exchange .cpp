#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct school{
	int From;
	int To;
	school(int x = 0, int y = 0):From(x), To(y){
	}
};
set<school> student;
int main(){
	int A, B;
	school schools;
	student.clear();
	while(cin>>A>>B){
		if(A == -1) break;
		schools.From = A;
		schools.To = B;
		student.insert(schools);
		//cout<<schools.From<<" "<<schools.To<<endl;
	}
	if(student.size() % 2 != 0){
		cout<<"No!"<<endl;
		return 1;
	}
	int size = student.size();
	cout<<size<<endl;
	for(int i = 0; i <size; i++ ){
		set<school>::iterator it;
		for(it = student.begin(); it !=student.end(); it++){
			if((*student.begin()).From == (*it).To && (*it).To == (*student.begin()).To){
				student.erase(student.begin());
				student.erase(it);
				break;
			}	
		}
		if(student.empty()) cout<<"Yes!"<<endl;
		
	}
	cout<<"No!"<<endl;
	return 0;
}
