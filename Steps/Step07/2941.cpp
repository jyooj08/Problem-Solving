#include<iostream>
using namespace std;

int main()
{
	string str;
	int count=0;
	cin >> str;
	
	for(int i=0;i<str.length();i++){
		if(str[i]=='=') {
			if(str[i-2]!=NULL && str[i-1]=='z' && str[i-2]=='d') count--;
			count--;
		}
		else if (str[i]=='-') count--;
		else if (str[i]=='j' && str[i-1]=='l') count--;
		else if (str[i]=='j' && str[i-1]=='n') count --;
		
		count ++;
	}
	cout << count;
	return 0;
}
