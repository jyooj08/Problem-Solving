#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int n, num=0;
	cin >> n;
	
	while(++num){
		int temp = num; bool find=false;
		while(temp){
			if(temp % 1000 == 666){
				find=true; break;
			}
			temp /= 10;
		}
		
		if(find && --n==0) break;
	}
	
	cout << num;
	
	return 0;
}
