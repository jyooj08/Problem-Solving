#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double r;
	cin >> r;
	
	cout << fixed;
	cout.precision(6);
	cout << M_PI*r*r << endl;
	cout << 2*r*r << endl;
	
	return 0;
}
