#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double a, b, v;
	int day=1, distance;
	
	cin >> a >> b >> v;
	
	day = 1 + ceil((v-a)/(a-b));
	cout << day;
	return 0;
}
