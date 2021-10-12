#include<iostream>
using namespace std;

int getCount(int* money, int unit){
	int x = *money/unit;
	*money -= x*unit;
	return x;
}

int main()
{
	int money, price;
	cin >> price;
	
	money = 1000-price;
	
	int count=0;
	while(money > 0){
		if(money >= 500) count += getCount(&money, 500);
		else if (money >= 100) count+= getCount(&money, 100);
		else if (money >= 50) count+= getCount(&money, 50);
		else if (money >= 10) count+= getCount(&money, 10);
		else if (money >= 5) count+= getCount(&money, 5);
		else count+= getCount(&money, 1);
	}
	
	cout << count;
	return 0;
}
