#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int m, n;
int** tomato;
int arr[1001][1001];
pair<int,int> direction[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
queue<pair<int,int> > q;

int BFS(){
	int day=0;
	while(!q.empty()){
		int size = q.size();
		for(int k=0;k<size;k++){
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			arr[x][y]=day;
			for(int i=0;i<4;i++){
				int a=x+direction[i].first;
				int b=y+direction[i].second;
				
				if(a>=0 && a<n && b>=0 && b<m && tomato[a][b]==0){
					tomato[a][b]=1;
					q.push({a,b});
				}
			}
		}
		day++;
	}
	
	return day-1;
	
}

int main()
{
	int k;
	cin >> m >> n;
	tomato=new int*[n]; for(int i=0;i<n;i++) tomato[i]=new int[m];
	
	bool alreadyDone=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) {
			cin >> k;
			if(k==0) alreadyDone=false;
			if(k==1) q.push({i,j});
			tomato[i][j]=k;
		}
	}
	
	if(alreadyDone){
		cout << "0";
		return 0;
	}
	
	
	int day=BFS();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tomato[i][j]==0){
				cout << "-1";
				return 0;
			}
		}
	}
	cout << day;

	
	return 0;
}
