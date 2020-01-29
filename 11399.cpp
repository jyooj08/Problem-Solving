#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	int time[n];
	
	for(int i=0;i<n;i++) cin >> time[i];
	
	sort(time, time+n);
	
	int total=0, subtotal=0;
	for(int i=0;i<n;i++){
		subtotal += time[i];
		total += subtotal;
	}
	cout << total;
	return 0;
}
