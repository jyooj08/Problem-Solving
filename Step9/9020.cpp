#include<iostream>
using namespace std;

int main()
{
	int testcase, n;
	cin >> testcase;
	
	// get prime
	bool prime[10001]; 
	prime[1]=false;	
	for(int i=2;i<=10000;i++) prime[i]=true;
	
	for(int i=2;i*i<=10000;i++){
		if(prime[i]){
			for(int j=i*i;j<=10000;j+=i){
				prime[j]=false;
			}
		}	
	}
	
	while(testcase--){
		cin >> n;
		int start=n/2, p1, p2;
		
		while(start>1){
			if(prime[start] && prime[n-start]) break;
			start--;
		}
		cout <<start<<' '<<n-start<<endl;
	}
	return 0;
}
