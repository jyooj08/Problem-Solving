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

int shortest_path(vector<pair<int, int> >* graph, int* last_node) {
	//cout << "shortest path" << endl;
	int* dist = new int[n];
	fill_n(dist, n, MAX);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push({ 0,start });
	last_node[start] = -1;
	dist[start] = 0;

	while (!pq.empty()) {
		int current_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[current_node].size(); i++) {
			int next_dist = graph[current_node][i].second;
			int next_node = graph[current_node][i].first;

			if (dist[next_node] > dist[current_node] + next_dist) {
				dist[next_node] = dist[current_node] + next_dist;
				last_node[next_node] = current_node;
				pq.push({ dist[next_node], next_node });
			}
		}
	}

	return dist[dest];
}

void erase_path(vector<pair<int, int> >* graph, int* last_node) {
	//최단 경로 없애기
	int to = dest;
	int from = last_node[to];
	while (from != -1) {

		vector<pair<int, int> >::iterator iter;
		for (iter = graph[from].begin(); iter != graph[from].end(); iter++) {
			if ((*iter).first == to) {
				graph[from].erase(iter);
				break;
			}
		}
		to = from;
		from = last_node[to];
	}
	//cout << "end" << endl;
}

int main()
{	
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		cin >> start >> dest;

		vector<pair<int, int> >* graph = new vector<pair<int, int> >[n];// node, weight
		int* last_node = new int[n];

		for (int i = 0; i < m; i++) {
			cin >> from >> to >> len;
			graph[from].push_back({ to, len });
		}

		int min = shortest_path(graph, last_node); erase_path(graph, last_node);
		while (min == shortest_path(graph, last_node)) {
			erase_path(graph, last_node);
		}
		int answer = shortest_path(graph, last_node);
		if (answer == MAX) answer = -1;
		cout <<answer<< endl;

	}
	return 0;
}