#include<iostream>
using namespace std;

int w, h; // width, height

void island(int** map, int x, int y, int num){
	map[x][y]=num;
	
	if(x-1>=0 && map[x-1][y]==1) island(map, x-1, y, num);
	if(x+1<h && map[x+1][y]==1) island(map, x+1, y, num);
	if(y-1>=0 && map[x][y-1]==1) island(map, x, y-1, num);
	if(y+1<w && map[x][y+1]==1) island(map, x, y+1, num);
	if(x-1>=0 && y-1>=0 && map[x-1][y-1]==1) island(map, x-1, y-1, num);
	if(x-1>=0 && y+1<w && map[x-1][y+1]==1) island(map, x-1, y+1, num);
	if(x+1<h && y-1>=0 && map[x+1][y-1]==1) island(map, x+1, y-1, num);
	if(x+1<h && y+1<w && map[x+1][y+1]==1) island(map, x+1, y+1, num);
}

int main()
{	
	while(true){
		cin >> w >> h;
		if(w==0 || h==0) break; 
		
		int** map = new int*[h];
		for(int i=0;i<h;i++) map[i] = new int[w];
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin >> map[i][j];
		
		int count=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(map[i][j]==1){
					count++;
					island(map, i, j, count+1);
				}
			}
		}
		cout << count << '\n';
	}
	
	return 0;
}
