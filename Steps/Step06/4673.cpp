#include<iostream>
using namespace std;

void getD(bool* self, int n){
	int dn = n;
	while(n>0){
		dn += (n%10);
		n /= 10;
	}
	if(dn <= 10000) self[dn]=false;
}

int main()
{
	bool self[10001];
	for(int i=0;i<=10000;i++) self[i]=true;
	
	for(int i=1;i<=10000;i++) {
		getD(self, i);	
	}
	
	for(int i=1;i<=10000;i++){
		if(self[i]) cout<<i<<endl;
	}
	
	return 0;
}
