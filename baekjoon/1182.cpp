#include<iostream>
using namespace std;

int n, s;
int cnt = 0;
int* arr;

void partialSum(int i, int current_sum) {
	if (i == n) return;

	if (current_sum + arr[i] == s) cnt++;
	partialSum(i + 1, current_sum + arr[i]);
	partialSum(i + 1, current_sum);
}

int main()
{
	cin >> n >> s;

	arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	partialSum(0, 0);

	cout << cnt;

	return 0;
}
