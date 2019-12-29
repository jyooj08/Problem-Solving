#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	string str1 , str2;
	string revStr1="", revStr2=""; // reverse string
	int n1, n2;
	cin >> str1 >> str2;
	
	for(int i=str1.length()-1;i>=0;i--){
		revStr1 += str1[i];
	}
	for(int i=str2.length()-1;i>=0;i--){
		revStr2 += str2[i];
	}
	
	n1 = atoi(revStr1.c_str());
	n2 = atoi(revStr2.c_str());
	
	if(n1 > n2) cout << n1;
	else cout << n2;
	return 0;
}
