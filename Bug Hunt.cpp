#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void split(const string& src, const string& separator, vector<string>& dest)
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
}


int main()
{
    string src;
    vector<string> d;
    vector<string>::iterator p;
    while(cin>>src){
    	if(src == "end") break;
    	split(src,"=",d);
    	if(d.size() != 1){
    		cout<<d.back()<<endl;
    	}
    	//split(d.back(),"]",d);
    	/*for(p=d.begin();p!=d.end();++p){
        cout << *p <<"  "<< endl;
    	}*/
	}
    
    
    
    

    return 0;
}
