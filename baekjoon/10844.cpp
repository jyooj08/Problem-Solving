#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	long dp[10], temp[10];
	fill_n(dp, 10, 1); dp[0] = 0;
	
	for (int i = 1; i < n; i++) {
		temp[0] = dp[1];
		temp[9] = dp[8];
		for (int j = 1; j < 9; j++)
			temp[j] = (dp[j - 1] + dp[j + 1]) % 1000000000;
		copy(temp, temp + 10, dp);
	}

	long sum = 0;
	for (int i = 0; i < 10; i++) sum += dp[i];
	cout << sum % 1000000000;
	return 0;
}