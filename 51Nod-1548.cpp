#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int C, Hr, Hb, Wr, Wb;
	cin>>C>>Hr>>Hb>>Wr>>Wb;
	int maxH = 0;
	int end = sqrt(C) + 1;
	for(int i = 0; i < end; i++){
		if(i*Wr<= C) maxH = max(i*Hr + (C - i*Wr)/Wb*Hb, maxH);
		if(i*Wb<= C) maxH = max(i*Hb + (C - i*Wb)/Wr*Hr, maxH);
	}
	cout<<maxH<<endl;
	return 0;
}
