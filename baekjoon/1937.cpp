#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Point{
public:
	int x, y;
	int food;
	
	Point(int x, int y, int f): x(x), y(y), food(f) {}
};

struct cmp{
	bool operator()(Point a, Point b){
		return a.food > b.food;
	}
};

int main()
{
	int n;
	cin >> n;
	
	priority_queue<Point, vector<Point>, cmp> pq;
	
	int** map = new int*[n]; for(int i=0;i<n;i++) map[i] = new int[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
			pq.push(Point(i, j, map[i][j]));
		}
	}
	
	int** day = new int*[n]; for(int i=0;i<n;i++) day[i] = new int[n];
	for(int i=0;i<n;i++) fill_n(day[i], n, 1);
	
	/*cout << "day" << endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout << day[i][j] << ' ';
		cout << endl;
	}cout << endl;
	
	cout << "prioritiy queue" <<endl;
	while(!pq.empty()){
		cout << pq.top().food << ' ';
		pq.pop();
	}*/
	
	while(!pq.empty()){
		Point p = pq.top();
		pq.pop();
		
		int x = p.x, y = p.y, f = p.food;
		if(f != map[x][y]) {
			cout << "position error!"<<endl;
			break;
		}
		// if next position's food is more, update the max day
		if(x-1>=0 && map[x-1][y]>f) day[x-1][y] = max(day[x-1][y], day[x][y]+1);
		if(x+1<n && map[x+1][y]>f) day[x+1][y] = max(day[x+1][y], day[x][y]+1);
		if(y-1>=0 && map[x][y-1]>f) day[x][y-1] = max(day[x][y-1], day[x][y]+1);
		if(y+1<n && map[x][y+1]>f) day[x][y+1] = max(day[x][y+1], day[x][y]+1);
		
		/*cout << '[' << x << ',' << y << ']' << endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << day[i][j]<<' ';
			}cout << endl;
		}cout <<endl;*/
	}
	
	int max_day=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			max_day = max(max_day, day[i][j]);
		}
	}
	cout << max_day;
	
	return 0;
}
