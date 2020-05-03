//1238
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1000000

struct edge {
	int from, to;
	int time;
};

int n, m, x;
int** arr;
vector<edge> edges;

int main()
{
	cin >> n >> m >> x;
	int N = n + 1;
	int** arr = new int*[N]; for (int i = 0; i <= n; i++) arr[i] = new int[N];
	for (int i = 0; i <= n; i++) fill_n(arr[i], N, MAX);
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edges.push_back({ a,b,c });
		arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) arr[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int* total_time = new int[N];
	for (int i = 1; i <= n; i++) total_time[i] = arr[i][x] + arr[x][i];

	int max_time = 0;
	for (int i = 1; i <= n; i++) max_time = max(max_time, total_time[i]);

	cout << max_time;
	return 0;
}
