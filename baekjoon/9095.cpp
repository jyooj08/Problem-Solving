#include<iostream>
using namespace std;

int main()
{
	int n, t;
	
	cin >> t;
	
	while(t--){
		cin >> n;
	
		int arr[n+1]={0,};
	
		arr[0]=1;
		for(int i=0;i<n;i++){
			if(i+1<=n) arr[i+1]+=arr[i];
			if(i+2<=n) arr[i+2]+=arr[i];
			if(i+3<=n) arr[i+3]+=arr[i];
		}
	
		cout << arr[n] << endl;
	}
	
	
	
	
	return 0;
}
