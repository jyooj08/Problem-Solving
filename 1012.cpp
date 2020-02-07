#include<iostream>
#include<cstring>
using namespace std;

int arr[50][50];
pair<int,int> direction[4]={{1,0},{0,1},{-1,0},{0,-1}};

void DFS(int x, int y, int n, int m){
	arr[x][y]=2;
	
	for(int i=0;i<4;i++){
		int a=x+direction[i].first;
		int b=y+direction[i].second;
		if(0<=a && a<n && 0<=b && b<m && arr[a][b]==1){
			DFS(a,b,n,m);
		}
	}
}

int main()
{
	int m, n, k, t;
	int x,y;
	cin >> t;
	
	while(t--){
		cin >> m >> n >> k;
		memset(arr,0,sizeof(arr));
		
		for(int i=0;i<k;i++){
			cin >> x >> y;
			arr[y][x]=1;
		}
		
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[i][j]==1) {
					count++;
					DFS(i,j,n,m);
				}
			}
		}
		
		cout << count << endl;
	}
	
	
	return 0;
}
