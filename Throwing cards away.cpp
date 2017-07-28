#include<iostream>
#include<queue>
#include<set>

using namespace std;
ostream& operator << (ostream& out, set<int>& s){
	set<int>::iterator it;
	for(it = s.begin(); it != s.end();it++){
		out<<*it<<" ";
	}
	return out;
}
int main(){
	int n;
	queue<int> card;
	set<int> cards;
	cin >> n;
	for(int i = 1; i <= n; i++)	{
		card.push(i);
		cards.insert(i);
	}
	cout<<cards<<endl;
	while(cards.size()>2){
		cards.erase(card.front());
		cout<<card.front()<<"	";
		card.pop();
		card.push(card.front());
		card.pop();
		cout<<cards<<endl;
	}
	return 0;
}
