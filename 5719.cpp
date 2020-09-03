#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

#define MAX 10000000

// 5719
int n, m;
int start, dest;
int from, to, len;

int dijkstra(int** graph, vector<int>* path) {
	int* dist = new int[n];
	fill_n(dist, n, MAX);
	priority_queue<pair<int, int> > pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curr_cost = -pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();

		if (dist[curr_node] < curr_cost) continue;

		for (int next = 0; next < n; next++) {
			if (graph[curr_node][next] == -1) continue;
			int next_dist = curr_cost + graph[curr_node][next];

			if (dist[next] > next_dist) {
				dist[next] = next_dist;
				pq.push({ -dist[next], next });

				path[next].clear();
				path[next].push_back(curr_node);
			}
			else if (dist[next] == next_dist) {
				path[next].push_back(curr_node);
			}
		}
	}
	return dist[dest];
}

void delete_path(int** graph, vector<int>* path) {
	queue<pair<int, int> > q;
	for (int e : path[dest]) {
		q.push({ dest, e });
	}

	while (!q.empty()) {
		int to = q.front().first;
		int from = q.front().second;
		q.pop();
		
		//cout << "delete [" << from << "," << to << "]\n";
		graph[from][to] = -1;

		for (int e : path[from]) {
			//if (e == -1) continue;
			q.push({ from, e });
			//cout << "push {" << from << "," << e << "}\n";
		}
	}
}

int main()
{	
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> start >> dest;

		int** graph = new int* [n];
		vector<int>* path = new vector<int>[n];

		for (int i = 0; i < n; i++) {
			graph[i] = new int[n];
			fill_n(graph[i], n, -1);
		}
		

		for (int i = 0; i < m; i++) {
			cin >> from >> to >> len;
			graph[from][to] = len;
		}

		int result = dijkstra(graph, path);
		delete_path(graph, path);
		result = dijkstra(graph, path);
		if (result == MAX) result = -1;
		cout << result << endl;

		delete[] path;
		for (int i = 0; i < n; i++) delete[] graph[i]; delete[] graph;
	}
	return 0;
}
