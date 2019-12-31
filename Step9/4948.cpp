#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n!=0){
		bool prime[2*n+1];
	
		prime[1]=false;
		for(int i=2;i<=2*n;i++) prime[i]=true;
	
		for(int i=2;i*i<=2*n;i++){
		    if(prime[i]){
				for(int j=i*i;j<=2*n;j+=i){
				    prime[j]=false;
				}
		    }	
		}
		
		int count=0;
		for(int i=n+1;i<=2*n;i++){
			if(prime[i]) count++;
		}
		cout << count << '\n';
		cin >> n;
	}
	
	return 0;
}
