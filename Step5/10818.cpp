#include<iostream>
using namespace std;

int main(){
	int min=0, max=0;
	int n, k;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> k;
		if(i==0){
			min=k; max=k;
		} else {
			if(min > k) min=k;
			if(max < k) max=k;
		}
	}
	
	cout << min << ' ' << max;
	return 0;
}
