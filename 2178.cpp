#include<iostream>
#include<string>
#include<queue>
#include<climits>
using namespace std;

int n, m;
int** arr;

class Point {
public:
	int x;
	int y;
	int len;

	Point() {}
	Point(int xpos, int ypos, int length) {
		x = xpos; y = ypos;
		len = length;
	}
};


void findPath() {
	queue<Point> q;

	Point start(0, 0, 0);
	q.push(start);

	int min = INT_MAX;

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		if (p.x == n - 1 && p.y == m - 1) {
			if (p.len < min + 1) min = p.len + 1;
		}

		//visited=2
		if (arr[p.x][p.y] == 1) {
			arr[p.x][p.y] = 2;

			Point temp(p.x, p.y, p.len + 1);

			if (p.x - 1 >= 0) {
				temp.x = p.x - 1; temp.y = p.y;
				q.push(temp);
			}
			if (p.x + 1 < n) {
				temp.x = p.x + 1; temp.y = p.y;
				q.push(temp);
			}
			if (p.y - 1 >= 0) {
				temp.x = p.x; temp.y = p.y - 1;
				q.push(temp);
			}
			if (p.y + 1 < m) {
				temp.x = p.x; temp.y = p.y + 1;
				q.push(temp);
			}
		}
	}
	cout << min;
}


int main()
{
	cin >> n >> m;
	arr = new int*[n]; for (int i = 0; i < n; i++) arr[i] = new int[m];

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < m; j++) arr[i][j] = temp[j] - '0';
	}

	findPath();
	return 0;
}
