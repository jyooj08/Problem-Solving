#include<iostream>
using namespace std;

int main()
{
	string str;
	int testcase, count=0;
	bool alphabet[26];
	for(int i=0;i<26;i++) alphabet[i]=false;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		cin >> str;
		if(str.length()==1) {
			count++;
			continue;
		}
		
		bool groupWord=true;
		for(int i=0;i<26;i++) alphabet[i]=false;
		
		for(int j=0;j<str.length();j++){
			if(alphabet[str[j]-97]==false) alphabet[str[j]-97]=true;
			else if(str[j]!=str[j-1]){
				groupWord=false; 
				break;
			}
		}
		if(groupWord) {
			count++;
		}
	}
	
	cout << count;
	return 0;
}
