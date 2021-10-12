/*
pq�� pair ������ �ٲٸ� �ð��ʰ���. why? 
-> pair��first ���� compare�ϱ� ������ ������ �ٲٸ� distance �������� priority queue�� �̿��Ϸ���
������ ������ �޼��� �� ����. 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 5000000
vector< pair<int,int> > node[20001];

int main()
{
	int V, E, start;
	cin >> V >> E;
	cin >> start;
	
	int from, to, weight;
	for(int i=0;i<E;i++){
		cin >> from >> to >> weight;
		node[from].push_back(make_pair(to, weight));
	}
	
	vector<int> dist(V+1, INF);
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater<pair<int,int> > > pq; // <cost, nodeindex> min heap
	
	dist[start]=0;
	pq.push(make_pair(0, start));
	
	while(!pq.empty()){
		int d = pq.top().first;
		int current = pq.top().second;
		
		pq.pop();
		//cout << current << ' ' << d <<endl;
		
		int next, nextdist;
		for(int i=0;i<node[current].size();i++){
			next=node[current][i].first;
			nextdist = node[current][i].second+d;
			
			if(dist[next] > nextdist){
				dist[next] = nextdist;
				pq.push(make_pair(nextdist, next));
			}
		}
	}
	
	for(int i=1;i<=V;i++){
		if(dist[i] != INF) printf("%d\n",dist[i]);
		else printf("INF\n");
	}
	
	return 0;
}
