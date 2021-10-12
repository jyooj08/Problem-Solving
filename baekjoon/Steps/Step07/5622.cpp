#include<iostream>
using namespace std;

int getNum(char c){
	if(c >='A' && c <= 'C') return 2;
	else if (c <= 'F') return 3;
	else if (c <= 'I') return 4;
	else if (c <= 'L') return 5;
	else if (c <= 'O') return 6;
	else if (c <= 'S') return 7;
	else if (c <= 'V') return 8;
	else if (c <= 'Z') return 9;
}

int main()
{
	string str;
	int time =0;
	
	cin >> str;
	for(int i=0;i<str.length();i++){
		time += getNum(str[i]) + 1;
	}
	cout << time;
	return 0;
}
