#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int x = n/5, y=0;
	int weight; bool find=false;
	while(x>=0){
		weight = 5*x+3*y;
		if(weight==n) {
			find=true;
			break;
		}
		else if (weight < n) y++;
		else if (weight > n) {
			x--; y=0;
		}
	}
	if(find) {
		cout << x+y;
	} else cout<<"-1";
	
	return 0;
}
