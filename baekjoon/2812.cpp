#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, k, top = -1;
	string num;
	char s[500001];

	cin >> n >> k >> num;

	int cur = 0;
	while (cur < n) {
		if (top == -1 || k == 0) {
			s[++top] = num[cur++];
		}
		else if (s[top] < num[cur]) {
			top--;
			k--;
		}
		else {
			s[++top] = num[cur++];
		}
	}

	for (int i = 0; i < k; i++) top--;
	for (int i = 0; i <= top; i++) cout << s[i];

	return 0;
}