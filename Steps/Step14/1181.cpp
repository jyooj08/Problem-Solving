#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compareString(string a, string b){
	if(a.length() != b.length()) return a.length() < b.length();
	
	int idx=-1, len = a.length();
	while(++idx < len-1){
		if(a[idx] != b[idx]) return a[idx] < b[idx];
	}
	return true;
}

void testing(){
	int idx=-1;
	while(true){
		cout << ++idx << endl;
		if(idx==10) return;
	}
}

int main()
{
	/*int n;
	cin >> n;
	
	
	string words[n];
	
	for(int i=0;i<n;i++) cin >> words[i];
	
	sort(words, words+n, compareString);
	cout << endl << words[0].length()<<endl;
	cout << words[0] << '\n';
	for(int i=1;i<n;i++){
		if(words[i-1]!=words[i]) cout << words[i] << '\n';
	}
	*/
	
	testing();
	return 0;
}
