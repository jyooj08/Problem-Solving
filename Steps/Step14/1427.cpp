#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 

bool desc(int a, int b){
	return a>b;
}

int main()
{
	string str;
	cin >> str;
	
	int len = str.length();
	int arr[len];
	
	for(int i=0;i<len;i++) arr[i] = str[i]-48;
	
	sort(arr, arr+len, desc);
	
	for(int i=0;i<len;i++) cout << arr[i];
	return 0;
}
