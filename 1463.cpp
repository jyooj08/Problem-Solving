#include<iostream>
#include<climits>
using namespace std;

int main()
{
	
	int n;
	cin >> n;
	
	int arr[n+1];
	fill_n(arr, n+1, INT_MAX);
	
	arr[1]=0;
	for(int i=1;i<=n;i++){
		if(3*i <= n) arr[3*i] = min(arr[3*i], arr[i]+1);
		if(2*i <= n) arr[2*i] = min(arr[2*i], arr[i]+1);
		if(i+1 <= n) arr[i+1] = min(arr[i+1], arr[i]+1);
	}
	
	cout << arr[n];
	
	return 0;
}
