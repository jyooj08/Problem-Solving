#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int num[10]={0,};
	for(int i=0;i<s.size();i++){
		num[s[i]-'0']++;
	}
	
	num[6] = ceil((double)(num[6]+num[9])/2);
	int max=0;
	for(int i=0;i<9;i++) if(max < num[i]) max = num[i];
	cout << max;
	return 0;
}
