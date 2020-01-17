#include<iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	
	int max=1, count=1;
	while(max<x){
		count++;
		max += count;
	}
	
	bool decrease = (count%2 == 1) ? true : false;
	int row, col;
	
	if(decrease){
		row=1, col=count;
		while(max > x){
			row++; col--; max--;
		}
	} else{
		row=count, col=1;
		while(max > x){
			row--; col++; max--;
		}
	}
	
	cout << row << '/' << col;
	return 0;
}
