#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	vector<int> fib;

	cin >> n;
	fib.push_back(0);
	fib.push_back(1);

	for (int i = 2; i <= n; i++) {
		int num = fib[i - 1] + fib[i - 2];
		fib.push_back(num);
	}
	cout << fib[n] << endl;
	

	return 0;
}