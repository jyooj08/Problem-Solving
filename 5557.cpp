//5557
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, answer;
int arr[100];
long cnt = 0;
long sum[100][21] = { 0 };

//시간초과
void count_equation(int idx, int last_sum) {
	if (idx == n - 1) {
		if (last_sum == answer) cnt++;
		return;
	}

	int add = last_sum + arr[idx];
	int sub = last_sum - arr[idx];
	if (0 <= add && add <= 20) count_equation(idx + 1, add);
	if (0 <= sub && sub <= 20) count_equation(idx + 1, sub);
}

//메모리초과
void count_equation2() {
	vector<int>* v = new vector<int>[n];
	v[0].push_back(arr[0]);
	for (int i = 0; i < n - 2; i++) {
		int size = v[i].size();
		int add, sub;

		for (int j = 0; j < size; j++) {
			add = v[i][j] + arr[i + 1];
			sub = v[i][j] - arr[i + 1];
			if (0 <= add && add <= 20) v[i + 1].push_back(add);
			if (0 <= sub && sub <= 20) v[i + 1].push_back(sub);
		}
	}

	int size = v[n - 2].size();
	for (int i = 0; i < size; i++) {
		if (v[n - 2][i] == answer) {
			cnt++;
		}
	}
}

void count_equation3() {
	sum[0][arr[0]] = 1;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			if (sum[i][j] > 0) {
				long add = j + arr[i + 1];
				long sub = j - arr[i + 1];
				if (0 <= add && add <= 20) sum[i + 1][add] += sum[i][j];
				if (0 <= sub && sub <= 20) sum[i + 1][sub] += sum[i][j];
			}
		}
	}

	cnt = sum[n - 2][answer];

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	answer = arr[n - 1];
	

	//count_equation(1, arr[0]);
	//count_equation2();
	count_equation3();
	cout << cnt << endl;

	return 0;
}
