#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int score[5];
	for(int i=0;i<5;i++) cin >> score[i];
	
	int sum=0;
	for(int i=0;i<5;i++) sum += max(score[i],40);
	
	cout << sum/5;
	return 0;
}
