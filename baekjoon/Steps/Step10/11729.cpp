#include<iostream>
#include<cmath>
using namespace std;

void move(int n, int from, int by, int to){
	if(n==1){
		cout << from << ' ' << to << '\n';
	} else{
		move(n-1,from,to,by);
		cout << from << ' ' << to << '\n';
		move(n-1,by,from,to);
	}
}

int main()
{
	int n;
	cin >> n;
	cout << (int)(pow(2,n)-1) << endl; // int������ ĳ���������� ������ Ʋ����. 
	
	move(n,1,2,3);
	
	return 0;
}
