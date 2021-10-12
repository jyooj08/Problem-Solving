#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	
	cin >> n;
	int list[n];
	for(int i=0;i<n;i++) cin >> list[i];
	
	cin >> m;
	int target[m];
	for(int i=0;i<m;i++) cin >> target[i];
	
	sort(list, list+n);
	
	for(int i=0;i<m;i++){
		cout << binary_search(list, list+n, target[i]) << '\n';
	}
	return 0;
}
