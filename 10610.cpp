#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> num;
	string n_str;
	int len;
	
	cin >> n_str;
	len = n_str.length();
	for(int i=0;i<len;i++){
		num.push_back(n_str[i]-'0');
	}
	
	
	// 3으로 나뉘지 않음 
	int sum=0;
	for(int i=0;i<len;i++) sum += num[i];
	if(sum % 3 != 0){
		cout << -1;
		return 0;
	}
	
	//10으로 나뉘지 않음
	bool contains0=false;
	for(int i=0;i<len;i++){
		if(num[i]==0) {
			contains0=true;
			break;
		}
	}
	if(!contains0){
		cout << -1;
		return 0;
	} 
	
	sort(num.begin(), num.end());
	for(int i=len-1;i>=0;i--) cout << num[i];
	return 0;
}
