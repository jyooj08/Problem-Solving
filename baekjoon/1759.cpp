//1759
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int len = 4, C = 6;
char* arr;
bool* visit;
vector<string> pw;

void DFS(int idx, int size) {
	if (size == len) {
		//print
		string str;
		for (int i = 0; i < C; i++) {
			if (visit[i]) str += arr[i];
		}
		pw.push_back(str);
	}

	for (int i = idx; i < C; i++) {
		if (visit[i] == true) continue;

		visit[i] = true;
		DFS(i, size + 1);
		visit[i] = false;
	}
}

int main()
{
	cin >> len >> C;
	arr = new char[C];
	visit = new bool[C]; fill_n(visit, C, false);
	
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);

	DFS(0, 0);

	vector<string> pw_list;

	for (int i = 0; i < pw.size(); i++) {
		string s = pw[i];
		int v = 0, c = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
				v++;
			else
				c++;
		}

		if (v >= 1 && c >= 2) pw_list.push_back(s);
	}

	sort(pw_list.begin(), pw_list.end());

	int size = pw_list.size();
	for (int i = 0; i < size; i++) cout << pw_list[i] << endl;

	return 0;
 }
