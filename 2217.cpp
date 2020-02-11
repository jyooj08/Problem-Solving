#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int rope[n];
	for(int i=0;i<n;i++) cin >> rope[i];
	sort(rope, rope+n);
	
	int maxWeight=0, temp;
	for(int i=0;i<n;i++){
		maxWeight = max(maxWeight, rope[i]*(n-i));
	}
	cout << maxWeight;
	
	return 0;
}
