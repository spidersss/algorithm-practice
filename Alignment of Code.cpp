#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<sstream>
#include<cstring>
using namespace std;
const int maxcol = 180;
const int maxl = 1000;
typedef struct lines{
	vector<string> Words;
};
vector<lines> Lines;
//Êä³ö×Ö·û´®s£¬³¤¶È²»×ãlen Ê±²¹×Ö·ûextra
void print(const string& s, int len, char extra) {
	cout << s;
	for(int i = 0; i < len-s.length(); i++)
	cout << extra;
}
int main() {
	lines Line;
	string line, buf;
	Lines.clear();
	while(getline(cin, line)) {
		Line.Words.clear();
		if(line == "") break;
		stringstream ss(line);
		while(ss>>buf){
			Line.Words.push_back(buf);
		}
		Lines.push_back(Line);
	} 
	
	/*for(int i = 0; i < Lines.size(); i++){
		for(int j = 0; j < Lines[i].Words.size(); j++){
			cout<<Lines[i].Words[j]<<"	";
		}
		cout<<"\n";
	}*/
	int maxcol = 0;
	for(int i = 0; i < Lines.size(); i++){
		if( maxcol < Lines[i].Words.size()) maxcol = Lines[i].Words.size();
	}
	vector<int> M;
	for(int i=0; i < maxcol; i++){
		M.push_back(0);
	}
	for(int i = 0; i < Lines.size(); i++){
		for(int j = 0; j < maxcol; j++){
			if(j >= Lines[i].Words.size()) break;
			if(M[j]<Lines[i].Words[j].length()) M[j] = Lines[i].Words[j].length();
			
		}
	}
	
	//	int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
	print("", 60, '-');
	cout << "\n";
	for(int r = 0; r < Lines.size(); r++) {
		for(int c = 0; c < Lines[r].Words.size(); c++) {
			print(Lines[r].Words[c], c == Lines[r].Words.size()-1 ? M[c] : M[c]+1, ' ');
		}	 
		cout << "\n";
	}
	return 0;
}
