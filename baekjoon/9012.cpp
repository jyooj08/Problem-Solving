#include<iostream>
#include <stack>
using namespace std;

int main() {
	string ps, result;
	int n;

	cin >> n;
	while (n--) {
		stack<int> s;
		cin >> ps;
		result = "YES";
		for (int i = 0; i < ps.size(); i++) {
			if (ps[i] == '(') s.push(0);
			else if (ps[i] == ')') {
				if (!s.empty()) s.pop();
				else {
					result = "NO"; break;
				}
			}
		}
		if (!s.empty()) result = "NO";

		cout << result << endl;
	}

	return 0;
}