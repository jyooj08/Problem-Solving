#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
vector<int>* graph;
bool* dfs_visited, *bfs_visited;

void DFS(int node){
	dfs_visited[node]=true;
	cout << node << ' ';
	
	for(int i=0;i<graph[node].size();i++){
		if(!dfs_visited[graph[node][i]]){
			DFS(graph[node][i]);
		}
	}
}

void BFS(int start){	
	int node;
	queue<int> q;
	q.push(start);
	bfs_visited[start]=true;
	
	while(!q.empty()){
		node=q.front();
		q.pop();
		cout << node << ' ';
		
		for(int i=0;i<graph[node].size();i++){
			if(!bfs_visited[graph[node][i]]){
				q.push(graph[node][i]);
				bfs_visited[graph[node][i]]=true;
			}
		}
	}
}
 
int main()
{
	int start;
	cin >> n >> m >> start;
	
	graph = new vector<int>[n+1];
	dfs_visited = new bool[n+1]; bfs_visited = new bool[n+1];
	fill_n(dfs_visited, n+1, false); fill_n(bfs_visited, n+1, false);
	int x, y;
	
	for(int i=0;i<m;i++){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	for(int i=1;i<=n;i++){
		sort(graph[i].begin(), graph[i].end());
	}
	
	DFS(start); cout << endl;
	BFS(start);
	
	return 0;
}
