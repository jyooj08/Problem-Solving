#include<iostream>
#include<utility>
#include<queue>
using namespace std;

bool visit[100000] = {0, };

void BFS(int start, int target){
	queue<pair<int,int> > q; // <pos, time>
	q.push({start,0});
	int min_time = 100000;
	
	while(!q.empty()){
		pair<int,int> p = q.front();
		q.pop();
		
		visit[p.first]=true;
		
		if(p.first == target && p.second < min_time){
			min_time = p.second;
			continue;
		}
		
		if(p.first+1 <= 100000 && !visit[p.first+1]) q.push({p.first+1, p.second+1});
		if(p.first-1 >= 0 && !visit[p.first-1]) q.push({p.first-1, p.second+1});
		if(p.first*2 <= 100000 && !visit[p.first*2]) q.push({p.first*2, p.second+1});
	}
	
	cout << min_time;
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	BFS(n, k);
	
	return 0;
}
