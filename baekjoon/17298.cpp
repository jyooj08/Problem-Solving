#include<iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	int* arr, *ocs;
	stack<int> s;
	
	cin >> n;
	arr = new int[n];
	ocs = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n - 1; i >= 0; i--) {
		int num = arr[i];
		while (!s.empty() && s.top() <= num) s.pop();
		
		if (s.empty()) ocs[i] = -1;
		else ocs[i] = s.top();
		s.push(num);
	}

	for (int i = 0; i < n; i++) cout << ocs[i] << ' ';

	return 0;
}