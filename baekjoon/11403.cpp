#include<iostream>
#include<queue>
using namespace std;

void findPath(int** graph, int**path, int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(graph[i][j]==1) path[i][j]=1;
				else if(graph[i][k]==1 && graph[k][j]==1) path[i][j]=1;
				graph[i][j]=path[i][j];
			}
		}
	}
}

int main()
{
	int nVertex, v;
	cin >> nVertex;
	
	int ** graph;
	graph = new int*[nVertex]; for(int i=0;i<nVertex;i++) graph[i] = new int[nVertex];
	
	for(int i=0;i<nVertex;i++){
		for(int j=0;j<nVertex;j++){
			cin >> graph[i][j];
		}
	}
	
	int** path;
	path = new int*[nVertex]; for(int i=0;i<nVertex;i++) path[i] = new int[nVertex];
	for(int i=0;i<nVertex;i++) fill_n(path[i],nVertex, 0);
	
	findPath(graph, path, nVertex);
	
	for(int i=0;i<nVertex;i++){
		for(int j=0;j<nVertex;j++){
			cout << path[i][j] << ' ';
		}cout << endl;
	}
	return 0;
}
