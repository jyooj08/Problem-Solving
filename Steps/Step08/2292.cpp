#include<iostream>
using namespace std;

int main()
{
	int n, x=0, temp=1;
	cin >> n;
	
	while(temp+6*x < n){
		temp += 6*x;
		x++;
	}
	x++;
	cout<<x<<endl;
	return 0;
}
