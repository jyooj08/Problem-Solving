#include<iostream>
using namespace std;

int getDifference(int n){
	// n�� �� �ڸ� Ȥ�� �� �ڸ�  ���϶� 
	if(n/100 == 0) return 1;
	
	int diff = n%10 - (n/10)%10;
	n /= 10;
	
	while(n>=10){
		if(diff != n%10 - (n/10)%10) {
			return 0;
		}
		n /= 10;
	} 
	
	return 1;
}

int main()
{
	int count = 0, N;
	cin >> N;
	for(int i=1;i<=N;i++){
		count += getDifference(i);
	}
	cout << count;

	return 0;
}
