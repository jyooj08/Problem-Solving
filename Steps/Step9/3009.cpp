#include<iostream>
using namespace std;

typedef struct {
	int x;
	int y;
}Point;

int main()
{
	Point a,b,c,d;
	cin>>a.x>>a.y;
	cin>>b.x>>b.y;
	cin>>c.x>>c.y;
	
	if(a.x==b.x) d.x=c.x;
	else if (b.x==c.x) d.x=a.x;
	else if (c.x==a.x) d.x=b.x;
	
	if(a.y==b.y) d.y=c.y;
	else if(b.y==c.y) d.y=a.y;
	else if (c.y==a.y) d.y=b.y;
	
	cout << d.x << ' ' << d.y;
	
	return 0;
}
