#include<iostream>
using namespace std;

int main()
{
	int t, n;
	cin >> t;
	
	while(t--){
		cin >> n;
		int zero[n+1] = {0,};
		int one[n+1] = {0,};
		
		zero[0]=1; one[1]=1;
		for(int i=2;i<=n;i++){
			zero[i] = zero[i-1]+zero[i-2];
			one[i] = one[i-1] + one[i-2];
		}
		
		cout << zero[n] << ' ' << one[n] << '\n';
	}
	
	return 0;
}
