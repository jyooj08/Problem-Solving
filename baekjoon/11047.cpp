#include<iostream>
using namespace std;

int getCount(int idx, int count, int remaining, int* coin){
	if(remaining==0) return count;
	
	int n = remaining/coin[idx];
	
	if(n > 0){
		return getCount(idx+1, count+n, remaining - n*coin[idx], coin);
	} else {
		return getCount(idx+1, count, remaining, coin);
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	int coin[n];
	for(int i=n-1;i>=0;i--) cin >> coin[i]; // descending order
	
	cout << getCount(0,0,k,coin);
	return 0;
}
