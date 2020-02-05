#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	
	int bus[n+1][n+1];
	for(int i=1;i<=n;i++) fill(bus[i], bus[i]+n+1, INT_MAX);
	int from, to, weight;
	for(int i=0;i<m;i++) {
		cin >> from >> to >> weight;
		if(bus[from][to] > weight) {
			bus[from][to]=weight;
		}
	}
	for(int i=1;i<=n;i++) bus[i][i]=0;
	
	// floyd
	long long dist[n+1][n+1];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=bus[i][j];
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	//print
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) {
			if(dist[i][j]==INT_MAX) cout << "0 ";
			else cout << dist[i][j] << ' '; 
		}
		cout << '\n';
	}
	
	return 0;
}
