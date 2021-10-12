//1261
#include<iostream>
#include<queue>
using namespace std;

int** map;
int** visit;

struct Point {
	int x, y;
	int break_num;
};

int main()
{
	int m, n;
	string s;
	cin >> m >> n;

	map = new int*[n]; for (int i = 0; i < n; i++) map[i] = new int[m];
	visit = new int* [n]; for (int i = 0; i < n; i++) visit[i] = new int[m];
	for (int i = 0; i < n; i++) fill_n(visit[i], m, 10000);

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	//BFS
	queue<Point> q;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		Point p = q.front();
		q.pop();
		int x = p.x, y = p.y;
		int break_num = p.break_num;
		if (map[x][y] == 1) break_num++;
		if (visit[x][y] <= break_num) continue;
		visit[x][y] = break_num;

		if (x - 1 >= 0 && visit[x - 1][y] > break_num) q.push({ x - 1,y,break_num });
		if (x + 1 < n && visit[x + 1][y] > break_num) q.push({ x + 1,y,break_num });
		if (y - 1 >= 0 && visit[x][y - 1] > break_num) q.push({ x,y - 1,break_num });
		if (y + 1 < m && visit[x][y + 1] > break_num) q.push({ x,y + 1,break_num });

	}

	cout << visit[n - 1][m - 1];

	return 0;
}
