#include<iostream>
using namespace std;

int main()
{
	int burger, drink;
	int price;

	cin >> burger;
	cin >> price; if (price < burger) burger = price;
	cin >> price; if (price < burger) burger = price;
	cin >> drink;
	cin >> price; if (price < drink) drink = price;

	cout << burger + drink - 50;
	return 0;
}