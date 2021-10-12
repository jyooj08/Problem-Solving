#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int arr[n][n];
	for(int i=0;i<n;i++){
		fill(arr[i], arr[i]+n, 0);
		for(int j=0;j<=i;j++) cin >> arr[i][j];
	}
	
	int sum[n][n]; sum[0][0]=arr[0][0];

	
	// i: level
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j==0) sum[i][j] = sum[i-1][j]+arr[i][j];
			else if(j==i) sum[i][j] = sum[i-1][j-1]+arr[i][j];
			else{
				sum[i][j] = max(sum[i-1][j], sum[i-1][j-1]) + arr[i][j];
			}
		}
	}
	
	int maxValue=0;
	for(int i=0;i<n;i++) maxValue = max(maxValue, sum[n-1][i]);
	cout << maxValue;
	
	return 0;
}
