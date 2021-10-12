#include<iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	
	bool prime[n+1];
	
	prime[1]=false;
	for(int i=2;i<=n;i++) prime[i]=true;
	for(int i=2;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(prime[j]==true && j%i==0) prime[j]=false;
		}
	}
	
	int sum=0, min=0;
	for(int i=m;i<=n;i++){
		if(prime[i]){
			if(min==0 || min>i) min=i;
			sum += i;
		}
	}
	
	if(sum){
		cout << sum << endl;
		cout << min << endl;
	} else cout << "-1";
	
	return 0;
}
