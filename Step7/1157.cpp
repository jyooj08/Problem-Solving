#include<iostream>
using namespace std;

int main()
{
	string str;
	int alphabet[26];
	for(int i=0;i<26;i++) alphabet[i]=0;
	
	cin>>str;
	int size = str.size();
	
	for(int i=0;i<size;i++){
		char c = toupper(str[i]);
		alphabet[c-65]++;
	}
	
	int maxidx = 0; bool same=false;
	for(int i=1;i<26;i++){
		if(alphabet[maxidx] < alphabet[i]){
			maxidx = i; same=false;
		} else if (alphabet[maxidx]==alphabet[i]) same=true;
	}
	
	if(same) cout <<"?";
	else cout << (char)(maxidx+65);
	return 0;
}
