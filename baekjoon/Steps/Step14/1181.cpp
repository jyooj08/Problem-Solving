#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compareString(string a, string b){
	if(a.length() != b.length()) return a.length() < b.length();
	
	return a < b;
}



int main()
{
	int n;
	cin >> n;
	
	
	string words[n];
	
	for(int i=0;i<n;i++) cin >> words[i];
	
	sort(words, words+n, compareString);
	
	cout << words[0] << '\n';
	for(int i=1;i<n;i++){
		if(words[i-1]!=words[i]) cout << words[i] << '\n';
	}
	
	return 0;
}
