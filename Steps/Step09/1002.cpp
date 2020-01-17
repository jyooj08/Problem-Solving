#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	
	while(testcase--){
		long x1,y1,r1,x2,y2,r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		
		// double이 아니라 int으로 dist 선언해서 틀림 
		double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		int add = r1+r2;
		int sub = abs(r1-r2);
		if(dist==0){
			if(r1==r2) cout << -1;
			else cout << 0;
		}
		else if(sub < dist && dist < add) cout << 2;
		else if(dist==add || dist==sub) cout << 1;
		else cout << 0;
		cout << endl;
	}
	return 0;
}
