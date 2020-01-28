#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int** map;
int n;

void DFS(int x, int y, int group, vector<int>* num){
	map[x][y] = group;
	(*num)[group]++;
	
	if(x-1>=0 && map[x-1][y]==-1) DFS(x-1, y, group, num);
	if(x+1<n && map[x+1][y]==-1) DFS(x+1, y, group, num);
	if(y-1>=0 && map[x][y-1]==-1) DFS(x, y-1, group, num);
	if(y+1<n && map[x][y+1]==-1) DFS(x, y+1, group, num);
}

int main()
{
	char ch;
	cin >> n;
	//map1 = new bool*[n]; for(int i=0;i<n;i++) map1[i] = new bool[n];
	map = new int*[n]; for(int i=0;i<n;i++) map[i] = new int[n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			cin >> ch;
			if(ch=='0') map[i][j]=0;
			else map[i][j]=-1;
		} 
	}
	
	vector<int> num;
	int group=0;
	while(1){
		int i, j;
		bool find=false;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(map[i][j]==-1){
					num.push_back(0);
					DFS(i, j, group++, &num);
					find=true;
					break;
				}
			}
			if(find) break;
		}
		
		if(i==n && j==n) break;
	}
	
	sort(num.begin(), num.end());
	
	cout << group << '\n';
	for(int i=0;i<num.size();i++) cout << num[i] << '\n';
	
	return 0;
}
