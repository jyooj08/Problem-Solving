#include<iostream>
#include<algorithm>
using namespace std;

class Point{
public:
	int x;
	int y;
};

bool increase(Point a, Point b){
	if(a.x < b.x) return true;
	else if (a.x == b.x){
		if(a.y < b.y) return true;
		else return false;
	} else return false;
}

int main()
{
	int n;
	cin >> n;
	
	Point points[n];
	
	for(int i=0;i<n;i++) cin >> points[i].x >> points[i].y;
	
	sort(points, points+n, increase);
	
	for(int i=0;i<n;i++) cout << points[i].x << ' ' << points[i].y << '\n';
	
	return 0;
}
