#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	long long zero[n+1]; // int�� �ƴ϶� long long �̾�� �� �� 
	long long one[n+1]; // int�� �ƴ϶� long long �̾�� �� �� 
	zero[1]=0; one[1]=1;
	
	for(int i=2;i<=n;i++){
		one[i] = zero[i-1];
		zero[i] = zero[i-1]+one[i-1];
	}
	
	cout << zero[n]+one[n];
	return 0;
}
