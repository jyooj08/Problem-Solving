#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char word[100];
	int alphabet[26];
	for(int i=0;i<26;i++) alphabet[i]=-1;
	cin >> word;
	int len = strlen(word);
	
	for(int i=0;i<len;i++){
		int idx = word[i]-97;
		if(alphabet[idx]==-1) alphabet[idx] = i;
	}
	
	for(int i=0;i<26;i++) cout << alphabet[i] << ' ';
	return 0;
}
