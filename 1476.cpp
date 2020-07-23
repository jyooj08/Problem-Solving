#include<iostream>
using namespace std;

int main()
{
	int e=1, s=1, m=1;
	int E, S, M;
	int year = 1;
	cin >> E >> S >> M;

	while (1) {
		if (e == E && s == S && m == M) break;

		e++; s++; m++; year++;
		if (e > 15) e = 1;
		if (s > 28) s = 1;
		if (m > 19) m = 1;
	}
	cout << e << ' ' << s << ' ' << m << endl;
	cout << year << endl;
	return 0;
}