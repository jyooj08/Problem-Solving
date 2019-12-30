#include<iostream>
using namespace std;

int main()
{
	int testcase;
	int h, w, n;
	cin >> testcase;
	
	for(int i=0;i<testcase;i++){
		cin >> h >> w >> n;
		int x, y;
		
		if(n%h != 0){
			y = n%h; x  = n/h + 1;
		} else {
			y = h; x = n/h;
		}
		
		cout << y*100+x<<endl;
	}
	
	return 0;
}
