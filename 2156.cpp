#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cup[n+1]; cup[0]=0;
	for(int i=1;i<=n;i++) cin >> cup[i];
	
	int arr[n+1];
	arr[0]=0;
	arr[1]=cup[1];
	arr[2]=cup[1]+cup[2];
	for(int i=3;i<=n;i++){
		arr[i] = max(arr[i-2]+cup[i], arr[i-3]+cup[i-1]+cup[i]);
		arr[i] = max(arr[i-1],arr[i]);
	}
	
	int max=0;
	for(int i=1;i<=n;i++){
		if(max < arr[i]) max=arr[i];
	}
	cout << max;
	return 0;
}
