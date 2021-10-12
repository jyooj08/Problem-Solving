#include<iostream>
#include<vector>
using namespace std;

int n;
int* time;
int* pay;
int maxpay=0;

void consult(int day, int sum){
	if(day+time[day] >= n){
		if(day+time[day]==n) sum += pay[day];
		if(sum > maxpay) maxpay=sum;
		return;
	}
	
	sum += pay[day];
	
	for(int i=day+time[day]; i<n;i++){
		consult(i, sum);
	}
}

int main()
{
	cin >> n;
	
	time = new int[n];
	pay = new int[n];
	
	for(int i=0;i<n;i++) cin >> time[i] >> pay[i];
	
	for(int i=0;i<n;i++) consult(i, 0);
	cout << maxpay;
	
	return 0;
}
