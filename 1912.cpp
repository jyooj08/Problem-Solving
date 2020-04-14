#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int* arr, * dp;
	cin >> n;

	arr = new int[n];
	dp = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}

	cout << *max_element(dp, dp + n);
	return 0;
}