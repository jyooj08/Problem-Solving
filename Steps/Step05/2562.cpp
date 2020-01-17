#include<iostream>
using namespace std;

int main(){
	int idx = 1, maxValue, n;
	cin >> n;
	maxValue=n;
	
	for(int i=1;i<9;i++){
		cin >>n;
		if(n>maxValue){
			idx = i+1;
			maxValue=n;
		}
	}
	
	cout << maxValue<<endl<<idx;
	return 0;
}
