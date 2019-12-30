#include<iostream>
using namespace std;

int main()
{
	int testcase;
	int k, n;
	cin >> testcase;
	
	int arr[15][15];
	for(int i=1;i<15;i++) {
		arr[0][i]=i;
		arr[i][0]=0;
	}
	
	for(int i=1;i<15;i++){
		for(int j=1;j<15;j++){
			arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}
	
	while(testcase--){
		cin >> k >> n;		
		cout << arr[k][n]<<endl;
	}
	
	return 0;
}
