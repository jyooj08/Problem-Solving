#include<iostream>
#include<vector>
using namespace std;

void search(vector<int> v, int n, int m, int k){
	if(v.size()==0 || k >= v.back()) v.push_back(k);
	else return;
	
	if(v.size()==m){
		for(int i=0;i<m;i++) cout << v[i] << ' '; cout << '\n';
		return;
	}
	
	for(int i=1;i<=n;i++){
		search(v,n,m,i);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<int> v;

	for(int i=1;i<=n;i++) {
		search(v, n, m, i);	
	}
	
	return 0;
}
