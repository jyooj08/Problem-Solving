#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	
	while(testcase--){
		long x, y;
		
		cin >> x >> y;
		
		double goal = y - x;
		double moving= floor(sqrt(goal));
		
		int count = 2*moving-1 + ceil((goal-moving*moving)/moving);
		cout << count << endl;
	}
	return 0;
}
