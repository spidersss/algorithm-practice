#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Book{
	string author;
	string bookname;
	int BORROW;
	int RETURN;
	int SHELVE;
	/*Book(string au = NULL, string bo = NULL, int BO = 0, int RE = 0, int SH = 0):
	author(au), bookname(bo), BORROW(BO), RETURN(RE), SHELVE(SH){
	}*/
	Book(){
		BORROW = 0;
		RETURN = 0;
		SHELVE = 0;
	}
};
bool comp(const Book& b1, const Book& b2){
	if(b1.author > b2.author) return false;
	else if(b1.author < b2.author) return true;
	else{
		if(b1.bookname > b2.bookname) return false;
		else return true;
	}
}
vector<Book> lib;
Book* find(const string name){//返回书的地址； 
	for(int i = 0; i < lib.size(); i++){
		if(lib[i].bookname == name) return &lib[i];
	}
}
void bor(Book* it){
	it->BORROW = 1;
}
void ret(Book* it){
	if(it->BORROW == 0) cout<<"This book hasn't been borrowed!";
	else{
		it->BORROW = 0;
		it->RETURN = 1;
	}
}
void she(){
	for(int i = 0; i < lib.size(); i++){
		if(lib[i].RETURN == 1){
			lib[i].RETURN = 0;
			if(i == 0) cout<<"The first book."<<endl;
			else cout<<"SHELVE "<<lib[i].bookname<<"After "<<lib[i-1].bookname<<"."<<endl;
		}
	}
}
int main(){
	string bookname;
	string author;
	Book book;
	while(cin>>bookname){
		if(bookname == "END") break;
		cin>>author;
		book.bookname = bookname;
		book.author = author;
		lib.push_back(book);
	}
	/*for(int i = 0; i < lib.size(); i++){
		cout<<i+1<<" author: "<<lib[i].author<<" bookname: "<<lib[i].bookname<<endl;
	}*/
	sort(lib.begin(),lib.end(),comp);
	for(int i = 0; i < lib.size(); i++){
		cout<<i+1<<" author: "<<lib[i].author<<" bookname: "<<lib[i].bookname<<endl;
	}
	string order;
	string name;
	while(cin>>order){
		if(order == "END") break;
		else if(order == "BORROW") {
			cin>>name; 
			bor(find(name));
		}
		else if(order == "RETURN") {
			cin>>name;
			ret(find(name));
		}
		else if(order == "SHELVE") {
			she();
		}
		else cout<<"Wrong Order!"<<endl;
	}
	return 0;
}
