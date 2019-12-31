#include<iostream>
using namespace std;

int main()
{
	bool prime[1001];
	int n, k, count=0;
	
	prime[1]=false;
	for(int i=2;i<=1000;i++) prime[i]=true;
	for(int i=2;i<=1000;i++){
		for(int j=i+1;j<=1000;j++){
			if(prime[j]==true && j%i==0) prime[j]=false;
		}
	}
	
	cin >> n;
	while(n--){
		cin >> k;
		if(prime[k]) count++;
	}
	cout << count;
	
	return 0;
}
