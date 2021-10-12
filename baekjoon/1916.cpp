#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	vector<pair<int,int> > bus[n+1];
	int from, to, weight;
	for(int i=0;i<m;i++){
		cin >> from >> to >> weight;
		bus[from].push_back({to, weight});
	}
	
	int start, end;
	cin >> start >> end;
	
	int dist[n+1]; fill(dist, dist+n+1, INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; //dist, node
	pq.push({0,start}); dist[start]=0;
	
	while(!pq.empty()){
		int distance=pq.top().first;
		int current=pq.top().second;
		int num=bus[current].size();
		pq.pop();
		
		for(int i=0;i<num;i++){
			int next=bus[current][i].first;
			int nextDistance=bus[current][i].second+distance;
			if(dist[next] > nextDistance){
				dist[next]=nextDistance;
				pq.push({nextDistance, next});
			}
		}
	}
	
	cout<<dist[end];
	return 0;
}
