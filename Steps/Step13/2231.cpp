#include<iostream>
using namespace std;

int main()
{
	int n, k, constructor=0;
	
	cin >> n;
	for(int i=1;i<n;i++){
		k=i;
		int sum=k;
		while(k){
			sum += (k%10);
			k /= 10;
		}
		
		if(sum==n){
			constructor=i;
			break;
		}
	}
	
	cout << constructor;
	
	return 0;
}
