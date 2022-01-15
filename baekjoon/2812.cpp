#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, k, top = -1;
	string num;
	char s[500001];
    // stack<int> s 쓰면 시간초과

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

    /*
    출력 이런 식으로 해도 시간초과
    while (!s.empty()) {
		answer = s.top() + answer;
		s.pop();
	}
	cout << answer;
    */
	return 0;
}